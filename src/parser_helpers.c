/*
    Implementation of "parser_context.h"
*/

#include "parser_helpers.h"
#include "error_handling.h"
#include "parser_symbols.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    --------- Function name ---------
*/

static char *curr_func;

void set_func_name(char *name) {
    size_t len = strlen(name);
    curr_func = malloc(sizeof(char) * (len + 3));
    if (!curr_func) {
        perror("Malloc error when allocating new function name");
        exit(1);
    }
    sprintf(curr_func, "\"%s\"", name);
}

void func_ended() {
    free(curr_func);
    curr_func = 0;
}

char *func_name() {
    if (!curr_func) {
        printf("Error: __func_name__ used outside of function definition\n");
        return "";
    }
    return curr_func;
}

/*
    --------- Declarator ID ---------
*/

char *get_decltr_id(decltr *dctr) {
    for (decltr *curr = dctr; curr; curr = curr->next) {
        if (curr->kind == DCTR_ID) {
            return curr->id;
        }
    }
    return 0;
}

/*
    --------- Typedef Symbol ---------
*/

void add_typedef_type(decl *decl) {
    if (decl->specs->storage != SC_TYPEDEF) return;

    for (init_decltr *type_decltr = decl->init_decltrs; type_decltr; type_decltr = type_decltr->next) {
        if (type_decltr->decltr) {
            sym_define_typedef(get_decltr_id(type_decltr->decltr));
        }
    }
}

/*
    --------- List Reversal ---------
*/

// List of helper function forward declarations
static block_list *reverse_block_list                   (block_list *node, bool is_head);
static init_list *reverse_init_list                     (init_list *node, bool is_head);
static init_decltr *reverse_init_decltr_list            (init_decltr *node, bool is_head);
static param_list *reverse_param_list                   (param_list *node, bool is_head);
static struct_decltr_list *reverse_struct_decltr_list   (struct_decltr_list *node, bool is_head);
static struct_decl_list *reverse_struct_decl_list       (struct_decl_list *node, bool is_head);
static enumerator_list *reverse_enumerator_list         (enumerator_list *node, bool is_head);
static decltr *reverse_decltr                           (decltr *node, bool is_head);
static expr *reverse_argument_list                      (expr *node, bool is_head);

static void reverse_in_type_spec     (type_spec *curr);
static void reverse_in_decl_specs    (decl_specs *curr);
static void reverse_in_expr          (expr *curr);
static void reverse_in_initializer   (initializer *curr);
static void reverse_in_decl          (decl *curr);
static void reverse_in_stmt          (stmt *curr);
static void reverse_in_func_def      (func_def *curr);

// Macro shorthand for all list reversal
#define reverse_list(type, func) \
    if (!node) return 0; \
    type *new_head = (node->next) ? func(node->next, false) : node; \
    if (node->next) { \
        node->next->next = node; \
    } \
    if (is_head) { \
        node->next = 0; \
    }


// I realize that I used a suboptimal solution for list reversal
// Recursive list reversal may cause problems with the call stack for certain programs
// Although realistically, only a terrible programmer would write a program that exceeds max depth


static block_list *reverse_block_list(block_list *node, bool is_head) {
    reverse_list(block_list, reverse_block_list)

    // Reverse sublists
    if (node->kind == BI_DECL) {
        reverse_in_decl(node->decl);
    } else if (node->kind == BI_STMT) {
        reverse_in_stmt(node->stmt);
    }

    return new_head;
}

static init_list *reverse_init_list(init_list *node, bool is_head) {
    reverse_list(init_list, reverse_init_list)

    // Reverse sublists
    reverse_in_initializer(node->init);

    return new_head;
}

static init_decltr *reverse_init_decltr_list(init_decltr *node, bool is_head) {
    reverse_list(init_decltr, reverse_init_decltr_list)

    // Reverse sublists
    node->decltr = reverse_decltr(node->decltr, true);
    reverse_in_initializer(node->init);

    return new_head;
}

static param_list *reverse_param_list(param_list *node, bool is_head) {
    reverse_list(param_list, reverse_param_list)

    // Reverse sublists
    reverse_in_decl(node->param_decl);

    return new_head;
}

static struct_decltr_list *reverse_struct_decltr_list(struct_decltr_list *node, bool is_head) {
    reverse_list(struct_decltr_list, reverse_struct_decltr_list)

    // Reverse sublists
    node->decltr = reverse_decltr(node->decltr, true);

    return new_head;
}

static struct_decl_list *reverse_struct_decl_list(struct_decl_list *node, bool is_head) {
    reverse_list(struct_decl_list, reverse_struct_decl_list)

    // Reverse sublists
    reverse_in_decl_specs(node->specs);
    node->decltrs = reverse_struct_decltr_list(node->decltrs, true);

    return new_head;
}

static enumerator_list *reverse_enumerator_list(enumerator_list *node, bool is_head) {
    reverse_list(enumerator_list, reverse_enumerator_list)

    // Reverse sublists
    reverse_in_expr(node->const_val);

    return new_head;
}

static decltr *reverse_decltr(decltr *node, bool is_head) {
    reverse_list(decltr, reverse_decltr)

    // Reverse sublists
    switch (node->kind) {
        case DCTR_ARRAY:
            reverse_in_expr(node->array.size);
            break;
        case DCTR_FUNC:
            node->func.params = reverse_param_list(node->func.params, true);
            break;
        default:;
    }

    return new_head;
}

