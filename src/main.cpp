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

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

enum compiler_tag {
    OUTPUT_AST,
    OUTPUT_LLVM
};

std::map<std::string, compiler_tag> match_tag = {
    {"-ast", OUTPUT_AST},
    {"-print-llvm", OUTPUT_LLVM}
};

// Returns -1ULL if there's an issue with the tags
// If there are ever more than 64 tags, switch from uint64_t to bitset
uint64_t get_tags(int argc, char *argv[]) {
    if (argc < 3) return 0;

    uint64_t tags = 0;
    for (int i=2; i<argc; i++) {
        auto it = match_tag.find(std::string(argv[i]));

        // Check for invalid tag
        if (it == match_tag.end()) {
            std::cerr << "Tag '" << argv[i] << "' is invalid\n";
            return -1ULL;
        }

        compiler_tag new_tag = it->second;

        // Check for duplicate tag
        if (tags & (1 << new_tag)) {
            std::cerr << "Duplicate tag '" << argv[i] << "'\n";
            return -1ULL;
        }

        tags |= 1 << new_tag;
    }

    return tags;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "No program specified\n";
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yydebug = 0;

    if (!yyin) {
        std::cerr << "Cannot find file '" << argv[1] << "'\n";
        return 1;
    }

    uint64_t tags = get_tags(argc, argv);
    if (tags == -1ULL) {
        return 1;
    }
    tags = -1ULL;
    
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

    if (tags & (1 << OUTPUT_AST)) {
        print_ast(ast_root, "output.ast");
    }

    sem_push_scope();
    bool sem_success = traverse_ast(ast_root);
    sem_pop_scope();

    std::cout << error_count << " errors generated\n";
    if (error_count > 0 || !sem_success) return 0;

    /*
        Generate LLVM
    */

    std::unique_ptr<llvm::Module> llvm_module;
    std::unique_ptr<llvm::LLVMContext> context;

    if (auto opt = generate_llvm(ast_root)) {
        llvm_module = std::move(opt->first);
        context = std::move(opt->second);
    } else return 1;

    if (tags & (1 << OUTPUT_LLVM)) {
        write_module_to_file(*llvm_module, "llvm_output.ll");
    }

    llvm_module.release();
    context.release();

    return 0;
}