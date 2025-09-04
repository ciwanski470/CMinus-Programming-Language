/*
    Implementation of "error_handling.h"
*/

#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>

extern void yyerror(const char *s);

void check_alloc_error(void *ptr, char *message) {
    if (!ptr) {
        perror(message);
        exit(1);
    }
}

void push_error(const char *message) {
    yyerror(message);
}

