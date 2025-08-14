/*
    Implementation of "semantic_symtab.h"
*/

#include "semantic_symtab.h"
#include "string_helpers.h"
#include "error_handling.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 127

extern void yyerror(const char *s);

typedef struct sym_entry {
    bool defined;
    sem_symbol_t *sym;
    struct sym_entry *next;
} sym_entry_t;

typedef struct scope {
    struct sym_entry *buckets[HASH_SIZE];
    struct scope *prev;
} scope_t;

static scope_t *curr_scope = 0;

void sem_push_scope(void) {
    scope_t *new_scope = malloc(sizeof(scope_t));
    check_malloc_error(new_scope, "Malloc error when creating new scope in symbol table");
    memset(new_scope->buckets, 0, sizeof(new_scope->buckets));
    new_scope->prev = curr_scope;
    curr_scope = new_scope;
}

static void free_symbol(sem_symbol_t *sym) {
    // Unfilled
}

void sem_pop_scope(void) {
    if (!curr_scope) return;

    for (int i=0; i<HASH_SIZE; i++) {
        sym_entry_t *entry = curr_scope->buckets[i];
        while (entry) {
            sym_entry_t *next = entry->next;
            free_symbol(entry->sym);
            free(entry);
            entry = next;
        }
    }
    scope_t *old = curr_scope;
    curr_scope = curr_scope->prev;
    free(old);
}

static sem_symbol_t *make_sem_symbol(
    const char *name,
    int enum_val,
    sem_namespace ns,
    storage_class sc,
    sem_linkage linkage,
    sem_type_t *type,
    bool is_definition,
    bool is_tentative
) {
    sem_symbol_t *new_sym = malloc(sizeof(sem_symbol_t));
    check_malloc_error(new_sym, "Malloc error creating new symbol in symbol table");

    new_sym->name = name;
    new_sym->enum_val = enum_val;
    new_sym->ns = ns;
    new_sym->sc = sc;
    new_sym->linkage = linkage;
    new_sym->type = type;
    new_sym->is_definition = is_definition;
    new_sym->is_tentative = is_tentative;

    return new_sym;
}

static bool symbols_compatible(sem_symbol_t *a, sem_symbol_t *b) {
    if (a->ns != b->ns) return true;

    switch (a->ns) {
        case SEM_NS_LABEL:
        case SEM_NS_ENUM:
            return strcmp(a->name, b->name) != 0;
        case SEM_NS_ID:
        case SEM_NS_TAG:
        case SEM_NS_TYPEDEF:
            return strcmp(a->name, b->name) != 0 || types_equal(a->type, b->type);
    }
    return true;
}

/*
    Attempts to insert the given symbol into the symbol table
    Returns true if successful and false otherwise
    Insertion fails when a symbol with the same name and namespace as an existing one tries to be added
*/
static bool sem_insert_symbol(sem_symbol_t *sym) {
    if (!sym) return false;

    size_t hash = str_hash(sym->name, HASH_SIZE);

    for (sym_entry_t *entry = curr_scope->buckets[hash]; entry; entry = entry->next) {
        if (!symbols_compatible(sym, entry->sym)) {
            yyerror("*** illegal redefinition of a symbol within the same scope");
            return false;
        }
    }

    sym_entry_t *new_entry = malloc(sizeof(sym_entry_t));
    check_malloc_error(new_entry, "Malloc error when adding new entry to symbol table");

    new_entry->sym = sym;
    new_entry->next = curr_scope->buckets[hash];
    curr_scope->buckets[hash] = new_entry;

    return true;
}

sem_symbol_t *sem_declare_id(const char *name, sem_type_t *type, storage_class sc, bool is_tentative, scope_kind scope) {
    if (!curr_scope) return 0;

    sem_linkage linkage = SEM_LINK_NONE;
    switch (scope) {
        case SEM_SCOPE_FILE:
            linkage = (sc == SC_STATIC) ? SEM_LINK_INTERNAL : SEM_LINK_EXTERNAL;
            break;
        case SEM_SCOPE_BLOCK:
            linkage = (sc == SC_EXTERN) ? SEM_LINK_EXTERNAL : SEM_LINK_INTERNAL;
            break;
        default:;
    }

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SEM_NS_ID, sc, linkage, type, false, is_tentative);
    if (!sem_insert_symbol(new_sym)) return 0; // Return NULL if insertion fails
    return new_sym;
}

sem_symbol_t *sem_define_id(const char *name, sem_type_t *type, storage_class sc, bool is_tentative) {
    // Unfilled
}

sem_symbol_t *sem_define_enum(const char *name, int val) {
    if (!curr_scope) return 0;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, val, SEM_NS_ENUM, SC_NONE, SEM_LINK_NONE, 0, true, false);
    if (!sem_insert_symbol(new_sym)) return 0;
    return new_sym;
}

sem_symbol_t *sem_define_tag(const char *name, sem_type_t *type) {
    if (!curr_scope) return 0;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SEM_NS_TAG, SC_NONE, SEM_LINK_NONE, type, false, false);
    if (!sem_insert_symbol(new_sym)) return 0;
    return new_sym;
}

sem_symbol_t *sem_define_typedef(const char *name, sem_type_t *type) {
    if (!curr_scope) return 0;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SEM_NS_TYPEDEF, SC_TYPEDEF, SEM_LINK_NONE, type, false, false);
    if (!sem_insert_symbol(new_sym)) return 0;
    return new_sym;
}

sem_symbol_t *sem_define_label(const char *name) {
    if (!curr_scope) return 0;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SEM_NS_LABEL, SC_NONE, SEM_LINK_NONE, 0, false, false);
    if (!sem_insert_symbol(new_sym)) return 0;
    return new_sym;
}

/*
    Finds and returns the symbol with the given name and namespace
    Searches innermost scope first
    Returns NULL if symbol is not found
*/
static sem_symbol_t *lookup_symbol(const char *name, sem_namespace ns) {
    if (!curr_scope) return 0;

    size_t hash = str_hash(name, HASH_SIZE);

    for (scope_t *scope = curr_scope; scope; scope = scope->prev) {
        for (sym_entry_t *entry = scope->buckets[hash]; entry; entry = entry->next) {
            if (ns == entry->sym->ns && strcmp(name, entry->sym->name) == 0) {
                return entry->sym;
            }
        }
    }

    return 0;
}

sem_symbol_t *sem_lookup_id(const char *name) {
    return lookup_symbol(name, SEM_NS_ID);
}

sem_symbol_t *sem_lookup_tag(const char *name) {
    return lookup_symbol(name, SEM_NS_TAG);
}

sem_symbol_t *sem_lookup_typedef(const char *name) {
    return lookup_symbol(name, SEM_NS_TYPEDEF);
}

sem_symbol_t *sem_lookup_label(const char *name) {
    return lookup_symbol(name, SEM_NS_LABEL);
}

bool types_equal(sem_type_t *a, sem_type_t *b) {
    // Unfilled
}

parse_req types_parsable(sem_type_t *a, sem_type_t *b) {
    // Unfilled
}