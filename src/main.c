#include "ast.h"
#include "ast_printer.h"
#include "parser_symbols.h"
#include "parser_helpers.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        perror("No program specified");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    yydebug = 0;

    printf("Opened File\n");
    fflush(stdout);
    
    sym_push_scope();
    int success = yyparse();
    sym_pop_scope();

    printf("Finished parsing\n");
    fflush(stdout);

    if (success == 1) {
        perror("Syntax error; could not successfully parse program");
        exit(1);
    } else if (success == 2) {
        perror("Error: ran out of memory while parsing");
        exit(1);
    }

    // IMPORTANT NOTE: some things are not reversed
    // Lowkey kinda buggy
    ast_root = reverse_lists(ast_root, 1);
    printf("Reversed lists\n");
    fflush(stdout);

    print_ast(ast_root, "output.ast");
    printf("Printed AST\n");
    fflush(stdout);

    exit(0);
}