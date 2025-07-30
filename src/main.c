#include "ast.h"
#include "ast_printer.h"
#include "symbol_table.h"
#include "parser_helpers.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern translation_unit *ast_root;

int main() {
    yyin = fopen("example.txt", "r");
    
    sym_push_scope();
    int success = yyparse();
    sym_pop_scope();

    if (success == 1) {
        perror("Syntax error; could not successfully parse program");
        exit(1);
    } else if (success == 2) {
        perror("Error: ran out of memory while parsing");
        exit(1);
    }

    ast_root = reverse_lists(ast_root, 1);

    print_ast(ast_root, "output.ast");

    exit(0);
}