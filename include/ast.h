/*
    Contains structs, enums, and functions that represent the AST of the grammar
*/

#pragma once

#include "helper_enums.h"
#include <stdbool.h>
#include <stdlib.h>

/*
    --------- Enums ---------
*/

typedef enum {
    CONSTANT_INT,
    CONSTANT_FLOAT,
    CONSTANT_PTR,
    CONSTANT_ENUM
} const_kind;

// Expression enum
typedef enum {
    /* primary expressions */
    EXPR_ID,                // identifier
    EXPR_CONST,             // integer, floating, enumeration constant
    EXPR_STR_LITERAL,       // string literal

    /* postfix expressions */
    EXPR_CALL,              // f(args)
    EXPR_SUBSCRIPT,         // e1[e2]
    EXPR_MEMBER_DOT,        // e . id
    EXPR_MEMBER_ARROW,      // e -> id
    EXPR_POST_INCR,         // e++
    EXPR_POST_DECR,         // e--
    EXPR_INIT_LIST,         // (type) {init_list}

    /* argument list */
    EXPR_ARG,

    /* unary expressions */
    EXPR_PRE_INCR,          // ++e
    EXPR_PRE_DECR,          // --e
    EXPR_ADDREF,            // &e
    EXPR_DEREF,             // *e
    EXPR_MINUS,             // -e
    EXPR_BITNOT,            // ~e
    EXPR_LOGNOT,            // !e
    EXPR_SIZEOF_EXPR,       // sizeof(e)
    EXPR_SIZEOF_TYPE,       // sizeof(type)
    EXPR_MALLOC,            // malloc(size)

    /* cast */
    EXPR_CAST,              // (type) e

    /* multiplicative */
    EXPR_MUL,               // e1 * e2
    EXPR_DIV,               // e1 / e2
    EXPR_MOD,               // e1 % e2

    /* additive */
    EXPR_ADD,               // e1 + e2
    EXPR_SUB,               // e1 - e2

    /* shift */
    EXPR_LSHIFT,            // e1 << e2
    EXPR_RSHIFT,            // e1 >> e2

    /* relational */
    EXPR_LT,                // e1 < e2
    EXPR_GT,                // e1 > e2
    EXPR_LEQ,               // e1 <= e2
    EXPR_GEQ,               // e1 >= e2

    /* equality */
    EXPR_EQ,                // e1 == e2
    EXPR_NEQ,               // e1 != e2

    /* bitwise */
    EXPR_BITAND,            // e1 & e2
    EXPR_BITXOR,            // e1 ^ e2
    EXPR_BITOR,             // e1 | e2

    /* logical */
    EXPR_LOGAND,            // e1 && e2
    EXPR_LOGOR,             // e1 || e2

    /* conditional */
    EXPR_CONDITIONAL,       // e1 ? e2 : e3

    /* assignment */
    EXPR_ASSIGN,            // e1 = e2
} expr_kind;

typedef enum {
    DECL_NORMAL,
    DECL_PARAM
} decl_kind;

typedef enum {
    SOU_STRUCT,
    SOU_UNION
} sou_kind;

typedef enum {
    TS_VOID,
    TS_CHAR,
    TS_SHORT,
    TS_INT,
    TS_LONG,
    TS_FLOAT,
    TS_DOUBLE,
    TS_SIGNED,
    TS_UNSIGNED,
    TS_BOOL,
    TS_SOU,
    TS_ENUM,
    TS_TYPEDEF
} type_spec_kind;

// Must be set to the largest enum in type_spec_kind or this compiler will break if a larger one is used
#define MAX_TS_KIND TS_TYPEDEF

typedef enum {
    DCTR_EMPTY,
    DCTR_ID,
    DCTR_ARRAY,
    DCTR_FUNC
} decltr_kind;

typedef enum {
    DSG_INDEX,
    DSG_MEMBER
} designation_kind;

typedef enum {
    INIT_EXPR,
    INIT_LIST
} initializer_kind;

typedef enum {
    BI_DECL,
    BI_STMT
} block_item_kind;

