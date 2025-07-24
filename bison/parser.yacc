%{
#include <stdio.h>
#include "token_types.h"
#include "symbol_table.h"
#include "parser_helpers.h"
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
    decl_list *decl_list;
    decl_spec_list *decl_spec_list;
    init_list *init_list;
    initializer *initializer;
    init_decltr *init_decltr;
    type_spec *type_spec;
    sou_spec *sou_spec;
    struct_decl_list *struct_decl_list;
    struct_decltr_list *struct_decltr_list;
    enum_spec *enum_spec;
    enumerator_list *enumerator_list;
    decltr *decltr;
    pointer *pointer;
    type_qual_list *type_qual_list;
    param_list *param_list;
    id_list *id_list;
    type_name *type_name;
    designator *designator;
    stmt *stmt;
    block_list *block_list;
    translation_unit *translation_unit;
    ext_decl *ext_decl;
    func_def *func_def;
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
%type <constant> constant
%type <sval> string

// Operators
%type <int_val> unary_operator assignment_operator

// Declarations
%type <decl> declaration parameter_declaration
%type <decl_list> declaration_list
%type <decl_spec_list> declaration_specifiers specifier_qualifier_list
%type <initializer> initializer
%type <init_list> initializer_list
%type <init_decltr> init_declarator init_declarator_list
%type <int_val> storage_class_specifier type_qualifier function_specifier
%type <type_spec> type_specifier
%type <sou_spec> struct_or_union_specifier
%type <int_val> struct_or_union
%type <struct_decl_list> struct_declaration struct_declaration_list
%type <struct_decltr_list> struct_declarator struct_declarator_list
%type <enumerator_list> enumerator enumerator_list
%type <enum_spec> enum_specifier
%type <sval> enumeration_constant
%type <decltr> declarator direct_declarator abstract_declarator direct_abstract_declarator
%type <pointer> pointer
%type <type_qual_list> type_qualifier_list
%type <param_list> parameter_type_list parameter_list
%type <id_list> identifier_list
%type <type_name> type_name
%type <designator> designation designator designator_list
%type <stmt> statement expression_statement labeled_statement compound_statement
%type <stmt> selection_statement iteration_statement jump_statement
%type <block_list> block_item block_item_list
%type <func_def> function_definition
%type <ext_decl> external_declaration
%type <translation_unit> translation_unit

%%

primary_expression
	: IDENTIFIER            { $$ = make_id_expr($1); free($1); }
	| constant              { $$ = make_const_expr($1); }
	| string                { $$ = make_str_expr($1); }
	| '(' expression ')'    { $$ = $1; }
	;

constant
    : CONST_INT     { $$ = make_constant(CONSTANT_INT, $1); free($1); }
    | CONST_FLOAT   { $$ = make_constant(CONSTANT_FLOAT, $1); free($1); }
    | ENUM_CONST    { $$ = make_constant(CONSTANT_ENUM, $1); free($1); }

string
    : STR_LITERAL   { $$ = $1; free($1); }
    | FUNC_NAME     { $$ = func_name(); }

postfix_expression
	: primary_expression                                    { $$ = $1; }
	| postfix_expression '[' expression ']'                 { $$ = make_expr(EXPR_SUBSCRIPT, $1, $3); }
	| postfix_expression '(' ')'                            { $$ = make_expr(EXPR_CALL, $1, 0); }
	| postfix_expression '(' argument_expression_list ')'   { $$ = make_expr(EXPR_CALL, $1, $3); }
	| postfix_expression '.' IDENTIFIER                     { $$ = make_member_access_expr(EXPR_MEMBER_DOT, $1, $3); free($3); }
	| postfix_expression ARROW IDENTIFIER                   { $$ = make_member_access_expr(EXPR_MEMBER_ARROW, $1, $3); free($3); }
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
	: declaration_specifiers ';'                        { $$ = make_normal_decl(make_decl_specs($1), 0); }
	| declaration_specifiers init_declarator_list ';'   { $$ = make_normal_decl(make_decl_specs($1), $2); }
	;

declaration_specifiers
	: storage_class_specifier                           { $$ = add_storage_class(0, $1); }
	| storage_class_specifier declaration_specifiers    { $$ = add_storage_class($2, $1); }
	| type_specifier                                    { $$ = add_type_spec(0, $1); }
	| type_specifier declaration_specifiers             { $$ = add_type_spec($2, $1); }
	| type_qualifier                                    { $$ = add_type_qual(0, $1); }
	| type_qualifier declaration_specifiers             { $$ = add_type_qual($2, $1); }
	| function_specifier                                { $$ = add_func_spec(0, $1); }
	| function_specifier declaration_specifiers         { $$ = add_func_spec($2, $1); }
	;

init_declarator_list
	: init_declarator                           { $$ = $1; }
	| init_declarator_list ',' init_declarator  { add_init_decltr($1, $3); $$ = $3; }
	;

init_declarator
	: declarator                    { $$ = make_init_decltr($1, 0); }
	| declarator '=' initializer    { $$ = make_init_decltr($1, $3); }
	;

storage_class_specifier
	: TYPEDEF   { $$ = SC_TYPEDEF; }
	| EXTERN    { $$ = SC_EXTERN; }
	| STATIC    { $$ = SC_STATIC; }
	| AUTO      { $$ = SC_AUTO; }
	| REGISTER  { $$ = SC_REGISTER; }
	;

type_specifier
	: VOID                      { $$ = make_type_spec(TS_VOID); }
	| CHAR                      { $$ = make_type_spec(TS_CHAR); }
	| SHORT                     { $$ = make_type_spec(TS_SHORT); }
	| INT                       { $$ = make_type_spec(TS_INT); }
	| LONG                      { $$ = make_type_spec(TS_LONG); }
	| FLOAT                     { $$ = make_type_spec(TS_FLOAT); }
	| DOUBLE                    { $$ = make_type_spec(TS_DOUBLE); }
	| SIGNED                    { $$ = make_type_spec(TS_SIGNED); }
	| UNSIGNED                  { $$ = make_type_spec(TS_UNSIGNED); }
	| BOOL                      { $$ = make_type_spec(TS_BOOL); }
	| COMPLEX                   { $$ = make_type_spec(TS_COMPLEX); }
	| IMAGINARY                 { $$ = make_type_spec(TS_IMAGINARY); }
	| struct_or_union_specifier { $$ = make_sou_type_spec($1); }
	| enum_specifier            { $$ = make_enum_type_spec($1); }
	| TYPEDEF_NAME              { $$ = make_typedef_type_spec($1); }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'    { $$ = make_sou_spec($1, $2, $4); }
	| struct_or_union '{' struct_declaration_list '}'               { $$ = make_sou_spec($1, 0, $3); }
	| struct_or_union IDENTIFIER                                    { $$ = make_sou_spec($1, $2, 0); }
	;

struct_or_union
	: STRUCT    { $$ = SOU_STRUCT; }
	| UNION     { $$ = SOU_UNION; }
	;

struct_declaration_list
	: struct_declaration                            { $$ = $1; }
	| struct_declaration_list struct_declaration    { add_struct_decl($1, $2); $$ = $2; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'   { $$ = make_struct_decl_list($1, $2); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list   { $$ = add_type_spec($2, $1); }
	| type_specifier                            { $$ = add_type_spec(0, $1); }
	| type_qualifier specifier_qualifier_list   { $$ = add_type_qual($2, $1); }
	| type_qualifier                            { $$ = add_type_qual(0, $1); }
	;

struct_declarator_list
	: struct_declarator                             { $$ = $1; }
	| struct_declarator_list ',' struct_declarator  { add_struct_decltr($1, $3); $$ = $3; }
	;

struct_declarator
	: declarator                            { $$ = make_struct_decltr_list($1, 0); }
	| ':' constant_expression               { $$ = make_struct_decltr_list(0, $2); }
	| declarator ':' constant_expression    { $$ = make_struct_decltr_list($1, $3); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'                  { $$ = make_enum_spec(0, $3); }
	| ENUM IDENTIFIER '{' enumerator_list '}'       { $$ = make_enum_spec($2, $4); }
	| ENUM '{' enumerator_list ',' '}'              { $$ = make_enum_spec(0, $3); }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'   { $$ = make_enum_spec($2, $4); }
	| ENUM IDENTIFIER                               { $$ = make_enum_spec($2, 0); }
	;

enumerator_list
	: enumerator                        { $$ = $1; }
	| enumerator_list ',' enumerator    { add_enumerator($1, $3); $$ = $3; }
	;

enumerator
	: enumeration_constant                          { $$ = make_enum_list($1, 0); free($1); }
	| enumeration_constant '=' constant_expression  { $$ = make_enum_list($1, $3); free($1); }
	;

enumeration_constant
    : IDENTIFIER    { sym_define_enum($1); $$ = $1; } // Make sure to free $$ after use

type_qualifier
	: CONST     { $$ = TQ_CONST; }
	| RESTRICT  { $$ = TQ_RESTRICT; }
	| VOLATILE  { $$ = TQ_VOLATILE; }
	;

function_specifier
	: INLINE    { $$ = FS_INLINE; }
	;

declarator
	: pointer direct_declarator { add_pointer($1, $2); $$ = $2; }
	| direct_declarator         { $$ = $1; }
	;


direct_declarator
	: IDENTIFIER                                                                    { $$ = make_id_decltr($1); free($1); }     
	| '(' declarator ')'                                                            { $$ = make_nested_decltr($2); }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'           { $$ = make_decltr_array_suffix($1, $3, $4, 0, 0); }
	| direct_declarator '[' type_qualifier_list ']'                                 { $$ = make_decltr_array_suffix($1, $3, 0, 0, 0); }
	| direct_declarator '[' assignment_expression ']'                               { $$ = make_decltr_array_suffix($1, $3, $4, 0, 0); }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'    { $$ = make_decltr_array_suffix($1, $4, $5, 1, 0); }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'    { $$ = make_decltr_array_suffix($1, $3, $5, 1, 0); }
	| direct_declarator '[' type_qualifier_list '*' ']'                             { $$ = make_decltr_array_suffix($1, $3, 0, 0, 0); }
	| direct_declarator '[' '*' ']'                                                 { $$ = make_decltr_array_suffix($1, 0, 0, 0, 1); }
	| direct_declarator '[' ']'                                                     { $$ = make_decltr_array_suffix($1, 0, 0, 0, 0); }
	| direct_declarator '(' parameter_type_list ')'                                 { $$ = make_decltr_proto_suffix($1, $3); }
	| direct_declarator '(' identifier_list ')'                                     { $$ = make_decltr_kr_suffix($1, $3); }
	| direct_declarator '(' ')'                                                     { $$ = make_decltr_proto_suffix($1, 0); }
	;

pointer
	: '*'                               { $$ = make_pointer(0, 0); }
	| '*' type_qualifier_list           { $$ = make_pointer($2, 0); }
	| '*' pointer                       { $$ = make_pointer(0, $2); }
	| '*' type_qualifier_list pointer   { $$ = make_pointer($2, $3); }
	;

type_qualifier_list
	: type_qualifier                        { $$ = make_type_qual_list(0, $1); }
	| type_qualifier_list type_qualifier    { $$ = make_type_qual_list($1, $2); }
	;


parameter_type_list
	: parameter_list                { set_param_ellipsis(0); $$ = $1; }
	| parameter_list ',' ELLIPSIS   { set_param_ellipsis(1); $$ = $1; }
	;

parameter_list
	: parameter_declaration                     { $$ = make_param_list(0, $1); }
	| parameter_list ',' parameter_declaration  { $$ = make_param_list($1, $3); }
	;

parameter_declaration
	: declaration_specifiers declarator             { $$ = make_param_decl(make_decl_specs($1), $2); }
	| declaration_specifiers abstract_declarator    { $$ = make_param_decl(make_decl_specs($1), $2); }
	| declaration_specifiers                        { $$ = make_param_decl(make_decl_specs($1), 0); }
	;

identifier_list
	: IDENTIFIER                        { $$ = make_id_list(0, $1); }
	| identifier_list ',' IDENTIFIER    { $$ = make_id_list($1, $3); }
	;

type_name
	: specifier_qualifier_list                      { $$ = make_type_name(make_decl_specs($1), 0); }
	| specifier_qualifier_list abstract_declarator  { $$ = make_type_name(make_decl_specs($1), $2); }
	;

abstract_declarator
	: pointer                               { $$ = make_empty_decltr(1); }
	| direct_abstract_declarator            { $$ = $1; }
	| pointer direct_abstract_declarator    { add_pointer($1, $2); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'                               { $$ = make_nested_decltr($2); }
	| '[' ']'                                                   { $$ = make_decltr_array_suffix(0, 0, 0, 0, 0); }
	| '[' assignment_expression ']'                             { $$ = make_decltr_array_suffix(0, 0, $2, 0, 0); }
	| direct_abstract_declarator '[' ']'                        { $$ = make_decltr_array_suffix($1, 0, 0, 0, 0); }
	| direct_abstract_declarator '[' assignment_expression ']'  { $$ = make_decltr_array_suffix($1, 0, $3, 0, 0); }
	| '[' '*' ']'                                               { $$ = make_decltr_array_suffix(0, 0, 0, 0, 1); }
	| direct_abstract_declarator '[' '*' ']'                    { $$ = make_decltr_array_suffix($1, 0, 0, 0, 1); }
	| '(' ')'                                                   { $$ = make_decltr_proto_suffix(0, 0); }
	| '(' parameter_type_list ')'                               { $$ = make_decltr_proto_suffix(0, $2); }
	| direct_abstract_declarator '(' ')'                        { $$ = make_decltr_proto_suffix($1, 0); }
	| direct_abstract_declarator '(' parameter_type_list ')'    { $$ = make_decltr_proto_suffix($1, $3); }
	;

initializer
	: assignment_expression         { $$ = make_expr_init($1); }
	| '{' initializer_list '}'      { $$ = make_list_init($2); }
	| '{' initializer_list ',' '}'  { $$ = make_list_init($2); }
	;

initializer_list
	: initializer                                   { $$ = make_init_list(0, 0, $1); }
	| designation initializer                       { $$ = make_init_list(0, $1, $2); }
	| initializer_list ',' initializer              { $$ = make_init_list($1, 0, $3); }
	| initializer_list ',' designation initializer  { $$ = make_init_list($1, $3, $4); }
	;

designation
	: designator_list '='   { $$ = $1; }
	;

designator_list
	: designator                    { $$ = $1; }
	| designator_list designator    { add_designator($1, $2); $$ = $2; }
	;

designator
	: '[' constant_expression ']'   { $$ = make_arr_designator($2); }
	| '.' IDENTIFIER                { $$ = make_member_designator($2); free($2); }
	;

statement
	: labeled_statement     { $$ = $1; }
	| compound_statement    { $$ = $1; }
	| expression_statement  { $$ = $1; }
	| selection_statement   { $$ = $1; }
	| iteration_statement   { $$ = $1; }
	| jump_statement        { $$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement                  { $$ = make_labeled_stmt($1, $3); }
	| CASE constant_expression ':' statement    { $$ = make_case_stmt($2, $4); }
	| DEFAULT ':' statement                     { $$ = make_default_stmt($3); }
	;

compound_statement
	: '{' '}'           { $$ = make_compound_stmt(0); }
	| '{'               { sym_push_scope(); }
       block_item_list
       '}'              { sym_pop_scope(); $$ = make_compound_stmt($2); }
	;

block_item_list
	: block_item                    { $$ = $1; }
	| block_item_list block_item    { add_block_item($1, $2); $$ = $2; }
	;

block_item
	: declaration   { $$ = make_decl_block_item($1); }
	| statement     { $$ = make_stmt_block_item($1); }
	;

expression_statement
	: ';'               { $$ = make_expr_stmt(0); }
	| expression ';'    { $$ = make_expr_stmt($1); }
	;

selection_statement
	: IF '(' expression ')' statement                   { $$ = make_conditional_stmt(STMT_IF, $3, $5, 0); }
	| IF '(' expression ')' statement ELSE statement    { $$ = make_conditional_stmt(STMT_IF, $3, $5, $7); }
	| SWITCH '(' expression ')' statement               { $$ = make_conditional_stmt(STMT_SWITCH, $3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement                                            { $$ = make_conditional_stmt(STMT_WHILE, $3, $5, 0); }
	| DO statement WHILE '(' expression ')' ';'                                     { $$ = make_conditional_stmt(STMT_DO, $5, $2, 0); }
	| FOR '(' expression_statement expression_statement ')' statement               { $$ = make_for_expr_stmt($3, $4, 0, $6); }
	| FOR '(' expression_statement expression_statement expression ')' statement    { $$ = make_for_expr_stmt($3, $4, $5, $7); }
	| FOR '(' declaration expression_statement ')' statement                        { $$ = make_for_decl_stmt($3, $4, 0, $6); }
	| FOR '(' declaration expression_statement expression ')' statement             { $$ = make_for_decl_stmt($3, $4, $5, $7); }
	;

jump_statement
	: GOTO IDENTIFIER ';'   { $$ = make_goto_stmt($2); }
	| CONTINUE ';'          { $$ = make_empty_stmt(STMT_CONTINUE); }
	| BREAK ';'             { $$ = make_empty_stmt(STMT_BREAK); }
	| RETURN ';'            { $$ = make_empty_stmt(STMT_RETURN); }
	| RETURN expression ';' { $$ = make_return_stmt($2); }
	;

translation_unit
	: external_declaration                  { $$ = make_trans_unit(0, $1); }
	| translation_unit external_declaration { $$ = make_trans_unit($1, $2); }
	;

external_declaration
	: function_definition   { $$ = make_func_ext_decl($1); }
	| declaration           { $$ = make_decl_ext_decl($1); }
	;

function_definition
	: declaration_specifiers declarator declaration_list    { set_func_name(get_decltr_id($2)); }
      compound_statement                                    
    {
        func_ended();
        $$ = make_func_def(FD_KR, make_decl_specs($1), $2, $3, $4);
    }
	| declaration_specifiers declarator                     { set_func_name(get_decltr_id($2)); }
      compound_statement                                    
    {
        func_ended();
        $$ = make_func_def(FD_NORMAL, make_decl_specs($1), $2, 0, $3);
    }
	;

declaration_list
	: declaration                   { $$ = make_decl_list(0, $1); }
	| declaration_list declaration  { $$ = make_decl_list($1, $2); }
	;


%%

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}