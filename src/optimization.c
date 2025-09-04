/*
    Implementation of "optimization.h"
*/

#include "optimization.h"
#include "ast.h"
#include "error_handling.h"
#include <stdlib.h>

struct fold_result *fold_constants(expr *e) {
    if (!e) return 0;

    struct fold_result *result = calloc(1, sizeof(struct fold_result));

    if (e->kind == EXPR_CONST) {
        result->res = e;
        result->success = true;
        return result;
    }

    struct fold_result *left_res = fold_constants(e->left);
    struct fold_result *right_res = fold_constants(e->right);

    if (!left_res->success || !right_res->success) {
        result->res = e;
        result->success = false;
        return result;
    }

    // Fill in later
}