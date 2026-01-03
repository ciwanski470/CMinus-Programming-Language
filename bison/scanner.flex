%{
#include <stdio.h>
#include "parser_symbols.h"
#include "parser.h"

extern void yyerror(const char *); // Prints grammar errors

static int check_type();
%}

D			[0-9]
L			[a-zA-Z_]
FS			(f|F|d|D)
IS          ((u|U)?(l|L|ll|LL|s|S)?)
WS          [ \t\v\n\f]

%option nounput
%option yylineno

%x COMMENT

%%
"/*"			            { BEGIN(COMMENT); }
<COMMENT>"*/"               { BEGIN(INITIAL); }
<COMMENT>"\n"               { yylineno++; }
<COMMENT>.                  { /* consume comment */ }
"//".*                      { /* consume comment */ }


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
"bool"			            { return BOOL; }
"__func__"                  { return FUNC_NAME; }

(U|u)?'\\.'	                { yylval.sval = strdup(yytext); return CONST_INT; }

{D}*"."{D}+{FS}?	        { yylval.sval = strdup(yytext); return CONST_FLOAT; }
{D}+"."{D}*{FS}?	        { yylval.sval = strdup(yytext); return CONST_FLOAT; }

(0|[1-9]{D}*){IS}?		    { yylval.sval = strdup(yytext); return CONST_INT; }

{L}({L}|{D})*		        { yylval.sval = strdup(yytext); return check_type(); }

\"(\\.|[^\\"\n])*\"	        { yylval.sval = strdup(yytext); return STR_LITERAL; }

"..."			            { return ELLIPSIS; }
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
"+="                        { return ADD_ASSIGN; }
"-="                        { return SUB_ASSIGN; }
"*="                        { return MUL_ASSIGN; }
"/="                        { return DIV_ASSIGN; }
"%="                        { return MOD_ASSIGN; }
"&="                        { return AND_ASSIGN; }
"|="                        { return OR_ASSIGN; }
"^="                        { return XOR_ASSIGN; }
"<<="                       { return LSHIFT_ASSIGN; }
">>="                       { return RSHIFT_ASSIGN; }
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

"\n"                        { yylineno++; }
{WS}+		                { /* Consume whitespace */ }
<<EOF>>                     { return 0; }
.			                { yyerror("*** Bad character"); }

%%

int yywrap() {
	return 1;
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