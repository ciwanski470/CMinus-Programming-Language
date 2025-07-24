/*
    Helps to handle compilation errors that this compiler may run into
    Also handles possible runtime exceptions like malloc errors
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

static inline void check_malloc_error(void *ptr, char *message);