/*
    Symbol table used in semantic analysis
    File also houses structs and functions involving semantic types
*/

#pragma once

#include "ast.h"
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

typedef enum {
    ST_VOID,
    ST_INT,
    ST_SHORT,
    ST_LONG,
    ST_LL,
    ST_CHAR,
    ST_BOOL,
    ST_COMPLEX,
    ST_IMAGINARY,
    ST_FUNC,
    ST_STRUCT,
    ST_UNION,
    ST_TYPEDEF
} sem_type_kind;

typedef enum {
    PARSE_IMPLICIT,
    PARSE_EXPLICIT,
    PARSE_ILLEGAL
} parse_req;

struct sem_symbol;
struct sem_type;
struct sem_struct_decls;

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
        struct sem_type *typedef_type;
    };
} sem_type_t;

typedef struct sem_struct_decls {
    struct sem_type *type;


    struct sem_struct_decls *next;
} sem_struct_decls_t;

// Handle scope

void sem_push_scope(void);
void sem_pop_scope(void);

// Declare and define variables and functions

sem_symbol_t *sem_declare_id(const char *name, sem_type_t *type, storage_class sc, bool is_tentative, scope_kind scope);
sem_symbol_t *sem_define_id(const char *name, sem_type_t *type, storage_class sc, bool is_tentative);

// Define enum constants

sem_symbol_t *sem_define_enum(const char *name, int val);

// Define typedefs and tags

sem_symbol_t *sem_define_tag(const char *name, sem_type_t *type);
sem_symbol_t *sem_define_typedef(const char *name, sem_type_t *type);

// Define labels

sem_symbol_t *sem_define_label(const char *name);

// Lookup

sem_symbol_t *sem_lookup_id(const char *name);
sem_symbol_t *sem_lookup_tag(const char *name);
sem_symbol_t *sem_lookup_typedef(const char *name);
sem_symbol_t *sem_lookup_label(const char *name);

// Type comparison

bool types_equal(sem_type_t *a, sem_type_t *b);
parse_req types_parsable(sem_type_t *from, sem_type_t *to);