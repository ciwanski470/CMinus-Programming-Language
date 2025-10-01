/*
    Implementation of "decl_type.h"
*/

#include "decl_type.h"
#include "semantic_symtab.h"
#include "error_handling.h"
#include "ast.h"
#include "optimization.h"
#include <stdbool.h>
#include <stdlib.h>

/*
    Helpers and allocators
*/

// Returns false if invalid and true if valid
static bool validate_type_specs(type_spec_list *tsl) {
    if (!tsl) return true;

    size_t total_specs = 0;
    int *count = calloc(MAX_TS_KIND + 1, sizeof(int));
    check_alloc_error(count, "Alloc error when creating new count array");

    for (type_spec_list *t = tsl; t; t = t->next) {
        count[t->type->kind]++;
        total_specs++;
    }

    // These types must be alone if they are used at all
    if (count[TS_TYPEDEF] + count[TS_ENUM] + count[TS_SOU] + count[TS_VOID] + count[TS_BOOL] > 0 && total_specs > 1) {
        free(count);
        return false;
    }

    for (int kind = 0; kind <= MAX_TS_KIND; kind++) {
        // Only long can have more than one copy
        if (kind == TS_LONG) {
            if (count[kind] > 2) {
                free(count);
                return false;
            }
        } else {
            if (count[kind] > 1) {
                free(count);
                return false;
            }

            // Long can only be used with "int" and "double"
            if (count[kind] && count[TS_LONG] && kind != TS_INT && kind != TS_DOUBLE) {
                return false;
            }
        }
    }

    // Can't have both short and long or both signed and unsigned
    if ((count[TS_SHORT] && count[TS_LONG]) || (count[TS_SIGNED] && count[TS_UNSIGNED])) {
        free(count);
        return false;
    }

    // First handle the case where "long" is used with "double"
    // After this, long can only be with int
    if (total_specs == 2 && count[TS_LONG] && count[TS_DOUBLE]) {
        free(count);
        return true;
    }

    // Separate the integer and floating point types
    int total_int = count[TS_CHAR] + count[TS_SHORT] + count[TS_INT] + count[TS_LONG] + count[TS_SIGNED] + count[TS_UNSIGNED];
    int total_float = count[TS_FLOAT] + count[TS_DOUBLE];

    // Can't have both int and float types
    if (total_int > 0 && total_float > 0) {
        free(count);
        return false;
    }

    // signed/unsigned can only appear with integer types
    if (
        (count[TS_SIGNED] || count[TS_UNSIGNED]) &&
        !(count[TS_CHAR] || count[TS_SHORT] || count[TS_INT] || count[TS_LONG])
    ) {
        free(count);
        return false;
    }

    // int can only appear with long, short, signed, and unsigned
    if (
        count[TS_INT] &&
        count[TS_INT] + count[TS_LONG] + count[TS_SHORT] + count[TS_SIGNED] + count[TS_UNSIGNED] < total_specs
    ) {
        free(count);
        return false;
    }

    // char can only appear with signed and unsigned
    if (
        count[TS_CHAR] &&
        count[TS_CHAR] + count[TS_SIGNED] + count[TS_UNSIGNED] < total_specs
    ) {
        free(count);
        return false;
    }

    // All checks passed
    return true;
}

