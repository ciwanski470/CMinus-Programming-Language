/*
    Functionality for errors that the compiler runs into during compilation
    Also handles possible runtime exceptions like malloc errors
*/

#pragma once

void check_alloc_error(void *ptr, char *message);

void push_error(const char *message);