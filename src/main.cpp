extern "C" {
    #include "ast.h"
    #include "ast_printer.h"
    #include "parser_symbols.h"
    #include "parser_helpers.h"
    #include "parser.h"
    #include "sem_analysis.h"
    #include "semantic_symtab.h"
    #include "error_handling.h"
}

#include "llvm_codegen.hpp"

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <string>
#include <map>
#include <memory>

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

std::string get_base_name(const std::string &filename) {
    uint16_t last_dot = -1;
    for (uint16_t i=0; i<filename.size(); i++) {
        if (filename[i] == '.') last_dot = i;
    }

    return filename.substr(0, last_dot);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "No program specified\n";
        return 1;
    }

    if (argc > 2) {
        std::cerr << "Too many arguments\n";
        return 1;
    }

    const char *filename_cstr = argv[1];

    yyin = fopen(filename_cstr, "r");
    yydebug = 0;

    if (!yyin) {
        std::cerr << "Cannot find file '" << filename_cstr << "'\n";
        return 1;
    }
    
    sym_push_scope();
    int parse_success = yyparse();
    sym_pop_scope();

    if (parse_success == 1) {
        std::cerr << "Syntax error; could not successfully parse program\n";
        return 0;
    } else if (parse_success == 2) {
        std::cerr << "Error: ran out of memory while parsing\n";
        return 1;
    }

    ast_root = reverse_lists(ast_root, true);

    sem_push_scope();
    bool sem_success = traverse_ast(ast_root);
    sem_pop_scope();

    std::cout << error_count << " errors generated\n";
    if (error_count > 0 || !sem_success) return 0;

    print_ast(ast_root, "output.ast");

    /*
        Generate LLVM
    */

    std::string basename = get_base_name(std::string(filename_cstr));

    std::unique_ptr<llvm::Module> llvm_module;
    std::unique_ptr<llvm::LLVMContext> context;

    if (auto opt = generate_llvm(ast_root)) {
        llvm_module = std::move(opt->first);
        context = std::move(opt->second);
    } else {
        llvm_module.release();
        context.release();
        return 1;
    }

    std::string llvm_output_name(basename);
    llvm_output_name.append(".ll");
    write_module_to_file(*llvm_module, llvm_output_name);

    /*
        Emit object file
    */

    std::string obj_output_name(basename);
    obj_output_name.append(".o");
    module_to_obj(*llvm_module, obj_output_name, llvm::OptimizationLevel::O0);

    llvm_module.release();
    context.release();

    return 0;
}