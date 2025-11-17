/*
    Contains helper functions involving strings
    Needed in multiple files across different stages
*/

#pragma once

#include "semantic_types.h"
#include <stdlib.h>

/*
    Computes a hash for the given string and returns it with the given modulo
    Implemented using the FNV-1a algorithm
*/
size_t str_hash(const char *str, const int mod);

/*
    Formats a sem_type_t as a string
*/
const char *type_to_s(sem_type_t *t);