// Statement enum
typedef enum {
    STMT_EXPR,
    STMT_COMPOUND,
    STMT_IF,
    STMT_SWITCH,
    STMT_WHILE,
    STMT_DO,
    STMT_FOR,
    STMT_LABEL,
    STMT_CASE,
    STMT_DEFAULT,
    STMT_GOTO,
    STMT_CONTINUE,
    STMT_BREAK,
    STMT_RETURN,
    STMT_PRINT_STR,
    STMT_PRINT_EXPR,
    STMT_FREE
} stmt_kind;

typedef enum {
    FOR_DECL,
    FOR_EXPR
} for_init_kind;

typedef enum {
    EXT_DECL_FUNC,
    EXT_DECL_SIMPLE
} ext_decl_kind;

typedef enum {
    DS_STORAGE_CLASS,
    DS_TYPE_SPEC,
    DS_TYPE_QUAL,
    DS_FUNC_SPEC
} decl_spec_kind;


/*
    --------- Structures ---------
*/

struct constant;
struct expr;
struct type_name;
struct struct_decltr_list;
struct struct_decl_list;
struct sou_spec;
struct enumerator_list;
struct enum_spec;
struct type_spec;
struct type_spec_list;
struct type_qual_list;
struct decl_specs;
struct pointer;
struct param_list;
struct decltr;
struct init_list;
struct initializer;
struct init_decltr;
struct decl;
struct block_list;
struct stmt;
struct func_def;
struct ext_decl;
struct translation_unit;
struct decl_spec_list;

// Forward declaration for a struct defined in another header ("semantic_types.h")
struct sem_type;

// int, float, enum
typedef struct constant {
    const_kind kind;
    char *value;
    
    // Filled in later during semantic analysis
    bool val_filled;
    union {
        char c_val;
        short s_val;
        int i_val;
        long long l_val;
        unsigned char uc_val;
        unsigned short us_val;
        unsigned int ui_val;
        unsigned long long ul_val;
        float f_val;
        double d_val;
        uintptr_t p_val;
        u_int64_t bits; // to extract the exact bits during LLVM IR generation
    } val;
} constant;


typedef struct expr {
    expr_kind kind;

    // Both are used in binary expressions, and only left for unary
    struct expr *left;
    struct expr *right;

    // Leaves or additional
    union {
        char *id;                   // EXPR_IDENTIFIER (leaf) or EXPR_MEMBER (both dot and arrow)
        struct constant *const_val; // EXPR_CONSTANT (leaf)
        char *str_val;              // EXPR_STR_LITERAL (leaf)
        struct expr *conditional;   // EXPR_CONDITIONAL (ternary)
        struct {
            struct type_name *type;     // EXPR_CAST, EXPR_SIZEOF_TYPE, and EXPR_INIT_LIST
            struct init_list *init;     // EXPR_INIT_LIST
            struct sem_type *tn_type;   // Semantic type of the struct type_name
        };
    } extra;

    struct sem_type *type; // To be filled in during semantic analysis
} expr;


typedef struct type_name {
    struct decl_specs *specs; // Type specifiers and qualifiers
    struct decltr *suffix;
} type_name;


// Initially in reverse order during parsing
typedef struct struct_decltr_list {
    struct decltr *decltr;
    struct struct_decltr_list *next;
} struct_decltr_list;


// Initially in reverse order during parsing
typedef struct struct_decl_list {
    struct decl_specs *specs;
    struct struct_decltr_list *decltrs;

    struct struct_decl_list *next;
} struct_decl_list;


typedef struct sou_spec {
    sou_kind kind;
    char *name;
    struct struct_decl_list *decls;
} sou_spec;


// Initially in reverse order during parsing
typedef struct enumerator_list {
    char *name;
    struct expr *const_val;
    struct enumerator_list *next;
} enumerator_list;


typedef struct enum_spec {
    char *name;
    struct enumerator_list *enum_list;
} enum_spec;


typedef struct type_spec {
    type_spec_kind kind;
    union {
        struct sou_spec *sou;       // TS_SOU
        struct enum_spec *enums;    // TS_ENUM
        char *type_name;            // TS_TYPEDEF
    };
} type_spec;


typedef struct type_spec_list {
    struct type_spec *type;
    struct type_spec_list *next;
} type_spec_list;


typedef struct type_qual_list {
    type_qual qual;
    struct type_qual_list *next;
} type_qual_list;


