/*
    Contains functionality relating to semantic types
    Used during semantic analysis
    All contents were originally from "semantic_symtab.h" but were moved here to prevent
        potential circular dependencies with "ast.h"
*/

#pragma once

#include "helper_enums.h"
#include "ast.h"
#include <stdbool.h>
#include <stdlib.h>

// Bitmasks for encoding what qualifiers a type has
#define TQ_CONST_MASK 1
#define TQ_RESTRICT_MASK 2
#define TQ_VOLATILE_MASK 4

typedef enum {
    SEM_NS_ID,
    SEM_NS_ENUM,
    SEM_NS_TAG,
    SEM_NS_TYPEDEF,
    SEM_NS_LABEL
} sem_namespace;

typedef enum {
    SEM_SCOPE_FILE,
    SEM_SCOPE_BLOCK,
    SEM_SCOPE_PARAM
} scope_kind;

/*
    NOTE: Types are arranged by how you compare them (REORDERING MAY BE RISKY)
    ST_INT to ST_CHAR are compared by signedness
    ST_VOID to ST_BOOL are compared only by the sem_type_kind
    ST_FUNC is compared by return type and parameter type
    ST_ARRAY is compared by element type, size, and qualifiers
    ST_STRUCT and ST_UNION are compared the same way

    Order and grouping is strict and is taken advantage of in some functions

    Enums are handled as being equivalent to "unsigned short"
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
    ST_BOOL,
    ST_FUNC,
    ST_ARRAY,
    ST_STRUCT,
    ST_UNION,
    ST_POINTER
} sem_type_kind;

typedef enum {
    PARSE_IMPLICIT,
    PARSE_EXPLICIT,
    PARSE_ILLEGAL
} parse_req;

struct sem_symbol;
struct sem_type;
struct sem_type_list;
struct sem_sou_info;
struct sem_member;

typedef struct sem_symbol {
    const char *name;
    int enum_val; // For enum constants

    storage_class sc; // To be honest, I don't think this is necessary but it could help
    sem_namespace ns;
    struct sem_type *type;

    bool is_definition;
} sem_symbol_t;

typedef struct sem_type {
    sem_type_kind kind;
    unsigned short quals;
    bool is_signed;

    union {
        struct sem_sou_info *sou_info;

        struct sem_type *ptr_target;

        struct {
            struct sem_type *return_type;
            struct sem_type_list *params;
            bool variadic;
        } func_info;

        struct {
            struct sem_type *element_type;
            size_t size; // Obtained from constant folding
            bool incomplete;
        } arr_info;
    };
} sem_type_t;

typedef struct sem_type_list {
    struct sem_type *type;
    struct sem_type_list *next;
} sem_type_list_t;

typedef struct sem_sou_info {
    char *name;
    struct sem_member *members;
    bool complete;
} sem_sou_info_t;

typedef struct sem_member {
    char *name;
    struct sem_type *type;

    struct sem_member *next;
} sem_member_t;

// Type creation and deallocation

sem_type_t *alloc_sem_type(void);
sem_type_list_t *alloc_sem_type_list(sem_type_t *t);
sem_sou_info_t *alloc_sou_info(void);

sem_type_t *make_primitive_type(sem_type_kind kind, bool is_signed, unsigned short quals);
sem_type_t *make_pointer_type(sem_type_t *target, unsigned short quals);
sem_type_t *make_array_type(sem_type_t *element_type, size_t size, bool incomplete);
sem_type_t *make_func_type(sem_type_t *return_type, sem_type_list_t *params, bool variadic);
sem_type_t *make_enum_type(enum_spec *enums);
sem_type_t *make_sou_type(sou_spec *sou);

unsigned short make_qual_mask(type_qual_list *quals);

void free_all_sem_types(void);
void free_sem_type(sem_type_t *type);

// Type comparison

bool types_equal(sem_type_t *a, sem_type_t *b); // NOT FINISHED
bool type_is_scalar(sem_type_t *type);
bool type_is_integral(sem_type_t *type);
bool type_is_float(sem_type_t *type);

/*
    Validates the expression and returns the type of it
    Returns NULL if the expression is invalid
*/
sem_type_t *type_of_expr(expr *e);

/*
    Validates the constant and returns the type of it
    Returns NULL if the constant is invalid
*/
sem_type_t *type_of_const(constant *c);

/*
    Fills in the value of the constant given the type
    Returns true if the constant is valid and false otherwise
*/
bool fill_const_val(constant *c, sem_type_t *type);

parse_req expr_compatible(expr *e, sem_type_t *type);
parse_req types_parsable(sem_type_t *from, sem_type_t *to);

size_t size_of_type(sem_type_t *type);
sem_type_t *larger_type(sem_type_t *a, sem_type_t *b);
sem_type_t *arithmetic_promotion(sem_type_t *a, sem_type_t *b);

size_t size_of_string_lit(const char *s);

int get_char_val(const char *s);

bool resolve_sou(sem_type_t *sou_type);
sem_member_t *get_sou_member(sem_sou_info_t *sou, const char *name);