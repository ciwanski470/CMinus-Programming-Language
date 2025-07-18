%{
#include <stdio.h>
#include "token_types.h"
#include "symbol_table.h"
#include "parser_context.h"
#include "ast.h"
%}

%token DEFAULT IF ELSE SWITCH CASE WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token ENUM STRUCT UNION

%token CHAR INT SHORT LONG FLOAT DOUBLE BOOL VOID SIGNED UNSIGNED
%token CONST RESTRICT VOLATILE

%token COMPLEX IMAGINARY

%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND_ASSIGN OR_ASSIGN XOR_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN
%token INCREMENT DECREMENT
%token AND OR
%token LSHIFT RSHIFT

%token EQUAL NOT_EQUAL LEQ GEQ

%token ARROW
%token ELLIPSIS

%token IDENTIFIER TYPEDEF_NAME ENUM_CONST 

%token CONST_INT CONST_FLOAT STR_LITERAL FUNC_NAME SIZEOF

// Start declaration
%start translation_unit

%union {
    char *sval;
    int int_val;
    expr *expr;
    constant *constant;
    decl *decl;
    ext_decl *ext_decl;
    decl_list *decl_list;
    func_def *func_def;
    translation_unit *trans_unit;
}

// Terminals
%type <sval> IDENTIFIER
%type <sval> ENUM_CONST
%type <sval> TYPEDEF_NAME
%type <sval> CONST_INT
%type <sval> CONST_FLOAT
%type <sval> STR_LITERAL

// Expressions
%type <expr> expression
%type <expr> primary_expression
%type <expr> postfix_expression
%type <expr> argument_expression_list
%type <expr> unary_expression
%type <expr> cast_expression
%type <expr> multiplicative_expression
%type <expr> additive_expression
%type <expr> shift_expression
%type <expr> relational_expression
%type <expr> equality_expression
%type <expr> and_expression
%type <expr> exclusive_or_expression
%type <expr> inclusive_or_expression
%type <expr> logical_and_expression
%type <expr> logical_or_expression
%type <expr> conditional_expression
%type <expr> assignment_expression
%type <expr> constant_expression

// Operators
%type <int_val> unary_operator
%type <int_val> assignment_operator

%type <constant> constant
%type <sval> string
%type <decl> declaration
%type <ext_decl> external_declaration
%type <decl_list> declaration_list
%type <func_def> function_definition
%type <trans_unit> translation_unit

%%

primary_expression
	: IDENTIFIER            { $$ = make_id_expr(yylval.sval); }
	| constant              { $$ = make_const_expr($1); }
	| string                { $$ = make_str_expr($1); }
	| '(' expression ')'    { $$ = $1; }
	;

constant
    : CONST_INT     { $$ = make_constant(CONSTANT_INT, yylval.sval); }
    | CONST_FLOAT   { $$ = make_constant(CONSTANT_FLOAT, yylval.sval); }
    | ENUM_CONST    { $$ = make_constant(CONSTANT_ENUM, yylval.sval); }

string
    : STR_LITERAL   { $$ = yylval.sval; }
    | FUNC_NAME     { $$ = func_name(); }

postfix_expression
	: primary_expression                                    { $$ = $1; }
	| postfix_expression '[' expression ']'                 { $$ = make_expr(EXPR_SUBSCRIPT, $1, $3); }
	| postfix_expression '(' ')'                            { $$ = make_expr(EXPR_CALL, $1, 0); }
	| postfix_expression '(' argument_expression_list ')'   { $$ = make_expr(EXPR_CALL, $1, $3); }
	| postfix_expression '.' IDENTIFIER                     { $$ = make_member_access_expr(EXPR_MEMBER_DOT, $1, yylval.sval); }
	| postfix_expression ARROW IDENTIFIER                   { $$ = make_member_access_expr(EXPR_MEMBER_ARROW, $1, yylval.sval); }
	| postfix_expression INCREMENT                          { $$ = make_expr(EXPR_POST_INCR, $1, 0); }
	| postfix_expression DECREMENT                          { $$ = make_expr(EXPR_POST_DECR, $1, 0); }
	| '(' type_name ')' '{' initializer_list '}'            { $$ = make_init_expr($2, $5); }
	| '(' type_name ')' '{' initializer_list ',' '}'        { $$ = make_init_expr($2, $5); }
	;

argument_expression_list
	: assignment_expression                                 { $$ = $1; }
	| argument_expression_list ',' assignment_expression    { $$ = make_expr($1, $3); }
	;

unary_expression
	: postfix_expression                { $$ = $1; }
	| INCREMENT unary_expression        { $$ = make_expr(EXPR_PRE_INCR, $2, 0); }
	| DECREMENT unary_expression        { $$ = make_expr(EXPR_PRE_DECR, $2, 0); }
	| unary_operator cast_expression    { $$ = make_expr($1, $2, 0); }
	| SIZEOF unary_expression           { $$ = make_expr(EXPR_SIZEOF, $2, 0); }
	| SIZEOF '(' type_name ')'          { $$ = make_sizeof_expr($3); }
	;

