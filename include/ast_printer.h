/*
    File contains functionality for converting an AST into an output file
    Not used in the main compiler, but rather for debugging and visualization purposes
*/

#pragma once

#include "ast.h"

/*
    Prints the given AST in an Indented Tree Format
*/
void print_ast(translation_unit *tree, char *output_name);