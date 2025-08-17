/*
    Contains functionality relating to semantic types
    Used during semantic analysis
    All contents were originally from "semantic_symtab.h" but were moved here to prevent
        potential circular dependencies with "ast.h"
*/

#pragma once

#include "helper_enums.h"
#include <stdbool.h>

typedef enum {
    SEM_NS_ID,
    SEM_NS_ENUM,
    SEM_NS_TAG,
    SEM_NS_TYPEDEF,
    SEM_NS_LABEL
} sem_namespace;

typedef enum {
    SEM_LINK_NONE,
    SEM_LINK_INTERNAL,
    SEM_LINK_EXTERNAL
} sem_linkage;

typedef enum {
    SEM_SCOPE_FILE,
    SEM_SCOPE_BLOCK,
    SEM_SCOPE_PARAM
} scope_kind;

/*
    NOTE: Types are arranged by how you compare them
    ST_INT to ST_CHAR are compared by signedness
    ST_VOID to ST_IMAGINARY are compared only by the type enum
    ST_FUNC is compared by return type and parameter type
    ST_STRUCT and ST_UNION are compared the same way
*/
typedef enum {
    ST_INT,
    ST_SHORT,
    ST_LONG,
    ST_LL,
    ST_CHAR,
    ST_VOID,
    ST_FLOAT,
    ST_DOUBLE,
    ST_LDOUBLE,
    ST_BOOL,
    ST_FCOMPLEX, // Complex/Imaginary can be float, double, or long double
    ST_FIMAGINARY,
    ST_DCOMPLEX,
    ST_DIMAGINARY,
    ST_LDCOMPLEX,
    ST_LDIMAGINARY,
    ST_FUNC,
    ST_STRUCT,
    ST_UNION
} sem_type_kind;

typedef enum {
    PARSE_IMPLICIT,
    PARSE_EXPLICIT,
    PARSE_ILLEGAL
} parse_req;

struct sem_symbol;
struct sem_type;
struct sem_type_list;
struct sem_struct_decls;

extern struct expr;

typedef struct sem_symbol {
    char *name;
    int enum_val; // For enums

    sem_namespace ns;
    storage_class sc;
    sem_linkage linkage;
    struct sem_type *type;

    bool is_definition;
    bool is_tentative;
} sem_symbol_t;

// ts is not complete
typedef struct sem_type {
    sem_type_kind kind;
    bool is_signed;
    union {
        struct sem_struct_decls *sou_decls;

        struct {
            struct sem_type *ret_type; // Obtained from declarator or type specifier
            struct sem_type_list *list;
        } func_info;

        struct {
            struct sem_type *element_type;
            unsigned int size; // Obtained from constant folding
        } arr_info;
    };
} sem_type_t;

typedef struct sem_type_list {
    struct sem_type *type;
    struct sem_type_list *next;
} sem_type_list_t;

typedef struct sem_struct_decls {
    struct sem_symbol *sym;
    struct sem_struct_decls *next;
} sem_struct_decls_t;

// Type comparison

bool types_equal(sem_type_t *a, sem_type_t *b);
parse_req types_parsable(sem_type_t *from, sem_type_t *to);