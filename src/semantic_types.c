/*
    Implementation of "semantic_types.h"
*/

#include "semantic_symtab.h"
#include "semantic_types.h"
#include "ast.h"
#include "optimization.h"
#include "error_handling.h"
#include "decl_type.h"
#include "string_helpers.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>

// Array to pointers to sem_type_t
// Whenever a sem_type is allocated, it is added to this list
// As such, we do not need to worry about whether it is safe to free a sem_type_t
sem_type_t **all_sem_types;
size_t type_index = 0;
size_t type_capacity = 10;

sem_type_t *alloc_sem_type(void) {
    sem_type_t *t = calloc(1, sizeof(sem_type_t));
    check_alloc_error(t, "Alloc error when creating new sem_type");

    // Add the type into the all_sem_types array
    if (!all_sem_types) {
        all_sem_types = calloc(type_capacity, sizeof(sem_type_t *));
        all_sem_types[0] = t;
        type_index++;
    } else {
        if (type_index == type_capacity) {
            type_capacity = (3 * type_capacity) >> 1;
            all_sem_types = realloc(all_sem_types, type_capacity * sizeof(sem_type_t *));
        }
        all_sem_types[type_index] = t;
        type_index++;
    }
    return t;
}

sem_type_list_t *alloc_sem_type_list(sem_type_t *t) {
    sem_type_list_t *n = calloc(1, sizeof(sem_type_list_t));
    check_alloc_error(n, "Alloc error when creating new sem_type_list");

    n->type = t;
    n->next = NULL;
    return n;
}

sem_sou_info_t *alloc_sou_info(void) {
    sem_sou_info_t *sou = calloc(1, sizeof(sem_sou_info_t));
    check_alloc_error(sou, "Alloc error when creating new sem_type_list");
    return sou;
}

sem_type_t *make_primitive_type(sem_type_kind kind, bool is_signed, unsigned short quals) {
    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = kind;
    new_type->is_signed = is_signed;
    new_type->quals = quals;
    return new_type;
}

sem_type_t *make_pointer_type(sem_type_t *target, unsigned short quals) {
    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = ST_POINTER;
    new_type->ptr_target = target;
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

        if (!fold_constants(e->const_val)) {
            push_error("*** enum constant must be set to a constant value");
            return NULL;
        }
        
        constant *const_val = e->const_val->extra.const_val;
        if (const_val->kind != CONSTANT_INT) {
            push_error("*** enum constant must be an integer value");
            return NULL;
        }

        if (const_val->val.i_val < 0) {
            push_error("*** enum constant must fit within the range of \"unsigned short\"");
            return NULL;
        }

        sem_define_enum(e->name, const_val->val.i_val);
        val = const_val->val.i_val + 1;
    }

    return make_primitive_type(ST_SHORT, false, 0);
}

unsigned short make_qual_mask(type_qual_list *quals) {
    unsigned short mask = 0;
    for (type_qual_list *tql = quals; tql; tql = tql->next) {
        switch (tql->qual) {
            case TQ_CONST: mask |= TQ_CONST_MASK; break;
            case TQ_RESTRICT: mask |= TQ_RESTRICT_MASK; break;
            case TQ_VOLATILE: mask |= TQ_VOLATILE_MASK; break;
        }
    }
    return mask;
}

void free_sem_type(sem_type_t *type);
void free_sem_type_list(sem_type_list_t *type_list);
void free_sem_sou_info(sem_sou_info_t *sou);

void free_sem_type(sem_type_t *type) {
    if (!type) return;

    if (type->kind == ST_STRUCT || type->kind == ST_UNION) {
        free_sem_sou_info(type->sou_info);
    } else if (type->kind == ST_FUNC) {
        free_sem_type_list(type->func_info.params);
        free_sem_type(type->func_info.return_type);
    } else if (type->kind == ST_ARRAY) {
        free_sem_type(type->arr_info.element_type);
    }

    free(type);
}

void free_sem_type_list(sem_type_list_t *type_list) {
    while (type_list->next) {
        free_sem_type(type_list->type);
        type_list = type_list->next;
    }
}

void free_sem_sou_info(sem_sou_info_t *sou) {
    for (sem_member_t *member = sou->members; member;) {
        free(member->name);
        free_sem_type(member->type);
        sem_member_t *temp = member;
        member = member->next;
        free(temp);
    }
}

