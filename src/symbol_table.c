/*
    Implementation of "symbol_table.h"
*/

#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 127
#define P 67 // For hash function

extern void yyerror(const char *s);

// Entry in the hash table
typedef struct sym_entry_t {
    char *name;
    sym_kind kind;
    struct sym_entry_t *next;
} sym_entry_t;

// Stack of scopes
typedef struct scope_t {
    struct sym_entry_t *buckets[HASH_SIZE];
    struct scope_t *prev;
} scope_t;

// Uses rolling polynomial hash
size_t str_hash(const char *str) {
    unsigned int hash = 0;
    unsigned int curr_p = 1;
    for (int i=0; str[i]; i++) {
        hash += str[i] * curr_p % HASH_SIZE;
        curr_p = curr_p * P % HASH_SIZE;
    }
    return hash;
}

scope_t *curr_scope = 0;

// Enter new scope (public)
void sym_push_scope(void) {
    scope_t *new_scope = malloc(sizeof(scope_t));
    if (!new_scope) {
        perror("Malloc error when initializing new scope in symbol table");
        exit(1);
    }
    memset(new_scope->buckets, 0, sizeof(new_scope->buckets));
    new_scope->prev = curr_scope;
    curr_scope = new_scope;
}

// Exit current scope (public)
void sym_pop_scope(void) {
    if (!curr_scope) return;

    for (int i=0; i<HASH_SIZE; i++) {
        sym_entry_t *entry = curr_scope->buckets[i];
        while (entry) {
            sym_entry_t *next = entry->next;
            free(entry->name);
            free(entry);
            entry = next;
        }
    }
    scope_t *old = curr_scope;
    curr_scope = curr_scope->prev;
    free(old);
}

void sym_insert(const char *name, sym_kind kind) {
    // Typically if sym_push_scope() is not called before yyparse()
    if (!curr_scope) sym_push_scope();
    
    char *name_dup = strdup(name);
    size_t hash = str_hash(name_dup);

    // Check if it already exists in this scope
    for (sym_entry_t *entry = curr_scope->buckets[hash]; entry; entry = entry->next) {
        if (strcmp(name_dup, entry->name) == 0) {
            yyerror("illegal redefinition of a symbol within the same scope");
            return;
        }
    }

    // This identifier does not exist in this scope
    sym_entry_t *new_entry = malloc(sizeof(sym_entry_t));
    if (!new_entry) {
        perror("Malloc error when adding new entry to symbol table");
        exit(1);
    }
    new_entry->name = name_dup;
    new_entry->kind = kind;
    new_entry->next = curr_scope->buckets[hash];
    curr_scope->buckets[hash] = new_entry;
}

void sym_define_typedef(const char *name) {
    sym_insert(name, SYM_TYPEDEF);
}

void sym_define_enum(const char *name) {
    sym_insert(name, SYM_ENUM_CONST);
}

int sym_type(const char *token) {
    size_t hash = str_hash(token);
    
    for (scope_t *scope = curr_scope; scope; scope = scope->prev) {
        for (sym_entry_t *entry = scope->buckets[hash]; entry; entry = entry->next) {
            if (strcmp(entry->name, token) == 0) {
                return entry->kind;
            }
        }
    }
    return SYM_IDENTIFIER;
}