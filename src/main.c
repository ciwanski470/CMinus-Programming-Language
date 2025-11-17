#include "ast.h"
#include "ast_printer.h"
#include "parser_symbols.h"
#include "parser_helpers.h"
#include "parser.h"
#include "sem_analysis.h"
#include "semantic_symtab.h"
#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        perror("No program specified");
        exit(1);
    }
    if (argc > 2) {
        perror("Can only compile one program");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    yydebug = 0;

    printf("Opened File\n");
    fflush(stdout);
    
    sym_push_scope();
    int parse_success = yyparse();
    sym_pop_scope();

    printf("Finished parsing\n");
    fflush(stdout);

    if (parse_success == 1) {
        perror("Syntax error; could not successfully parse program");
        exit(0);
    } else if (parse_success == 2) {
        perror("Error: ran out of memory while parsing");
        exit(1);
    }

    // IMPORTANT NOTE: some things are not reversed
    // Lowkey kinda buggy
    ast_root = reverse_lists(ast_root, true);
    printf("Reversed lists\n");
    fflush(stdout);

    print_ast(ast_root, "output.ast");
    printf("Printed AST\n");
    fflush(stdout);

    sem_push_scope();
    bool sem_success = traverse_ast(ast_root);
    sem_pop_scope();

    printf("%d errors generated\n", error_count);
    if (error_count > 0) exit(0);

    exit(0);
}