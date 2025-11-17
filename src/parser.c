/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison/parser.yacc"

#include <stdio.h>
#include "parser_symbols.h"
#include "parser_helpers.h"
#include "ast.h"
#include "error_handling.h"

translation_unit *ast_root;

int yylex(void);

void yyerror(const char *s) {
	push_error(s);
}


#line 88 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFAULT = 3,                    /* DEFAULT  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_SWITCH = 6,                     /* SWITCH  */
  YYSYMBOL_CASE = 7,                       /* CASE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_DO = 9,                         /* DO  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_GOTO = 11,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_TYPEDEF = 15,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 16,                    /* EXTERN  */
  YYSYMBOL_STATIC = 17,                    /* STATIC  */
  YYSYMBOL_AUTO = 18,                      /* AUTO  */
  YYSYMBOL_REGISTER = 19,                  /* REGISTER  */
  YYSYMBOL_INLINE = 20,                    /* INLINE  */
  YYSYMBOL_ENUM = 21,                      /* ENUM  */
  YYSYMBOL_STRUCT = 22,                    /* STRUCT  */
  YYSYMBOL_UNION = 23,                     /* UNION  */
  YYSYMBOL_PRINT = 24,                     /* PRINT  */
  YYSYMBOL_MALLOC = 25,                    /* MALLOC  */
  YYSYMBOL_FREE = 26,                      /* FREE  */
  YYSYMBOL_CHAR = 27,                      /* CHAR  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_SHORT = 29,                     /* SHORT  */
  YYSYMBOL_LONG = 30,                      /* LONG  */
  YYSYMBOL_FLOAT = 31,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 32,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 33,                      /* BOOL  */
  YYSYMBOL_VOID = 34,                      /* VOID  */
  YYSYMBOL_SIGNED = 35,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 36,                  /* UNSIGNED  */
  YYSYMBOL_CONST = 37,                     /* CONST  */
  YYSYMBOL_RESTRICT = 38,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 39,                  /* VOLATILE  */
  YYSYMBOL_ADD_ASSIGN = 40,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 41,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 42,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 43,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 44,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 45,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 46,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 47,                /* XOR_ASSIGN  */
  YYSYMBOL_LSHIFT_ASSIGN = 48,             /* LSHIFT_ASSIGN  */
  YYSYMBOL_RSHIFT_ASSIGN = 49,             /* RSHIFT_ASSIGN  */
  YYSYMBOL_INCREMENT = 50,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 51,                 /* DECREMENT  */
  YYSYMBOL_AND = 52,                       /* AND  */
  YYSYMBOL_OR = 53,                        /* OR  */
  YYSYMBOL_LSHIFT = 54,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 55,                    /* RSHIFT  */
  YYSYMBOL_EQUAL = 56,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 57,                 /* NOT_EQUAL  */
  YYSYMBOL_LEQ = 58,                       /* LEQ  */
  YYSYMBOL_GEQ = 59,                       /* GEQ  */
  YYSYMBOL_ARROW = 60,                     /* ARROW  */
  YYSYMBOL_ELLIPSIS = 61,                  /* ELLIPSIS  */
  YYSYMBOL_IDENTIFIER = 62,                /* IDENTIFIER  */
  YYSYMBOL_TYPEDEF_NAME = 63,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUM_CONST = 64,                /* ENUM_CONST  */
  YYSYMBOL_CONST_CHAR = 65,                /* CONST_CHAR  */
  YYSYMBOL_CONST_SHORT = 66,               /* CONST_SHORT  */
  YYSYMBOL_CONST_INT = 67,                 /* CONST_INT  */
  YYSYMBOL_CONST_LONG = 68,                /* CONST_LONG  */
  YYSYMBOL_CONST_FLOAT = 69,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_DOUBLE = 70,              /* CONST_DOUBLE  */
  YYSYMBOL_CONST_PTR = 71,                 /* CONST_PTR  */
  YYSYMBOL_STR_LITERAL = 72,               /* STR_LITERAL  */
  YYSYMBOL_FUNC_NAME = 73,                 /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 74,                    /* SIZEOF  */
  YYSYMBOL_NO_ELSE = 75,                   /* NO_ELSE  */
  YYSYMBOL_76_ = 76,                       /* '('  */
  YYSYMBOL_77_ = 77,                       /* ')'  */
  YYSYMBOL_78_ = 78,                       /* '['  */
  YYSYMBOL_79_ = 79,                       /* ']'  */
  YYSYMBOL_80_ = 80,                       /* '.'  */
  YYSYMBOL_81_ = 81,                       /* '{'  */
  YYSYMBOL_82_ = 82,                       /* '}'  */
  YYSYMBOL_83_ = 83,                       /* ','  */
  YYSYMBOL_84_ = 84,                       /* '&'  */
  YYSYMBOL_85_ = 85,                       /* '*'  */
  YYSYMBOL_86_ = 86,                       /* '-'  */
  YYSYMBOL_87_ = 87,                       /* '~'  */
  YYSYMBOL_88_ = 88,                       /* '!'  */
  YYSYMBOL_89_ = 89,                       /* '/'  */
  YYSYMBOL_90_ = 90,                       /* '%'  */
  YYSYMBOL_91_ = 91,                       /* '+'  */
  YYSYMBOL_92_ = 92,                       /* '<'  */
  YYSYMBOL_93_ = 93,                       /* '>'  */
  YYSYMBOL_94_ = 94,                       /* '^'  */
  YYSYMBOL_95_ = 95,                       /* '|'  */
  YYSYMBOL_96_ = 96,                       /* '?'  */
  YYSYMBOL_97_ = 97,                       /* ':'  */
  YYSYMBOL_98_ = 98,                       /* '='  */
  YYSYMBOL_99_ = 99,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 100,                 /* $accept  */
  YYSYMBOL_primary_expression = 101,       /* primary_expression  */
  YYSYMBOL_constant = 102,                 /* constant  */
  YYSYMBOL_string = 103,                   /* string  */
  YYSYMBOL_postfix_expression = 104,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 105, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 106,         /* unary_expression  */
  YYSYMBOL_unary_operator = 107,           /* unary_operator  */
  YYSYMBOL_cast_expression = 108,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 109, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 110,      /* additive_expression  */
  YYSYMBOL_shift_expression = 111,         /* shift_expression  */
  YYSYMBOL_relational_expression = 112,    /* relational_expression  */
  YYSYMBOL_equality_expression = 113,      /* equality_expression  */
  YYSYMBOL_and_expression = 114,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 115,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 116,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 117,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 118,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 119,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 120,    /* assignment_expression  */
  YYSYMBOL_compound_assignment = 121,      /* compound_assignment  */
  YYSYMBOL_expression = 122,               /* expression  */
  YYSYMBOL_constant_expression = 123,      /* constant_expression  */
  YYSYMBOL_declaration = 124,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 125,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 126,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 127,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 128,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 129,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 130, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 131,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 132,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 133,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 134, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 135,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 136,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 137,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 138,          /* enumerator_list  */
  YYSYMBOL_enumerator = 139,               /* enumerator  */
  YYSYMBOL_enumeration_constant = 140,     /* enumeration_constant  */
  YYSYMBOL_type_qualifier = 141,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 142,       /* function_specifier  */
  YYSYMBOL_declarator = 143,               /* declarator  */
  YYSYMBOL_direct_declarator = 144,        /* direct_declarator  */
  YYSYMBOL_pointer = 145,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 146,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 147,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 148,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 149,    /* parameter_declaration  */
  YYSYMBOL_type_name = 150,                /* type_name  */
  YYSYMBOL_abstract_declarator = 151,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 152, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 153,              /* initializer  */
  YYSYMBOL_initializer_list = 154,         /* initializer_list  */
  YYSYMBOL_statement = 155,                /* statement  */
  YYSYMBOL_labeled_statement = 156,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 157,       /* compound_statement  */
  YYSYMBOL_158_1 = 158,                    /* $@1  */
  YYSYMBOL_block_item_list = 159,          /* block_item_list  */
  YYSYMBOL_block_item = 160,               /* block_item  */
  YYSYMBOL_expression_statement = 161,     /* expression_statement  */
  YYSYMBOL_selection_statement = 162,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 163,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 164,           /* jump_statement  */
  YYSYMBOL_print_statement = 165,          /* print_statement  */
  YYSYMBOL_free_statement = 166,           /* free_statement  */
  YYSYMBOL_translation_unit = 167,         /* translation_unit  */
  YYSYMBOL_external_declaration = 168,     /* external_declaration  */
  YYSYMBOL_function_definition = 169,      /* function_definition  */
  YYSYMBOL_170_2 = 170                     /* $@2  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1477

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,     2,     2,     2,    90,    84,     2,
      76,    77,    85,    91,    83,    86,    80,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    97,    99,
      92,    98,    93,    96,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,    94,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,    95,    82,    87,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   154,   155,   156,   160,   161,   162,   163,
     166,   167,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   183,   184,   188,   189,   190,   191,   192,   193,
     194,   198,   199,   200,   201,   202,   206,   207,   211,   212,
     213,   214,   218,   219,   220,   224,   225,   226,   230,   231,
     232,   233,   234,   238,   239,   240,   244,   245,   249,   250,
     254,   255,   259,   260,   264,   265,   269,   270,   274,   275,
     276,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   293,   297,   301,   302,   310,   311,   312,   313,   314,
     315,   316,   317,   321,   322,   326,   327,   331,   332,   333,
     334,   335,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   355,   356,   357,   361,   362,
     366,   367,   371,   375,   376,   377,   378,   382,   383,   387,
     388,   389,   393,   394,   395,   396,   397,   401,   402,   406,
     407,   411,   414,   415,   416,   420,   426,   427,   432,   433,
     434,   435,   436,   437,   438,   439,   443,   444,   445,   446,
     450,   451,   456,   460,   461,   465,   466,   467,   471,   472,
     476,   477,   478,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   494,   495,   496,   500,   501,   505,   506,   507,
     508,   509,   510,   511,   512,   516,   517,   518,   522,   523,
     523,   529,   530,   534,   535,   539,   540,   544,   545,   546,
     550,   551,   552,   553,   554,   555,   559,   560,   561,   562,
     563,   567,   568,   572,   576,   577,   581,   582,   586,   586
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFAULT", "IF",
  "ELSE", "SWITCH", "CASE", "WHILE", "DO", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "INLINE", "ENUM", "STRUCT", "UNION", "PRINT", "MALLOC", "FREE", "CHAR",
  "INT", "SHORT", "LONG", "FLOAT", "DOUBLE", "BOOL", "VOID", "SIGNED",
  "UNSIGNED", "CONST", "RESTRICT", "VOLATILE", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "OR_ASSIGN",
  "XOR_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "INCREMENT", "DECREMENT",
  "AND", "OR", "LSHIFT", "RSHIFT", "EQUAL", "NOT_EQUAL", "LEQ", "GEQ",
  "ARROW", "ELLIPSIS", "IDENTIFIER", "TYPEDEF_NAME", "ENUM_CONST",
  "CONST_CHAR", "CONST_SHORT", "CONST_INT", "CONST_LONG", "CONST_FLOAT",
  "CONST_DOUBLE", "CONST_PTR", "STR_LITERAL", "FUNC_NAME", "SIZEOF",
  "NO_ELSE", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'",
  "'*'", "'-'", "'~'", "'!'", "'/'", "'%'", "'+'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "'='", "';'", "$accept", "primary_expression",
  "constant", "string", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "compound_assignment",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "enumeration_constant", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "$@1", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "print_statement", "free_statement",
  "translation_unit", "external_declaration", "function_definition", "$@2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-254)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-229)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1414,  -254,  -254,  -254,  -254,  -254,  -254,   -45,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,    83,  1414,  1414,  -254,   -22,
    -254,  1414,  1414,   822,  -254,  -254,   -67,   -16,  -254,    32,
     -14,  -254,    71,  -254,    12,   -25,    99,  -254,  -254,    69,
     676,  -254,  -254,  -254,  -254,   -16,  -254,   120,  -254,    81,
     106,  -254,  -254,   -14,    32,  -254,   962,   110,  1283,   837,
     -25,   676,   676,  1340,  -254,   -27,   676,   140,  -254,   -15,
    1155,  -254,  -254,  -254,  -254,    91,   123,  1182,  1182,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  1209,   747,   962,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,   -12,   426,  1155,
    -254,    63,    -9,   170,     4,   213,   112,   126,   109,   174,
     -44,  -254,  -254,  -254,   147,  -254,  -254,     7,   155,   152,
    -254,  -254,  -254,  -254,   160,   880,  1377,  -254,  -254,  -254,
    1155,    79,  -254,   149,  -254,  -254,    -7,  -254,  -254,  -254,
    1155,   747,  -254,  -254,   747,  -254,  -254,   173,    35,   176,
    -254,   196,  -254,  -254,   193,   989,  1155,   195,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  1155,  1155,
    -254,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
    -254,   414,   657,  1017,  -254,    95,  -254,    40,  -254,  1414,
    -254,  -254,   183,  -254,  -254,   -27,  -254,  1155,  -254,   190,
     199,   207,  -254,   728,    98,  -254,  1044,  -254,   907,  -254,
    -254,    66,  -254,   212,  -254,  -254,  -254,  -254,  -254,  -254,
      63,    63,    -9,    -9,   170,   170,   170,   170,     4,     4,
     213,   112,   126,   109,   174,   205,   206,   217,   228,  1155,
     229,   508,   232,   247,   211,   214,   187,   235,   236,   218,
    -254,   219,  -254,    83,  -254,  -254,  -254,   320,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,   239,   240,  -254,   241,
      40,  1320,  1072,  -254,  -254,  -254,  -254,  -254,   238,   238,
     962,  -254,  -254,  -254,  -254,  1155,  -254,  1155,   508,  1155,
    1155,   224,  1155,   352,   583,   262,  -254,  -254,  -254,   263,
     223,  1155,   508,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
     286,  -254,   285,   198,  -254,  -254,  -254,   288,   289,   508,
     290,   292,   479,   479,  -254,  -254,   295,   130,   296,  -254,
    -254,  -254,  -254,   935,   508,   508,  -254,   508,  1155,  1099,
    1127,   270,   307,   276,  -254,   371,  -254,  -254,   300,   508,
     301,   508,   302,  -254,   303,  -254,   508,   282,  -254,   508,
    -254,   508,   287,  -254,  -254,  -254,  -254,  -254
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    98,    99,   100,   101,   145,     0,   118,   119,
     103,   105,   104,   106,   107,   108,   111,   102,   109,   110,
     142,   143,   144,   114,   227,     0,    85,    87,   112,     0,
     113,    89,    91,     0,   224,   226,   136,     0,   148,     0,
     156,    83,     0,    93,    95,   147,     0,    86,    88,   117,
       0,    90,    92,     1,   225,     0,   141,     0,   137,   139,
       0,   160,   158,   157,     0,    84,     0,     0,     0,     0,
     146,     0,   124,     0,   120,     0,   126,     0,   132,     0,
       0,   149,   161,   159,    94,    95,     0,     0,     0,     2,
       9,     6,     7,     8,    10,    11,     0,     0,     0,    31,
      32,    33,    34,    35,    12,     3,     4,    24,    36,     0,
      38,    42,    45,    48,    53,    56,    58,    60,    62,    64,
      66,    68,   182,    96,   199,   229,   155,   167,     0,   162,
     163,   153,    36,    82,     0,     0,     0,   123,   116,   121,
       0,     0,   127,   129,   125,   133,     0,   134,   138,   140,
       0,     0,    25,    26,     0,    28,    81,     0,   168,     0,
     185,     0,    18,    19,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,     0,   165,   170,   166,   171,   154,     0,
     152,   151,     0,   115,   130,     0,   122,     0,   135,     0,
       0,     0,     5,     0,   170,   169,     0,   183,     0,    17,
      14,     0,    22,     0,    16,    69,    70,    39,    40,    41,
      44,    43,    46,    47,    51,    52,    49,    50,    54,    55,
      57,    59,    61,    63,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
     205,     0,   203,     0,   204,   187,   188,     0,   201,   189,
     190,   191,   192,   193,   194,   178,     0,     0,   174,     0,
     172,     0,     0,   164,   150,   128,   131,    30,     0,    29,
       0,    37,   184,   186,    15,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   218,   219,     0,
       0,     0,     0,   206,   200,   202,   179,   173,   175,   180,
       0,   176,     0,     0,    23,    67,   197,     0,     0,     0,
       0,     0,     0,     0,   216,   220,    10,     0,     0,   195,
     181,   177,    20,     0,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,    21,   207,   209,   210,     0,     0,
       0,     0,     0,   221,     0,   223,     0,     0,   214,     0,
     212,     0,     0,   208,   211,   215,   213,   222
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -254,  -254,  -254,  -254,    65,  -254,   -59,  -254,   -79,   113,
      96,    -3,   108,   194,   200,   201,   202,   192,  -254,   -62,
     -64,  -254,   -94,   -61,  -193,     0,  -254,   334,  -254,    15,
    -254,  -254,   329,   -29,   -56,  -254,   188,  -254,   354,   -66,
    -254,   171,  -254,   -21,   -40,   -18,   341,   -63,  -254,   203,
    -139,  -116,  -105,   -65,   111,  -162,  -254,   346,  -254,  -254,
     137,  -253,  -254,  -254,  -254,  -254,  -254,  -254,   382,  -254,
    -254
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   104,   105,   106,   107,   231,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     156,   179,   271,   134,    24,   127,    42,    43,    26,    27,
      28,    29,    73,    74,    75,   141,   142,    30,    57,    58,
      59,    31,    32,    60,    45,    46,    63,   286,   129,   130,
     159,   287,   207,   160,   161,   274,   275,   276,   201,   277,
     278,   279,   280,   281,   282,   283,   284,    33,    34,    35,
      67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   123,   122,   157,    44,   128,    70,   133,   272,   198,
     132,   206,   220,   148,    55,   221,   137,    36,   133,   149,
     144,   132,    62,    20,    21,    22,    47,    48,   152,   153,
     180,    51,    52,    25,   122,    38,    37,   155,   162,   163,
      49,   158,   225,    85,   139,    83,    56,    56,   164,    39,
     132,    68,   199,    69,   143,    56,   219,   157,    40,    50,
     157,   343,   188,   189,   165,    72,   166,   147,   167,    38,
     140,    40,   233,   133,   212,   218,   132,   184,   133,   214,
     148,   132,   185,   202,   272,   203,    72,    72,    72,   359,
     360,    72,    40,  -228,    38,   158,   190,   191,   158,   313,
     290,   232,   237,   238,   239,   255,   204,   139,    39,   205,
      66,   223,    72,   203,   235,   236,   291,    40,   292,   290,
      40,   342,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     224,   133,   289,   304,   132,    38,   336,   301,   181,   305,
      71,    72,   182,   183,    64,   133,   296,    38,   132,    39,
     349,    38,   215,   303,   122,    70,    72,   132,    40,    72,
      65,   202,   319,   203,   223,    39,   203,   356,   216,    80,
     162,   163,    41,    81,   205,   244,   245,   246,   247,    66,
     164,   124,   365,   366,   143,   367,   194,   133,   311,   150,
     132,   273,    78,    79,   196,   224,   165,   378,   166,   380,
     167,    61,    86,   362,   383,   337,   338,   385,   340,   386,
     195,    76,   145,   146,   186,   187,   197,   348,   330,   200,
     133,   332,   208,   132,    82,   209,   122,    87,    88,   210,
      61,   334,    76,    76,    76,   335,   217,    76,   132,    89,
     222,    90,    85,   226,    91,   229,    92,   234,    93,    94,
      95,    96,   294,    97,   368,   370,   372,   297,    76,   192,
     193,    99,   100,   101,   102,   103,   298,   273,   227,   228,
     352,   353,   242,   243,   299,    89,   318,    90,   303,   122,
      91,   306,    92,   309,    93,   346,    95,   240,   241,   151,
     248,   249,   307,   308,   310,   312,    82,    76,   314,   315,
     316,   320,   321,   317,   273,   322,   326,   327,   323,   300,
     328,   339,    76,   256,   257,    76,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     1,     2,     3,     4,     5,
       6,     7,     8,     9,   267,    86,   268,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     341,   344,   345,   350,   351,   354,   355,   357,   358,   373,
      87,    88,   361,   363,   374,   375,   376,   377,   379,   381,
     382,   384,   269,    23,    90,   347,   387,    91,   250,    92,
     254,    93,    94,    95,    96,   251,    97,   252,    84,   253,
     136,   124,   324,   295,    99,   100,   101,   102,   103,    77,
     135,   333,   293,   125,   325,    54,     0,   256,   257,   270,
     258,   259,   260,   261,   262,   263,   264,   265,   266,     1,
       2,     3,     4,     5,     6,     7,     8,     9,   267,    86,
     268,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   269,    23,    90,     0,
       0,    91,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,     0,   124,     0,     0,    99,   100,
     101,   102,   103,     0,    86,     0,     0,     0,     0,     0,
       0,   256,   257,   270,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,   178,     0,     0,     0,     0,    87,
      88,     0,   267,    86,   268,     0,     0,     0,     0,     0,
       0,    89,     0,    90,     0,     0,    91,     0,    92,     0,
      93,    94,    95,    96,     0,    97,     0,     0,    87,    88,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
     269,     0,    90,     0,     0,    91,     0,    92,   270,    93,
      94,    95,    96,     0,    97,     0,     0,     0,     0,   124,
       0,     0,    99,   100,   101,   102,   103,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,   270,    86,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    23,    90,     0,     0,
      91,     0,    92,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,   270,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     7,     8,     9,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,    38,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   285,   203,     0,     0,     0,    23,
       0,     0,    40,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     7,     8,
       9,     0,    86,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,    87,    88,     0,
       0,     0,     0,     0,   223,   285,   203,     0,     0,    89,
      23,    90,     0,    40,    91,     0,    92,     0,    93,    94,
      95,    96,    53,    97,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,    90,     0,     0,    91,    86,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,   131,    20,    21,    22,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
      87,    88,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,    90,     0,     0,    91,     0,    92,
       0,    93,    94,    95,    96,     0,    97,    87,    88,   211,
      86,     0,     0,     0,    99,   100,   101,   102,   103,    89,
       0,    90,     0,     0,    91,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,    87,    88,    86,    98,   302,
       0,    99,   100,   101,   102,   103,     0,    89,     0,    90,
       0,     0,    91,     0,    92,     0,    93,    94,    95,    96,
       0,    97,    87,    88,    86,     0,    98,   364,     0,    99,
     100,   101,   102,   103,    89,     0,    90,     0,     0,    91,
       0,    92,     0,    93,    94,    95,    96,     0,    97,    87,
      88,     0,    86,    98,     0,     0,    99,   100,   101,   102,
     103,    89,     0,    90,     0,     0,    91,     0,    92,     0,
      93,    94,    95,    96,     0,    97,   230,    87,    88,    86,
       0,     0,     0,    99,   100,   101,   102,   103,     0,    89,
       0,    90,     0,     0,    91,     0,    92,     0,    93,    94,
      95,    96,     0,    97,    87,    88,   288,    86,     0,     0,
       0,    99,   100,   101,   102,   103,    89,     0,    90,     0,
       0,    91,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,    87,    88,    86,   300,     0,     0,    99,   100,
     101,   102,   103,     0,    89,     0,    90,     0,     0,    91,
       0,    92,     0,    93,    94,    95,    96,     0,    97,    87,
      88,   331,    86,     0,     0,     0,    99,   100,   101,   102,
     103,    89,     0,    90,     0,     0,    91,     0,    92,     0,
      93,    94,    95,    96,     0,    97,   369,    87,    88,     0,
      86,     0,     0,    99,   100,   101,   102,   103,     0,    89,
       0,    90,     0,     0,    91,     0,    92,     0,    93,    94,
      95,    96,     0,    97,   371,    87,    88,    86,     0,     0,
       0,    99,   100,   101,   102,   103,     0,    89,     0,    90,
       0,     0,    91,     0,    92,     0,    93,    94,    95,    96,
       0,    97,    87,    88,    86,     0,     0,     0,     0,    99,
     100,   101,   102,   103,    89,     0,    90,     0,     0,    91,
       0,    92,     0,    93,    94,    95,    96,     0,   151,    87,
      88,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,    89,     0,    90,     0,     0,    91,     0,    92,     0,
      93,    94,    95,    96,     0,   154,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,    23,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     126,     7,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,     7,     8,
       9,     0,     0,    23,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      23,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       0,    66,    66,    97,    25,    68,    46,    69,   201,    53,
      69,   127,   151,    79,    81,   154,    72,    62,    80,    80,
      76,    80,    40,    37,    38,    39,    26,    27,    87,    88,
     109,    31,    32,    33,    98,    62,    81,    96,    50,    51,
      62,    97,   158,    64,    73,    63,    62,    62,    60,    76,
     109,    76,    96,    78,    75,    62,   150,   151,    85,    81,
     154,   314,    58,    59,    76,    50,    78,    82,    80,    62,
      97,    85,   166,   135,   135,    82,   135,    86,   140,   140,
     146,   140,    91,    76,   277,    78,    71,    72,    73,   342,
     343,    76,    85,    81,    62,   151,    92,    93,   154,   261,
     205,   165,   181,   182,   183,   199,   127,   136,    76,   127,
      98,    76,    97,    78,   178,   179,    76,    85,    78,   224,
      85,   314,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     158,   203,   203,    77,   203,    62,   308,   226,    85,    83,
      81,   136,    89,    90,    83,   217,   217,    62,   217,    76,
     322,    62,    83,   228,   228,   205,   151,   226,    85,   154,
      99,    76,   266,    78,    76,    76,    78,   339,    99,    98,
      50,    51,    99,    77,   202,   188,   189,   190,   191,    98,
      60,    81,   354,   355,   215,   357,    84,   259,   259,    76,
     259,   201,    82,    83,    95,   223,    76,   369,    78,   371,
      80,    40,    25,    83,   376,   309,   310,   379,   312,   381,
      94,    50,    82,    83,    54,    55,    52,   321,   291,    82,
     292,   292,    77,   292,    63,    83,   300,    50,    51,    79,
      69,   305,    71,    72,    73,   307,    97,    76,   307,    62,
      77,    64,   273,    77,    67,    62,    69,    62,    71,    72,
      73,    74,    79,    76,   358,   359,   360,    77,    97,    56,
      57,    84,    85,    86,    87,    88,    77,   277,    82,    83,
      82,    83,   186,   187,    77,    62,    99,    64,   353,   353,
      67,    79,    69,    76,    71,    72,    73,   184,   185,    76,
     192,   193,    97,    97,    76,    76,   135,   136,    76,    62,
      99,    76,    76,    99,   314,    97,    77,    77,    99,    81,
      79,    97,   151,     3,     4,   154,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       8,    99,    99,    77,    79,    77,    77,    77,    76,    99,
      50,    51,    77,    77,    67,    99,     5,    77,    77,    77,
      77,    99,    62,    63,    64,   320,    99,    67,   194,    69,
     198,    71,    72,    73,    74,   195,    76,   196,    64,   197,
      71,    81,    82,   215,    84,    85,    86,    87,    88,    55,
      69,   300,   209,    67,   277,    33,    -1,     3,     4,    99,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    62,    63,    64,    -1,
      -1,    67,    -1,    69,    -1,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    99,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    98,    -1,    -1,    -1,    -1,    50,
      51,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    74,    -1,    76,    -1,    -1,    50,    51,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      62,    -1,    64,    -1,    -1,    67,    -1,    69,    99,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    85,    86,    87,    88,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    99,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      67,    -1,    69,    -1,    71,    72,    73,    74,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    99,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    21,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,    63,
      -1,    -1,    85,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,    62,
      63,    64,    -1,    85,    67,    -1,    69,    -1,    71,    72,
      73,    74,     0,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    -1,    -1,    67,    25,    69,    -1,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    79,    37,    38,    39,
      -1,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      50,    51,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    64,    -1,    -1,    67,    -1,    69,
      -1,    71,    72,    73,    74,    -1,    76,    50,    51,    79,
      25,    -1,    -1,    -1,    84,    85,    86,    87,    88,    62,
      -1,    64,    -1,    -1,    67,    -1,    69,    -1,    71,    72,
      73,    74,    -1,    76,    -1,    50,    51,    25,    81,    82,
      -1,    84,    85,    86,    87,    88,    -1,    62,    -1,    64,
      -1,    -1,    67,    -1,    69,    -1,    71,    72,    73,    74,
      -1,    76,    50,    51,    25,    -1,    81,    82,    -1,    84,
      85,    86,    87,    88,    62,    -1,    64,    -1,    -1,    67,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    50,
      51,    -1,    25,    81,    -1,    -1,    84,    85,    86,    87,
      88,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    74,    -1,    76,    77,    50,    51,    25,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    62,
      -1,    64,    -1,    -1,    67,    -1,    69,    -1,    71,    72,
      73,    74,    -1,    76,    50,    51,    79,    25,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    62,    -1,    64,    -1,
      -1,    67,    -1,    69,    -1,    71,    72,    73,    74,    -1,
      76,    -1,    50,    51,    25,    81,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    62,    -1,    64,    -1,    -1,    67,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    50,
      51,    79,    25,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    74,    -1,    76,    77,    50,    51,    -1,
      25,    -1,    -1,    84,    85,    86,    87,    88,    -1,    62,
      -1,    64,    -1,    -1,    67,    -1,    69,    -1,    71,    72,
      73,    74,    -1,    76,    77,    50,    51,    25,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    62,    -1,    64,
      -1,    -1,    67,    -1,    69,    -1,    71,    72,    73,    74,
      -1,    76,    50,    51,    25,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    62,    -1,    64,    -1,    -1,    67,
      -1,    69,    -1,    71,    72,    73,    74,    -1,    76,    50,
      51,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    63,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      77,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    21,    22,
      23,    -1,    -1,    63,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      63,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    63,   124,   125,   128,   129,   130,   131,
     137,   141,   142,   167,   168,   169,    62,    81,    62,    76,
      85,    99,   126,   127,   143,   144,   145,   125,   125,    62,
      81,   125,   125,     0,   168,    81,    62,   138,   139,   140,
     143,   141,   145,   146,    83,    99,    98,   170,    76,    78,
     144,    81,   129,   132,   133,   134,   141,   138,    82,    83,
      98,    77,   141,   145,   127,   143,    25,    50,    51,    62,
      64,    67,    69,    71,    72,    73,    74,    76,    81,    84,
      85,    86,    87,    88,   101,   102,   103,   104,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   153,    81,   157,    77,   125,   147,   148,
     149,    79,   106,   119,   123,   146,   132,   134,    82,   133,
      97,   135,   136,   143,   134,    82,    83,    82,   139,   123,
      76,    76,   106,   106,    76,   106,   120,   122,   134,   150,
     153,   154,    50,    51,    60,    76,    78,    80,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    98,   121,
     108,    85,    89,    90,    86,    91,    54,    55,    58,    59,
      92,    93,    56,    57,    84,    94,    95,    52,    53,    96,
      82,   158,    76,    78,   143,   145,   151,   152,    77,    83,
      79,    79,   123,    82,   123,    83,    99,    97,    82,   122,
     150,   150,    77,    76,   145,   151,    77,    82,    83,    62,
      77,   105,   120,   122,    62,   120,   120,   108,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   112,   112,
     113,   114,   115,   116,   117,   122,     3,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    24,    26,    62,
      99,   122,   124,   125,   155,   156,   157,   159,   160,   161,
     162,   163,   164,   165,   166,    77,   147,   151,    79,   123,
     152,    76,    78,   149,    79,   136,   123,    77,    77,    77,
      81,   108,    82,   153,    77,    83,    79,    97,    97,    76,
      76,   123,    76,   155,    76,    62,    99,    99,    99,   122,
      76,    76,    97,    99,    82,   160,    77,    77,    79,    77,
     147,    79,   123,   154,   120,   119,   155,   122,   122,    97,
     122,     8,   124,   161,    99,    99,    72,   104,   122,   155,
      77,    79,    82,    83,    77,    77,   155,    77,    76,   161,
     161,    77,    83,    77,    82,   155,   155,   155,   122,    77,
     122,    77,   122,    99,    67,    99,     5,    77,   155,    77,
     155,    77,    77,   155,    99,   155,   155,    99
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   102,   102,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   108,   108,   109,   109,
     109,   109,   110,   110,   110,   111,   111,   111,   112,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   130,   130,   130,   131,   131,
     132,   132,   133,   134,   134,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   138,   138,   139,
     139,   140,   141,   141,   141,   142,   143,   143,   144,   144,
     144,   144,   144,   144,   144,   144,   145,   145,   145,   145,
     146,   146,   147,   148,   148,   149,   149,   149,   150,   150,
     151,   151,   151,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   153,   153,   153,   154,   154,   155,   155,   155,
     155,   155,   155,   155,   155,   156,   156,   156,   157,   158,
     157,   159,   159,   160,   160,   161,   161,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   164,   164,   164,   164,
     164,   165,   165,   166,   167,   167,   168,   168,   170,   169
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     4,
       4,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     5,     6,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       5,     4,     4,     3,     4,     3,     1,     2,     2,     3,
       1,     2,     1,     1,     3,     2,     2,     1,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     0,
       4,     1,     2,     1,     1,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     5,     7,     5,     1,     2,     1,     1,     0,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 153 "bison/parser.yacc"
                                { (yyval.expr) = make_id_expr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1762 "parser.c"
    break;

  case 3: /* primary_expression: constant  */
