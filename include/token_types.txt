// File contains the enum for all types of tokens the scanner can read
// Note that single character tokens are not given an enum, and are instead handled as chars

#pragma once

typedef enum {
    // --- Keywords ---
    AUTO = 256, // Prevents collisions with the char values of single characters
    BREAK,
    CASE,
    CHAR,
    CONST,
    CONTINUE,
    DEFAULT,
    DO,
    DOUBLE,
    ELSE,
    ENUM,
    EXTERN,
    FLOAT,
    FOR,
    FUNC_NAME,
    GOTO,
    IF,
    INLINE,
    INT,
    LONG,
    REGISTER,
    RESTRICT,
    RETURN,
    SHORT,
    SIGNED,
    SIZEOF,
    STATIC,
    STRUCT,
    SWITCH,
    TYPEDEF,
    UNION,
    UNSIGNED,
    VOID,
    VOLATILE,
    WHILE,
    ALIGNAS,
    ALIGNOF,
    ATOMIC,
    BOOL,
    COMPLEX,
    GENERIC,
    IMAGINARY,
    NORETURN,
    STATIC_ASSERT,
    THREAD_LOCAL,

    // --- Operators ---

    // Bitwise
    LSHIFT,           // <<
    RSHIFT,           // >>

    // Logical
    AND,              // &&
    OR,               // ||

    // Assignment
    ADD_ASSIGN,       // +=
    SUB_ASSIGN,       // -=
    MUL_ASSIGN,       // *=
    DIV_ASSIGN,       // /=
    MOD_ASSIGN,       // %=

    // Bitwise assignment
    AND_ASSIGN,       // &=
    OR_ASSIGN,        // |=
    XOR_ASSIGN,       // ^=
    LSHIFT_ASSIGN,    // <<=
    RSHIFT_ASSIGN,    // >>=

    // Increment/Decrement
    INCREMENT,        // ++
    DECREMENT,        // --

    // Comparison
    EQUAL,            // ==
    NOT_EQUAL,        // !=
    LEQ,              // <=
    GEQ,              // >=
    ARROW,            // ->
    ELLIPSIS,         // ...

    // --- Identifier-like tokens ---
    IDENTIFIER,
    TYPEDEF_NAME,
    ENUM_CONST,

    // --- Constants and literals ---
    CONST_INT,
    CONST_FLOAT,
    STR_LITERAL,

    // --- Special Tokens ---
    ERROR
} token_t;