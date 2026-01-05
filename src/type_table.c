/*
    Implementation of "type_table.h"

    Does nothing; this code is unused in the project
*/

#include "type_table.h"
#include "string_helpers.h"
#include "error_handling.h"
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 127

typedef struct type_entry {
    size_t id;
    char *name;
    bool defined;
    ttable_entry_kind kind;
    struct type_entry *next;
} type_entry_t;

typedef struct scope {
    struct type_entry *buckets[HASH_SIZE];
    struct scope *prev;
} scope_t;

static scope_t *curr_scope = NULL;

// Array of pointers to sem_type_t where the index is the id
static sem_type_t **types;

static size_t next_id = 0; // Doubles as the array length
static size_t curr_size = 10;

static size_t search_id(const char *name, ttable_entry_kind kind) {
    if (!curr_scope || !name) return SIZE_MAX;

    size_t hash = str_hash(name, HASH_SIZE);

    for (scope_t *scope = curr_scope; scope; scope = scope->prev) {
        for (type_entry_t *entry = scope->buckets[hash]; entry; entry = entry->next) {
            if (strcmp(name, entry->name) == 0 && entry->kind == kind) {
                return entry->id;
            }
        }
    }

    return SIZE_MAX;
}

size_t id_of_struct(const char *name) {
    return search_id(name, TTABLE_STRUCT);
}

size_t id_of_union(const char *name) {
    return search_id(name, TTABLE_UNION);
}

sem_type_t *get_type_info(size_t id) {
    return (id < next_id) ? types[id] : NULL;
}

static size_t push_type(sem_type_t *type, const char *name, ttable_entry_kind kind) {
    if (!curr_scope || !name) return SIZE_MAX;
    
    size_t hash = str_hash(name, HASH_SIZE);

    // Search the current scope for matches
    for (type_entry_t *entry = curr_scope->buckets[hash]; entry; entry = entry->next) {
        if (strcmp(name, entry->name) == 0) {
            if (entry->kind != kind) return SIZE_MAX;

            // Has a valid match
            if (entry->defined && type) {
                return SIZE_MAX;
            } else if (type) {
                // Add the sou_info to the type
                types[entry->id]->sou_info = type->sou_info;
                entry->defined = true;
            } else {
                return entry->id;
            }
        }
    }

    const char *name_dup = strdup(name);

    type_entry_t *new_entry = calloc(1, sizeof(type_entry_t));
    check_alloc_error(new_entry, "Alloc error when creating new type_entry_t");

    if (next_id >= curr_size) {
        curr_size <<= 1;
        types = realloc(types, curr_size * sizeof(sem_type_t *));
    }

    new_entry->kind = kind;
    new_entry->id = next_id;
    new_entry->name = name_dup;
    new_entry->next = curr_scope->buckets[hash];

    curr_scope->buckets[hash] = new_entry;

    types[next_id] = type;

    return next_id++;
}

size_t ttable_push_sou(sou_spec *sou) {
    if (!sou->decls) return SIZE_MAX;
    sem_type_t *sou_type = make_sou_type(sou);
    if (!sou_type) return SIZE_MAX;
    return push_type(sou_type, sou->name, (sou->kind == SOU_STRUCT) ? TTABLE_STRUCT : TTABLE_UNION);
}

size_t ttable_reserve_entry(const char *name, ttable_entry_kind kind) {
    return push_type(NULL, name, kind);
}

void ttable_push_scope(void) {
    scope_t *new_scope = calloc(1, sizeof(scope_t));
    new_scope->prev = curr_scope;
    curr_scope = new_scope;
}

void ttable_pop_scope(void) {
    for (int i=0; i<HASH_SIZE; i++) {
        for (type_entry_t *entry = curr_scope->buckets[i]; entry;) {
            type_entry_t *temp = entry;
            entry = entry->next;
            free(temp->name);
            free(temp);
        }
    }
}