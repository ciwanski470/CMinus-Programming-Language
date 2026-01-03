/*
    Implementation of "semantic_symtab.h"
*/

#include "semantic_symtab.h"
#include "string_helpers.h"
#include "error_handling.h"
#include "ast.h"
#include "optimization.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define HASH_SIZE 127

typedef struct sym_entry {
    sem_symbol_t *sym;
    struct sym_entry *next;
} sym_entry_t;

typedef struct scope {
    struct sym_entry *buckets[HASH_SIZE];
    struct scope *prev;
} scope_t;

static scope_t *curr_scope = 0;

void sem_push_scope(void) {
    scope_t *new_scope = calloc(1, sizeof(scope_t));
    check_alloc_error(new_scope, "Alloc error when creating new scope in symbol table");
    memset(new_scope->buckets, 0, sizeof(new_scope->buckets));
    new_scope->prev = curr_scope;
    curr_scope = new_scope;
}

void free_symbol(sem_symbol_t *sym) {
    if (!sym) return;

    free(sym->name);
    free(sym);
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
    storage_class sc,
    sem_namespace ns,
    sem_type_t *type,
    bool is_definition
) {
    sem_symbol_t *new_sym = calloc(1, sizeof(sem_symbol_t));
    check_alloc_error(new_sym, "Alloc error creating new symbol in symbol table");

    new_sym->name = name;
    new_sym->enum_val = enum_val;
    new_sym->sc = sc;
    new_sym->ns = ns;
    new_sym->type = type;
    new_sym->is_definition = is_definition;

    return new_sym;
}

/*
    Attempts to insert the given symbol into the symbol table
    Returns true if successful and false otherwise
    Successful if there are no duplicate names 
*/
static bool sem_insert_symbol(sem_symbol_t *sym) {
    if (!sym) return false;

    size_t hash = str_hash(sym->name, HASH_SIZE);
    sym_entry_t *decl_location = NULL;

    for (sym_entry_t *entry = curr_scope->buckets[hash]; entry; entry = entry->next) {
        if (strcmp(sym->name, entry->sym->name) != 0) continue;
        if (sym->ns != entry->sym->ns) continue;

        if (sym->is_definition && entry->sym->is_definition) {
            push_error("*** illegal redefinition of a symbol within the same scope");
            return false;
        } else if (entry->sym->is_definition) {
            return false;
        } else if (sym->is_definition) {
            decl_location = entry;
            break;
        } else {
            return false; // Redeclaration is pointless to add to the symbol table
        }
    }

    if (!decl_location) {
        sym_entry_t *new_entry = calloc(1, sizeof(sym_entry_t));
        check_alloc_error(new_entry, "Alloc error when adding new entry to symbol table");

        new_entry->sym = sym;
        new_entry->next = curr_scope->buckets[hash];
        curr_scope->buckets[hash] = new_entry;
    } else {
        free_symbol(decl_location->sym);
        decl_location->sym = sym;
    }

    return true;
}

sem_symbol_t *sem_declare_id(const char *name, sem_type_t *type, storage_class sc, bool is_definition) {
    if (!curr_scope) return NULL;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, sc, SEM_NS_ID, type, is_definition);
    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    }
    return new_sym;
}

sem_symbol_t *sem_define_enum(const char *name, int val) {
    if (!curr_scope) return NULL;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, val, SC_NONE, SEM_NS_ENUM, NULL, true);
    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    } 
    return new_sym;
}

sem_symbol_t *sem_declare_tag(const char *name, sem_type_kind kind) {
    if (!curr_scope) return NULL;

    const char *name_dup = strdup(name);

    sem_type_t *new_type = alloc_sem_type();
    new_type->kind = kind;

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SC_NONE, SEM_NS_TAG, new_type, false);
    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    } 
    return new_sym;
}

sem_symbol_t *sem_define_tag(const char *name, sem_type_t *type) {
    if (!curr_scope) return NULL;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SC_NONE, SEM_NS_TAG, type, true);
    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    }
    return new_sym;
}

sem_symbol_t *sem_define_sou(const char *name, sou_spec *sou) {
    if (!curr_scope) return NULL;
    printf("Defining SoU in symbol table\n");

    const char *name_dup = strdup(name);
    sem_type_t *placeholder_type = alloc_sem_type();
    placeholder_type->kind = (sou->kind == SOU_STRUCT) ? ST_STRUCT : ST_UNION;
    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SC_NONE, SEM_NS_TAG, placeholder_type, true);

    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    }

    sem_type_t *sou_type = make_sou_type(sou);
    new_sym->type->sou_info = sou_type->sou_info;

    return new_sym;
}

sem_symbol_t *sem_define_typedef(const char *name, sem_type_t *type) {
    if (!curr_scope) return NULL;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SC_NONE, SEM_NS_TYPEDEF, type, false);
    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    }
    return new_sym;
}

sem_symbol_t *sem_define_label(const char *name) {
    if (!curr_scope) return NULL;

    const char *name_dup = strdup(name);

    sem_symbol_t *new_sym = make_sem_symbol(name_dup, 0, SC_NONE, SEM_NS_LABEL, NULL, false);
    if (!sem_insert_symbol(new_sym)) {
        free_symbol(new_sym);
        return NULL;
    } 
    return new_sym;
}

/*
    Finds and returns the symbol with the given name and namespace
    Searches innermost scope first
    Returns NULL if symbol is not found
*/
static sem_symbol_t *lookup_symbol(const char *name, sem_namespace ns) {
    if (!curr_scope) return NULL;

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

void dump_table() {
    printf("--- Dumping symbol table ---\n");
    for (scope_t *scope = curr_scope; scope; scope = scope->prev) {
        printf("Printing scope...\n");
        for (int i=0; i<HASH_SIZE; i++) {
            for (sym_entry_t *entry = scope->buckets[i]; entry; entry = entry->next) {
                sem_symbol_t *sym = entry->sym;
                const char *ns_str;
                switch (sym->ns) {
                    case SEM_NS_ENUM: ns_str = "Enum"; break;
                    case SEM_NS_ID: ns_str = "ID"; break;
                    case SEM_NS_LABEL: ns_str = "Label"; break;
                    case SEM_NS_TAG: ns_str = "Tag"; break;
                    case SEM_NS_TYPEDEF: ns_str = "Typedef"; break;
                }
                printf("Namespace: %s\n", ns_str);

                if (sym->name) {
                    printf("Name: %s\n", sym->name);
                } else {
                    printf("Name: None\n");
                }

                if (sym->type) {
                    printf("Type: %s\n", type_to_s(sym->type));
                } else {
                    printf("Type: None\n");
                }
            }
        }
    }
    printf("--- Dump over ---\n");
}