#line 154 "bison/parser.yacc"
                                { (yyval.expr) = make_const_expr((yyvsp[0].constant)); }
#line 1768 "parser.c"
    break;

  case 4: /* primary_expression: string  */
#line 155 "bison/parser.yacc"
                                { (yyval.expr) = make_string_expr((yyvsp[0].sval)); }
#line 1774 "parser.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 156 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1780 "parser.c"
    break;

  case 6: /* constant: CONST_INT  */
#line 160 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_INT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1786 "parser.c"
    break;

  case 7: /* constant: CONST_FLOAT  */
#line 161 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_FLOAT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1792 "parser.c"
    break;

  case 8: /* constant: CONST_PTR  */
#line 162 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_PTR, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1798 "parser.c"
    break;

  case 9: /* constant: ENUM_CONST  */
#line 163 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_ENUM, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1804 "parser.c"
    break;

  case 10: /* string: STR_LITERAL  */
#line 166 "bison/parser.yacc"
                    { (yyval.sval) = (yyvsp[0].sval); free((yyvsp[0].sval)); }
#line 1810 "parser.c"
    break;

  case 11: /* string: FUNC_NAME  */
#line 167 "bison/parser.yacc"
                    { (yyval.sval) = func_name(); }
#line 1816 "parser.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 170 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1822 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 171 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_SUBSCRIPT, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1828 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' ')'  */
#line 172 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-2].expr), 0); }
#line 1834 "parser.c"
    break;

  case 15: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 173 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1840 "parser.c"
    break;

  case 16: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 174 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_DOT, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1846 "parser.c"
    break;

  case 17: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 175 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_ARROW, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1852 "parser.c"
    break;

  case 18: /* postfix_expression: postfix_expression INCREMENT  */
