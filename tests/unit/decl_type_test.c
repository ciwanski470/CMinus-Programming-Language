#include "decl_type.h"
#include <stdio.h>

int main(void) {
    int passed = 0;
    const int total = 1;

    // First test
    {
        decl_spec_list *dsl = calloc(1, sizeof(decl_spec_list));
        dsl = add_type_spec(dsl, make_basic_type_spec(TS_INT));
        decl_specs *specs = make_decl_specs(dsl);
        decltr *d = make_id_decltr("a");
        d->next = make_decltr_array_suffix(
            NULL,
            NULL,
            make_const_expr(make_constant(CONSTANT_INT, "10"))
        );
        d->ptr = make_pointer(NULL, NULL);

        sem_type_t *expected = make_array_type(
            make_pointer_type(
                make_primitive_type(ST_INT, false, 0),
                0
            ),
            10,
            false
        );
        sem_type_t *actual = decl_type(specs, d, false);
        if (types_equal(expected, actual)) {
            passed++;
        } else {
            printf("decl_type failed test for \"int *a[10];\"\n");
        }
    }

    if (passed < total) exit(1);
    exit(0);
}