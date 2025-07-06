%{
#include <stdio.h>
#include "token_types.h"

extern void yyerror(const char *);


static void comment(void);
%}

/* ——— Definitions ——— */

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%%

(" "|\t|\n)                         { /* Skip whitespace */ }
"//"[^\n]*                          { /* Skip comment */ }
"/*"([^*]|\*+[^*/])*"*"+"/"         { comment(); }

<<EOF>>                             { return END_OF_FILE; }
    
"auto"                              { return AUTO; }
"break"                             { return BREAK; }
"case"                              { return CASE; }
"char"                              { return CHAR; }
"const"                             { return CONST; }
"continue"                          { return CONTINUE; }
"default"                           { return DEFAULT; }
"do"                                { return DO; }
"double"                            { return DOUBLE; }
"else"                              { return ELSE; }
"enum"                              { return ENUM; }
"extern"                            { return EXTERN; }
"float"                             { return FLOAT; }
"for"                               { return FOR; }
"goto"                              { return GOTO; }
"if"                                { return IF; }
"inline"                            { return INLINE; }
"int"                               { return INT; }
"long"                              { return LONG; }
"register"                          { return REGISTER; }
"restrict"                          { return RESTRICT; }
"return"                            { return RETURN; }
"short"                             { return SHORT; }
"signed"                            { return SIGNED; }
"sizeof"                            { return SIZEOF; }
"static"                            { return STATIC; }
"struct"                            { return STRUCT; }
"switch"                            { return SWITCH; }
"typedef"                           { return TYPEDEF; }
"union"                             { return UNION; }
"unsigned"                          { return UNSIGNED; }
"void"                              { return VOID; }
"volatile"                          { return VOLATILE; }
"while"                             { return WHILE; }
"_Alignas"                          { return ALIGNAS; }
"_Alignof"                          { return ALIGNOF; }
"_Atomic"                           { return ATOMIC; }
"_Bool"                             { return BOOL; }
"_Complex"                          { return COMPLEX; }
"_Generic"                          { return GENERIC; }
"_Imaginary"                        { return IMAGINARY; }
"_Noreturn"                         { return NORETURN; }
"_Static_assert"                    { return STATIC_ASSERT; }
"_Thread_local"                     { return THREAD_LOCAL; }
"__func__"                          { return FUNC_NAME; }

{HP}{H}+{IS}?				        { return INT_LITERAL; }
{NZ}{D}*{IS}?				        { return INT_LITERAL; }
"0"{O}*{IS}?				        { return INT_LITERAL; }
{CP}?"'"([^'\\\n]|{ES})+"'"         { return INT_LITERAL; }

{D}+{E}{FS}?				        { return FLOAT_LITERAL; }
{D}*"."{D}+{E}?{FS}?		        { return FLOAT_LITERAL; }
{D}+"."{E}?{FS}?			        { return FLOAT_LITERAL; }
{HP}{H}+{P}{FS}?			        { return FLOAT_LITERAL; }
{HP}{H}*"."{H}+{P}{FS}?		        { return FLOAT_LITERAL; }
{HP}{H}+"."{P}{FS}?			        { return FLOAT_LITERAL; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { return STR_LITERAL; }

"&&"                                { return LOGIC_AND; }
"||"                                { return LOGIC_OR; }
"!"                                 { return LOGIC_NOT; }

"&"                                 { return BIT_AND; }
"|"                                 { return BIT_OR; }
"^"                                 { return BIT_XOR; }
"~"                                 { return BIT_NOT; }
"<<"                                { return LSHIFT; }
">>"                                { return RSHIFT; }

"+="                                { return PLUS_ASSIGN; }
"-="                                { return MINUS_ASSIGN; }
"*="                                { return MUL_ASSIGN; }
"/="                                { return DIV_ASSIGN; }
"%="                                { return MOD_ASSIGN; }

"&="                                { return AND_ASSIGN; }
"|="                                { return OR_ASSIGN; }
"^="                                { return XOR_ASSIGN; }
"<<="                               { return LSHIFT_ASSIGN; }
">>="                               { return RSHIFT_ASSIGN; }

"++"                                { return INCREMENT; }
"--"                                { return DECREMENT; }

"=="                                { return EQUAL; }
"!="                                { return NOT_EQUAL; }
"<"                                 { return LESS; }
">"                                 { return GREATER; }
"<="                                { return LEQ; }
">="                                { return GEQ; }

"->"                                { return ARROW; }

"="                                 { return ASSIGN; }

"+"                                 { return PLUS; }
"-"                                 { return MINUS; }
"*"                                 { return ASTERISK; }
"/"                                 { return SLASH; }
"%"                                 { return PERCENT; }

"?"                                 { return QUESTION; }
":"                                 { return COLON; }

","                                 { return COMMA; }
";"                                 { return SEMICOLON; }
"."                                 { return DOT; }
"..."                               { return ELLIPSIS; }

"("                                 { return LPAREN; }
")"                                 { return RPAREN; }
"["|"<:"                            { return LBRACKET; }
"]"|":>"                            { return RBRACKET; }
"{"|"<%"                            { return LBRACE; }
"}"|"%>"                            { return RBRACE; }

{L}{A}+                             { return check_type(); }

.                                   { return ERROR; }

%%

int yywrap() { return 1; }

static void comment(void) {
    int c;
    while ((c = input()) != 0) {
        if (c == '*') {
            while ((c = input()) == '*');

            if (c == '/') return;

            if (c == 0) break;
        }
    }
    yyerror("unterminated comment");
}