#line 176 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_INCR, (yyvsp[-1].expr), 0); }
#line 1858 "parser.c"
    break;

  case 19: /* postfix_expression: postfix_expression DECREMENT  */
#line 177 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_DECR, (yyvsp[-1].expr), 0); }
#line 1864 "parser.c"
    break;

  case 20: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 178 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-4].type_name), (yyvsp[-1].init_list)); }
#line 1870 "parser.c"
    break;

  case 21: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 179 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-5].type_name), (yyvsp[-2].init_list)); }
#line 1876 "parser.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 183 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), 0); }
#line 1882 "parser.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 184 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1888 "parser.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 188 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1894 "parser.c"
    break;

  case 25: /* unary_expression: INCREMENT unary_expression  */
#line 189 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_INCR, (yyvsp[0].expr), 0); }
#line 1900 "parser.c"
    break;

  case 26: /* unary_expression: DECREMENT unary_expression  */
#line 190 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_DECR, (yyvsp[0].expr), 0); }
#line 1906 "parser.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 191 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[0].expr), 0); }
#line 1912 "parser.c"
    break;

  case 28: /* unary_expression: SIZEOF unary_expression  */
#line 192 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_SIZEOF_EXPR, (yyvsp[0].expr), 0); }
#line 1918 "parser.c"
    break;

  case 29: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 193 "bison/parser.yacc"
                                            { (yyval.expr) = make_sizeof_expr((yyvsp[-1].type_name)); }
