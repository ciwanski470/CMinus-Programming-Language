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

// Expression enum
typedef enum {
    /* primary expressions */
    EXPR_IDENTIFIER,        // identifier
    EXPR_CONSTANT,          // integer, floating, enumeration constant
    EXPR_STRING_LITERAL,    // string literal
    EXPR_PAREN,             // parenthesized sub‑expression

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
    EXPR_PLUS,              // +e
    EXPR_MINUS,             // -e
    EXPR_BITNOT,            // ~e
    EXPR_LOGNOT,            // !e
    EXPR_SIZEOF,            // sizeof e or sizeof(type)

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

    /* assignment (all forms) */
    EXPR_ASSIGN,            // e1 = e2
    EXPR_MUL_ASSIGN,        // e1 *= e2
    EXPR_DIV_ASSIGN,        // e1 /= e2
    EXPR_MOD_ASSIGN,        // e1 %= e2
    EXPR_ADD_ASSIGN,        // e1 += e2
    EXPR_SUB_ASSIGN,        // e1 -= e2
    EXPR_LSHIFT_ASSIGN,     // e1 <<= e2
    EXPR_RSHIFT_ASSIGN,     // e1 >>= e2
    EXPR_AND_ASSIGN,        // e1 &= e2
    EXPR_XOR_ASSIGN,        // e1 ^= e2
    EXPR_OR_ASSIGN,         // e1 |= e2

    /* comma expression */
    EXPR_COMMA              // e1 , e2
} expr_kind;

typedef enum {
    DD_ID,
    DD_NESTED,
    DD_ARRAY,
    DD_FUNC_PROTO,
    DD_FUNC_KR
} decltr_core_kind;

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

typedef enum {
    DSG_CONST,
    DSG_ID
} designator_kind;

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
    STMT_RETURN
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
    FD_NORMAL,
    FD_KR
} func_def_kind;

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

typedef enum {
    DS_STORAGE_CLASS,
    DS_TYPE_SPEC,
    DS_TYPE_QUAL,
    DS_FUNC_SPEC
} decl_spec_kind;


/*
    --------- Structures ---------
*/

// int, float, enum
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
        char *string_val;       // EXPR_STRING (leaf)
        expr *conditional;      // EXPR_CONDITIONAL (ternary)
        type_name *type;        // EXPR_CAST and EXPR_SIZEOF
        init_list *init;        // EXPR_INIT_LIST
    } extra;
} expr;


typedef struct {
    decl_specs *specs; // Type specifiers and qualifiers
    decltr *suffix;
} type_name;


typedef struct {
    sou_kind kind;
    char *name;
    decl_list *decls;
} sou_decl;


typedef struct {
    enumerator_list *prev;
    char *enum_const;
    expr *const_val;
} enumerator_list;


typedef struct {
    char *name;
    enumerator_list *enums;
} enum_decl;


typedef struct {
    type_spec_kind kind;
    union {
        sou_decl *sou;      // TS_SOU
        enum_decl *enums;   // TS_ENUM
        char *type_name;    // TS_TYPEDEF
    };
} type_spec;


typedef struct {
    type_spec *type;
    type_spec_list *next;
} type_spec_list;


typedef struct {
    type_qual qual;
    type_qual_list *next;
} type_qual_list;


// There is only one kind of func_spec, but I'm still making a list for scalability
typedef struct {
    func_spec spec;
    func_spec_list *next;
} func_spec_list;


typedef struct {
    storage_class storage;
    type_spec_list *type_specs;
    type_qual_list *type_quals;
    func_spec_list *func_specs;
} decl_specs;


typedef struct {
    type_qual_list *type_quals;
    pointer *next;
} pointer;


typedef struct {
    char *id;
    id_list *prev;
} id_list;


typedef struct {
    decl *param_decl;
    param_list *prev;
} param_list;


typedef struct {
    pointer *ptr;
    decltr_core_kind kind;
    union {
        char *id;

        decltr *nested;

        struct {
            bool is_static;
            bool has_asterisk;
            type_qual_list *quals;
            expr *size;
        } array;

        struct {
            param_list *params;
            bool has_ellipsis;
        } func;

        id_list *kr_ids; // Old K&R style; might remove later
    };

    decltr *prev;
} decltr;


typedef struct {
    designator_kind kind;
    union {
        expr *index;
        char *member;
    };

    designator *prev;
} designator;


typedef struct {
    initializer *init;
    designator *designation;

    init_list *prev;
} init_list;


typedef struct {
    initializer_kind kind;
    union {
        expr *assignment;
        init_list *list;
    };
} initializer;


typedef struct {
    decltr *a;
    initializer *init;

    init_decltr *prev;
} init_decltr;


typedef struct {
    decl_specs *specs;
    init_decltr *decltrs;
} decl;


typedef struct {
    decl *curr;
    decl_list *next;
} decl_list;


typedef struct {
    block_item_kind kind;
    union {
        decl *decl;
        stmt *stmt;
    } info;
    block_list *prev;
} block_list;