// Note: automatically assumes this node is an argument expression list
static expr *reverse_argument_list(expr *node, bool is_head) {
    // Not using macro because it uses "right" instead of "next"
    if (!node) return 0;
    
    expr *new_head = (node->right) ? reverse_argument_list(node->right, false) : node;

    if (node->right) {
        node->right->right = node;
    }
    if (is_head) {
        node->right = 0;
    }

    // Reverse sublists
    reverse_in_expr(node->left);

    return new_head;
}

static void reverse_in_type_spec(type_spec *curr) {
    if (!curr) return;

    if (curr->kind == TS_SOU) {
        curr->sou->decls = reverse_struct_decl_list(curr->sou->decls, true);
    } else if (curr->kind == TS_ENUM) {
        curr->enums->enum_list = reverse_enumerator_list(curr->enums->enum_list, true);
    }
}

static void reverse_in_decl_specs(decl_specs *curr) {
    if (!curr) return;

    for (type_spec_list *spec = curr->type_specs; spec; spec = spec->next) {
        reverse_in_type_spec(spec->type);
    }
}

static void reverse_in_expr(expr *curr) {
    if (!curr) return;

    switch (curr->kind) {
        case EXPR_INIT_LIST:
            curr->extra.type->suffix = reverse_decltr(curr->extra.type->suffix, true);
            curr->extra.init = reverse_init_list(curr->extra.init, true);
            break;
        case EXPR_CAST:
            curr->extra.type->suffix = reverse_decltr(curr->extra.type->suffix, true);
            break;
        case EXPR_SIZEOF_TYPE:
            curr->extra.type->suffix = reverse_decltr(curr->extra.type->suffix, true);
            break;
        case EXPR_CALL:
            curr->right = reverse_argument_list(curr->right, true);
            break;
        case EXPR_CONDITIONAL:
            reverse_in_expr(curr->extra.conditional);
            break;
        default:;
    }

    reverse_in_expr(curr->left);
    reverse_in_expr(curr->right);
}

static void reverse_in_initializer(initializer *curr) {
    if (!curr) return;

    if (curr->kind == INIT_EXPR) {
        reverse_in_expr(curr->assignment);
    }
    if (curr->kind == INIT_LIST) {
        curr->list = reverse_init_list(curr->list, true);
    }
}

static void reverse_in_decl(decl *curr) {
    if (!curr) return;

    reverse_in_decl_specs(curr->specs);

    switch (curr->kind) {
        case DECL_NORMAL:
            curr->init_decltrs = reverse_init_decltr_list(curr->init_decltrs, true);
            break;
        case DECL_PARAM:
            curr->param_decltr = reverse_decltr(curr->param_decltr, true);
            break;
    }
}

static void reverse_in_stmt(stmt *curr) {
    if (!curr) return;

    stmt_kind kind = curr->kind;

    switch (kind) {
        case STMT_EXPR: {
            reverse_in_expr(curr->expr_stmt);
            break;
        }
        case STMT_COMPOUND: {
            curr->compound_stmt.items = reverse_block_list(curr->compound_stmt.items, true);
            break;
        }
        case STMT_IF: {
            reverse_in_expr(curr->conditional_stmt.cond);
            reverse_in_stmt(curr->conditional_stmt.body);
            reverse_in_stmt(curr->conditional_stmt.else_body);
            break;
        }
        case STMT_SWITCH: {
            reverse_in_expr(curr->conditional_stmt.cond);
            reverse_in_stmt(curr->conditional_stmt.body);
            reverse_in_stmt(curr->conditional_stmt.else_body);
            break;
        }
        case STMT_WHILE: {
            reverse_in_expr(curr->conditional_stmt.cond);
            reverse_in_stmt(curr->conditional_stmt.body);
            reverse_in_stmt(curr->conditional_stmt.else_body);
            break;
        }
        case STMT_DO: {
            reverse_in_expr(curr->conditional_stmt.cond);
            reverse_in_stmt(curr->conditional_stmt.body);
            reverse_in_stmt(curr->conditional_stmt.else_body);
            break;
        }
        case STMT_FOR: {
            for_init_kind for_kind = curr->for_stmt.kind;
            if (for_kind == FOR_DECL) {
                reverse_in_decl(curr->for_stmt.init.decl);
            } else {
                reverse_in_expr(curr->for_stmt.init.expr);
            }

            reverse_in_expr(curr->for_stmt.cond);
            reverse_in_expr(curr->for_stmt.update);
            reverse_in_stmt(curr->for_stmt.body);
            break;
        }
        case STMT_LABEL: {
            reverse_in_stmt(curr->label_stmt.next);
            break;
        }
        case STMT_CASE: {
            reverse_in_expr(curr->case_stmt.case_expr);
            reverse_in_stmt(curr->case_stmt.result);
            break;
        }
        case STMT_DEFAULT: {
            reverse_in_stmt(curr->default_stmt.result);
            break;
        }
        case STMT_RETURN: {
            reverse_in_expr(curr->return_stmt.result);
            break;
        }
        default:;
    }
}

static void reverse_in_func_def(func_def *curr) {
    if (!curr) return;

    curr->decltr = reverse_decltr(curr->decltr, true);
    reverse_in_stmt(curr->body);
}

translation_unit *reverse_lists(translation_unit *tree, bool is_head) {
    if (!tree) return 0;

    translation_unit *new_head = (tree->next) ? reverse_lists(tree->next, false) : tree;

    if (tree->next) {
        tree->next->next = tree;
    }
    if (is_head) {
        tree->next = 0;
    }

    // Reverse sublists
    if (tree->action->kind == EXT_DECL_FUNC) {
        reverse_in_func_def(tree->action->func);
    } else if (tree->action->kind == EXT_DECL_SIMPLE) {
        reverse_in_decl(tree->action->decl);
    }

    return new_head;
}