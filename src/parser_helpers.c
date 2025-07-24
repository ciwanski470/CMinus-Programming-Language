/*
    Implementation of "parser_context.h"
*/

#include "parser_helpers.h"
#include "error_handling.h"
#include <stdbool.h>
#include <string.h>

/*
    --------- Function name ---------
*/

char *curr_func;

static inline void set_func_name(char *name) {
    curr_func = strcat(strcat("\"", name), "\"");
}

static inline void func_ended() {
    free(curr_func);
    curr_func = 0;
}

static inline char *func_name() {
    if (!curr_func) {
        printf("Error: __func_name__ used outside of function definition\n");
        return "";
    }
    return curr_func;
}

/*
    --------- Parameter ellipsis ---------
*/

bool has_ellipsis = 0;

static inline void set_param_ellipsis(bool val) {
    has_ellipsis = val;
}

static inline bool check_param_ellipsis() {
    return has_ellipsis;
}

/*
    --------- Declarator ID ---------
*/

static inline char *get_decltr_id(decltr *decltr) {
    decltr_kind kind = decltr->kind;

    if (kind == DCTR_ID)
        return decltr->id;

    if (kind == DCTR_NESTED)
        return get_decltr_id(decltr->nested);

    if (decltr->prev != 0)
        return get_decltr_id(decltr->prev);

    return 0;
}

/*
    --------- List Reversal ---------
*/

// List of helper function forward declarations
static block_list *reverse_block_list                   (block_list *node, bool is_head);
static init_list *reverse_init_list                     (init_list *node, bool is_head);
static init_decltr *reverse_init_decltr_list            (init_decltr *node, bool is_head);
static param_list *reverse_param_list                   (param_list *node, bool is_head);
static id_list *reverse_id_list                         (id_list *node, bool is_head);
static decl_list *reverse_decl_list                     (decl_list *node, bool is_head);
static struct_decltr_list *reverse_struct_decltr_list   (struct_decltr_list *node, bool is_head);
static struct_decl_list *reverse_struct_decl_list       (struct_decl_list *node, bool is_head);
static enumerator_list *reverse_enumerator_list         (enumerator_list *node, bool is_head);
static designator *reverse_designation                  (designator *node, bool is_head);

static inline void reverse_in_type_spec     (type_spec *curr);
static inline void reverse_in_decl_specs    (decl_specs *curr);
static inline void reverse_in_expr          (expr *curr);
static inline void reverse_in_decltr        (decltr *curr);
static inline void reverse_in_initializer   (initializer *curr);
static inline void reverse_in_decl          (decl *curr);
static inline void reverse_in_stmt          (stmt *curr);
static inline void reverse_in_func_def      (func_def *curr);


// I realize that I used a suboptimal solution for list reversal
// Recursive list reversal may cause problems with the call stack for certain programs
// Although realistically, only a terrible programmer would write a program that exceeds max depth


static block_list *reverse_block_list(block_list *node, bool is_head) {
    block_list *new_head = (node->next) ? reverse_block_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    if (node->kind = BI_DECL) {
        reverse_in_decl(node->decl);
    } else if (node->kind == BI_STMT) {
        reverse_in_stmt(node->stmt);
    }

    return new_head;
}

static init_list *reverse_init_list(init_list *node, bool is_head) {
    init_list *new_head = (node->next) ? reverse_init_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_initializer(node->init);
    node->designation = reverse_designation(node->designation, true);

    return new_head;
}

static init_decltr *reverse_init_decltr_list(init_decltr *node, bool is_head) {
    init_decltr *new_head = (node->next) ? reverse_init_decltr_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_decltr(node->decltr);
    reverse_in_initializer(node->init);

    return new_head;
}

static param_list *reverse_param_list(param_list *node, bool is_head) {
    param_list *new_head = (node->next) ? reverse_param_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_decl(node->param_decl);

    return new_head;
}

static id_list *reverse_id_list(id_list *node, bool is_head) {
    id_list *new_head = (node->next) ? reverse_id_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    return new_head;
}

static decl_list *reverse_decl_list(decl_list *node, bool is_head) {
    decl_list *new_head = (node->next) ? reverse_decl_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_decl(node->curr);

    return new_head;
}

static struct_decltr_list *reverse_struct_decltr_list(struct_decltr_list *node, bool is_head) {
    struct_decltr_list *new_head = (node->next) ? reverse_struct_decltr_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_decltr(node->decltr);
    reverse_in_expr(node->bits);

    return new_head;
}

static struct_decl_list *reverse_struct_decl_list(struct_decl_list *node, bool is_head) {
    struct_decl_list *new_head = (node->next) ? reverse_struct_decl_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_decl_specs(node->specs);
    node->decltrs = reverse_struct_decltrs(node->decltrs, true);

    return new_head;
}

static enumerator_list *reverse_enumerator_list(enumerator_list *node, bool is_head) {
    enumerator_list *new_head = (node->next) ? reverse_enumerator_list(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_expr(node->const_val);

    return new_head;
}

static designator *reverse_designation(designator *node, bool is_head) {
    designator *new_head = (node->next) ? reverse_designation(node->next, false) : node;

    if (node->next) {
        node->next->next = node;
    }
    if (is_head) {
        node->next = 0;
    }

    // Reverse sublists
    reverse_in_expr(node->index);

    return new_head;
}

static inline void reverse_in_type_spec(type_spec *curr) {
    if (!curr) return;

    if (curr->kind == TS_SOU) {
        curr->sou->decls = reverse_struct_decl_list(curr->sou->decls, true);
    } else if (curr->kind == TS_ENUM) {
        curr->enums->enum_list = reverse_enumerator_list(curr->enums->enum_list, true);
    }
}

static inline void reverse_in_decl_specs(decl_specs *curr) {
    if (!curr) return;

    for (type_spec_list *spec = curr->type_specs; spec; spec = spec->next) {
        reverse_in_type_spec(spec->type);
    }
}

static inline void reverse_in_expr(expr *curr) {
    if (!curr || curr->kind != EXPR_INIT_LIST) return;

    curr->extra.init = reverse_init_list(curr->extra.init, true);
}

static inline void reverse_in_decltr(decltr *curr) {
    if (!curr) return;

    switch (curr->kind) {
        case DCTR_NESTED:
            reverse_in_decltr(curr->nested);
        case DCTR_ARRAY:
            reverse_in_expr(curr->array.size);
        case DCTR_FUNC_PROTO:
            reverse_param_list(curr->func.params, true);
        case DCTR_FUNC_KR:
            curr->kr_ids = reverse_id_list(curr->kr_ids, true);
    }
}

static inline void reverse_in_initializer(initializer *curr) {
    if (!curr) return;

    if (curr->kind == INIT_EXPR) {
        reverse_in_expr(curr->assignment);
    }
    if (curr->kind == INIT_LIST) {
        curr->list = reverse_init_list(curr->list, true);
    }
}

static inline void reverse_in_decl(decl *curr) {
    if (!curr) return;

    switch (curr->kind) {
        case DECL_NORMAL:
            curr->init_decltrs = reverse_init_decltr_list(curr->init_decltrs, true);
        case DECL_PARAM:
            reverse_in_decltr(curr->param_decltr);
    }
}

static inline void reverse_in_stmt(stmt *curr) {
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
    }
}

static inline void reverse_in_func_def(func_def *curr) {
    if (!curr) return;

    reverse_in_decltr(curr->decltr);
    reverse_in_stmt(curr->body);
    curr->decls = reverse_decl_list(curr->decls, true);
}

static translation_unit *reverse_lists(translation_unit *tree, bool is_head) {
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