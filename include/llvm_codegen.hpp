/*
    File for generating LLVM IR from the AST
*/

#pragma once

extern "C" {
    #include "ast.h"
}

#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Passes/OptimizationLevel.h"
#include "llvm/TargetParser/Host.h"

#include <string>
#include <memory>
#include <optional>

// optional pair of llvm::Module and llvm::LLVMContext
std::optional<std::pair<std::unique_ptr<llvm::Module>, std::unique_ptr<llvm::LLVMContext>>>
generate_llvm(translation_unit *ast);

bool write_module_to_file(const llvm::Module &m, const std::string &filename);

void module_to_obj(
    llvm::Module &m,
    const std::string &filename,
    const llvm::OptimizationLevel &optimization = llvm::OptimizationLevel::O2,
    const std::string &TargetTripleStr = llvm::sys::getDefaultTargetTriple()
);