static sem_type_t *type_from_decl_specs(decl_specs *specs) {
    if (!specs) return NULL;
    if (!validate_type_specs(specs->type_specs)) {
        push_error("*** invalid combination of type specifiers");
        return NULL;
    }

    type_spec_list *tsl = specs->type_specs;
    unsigned short quals = make_qual_mask(specs->type_quals);

    // Handle special types (TS_ENUM, TS_TYPEDEF, TS_SOU)
    tsl = specs->type_specs;
    for (; tsl; tsl = tsl->next) {
        type_spec *ts = tsl->type;
        if (ts->kind == TS_ENUM) {
            enum_spec *enums = ts->enums;
            sem_symbol_t *sym = sem_lookup_tag(enums->name);

            // Redefinition
            if (sym && sym->is_definition && enums->enum_list) {
                push_error("*** illegal redefinition of an enum");
                return NULL;
            }

            // Wrong tag kind
            if (sym && sym->type->kind != ST_SHORT) {
                push_error("*** tag not of struct kind used as struct");
                return NULL;
            }

            // First definition
            if (enums->enum_list) {
                sem_type_t *enum_type = make_enum_type(enums);
                if (enums->name) sem_define_tag(enums->name, enum_type);
                return enum_type;
            }

            // No definition (although that is unimportant for enums)
            if (!sym) {
                sym = sem_declare_tag(enums->name, ST_SHORT);
            }
            sem_type_t *new_type = alloc_sem_type();
            new_type->kind = sym->type->kind;
            new_type->quals = quals;
            return new_type;
        } else if (ts->kind == TS_SOU) {
            sou_spec *sou = ts->sou;
            sem_symbol_t *sym = sem_lookup_tag(sou->name);

            // Redefinition
            if (sym && sym->is_definition && sou->decls) {
                push_error("*** illegal redefinition of a struct or union");
                return NULL;
            }

            // Wrong tag kind
            if (sym && sou->kind == SOU_STRUCT && sym->type->kind != ST_STRUCT) {
                push_error("*** tag not of struct kind used as struct");
                return NULL;
            }
            if (sym && sou->kind == SOU_UNION && sym->type->kind != ST_UNION) {
                push_error("*** tag not of union kind used as union");
                return NULL;
            }

            // First definition
            if (sou->decls) {
                sem_type_t *sou_type = make_sou_type(sou);
                if (sou->name) sem_define_tag(sou->name, sou_type);
                return sou_type;
            }

            // No definition (whether before or now)
            // Will get a definition later when type is forced to be completed
            if (!sym) {
                sym = sem_declare_tag(sou->name, (sou->kind == SOU_STRUCT) ? ST_STRUCT : ST_UNION);
            }
            sem_type_t *new_type = alloc_sem_type();
            new_type->kind = sym->type->kind;
            new_type->quals = quals;
            return new_type;
        } else if (ts->kind == TS_TYPEDEF) {
            sem_symbol_t *typedef_sym = sem_lookup_typedef(ts->type_name);
            if (!typedef_sym) {
                push_error("*** typedef does not exist");
                return NULL;
            }
            return typedef_sym->type;
        }
    }

    // Check for numeric types
    bool is_signed = true;
    int long_count = 0;
    bool saw_short = false;

    sem_type_kind primary = ST_INT;

    // *** NOTE: SHOULD CHANGE TO THROW ERROR FOR INCOMPATIBLE TYPE SPECIFIERS ***
    for (; tsl; tsl = tsl->next) {
        type_spec_kind kind = tsl->type->kind;
        switch (kind) {
            case TS_VOID:       primary = ST_VOID; break;
            case TS_CHAR:       primary = ST_CHAR; break;
            case TS_INT:        primary = ST_INT; break;
            case TS_FLOAT:      primary = ST_FLOAT; break;
            case TS_DOUBLE:     primary = ST_DOUBLE; break;
            case TS_BOOL:       primary = ST_BOOL; break;
            case TS_LONG:       long_count++; break;
            case TS_SHORT:      saw_short = true; break;
            case TS_UNSIGNED:   is_signed = false; break;
            default:;
        }
    }

    if (long_count == 1) {
        if (primary == ST_DOUBLE) {
            primary = ST_LDOUBLE;
        }
        primary = ST_LONG;
    } else if (long_count == 2) {
        primary = ST_LL;
    }
    return make_primitive_type(primary, is_signed, quals);
}

static sem_type_t *construct_pointer_chain(pointer *ptr) {
    sem_type_t *prev = NULL;
    sem_type_t *head = NULL;

    while (ptr) {
        sem_type_t *curr = make_pointer_type(make_qual_mask(ptr->type_quals));

        if (!head) {
            head = curr;
        }
        if (prev) {
            prev->ptr_target = curr;
        }

        prev = curr;
        ptr = ptr->next;
    }

    return head;
}

