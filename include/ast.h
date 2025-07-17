/*
    Contains structs, enums, and functions that represent the AST of the grammar
*/

#pragma once

/*
    --------- Enums ---------
*/

typedef enum {
    CONSTANT_INT,
    CONSTANT_FLOAT,
    CONSANT_ENUM
} const_kind;

typedef enum {
    STRING_LIT,
    FUNC_NAME
} string_kind;

typedef enum {
    EXT_DECL_FUNC,
    EXT_DECL_SIMPLE
} ext_decl_kind;

typedef enum {
    DD_ARRAY,
    DD_FUNC_PROTO,
    DD_FUNC_KR
} direct_decl_suffix_kind;

typedef enum {
    DS_TYPE_SPEC,
    DS_TYPE_QUAL,
    DS_FUNC_SPEC,
    DS_ALIGN_SPEC
} decl_spec_kind;

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
    TS_COMPLEX,
    TS_IMAGINARY,
    TS_SU_SPEC,
    TS_ENUM_SPEC,
    TS_TYPEDEF
} type_spec_kind;

typedef enum {
    DCTR_NORMAL,
    DCTR_BIT_FIELD
} decltr_kind;

// Expression enum
typedef enum {
    /* primary expressions */
    EXPR_IDENTIFIER,        // identifier
    EXPR_CONSTANT,          // integer, floating, enumeration constant
    EXPR_STRING_LITERAL,    // string literal
    EXPR_PAREN,             // parenthesized sub‑expression

    /* postfix expressions */
    EXPR_POST_CALL,         // f(args)
    EXPR_POST_SUBSCRIPT,    // e1[e2]
    EXPR_POST_MEMBER_DOT,   // e . id
    EXPR_POST_MEMBER_ARROW, // e -> id
    EXPR_POST_INC,          // e++
    EXPR_POST_DEC,          // e--
    EXPR_POST_INIT_LIST,    // (type) {init_list}

    /* unary expressions */
    EXPR_UNARY_PRE_INC,     // ++e
    EXPR_UNARY_PRE_DEC,     // --e
    EXPR_UNARY_ADDREF,      // &e
    EXPR_UNARY_DEREF,       // *e
    EXPR_UNARY_PLUS,        // +e
    EXPR_UNARY_MINUS,       // -e
    EXPR_UNARY_BITNOT,      // ~e
    EXPR_UNARY_LOGNOT,      // !e
    EXPR_UNARY_SIZEOF,      // sizeof e or sizeof(type)
    EXPR_UNARY_ALIGNOF,     // _Alignof e

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
    EXPR_NE,                // e1 != e2

    /* bitwise */
    EXPR_BITAND,            // e1 & e2
    EXPR_BITXOR,            // e1 ^ e2
    EXPR_BITOR,             // e1 | e2

    /* logical */
    EXPR_LOGAND,            // e1 && e2
    EXPR_LOGOR,             // e1 || e2

    /* conditional */
    EXPR_CONDITIONAL,       // e1 ? e2 : e3

    /* assignment (all forms) */
    EXPR_ASSIGN,            // e1 = e2
    EXPR_ASSIGN_MUL,        // e1 *= e2
    EXPR_ASSIGN_DIV,        // e1 /= e2
    EXPR_ASSIGN_MOD,        // e1 %= e2
    EXPR_ASSIGN_ADD,        // e1 += e2
    EXPR_ASSIGN_SUB,        // e1 -= e2
    EXPR_ASSIGN_LSHIFT,     // e1 <<= e2
    EXPR_ASSIGN_RSHIFT,     // e1 >>= e2
    EXPR_ASSIGN_AND,        // e1 &= e2
    EXPR_ASSIGN_XOR,        // e1 ^= e2
    EXPR_ASSIGN_OR,         // e1 |= e2

    /* comma expression */
    EXPR_COMMA,             // e1 , e2

    /* argument list */
    EXPR_ARG
} expr_kind;

// Declaration enum
typedef enum {
    DECL_SIMPLE,
    DECL_PARAM,
    DECL_STATIC_ASSERT
} decl_kind;

// Statement enum
typedef enum {
    STMT_LABELED,
    STMT_COMPOUND,
    STMT_EXPR,
    STMT_SELECTION,
    STMT_ITERATION,
    STMT_JUMP
} stmt_kind;

/* --- Helper enums --- */

