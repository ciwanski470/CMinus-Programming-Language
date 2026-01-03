/*
    Implementation of "error_handling.h"
*/

#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void check_alloc_error(void *ptr, char *message) {
    if (!ptr) {
        perror(message);
        exit(1);
    }
}

int error_count = 0;

void push_error(const char *format, ...) {
    va_list args;
    va_start(args, format);

    fflush(stdout);
	vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    error_count++;
}