#line 1924 "parser.c"
    break;

  case 30: /* unary_expression: MALLOC '(' expression ')'  */
#line 194 "bison/parser.yacc"
                                        { (yyval.expr) = make_expr(EXPR_MALLOC, (yyvsp[-1].expr), 0); }
#line 1930 "parser.c"
    break;

  case 31: /* unary_operator: '&'  */
#line 198 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_ADDREF; }
#line 1936 "parser.c"
    break;

  case 32: /* unary_operator: '*'  */
#line 199 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_DEREF; }
#line 1942 "parser.c"
    break;

  case 33: /* unary_operator: '-'  */
#line 200 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_MINUS; }
#line 1948 "parser.c"
    break;

  case 34: /* unary_operator: '~'  */
#line 201 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_BITNOT; }
#line 1954 "parser.c"
    break;

  case 35: /* unary_operator: '!'  */
#line 202 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_LOGNOT; }
#line 1960 "parser.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 206 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1966 "parser.c"
    break;

  case 37: /* cast_expression: '(' type_name ')' cast_expression  */
#line 207 "bison/parser.yacc"
                                            { (yyval.expr) = make_cast_expr((yyvsp[-2].type_name), (yyvsp[0].expr)); }
#line 1972 "parser.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 211 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1978 "parser.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 212 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1984 "parser.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 213 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1990 "parser.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 214 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1996 "parser.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 218 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2002 "parser.c"
    break;

  case 43: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 219 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2008 "parser.c"
    break;

  case 44: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 220 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2014 "parser.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 224 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2020 "parser.c"
    break;

  case 46: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 225 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2026 "parser.c"
    break;

  case 47: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 226 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_RSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2032 "parser.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 230 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2038 "parser.c"
    break;

  case 49: /* relational_expression: relational_expression '<' shift_expression  */
