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
    constant *new_const = malloc(sizeof(constant));
    check_malloc_error(new_const, "Malloc error when creating new constant value");

    new_const->kind = kind;
    new_const->value = strdup(value);

    return new_const;
}

/*
    --------- Expressions ---------
*/

// Helper function; not public
static inline expr *malloc_expr() {
    expr *new_expr = malloc(sizeof(expr));
    check_malloc_error(new_expr, "Malloc error when creatng new expression");
    return new_expr;
}

expr *make_expr(expr_kind kind, expr *left, expr *right) {
    expr *new_expr = malloc_expr();

    new_expr->kind = kind;
    new_expr->left = left;
    new_expr->right = right;

    return new_expr;
}

expr *make_id_expr(char *id) {
    expr *new_expr = malloc_expr();

    new_expr->kind = EXPR_ID;
    new_expr->extra.id = strdup(id);

    return new_expr;
}

expr *make_const_expr(constant *const_val) {
    expr *new_expr = malloc_expr();

    new_expr->kind = EXPR_CONST;
    new_expr->extra.const_val = const_val;

    return new_expr;
}

expr *make_string_expr(char *str) {
    expr *new_expr = malloc_expr();

    new_expr->kind = EXPR_STR_LITERAL;
    new_expr->extra.str_val = strdup(str);

    return new_expr;
}

expr *make_member_access_expr(expr_kind kind, expr *item, char *id) {
    expr *new_expr = malloc_expr();

    new_expr->kind = kind;
    new_expr->left = item;
    new_expr->extra.id = strdup(id);

    return new_expr;
}

expr *make_init_expr(type_name *type, init_list *init) {
    expr *new_expr = malloc_expr();

    new_expr->kind = EXPR_INIT_LIST;
    new_expr->extra.type = type;
    new_expr->extra.init = init;

    return new_expr;
}

expr *make_sizeof_expr(type_name *type) {
    expr *new_expr = malloc_expr();

    new_expr->kind = EXPR_SIZEOF_TYPE;
    new_expr->extra.type = type;

    return new_expr;
}

expr *make_cast_expr(type_name *type, expr* val) {
    expr *new_expr = malloc_expr();

    new_expr->kind = EXPR_CAST;
    new_expr->left = val;
    new_expr->extra.type = type;

    return new_expr;
}

expr *make_ternary_expr(expr *conditional, expr *first, expr *second) {
    expr *new_expr = malloc_expr();

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
    decl *new_decl = malloc(sizeof(decl));
    check_malloc_error(new_decl, "Malloc error when creating new decl");

    new_decl->kind = DECL_NORMAL;
    new_decl->specs = specs;
    new_decl->init_decltrs = init;

    return new_decl;
}

decl *make_param_decl(decl_specs *specs, decltr *param_decltr, bool decltr_abstract) {
    decl *new_decl = malloc(sizeof(decl));
    check_malloc_error(new_decl, "Malloc error when creating new decl");

    new_decl->kind = DECL_PARAM;
    new_decl->specs = specs;
    new_decl->param_decltr = param_decltr;
    new_decl->decltr_abstract = decltr_abstract;

    return new_decl;
}

sou_spec *make_sou_spec(sou_kind kind, char *name, struct_decl_list *decls) {
    sou_spec *new_sou_spec = malloc(sizeof(sou_spec));
    check_malloc_error(new_sou_spec, "Malloc error when creating new sou specifier");

    new_sou_spec->kind = kind;
    new_sou_spec->name = strdup(name);
    new_sou_spec->decls = decls;

    return new_sou_spec;
}

struct_decl_list *make_struct_decl_list(decl_specs *specs, struct_decltr_list *decltrs) {
    struct_decl_list *new_sdl = malloc(sizeof(struct_decl_list));
    check_malloc_error(new_sdl, "Malloc error when creating new struct decl list");

    new_sdl->specs = specs;
    new_sdl->decltrs = decltrs;

    return new_sdl;
}

void add_struct_decl(struct_decl_list *prev, struct_decl_list *curr) {
    curr->next = prev;
}

struct_decltr_list *make_struct_decltr_list(decltr *decltr, expr *bits) {
    struct_decltr_list *new_sdl = malloc(sizeof(struct_decltr_list));
    check_malloc_error(new_sdl, "Malloc error when creating new struct decltr list");

    new_sdl->decltr = decltr;
    new_sdl->bits = bits;

    return new_sdl;
}

void add_struct_decltr(struct_decltr_list *prev, struct_decltr_list *curr) {
    curr->next = prev;
}

init_decltr *make_init_decltr(decltr *decltr, initializer *init) {
    init_decltr *new_init_decltr = malloc(sizeof(init_decltr));
    check_malloc_error(new_init_decltr, "Malloc error when creating new init_decltr");

    new_init_decltr->decltr = decltr;
    new_init_decltr->init = init;

    return new_init_decltr;
}

