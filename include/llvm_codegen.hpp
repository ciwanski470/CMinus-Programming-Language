/*
    File for generating LLVM IR from the AST
*/

#pragma once

#include "ast.h"

void emit_llvm(translation_unit *ast);