#line 231 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2044 "parser.c"
    break;

  case 50: /* relational_expression: relational_expression '>' shift_expression  */
#line 232 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2050 "parser.c"
    break;

  case 51: /* relational_expression: relational_expression LEQ shift_expression  */
#line 233 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2056 "parser.c"
    break;

  case 52: /* relational_expression: relational_expression GEQ shift_expression  */
#line 234 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2062 "parser.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 238 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2068 "parser.c"
    break;

  case 54: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 239 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2074 "parser.c"
    break;

  case 55: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 240 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2080 "parser.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 244 "bison/parser.yacc"
                                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2086 "parser.c"
    break;

  case 57: /* and_expression: and_expression '&' equality_expression  */
#line 245 "bison/parser.yacc"
                                                    { (yyval.expr) = make_expr(EXPR_BITAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2092 "parser.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 249 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2098 "parser.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 250 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_BITXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2104 "parser.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 254 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2110 "parser.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 255 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_BITOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2116 "parser.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 259 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2122 "parser.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 260 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2128 "parser.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 264 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2134 "parser.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 265 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2140 "parser.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 269 "bison/parser.yacc"
                                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2146 "parser.c"
    break;

  case 67: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 270 "bison/parser.yacc"
                                                                            { (yyval.expr) = make_ternary_expr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2152 "parser.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 274 "bison/parser.yacc"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2158 "parser.c"
    break;

  case 69: /* assignment_expression: unary_expression '=' assignment_expression  */
#line 275 "bison/parser.yacc"
                                                                        { (yyval.expr) = make_expr(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2164 "parser.c"
    break;

  case 70: /* assignment_expression: unary_expression compound_assignment assignment_expression  */
#line 276 "bison/parser.yacc"
                                                                    { (yyval.expr) = make_expr(EXPR_ASSIGN, (yyvsp[-2].expr), make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 2170 "parser.c"
    break;

  case 71: /* compound_assignment: ADD_ASSIGN  */
#line 280 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ADD; }
#line 2176 "parser.c"
    break;

  case 72: /* compound_assignment: SUB_ASSIGN  */
#line 281 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_SUB; }
#line 2182 "parser.c"
    break;

  case 73: /* compound_assignment: MUL_ASSIGN  */
#line 282 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_MUL; }
#line 2188 "parser.c"
    break;

  case 74: /* compound_assignment: DIV_ASSIGN  */
#line 283 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_DIV; }
#line 2194 "parser.c"
    break;

  case 75: /* compound_assignment: MOD_ASSIGN  */
#line 284 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_MOD; }
#line 2200 "parser.c"
    break;

  case 76: /* compound_assignment: AND_ASSIGN  */
#line 285 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_BITAND; }
#line 2206 "parser.c"
    break;

  case 77: /* compound_assignment: OR_ASSIGN  */
#line 286 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_BITOR; }
#line 2212 "parser.c"
    break;

  case 78: /* compound_assignment: XOR_ASSIGN  */
#line 287 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_BITXOR; }
#line 2218 "parser.c"
    break;

  case 79: /* compound_assignment: LSHIFT_ASSIGN  */
#line 288 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_LSHIFT; }
#line 2224 "parser.c"
    break;

  case 80: /* compound_assignment: RSHIFT_ASSIGN  */
#line 289 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_RSHIFT; }
#line 2230 "parser.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 293 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2236 "parser.c"
    break;

  case 82: /* constant_expression: conditional_expression  */
#line 297 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2242 "parser.c"
    break;

  case 83: /* declaration: declaration_specifiers ';'  */
#line 301 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), 0); }
#line 2248 "parser.c"
    break;

  case 84: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 303 "bison/parser.yacc"
    {
        (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].init_decltr));
        add_typedef_type((yyval.decl));
    }
#line 2257 "parser.c"
    break;

  case 85: /* declaration_specifiers: storage_class_specifier  */
#line 310 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class(0, (yyvsp[0].int_val)); }
#line 2263 "parser.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 311 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2269 "parser.c"
    break;

  case 87: /* declaration_specifiers: type_specifier  */
#line 312 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2275 "parser.c"
    break;

  case 88: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 313 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2281 "parser.c"
    break;

  case 89: /* declaration_specifiers: type_qualifier  */
#line 314 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2287 "parser.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 315 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2293 "parser.c"
    break;

  case 91: /* declaration_specifiers: function_specifier  */
#line 316 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec(0, (yyvsp[0].int_val)); }
#line 2299 "parser.c"
    break;

  case 92: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 317 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2305 "parser.c"
    break;

  case 93: /* init_declarator_list: init_declarator  */
#line 321 "bison/parser.yacc"
                                                    { (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2311 "parser.c"
    break;

  case 94: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 322 "bison/parser.yacc"
                                                    { add_init_decltr((yyvsp[-2].init_decltr), (yyvsp[0].init_decltr)); (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2317 "parser.c"
    break;

  case 95: /* init_declarator: declarator  */
#line 326 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[0].decltr), 0); }
#line 2323 "parser.c"
    break;

  case 96: /* init_declarator: declarator '=' initializer  */
#line 327 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[-2].decltr), (yyvsp[0].initializer)); }
#line 2329 "parser.c"
    break;

  case 97: /* storage_class_specifier: TYPEDEF  */
#line 331 "bison/parser.yacc"
                    { (yyval.int_val) = SC_TYPEDEF; }
#line 2335 "parser.c"
    break;

  case 98: /* storage_class_specifier: EXTERN  */
#line 332 "bison/parser.yacc"
                    { (yyval.int_val) = SC_EXTERN; }
#line 2341 "parser.c"
    break;

  case 99: /* storage_class_specifier: STATIC  */
#line 333 "bison/parser.yacc"
                    { (yyval.int_val) = SC_STATIC; }
#line 2347 "parser.c"
    break;

  case 100: /* storage_class_specifier: AUTO  */
#line 334 "bison/parser.yacc"
                    { (yyval.int_val) = SC_AUTO; }
#line 2353 "parser.c"
    break;

  case 101: /* storage_class_specifier: REGISTER  */
#line 335 "bison/parser.yacc"
                    { (yyval.int_val) = SC_REGISTER; }
#line 2359 "parser.c"
    break;

  case 102: /* type_specifier: VOID  */
#line 339 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_VOID); }
#line 2365 "parser.c"
    break;

  case 103: /* type_specifier: CHAR  */
#line 340 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_CHAR); }
#line 2371 "parser.c"
    break;

  case 104: /* type_specifier: SHORT  */
#line 341 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SHORT); }
#line 2377 "parser.c"
    break;

  case 105: /* type_specifier: INT  */
#line 342 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_INT); }
#line 2383 "parser.c"
    break;

  case 106: /* type_specifier: LONG  */
#line 343 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_LONG); }
#line 2389 "parser.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 344 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_FLOAT); }
#line 2395 "parser.c"
    break;

  case 108: /* type_specifier: DOUBLE  */
#line 345 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_DOUBLE); }
#line 2401 "parser.c"
    break;

  case 109: /* type_specifier: SIGNED  */
#line 346 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SIGNED); }
#line 2407 "parser.c"
    break;

  case 110: /* type_specifier: UNSIGNED  */
#line 347 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_UNSIGNED); }
#line 2413 "parser.c"
    break;

  case 111: /* type_specifier: BOOL  */
#line 348 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_BOOL); }
#line 2419 "parser.c"
    break;

  case 112: /* type_specifier: struct_or_union_specifier  */
#line 349 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_sou_type_spec((yyvsp[0].sou_spec)); }
#line 2425 "parser.c"
    break;

  case 113: /* type_specifier: enum_specifier  */
#line 350 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_enum_type_spec((yyvsp[0].enum_spec)); }
#line 2431 "parser.c"
    break;

  case 114: /* type_specifier: TYPEDEF_NAME  */
#line 351 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_typedef_type_spec((yyvsp[0].sval)); }
#line 2437 "parser.c"
    break;

  case 115: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 355 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-4].int_val), (yyvsp[-3].sval), (yyvsp[-1].struct_decl_list)); }
#line 2443 "parser.c"
    break;

  case 116: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 356 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-3].int_val), 0, (yyvsp[-1].struct_decl_list)); }
#line 2449 "parser.c"
    break;

  case 117: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 357 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-1].int_val), (yyvsp[0].sval), 0); }