void add_init_decltr(init_decltr *prev, init_decltr *curr) {
    curr->next = prev;
}

enum_spec *make_enum_spec(char *name, enumerator_list *enums) {
    enum_spec *new_enum_spec = malloc(sizeof(enum_spec));
    check_malloc_error(new_enum_spec, "Malloc error when creating new enum specifier");

    new_enum_spec->name = strdup(name);
    new_enum_spec->enum_list = enums;

    return new_enum_spec;
}

enumerator_list *make_enum_list(char *name, expr *val) {
    enumerator_list *new_enum_list = malloc(sizeof(enumerator_list));
    check_malloc_error(new_enum_list, "Malloc error when creating new enum list");

    new_enum_list->name = strdup(name);
    new_enum_list->const_val = val;
    
    return new_enum_list;
}

void add_enumerator(enumerator_list *prev, enumerator_list *curr) {
    curr->next = prev;
}

pointer *make_pointer(type_qual_list *quals, pointer *next) {
    pointer *new_ptr = malloc(sizeof(pointer));
    check_malloc_error(new_ptr, "Malloc error when creating new pointer (struct)");

    new_ptr->type_quals = quals;
    new_ptr->next = next;

    return new_ptr;
}

// Helper function; not public
static inline decltr *malloc_decltr() {
    decltr *new_decltr = malloc(sizeof(decltr));
    check_malloc_error(new_decltr, "Malloc error when creating new decltr");
    return new_decltr;
}

decltr *make_empty_decltr(pointer *ptr) {
    decltr *new_decltr = malloc_decltr();

    new_decltr->ptr = ptr;

    return new_decltr;
}

decltr *make_id_decltr(char *id) {
    decltr *new_decltr = malloc_decltr();

    new_decltr->kind = DCTR_ID;
    new_decltr->id = strdup(id);

    return new_decltr;
}

decltr *make_decltr_array_suffix(decltr *prev, type_qual_list *quals, expr *size, bool is_static, bool has_asterisk) {
    decltr *new_decltr = malloc_decltr();

    new_decltr->kind = DCTR_ARRAY;
    new_decltr->next = prev;
    new_decltr->array.has_asterisk = has_asterisk;
    new_decltr->array.is_static = is_static;
    new_decltr->array.quals = quals;
    new_decltr->array.size = size;

    return new_decltr;
}

decltr *make_decltr_proto_suffix(decltr *prev, param_list *params) {
    decltr *new_decltr = malloc_decltr();

    new_decltr->kind = DCTR_FUNC_PROTO;
    new_decltr->next = prev;
    new_decltr->func.has_ellipsis = check_param_ellipsis();
    new_decltr->func.params = params;

    return new_decltr;
}

void add_pointer(pointer *ptr, decltr *decltr) {
    if (!decltr) {
        perror("Error trying to add pointer to null decltr");
        return;
    }
    decltr->ptr = ptr;
}

param_list *make_param_list(param_list *prev, decl *param_decl) {
    param_list *new_params = malloc(sizeof(param_list));
    check_malloc_error(new_params, "Malloc error when creating new param list");

    new_params->next = prev;
    new_params->param_decl = param_decl;

    return new_params;
}

initializer *make_expr_init(expr *assignment) {
    initializer *new_init = malloc(sizeof(initializer));
    check_malloc_error(new_init, "Malloc error when creating new initalizer");

    new_init->kind = INIT_EXPR;
    new_init->assignment = assignment;

    return new_init;
}
initializer *make_list_init(init_list *list) {
    initializer *new_init = malloc(sizeof(initializer));
    check_malloc_error(new_init, "Malloc error when creating new initalizer");

    new_init->kind = INIT_LIST;
    new_init->list = list;

    return new_init;
}

init_list *make_init_list(init_list *prev, designation *designation, initializer *init) {
    init_list *new_init_list = malloc(sizeof(init_list));
    check_malloc_error(new_init_list, "Malloc error when creating new init list");

    new_init_list->designation = designation;
    new_init_list->init = init;
    new_init_list->next = prev;

    return new_init_list;
}

designation *make_arr_designator(expr *index) {
    designation *new_designation = malloc(sizeof(designation));
    check_malloc_error(new_designation, "Malloc error when creating new designation");

    new_designation->kind = DSG_INDEX;
    new_designation->index = index;

    return new_designation;
}

designation *make_member_designator(char *member) {
    designation *new_designation = malloc(sizeof(designation));
    check_malloc_error(new_designation, "Malloc error when creating new designation");

    new_designation->kind = DSG_MEMBER;
    new_designation->member = strdup(member);

    return new_designation;
}

void add_designator(designation *prev, designation *curr) {
    curr->next = prev;
}

