/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 141 "bison/parser.yacc"

    #include "ast.h"

#line 53 "parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFAULT = 258,                 /* DEFAULT  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    SWITCH = 261,                  /* SWITCH  */
    CASE = 262,                    /* CASE  */
    WHILE = 263,                   /* WHILE  */
    DO = 264,                      /* DO  */
    FOR = 265,                     /* FOR  */
    GOTO = 266,                    /* GOTO  */
    CONTINUE = 267,                /* CONTINUE  */
    BREAK = 268,                   /* BREAK  */
    RETURN = 269,                  /* RETURN  */
    TYPEDEF = 270,                 /* TYPEDEF  */
    EXTERN = 271,                  /* EXTERN  */
    STATIC = 272,                  /* STATIC  */
    AUTO = 273,                    /* AUTO  */
    REGISTER = 274,                /* REGISTER  */
    INLINE = 275,                  /* INLINE  */
    ENUM = 276,                    /* ENUM  */
    STRUCT = 277,                  /* STRUCT  */
    UNION = 278,                   /* UNION  */
    PRINT = 279,                   /* PRINT  */
    MALLOC = 280,                  /* MALLOC  */
    FREE = 281,                    /* FREE  */
    CHAR = 282,                    /* CHAR  */
    INT = 283,                     /* INT  */
    SHORT = 284,                   /* SHORT  */
    LONG = 285,                    /* LONG  */
    FLOAT = 286,                   /* FLOAT  */
    DOUBLE = 287,                  /* DOUBLE  */
    BOOL = 288,                    /* BOOL  */
    VOID = 289,                    /* VOID  */
    SIGNED = 290,                  /* SIGNED  */
    UNSIGNED = 291,                /* UNSIGNED  */
    CONST = 292,                   /* CONST  */
    RESTRICT = 293,                /* RESTRICT  */
    VOLATILE = 294,                /* VOLATILE  */
    ADD_ASSIGN = 295,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 296,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 297,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 298,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 299,              /* MOD_ASSIGN  */
    AND_ASSIGN = 300,              /* AND_ASSIGN  */
    OR_ASSIGN = 301,               /* OR_ASSIGN  */
    XOR_ASSIGN = 302,              /* XOR_ASSIGN  */
    LSHIFT_ASSIGN = 303,           /* LSHIFT_ASSIGN  */
    RSHIFT_ASSIGN = 304,           /* RSHIFT_ASSIGN  */
    INCREMENT = 305,               /* INCREMENT  */
    DECREMENT = 306,               /* DECREMENT  */
    AND = 307,                     /* AND  */
    OR = 308,                      /* OR  */
    LSHIFT = 309,                  /* LSHIFT  */
    RSHIFT = 310,                  /* RSHIFT  */
    EQUAL = 311,                   /* EQUAL  */
    NOT_EQUAL = 312,               /* NOT_EQUAL  */
    LEQ = 313,                     /* LEQ  */
    GEQ = 314,                     /* GEQ  */
    ARROW = 315,                   /* ARROW  */
    ELLIPSIS = 316,                /* ELLIPSIS  */
    IDENTIFIER = 317,              /* IDENTIFIER  */
    TYPEDEF_NAME = 318,            /* TYPEDEF_NAME  */
    ENUM_CONST = 319,              /* ENUM_CONST  */
    CONST_CHAR = 320,              /* CONST_CHAR  */
    CONST_SHORT = 321,             /* CONST_SHORT  */
    CONST_INT = 322,               /* CONST_INT  */
    CONST_LONG = 323,              /* CONST_LONG  */
    CONST_FLOAT = 324,             /* CONST_FLOAT  */
    CONST_DOUBLE = 325,            /* CONST_DOUBLE  */
    CONST_PTR = 326,               /* CONST_PTR  */
    STR_LITERAL = 327,             /* STR_LITERAL  */
    FUNC_NAME = 328,               /* FUNC_NAME  */
    SIZEOF = 329,                  /* SIZEOF  */
    NO_ELSE = 330                  /* NO_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "bison/parser.yacc"

    char *sval;
    int int_val;
    expr *expr;
    constant *constant;
    decl *decl;
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
    type_name *type_name;
    stmt *stmt;
    block_list *block_list;
    translation_unit *translation_unit;
    ext_decl *ext_decl;
    func_def *func_def;

#line 173 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