unary_operator
	: '&'   { $$ = EXPR_ADDREF; }
	| '*'   { $$ = EXPR_DEREF; }
	| '+'   { $$ = EXPR_PLUS; }
	| '-'   { $$ = EXPR_MINUS; }
	| '~'   { $$ = EXPR_BITNOT; }
	| '!'   { $$ = EXPR_LOGNOT; }
	;

cast_expression
	: unary_expression                  { $$ = $1; }
	| '(' type_name ')' cast_expression { $$ = make_cast_expr($2, $4); }
	;

multiplicative_expression
	: cast_expression                               { $$ = $1; }
	| multiplicative_expression '*' cast_expression { $$ = make_expr(EXPR_MUL, $1, $3); }
	| multiplicative_expression '/' cast_expression { $$ = make_expr(EXPR_DIV, $1, $3); }
	| multiplicative_expression '%' cast_expression { $$ = make_expr(EXPR_MOD, $1, $3); }
	;

additive_expression
	: multiplicative_expression                         { $$ = $1; }
	| additive_expression '+' multiplicative_expression { $$ = make_expr(EXPR_ADD, $1, $3); }
	| additive_expression '-' multiplicative_expression { $$ = make_expr(EXPR_SUB, $1, $3); }
	;

shift_expression
	: additive_expression                           { $$ = $1; }
	| shift_expression LSHIFT additive_expression   { $$ = make_expr(EXPR_LSHIFT, $1, $3); }
	| shift_expression RSHIFT additive_expression   { $$ = make_expr(EXPR_RSHIFT, $1, $3); }
	;

relational_expression
	: shift_expression                              { $$ = $1; }
	| relational_expression '<' shift_expression    { $$ = make_expr(EXPR_LT, $1, $3); }
	| relational_expression '>' shift_expression    { $$ = make_expr(EXPR_GT, $1, $3); }
	| relational_expression LEQ shift_expression    { $$ = make_expr(EXPR_LEQ, $1, $3); }
	| relational_expression GEQ shift_expression    { $$ = make_expr(EXPR_GEQ, $1, $3); }
	;

equality_expression
	: relational_expression                                 { $$ = $1; }
	| equality_expression EQUAL relational_expression       { $$ = make_expr(EXPR_EQ, $1, $3); }
	| equality_expression NOT_EQUAL relational_expression   { $$ = make_expr(EXPR_NEQ, $1, $3); }
	;

and_expression
	: equality_expression                       { $$ = $1; }
	| and_expression '&' equality_expression    { $$ = make_expr(EXPR_BITAND, $1, $3); }
	;

exclusive_or_expression
	: and_expression                                { $$ = $1; }
	| exclusive_or_expression '^' and_expression    { $$ = make_expr(EXPR_BITXOR, $1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression                               { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression   { $$ = make_expr(EXPR_BITOR, $1, $3); }
	;

logical_and_expression
	: inclusive_or_expression                               { $$ = $1; }
	| logical_and_expression AND inclusive_or_expression    { $$ = make_expr(EXPR_LOGAND, $1, $3); }
	;

logical_or_expression
	: logical_and_expression                            { $$ = $1; }
	| logical_or_expression OR logical_and_expression   { $$ = make_expr(EXPR_LOGOR, $1, $3); }
	;

conditional_expression
	: logical_or_expression                                             { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression   { $$ = make_ternary_expr($1, $3, $5); }
	;

assignment_expression
	: conditional_expression                                        { $$ = $1; }
	| unary_expression assignment_operator assignment_expression    { $$ = make_expr($2, $1, $3); }
	;

assignment_operator
	: '='           { $$ = EXPR_ASSIGN; }
	| MUL_ASSIGN    { $$ = EXPR_MUL_ASSIGN; }
	| DIV_ASSIGN    { $$ = EXPR_DIV_ASSIGN; }
	| MOD_ASSIGN    { $$ = EXPR_MOD_ASSIGN; }
	| ADD_ASSIGN    { $$ = EXPR_ADD_ASSIGN; }
	| SUB_ASSIGN    { $$ = EXPR_SUB_ASSIGN; }
	| LSHIFT_ASSIGN { $$ = EXPR_LSHIFT_ASSIGN; }
	| RSHIFT_ASSIGN { $$ = EXPR_RSHIFT_ASSIGN; }
	| AND_ASSIGN    { $$ = EXPR_AND_ASSIGN; }
	| XOR_ASSIGN    { $$ = EXPR_XOR_ASSIGN; }
	| OR_ASSIGN     { $$ = EXPR_OR_ASSIGN; }
	;

expression
	: assignment_expression                 { $$ = $1; }
	| expression ',' assignment_expression  { $$ = make_expr(EXPR_COMMA, $1, $3); }
	;

constant_expression
	: conditional_expression                { $$ = $1; }
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	| function_specifier
	| function_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: enumeration_constant                          
	| enumeration_constant '=' constant_expression
	;

enumeration_constant
    : IDENTIFIER    { sym_define_enum(yylval.sval); }

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	;

function_specifier
	: INLINE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;


direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '[' '*' ']'
	| direct_abstract_declarator '[' '*' ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	| initializer_list ',' designation initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{'               { sym_push_scope() }
       block_item_list
       '}'              { sym_pop_scope() }
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;


%%

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}