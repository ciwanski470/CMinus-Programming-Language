/*
    Implementation of "optimization.h"
*/

#include "optimization.h"
#include "ast.h"
#include "error_handling.h"
#include "semantic_types.h"
#include <stdlib.h>

bool fold_constants(expr *e) {
    // SKIPPING CONSTANT FOLDING FOR NOW
    if (e->kind == EXPR_CONST) {
        return type_of_const(e->extra.const_val) != NULL;
    }
    else return false;

    // All code below is dead code

    if (!e || !e->type) return false;

    // Handle leaf nodes/base cases
    switch (e->kind) {
        case EXPR_ID: return false;
        case EXPR_CONST: return true;
        case EXPR_STR_LITERAL: return false;
        case EXPR_INIT_LIST: return false;
        case EXPR_SIZEOF_TYPE: {
            e->kind = EXPR_CONST;
            free_type_name(e->extra.type);
            unsigned long long size = size_of_type(e->extra.tn_type);
            e->extra.const_val = make_constant(CONSTANT_INT, "");
            e->extra.const_val->val.ul_val = size;
            e->extra.const_val->val_filled = true;
            return true;
        }
        case EXPR_SIZEOF_EXPR: {
            sem_type_t *type = e->left->type;
            unsigned long long size = size_of_type(type);
            free_expr(e->left);
            e->kind = EXPR_CONST;
            e->extra.const_val = make_constant(CONSTANT_INT, "");
            e->extra.const_val->val.ul_val = size;
            e->extra.const_val->val_filled = true;
            return true;
        }
        default:;
    }

    // Fill in later
}