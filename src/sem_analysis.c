/*
    Implementation of "sem_analysis.h"
*/

#include "sem_analysis.h"
#include "ast.h"
#include "decl_type.h"
#include "semantic_symtab.h"
#include "semantic_types.h"
#include "error_handling.h"
#include "optimization.h"
#include "string_helpers.h"
#include <stdbool.h>
#include <stdio.h>

/*
    Functions returning bool will return true if no errors are detected and false otherwise
*/

// Helper structs

#define HASH_SIZE 31

typedef struct switch_entry {
    int case_val;
    struct switch_entry *next;
} switch_entry_t;

typedef struct switch_state {
    struct switch_entry *cases[HASH_SIZE];
    bool has_default;
} switch_state_t;

typedef struct sem_state {
    bool in_loop;
    bool in_switch;
    sem_type_t *func_return;
    struct switch_state *switch_state;
} sem_state_t;

// Keeps track of the current state being processed
static sem_state_t *state = NULL;

// Shorthand to keep track of whether or not a structure is valid
#define assign_success(val) \
    success = success && val;

/*
    *** Switch state management ***
*/

static void free_switch_state(switch_state_t *ss) {
    for (int i=0; i<HASH_SIZE; i++) {
        for (switch_entry_t *entry = ss->cases[i]; entry;) {
            switch_entry_t *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(ss);
}

static bool add_case(expr *e) {
    if (!state->switch_state) return false;

    if (!e) {
        // This should not happen
        push_error("*** case must have an expression");
        return false;
    }
    
    sem_type_t *case_type = type_of_expr(e);
    if (!case_type || !type_is_integral(case_type)) {
        push_error("*** case expression must be a valid integral type");
        return false;
    }
    free_sem_type(case_type);

    if (!fold_constants(e)) {
        push_error("*** case must be of a constant type");
        return false;
    }

    int val = e->extra.const_val->val.i_val;
    int hash = val % HASH_SIZE; // maybe replace this with a better hash

    for (switch_entry_t *entry = state->switch_state->cases[hash]; entry; entry = entry->next) {
        if (entry->case_val == val) {
            push_error("*** cases in the same switch statement may not have the same value");
            return false;
        }
    }

    switch_entry_t *new_entry = calloc(1, sizeof(switch_entry_t));
    check_alloc_error(new_entry, "Alloc error when creating new switch entry");
    new_entry->case_val = val;
    new_entry->next = state->switch_state->cases[hash];
    state->switch_state->cases[hash] = new_entry;
    
    return true;
}

/*
    *** Forward declarations ***
*/

static bool process_init_compatibility(sem_type_t *type, initializer *init);
static bool process_decl(decl *dcl, scope_kind scope);
static bool validate_func_header(func_def *func);
static bool validate_expr(expr *e);
static bool process_statement(stmt *s);
static bool traverse_block_list(block_list *block);

/*
    *** Implementations ***
*/

static bool process_init_compatibility(sem_type_t *type, initializer *init) {
    // *** Initializer lists are not being implemented yet ***
    if (init->kind == INIT_LIST) {
        push_error("*** I don't feel like implementing initializer lists yet");
        return false;
    }

    if (!validate_expr(init->assignment)) {
        return false;
    }

    parse_req compatibility = expr_compatible(init->assignment, type);
    switch (compatibility) {
        case PARSE_ILLEGAL:
            //dump_table();
            push_error("*** initializer of type %s does not match declaration type %s", type_to_s(init->assignment->type), type_to_s(type));
            return false;
        case PARSE_EXPLICIT:
            push_error("*** initializer requires explicit type cast");
            return false;
        default:
            return true;
    }
}

/*
    Returns true if the declaration is valid and false otherwise
    Also handles the symbol table
    This function assumes that declarators are not abstract
        In other words, prototype parameters should NOT be handled here
*/
static bool process_decl(decl *dcl, scope_kind scope) {
    bool success = true;

    decl_specs *specs = dcl->specs;

    if (dcl->kind == DECL_NORMAL) {
        for (init_decltr *init_d = dcl->init_decltrs; init_d; init_d = init_d->next) {
            decltr *d = init_d->decltr;
            initializer *init = init_d->init;

            if (specs->func_spec != FS_NONE) {
                push_error("*** function specifiers are not implemented");
                success = false;
                continue;
            }

            if (scope == SEM_SCOPE_FILE) {
                if (
                    specs->storage != SC_NONE &&
                    specs->storage != SC_TYPEDEF &&
                    specs->storage != SC_EXTERN &&
                    specs->storage != SC_STATIC
                ) {
                    push_error("*** file scope storage class may only be static, extern, or typedef");
                    success = false;
                    continue;
                }
            } else {
                if (specs->storage == SC_EXTERN || specs->storage == SC_STATIC) {
                    push_error("*** linkage may not be specified outside of file scope");
                    success = false;
                    continue;
                }
            }
            
            sem_type_t *type = decl_type(specs, d, false);
            if (!type) {
                push_error("*** declaration type invalid");
                success = false;
                continue;
            }

            if (scope != SEM_SCOPE_FILE && type->kind == ST_FUNC) {
                push_error("*** function declaration only allowed at file scope");
                success = false;
                continue;
            }

            if (specs->storage == SC_TYPEDEF && init) {
                push_error("*** typedef declaration may not have an initializer");
                success = false;
                continue;
            }

            // Potentially valid typedef declaration
            if (specs->storage == SC_TYPEDEF) {
                sem_symbol_t *sym = sem_define_typedef(d->id, type);
                if (!sym) {
                    push_error("*** invalid redefinition of a typedef");
                    success = false;
                }
                continue;
            }

            // Regular declaration
            if (init && !process_init_compatibility(type, init)) {
                success = false;
                continue;
            }
            sem_symbol_t *sym = sem_declare_id(d->id, type, specs->storage, (bool) init);
            if (!sym) {
                push_error("*** invalid redefinition of a variable");
                success = false;
            }

            init_d->type = type;
        }
    } else {
        sem_type_t *type = decl_type(specs, dcl->param_decltr, true);
        if (!type) return false;
        if (dcl->param_decltr->kind != DCTR_ID) {
            push_error("*** parameter missing an identifier");
            return false;
        }
        sem_symbol_t *sym = sem_declare_id(dcl->param_decltr->id, type, specs->storage, false);
        if (!sym) {
            push_error("*** invalid redefinition of an identifier");
            success = false;
        }
        dcl->param_type = type;
    }

    return success;
}

static bool validate_func_header(func_def *func) {
    if (!func->decltr->next) {
        push_error("*** function definition requires parameter list");
        return false;
    }

    if (func->decltr->ptr) {
        push_error("*** function definition must not be a pointer to a function");
        return false;
    }

    if (func->decltr->next->kind != DCTR_FUNC) {
        push_error("*** function definition must have a function header");
        return false;
    }

    if (func->decltr->next->next) {
        push_error("*** function cannot return function or array types");
        return false;
    }
    
    return true;
}

static bool validate_expr(expr *e) {
    //printf("Validating expression\n");
    sem_type_t *expr_type = type_of_expr(e);
    if (!expr_type) return false;

    fold_constants(e);

    return true;
}

static bool validate_switch(stmt *s) {
    if (s->kind != STMT_SWITCH) return false;

    bool success = true;

    sem_type_t *comp_type = type_of_expr(s->conditional_stmt.cond);
    if (comp_type && !type_is_integral(comp_type)) {
        push_error("*** switch comparison must be an integral type");
        success = false;
    }

    switch_state_t *switch_state = state->switch_state;
    state->switch_state = calloc(1, sizeof(switch_state_t));
    check_alloc_error(state->switch_state, "Alloc error when creating new switch state");

    assign_success(process_statement(s->conditional_stmt.body))

    free_switch_state(state->switch_state);
    state->switch_state = switch_state;

    return success;
}

static bool process_statement(stmt *s) {
    if (!s) return true;

    bool success = true;

    switch (s->kind) {
        case STMT_EXPR:
            if (!validate_expr(s->expr_stmt)) {
                return false;
            }
            break;
        case STMT_COMPOUND:
            if (!traverse_block_list(s->compound_stmt.items)) {
                return false;
            }
            break;
        case STMT_IF: {
            sem_type_t *type = type_of_expr(s->conditional_stmt.cond);
            if (!type) {
                success = false;
            } else if (!type_is_scalar(type) && type->kind != ST_POINTER) {
                push_error("*** if statement condition must be a scalar type");
                success = false;
            }

            fold_constants(s->conditional_stmt.cond);
            free_sem_type(type);

            assign_success(process_statement(s->conditional_stmt.body))
            assign_success(process_statement(s->conditional_stmt.else_body))
            break;
        }
        case STMT_SWITCH:
            assign_success(validate_switch(s))
            break;
        case STMT_WHILE: case STMT_DO: {
            sem_type_t *type = type_of_expr(s->conditional_stmt.cond);
            if (!type) {
                success = false;
            } else if (!type_is_scalar(type)) {
                push_error("*** while loop condition must be a scalar type");
                success = false;
            }

            fold_constants(s->conditional_stmt.cond);
            free_sem_type(type);

            bool temp_in_loop = state->in_loop;
            state->in_loop = true;
            assign_success(process_statement(s->conditional_stmt.body))
            state->in_loop = temp_in_loop;
            break;
        }
        case STMT_FOR:
            sem_push_scope();
            if (s->for_stmt.kind == FOR_DECL) {
                assign_success(process_decl(s->for_stmt.init.decl, SEM_SCOPE_BLOCK))
            } else {
                assign_success(validate_expr(s->for_stmt.init.expr))
            }

            assign_success(validate_expr(s->for_stmt.cond))
            assign_success(validate_expr(s->for_stmt.update))

            bool temp_in_loop = state->in_loop;
            state->in_loop = true;
            assign_success(process_statement(s->for_stmt.body))
            state->in_loop = temp_in_loop;
            sem_pop_scope();
            break;
        case STMT_LABEL:
            sem_define_label(s->label_stmt.label);
            assign_success(process_statement(s->label_stmt.next))
            break;
        case STMT_CASE:
            if (!state->switch_state) {
                push_error("*** case statement must be placed inside a switch statement");
                success = false;
                break;
            }
            if (!s->case_stmt.case_expr) {
                push_error("*** case statement requires expression");
                success = false;
            }
            assign_success(add_case(s->case_stmt.case_expr))
            process_statement(s->case_stmt.result);
            break;
        case STMT_DEFAULT:
            if (!state->switch_state) {
                push_error("*** default statement must be placed inside a switch statement");
                success = false;
                break;
            }
            if (state->switch_state->has_default) {
                push_error("*** switch statement cannot have multiple default statements");
                success = false;
            }
            state->switch_state->has_default = true;
            break;
        case STMT_GOTO:
            if (!sem_lookup_label(s->goto_stmt.label)) {
                push_error("*** goto statement label undefined");
                success = false;
            }
            break;
        case STMT_CONTINUE:
            if (!state->in_loop) {
                push_error("*** continue statement must be placed inside loop");
                return false;
            }
            break;
        case STMT_BREAK:
            if (!state->in_loop && !state->in_switch) {
                push_error("*** break statement must be placed inside loop or switch block");
                return false;
            }
            break;
        case STMT_RETURN:
            // I don't think this can happen according to the grammar but this check is done anyway
            if (!state->func_return) {
                push_error("*** return statement must be placed inside function");
                return false;
            }
            if (!validate_expr(s->return_stmt.result)) {
                success = false;
            } else if (expr_compatible(s->return_stmt.result, state->func_return)) {
                push_error("*** type returned by return statement not compatible with return type");
                success = false;
            }
            break;
        default:;
    }

    return success;
}

static bool traverse_block_list(block_list *block) {
    bool success = true;

    // Start by processing all types within this scope

    for (block_list *blk = block; blk; blk = blk->next) {
        if (blk->kind == BI_DECL) {
            success = success && process_decl(blk->decl, SEM_SCOPE_BLOCK);
        } else {
            success = success && process_statement(blk->stmt);
        }
    }

    //dump_table();

    return success;
}

// Exported function
bool traverse_ast(translation_unit *ast) {
    state = calloc(1, sizeof(sem_state_t));
    check_alloc_error(state, "Alloc error when creating new sem_state");

    bool success = true;
        
    for (translation_unit *curr_ed = ast; curr_ed; curr_ed = curr_ed->next) {
        if (curr_ed->action->kind == EXT_DECL_SIMPLE) {
            //printf("Processing file scope declaration\n");
            // Handle declaration
            success = success && process_decl(curr_ed->action->decl, SEM_SCOPE_FILE);
        } else {
            //printf("Processing function\n");
            // Function definition
            func_def *func = curr_ed->action->func;
            if (!validate_func_header(func)) {
                success = false;
                continue;
            }

            sem_symbol_t *sym = sem_lookup_id(func->decltr->id);
            if (sym && sym->type->kind != ST_FUNC) {
                push_error("*** function definition may not use a non-function identifier as a name");
                success = false;
                continue;
            }

            if (sym && sym->is_definition) {
                push_error("*** redefinition of function not allowed");
                success = false;
                continue;
            }

            sem_type_t *func_type = decl_type(func->specs, func->decltr, false);
            sem_declare_id(func->decltr->id, func_type, func->specs->storage, true);
            
            // Handle parameters
            // In a function definition, the second part of the declarator contains the parameters
            sem_push_scope();
            for (param_list *param = func->decltr->next->func.params; param; param = param->next) {
                success = success && process_decl(param->param_decl, SEM_SCOPE_PARAM);
            }

            // Push body scope and handle body
            state->func_return = func_type->func_info.return_type;
            sem_push_scope();
            if (!traverse_block_list(func->body->compound_stmt.items)) {
                success = false;
            }

            sem_pop_scope();
            sem_pop_scope();

            func->type = func_type;

            //dump_table();

            // Check if the function is void; if not, check for a return statement
            if (
                types_equal(
                    func_type->func_info.return_type,
                    make_primitive_type(ST_VOID, false, 0)
                )
            ) continue;

            block_list *bl = func->body->compound_stmt.items;
            while (bl->next) bl = bl->next;
            if (bl->stmt->kind != STMT_RETURN) {
                push_error("*** non-void function must end with a return statement");
                success = false;
            }
        }
    }

    // Check for valid main function
    sem_symbol_t *main_func = sem_lookup_id("main");
    if (!main_func || !main_func->type || main_func->type->kind != ST_FUNC) {
        push_error("*** main function not found");
        return false;
    }
    if (main_func->type->func_info.return_type->kind != ST_INT) {
        push_error("*** main function must return int");
        return false;
    }
    if (main_func->type->func_info.params) {
        push_error("*** main function must not have parameters");
        return false;
    }

    return success && error_count == 0;
}