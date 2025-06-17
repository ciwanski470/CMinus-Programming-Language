%{
#include "token_types.h"
%}

L_SUFFIX            L|l
LL_SUFFIX           (ll)|(LL)
F_SUFFIX            [LlFf]
U_SUFFIX            U|u

EXP_PART            [Ee][\+-]?[0-9]+
BIN_EXP_PART        [Pp][\+-]?[0-9]+

INT_SUFFIX          (U_SUFFIX L_SUFFIX | LL_SUFFIX) | (L_SUFFIX | LL_SUFFIX U_SUFFIX)     

DEC_FRAC_CONST      ([0-9]+?\.[0-9]+) | ([0-9]+\.)
HEX_FRAC_CONST      ([0-9a-fA-F]+?\.[0-9a-fA-F]+) | ([0-9a-fA-F]+.)

DEC_FLOAT_CONST     ((DEC_FRAC_CONST EXP_PART?) | ([0-9]+ EXP_PART)) F_SUFFIX?
HEX_FLOAT_CONST     0[Xx] (HEX_FRAC_CONST BIN_EXP_PART?) | ([0-9a-fA-F]+ BIN_EXP_PART) F_SUFFIX?

SIMPLE_ESC_SEQ      [(\\a)(\\b)(\\f)(\\n)(\\r)(\\t)(\\v)(\\')(\\\")(\\\\)(\\\?)]
OCTAL_ESC_SEQ       \\[0-7]{1,3}
HEX_ESC_SEQ         \\x[0-9a-fA-F]+
UNIVERSAL_CHAR      \\[Uu][0-9a-fA-F]{4}{1,2}

ESC_SEQ             SIMPLE_ESC_SEQ | OCTAL_ESC_SEQ | HEX_ESC_SEQ | UNIVERSAL_CHAR

C_CHAR              ([^'\\\n]) | ESC_SEQ
CHAR_CONST          L?' C_CHAR+ '

ENCODING_PREFIX     (u8) | [UuL]
S_CHAR              ([^\"\\\n]) | ESC_SEQ

STR_LITERAL         ENCODING_PREFIX? \" S_CHAR* \"

HASH                # | (%:)

%%

(" "|\t|\n)     // Skip whitespace

<<EOF>>                 { return TOKEN_EOF; }
    
auto                    { return TOKEN_AUTO; }
break                   { return TOKEN_BREAK; }
case                    { return TOKEN_CASE; }
char                    { return TOKEN_CHAR; }
const                   { return TOKEN_CONST; }
continue                { return TOKEN_CONTINUE; }
default                 { return TOKEN_DEFAULT; }
do                      { return TOKEN_DO; }
double                  { return TOKEN_DOUBLE; }
else                    { return TOKEN_ELSE; }
enum                    { return TOKEN_ENUM; }
extern                  { return TOKEN_EXTERN; }
float                   { return TOKEN_FLOAT; }
for                     { return TOKEN_FOR; }
goto                    { return TOKEN_GOTO; }
if                      { return TOKEN_IF; }
inline                  { return TOKEN_INLINE; }
int                     { return TOKEN_INT; }
long                    { return TOKEN_LONG; }
register                { return TOKEN_REGISTER; }
restrict                { return TOKEN_RESTRICT; }
return                  { return TOKEN_RETURN; }
short                   { return TOKEN_SHORT; }
signed                  { return TOKEN_SIGNED; }
sizeof                  { return TOKEN_SIZEOF; }
static                  { return TOKEN_STATIC; }
struct                  { return TOKEN_STRUCT; }
switch                  { return TOKEN_SWITCH; }
typedef                 { return TOKEN_TYPEDEF; }
union                   { return TOKEN_UNION; }
unsigned                { return TOKEN_UNSIGNED; }
void                    { return TOKEN_VOID; }
volatile                { return TOKEN_VOLATILE; }
while                   { return TOKEN_WHILE; }
_Alignas                { return TOKEN_ALIGNAS; }
_Alignof                { return TOKEN_ALIGNOF; }
_Atomic                 { return TOKEN_ATOMIC; }
_Bool                   { return TOKEN_BOOL; }
_Complex                { return TOKEN_COMPLEX; }
_Generic                { return TOKEN_GENERIC; }
_Imaginary              { return TOKEN_IMAGINARY; }
_Noreturn               { return TOKEN_NORETURN; }
_Static_assert          { return TOKEN_STATIC_ASSERT; }
_Thread_local           { return TOKEN_THREAD_LOCAL; }

\+                      { return TOKEN_PLUS; }
\-                      { return TOKEN_MINUS; }
\*                      { return TOKEN_ASTERISK; }
\/                      { return TOKEN_SLASH; }
\%                      { return TOKEN_PERCENT; }

&                       { return TOKEN_BIT_AND; }
\|                      { return TOKEN_BIT_OR; }
\^                      { return TOKEN_BIT_XOR; }
~                       { return TOKEN_BIT_NOT; }
\<\<                    { return TOKEN_LSHIFT; }
\>\>                    { return TOKEN_RSHIFT; }

&&                      { return TOKEN_LOGIC_AND; }
\|\|                    { return TOKEN_LOGIC_OR; }
!                       { return TOKEN_LOGIC_NOT; }

=                       { return TOKEN_ASSIGN; }
\+=                     { return TOKEN_PLUS_ASSIGN; }
-=                      { return TOKEN_MINUS_ASSIGN; }
\*=                     { return TOKEN_MUL_ASSIGN; }
\/=                     { return TOKEN_DIV_ASSIGN; }
%=                      { return TOKEN_MOD_ASSIGN; }

&=                      { return TOKEN_AND_ASSIGN; }
\|=                     { return TOKEN_OR_ASSIGN; }
\^=                     { return TOKEN_XOR_ASSIGN; }
\<\<=                   { return TOKEN_LSHIFT_ASSIGN; }
\>\>=                   { return TOKEN_RSHIFT_ASSIGN; }

\+\+                    { return TOKEN_INCREMENT; }
--                      { return TOKEN_DECREMENT; }

==                      { return TOKEN_EQUAL; }
!=                      { return TOKEN_NOT_EQUAL; }
\<                      { return TOKEN_LESS; }
\>                      { return TOKEN_GREATER; }
\<=                     { return TOKEN_LEQ; }
\>=                     { return TOKEN_GEQ; }

\?                      { return TOKEN_QUESTION; }
:                       { return TOKEN_COLON; }

\,                      { return TOKEN_COMMA; }
;                       { return TOKEN_SEMICOLON; }
\.                      { return TOKEN_DOT; }
->                      { return TOKEN_ARROW; }
\.\.\.                  { return TOKEN_ELLIPSIS; }

\(                      { return TOKEN_LPAREN; }
\)                      { return TOKEN_RPAREN; }
(\[)|(<:)               { return TOKEN_LBRACKET; }
(\])|(:>)               { return TOKEN_RBRACKET; }
(\{)|(<%)               { return TOKEN_LBRACE; }
(\})|(%>)               { return TOKEN_RBRACE; }

[a-zA-Z][a-zA-Z0-9]*    { return TOKEN_IDENTIFIER; }

[\+-]?0[Bb][01]+INT_SUFFIX?         { return TOKEN_INT_LITERAL; } // Binary int
[\+-]?0[Xx][0-9a-fA-F]+INT_SUFFIX?  { return TOKEN_INT_LITERAL; } // Hexadecimal int
[\+-]?[0-9]+INT_SUFFIX?             { return TOKEN_INT_LITERAL; } // Octal or Decimal int

DEC_FLOAT_CONST         { return TOKEN_FLOAT_LITERAL; } // Decimal float
HEX_FLOAT_CONST         { return TOKEN_FLOAT_LITERAL; } // Hexadecimal float

CHAR_CONST              { return TOKEN_CHAR_LITERAL; }

STR_LITERAL             { return TOKEN_STR_LITERAL; }

.                       { return TOKEN_ERROR; }

%%

int yywrap() { return 1; }