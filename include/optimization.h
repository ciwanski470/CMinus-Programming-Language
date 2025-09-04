/*
    Header file that gives access to all functions used in compiler optimizations
*/

#pragma once

#include "ast.h"

struct fold_result {
    expr *res;
    bool success;
};

struct fold_result *fold_constants(expr *e);