#line 2455 "parser.c"
    break;

  case 118: /* struct_or_union: STRUCT  */
#line 361 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_STRUCT; }
#line 2461 "parser.c"
    break;

  case 119: /* struct_or_union: UNION  */
#line 362 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_UNION; }
#line 2467 "parser.c"
    break;

  case 120: /* struct_declaration_list: struct_declaration  */
#line 366 "bison/parser.yacc"
                                                        { (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2473 "parser.c"
    break;

  case 121: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 367 "bison/parser.yacc"
                                                        { add_struct_decl((yyvsp[-1].struct_decl_list), (yyvsp[0].struct_decl_list)); (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2479 "parser.c"
    break;

  case 122: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 371 "bison/parser.yacc"
                                                                { (yyval.struct_decl_list) = make_struct_decl_list(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].struct_decltr_list)); }
#line 2485 "parser.c"
    break;

  case 123: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 375 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2491 "parser.c"
    break;

  case 124: /* specifier_qualifier_list: type_specifier  */
#line 376 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2497 "parser.c"
    break;

  case 125: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 377 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2503 "parser.c"
    break;

  case 126: /* specifier_qualifier_list: type_qualifier  */
#line 378 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2509 "parser.c"
    break;

  case 127: /* struct_declarator_list: struct_declarator  */
#line 382 "bison/parser.yacc"
                                                        { (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2515 "parser.c"
    break;

  case 128: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 383 "bison/parser.yacc"
                                                        { add_struct_decltr((yyvsp[-2].struct_decltr_list), (yyvsp[0].struct_decltr_list)); (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2521 "parser.c"
    break;

  case 129: /* struct_declarator: declarator  */
#line 387 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[0].decltr), 0); }
#line 2527 "parser.c"
    break;

  case 130: /* struct_declarator: ':' constant_expression  */
#line 388 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list(0, (yyvsp[0].expr)); }
#line 2533 "parser.c"
    break;

  case 131: /* struct_declarator: declarator ':' constant_expression  */
#line 389 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[-2].decltr), (yyvsp[0].expr)); }
#line 2539 "parser.c"
    break;

  case 132: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 393 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-1].enumerator_list)); }
#line 2545 "parser.c"
    break;

  case 133: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 394 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-3].sval), (yyvsp[-1].enumerator_list)); }