typedef struct decl_specs {
    storage_class storage;
    func_spec func_spec;
    struct type_spec_list *type_specs;
    struct type_qual_list *type_quals;
} decl_specs;


typedef struct pointer {
    struct type_qual_list *type_quals;
    struct pointer *next;
} pointer;


// Initially in reverse order during parsing
typedef struct param_list {
    struct decl *param_decl;
    struct param_list *next;
} param_list;


// Initially in reverse order during parsing
typedef struct decltr {
    decltr_kind kind;
    struct pointer *ptr;
    union {
        char *id;

        struct {
            struct type_qual_list *quals;
            struct expr *size;
        } array;

        struct {
            struct param_list *params;
        } func;
    };

    struct decltr *next;
} decltr;


// Initially in reverse order during parsing
// Note that this feature does not work because I don't feel like implementing it
typedef struct init_list {
    struct initializer *init;

    struct init_list *next;
} init_list;


typedef struct initializer {
    initializer_kind kind;
    union {
        struct expr *assignment;
        struct init_list *list;
    };
} initializer;


// Initially in reverse order during parsing
typedef struct init_decltr {
    struct decltr *decltr;
    struct initializer *init;
    struct sem_type *type; // To be filled in during semantic analysis

    struct init_decltr *next;
} init_decltr;


typedef struct decl {
    decl_kind kind;
    struct decl_specs *specs;
    bool decltr_abstract;
    union {
        struct init_decltr *init_decltrs;
        struct {
            struct decltr *param_decltr;
            struct sem_type *param_type;
        };
    };
} decl;


// Initially in reverse order during parsing
typedef struct block_list {
    block_item_kind kind;
    union {
        struct decl *decl;
        struct stmt *stmt;
    };
    struct block_list *next;
} block_list;


// Important to note that while loops are being used as conditional statements
typedef struct stmt {
    stmt_kind kind;

    union {
        struct expr *expr_stmt; // STMT_EXPR

        struct {
            struct block_list *items;
        } compound_stmt;

        // STMT_IF, STMT_SWITCH, STMT_WHILE, STMT_DO
        struct {
            struct expr *cond;         // Thing to be compared in a switch statement
            struct stmt *body;
            struct stmt *else_body;    // If there is an else block
        } conditional_stmt;

        struct {
            // Note that the init can either be a declaration or assignment expression
            for_init_kind kind;
            union {
                struct decl *decl;
                struct expr *expr;
            } init;
            struct expr *cond;
            struct expr *update;
            struct stmt *body;
        } for_stmt;

        struct {
            char *label;
            struct stmt *next;
        } label_stmt;

        struct {
            struct expr *case_expr;
            struct stmt *result;
        } case_stmt;

        struct {
            struct stmt *result;
        } default_stmt;

        struct {
            char *label;
        } goto_stmt;

        struct {
            struct expr *result;
        } return_stmt;

        union {
            struct {
                struct expr *item;
                constant *size;
            };

            const char *str_val;
        } print_stmt;

        struct {
            struct expr *item;
        } free_stmt;
    };
} stmt;


typedef struct func_def {
    struct decl_specs *specs;
    struct decltr *decltr;
    struct stmt *body;
    struct sem_type *type;
} func_def;


typedef struct ext_decl {
    ext_decl_kind kind;
    union {
        struct func_def *func;
        struct decl *decl;
    };
} ext_decl;


// Initially in reverse order during parsing
typedef struct translation_unit {
    struct ext_decl *action;
    struct translation_unit *next;
} translation_unit;


// Helper struct that gets converted into a decl_specs when parsing
// Represents the "declaration_specifiers" non-terminal
// Not used in the AST
typedef struct decl_spec_list {
    decl_spec_kind kind;
    union {
        storage_class storage;
        struct type_spec *type_spec;
        type_qual type_qual;
        func_spec func_spec;
    };

    struct decl_spec_list *next;
} decl_spec_list;

/*
    --------- Struct Factories ---------
*/

// Constant
constant *make_constant(const_kind kind, char *value);

// Expressions
expr *make_expr(expr_kind kind, expr *left, expr *right);
expr *make_id_expr(char *id);
expr *make_const_expr(constant *const_val);
expr *make_string_expr(char *str);
expr *make_member_access_expr(expr_kind kind, expr *item, char *id);
expr *make_init_expr(type_name *type, init_list *init);
expr *make_sizeof_expr(type_name *type);
expr *make_cast_expr(type_name *type, expr* val);
expr *make_ternary_expr(expr *conditional, expr *first, expr *second);

