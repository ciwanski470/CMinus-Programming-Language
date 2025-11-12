/*
    File handles context-sensitive functionality
    As of now, the only functionality handled is the "__func_name__" keyword
*/

#pragma once

#include "ast.h"
#include <stdbool.h>

// For keeping track of function name
void set_func_name(char *name);
void func_ended();
char *func_name();

/*
    Takes a declarator and traverses the tree until an id is found, and returns that id
    Returns NULL if there is none (meaning the declarator is abstract)
*/
char *get_decltr_id(decltr *decltr);

/*
    If the given declaration is a typedef declaration, add the identifier to the symbol table
*/
void add_typedef_type(decl *decl);

/*
    When parsing, many list structs end up in reverse order
    Recursively reverses all lists in all subtrees in the AST
    Use directly after parsing
    Always set "is_first" to true when passing the head of a list
*/
translation_unit *reverse_lists(translation_unit *tree, bool is_head);