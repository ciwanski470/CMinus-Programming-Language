/*
    Implementation of "ast_printer.h"
*/

#include "ast_printer.h"
#include "ast.h"
#include "parser_helpers.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *file = 0;
static int indents = 0;

#define TAB_SIZE 4

/*
    Prints the given text to the output file with appropriate whitespace
    Allows for format specification
    "##__VA_ARGS__" is GCC and Clang specific
*/
#define ast_write(a, ...) \
    print_indents(); \
    fprintf(file, a, ##__VA_ARGS__);

/*
    Used as a shorthand for writing cases for printing unary expressions
*/
#define unary_expr_case(expr_enum, label) \
    case expr_enum:             \
        ast_write(label)        \
        ast_write("Item:\n")    \
        print_expr(expr->left);  \
        break;

/*
    Used as a shorthand for writing cases for printing binary expressions
*/
#define bin_expr_case(expr_enum, label) \
    case expr_enum:                 \
        ast_write(label)            \
        ast_write("Left:\n")        \
        print_expr(expr->left);     \
        ast_write("Right:\n")       \
        print_expr(expr->right);    \
        break;

/*
    Used as a shorthand for writing cases for printing assignment expressions
*/
#define assignment_expr_case(expr_enum, label) \
    case expr_enum:                     \
        ast_write(label)                \
        ast_write("Left Value:\n")      \
        print_expr(expr->left);         \
        ast_write("Assigned Value:\n")  \
        print_expr(expr->right);        \
        break;

// Forward declarations
static void print_trans_unit(translation_unit *trans_unit);

static void print_func_def          (func_def *func);
static void print_param_list        (param_list *params);
static void print_decl              (decl *decl);
static void print_decl_specs        (decl_specs *specs);
static void print_type_qual_list    (type_qual_list *quals);
static void print_type_spec         (type_spec *type);
static void print_sou_spec          (sou_spec *sou);
static void print_struct_decltrs    (struct_decltr_list *decltrs);
static void print_enum_spec         (enum_spec *enums);
static void print_init_decltrs      (init_decltr *decltrs);
static void print_decltr            (decltr *decltr);
static void print_pointer           (pointer *ptr);
static void print_initializer       (initializer *init);
static void print_stmt              (stmt *stmt);
static void print_block_list        (block_list *block);
static void print_expr              (expr *expr);
static void print_type_name         (type_name *type);
static void print_init_list         (init_list *list);
static void print_arg_list          (expr *arg_expr);

// Public function
void print_ast(translation_unit *tree, const char *output_name) {
    file = fopen(output_name, "w");
    if (!file) {
        perror("Could not create output file for AST");
        return;
    }

    indents = 0;
    print_trans_unit(tree);
    
    fclose(file);
    file = 0;
}

static inline void print_indents() {
    for (int i=0; i<indents; i++) {
        for (int j=0; j<TAB_SIZE; j++) {
            fprintf(file, " ");
        }
    }
}

static void print_trans_unit(translation_unit *trans_unit) {
    for (translation_unit *curr = trans_unit; curr; curr = curr->next) {
        switch (curr->action->kind) {
            case EXT_DECL_FUNC:
                ast_write("Function definition:\n");
                print_func_def(curr->action->func);
                break;
            case EXT_DECL_SIMPLE:
                ast_write("Declaration:\n");
                print_decl(curr->action->decl);
                break;
        }
        fprintf(file, "\n");
        fflush(file);
    }
}

static void print_func_def(func_def *func) {
    indents++;

    ast_write("Specifiers:\n");
    print_decl_specs(func->specs);

    ast_write("Declarator:\n");
    print_decltr(func->decltr);

    ast_write("Body:\n");
    print_block_list(func->body->compound_stmt.items);

    indents--;
}

static void print_param_list(param_list *params) {
    indents++;

    for (param_list *curr = params; curr; curr = curr->next) {
        ast_write("Declaration:\n");
        print_decl(curr->param_decl);
    }

    indents--;
}

static void print_decl(decl *decl) {
    indents++;

    ast_write("Specifiers:\n");
    print_decl_specs(decl->specs);

    switch (decl->kind) {
        case DECL_NORMAL:
            ast_write("Declarator-Initializer List:\n");
            print_init_decltrs(decl->init_decltrs);
            break;
        case DECL_PARAM:
            if (decl->param_decltr) {
                ast_write("Parameter Declarator:\n");
                print_decltr(decl->param_decltr);
            }
            break;
    }

    indents--;
}

static void print_decl_specs(decl_specs *specs) {
    indents++;

    switch (specs->storage) {
        case SC_EXTERN:
            ast_write("Storage Class: extern\n");
            break;
        case SC_STATIC:
            ast_write("Storage Class: static\n");
            break;
        case SC_REGISTER:
            ast_write("Storage class: register");
            break;
        case SC_AUTO:
            ast_write("Storage class: auto");
            break;
        case SC_TYPEDEF:
            ast_write("Storage Class: typedef\n");
            break;
        case SC_NONE:;
    }

    switch (specs->func_spec) {
        case FS_INLINE:
            ast_write("Function Specifier: inline\n");
            break;
        case FS_NONE:;
    }

    if (specs->type_quals) {
        ast_write("Type Qualifiers:\n");
        print_type_qual_list(specs->type_quals);
    }

    if (specs->type_specs) {
        ast_write("Type Specifiers:\n");
        for (type_spec_list *curr = specs->type_specs; curr; curr = curr->next) {
            print_type_spec(curr->type);
        }
    }

    indents--;
}

static void print_type_qual_list(type_qual_list *quals) {
    indents++;

    for (type_qual_list *curr = quals; curr; curr = curr->next) {
        switch (curr->qual) {
            case TQ_CONST:
                ast_write("const");
                break;
            case TQ_RESTRICT:
                ast_write("restrict");
                break;
            case TQ_VOLATILE:
                ast_write("volatile");
                break;
        }
    }

    indents--;
}

static void print_type_spec(type_spec *type) {
    indents++;

    switch (type->kind) {
        case TS_VOID:
            ast_write("void\n");
            break;
        case TS_CHAR:
            ast_write("char\n");
            break;
        case TS_SHORT:
            ast_write("short\n");
            break;
        case TS_INT:
            ast_write("int\n");
            break;
        case TS_LONG:
            ast_write("long\n");
            break;
        case TS_FLOAT:
            ast_write("float\n");
            break;
        case TS_DOUBLE:
            ast_write("double\n");
            break;
        case TS_SIGNED:
            ast_write("signed\n");
            break;
        case TS_UNSIGNED:
            ast_write("unsigned\n");
            break;
        case TS_BOOL:
            ast_write("_Bool\n");
            break;
        case TS_SOU: {
            char *kind;
            switch (type->sou->kind) {
                case SOU_STRUCT:
                    kind = "Struct";
                    break;
                case SOU_UNION:
                    kind = "Union";
                    break;
            }
            if (type->sou->decls) {
                ast_write("%s \"%s\":\n", kind, type->sou->name);
                print_sou_spec(type->sou);
            } else {
                ast_write("%s \"%s\"\n", kind, type->sou->name);
            }
            free(kind);
            break;
        }
        case TS_ENUM:
            ast_write("Enum \"%s\"\n", type->enums->name);
            print_enum_spec(type->enums);
            break;
        case TS_TYPEDEF:
            ast_write("Typedef: \"%s\"\n", type->type_name);
            break;
    }

    indents--;
}

static void print_sou_spec(sou_spec *sou) {
    indents++;

    for (struct_decl_list *curr = sou->decls; curr; curr = curr->next) {
        ast_write("Declaration:\n");
        indents++;
        ast_write("Specifiers:\n");
        print_decl_specs(curr->specs);
        ast_write("Declarators:\n");
        print_struct_decltrs(curr->decltrs);
        indents--;
    }

    indents--;
}

static void print_struct_decltrs(struct_decltr_list *decltrs) {
    indents++;

    for (struct_decltr_list *curr = decltrs; curr; curr = curr->next) {
        if (curr->decltr) {
            ast_write("Declarator:\n");
            print_decltr(curr->decltr);
        } else {
            ast_write("Declarator: None\n");
        }
    }

    indents--;
}

static void print_enum_spec(enum_spec *specs) {
    indents++;

    for (enumerator_list *curr = specs->enum_list; curr; curr = curr->next) {
        ast_write("Enumerator:\n");
        indents++;
        ast_write("Name: \"%s\"\n", curr->name);
        if (curr->const_val) {
            ast_write("Value:\n");
            print_expr(curr->const_val);
        } else {
            ast_write("Value: None\n");
        }
    }

    indents--;
}

static void print_init_decltrs(init_decltr *decltrs) {
    indents++;

    for (init_decltr *curr = decltrs; curr; curr = decltrs->next) {
        ast_write("Declarator:\n");
        print_decltr(curr->decltr);
        if (curr->init) {
            ast_write("Initializer:\n");
            print_initializer(curr->init);
        } else {
            ast_write("Initializer: None\n");
        }
    }

    indents--;
}

static void print_decltr(decltr *dctr) {
    indents++;

    for (decltr *curr = dctr; curr; curr = curr->next) {
        switch (curr->kind) {
            case DCTR_ARRAY:
                ast_write("Array Suffix:\n");
                indents++;
                if (curr->array.quals) {
                    ast_write("Type Qualifiers:\n");
                    print_type_qual_list(curr->array.quals);
                }
                if (curr->array.size) {
                    ast_write("Size:\n");
                    print_expr(curr->array.size);
                } else {
                    ast_write("Size: None\n");
                }
                indents--;
                break;
            case DCTR_FUNC:
                ast_write("Function Suffix:\n");
                indents++;
                ast_write("Parameters:\n");
                print_param_list(curr->func.params);
                indents--;
                break;
            case DCTR_ID:
                ast_write("Identifier: \"%s\"\n", curr->id);
                break;
            case DCTR_EMPTY:
                ast_write("Empty\n");
        }
        if (curr->ptr) {
            indents++;
            ast_write("Pointer:\n");
            print_pointer(curr->ptr);
            indents--;
        }
    }

    indents--;
}

static void print_pointer(pointer *ptr) {
    indents++;

    for (pointer *curr = ptr; curr; curr = curr->next) {
        if (curr->type_quals) {
            ast_write("*Ptr:\n");
            indents++;
            ast_write("Type Quals:\n");
            print_type_qual_list(curr->type_quals);
            indents--;
        } else {
            ast_write("*Ptr\n");
        }
    }

    indents--;
}

static void print_initializer(initializer *init) {
    switch (init->kind) {
        case INIT_EXPR:
            print_expr(init->assignment);
            break;
        case INIT_LIST:
            print_init_list(init->list);
            break;
    }
}

static void print_stmt(stmt *stmt) {
    indents++;

    switch (stmt->kind) {
        case STMT_EXPR:
            if (stmt->expr_stmt) {
                ast_write("Expression:\n");
                print_expr(stmt->expr_stmt);
            } else {
                ast_write("Expression: empty\n");
            }
            break;
        case STMT_COMPOUND:
            ast_write("Block List:\n");
            print_block_list(stmt->compound_stmt.items);
            break;
        case STMT_IF:
            ast_write("If Statement:\n");
            indents++;
            ast_write("Condition:\n");
            print_expr(stmt->conditional_stmt.cond);
            ast_write("Body:\n");
            print_stmt(stmt->conditional_stmt.body);
            if (stmt->conditional_stmt.else_body) {
                ast_write("Else:\n");
                print_stmt(stmt->conditional_stmt.else_body);
            }
            indents--;
            break;
        case STMT_SWITCH:
            ast_write("Switch Statement:\n");
            indents++;
            ast_write("Expression:\n");
            print_expr(stmt->conditional_stmt.cond);
            ast_write("Body:\n");
            print_stmt(stmt->conditional_stmt.body);
            indents--;
            break;
        case STMT_WHILE:
            ast_write("While Loop:\n");
            indents++;
            ast_write("Condition:\n");
            print_expr(stmt->conditional_stmt.cond);
            ast_write("Body:\n");
            print_stmt(stmt->conditional_stmt.body);
            indents--;
            break;
        case STMT_DO:
            ast_write("Do-While Loop:\n");
            indents++;
            ast_write("Condition:\n");
            print_expr(stmt->conditional_stmt.cond);
            ast_write("Body:\n");
            print_stmt(stmt->conditional_stmt.body);
            indents--;
            break;
        case STMT_FOR:
            ast_write("For Loop:\n");
            indents++;
            switch (stmt->for_stmt.kind) {
                case FOR_DECL:
                    ast_write("Init Declaration:\n");
                    print_decl(stmt->for_stmt.init.decl);
                    break;
                case FOR_EXPR:
                    ast_write("Init Expression:\n");
                    print_expr(stmt->for_stmt.init.expr);
                    break;
            }
            ast_write("Condition:\n");
            print_expr(stmt->for_stmt.cond);
            ast_write("Update:\n");
            print_expr(stmt->for_stmt.update);
            ast_write("Body:\n");
            print_stmt(stmt->for_stmt.body);
            indents--;
            break;
        case STMT_LABEL:
            ast_write("Labeled Statement:\n");
            indents++;
            ast_write("Label: \"%s\"\n", stmt->label_stmt.label);
            ast_write("Statement:\n");
            print_stmt(stmt->label_stmt.next);
            indents--;
            break;
        case STMT_CASE:
            ast_write("Case Statement:\n");
            indents++;
            ast_write("Case Expression:\n");
            print_expr(stmt->case_stmt.case_expr);
            ast_write("Case Result:\n");
            print_stmt(stmt->case_stmt.result);
            indents--;
            break;
        case STMT_DEFAULT:
            ast_write("Default Statement:\n");
            indents++;
            ast_write("Default Result:\n");
            print_stmt(stmt->default_stmt.result);
            indents--;
            break;
        case STMT_GOTO:
            ast_write("Goto \"%s\" Statement:\n", stmt->goto_stmt.label);
            break;
        case STMT_CONTINUE:
            ast_write("continue\n");
            break;
        case STMT_BREAK:
            ast_write("break\n");
            break;
        case STMT_RETURN:
            if (stmt->return_stmt.result) {
                ast_write("Return:\n");
                print_expr(stmt->return_stmt.result);
            } else {
                ast_write("Return: None\n");
            }
            break;
    }

    indents--;
}

static void print_block_list(block_list *block) {
    indents++;

    for (block_list *curr = block; curr; curr = curr->next) {
        switch (curr->kind) {
            case BI_DECL:
                ast_write("Declaration:\n");
                print_decl(curr->decl);
                break;
            case BI_STMT:
                ast_write("Statement:\n");
                print_stmt(curr->stmt);
                break;
        }
    }

    indents--;
}

static void print_expr(expr *expr) {
    indents++;

    switch (expr->kind) {
        case EXPR_ID:
            ast_write("Identifier: \"%s\"\n", expr->extra.id);
            break;
        case EXPR_CONST:
            ast_write("Constant: \"%s\"\n", expr->extra.const_val->value);
            break;
        case EXPR_STR_LITERAL:
            ast_write("String: \"%s\"\n", expr->extra.str_val);
            break;

        unary_expr_case(EXPR_POST_INCR, "Postfix Increment\n")
        unary_expr_case(EXPR_POST_DECR, "Postfix Decrement\n")
        unary_expr_case(EXPR_PRE_INCR, "Prefix Increment\n")
        unary_expr_case(EXPR_PRE_DECR, "Prefix Decrement\n")
        unary_expr_case(EXPR_ADDREF, "Address of\n")
        unary_expr_case(EXPR_DEREF, "Dereference\n")
        unary_expr_case(EXPR_MINUS, "Minus\n")
        unary_expr_case(EXPR_BITNOT, "Bitwise Not\n")
        unary_expr_case(EXPR_LOGNOT, "Logical Not\n")
        unary_expr_case(EXPR_SIZEOF_EXPR, "Sizeof:\n")

        bin_expr_case(EXPR_MUL, "Multiplication\n")
        bin_expr_case(EXPR_DIV, "Division\n")
        bin_expr_case(EXPR_MOD, "Modulus\n")
        bin_expr_case(EXPR_ADD, "Addition\n")
        bin_expr_case(EXPR_SUB, "Addition\n")
        bin_expr_case(EXPR_LSHIFT, "Left-Shift\n")
        bin_expr_case(EXPR_RSHIFT, "Right-Shift\n")
        bin_expr_case(EXPR_LT, "Less Than\n")
        bin_expr_case(EXPR_GT, "Greater Than\n")
        bin_expr_case(EXPR_LEQ, "Less Than or Equal to\n")
        bin_expr_case(EXPR_GEQ, "Greater Than or Equal to\n")
        bin_expr_case(EXPR_EQ, "Equals\n")
        bin_expr_case(EXPR_NEQ, "Not Equal\n")
        bin_expr_case(EXPR_BITAND, "Bitwise And\n")
        bin_expr_case(EXPR_BITXOR, "Bitwise XOR\n")
        bin_expr_case(EXPR_BITOR, "Bitwise Or\n")
        bin_expr_case(EXPR_LOGAND, "Logical And\n")
        bin_expr_case(EXPR_LOGOR, "Logical Or\n")

        assignment_expr_case(EXPR_ASSIGN, "Assignment\n")

        case EXPR_CALL:
            ast_write("Function Call\n");
            ast_write("Function:\n");
            print_expr(expr->left);
            if (expr->right) {
                ast_write("Arguments:\n");
                print_expr(expr->right);
            } else {
                ast_write("Arguments: None\n");
            }
            break;
        case EXPR_SUBSCRIPT:
            ast_write("Array Access\n");
            ast_write("Array:\n");
            print_expr(expr->left);
            ast_write("Index:\n");
            print_expr(expr->right);
            break;
        case EXPR_MEMBER_DOT:
            ast_write("Member Access\n");
            ast_write("Item:\n");
            print_expr(expr->left);
            ast_write("Member: \"%s\"\n", expr->extra.id);
            break;
        case EXPR_MEMBER_ARROW:
            ast_write("Pointer Member Access\n");
            ast_write("Item:\n");
            print_expr(expr->left);
            ast_write("Member: \"%s\"\n", expr->extra.id);
            break;
        case EXPR_INIT_LIST:
            ast_write("Initializer List\n");
            ast_write("Type:\n");
            print_type_name(expr->extra.type);
            ast_write("List:\n");
            print_init_list(expr->extra.init);
            break;
        case EXPR_ARG:
            ast_write("Argument List:\n");
            print_arg_list(expr);
            break;
        case EXPR_SIZEOF_TYPE:
            ast_write("Sizeof:\n");
            print_type_name(expr->extra.type);
            break;
        case EXPR_CAST:
            ast_write("Cast Expression\n");
            ast_write("Type:\n");
            print_type_name(expr->extra.type);
            ast_write("Expression:\n");
            print_expr(expr->left);
            break;
        case EXPR_CONDITIONAL:
            ast_write("Ternary Expression\n");
            ast_write("Condition:\n");
            print_expr(expr->extra.conditional);
            ast_write("First:\n");
            print_expr(expr->left);
            ast_write("Second:\n");
            print_expr(expr->right);
            break;
    }

    fflush(file);

    indents--;
}

static void print_type_name(type_name *type) {
    indents++;

    ast_write("Specifiers:\n");
    print_decl_specs(type->specs);
    ast_write("Abstract Declarator:\n");
    print_decltr(type->suffix);

    indents--;
}

static void print_init_list(init_list *list) {
    indents++;

    for (init_list *curr = list; curr; curr = curr->next) {
        ast_write("Initializer:\n");
        print_initializer(curr->init);
    }

    indents--;
}

// Note: trusts that the given expression is an argument expression
static void print_arg_list(expr *arg_expr) {
    indents++;

    for (expr *curr = arg_expr; curr; curr = curr->right) {
        ast_write("Expression:\n");
        print_expr(curr->left);
    }

    indents--;
}