// Declarations
decl_specs *make_decl_specs(decl_spec_list *specs);

decl *make_normal_decl(decl_specs *specs, init_decltr *init);
decl *make_param_decl(decl_specs *specs, decltr *param_decltr, bool decltr_abstract);

sou_spec *make_sou_spec(sou_kind kind, char *name, struct_decl_list *decls);

struct_decl_list *make_struct_decl_list(decl_specs *specs, struct_decltr_list *decltrs);
void add_struct_decl(struct_decl_list *prev, struct_decl_list *curr);

struct_decltr_list *make_struct_decltr_list(decltr *decltr);
void add_struct_decltr(struct_decltr_list *prev, struct_decltr_list *curr);

init_decltr *make_init_decltr(decltr *decltr, initializer *init);
void add_init_decltr(init_decltr *prev, init_decltr *curr);

enum_spec *make_enum_spec(char *name, enumerator_list *enums);

enumerator_list *make_enum_list(char *name, expr *val);
void add_enumerator(enumerator_list *prev, enumerator_list *curr);

pointer *make_pointer(type_qual_list *quals, pointer *curr);

decltr *make_empty_decltr(pointer *ptr); // For abstract
decltr *make_id_decltr(char *id);
decltr *make_decltr_array_suffix(decltr *prev, type_qual_list *quals, expr *size);
decltr *make_decltr_proto_suffix(decltr *prev, param_list *params);
void add_pointer(pointer *ptr, decltr *decltr);
void extend_pointer(pointer *curr, pointer *extend);

param_list *make_param_list(param_list *prev, decl *param_decl);

initializer *make_expr_init(expr *assignment);
initializer *make_list_init(init_list *list);

init_list *make_init_list(init_list *prev, initializer *init);

type_name *make_type_name(decl_specs *specs, decltr *suffix);

decl_spec_list *add_storage_class(decl_spec_list *next, storage_class storage);
decl_spec_list *add_type_spec(decl_spec_list *next, type_spec *type_spec);
decl_spec_list *add_type_qual(decl_spec_list *next, type_qual type_qual);
decl_spec_list *add_func_spec(decl_spec_list *next, func_spec func_spec);

type_qual_list *make_type_qual_list(type_qual_list *prev, type_qual qual);

type_spec *make_basic_type_spec(type_spec_kind kind);
type_spec *make_sou_type_spec(sou_spec *sou);
type_spec *make_enum_type_spec(enum_spec *enums);
type_spec *make_typedef_type_spec(char *name);

// Statements
stmt *make_expr_stmt(expr *expr);
stmt *make_compound_stmt(block_list *block);
stmt *make_conditional_stmt(stmt_kind kind, expr *cond, stmt *body, stmt *else_body);
stmt *make_for_decl_stmt(decl *init, stmt *cond, expr *update, stmt *body);
stmt *make_for_expr_stmt(stmt *init, stmt *cond, expr *update, stmt *body);
stmt *make_labeled_stmt(char *label, stmt *next);
stmt *make_case_stmt(expr *case_expr, stmt *result);
stmt *make_default_stmt(stmt *result);
stmt *make_goto_stmt(char *label);
stmt *make_return_stmt(expr *result);
stmt *make_str_print_stmt(const char *str_val);
stmt *make_expr_print_stmt(expr *item, constant *size);
stmt *make_free_stmt(expr *item);
stmt *make_empty_stmt(stmt_kind kind); // For continue, break, and empty return

block_list *make_stmt_block_item(stmt *stmt);
block_list *make_decl_block_item(decl *decl);
void add_block_item(block_list *prev, block_list *curr);

// Function definition
func_def *make_func_def(decl_specs *specs, decltr *decltr, stmt *body);

// External declaration
ext_decl *make_func_ext_decl(func_def *func);
ext_decl *make_decl_ext_decl(decl *decl);

// Translation unit
translation_unit *make_trans_unit(translation_unit *prev, ext_decl *curr);

/*
    --------- Freeing Memory ---------
*/

void free_expr(expr *e);
void free_type_name(type_name *tn);