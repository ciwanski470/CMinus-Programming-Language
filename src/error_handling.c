/*
    Implementation of "error_handling.h"
*/

#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>

void check_alloc_error(void *ptr, char *message) {
    if (!ptr) {
        perror(message);
        exit(1);
    }
}

int error_count = 0;

void push_error(const char *message) {
    fflush(stdout);
	fprintf(stderr, "%s\n", message);
    error_count++;
}

