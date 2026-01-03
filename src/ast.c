/*
    Implementation of "ast.h"
*/

#include "ast.h"
#include "parser_helpers.h"
#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    --------- Constant ---------
*/

constant *make_constant(const_kind kind, char *value) {
    constant *new_const = calloc(1, sizeof(constant));
    check_alloc_error(new_const, "Alloc error when creating new constant value");

    new_const->kind = kind;
    new_const->value = value ? strdup(value) : 0;

    return new_const;
}

/*
    --------- Expressions ---------
*/

// Helper function; not public
static inline expr *alloc_expr() {
    expr *new_expr = calloc(1, sizeof(expr));
    check_alloc_error(new_expr, "Alloc error when creatng new expression");
    return new_expr;
}

expr *make_expr(expr_kind kind, expr *left, expr *right) {
    expr *new_expr = alloc_expr();

    new_expr->kind = kind;
    new_expr->left = left;
    new_expr->right = right;

    return new_expr;
}

expr *make_id_expr(char *id) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_ID;
    new_expr->extra.id = id ? strdup(id) : 0;

    return new_expr;
}

expr *make_const_expr(constant *const_val) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_CONST;
    new_expr->extra.const_val = const_val;

    return new_expr;
}

expr *make_string_expr(const char *str) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_STR_LITERAL;
    new_expr->extra.str_val = str ? strdup(str) : 0;

    return new_expr;
}

expr *make_member_access_expr(expr_kind kind, expr *item, char *id) {
    expr *new_expr = alloc_expr();

    new_expr->kind = kind;
    new_expr->left = item;
    new_expr->extra.id = id ? strdup(id) : 0;

    return new_expr;
}

expr *make_init_expr(type_name *type, init_list *init) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_INIT_LIST;
    new_expr->extra.type = type;
    new_expr->extra.init = init;

    return new_expr;
}

expr *make_sizeof_expr(type_name *type) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_SIZEOF_TYPE;
    new_expr->extra.type = type;

    return new_expr;
}

expr *make_cast_expr(type_name *type, expr* val) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_CAST;
    new_expr->left = val;
    new_expr->extra.type = type;

    return new_expr;
}

expr *make_ternary_expr(expr *conditional, expr *first, expr *second) {
    expr *new_expr = alloc_expr();

    new_expr->kind = EXPR_CONDITIONAL;
    new_expr->left = first;
    new_expr->right = second;
    new_expr->extra.conditional = conditional;

    return new_expr;
}

/*
    --------- Declarations ---------
*/

decl *make_normal_decl(decl_specs *specs, init_decltr *init) {
    decl *new_decl = calloc(1, sizeof(decl));
    check_alloc_error(new_decl, "Alloc error when creating new decl");

    new_decl->kind = DECL_NORMAL;
    new_decl->specs = specs;
    new_decl->init_decltrs = init;

    return new_decl;
}

decl *make_param_decl(decl_specs *specs, decltr *param_decltr, bool decltr_abstract) {
    decl *new_decl = calloc(1, sizeof(decl));
    check_alloc_error(new_decl, "Alloc error when creating new decl");

    new_decl->kind = DECL_PARAM;
    new_decl->specs = specs;
    new_decl->param_decltr = param_decltr;
    new_decl->decltr_abstract = decltr_abstract;

    return new_decl;
}

sou_spec *make_sou_spec(sou_kind kind, char *name, struct_decl_list *decls) {
    sou_spec *new_sou_spec = calloc(1, sizeof(sou_spec));
    check_alloc_error(new_sou_spec, "Alloc error when creating new sou specifier");

    new_sou_spec->kind = kind;
    new_sou_spec->name = name ? strdup(name) : 0;
    new_sou_spec->decls = decls;

    return new_sou_spec;
}

struct_decl_list *make_struct_decl_list(decl_specs *specs, struct_decltr_list *decltrs) {
    struct_decl_list *new_sdl = calloc(1, sizeof(struct_decl_list));
    check_alloc_error(new_sdl, "Alloc error when creating new struct decl list");

    new_sdl->specs = specs;
    new_sdl->decltrs = decltrs;

    return new_sdl;
}

