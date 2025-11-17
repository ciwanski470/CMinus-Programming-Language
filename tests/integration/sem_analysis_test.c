#include "ast.h"
#include "error_handling.h"
#include "parser_symbols.h"
#include "parser_helpers.h"
#include "parser.h"
#include "sem_analysis.h"
#include "semantic_symtab.h"
#include <stdio.h>

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

int main() {
    yyin = fopen("tests/data/sem_analysis_test.cm", "r");
    yydebug = false;

    sym_push_scope();
    int parse_success = yyparse();
    sym_pop_scope();

    if (parse_success != 0) exit(1);

    ast_root = reverse_lists(ast_root, true);

    sem_push_scope();
    bool sem_success = traverse_ast(ast_root);
    sem_pop_scope();

    // It should pass
    if (sem_success) {
        printf("semantic analysis PASSED test\n");
        exit(0);
    }
    printf("semantic analysis FAILED test\n");
    exit(1);
}