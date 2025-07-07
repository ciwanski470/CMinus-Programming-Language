/* 
    Handles the symbol table used to differentiate typedefs, enums, and indentifiers
    Manages the scope of these defined types
*/

#pragma once

/*
    Determines the type of the given token
    @param const char *token
        A token string following the regex rule {L}{A}+
    @return
        TYPEDEF_NAME if it is the name of a type given by typedef
        ENUM_CONST if it is a constant from an enum table
        IDENTIFIER if none of the above
*/
static inline int sym_type(const char *token);