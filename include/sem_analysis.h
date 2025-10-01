/*
    File contains functions that are the main driver of the semantic analysis phase of the compiler
*/

#pragma once

#include "ast.h"
#include <stdbool.h>

/*
    Traverses the AST, reporting errors, folding constants, and filling in type data
    Returns true if successful and false if there are errors
*/
bool traverse_ast(translation_unit *ast);