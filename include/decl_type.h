/*
    File contains one function, which converts decl_specs + decltr -> sem_type_t
    References "ast.h" and "semantic_types.h"
*/

#pragma once

#include "ast.h"
#include "semantic_types.h"
#include <stdbool.h>

/*
    Constructs a sem_type_t for based on the given declaration specifiers and declarator
    Returns NULL if invalid
*/
sem_type_t *decl_type(decl_specs *specs, decltr *d, bool is_param);