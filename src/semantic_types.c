/*
    Implementation of "semantic_types.h"
*/

#include "semantic_types.h"
#include <stdbool.h>

bool types_equal(sem_type_t *a, sem_type_t *b) {
    if (a->kind != b->kind) return false;
    
    
    if (ST_INT <= a->kind && a->kind <= ST_CHAR) { // a and b are integer types
        return a->is_signed == b->is_signed;
    }

    if (ST_VOID <= a->kind && a->kind <= ST_LDIMAGINARY) {
        return true;
    }

    if (a->kind == ST_FUNC) {
        // Compare return type and parameter types
    }

    if (a->kind == ST_STRUCT || a->kind == ST_UNION) {
        // Compare struct declarations
    }

    return false;
}

parse_req types_parsable(sem_type_t *from, sem_type_t *to) {
    // Unfilled
}