// File contains the enum for all types of tokens the scanner can read

#pragma once

typedef enum {
    // --- Keywords ---
    AUTO,
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
    FUNC_NAME,
    FOR,
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

    // Arithmetic
    PLUS,             // +
    MINUS,            // -
    ASTERISK,         // *
    SLASH,            // /
    PERCENT,          // %

    // Bitwise
    BIT_AND,          // &
    BIT_OR,           // |
    BIT_XOR,          // ^
    BIT_NOT,          // ~
    LSHIFT,           // <<
    RSHIFT,           // >>

    // Logical
    LOGIC_AND,        // &&
    LOGIC_OR,         // ||
    LOGIC_NOT,        // !

    // Assignment
    ASSIGN,           // =
    PLUS_ASSIGN,      // +=
    MINUS_ASSIGN,     // -=
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
    LESS,             // <
    GREATER,          // >
    LEQ,              // <=
    GEQ,              // >=

    // Ternary
    QUESTION,         // ?
    COLON,            // :

    // Punctuation
    COMMA,            // ,
    SEMICOLON,        // ;
    DOT,              // .
    ARROW,            // ->
    ELLIPSIS,         // ...

    // Brackets
    LPAREN,           // (
    RPAREN,           // )
    LBRACKET,         // [
    RBRACKET,         // ]
    LBRACE,           // {
    RBRACE,           // }

    // --- Identifiers ---
    IDENTIFIER,

    // --- Literals ---
    INT_LITERAL,
    FLOAT_LITERAL,
    STR_LITERAL,

    // --- Comments ---
    COMMENT,

    // --- Special Tokens ---
    END_OF_FILE,
    ERROR
} token_t;