typedef struct {
    stmt_kind kind;

    union {
        expr *expr_stmt; // STMT_EXPR

        struct {
            block_list *items;
        } compound_stmt;

        // STMT_IF, STMT_SWITCH, STMT_WHILE, STMT_DO
        struct {
            expr *cond;         // Thing to be compared in a switch statement
            stmt *body;
            stmt *else_body;    // If there is an else block
        } conditional_stmt;

        struct {
            // Note that the init can either be a declaration or assignment expression
            for_init_kind kind;
            union {
                decl *decl;
                expr *expr;
            } init;
            expr *cond;
            expr *update_expr;
            stmt *body;
        } for_stmt;

        struct {
            char *label;
            stmt *stmt;
        } label_stmt;

        struct {
            expr *case_expr;
            stmt *result;
        } case_stmt;

        struct {
            stmt *result;
        } default_stmt;

        struct {
            char *label;
        } goto_stmt;

        struct {
            expr *result;
        } return_stmt;
    };
} stmt;


typedef struct {
    func_def_kind kind;
    decl_specs *specs;
    decltr *decltr;
    decl_list *decls;
    stmt *body;
} func_def;


typedef struct {
    ext_decl_kind kind;
    union {
        func_def *func;
        decl *decl;
    };
} ext_decl;


typedef struct {
    ext_decl *action;
    translation_unit *prev;
} translation_unit;


// Helper struct that gets converted into a decl_specs when parsing
// Represents the "declaration_specifiers" non-terminal
// Not used in the AST
typedef struct {
    decl_spec_kind kind;
    union {
        storage_class storage;
        type_spec *type_spec;
        type_qual type_qual;
        func_spec func_spec;
    };

    decl_spec_list *next;
} decl_spec_list;


/*
    --------- Struct Factories ---------
*/

// Constant
static inline constant *make_constant(const_kind kind, char *value);

// Translation unit
//static inline translation_unit *make_trans_unit(translation_unit *next, ext_decl *curr);

// Expressions
static inline expr *make_expr(expr_kind kind, expr *left, expr *right);
static inline expr *make_id_expr(char *id);
static inline expr *make_const_expr(constant *const_val);
static inline expr *make_string_expr(char *str);
static inline expr *make_member_access_expr(expr_kind kind, expr *item, char *id);
static inline expr *make_init_expr(type_name *type, init_list *init);
static inline expr *make_sizeof_expr(type_name *type);
static inline expr *make_cast_expr(type_name *type, expr* val);
static inline expr *make_ternary_expr(expr *conditional, expr *first, expr *second);

// Declarations
static inline decl_specs *make_decl_specs(decl_spec_list *specs);

static inline decl *make_decl(decl_specs *specs, init_decltr *init);

static inline init_decltr *make_init_decltr(decltr *decltr, initializer *init);
static inline void add_init_decltr(init_decltr *prev, init_decltr *curr);

static inline decltr *make_id_decltr(char *id);
static inline decltr *make_nested_decltr(decltr *nested);
static inline decltr *make_decltr_array_suffix(decltr *prev, type_qual_list *quals, expr *size, bool is_static, bool has_asterisk);
static inline decltr *make_decltr_proto_suffix(param_list *params);
static inline decltr *make_decltr_kr_suffix(id_list *ids);
static inline void add_pointer(pointer *ptr, decltr *decltr);

static inline initializer *make_expr_init(expr *assignment);
static inline initializer *make_list_init(init_list *list);

static inline init_list *make_init_list(init_list *prev, designator *designation, initializer *init);

static inline designator *make_arr_designator(expr *index);
static inline designator *make_member_designator(char *member);
static inline void add_designator(designator *prev, designator *curr);

static inline type_name *make_type_name(decl_specs *specs, decltr *suffix);

static inline void add_storage_class(decl_spec_list *prev, storage_class storage);
static inline void add_type_spec(decl_spec_list *prev, type_spec *type_spec);
static inline void add_type_qual(decl_spec_list *prev, type_qual type_qual);
static inline void add_func_spec(decl_spec_list *prev, func_spec func_spec);

static inline type_qual_list *make_type_qual_list(type_qual_list *prev, type_qual qual);

// Statements
static inline stmt *make_expr_stmt(expr *expr);
static inline stmt *make_compound_stmt(block_list *block);
static inline stmt *make_conditional_stmt(stmt_kind kind, expr *cond, stmt *body, stmt *else_body);
static inline stmt *make_for_decl_stmt(decl *init, expr *cond, expr *update, stmt *body);
static inline stmt *make_for_expr_stmt(expr *init, expr *cond, expr *update, stmt *body);
static inline stmt *make_labeled_stmt(char *label, stmt *stmt);
static inline stmt *make_case_stmt(expr *case_expr, stmt *result);
static inline stmt *make_default_stmt(stmt *result);
static inline stmt *make_goto_stmt(char *label);
static inline stmt *make_return_stmt(expr *result);
static inline stmt *make_empty_stmt(stmt_kind kind); // For continue, break, and empty return

static inline block_list *make_stmt_block_item(block_list *prev, stmt *stmt);
static inline block_list *make_decl_block_item(block_list *prev, decl *decl);