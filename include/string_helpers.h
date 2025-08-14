/*
    Contains helper functions involving strings
    Needed in multiple files across different stages
*/

#pragma once

#include <stdlib.h>

/*
    Computes a hash for the given string and returns it with the given modulo
    Implemented using the FNV-1a algorithm
*/
size_t str_hash(const char *str, const int mod);