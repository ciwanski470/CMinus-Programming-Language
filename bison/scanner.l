%{
#include <stdio.h>
#include "token_types.h"

extern void yyerror(const char *); // Prints grammar errors
extern int sym_type(const char *); // Returns symbol type from the symbol table

static void comment(void);
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P           ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS          ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))
WS          [ \t\v\n\f]

%%
"/*"			            { comment(); }
"//"[^\n]*                  { /* consume comment */ }


"auto"			            { return AUTO; }
"break"			            { return BREAK; }
"case"			            { return CASE; }
"char"			            { return CHAR; }
"const"			            { return CONST; }
"continue"		            { return CONTINUE; }
"default"		            { return DEFAULT; }
"do"			            { return DO; }
"double"		            { return DOUBLE; }
"else"			            { return ELSE; }
"enum"			            { return ENUM; }
"extern"		            { return EXTERN; }
"float"			            { return FLOAT; }
"for"			            { return FOR; }
"goto"			            { return GOTO; }
"if"			            { return IF; }
"inline"		            { return INLINE; }
"int"			            { return INT; }
"long"			            { return LONG; }
"register"		            { return REGISTER; }
"restrict"		            { return RESTRICT; }
"return"		            { return RETURN; }
"short"			            { return SHORT; }
"signed"		            { return SIGNED; }
"sizeof"		            { return SIZEOF; }
"static"		            { return STATIC; }
"struct"		            { return STRUCT; }
"switch"		            { return SWITCH; }
"typedef"		            { return TYPEDEF; }
"union"			            { return UNION; }
"unsigned"		            { return UNSIGNED; }
"void"			            { return VOID; }
"volatile"		            { return VOLATILE; }
"while"			            { return WHILE; }
"_Bool"			            { return BOOL; }
"_Complex"		            { return COMPLEX; }
"_Imaginary"		        { return IMAGINARY; }
"__func__"                  { return FUNC_NAME; }

{L}({L}|{D})*		        { yylval.sval = yytext; return check_type(); }

0[xX]{H}+{IS}?		        { yylval.sval = yytext; return CONST_INT; }
0[0-7]*{IS}?		        { yylval.sval = yytext; return CONST_INT; }
[1-9]{D}*{IS}?		        { yylval.sval = yytext; return CONST_INT; }
L?'(\\.|[^\\'\n])+'	        { yylval.sval = yytext; return CONST_INT; }

{D}+{E}{FS}?		        { yylval.sval = yytext; return CONST_FLOAT; }
{D}*"."{D}+{E}?{FS}?	    { yylval.sval = yytext; return CONST_FLOAT; }
{D}+"."{D}*{E}?{FS}?	    { yylval.sval = yytext; return CONST_FLOAT; }
0[xX]{H}+{P}{FS}?	        { yylval.sval = yytext; return CONST_FLOAT; }
0[xX]{H}*"."{H}+{P}{FS}?    { yylval.sval = yytext; return CONST_FLOAT; }
0[xX]{H}+"."{H}*{P}{FS}?    { yylval.sval = yytext; return CONST_FLOAT; }


L?\"(\\.|[^\\"\n])*\"	    { yylval.sval = yytext; return STR_LITERAL; }

"..."			            { return ELLIPSIS; }
">>="			            { return RSHIFT_ASSIGN; }
"<<="			            { return LSHIFT_ASSIGN; }
"+="			            { return ADD_ASSIGN; }
"-="			            { return SUB_ASSIGN; }
"*="			            { return MUL_ASSIGN; }
"/="			            { return DIV_ASSIGN; }
"%="			            { return MOD_ASSIGN; }
"&="			            { return AND_ASSIGN; }
"^="			            { return XOR_ASSIGN; }
"|="			            { return OR_ASSIGN; }
">>"			            { return RSHIFT; }
"<<"			            { return LSHIFT; }
"++"			            { return INCREMENT; }
"--"			            { return DECREMENT; }
"->"			            { return ARROW; }
"&&"			            { return AND; }
"||"			            { return OR; }
"<="			            { return LEQ; }
">="			            { return GEQ; }
"=="			            { return EQUAL; }
"!="			            { return NOT_EQUAL; }
";"			                { return ';'; }
("{"|"<%")		            { return '{'; }
("}"|"%>")		            { return '}'; }
","			                { return ','; }
":"			                { return ':'; }
"="			                { return '='; }
"("			                { return '('; }
")"			                { return ')'; }
("["|"<:")		            { return '['; }
("]"|":>")		            { return ']'; }
"."			                { return '.'; }
"&"			                { return '&'; }
"!"			                { return '!'; }
"~"			                { return '~'; }
"-"			                { return '-'; }
"+"			                { return '+'; }
"*"			                { return '*'; }
"/"			                { return '/'; }
"%"			                { return '%'; }
"<"			                { return '<'; }
">"			                { return '>'; }
"^"			                { return '^'; }
"|"			                { return '|'; }
"?"			                { return '?'; }

{WS}+		                { /* Consume whitespace */ }
.			{ yyerror("Bad character") }

%%

int yywrap() {
	return 1;
}


static void comment() {
    int c;

    while ((c = input()) != 0)
        if (c == '*') {
            while ((c = input()) == '*');

            if (c == '/') return;
            
            if (c == 0) break;
        }
    yyerror("unterminated comment");
}

static int check_type() {
    switch (sym_type(yytext)) {
        case SYM_TYPEDEF:
            return TYPEDEF_NAME;
        case SYM_ENUM_CONST:
            return ENUM_CONST;
        default:
            return IDENTIFIER;
    }
}