void add_struct_decl(struct_decl_list *prev, struct_decl_list *curr) {
    curr->next = prev;
}

struct_decltr_list *make_struct_decltr_list(decltr *decltr) {
    struct_decltr_list *new_sdl = calloc(1, sizeof(struct_decltr_list));
    check_alloc_error(new_sdl, "Alloc error when creating new struct decltr list");

    new_sdl->decltr = decltr;

    return new_sdl;
}

void add_struct_decltr(struct_decltr_list *prev, struct_decltr_list *curr) {
    curr->next = prev;
}

init_decltr *make_init_decltr(decltr *decltr, initializer *init) {
    init_decltr *new_init_decltr = calloc(1, sizeof(init_decltr));
    check_alloc_error(new_init_decltr, "Alloc error when creating new init_decltr");

    new_init_decltr->decltr = decltr;
    new_init_decltr->init = init;

    return new_init_decltr;
}

void add_init_decltr(init_decltr *prev, init_decltr *curr) {
    curr->next = prev;
}

enum_spec *make_enum_spec(char *name, enumerator_list *enums) {
    enum_spec *new_enum_spec = calloc(1, sizeof(enum_spec));
    check_alloc_error(new_enum_spec, "Alloc error when creating new enum specifier");

    new_enum_spec->name = name ? strdup(name) : 0;
    new_enum_spec->enum_list = enums;

    return new_enum_spec;
}

enumerator_list *make_enum_list(char *name, expr *val) {
    enumerator_list *new_enum_list = calloc(1, sizeof(enumerator_list));
    check_alloc_error(new_enum_list, "Alloc error when creating new enum list");

    new_enum_list->name = name ? strdup(name) : 0;
    new_enum_list->const_val = val;
    
    return new_enum_list;
}

void add_enumerator(enumerator_list *prev, enumerator_list *curr) {
    curr->next = prev;
}

pointer *make_pointer(type_qual_list *quals, pointer *curr) {
    pointer *new_ptr = calloc(1, sizeof(pointer));
    check_alloc_error(new_ptr, "Alloc error when creating new pointer (struct)");

    new_ptr->type_quals = quals;
    if (curr) curr->next = new_ptr;

    return new_ptr;
}

// Helper function; not public
static inline decltr *alloc_decltr() {
    decltr *new_decltr = calloc(1, sizeof(decltr));
    check_alloc_error(new_decltr, "Alloc error when creating new decltr");
    return new_decltr;
}

decltr *make_empty_decltr(pointer *ptr) {
    decltr *new_decltr = alloc_decltr();

    new_decltr->ptr = ptr;

    return new_decltr;
}

decltr *make_id_decltr(char *id) {
    decltr *new_decltr = alloc_decltr();

    new_decltr->kind = DCTR_ID;
    new_decltr->id = strdup(id);

    return new_decltr;
}

decltr *make_decltr_array_suffix(decltr *prev, type_qual_list *quals, expr *size) {
    decltr *new_decltr = alloc_decltr();

    new_decltr->kind = DCTR_ARRAY;
    new_decltr->next = prev;
    new_decltr->array.quals = quals;
    new_decltr->array.size = size;

    return new_decltr;
}

decltr *make_decltr_proto_suffix(decltr *prev, param_type_list *params) {
    decltr *new_decltr = alloc_decltr();

    new_decltr->kind = DCTR_FUNC;
    new_decltr->next = prev;
    if (params) new_decltr->func.params = params->params;
    if (params) new_decltr->func.variadic = params->variadic;

    free(params);

    return new_decltr;
}

void add_pointer(pointer *ptr, decltr *decltr) {
    if (!decltr) {
        perror("Error trying to add pointer to null decltr");
        return;
    }

    if (!decltr->ptr) {
        decltr->ptr = ptr;
        return;
    }

    // Handles cases like "void *(*a)" which would otherwise replace the inner pointer with the outer
    extend_pointer(decltr->ptr, ptr);
}

void extend_pointer(pointer *curr, pointer *extend) {
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = extend;
}

