/*
    Implementation of "error_handling.h"
*/

#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>

static inline void check_malloc_error(void *ptr, char *message) {
    if (!ptr) {
        perror(message);
        exit(1);
    }
}