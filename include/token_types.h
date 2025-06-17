// File contains the enum for all types of tokens the scanner can read

#pragma once

typedef enum {
    // --- Keywords ---
    TOKEN_AUTO,
    TOKEN_BREAK,
    TOKEN_CASE,
    TOKEN_CHAR,
    TOKEN_CONST,
    TOKEN_CONTINUE,
    TOKEN_DEFAULT,
    TOKEN_DO,
    TOKEN_DOUBLE,
    TOKEN_ELSE,
    TOKEN_ENUM,
    TOKEN_EXTERN,
    TOKEN_FLOAT,
    TOKEN_FOR,
    TOKEN_GOTO,
    TOKEN_IF,
    TOKEN_INLINE,
    TOKEN_INT,
    TOKEN_LONG,
    TOKEN_REGISTER,
    TOKEN_RESTRICT,
    TOKEN_RETURN,
    TOKEN_SHORT,
    TOKEN_SIGNED,
    TOKEN_SIZEOF,
    TOKEN_STATIC,
    TOKEN_STRUCT,
    TOKEN_SWITCH,
    TOKEN_TYPEDEF,
    TOKEN_UNION,
    TOKEN_UNSIGNED,
    TOKEN_VOID,
    TOKEN_VOLATILE,
    TOKEN_WHILE,
    TOKEN_ALIGNAS,
    TOKEN_ALIGNOF,
    TOKEN_ATOMIC,
    TOKEN_BOOL,
    TOKEN_COMPLEX,
    TOKEN_GENERIC,
    TOKEN_IMAGINARY,
    TOKEN_NORETURN,
    TOKEN_STATIC_ASSERT,
    TOKEN_THREAD_LOCAL,

    // --- Operators ---

    // Arithmetic
    TOKEN_PLUS,             // +
    TOKEN_MINUS,            // -
    TOKEN_ASTERISK,         // *
    TOKEN_SLASH,            // /
    TOKEN_PERCENT,          // %

    // Bitwise
    TOKEN_BIT_AND,          // &
    TOKEN_BIT_OR,           // |
    TOKEN_BIT_XOR,          // ^
    TOKEN_BIT_NOT,          // ~
    TOKEN_LSHIFT,           // <<
    TOKEN_RSHIFT,           // >>

    // Logical
    TOKEN_LOGIC_AND,        // &&
    TOKEN_LOGIC_OR,         // ||
    TOKEN_LOGIC_NOT,        // !

    // Assignment
    TOKEN_ASSIGN,           // =
    TOKEN_PLUS_ASSIGN,      // +=
    TOKEN_MINUS_ASSIGN,     // -=
    TOKEN_MUL_ASSIGN,       // *=
    TOKEN_DIV_ASSIGN,       // /=
    TOKEN_MOD_ASSIGN,       // %=

    // Bitwise assignment
    TOKEN_AND_ASSIGN,       // &=
    TOKEN_OR_ASSIGN,        // |=
    TOKEN_XOR_ASSIGN,       // ^=
    TOKEN_LSHIFT_ASSIGN,    // <<=
    TOKEN_RSHIFT_ASSIGN,    // >>=

    // Increment/Decrement
    TOKEN_INCREMENT,        // ++
    TOKEN_DECREMENT,        // --

    // Comparison
    TOKEN_EQUAL,            // ==
    TOKEN_NOT_EQUAL,        // !=
    TOKEN_LESS,             // <
    TOKEN_GREATER,          // >
    TOKEN_LEQ,              // <=
    TOKEN_GEQ,              // >=

    // Ternary
    TOKEN_QUESTION,         // ?
    TOKEN_COLON,            // :

    // Punctuation
    TOKEN_COMMA,            // ,
    TOKEN_SEMICOLON,        // ;
    TOKEN_DOT,              // .
    TOKEN_ARROW,            // ->
    TOKEN_ELLIPSIS,         // ...

    // Brackets
    TOKEN_LPAREN,           // (
    TOKEN_RPAREN,           // )
    TOKEN_LBRACKET,         // [
    TOKEN_RBRACKET,         // ]
    TOKEN_LBRACE,           // {
    TOKEN_RBRACE,           // }

    // --- Identifiers ---
    TOKEN_IDENTIFIER,

    // --- Literals ---
    TOKEN_INT_LITERAL,
    TOKEN_FLOAT_LITERAL,
    TOKEN_CHAR_LITERAL,
    TOKEN_STR_LITERAL,

    // --- Special Tokens ---
    TOKEN_EOF,
    TOKEN_ERROR
} token_t;