type_name *make_type_name(decl_specs *specs, decltr *suffix) {
    type_name *new_type_name = malloc(sizeof(type_name));
    check_malloc_error(new_type_name, "Malloc error when creating new type name");

    new_type_name->specs = specs;
    new_type_name->suffix = suffix;

    return new_type_name;
}

// Helper function; not public
static inline decl_spec_list *malloc_spec_list() {
    decl_spec_list *new_specs = malloc(sizeof(decl_spec_list));
    check_malloc_error(new_specs, "Malloc error when creating new decl spec list");
    return new_specs;
}

decl_spec_list *add_storage_class(decl_spec_list *next, storage_class storage) {
    decl_spec_list *new_specs = malloc_spec_list();

    new_specs->kind = DS_STORAGE_CLASS;
    new_specs->storage = storage;
    new_specs->next = next;

    return new_specs;
}

decl_spec_list *add_type_spec(decl_spec_list *next, type_spec *type_spec) {
    decl_spec_list *new_specs = malloc_spec_list();

    new_specs->kind = DS_TYPE_SPEC;
    new_specs->type_spec = type_spec;
    new_specs->next = next;

    return new_specs;
}

decl_spec_list *add_type_qual(decl_spec_list *next, type_qual type_qual) {
    decl_spec_list *new_specs = malloc_spec_list();

    new_specs->kind = DS_TYPE_QUAL;
    new_specs->type_qual = type_qual;
    new_specs->next = next;

    return new_specs;
}

decl_spec_list *add_func_spec(decl_spec_list *next, func_spec func_spec) {
    decl_spec_list *new_specs = malloc_spec_list();

    new_specs->kind = DS_FUNC_SPEC;
    new_specs->func_spec = func_spec;
    new_specs->next = next;

    return new_specs;
}

type_qual_list *make_type_qual_list(type_qual_list *prev, type_qual qual) {
    type_qual_list *new_qual_list = malloc(sizeof(type_qual_list));
    check_malloc_error(new_qual_list, "Malloc error when creating new type qual list");

    new_qual_list->qual = qual;
    new_qual_list->next = prev;

    return new_qual_list;
}

static inline type_spec *malloc_type_spec() {
    type_spec *new_type_spec = malloc(sizeof(type_spec));
    check_malloc_error(new_type_spec, "Malloc error when creating new type spec");
    return new_type_spec;
}

type_spec *make_basic_type_spec(type_spec_kind kind) {
    type_spec *new_type_spec = malloc_type_spec();
    
    new_type_spec->kind = kind;

    return new_type_spec;
}

type_spec *make_sou_type_spec(sou_spec *sou) {
    type_spec *new_type_spec = malloc_type_spec();

    new_type_spec->kind = TS_SOU;
    new_type_spec->sou = sou;
    
    return new_type_spec;
}

type_spec *make_enum_type_spec(enum_spec *enums) {
    type_spec *new_type_spec = malloc_type_spec();

    new_type_spec->kind = TS_ENUM;
    new_type_spec->enums = enums;

    return new_type_spec;
}

type_spec *make_typedef_type_spec(char *name) {
    type_spec *new_type_spec = malloc_type_spec();

    new_type_spec->kind = TS_TYPEDEF;
    new_type_spec->type_name = strdup(name);

    return new_type_spec;
}

/*
    --------- Statements ---------
*/

// Helper function; not public
static inline stmt *malloc_stmt() {
    stmt *new_stmt = malloc(sizeof(stmt));
    check_malloc_error(new_stmt, "Malloc error when creating new statement");
    return new_stmt;
}

stmt *make_expr_stmt(expr *expr) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_EXPR;
    new_stmt->expr_stmt = expr;

    return new_stmt;
}

stmt *make_compound_stmt(block_list *block) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_COMPOUND;
    new_stmt->compound_stmt.items = block;

    return new_stmt;
}

stmt *make_conditional_stmt(stmt_kind kind, expr *cond, stmt *body, stmt *else_body) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = kind;
    new_stmt->conditional_stmt.cond = cond;
    new_stmt->conditional_stmt.body = body;
    new_stmt->conditional_stmt.else_body = else_body;

    return new_stmt;
}

stmt *make_for_decl_stmt(decl *init, stmt *cond, expr *update, stmt *body) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_FOR;
    new_stmt->for_stmt.kind = FOR_DECL;
    new_stmt->for_stmt.init.decl = init;
    new_stmt->for_stmt.cond = cond->expr_stmt;
    new_stmt->for_stmt.update = update;
    new_stmt->for_stmt.body = body;

    return new_stmt;
}

stmt *make_for_expr_stmt(stmt *init, stmt *cond, expr *update, stmt *body) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_FOR;
    new_stmt->for_stmt.kind = FOR_EXPR;
    new_stmt->for_stmt.init.expr = init->expr_stmt;
    new_stmt->for_stmt.cond = cond->expr_stmt;
    new_stmt->for_stmt.update = update;
    new_stmt->for_stmt.body = body;

    return new_stmt;
}