param_list *make_param_list(param_list *prev, decl *param_decl) {
    param_list *new_params = calloc(1, sizeof(param_list));
    check_alloc_error(new_params, "Alloc error when creating new param list");

    new_params->next = prev;
    new_params->param_decl = param_decl;

    return new_params;
}

param_type_list *make_param_type_list(param_list *params, bool variadic) {
    param_type_list *new_list = calloc(1, sizeof(param_type_list));
    check_alloc_error(new_list, "Alloc error when creating new param type list");

    new_list->params = params;
    new_list->variadic = variadic;

    return new_list;
}

initializer *make_expr_init(expr *assignment) {
    initializer *new_init = calloc(1, sizeof(initializer));
    check_alloc_error(new_init, "Alloc error when creating new initalizer");

    new_init->kind = INIT_EXPR;
    new_init->assignment = assignment;

    return new_init;
}
initializer *make_list_init(init_list *list) {
    initializer *new_init = calloc(1, sizeof(initializer));
    check_alloc_error(new_init, "Alloc error when creating new initalizer");

    new_init->kind = INIT_LIST;
    new_init->list = list;

    return new_init;
}

init_list *make_init_list(init_list *prev, initializer *init) {
    init_list *new_init_list = calloc(1, sizeof(init_list));
    check_alloc_error(new_init_list, "Alloc error when creating new init list");

    new_init_list->init = init;
    new_init_list->next = prev;

    return new_init_list;
}

type_name *make_type_name(decl_specs *specs, decltr *suffix) {
    type_name *new_type_name = calloc(1, sizeof(type_name));
    check_alloc_error(new_type_name, "Alloc error when creating new type name");

    new_type_name->specs = specs;
    new_type_name->suffix = suffix;

    return new_type_name;
}

// Helper function; not public
static inline decl_spec_list *alloc_spec_list() {
    decl_spec_list *new_specs = calloc(1, sizeof(decl_spec_list));
    check_alloc_error(new_specs, "Alloc error when creating new decl spec list");
    return new_specs;
}

decl_spec_list *add_storage_class(decl_spec_list *next, storage_class storage) {
    decl_spec_list *new_specs = alloc_spec_list();

    new_specs->kind = DS_STORAGE_CLASS;
    new_specs->storage = storage;
    new_specs->next = next;

    return new_specs;
}

decl_spec_list *add_type_spec(decl_spec_list *next, type_spec *type_spec) {
    decl_spec_list *new_specs = alloc_spec_list();

    new_specs->kind = DS_TYPE_SPEC;
    new_specs->type_spec = type_spec;
    new_specs->next = next;

    return new_specs;
}

decl_spec_list *add_type_qual(decl_spec_list *next, type_qual type_qual) {
    decl_spec_list *new_specs = alloc_spec_list();

    new_specs->kind = DS_TYPE_QUAL;
    new_specs->type_qual = type_qual;
    new_specs->next = next;

    return new_specs;
}

decl_spec_list *add_func_spec(decl_spec_list *next, func_spec func_spec) {
    decl_spec_list *new_specs = alloc_spec_list();

    new_specs->kind = DS_FUNC_SPEC;
    new_specs->func_spec = func_spec;
    new_specs->next = next;

    return new_specs;
}

type_qual_list *make_type_qual_list(type_qual_list *prev, type_qual qual) {
    type_qual_list *new_qual_list = calloc(1, sizeof(type_qual_list));
    check_alloc_error(new_qual_list, "Alloc error when creating new type qual list");

    new_qual_list->qual = qual;
    new_qual_list->next = prev;

    return new_qual_list;
}

static inline type_spec *alloc_type_spec() {
    type_spec *new_type_spec = calloc(1, sizeof(type_spec));
    check_alloc_error(new_type_spec, "Alloc error when creating new type spec");
    return new_type_spec;
}

type_spec *make_basic_type_spec(type_spec_kind kind) {
    type_spec *new_type_spec = alloc_type_spec();
    
    new_type_spec->kind = kind;

    return new_type_spec;
}

type_spec *make_sou_type_spec(sou_spec *sou) {
    type_spec *new_type_spec = alloc_type_spec();

    new_type_spec->kind = TS_SOU;
    new_type_spec->sou = sou;
    
    return new_type_spec;
}

