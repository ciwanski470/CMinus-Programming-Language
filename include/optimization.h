/*
    Header file that gives access to all functions used in compiler optimizations
*/

#pragma once

#include "ast.h"
#include <stdlib.h>

/*
    Returns true if constants are successfully folded and false otherwise
    Note: ONLY works if the types of each expr is filled in using sem_type_t *type_of_expr(expr *e)
    Assumes the expression is valid
*/
bool fold_constants(expr *e);