stmt *make_labeled_stmt(char *label, stmt *next) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_LABEL;
    new_stmt->label_stmt.label = strdup(label);
    new_stmt->label_stmt.next = next;

    return new_stmt;
}

stmt *make_case_stmt(expr *case_expr, stmt *result) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_CASE;
    new_stmt->case_stmt.case_expr = case_expr;
    new_stmt->case_stmt.result = result;

    return new_stmt;
}

stmt *make_default_stmt(stmt *result) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_DEFAULT;
    new_stmt->default_stmt.result = result;

    return new_stmt;
}

stmt *make_goto_stmt(char *label) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_GOTO;
    new_stmt->goto_stmt.label = strdup(label);

    return new_stmt;
}

stmt *make_return_stmt(expr *result) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = STMT_RETURN;
    new_stmt->return_stmt.result = result;

    return new_stmt;
}

// For continue, break, and empty return
stmt *make_empty_stmt(stmt_kind kind) {
    stmt *new_stmt = malloc_stmt();

    new_stmt->kind = kind;

    return new_stmt;
}

block_list *make_stmt_block_item(stmt *stmt) {
    block_list *new_block = malloc(sizeof(block_list));
    check_malloc_error(new_block, "Malloc error when creating new block list");

    new_block->kind = BI_STMT;
    new_block->stmt = stmt;

    return new_block;
}

block_list *make_decl_block_item(decl *decl) {
    block_list *new_block = malloc(sizeof(block_list));
    check_malloc_error(new_block, "Malloc error when creating new block list");

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
    func_def *new_func = malloc(sizeof(func_def));

    new_func->specs = specs;
    new_func->decltr = decltr;
    new_func->body = body;

    return new_func;
}

/*
    --------- External Declarations ---------
*/

ext_decl *make_func_ext_decl(func_def *func) {
    ext_decl *new_ext_decl = malloc(sizeof(ext_decl));
    check_malloc_error(new_ext_decl, "Malloc error when creating new external decl");

    new_ext_decl->kind = EXT_DECL_FUNC;
    new_ext_decl->func = func;

    return new_ext_decl;
}

ext_decl *make_decl_ext_decl(decl *decl) {
    ext_decl *new_ext_decl = malloc(sizeof(ext_decl));
    check_malloc_error(new_ext_decl, "Malloc error when creating new external decl");

    new_ext_decl->kind = EXT_DECL_SIMPLE;
    new_ext_decl->decl = decl;

    return new_ext_decl;
}

/*
    --------- Translation Unit ---------
*/

translation_unit *make_trans_unit(translation_unit *prev, ext_decl *curr) {
    translation_unit *new_trans_unit = malloc(sizeof(translation_unit));
    check_malloc_error(new_trans_unit, "Malloc error when creating new translation unit");

    new_trans_unit->action = curr;
    new_trans_unit->next = prev;

    return new_trans_unit;
}

/*
    --------- Extra helpers ---------
*/

decl_specs *make_decl_specs(decl_spec_list *list) {
    decl_specs *specs = malloc(sizeof(decl_specs));
    check_malloc_error(specs, "Malloc error when initializing new decl_specs in AST");
    specs->storage = SC_NONE;

    for (decl_spec_list *curr = list; curr; curr = curr->next) {
        switch (curr->kind) {
            case DS_STORAGE_CLASS: {
                if (specs->storage != SC_NONE) {
                    fprintf(stderr, "*** declarations may not have more than one storage class");
                }
                specs->storage = curr->storage;
                break;
            }
            case DS_TYPE_SPEC: {
                type_spec_list *type_specs = specs->type_specs;
                type_spec_list *new_spec = malloc(sizeof(type_spec_list));
                check_malloc_error(new_spec, "Malloc error when creating new type spec");

                new_spec->type = curr->type_spec;
                new_spec->next = type_specs;
                specs->type_specs = new_spec;
                break;
            }
            case DS_TYPE_QUAL: {
                type_qual_list *type_quals = specs->type_quals;
                type_qual_list *new_qual = malloc(sizeof(type_qual_list));
                check_malloc_error(new_qual, "Malloc error when creating new type qual");

                new_qual->qual = curr->type_qual;
                new_qual->next = type_quals;
                specs->type_quals = new_qual;
                break;
            } case DS_FUNC_SPEC: {
                func_spec_list *func_specs = specs->func_specs;
                func_spec_list *new_spec = malloc(sizeof(func_spec_list));
                check_malloc_error(new_spec, "Malloc error when creating new func spec");
                
                new_spec->spec = curr->func_spec;
                new_spec->next = func_specs;
                specs->func_specs = new_spec;
                break;
            }
        }
    }

    return specs;
}