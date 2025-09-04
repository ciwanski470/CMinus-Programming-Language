/*
    Implementation of "semantic_types.h"
*/

#include "semantic_symtab.h"
#include "semantic_types.h"
#include "ast.h"
#include "optimization.h"
#include "error_handling.h"
#include <stdbool.h>

sem_type_t *alloc_sem_type(void) {
    sem_type_t *t = calloc(1, sizeof(sem_type_t));
    check_alloc_error(t, "Alloc error when creating new sem_type");

    return t;
}

sem_type_list_t *alloc_sem_type_list(sem_type_t *t) {
    sem_type_list_t *n = calloc(1, sizeof(sem_type_list_t));
    check_alloc_error(n, "Alloc error when creating new sem_type_list");

    n->type = t;
    n->next = NULL;
    return n;
}

sem_type_t *make_primitive_type(sem_type_kind kind, bool is_signed, unsigned short quals) {
    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = kind;
    new_type->is_signed = is_signed;
    new_type->quals = quals;
    return new_type;
}

sem_type_t *make_pointer_type(unsigned short quals) {
    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = ST_POINTER;
    new_type->quals = quals;
    return new_type;
}

sem_type_t *make_array_type(sem_type_t *element_type, size_t size, bool incomplete) {
    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = ST_ARRAY;
    new_type->arr_info.element_type = element_type;
    new_type->arr_info.size = size;
    new_type->arr_info.incomplete = incomplete;
    return new_type;
}

sem_type_t *make_func_type(sem_type_t *return_type, sem_type_list_t *params, bool variadic) {
    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = ST_FUNC;
    new_type->func_info.return_type = return_type;
    new_type->func_info.params = params;
    new_type->func_info.variadic = variadic;
    return new_type;
}

sem_type_t *make_enum_type(enum_spec *enums) {
    unsigned short val = 0;
    for (enumerator_list *e = enums->enum_list; e; e = e->next) {
        if (!e->const_val) {
            sem_define_enum(e->name, val);
            val++;
            continue;
        }

        struct fold_result *fold_res = fold_constants(e->const_val);
        if (!fold_res->success) {
            push_error("*** enum constant must be set to a constant value");
            return NULL;
        }
        
        constant *const_val = fold_res->res->extra.const_val;
        if (const_val->kind != CONSTANT_INT) {
            push_error("*** enum constant must be a integral value");
            return NULL;
        }

        if (const_val->int_val < 0) {
            push_error("*** enum constant must fit within the range of \"unsigned short\"");
            return NULL;
        }

        sem_define_enum(e->name, const_val->int_val);
        val = const_val->int_val + 1;
    }

    return make_primitive_type(ST_SHORT, false, 0);
}

sem_type_t *make_sou_type(sou_spec *sou) {
    sem_sou_info_t *sou_info;
    
}

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