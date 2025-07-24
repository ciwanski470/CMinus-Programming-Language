/*
    File handles context-sensitive functionality
    As of now, the only functionality handled is the "__func_name__" keyword
*/

#pragma once

#include "ast.h"
#include <stdbool.h>

// For keeping track of function name
static inline void set_func_name(char *name);
static inline void func_ended();
static inline char *func_name();

// For determining whether or not a function is declared with ellipsis in it params
// Uses a stack because parameter lists can be nested
// This is the alternative to simply making a "param_type_list" struct, but this gives a cleaner AST
static inline void set_param_ellipsis(bool val);
static inline bool check_param_ellipsis();

// Takes a declarator and traverses the tree until an id is found, and returns that id
// Returns NULL if there is none (meaning the declarator is abstract)
static inline char *get_decltr_id(decltr *decltr);

/*
    When parsing, many list structs end up in reverse order
    Recursively reverses all lists in all subtrees in the AST
    Use directly after parsing
    Always set "is_first" to true when passing the head of a list
*/
static translation_unit *reverse_lists(translation_unit *tree, bool is_head);