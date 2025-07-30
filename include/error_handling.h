/*
    Helps to handle compilation errors that this compiler may run into
    Also handles possible runtime exceptions like malloc errors
*/

#pragma once

void check_malloc_error(void *ptr, char *message);