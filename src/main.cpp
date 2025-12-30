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

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        perror("No program specified");
        return 1;
    }
    if (argc > 2) {
        perror("Can only compile one program");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yydebug = 0;

    std::cout << "Opened File\n";
    fflush(stdout);
    
    sym_push_scope();
    int parse_success = yyparse();
    sym_pop_scope();

    std::cout << "Finished parsing\n";
    fflush(stdout);

    if (parse_success == 1) {
        perror("Syntax error; could not successfully parse program");
        return 0;
    } else if (parse_success == 2) {
        perror("Error: ran out of memory while parsing");
        return 1;
    }

    // IMPORTANT NOTE: some things are not reversed
    // Lowkey kinda buggy
    ast_root = reverse_lists(ast_root, true);
    std::cout << "Reversed lists\n";
    fflush(stdout);

    print_ast(ast_root, "output.ast");
    std::cout << "Printed AST\n";
    fflush(stdout);

    sem_push_scope();
    bool sem_success = traverse_ast(ast_root);
    sem_pop_scope();

    std::cout << error_count << " errors generated\n";
    if (error_count > 0) return 0;

    /*
        Generate LLVM
    */

    std::unique_ptr<llvm::Module> llvm_module;
    std::unique_ptr<llvm::LLVMContext> context;

    if (auto opt = generate_llvm(ast_root)) {
        llvm_module = std::move(opt->first);
        context = std::move(opt->second);
    } else return 1;


    write_module_to_file(*llvm_module, "llvm_output.ll");

    llvm_module.release();
    context.release();

    return 0;
}