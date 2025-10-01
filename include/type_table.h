/*
    Keeps track of every user-defined type in the program
    This is used explicitly for typedefs, structs, and unions

    Does not free types after exiting the scope
        Prevents decl structs from referencing null pointers
        All memory is freed from a single call of 

    Note that no function in this file will report compilation errors
*/

#pragma once

#include "ast.h"
#include "semantic_types.h"

typedef enum {
    TTABLE_STRUCT,
    TTABLE_UNION,
    TTABLE_TYPEDEF
} ttable_entry_kind;

/*
    Returns the integer id of the struct given by the tag
    The returned id is dependent on the current scope due to shadowing
    Returns SIZE_MAX if it does not exist
*/
size_t id_of_struct(const char *name);

/*
    Same thing but for unions
*/
size_t id_of_union(const char *name);

/*
    Same thing but for typedefs
*/
size_t id_of_typedef(const char *name);

/*
    Returns the type given by the integer id
    Type can either be an SoU or a typedef type
    Note that this data may be incomplete if types are not resolved at the end of the scope
    This is INDEPENDENT of scope
*/
sem_type_t *get_type_info(size_t id);

/*
    Adds an SoU into the table and returns the id associated with it
    Note that every id is unique, regardless of shadowing of the names
    If there is an undefined type with the same name in the same scope, defines it
        Undefined type created by ttable_reserve_entry
*/
size_t ttable_push_sou(sou_spec *sou);

/*
    Same as ttable_push_sou but for typedefs
*/
size_t ttable_push_typedef(sem_type_t *type, const char *name);

/*
    Creates an entry in the type table that has an undefined type which can be defined later
    If already exists in the symbol table (whether or not it is defined), returns that id
*/
size_t ttable_reserve_entry(const char *name, ttable_entry_kind kind);

/*
    For each SoU in the scope, resolves any nested SoUs to complete the type
    Returns true if successful and false if an error is generated
*/
bool resolve_sous(void);

/*
    Handles scope
*/

void ttable_push_scope(void);
void ttable_pop_scope(void);

/*
    Frees all memory associated with this symbol table
    To be called after the IR is generated, rather than semantic analysis
*/
void free_type_data(void);