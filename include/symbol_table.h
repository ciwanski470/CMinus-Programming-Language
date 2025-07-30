/* 
    Handles the symbol table used to differentiate typedefs, enums, and indentifiers
    Manages the scope of these defined types
*/

#pragma once

/*
    Public enum for the types of symbols represented in the symbol table
    SYM_IDENTIFIER is unused in the table, but can be returned by sym_type
*/
typedef enum {
    SYM_IDENTIFIER,
    SYM_TYPEDEF,
    SYM_ENUM_CONST
} sym_kind;

/*
    Determines the type of the given token
    @param const char *token
        A token string following the regex rule {L}{A}+
    @return
        TYPEDEF_NAME if it is the name of a type given by typedef
        ENUM_CONST if it is a constant from an enum table
        IDENTIFIER if none of the above
*/
int sym_type(const char *token);

/*
    Pushes a new inner scope to the stack
    To be used at the start of a compound statement (at the '{')
    Ensure that this is always called exactly once right before calling yyparse()
*/
void sym_push_scope(void);

/*
    Removes the innermost scope from the stack
    To be used at the end of a compound statement (at the '}')
    Ensure that this is always called exactly once right after calling yyparse()
*/
void sym_pop_scope(void);

/*
    Adds a new typedef to the current scope
*/
void sym_define_typedef(const char *name);

/*
    Adds a new enum to the current scope
*/
void sym_define_enum(const char *name);