#line 2551 "parser.c"
    break;

  case 134: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 395 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-2].enumerator_list)); }
#line 2557 "parser.c"
    break;

  case 135: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 396 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-4].sval), (yyvsp[-2].enumerator_list)); }
#line 2563 "parser.c"
    break;

  case 136: /* enum_specifier: ENUM IDENTIFIER  */
#line 397 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[0].sval), 0); }
#line 2569 "parser.c"
    break;

  case 137: /* enumerator_list: enumerator  */
#line 401 "bison/parser.yacc"
                                            { (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2575 "parser.c"
    break;

  case 138: /* enumerator_list: enumerator_list ',' enumerator  */
#line 402 "bison/parser.yacc"
                                            { add_enumerator((yyvsp[-2].enumerator_list), (yyvsp[0].enumerator_list)); (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2581 "parser.c"
    break;

  case 139: /* enumerator: enumeration_constant  */
#line 406 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[0].sval), 0); free((yyvsp[0].sval)); }
#line 2587 "parser.c"
    break;

  case 140: /* enumerator: enumeration_constant '=' constant_expression  */
#line 407 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[-2].sval), (yyvsp[0].expr)); free((yyvsp[-2].sval)); }
#line 2593 "parser.c"
    break;

  case 141: /* enumeration_constant: IDENTIFIER  */
#line 411 "bison/parser.yacc"
                    { sym_define_enum((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); }
#line 2599 "parser.c"
    break;

  case 142: /* type_qualifier: CONST  */
#line 414 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_CONST; }
#line 2605 "parser.c"
    break;

  case 143: /* type_qualifier: RESTRICT  */
#line 415 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_RESTRICT; }
#line 2611 "parser.c"
    break;

  case 144: /* type_qualifier: VOLATILE  */
#line 416 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_VOLATILE; }
#line 2617 "parser.c"
    break;

  case 145: /* function_specifier: INLINE  */
#line 420 "bison/parser.yacc"
                    { (yyval.int_val) = FS_INLINE; }
#line 2623 "parser.c"
    break;

  case 146: /* declarator: pointer direct_declarator  */
#line 426 "bison/parser.yacc"
                                    { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); (yyval.decltr) = (yyvsp[0].decltr); }
#line 2629 "parser.c"
    break;

  case 147: /* declarator: direct_declarator  */
#line 427 "bison/parser.yacc"
                                    { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2635 "parser.c"
    break;

  case 148: /* direct_declarator: IDENTIFIER  */
#line 432 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_id_decltr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2641 "parser.c"
    break;

  case 149: /* direct_declarator: '(' declarator ')'  */
#line 433 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2647 "parser.c"
    break;

  case 150: /* direct_declarator: direct_declarator '[' type_qualifier_list constant_expression ']'  */
#line 434 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr)); }
#line 2653 "parser.c"
    break;

  case 151: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 435 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), (yyvsp[-1].type_qual_list), 0); }
#line 2659 "parser.c"
    break;

  case 152: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 436 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2665 "parser.c"
    break;

  case 153: /* direct_declarator: direct_declarator '[' ']'  */
#line 437 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2671 "parser.c"
    break;

  case 154: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 438 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2677 "parser.c"
    break;

  case 155: /* direct_declarator: direct_declarator '(' ')'  */
#line 439 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2683 "parser.c"
    break;

  case 156: /* pointer: '*'  */
#line 443 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, 0); }
#line 2689 "parser.c"
    break;

  case 157: /* pointer: '*' type_qualifier_list  */
#line 444 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[0].type_qual_list), 0); }
#line 2695 "parser.c"
    break;

  case 158: /* pointer: '*' pointer  */
#line 445 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, (yyvsp[0].pointer)); }
#line 2701 "parser.c"
    break;

  case 159: /* pointer: '*' type_qualifier_list pointer  */
#line 446 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[-1].type_qual_list), (yyvsp[0].pointer)); }
#line 2707 "parser.c"
    break;

  case 160: /* type_qualifier_list: type_qualifier  */
#line 450 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list(0, (yyvsp[0].int_val)); }
#line 2713 "parser.c"
    break;

  case 161: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 451 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list((yyvsp[-1].type_qual_list), (yyvsp[0].int_val)); }
#line 2719 "parser.c"
    break;

  case 162: /* parameter_type_list: parameter_list  */
#line 456 "bison/parser.yacc"
                            { (yyval.param_list) = (yyvsp[0].param_list); }
#line 2725 "parser.c"
    break;

  case 163: /* parameter_list: parameter_declaration  */
#line 460 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list(0, (yyvsp[0].decl)); }
#line 2731 "parser.c"
    break;

  case 164: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 461 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list((yyvsp[-2].param_list), (yyvsp[0].decl)); }
#line 2737 "parser.c"
    break;

  case 165: /* parameter_declaration: declaration_specifiers declarator  */
#line 465 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 0); }
#line 2743 "parser.c"
    break;

  case 166: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 466 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 1); }
#line 2749 "parser.c"
    break;

  case 167: /* parameter_declaration: declaration_specifiers  */
#line 467 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[0].decl_spec_list)), 0, 0); }
#line 2755 "parser.c"
    break;

  case 168: /* type_name: specifier_qualifier_list  */
#line 471 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[0].decl_spec_list)), 0); }
#line 2761 "parser.c"
    break;

  case 169: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 472 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr)); }
#line 2767 "parser.c"
    break;

  case 170: /* abstract_declarator: pointer  */
#line 476 "bison/parser.yacc"
                                                { (yyval.decltr) = make_empty_decltr((yyvsp[0].pointer)); }
#line 2773 "parser.c"
    break;

  case 171: /* abstract_declarator: direct_abstract_declarator  */
#line 477 "bison/parser.yacc"
                                                { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2779 "parser.c"
    break;

  case 172: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 478 "bison/parser.yacc"
                                                { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); }
#line 2785 "parser.c"
    break;

  case 173: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 482 "bison/parser.yacc"
                                                                    { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2791 "parser.c"
    break;

  case 174: /* direct_abstract_declarator: '[' ']'  */
#line 483 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0); }
#line 2797 "parser.c"
    break;

  case 175: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 484 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, (yyvsp[-1].expr)); }