typedef enum {
    SC_TYPEDEF,
    SC_EXTERN,
    SC_STATIC,
    SC_THREAD_LOCAL,
    SC_AUTO,
    SC_REGISTER
} storage_class;

typedef enum {
    FS_INLINE // Only inline in C99
} func_spec;

typedef enum {
    TQ_CONST,
    TQ_RESTRICT,
    TQ_VOLATILE,
    TQ_ATOMIC
} type_qual;

typedef enum {
    PF_NONE,
    PF_ID_LIST,
    PF_TYPE_LIST
} param_form;


/*
    --------- Structures ---------
*/

typedef struct {
    void *val;
    node_list *next;
} node_list;

// Constant (int, float, enum)
typedef struct {
    const_kind kind;
    char *value;
} constant;


typedef struct {
    expr_kind kind;

    // Both are used in binary expressions, and only left for unary
    expr *left;
    expr *right;

    // Leaves or additional data
    union {
        char *identifier;       // EXPR_IDENTIFIER (leaf)
        constant *const_val;    // EXPR_CONSTANT (leaf)
        char *string_val;     // EXPR_STRING (leaf)
        expr *conditional;      // EXPR_CONDITIONAL (ternary)
        type_name *type;        // EXPR_CAST
    } extra;
} expr;


typedef struct {
    decl_spec *specs; // Type specifiers and qualifiers
    decltr *suffix;
} type_name;


typedef struct {
    char *name;
    bool has_val;
    int val;
    enum_list *next;
} enum_list;


typedef struct {
    char *name;
    enum_list *enums;
} enum_spec;


typedef struct {
    decl_spec *specs;
    decltr_list *decltrs;
    struct_decl_list *next;
} struct_decl_list;


typedef struct {
    sou_kind kind;
    char *name;
    struct_decl_list *decls;
} struct_or_union;


typedef struct {
    type_spec_kind kind;
    union {
        struct_or_union *sou;   // TS_SU_SPEC
        enum_spec *enum_type;   // TS_ENUM_SPEC
        char *type;             // TS_TYPEDEF
    };
} type_spec;


typedef struct {
    decl_spec_kind kind;
    decl_spec *next;

    union {
        type_spec *ts; // This one is a struct; other two are enums
        type_qual *tq;
        func_spec *fs;
    } info;
} decl_spec;


typedef struct {
    type_qual e;
    pointer *next;
} pointer;


typedef struct {
    decl *curr;
    param_list *next;
} param_list;


typedef struct {
    char *id;
    id_list *next;
} id_list;


typedef struct {
    direct_decl_suffix_kind kind;
    direct_decl_suffix *next;
    union {
        struct {
            bool is_static;
            bool has_star;
            node_list *type_qualifiers;
            expr *size;
        } arr_info; // For arrays

        struct {
            param_list *params;
            bool has_ellipsis;
        } proto_info; // For prototype

        id_list *kr_info;
    } info;
} direct_decl_suffix;


typedef struct {
    pointer *ptr;
    union {
        char *id; // NULL if abstract
        decltr_core *nested;
        direct_decl_suffix *suffixes;
    };
} decltr_core;


typedef struct {
    decltr_kind kind;
    decltr_core *core;

    // Represents either the bits in a bit field or the initialization of the variable
    expr *init; // NULL if no '= [expr]' and not bit field
} decltr;


typedef struct {
    decltr *curr;
    decltr_list *next;
} decltr_list;


typedef struct {
    decl_kind kind;

    union {
        struct {
            storage_class sc;
            decl_spec *specs;
            decltr_list *decltrs;
        } normal;

        struct {
            decl_spec *specs;
            decltr *decltr;
        } param;
    };
} decl;


typedef struct {
    stmt_kind kind;

    union {

    };
} stmt;


typedef struct {

    translation_unit *next;
} translation_unit;


/*
    --------- Struct Factories ---------
*/

// Constant
static inline constant *make_constant(const_kind kind, char *value);

// Translation unit
//static inline translation_unit *make_trans_unit(translation_unit *next, ext_decl *curr);

// Expression
static inline expr *make_expr(expr_kind kind, expr *left, expr *right);
static inline expr *make_id_expr(char *id);
static inline expr *make_const_expr(constant *const_val);
static inline expr *make_member_access_expr(expr_kind kind, expr *item, char *id);
static inline expr *make_ternary_expr(expr *conditional, expr *first, expr *second);

// External declaration
//static inline decl *make_func_ext_decl(func_def *fd);
static inline decl *make_simple_ext_decl(decl *declaration);