void free_all_sem_types(void) {
    for (int i=0; i<type_index; i++) {
        free_sem_type(all_sem_types[i]);
    }
}

bool types_equal(sem_type_t *a, sem_type_t *b) {
    if (!a || !b || a->kind != b->kind) return false;
    
    if (ST_INT <= a->kind && a->kind <= ST_CHAR) { // a and b are integer types
        return a->is_signed == b->is_signed;
    }

    if (ST_VOID <= a->kind && a->kind <= ST_BOOL) {
        return true;
    }

    if (a->kind == ST_POINTER) {
        if (!types_equal(a->ptr_target, b->ptr_target)) return false;
        if (a->quals != b->quals) return false;
        return true;
    }

    if (a->kind == ST_ARRAY) {
        if (!types_equal(a->arr_info.element_type, b->arr_info.element_type)) return false;
        if (a->arr_info.size != b->arr_info.size) return false;
        return true;
    }

    if (a->kind == ST_FUNC) {
        if (!types_equal(a->func_info.return_type, b->func_info.return_type)) return false;

        sem_type_list_t *a_params = a->func_info.params;
        sem_type_list_t *b_params = b->func_info.params;
        while (a_params && b_params) {
            if (!types_equal(a_params->type, b_params->type)) return false;
            a_params = a_params->next;
            b_params = b_params->next;
        }

        if (!a_params && !b_params) return true;
        return false;
    }

    if (a->kind == ST_STRUCT || a->kind == ST_UNION) {
        // They must point to the same exact struct or union
        return a->sou_info == b->sou_info;
    }

    return false;
}

bool type_is_scalar(sem_type_t *type) {
    switch (type->kind) {
        case ST_BOOL: case ST_INT: case ST_CHAR: case ST_SHORT: case ST_LONG: case ST_LL:
        case ST_FLOAT: case ST_DOUBLE:
            return true;
        default:
            return false;
    }
}

bool type_is_integral(sem_type_t *type) {
    return
        type->kind == ST_BOOL ||
        type->kind == ST_SHORT ||
        type->kind == ST_INT ||
        type->kind == ST_CHAR ||
        type->kind == ST_LONG ||
        type->kind == ST_LL;
}

bool type_is_float(sem_type_t *type) {
    return type->kind == ST_FLOAT || type->kind == ST_DOUBLE;
}

#define set_return(type) \
    ret_type = type; \
    break;