type_spec *make_enum_type_spec(enum_spec *enums) {
    type_spec *new_type_spec = alloc_type_spec();

    new_type_spec->kind = TS_ENUM;
    new_type_spec->enums = enums;

    return new_type_spec;
}

type_spec *make_typedef_type_spec(char *name) {
    type_spec *new_type_spec = alloc_type_spec();

    new_type_spec->kind = TS_TYPEDEF;
    new_type_spec->type_name = name ? strdup(name) : 0;

    return new_type_spec;
}

/*
    --------- Statements ---------
*/

// Helper function; not public
static inline stmt *alloc_stmt() {
    stmt *new_stmt = calloc(1, sizeof(stmt));
    check_alloc_error(new_stmt, "Alloc error when creating new statement");
    return new_stmt;
}

stmt *make_expr_stmt(expr *expr) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_EXPR;
    new_stmt->expr_stmt = expr;

    return new_stmt;
}

stmt *make_compound_stmt(block_list *block) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_COMPOUND;
    new_stmt->compound_stmt.items = block;

    return new_stmt;
}

stmt *make_conditional_stmt(stmt_kind kind, expr *cond, stmt *body, stmt *else_body) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = kind;
    new_stmt->conditional_stmt.cond = cond;
    new_stmt->conditional_stmt.body = body;
    new_stmt->conditional_stmt.else_body = else_body;

    return new_stmt;
}

stmt *make_for_decl_stmt(decl *init, stmt *cond, expr *update, stmt *body) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_FOR;
    new_stmt->for_stmt.kind = FOR_DECL;
    new_stmt->for_stmt.init.decl = init;
    new_stmt->for_stmt.cond = cond->expr_stmt;
    new_stmt->for_stmt.update = update;
    new_stmt->for_stmt.body = body;

    return new_stmt;
}

stmt *make_for_expr_stmt(stmt *init, stmt *cond, expr *update, stmt *body) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_FOR;
    new_stmt->for_stmt.kind = FOR_EXPR;
    new_stmt->for_stmt.init.expr = init->expr_stmt;
    new_stmt->for_stmt.cond = cond->expr_stmt;
    new_stmt->for_stmt.update = update;
    new_stmt->for_stmt.body = body;

    return new_stmt;
}

stmt *make_labeled_stmt(char *label, stmt *next) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_LABEL;
    new_stmt->label_stmt.label = label ? strdup(label) : 0;
    new_stmt->label_stmt.next = next;

    return new_stmt;
}

stmt *make_case_stmt(expr *case_expr, stmt *result) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_CASE;
    new_stmt->case_stmt.case_expr = case_expr;
    new_stmt->case_stmt.result = result;

    return new_stmt;
}

stmt *make_default_stmt(stmt *result) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_DEFAULT;
    new_stmt->default_stmt.result = result;

    return new_stmt;
}

stmt *make_goto_stmt(char *label) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_GOTO;
    new_stmt->goto_stmt.label = label ? strdup(label) : 0;

    return new_stmt;
}

stmt *make_return_stmt(expr *result) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = STMT_RETURN;
    new_stmt->return_stmt.result = result;

    return new_stmt;
}

// For continue and break
stmt *make_empty_stmt(stmt_kind kind) {
    stmt *new_stmt = alloc_stmt();

    new_stmt->kind = kind;

    return new_stmt;
}

block_list *make_stmt_block_item(stmt *stmt) {
    block_list *new_block = calloc(1, sizeof(block_list));
    check_alloc_error(new_block, "Alloc error when creating new block list");

    new_block->kind = BI_STMT;
    new_block->stmt = stmt;

    return new_block;
}

block_list *make_decl_block_item(decl *decl) {
    block_list *new_block = calloc(1, sizeof(block_list));
    check_alloc_error(new_block, "Alloc error when creating new block list");

    new_block->kind = BI_DECL;
    new_block->decl = decl;

    return new_block;
}

void add_block_item(block_list *prev, block_list *curr) {
    curr->next = prev;
}

/*
    --------- Function definition ---------
*/