static sem_type_t *process_array_declarator(decltr *d, bool is_param) {
    if (d->kind != DCTR_ARRAY) return NULL;

    if (is_param) {
        // Array parameters are automatically converted into regular pointers
        return make_pointer_type(d->array.quals);
    }

    // Non-parameter array declarations are actual arrays

    if (!d->array.size) {
        // No size implies incomplete type
        return make_array_type(NULL, 0, true);
    }

    struct fold_result *const_fold = fold_constants(d->array.size);
    if (!const_fold->success) {
        push_error("*** non-constant array size not allowed");
        return NULL;
    }

    constant *const_val = const_fold->res->extra.const_val;
    if (const_val->kind != CONSTANT_INT) {
        push_error("*** non-integer constant array size not allowed");
        return NULL;
    }

    // This condition may have to change when struct constant is changed
    if (const_val->int_val <= 0) {
        push_error("*** array size must be a positive integer");
        return NULL;
    }

    return make_array_type(NULL, const_val->int_val, false);
}

static sem_type_list_t *make_parameter_type_list(param_list *params) {
    sem_type_list_t *prev = NULL;
    sem_type_list_t *head = NULL;

    while (params) {
        sem_type_t *param_type = decl_type(
            params->param_decl->specs,
            params->param_decl->param_decltr,
            true
        );

        sem_type_list_t *curr = alloc_sem_type_list(param_type);

        if (!head) {
            head = curr;
        }
        if (prev) {
            prev->next = curr;
        }

        prev = curr;
        params = params->next;
    }

    return head;
}

static sem_type_t *apply_decltr_chain(decltr *d, sem_type_t *base, bool is_param) {
    if (!d) return base;
    if (!base) return NULL;

    sem_type_t *prev = NULL;
    sem_type_t *head = NULL;

    while (d) {
        sem_type_t *curr = NULL;

        switch (d->kind) {
            case DCTR_ARRAY:
                curr = process_array_declarator(d, is_param);
                break;
            case DCTR_FUNC:
                sem_type_list_t *params = make_parameter_type_list(d->func.params);
                curr = make_func_type(NULL, params);
                break;
            default:;
        }

        sem_type_t *ptr_chain = construct_pointer_chain(d->ptr);
        if (!curr && !ptr_chain) {
            d = d->next;
            continue;
        }

        if (!curr) {
            curr = ptr_chain;
        }

        if (!head) {
            head = curr;
        }
        if (prev) {
            switch (prev->kind) {
                case ST_POINTER:    prev->ptr_target = curr; break;
                case ST_ARRAY:      prev->arr_info.element_type = curr; break;
                case ST_FUNC:       prev->func_info.return_type = curr; break;
                default:;
            }
        }

        // If curr is a pointer chain, advance along the chain until the end
        while (curr->kind == ST_POINTER && curr->ptr_target) {
            curr = curr->ptr_target;
        }
        prev = curr;
        d = d->next;

        // Last declarator component converted
        if (!d) {
            switch (prev->kind) {
                case ST_POINTER:    prev->ptr_target = base; break;
                case ST_ARRAY:      prev->arr_info.element_type = base; break;
                case ST_FUNC:       prev->func_info.return_type = base; break;
                default:;
            }
        }
    }

    return head;
}

static bool validate_type(sem_type_t *type, bool is_param) {
    if (!type) return false;

    while (type) {
        switch (type->kind) {
            case ST_ARRAY:
                sem_type_t *element = type->arr_info.element_type;
                if (!element || element->kind == ST_VOID) {
                    push_error("*** array void is not allowed");
                    return false;
                }
                if (element->kind == ST_FUNC) {
                    push_error("*** array of functions is not allowed");
                    return false;
                }
                type = element;
                break;
            case ST_FUNC:
                sem_type_t *ret = type->func_info.return_type;
                if (!ret) {
                    push_error("*** function must have return type");
                    return false;
                }
                if (ret->kind == ST_FUNC) {
                    push_error("*** functions may not return functions");
                    return false;
                }
                if (ret->kind == ST_ARRAY) {
                    push_error("*** functions may not return arrays");
                    return false;
                }
                type = ret;
                break;
            case ST_POINTER:
                type = type->ptr_target;
                break;
            default:
                return true;
        }
    }
    return true;
}

/*
    Exported function: decl_type
*/
sem_type_t *decl_type(decl_specs *specs, decltr *d, bool is_param) {
    if (!specs) return NULL;

    sem_type_t *base = type_from_decl_specs(specs);
    sem_type_t *final = apply_decltr_chain(d, base, is_param);

    if (!validate_type(final, is_param)) {
        free_sem_type(final);
        free_sem_type(base);
        return NULL;
    }
    return final;
}