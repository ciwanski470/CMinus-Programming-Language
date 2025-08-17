/*
    Symbol table used in semantic analysis
    File also houses structs and functions involving semantic types
    All data types 
*/

#pragma once

#include "ast.h"
#include "semantic_types.h"
#include <stdbool.h>

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