func_def *make_func_def(decl_specs *specs, decltr *decltr, stmt *body) {
    func_def *new_func = calloc(1, sizeof(func_def));
    check_alloc_error(new_func, "Alloc error when creating new function definition");

    new_func->specs = specs;
    new_func->decltr = decltr;
    new_func->body = body;

    return new_func;
}

/*
    --------- External Declarations ---------
*/

ext_decl *make_func_ext_decl(func_def *func) {
    ext_decl *new_ext_decl = calloc(1, sizeof(ext_decl));
    check_alloc_error(new_ext_decl, "Alloc error when creating new external decl");

    new_ext_decl->kind = EXT_DECL_FUNC;
    new_ext_decl->func = func;

    return new_ext_decl;
}

ext_decl *make_decl_ext_decl(decl *decl) {
    ext_decl *new_ext_decl = calloc(1, sizeof(ext_decl));
    check_alloc_error(new_ext_decl, "Alloc error when creating new external decl");

    new_ext_decl->kind = EXT_DECL_SIMPLE;
    new_ext_decl->decl = decl;

    return new_ext_decl;
}

/*
    --------- Translation Unit ---------
*/

translation_unit *make_trans_unit(translation_unit *prev, ext_decl *curr) {
    translation_unit *new_trans_unit = calloc(1, sizeof(translation_unit));
    check_alloc_error(new_trans_unit, "Alloc error when creating new translation unit");

    new_trans_unit->action = curr;
    new_trans_unit->next = prev;

    return new_trans_unit;
}

/*
    --------- Freeing Memory ---------
*/

void free_expr(expr *e) {
    if (!e) return;

    switch (e->kind) {
        case EXPR_MEMBER_DOT: case EXPR_MEMBER_ARROW: case EXPR_ID:
            free(e->extra.id);
            break;
        case EXPR_CONST:
            free(e->extra.const_val->value);
            free(e->extra.const_val);
            break;
        case EXPR_STR_LITERAL:
            free(e->extra.str_val);
            break;
        case EXPR_CONDITIONAL:
            free(e->extra.conditional);
            break;
        case EXPR_CAST: case EXPR_SIZEOF_TYPE:
            free_type_name(e->extra.type);
            break;
        case EXPR_INIT_LIST:
            free_type_name(e->extra.type);
            // free_init_list(e->extra.init);
            break;
        default:;
    }

    free_expr(e->left);
    free_expr(e->right);
    free(e);
}

void free_type_name(type_name *tn) {
    // NOTE: FINISH LATER
}

/*
    --------- Extra helpers ---------
*/

decl_specs *make_decl_specs(decl_spec_list *list) {
    decl_specs *specs = calloc(1, sizeof(decl_specs));
    check_alloc_error(specs, "Alloc error when initializing new decl_specs in AST");
    specs->storage = SC_NONE;
    specs->func_spec = FS_NONE;

    for (decl_spec_list *curr = list; curr; curr = curr->next) {
        switch (curr->kind) {
            case DS_STORAGE_CLASS: {
                if (specs->storage != SC_NONE) {
                    fprintf(stderr, "*** declarations may not have more than one storage class");
                }
                specs->storage = curr->storage;
                break;
            }
            case DS_FUNC_SPEC: {
                if (specs->func_spec != FS_NONE) {
                    fprintf(stderr, "*** declarations may not have more than one storage class");
                }
                specs->func_spec = curr->func_spec;
                break;
            }
            case DS_TYPE_SPEC: {
                type_spec_list *type_specs = specs->type_specs;
                type_spec_list *new_spec = calloc(1, sizeof(type_spec_list));
                check_alloc_error(new_spec, "Alloc error when creating new type spec");

                new_spec->type = curr->type_spec;
                new_spec->next = type_specs;
                specs->type_specs = new_spec;
                break;
            }
            case DS_TYPE_QUAL: {
                type_qual_list *type_quals = specs->type_quals;
                type_qual_list *new_qual = calloc(1, sizeof(type_qual_list));
                check_alloc_error(new_qual, "Alloc error when creating new type qual");

                new_qual->qual = curr->type_qual;
                new_qual->next = type_quals;
                specs->type_quals = new_qual;
                break;
            }
        }
    }

    return specs;
}