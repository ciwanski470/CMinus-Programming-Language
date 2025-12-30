#include "decl_type.h"
#include "string_helpers.h"
#include "sem_analysis.h"
#include "semantic_symtab.h"
#include "parser_helpers.h"
#include "parser_symbols.h"
#include "parser.h"
#include "ast_printer.h"
#include <stdio.h>
#include <stdbool.h>

extern FILE *yyin;
extern translation_unit *ast_root;
extern int yydebug;

#define verify(test_num) \
    printf("Expected: %s\n", type_to_s(expected)); \
    printf("Actual: %s\n", type_to_s(actual)); \
    if (types_equal(expected, actual)) { \
        printf("decl_type passed test #%d\n", test_num); \
        passed++; \
    } else { \
        printf("decl_type failed test #%d\n", test_num); \
    } \
    printf("\n")

int main(void) {
    printf("\n");
    int passed = 0;
    const int total = 5;

    yyin = fopen("tests/data/decl_type_test.cm", "r");
    yydebug = false;

    sym_push_scope();
    int parse_success = yyparse();
    sym_pop_scope();

    ast_root = reverse_lists(ast_root, true);

    translation_unit *t = ast_root;

    //print_ast(ast_root, "decl_type_tree.ast");

    // First test
    {   
        printf("decl_type test 1:\n");
        decl *curr_decl = t->action->decl;

        sem_type_t *expected = make_array_type(
            make_pointer_type(make_primitive_type(ST_INT, true, 0), 0),
            10,
            false
        );
        sem_type_t *actual = decl_type(curr_decl->specs, curr_decl->init_decltrs->decltr, false);

        verify(1);
    }

    t = t->next;

    // Second test
    {
        printf("decl_type test 2:\n");
        decl *curr_decl = t->action->decl;

        sem_type_list_t *params = alloc_sem_type_list(make_primitive_type(ST_INT, true, 0));
        params->next = alloc_sem_type_list(make_primitive_type(ST_SHORT, true, TQ_VOLATILE_MASK));
        params->next->next = alloc_sem_type_list(make_primitive_type(ST_DOUBLE, false, 0));

        sem_type_t *expected = make_array_type(
            make_pointer_type(
                make_func_type(
                    make_pointer_type(make_primitive_type(ST_VOID, false, 0), 0),
                    params
                ),
                0
            ),
            10,
            false
        );

        sem_type_t *actual = decl_type(curr_decl->specs, curr_decl->init_decltrs->decltr, false);

        verify(2);
    }

    t = t->next;
    
    // Third test
    {
        printf("decl_type test 3:\n");
        decl *curr_decl = t->action->decl;

        sem_type_t *expected = make_primitive_type(ST_VOID, false, TQ_CONST_MASK);
        sem_type_t *actual = decl_type(curr_decl->specs, curr_decl->init_decltrs->decltr, false);

        verify(3);
    }

    t = t->next;
    
    // Fourth test
    {
        printf("decl_type test 4:\n");
        decl *curr_decl = t->action->decl;

        sem_type_t *expected = make_primitive_type(ST_INT, true, 0);
        sem_type_t *actual = decl_type(curr_decl->specs, curr_decl->init_decltrs->decltr, false);

        verify(4);
    }

    t = t->next;

    // Fifth test
    {
        printf("decl_type test 5:\n");
        decl *curr_decl = t->action->decl;

        sem_type_t *expected = make_pointer_type(
            make_func_type(
                make_primitive_type(ST_INT, true, 0),
                alloc_sem_type_list(make_primitive_type(ST_INT, true, 0))
            ),
            0
        );
        sem_type_t *actual = decl_type(curr_decl->specs, curr_decl->init_decltrs->decltr, false);

        verify(5);
    }

    if (passed < total) exit(1);
    exit(0);
}