/*
    Includes several helpful enums that are required across multiple files
*/

#pragma once

typedef enum {
    SC_NONE,
    SC_TYPEDEF,
    SC_EXTERN,
    SC_STATIC,
    SC_AUTO,
    SC_REGISTER
} storage_class;

typedef enum {
    FS_INLINE // Only inline in C99
} func_spec;

typedef enum {
    TQ_CONST,
    TQ_RESTRICT,
    TQ_VOLATILE
} type_qual;