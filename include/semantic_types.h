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
    NOTE: Types are arranged by how you compare them (REORDERING MAY BE RISKY)
    ST_INT to ST_CHAR are compared by signedness
    ST_VOID to ST_IMAGINARY are compared only by the type enum
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
    ST_LDOUBLE,
    ST_BOOL,
    ST_FCOMPLEX, // Complex/Imaginary can be float, double, or long double
    ST_FIMAGINARY,
    ST_DCOMPLEX,
    ST_DIMAGINARY,
    ST_LDCOMPLEX,
    ST_LDIMAGINARY,
    ST_FUNC,
    ST_ARRAY,
    ST_STRUCT,
    ST_UNION,
    ST_TYPEDEF,
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
    char *name;
    int enum_val; // For enum constants

    sem_namespace ns;
    storage_class sc;
    func_spec fs;
    sem_linkage linkage;
    struct sem_type *type;

    bool is_definition;
    bool is_tentative;
} sem_symbol_t;

typedef struct sem_type {
    sem_type_kind kind;
    unsigned short quals;
    bool is_signed;

    union {
        struct sem_sou_info *sou_info;

        struct sem_type *ptr_target;

        struct sem_type *typedef_type;

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
    struct sem_member *members;
    size_t size; // in bytes
    size_t alignment; // in bytes
    bool complete;
} sem_sou_info_t;

typedef struct sem_member {
    char *name;
    struct sem_type *type;
    bool has_bitfield;
    int bit_width;
    size_t offset_bytes; // byte offset from start of struct
    int bit_offset_in_unit; // bit offset within current storage unit

    struct sem_member *next;
} sem_member_t;

// Type creation

sem_type_t *alloc_sem_type(void);
sem_type_list_t *alloc_sem_type_list(sem_type_t *t);

sem_type_t *make_primitive_type(sem_type_kind kind, bool is_signed, unsigned short quals);
sem_type_t *make_pointer_type(unsigned short quals);
sem_type_t *make_array_type(sem_type_t *element_type, size_t size, bool incomplete);
sem_type_t *make_func_type(sem_type_t *return_type, sem_type_list_t *params, bool variadic);
sem_type_t *make_enum_type(enum_spec *enums);
sem_type_t *make_sou_type(sou_spec *sou);

unsigned short make_qual_mask(type_qual_list *quals);

// Type comparison

bool types_equal(sem_type_t *a, sem_type_t *b);
parse_req types_parsable(sem_type_t *from, sem_type_t *to);