#line 2803 "parser.c"
    break;

  case 176: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 485 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2809 "parser.c"
    break;

  case 177: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 486 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2815 "parser.c"
    break;

  case 178: /* direct_abstract_declarator: '(' ')'  */
#line 487 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, 0); }
#line 2821 "parser.c"
    break;

  case 179: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 488 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, (yyvsp[-1].param_list)); }
#line 2827 "parser.c"
    break;

  case 180: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 489 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2833 "parser.c"
    break;

  case 181: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 490 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2839 "parser.c"
    break;

  case 182: /* initializer: assignment_expression  */
#line 494 "bison/parser.yacc"
                                        { (yyval.initializer) = make_expr_init((yyvsp[0].expr)); }
#line 2845 "parser.c"
    break;

  case 183: /* initializer: '{' initializer_list '}'  */
#line 495 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-1].init_list)); }
#line 2851 "parser.c"
    break;

  case 184: /* initializer: '{' initializer_list ',' '}'  */
#line 496 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-2].init_list)); }
#line 2857 "parser.c"
    break;

  case 185: /* initializer_list: initializer  */
#line 500 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, (yyvsp[0].initializer)); }
#line 2863 "parser.c"
    break;

  case 186: /* initializer_list: initializer_list ',' initializer  */
#line 501 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-2].init_list), (yyvsp[0].initializer)); }
#line 2869 "parser.c"
    break;

  case 187: /* statement: labeled_statement  */
#line 505 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2875 "parser.c"
    break;

  case 188: /* statement: compound_statement  */
#line 506 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2881 "parser.c"
    break;

  case 189: /* statement: expression_statement  */
#line 507 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2887 "parser.c"
    break;

  case 190: /* statement: selection_statement  */
#line 508 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2893 "parser.c"
    break;

  case 191: /* statement: iteration_statement  */
#line 509 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2899 "parser.c"
    break;

  case 192: /* statement: jump_statement  */
#line 510 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2905 "parser.c"
    break;

  case 193: /* statement: print_statement  */
#line 511 "bison/parser.yacc"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2911 "parser.c"
    break;

  case 194: /* statement: free_statement  */
#line 512 "bison/parser.yacc"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2917 "parser.c"
    break;

  case 195: /* labeled_statement: IDENTIFIER ':' statement  */
#line 516 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_labeled_stmt((yyvsp[-2].sval), (yyvsp[0].stmt)); }
#line 2923 "parser.c"
    break;

  case 196: /* labeled_statement: CASE constant_expression ':' statement  */
#line 517 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_case_stmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2929 "parser.c"
    break;

  case 197: /* labeled_statement: DEFAULT ':' statement  */
#line 518 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_default_stmt((yyvsp[0].stmt)); }
#line 2935 "parser.c"
    break;

  case 198: /* compound_statement: '{' '}'  */
#line 522 "bison/parser.yacc"
                            { (yyval.stmt) = make_compound_stmt(0); }
#line 2941 "parser.c"
    break;

  case 199: /* $@1: %empty  */
#line 523 "bison/parser.yacc"
                            { sym_push_scope(); }
#line 2947 "parser.c"
    break;

  case 200: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 525 "bison/parser.yacc"
                        { sym_pop_scope(); (yyval.stmt) = make_compound_stmt((yyvsp[-1].block_list)); }
#line 2953 "parser.c"
    break;

  case 201: /* block_item_list: block_item  */
#line 529 "bison/parser.yacc"
                                        { (yyval.block_list) = (yyvsp[0].block_list); }
#line 2959 "parser.c"
    break;

  case 202: /* block_item_list: block_item_list block_item  */
#line 530 "bison/parser.yacc"
                                        { add_block_item((yyvsp[-1].block_list), (yyvsp[0].block_list)); (yyval.block_list) = (yyvsp[0].block_list); }
#line 2965 "parser.c"
    break;

  case 203: /* block_item: declaration  */
#line 534 "bison/parser.yacc"
                        { (yyval.block_list) = make_decl_block_item((yyvsp[0].decl)); }
#line 2971 "parser.c"
    break;

  case 204: /* block_item: statement  */
#line 535 "bison/parser.yacc"
                        { (yyval.block_list) = make_stmt_block_item((yyvsp[0].stmt)); }
#line 2977 "parser.c"
    break;

  case 205: /* expression_statement: ';'  */
#line 539 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt(0); }
#line 2983 "parser.c"
    break;

  case 206: /* expression_statement: expression ';'  */
#line 540 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt((yyvsp[-1].expr)); }
#line 2989 "parser.c"
    break;

  case 207: /* selection_statement: IF '(' expression ')' statement  */
#line 544 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 2995 "parser.c"
    break;

  case 208: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 545 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 3001 "parser.c"
    break;

  case 209: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 546 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_SWITCH, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3007 "parser.c"
    break;

  case 210: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 550 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_WHILE, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3013 "parser.c"
    break;

  case 211: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 551 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_DO, (yyvsp[-2].expr), (yyvsp[-5].stmt), 0); }
#line 3019 "parser.c"
    break;

  case 212: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 552 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-3].stmt), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3025 "parser.c"
    break;

  case 213: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 553 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3031 "parser.c"
    break;

  case 214: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 554 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-3].decl), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3037 "parser.c"
    break;

  case 215: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 555 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-4].decl), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3043 "parser.c"
    break;

  case 216: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 559 "bison/parser.yacc"
                                { (yyval.stmt) = make_goto_stmt((yyvsp[-1].sval)); }
#line 3049 "parser.c"
    break;

  case 217: /* jump_statement: CONTINUE ';'  */
#line 560 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_CONTINUE); }
#line 3055 "parser.c"
    break;

  case 218: /* jump_statement: BREAK ';'  */
#line 561 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_BREAK); }
#line 3061 "parser.c"
    break;

  case 219: /* jump_statement: RETURN ';'  */
#line 562 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt(0); }
#line 3067 "parser.c"
    break;

  case 220: /* jump_statement: RETURN expression ';'  */
#line 563 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt((yyvsp[-1].expr)); }
#line 3073 "parser.c"
    break;

  case 221: /* print_statement: PRINT '(' STR_LITERAL ')' ';'  */
#line 567 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_str_print_stmt((yyvsp[-2].sval)); }
#line 3079 "parser.c"
    break;

  case 222: /* print_statement: PRINT '(' postfix_expression ',' CONST_INT ')' ';'  */
#line 568 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_expr_print_stmt((yyvsp[-4].expr), make_constant(CONSTANT_INT, (yyvsp[-2].sval))); }
#line 3085 "parser.c"
    break;

  case 223: /* free_statement: FREE '(' expression ')' ';'  */
#line 572 "bison/parser.yacc"
                                    { (yyval.stmt) = make_free_stmt((yyvsp[-2].expr)); }
#line 3091 "parser.c"
    break;

  case 224: /* translation_unit: external_declaration  */
#line 576 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit(0, (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3097 "parser.c"
    break;

  case 225: /* translation_unit: translation_unit external_declaration  */
#line 577 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit((yyvsp[-1].translation_unit), (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3103 "parser.c"
    break;

  case 226: /* external_declaration: function_definition  */
#line 581 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_func_ext_decl((yyvsp[0].func_def)); }
#line 3109 "parser.c"
    break;

  case 227: /* external_declaration: declaration  */
#line 582 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_decl_ext_decl((yyvsp[0].decl)); }
#line 3115 "parser.c"
    break;

  case 228: /* $@2: %empty  */
#line 586 "bison/parser.yacc"
                                                                { set_func_name(get_decltr_id((yyvsp[0].decltr))); }
#line 3121 "parser.c"
    break;

  case 229: /* function_definition: declaration_specifiers declarator $@2 compound_statement  */
#line 588 "bison/parser.yacc"
    {
        func_ended();
        (yyval.func_def) = make_func_def(make_decl_specs((yyvsp[-3].decl_spec_list)), (yyvsp[-2].decltr), (yyvsp[0].stmt));
    }
#line 3130 "parser.c"
    break;


#line 3134 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 594 "bison/parser.yacc"