#define check_error(condition, message, ...) \
    if (condition) { \
        push_error(message, ##__VA_ARGS__); \
        return NULL; \
    }

sem_type_t *type_of_expr(expr *e) {
    if (!e) return NULL;
    if (e->type) return e->type;
    
    sem_type_t *left_type = NULL;
    sem_type_t *right_type = NULL;

    sem_type_t *ret_type = NULL;

    // Base case
    switch (e->kind) {
        case EXPR_ID: {
            sem_symbol_t *sym = sem_lookup_id(e->extra.id);

            check_error(!sym, "*** identifier not found")

            e->type = sym->type;
            return e->type;
        }
        case EXPR_CONST: {
            sem_type_t *ct = type_of_const(e->extra.const_val);
            e->type = ct;
            return ct;
        }
        case EXPR_STR_LITERAL: {
            size_t size = size_of_string_lit(e->extra.str_val);
            check_error(size == SIZE_MAX, "*** string is invalid")

            e->type = make_pointer_type(make_primitive_type(ST_CHAR, true, 0), 0);
            return e->type;
        }
        case EXPR_INIT_LIST:
            push_error("*** vro...");
            return NULL;
        case EXPR_SIZEOF_TYPE: {
            sem_type_t *type = decl_type(e->extra.type->specs, e->extra.type->suffix, false);

            check_error(!type, "*** sizeof type is not a valid type")
            check_error(type->kind == ST_FUNC, "*** sizeof type cannot be a function type")
            check_error(!resolve_sou(type), "*** sizeof type must be complete")

            e->extra.tn_type = type;
            e->type = make_primitive_type(ST_LONG, false, 0);
            return e->type;
        }
        default:
            // No base case; evaluate the left and right
            left_type = type_of_expr(e->left);
            right_type = type_of_expr(e->right);
            //printf("Left type: %s\n", type_to_s(left_type));
            //printf("Right type: %s\n", type_to_s(right_type));
    }

    // Check if the needed left and right exist
    switch (e->kind) {
        // This block all requires both the left and right nodes
        case EXPR_SUBSCRIPT: case EXPR_MUL: case EXPR_DIV: case EXPR_MOD:
        case EXPR_ADD: case EXPR_SUB: case EXPR_LSHIFT: case EXPR_RSHIFT:
        case EXPR_LT: case EXPR_GT: case EXPR_LEQ: case EXPR_GEQ: case EXPR_EQ: case EXPR_NEQ:
        case EXPR_BITAND: case EXPR_BITOR: case EXPR_BITXOR: case EXPR_LOGAND: case EXPR_LOGOR:
        case EXPR_CONDITIONAL: case EXPR_ASSIGN:
            if (!right_type) {
                return NULL;
            }
        // All other expressions only require a left node
        default:
            if (!left_type) {
                return NULL;
            }
    }

    // See what type the result will be
    switch (e->kind) {
        case EXPR_CALL: {
            check_error(left_type->kind != ST_FUNC, "*** cannot call something that isn't a function")
            sem_type_list_t *params = left_type->func_info.params;
            expr *args = e->right;
            while (params && args) {
                check_error(
                    types_parsable(args->type, params->type) != PARSE_IMPLICIT,
                    "*** argument and parameter types do not match"
                )
                params = params->next;
                args = args->right;
            }
            check_error(args && !left_type->func_info.variadic, "*** function call has too many arguments")
            check_error(params, "*** function call has too few arguments")

            set_return(left_type->func_info.return_type)
        }
        case EXPR_SUBSCRIPT: {
            check_error(!type_is_integral(right_type), "*** cannot index with non-integer value")
            check_error(
                left_type->kind != ST_POINTER && left_type->kind != ST_ARRAY,
                "*** non-pointer/array type cannot be indexed"
            )

            if (left_type->kind == ST_POINTER) {
                set_return(left_type->ptr_target)
            } else {
                set_return(left_type->arr_info.element_type)
            }
        }
        case EXPR_MEMBER_ARROW: {
            check_error(!resolve_sou(left_type), "*** cannot dereference incomplete type")
            check_error(
                left_type->kind != ST_POINTER,
                "*** can only use arrow member access with a pointer to struct or union; type: %s; member: %s",
                type_to_s(left_type),
                e->extra.id
            )
            left_type = left_type->ptr_target;
            // Falls through into EXPR_MEMBER_DOT
        }
        case EXPR_MEMBER_DOT: {
            check_error(
                left_type->kind != ST_STRUCT && left_type->kind != ST_UNION,
                "*** member access only allowed for struct and union types"
            )

            printf("SoU %s accessing member %s\n", left_type->sou_info->name, e->extra.id);

            sem_member_t *member = get_sou_member(left_type->sou_info, e->extra.id);
            check_error(!member, "*** member does not exist")
            check_error(!member->type, "*** member somehow does not have type")

            set_return(member->type)
        }
        case EXPR_POST_INCR: case EXPR_POST_DECR: case EXPR_PRE_INCR: case EXPR_PRE_DECR:
            check_error(!type_is_scalar(left_type), "*** can only increment and decrement scalar types")
            set_return(left_type)
        case EXPR_ARG:
            set_return(left_type)
        case EXPR_ADDREF:
            check_error(
                e->left->kind != EXPR_ID &&
                e->left->kind != EXPR_MEMBER_ARROW &&
                e->left->kind != EXPR_MEMBER_DOT &&
                e->left->kind != EXPR_DEREF &&
                e->left->kind != EXPR_SUBSCRIPT,
                "*** can only take the reference of a valid lvalue"
            )
            set_return(make_pointer_type(left_type, 0))
        case EXPR_DEREF:
            check_error(
                left_type->kind != ST_POINTER && left_type->kind != ST_ARRAY,
                "*** cannot dereference non-pointer type"
            )
            check_error(!resolve_sou(left_type), "*** cannot dereference incomplete type")
            set_return(left_type->ptr_target)
        case EXPR_MINUS:
            check_error(!type_is_scalar(left_type), "*** minus operator can only be used on scalar types")
            set_return(left_type);
        case EXPR_BITNOT:
            check_error(
                !type_is_integral(left_type),
                "*** all operands must be of integer type for bitwise operations"
            )
            set_return(left_type)
        case EXPR_LOGNOT:
            check_error(
                !type_is_scalar(left_type) && left_type->kind != ST_POINTER,
                "*** logical not can only be used on scalar and pointer types"
            )
            set_return(make_primitive_type(ST_INT, true, 0))
        case EXPR_SIZEOF_EXPR:
            check_error(left_type->kind == ST_FUNC, "*** sizeof type cannot be a function type")
            check_error(!resolve_sou(left_type), "*** sizeof type is incomplete")
            set_return(make_primitive_type(ST_LONG, false, 0))
        case EXPR_CAST: {
            sem_type_t *type = decl_type(e->extra.type->specs, e->extra.type->suffix, false);
            check_error(!type, "*** invalid type for cast expression")
            check_error(
                types_parsable(right_type, type) == PARSE_ILLEGAL,
                "*** illegal cast expression"
            )
            set_return(type)
        }
        case EXPR_MUL: case EXPR_DIV: case EXPR_MOD: case EXPR_ADD: case EXPR_SUB:
            // Note that I did not account for pointer arithmetic
            check_error(
                !type_is_scalar(left_type) || !type_is_scalar(right_type),
                "*** arithmetic expression requires two scalar types"
            )
            // For promotions, maybe change the child expression type to its promoted type
            set_return(arithmetic_promotion(left_type, right_type))
        case EXPR_LSHIFT: case EXPR_RSHIFT: {
            check_error(
                !type_is_integral(left_type) || !type_is_integral(right_type),
                "*** shift operation requires two integer types"
            )
            // lowk a memory leak teehee
            sem_type_t *int_type = make_primitive_type(ST_INT, true, 0);
            set_return(arithmetic_promotion(left_type, int_type))
        }
        case EXPR_EQ: case EXPR_NEQ:
            if (left_type->kind != ST_POINTER || right_type->kind != ST_POINTER) {
                check_error(
                    !type_is_scalar(left_type) || !type_is_scalar(right_type),
                    "*** equality expressions require both operands as scalars or pointers"
                )
            }
            set_return(make_primitive_type(ST_BOOL, true, 0))
        case EXPR_LT: case EXPR_GT: case EXPR_LEQ: case EXPR_GEQ:
            check_error(
                (!type_is_scalar(left_type) && left_type->kind != ST_POINTER) ||
                (!type_is_scalar(right_type) && right_type->kind != ST_POINTER),
                "*** relational expressions require both operands as scalar"
            )
            set_return(make_primitive_type(ST_BOOL, true, 0))
        case EXPR_BITAND: case EXPR_BITOR: case EXPR_BITXOR: {
            check_error(
                !type_is_integral(left_type) || !type_is_integral(right_type),
                "*** all operands must be integer type for bitwise operations"
            )
            sem_type_t *int_type = make_primitive_type(ST_INT, true, 0);
            set_return(arithmetic_promotion(left_type, int_type))
        }
        case EXPR_LOGAND: case EXPR_LOGOR:
            check_error(
                !type_is_integral(left_type) || !type_is_integral(right_type),
                "*** all operands must be integer type for logical operations"
            )
            set_return(make_primitive_type(ST_INT, true, 0))
        case EXPR_CONDITIONAL: {
            sem_type_t *cond_type = type_of_expr(e->extra.conditional);
            check_error(
                !type_is_scalar(cond_type) && cond_type->kind != ST_POINTER,
                "*** conditional expression must be of integer type"
            )
            check_error(
                types_parsable(left_type, right_type) != PARSE_IMPLICIT ||
                types_parsable(right_type, left_type) != PARSE_IMPLICIT,
                "*** ternary expression requires both results to be of similar type; left type: %s; right type: %s",
                type_to_s(left_type), type_to_s(right_type)
            )
            set_return(left_type) // right_type works too
        }
        case EXPR_ASSIGN: {
            bool modifiable = false;
            switch (e->left->kind) {
                case EXPR_DEREF: case EXPR_SUBSCRIPT:
                case EXPR_MEMBER_ARROW: case EXPR_MEMBER_DOT:
                case EXPR_ID:
                    modifiable = true;
                default:;
            }
            if (left_type->quals & TQ_CONST_MASK) {
                modifiable = false;
            }
            check_error(!modifiable, "*** assignment expression requires modifiable lvalue")
            set_return(right_type)
        }
        default:;
    }

    e->type = ret_type;
    return ret_type;
}

sem_type_t *type_of_const(constant *c) {
    sem_type_t *ret_type = NULL;

    switch (c->kind) {
        case CONSTANT_ENUM:
            // The enum is guaranteed to be defined
            set_return(make_primitive_type(ST_SHORT, false, 0))
        case CONSTANT_INT: {
            sem_type_t *new_type = alloc_sem_type();
            const char *s = c->value;

            // Unsigned char
            if (*s == 'u' || *s == 'U') {
                new_type->kind = ST_CHAR;
                new_type->is_signed = false;
                set_return(new_type)
            }

            // Signed char
            if (*s == '\'') {
                new_type->kind = ST_CHAR;
                new_type->is_signed = true;
                set_return(new_type)
            }

            // Go to the characters past the digits
            while (0 <= *s - '0' && *s - '0' <= 9) s++;

            // Check for signedness
            if (*s == 'u' || *s == 'U') {
                new_type->is_signed = false;
                s++;
            } else {
                new_type->is_signed = true;
            }

            // Check for size
            if (*s == 'l' || *s == 'L') {
                if (*(s+1) == 'l' || *(s+1) == 'L') {
                    new_type->kind = ST_LL;
                } else {
                    new_type->kind = ST_LONG;
                }
            } else if (*s == 's' || *s == 'S') {
                new_type->kind = ST_SHORT;
            } else {
                new_type->kind = ST_INT;
            }
            set_return(new_type)
        }
        case CONSTANT_FLOAT: {
            sem_type_t *new_type = alloc_sem_type();
            const char *s = c->value;

            while (*s == '.' || (0 <= *s - '0' && *s - '0' <= 9)) s++;

            if (*s == 'f' || *s == 'F') {
                new_type->kind = ST_FLOAT;
            } else {
                new_type->kind = ST_DOUBLE;
            }

            set_return(new_type)
        }
        case CONSTANT_PTR:
            set_return(make_pointer_type(make_primitive_type(ST_VOID, false, 0), 0))
    }

    return (ret_type && fill_const_val(c, ret_type)) ? ret_type : NULL;
}

bool fill_const_val(constant *c, sem_type_t *type) {
    if (c->val_filled) return true;

    switch (type->kind) {
        case ST_CHAR:
            if (type->is_signed) {
                c->val.c_val = get_char_val(c->value);
            } else {
                c->val.uc_val = get_char_val(c->value);
            }
            break;
        case ST_SHORT: {
            // Find the value and check validity
            char *endptr;
            int a = strtol(c->value, &endptr, 10);
            if (type->is_signed) {
                if (a < INT16_MIN || a > INT16_MAX) {
                    push_error("*** constant does not fit in signed short");
                    return false;
                }
                c->val.s_val = a;
            } else {
                if (a < 0 || a > UINT16_MAX) {
                    push_error("*** constant does not fit in unsigned short");
                    return false;
                }
                c->val.us_val = a;
            }
            break;
        }
        case ST_INT: {
            char *endptr;
            long long a = strtoll(c->value, &endptr, 10);
            if (type->is_signed) {
                if (a < INT32_MIN || a > INT32_MAX) {
                    push_error("*** constant does not fit in signed int");
                    return false;
                }
                c->val.i_val = a;
            } else {
                if (a < 0 || a > UINT32_MAX) {
                    push_error("*** constant does not fit in unsigned int");
                    return false;
                }
                c->val.ui_val = a;
            }
            break;
        }
        case ST_LONG: case ST_LL: {
            errno = 0;
            char *endptr;
            
            if (type->is_signed) {
                long long a = strtoll(c->value, &endptr, 10);
                if (errno == ERANGE) {
                    push_error("*** constant does not fit in signed long");
                    return false;
                }
                c->val.l_val = a;
            } else {
                unsigned long long a = strtoull(c->value, &endptr, 10);
                if (errno == ERANGE) {
                    push_error("*** constant does not fit in unsigned long");
                    return false;
                }
                c->val.ul_val = a;
            }
            break;
        }
        case ST_POINTER: {
            errno = 0;
            char *endptr;

            unsigned long a = strtoul(c->value, &endptr, 10);
            if (errno == ERANGE) {
                push_error("*** constant does not fit in pointer range (unsigned long)");
                return false;
            }
            c->val.p_val = a;
            break;
        }
        case ST_FLOAT: {
            errno = 0;
            char *endptr;

            float a = strtof(c->value, &endptr);

            if (errno == ERANGE && (a == HUGE_VAL || a == -HUGE_VAL)) {
                push_error("*** constant does not fit in float range");
                return false;
            }
            c->val.f_val = a;
            break;
        }
        case ST_DOUBLE: {
            errno = 0;
            char *endptr;

            double a = strtod(c->value, &endptr);

            if (errno == ERANGE && (a == HUGE_VAL || a == -HUGE_VAL)) {
                push_error("*** constant does not fit in double range");
                return false;
            }
            c->val.d_val = a;
            break;
        }
        default:
            push_error("*** erm what the sigma");
            return false;
    }
    
    c->val_filled = true;
    return true;
}

parse_req expr_compatible(expr *e, sem_type_t *type) {
    sem_type_t *e_type = type_of_expr(e);
    if (type->kind == ST_POINTER && type_is_integral(e_type)) {
        if (
            e->kind == EXPR_CONST &&
            fill_const_val(e->extra.const_val, e_type) &&
            e->extra.const_val->val.p_val == 0
        ) {
            return PARSE_IMPLICIT;
        } else {
            push_error("*** integer expression requires must be equal to 0 for implicit cast to pointer");
        }
    }
    return types_parsable(type_of_expr(e), type);
}

parse_req types_parsable(sem_type_t *from, sem_type_t *to) {
    if (!from || !to) return PARSE_ILLEGAL;

    if (types_equal(from, to)) {
        return PARSE_IMPLICIT;
    }

    if (
        (type_is_integral(from) && type_is_integral(to)) ||
        (type_is_float(from) && type_is_float(to))
    ) {
        return PARSE_IMPLICIT;
    }

    if (type_is_scalar(from) && type_is_scalar(to)) {
        return PARSE_IMPLICIT;
    }

    if (from->kind == ST_POINTER && to->kind == ST_POINTER) {
        return PARSE_IMPLICIT;
    }

    if (
        from->kind == ST_ARRAY && to->kind == ST_POINTER &&
        types_parsable(from->arr_info.element_type, to->ptr_target)
    ) {
        return PARSE_EXPLICIT;
    }

    return PARSE_ILLEGAL;
}

size_t size_of_type(sem_type_t *type) {
    switch (type->kind) {
        case ST_VOID:
            return 0;
        case ST_BOOL: case ST_CHAR:
            return 1;
        case ST_SHORT:
            return 2;
        case ST_INT: case ST_FLOAT:
            return 4;
        case ST_LONG: case ST_LL: case ST_DOUBLE: case ST_POINTER:
            return 8;
        // Highkey don't wanna do it myself
        case ST_ARRAY:
            return SIZE_MAX;
        case ST_UNION: case ST_STRUCT:
            return SIZE_MAX;
        case ST_FUNC:
            return SIZE_MAX;
    }
    return SIZE_MAX;
}

sem_type_t *larger_type(sem_type_t *a, sem_type_t *b) {
    if (size_of_type(a) >= size_of_type(b)) {
        return a;
    }
    return b;
}

sem_type_t *arithmetic_promotion(sem_type_t *a, sem_type_t *b) {
    if (!type_is_integral(a) || !type_is_integral(b)) return NULL;
    return larger_type(a, b);
}

size_t size_of_string_lit(const char *s) {
    int n = strlen(s);
    size_t size = 0;
    for (int i=1; i<n-1; i++) {
        size++;
        if (s[i] == '\\') {
            if (i == n-1 || i == n-2) return SIZE_MAX;
            switch (s[i+1]) {
                case 'a': case 'b': case 'f': case 'n': case 'r':
                case 't': case 'v': case '\\': case '\'': case '\"':
                case '?': case '0':
                    i++; size++; break;
                default: return SIZE_MAX;
            }
        }
    }
    return size;
}

int get_char_val(const char *s) {
    bool us = false;
    if (*s == 'u' || *s == 'U') {
        us = true;
        s++;
    }

    int escape_vals[256] = {0};
    escape_vals['a'] = '\a';
    escape_vals['b'] = '\b';
    escape_vals['f'] = '\f';
    escape_vals['n'] = '\n';
    escape_vals['r'] = '\r';
    escape_vals['t'] = '\t';
    escape_vals['v'] = '\v';
    escape_vals['\\'] = '\\';
    escape_vals['\''] = '\'';
    escape_vals['\"'] = '\"';
    escape_vals['?'] = '\?';
    escape_vals['0'] = '\0';

    int val = s[1];

    if (s[1] == '\\') {
        val = escape_vals[s[2]];
    }
    
    union {
        signed char sc;
        unsigned char uc;
    } u;
    u.sc = val;
    return (us) ? u.uc : u.sc;
}

typedef struct sou_info_entry {
    sem_sou_info_t *info;
    struct sou_info_entry *next;
} *sou_info_set_t[31];

static bool resolve_sou_solver(sem_type_t *sou_type, sou_info_set_t *seen) {
    // Non-SoUs are resolved by default
    if (sou_type->kind != ST_STRUCT && sou_type->kind != ST_UNION) return true;
    if (sou_type->sou_info->complete) return true;

    sem_sou_info_t *info = sou_type->sou_info;

    int hash = ((uintptr_t) info) % 31;

    // Ensure we haven't already seen this sou_info
    for (struct sou_info_entry *entry = (*seen)[hash]; entry; entry = entry->next) {
        if (entry->info == info) return false;
    }

    struct sou_info_entry *new_entry = calloc(1, sizeof(struct sou_info_entry));
    new_entry->info = info;
    new_entry->next = (*seen)[hash];
    (*seen)[hash] = new_entry;

    for (sem_member_t *mem = info->members; mem; mem = mem->next) {
        if (!resolve_sou_solver(mem->type, seen)) return false;
    }
    info->complete = true;
    return true;
}

bool resolve_sou(sem_type_t *sou_type) {
    sou_info_set_t seen;
    return resolve_sou_solver(sou_type, &seen);
}

sem_member_t *get_sou_member(sem_sou_info_t *sou, const char *name) {
    for (sem_member_t *mem = sou->members; mem; mem = mem->next) {
        if (strcmp(mem->name, name) == 0) {
            return mem;
        }
    }
    return NULL;
}

sem_type_t *make_sou_type(sou_spec *sou) {
    printf("Making SoU type\n");

    sem_sou_info_t *info = alloc_sou_info();
    sem_member_t *prev_member = NULL;

    // Quick hash table
    struct entry {
        char *id;
        struct entry *next;
    };
    struct entry *ids[31] = {NULL};

    bool valid = true;

    for (struct_decl_list *d = sou->decls; d; d = d->next) {
        for (struct_decltr_list *dctr = d->decltrs; dctr; dctr = dctr->next) {
            // Check for duplicate ids
            size_t hash = str_hash(dctr->decltr->id, 31);
            for (struct entry *curr = ids[hash]; curr; curr = curr->next) {
                if (curr->id && dctr->decltr->id && strcmp(curr->id, dctr->decltr->id) == 0) {
                    valid = false;
                    goto early_break;
                }
            }

            sem_type_t *member_type = decl_type(d->specs, dctr->decltr, false);
            if (!member_type) {
                push_error("*** SoU member type is invalid");
                valid = false;
                goto early_break;
            }

            sem_member_t *new_member = calloc(1, sizeof(sem_member_t));
            new_member->type = member_type;
            new_member->name = dctr->decltr->id;
            new_member->next = NULL;
            if (prev_member) {
                prev_member->next = new_member;
            } else {
                prev_member = new_member;
                info->members = new_member;
            }
            prev_member = new_member;

            // Add this id to the hash table
            struct entry *new_hash_entry = calloc(1, sizeof(struct entry));
            new_hash_entry->id = dctr->decltr->id;
            new_hash_entry->next = ids[hash];
            ids[hash] = new_hash_entry;
        }
    }

    early_break:
    if (!valid) {
        for (int i=0; i<31; i++) {
            for (struct entry *curr = ids[i]; curr;) {
                struct entry *next = curr->next;
                free(curr);
                curr = next;
            }
        }
        for (sem_member_t *member = info->members; member;) {
            sem_member_t *next_member = member->next;
            free(member);
            member = next_member;
        }
        free(info);
        return NULL;
    }

    info->complete = true;
    info->name = sou->name;

    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = sou->kind == SOU_STRUCT ? ST_STRUCT : ST_UNION;
    new_type->sou_info = info;
    return new_type;
}