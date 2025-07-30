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
#include "symbol_table.h"
#include "parser_helpers.h"
#include "ast.h"

translation_unit *ast_root;

int yylex(void);

void yyerror(const char *s) {
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
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
  YYSYMBOL_CHAR = 24,                      /* CHAR  */
  YYSYMBOL_INT = 25,                       /* INT  */
  YYSYMBOL_SHORT = 26,                     /* SHORT  */
  YYSYMBOL_LONG = 27,                      /* LONG  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 29,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 30,                      /* BOOL  */
  YYSYMBOL_VOID = 31,                      /* VOID  */
  YYSYMBOL_SIGNED = 32,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 33,                  /* UNSIGNED  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_RESTRICT = 35,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 36,                  /* VOLATILE  */
  YYSYMBOL_COMPLEX = 37,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 38,                 /* IMAGINARY  */
  YYSYMBOL_ADD_ASSIGN = 39,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 40,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 41,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 42,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 43,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 44,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 45,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 46,                /* XOR_ASSIGN  */
  YYSYMBOL_LSHIFT_ASSIGN = 47,             /* LSHIFT_ASSIGN  */
  YYSYMBOL_RSHIFT_ASSIGN = 48,             /* RSHIFT_ASSIGN  */
  YYSYMBOL_INCREMENT = 49,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 50,                 /* DECREMENT  */
  YYSYMBOL_AND = 51,                       /* AND  */
  YYSYMBOL_OR = 52,                        /* OR  */
  YYSYMBOL_LSHIFT = 53,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 54,                    /* RSHIFT  */
  YYSYMBOL_EQUAL = 55,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 56,                 /* NOT_EQUAL  */
  YYSYMBOL_LEQ = 57,                       /* LEQ  */
  YYSYMBOL_GEQ = 58,                       /* GEQ  */
  YYSYMBOL_ARROW = 59,                     /* ARROW  */
  YYSYMBOL_ELLIPSIS = 60,                  /* ELLIPSIS  */
  YYSYMBOL_IDENTIFIER = 61,                /* IDENTIFIER  */
  YYSYMBOL_TYPEDEF_NAME = 62,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUM_CONST = 63,                /* ENUM_CONST  */
  YYSYMBOL_CONST_INT = 64,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 65,               /* CONST_FLOAT  */
  YYSYMBOL_STR_LITERAL = 66,               /* STR_LITERAL  */
  YYSYMBOL_FUNC_NAME = 67,                 /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 68,                    /* SIZEOF  */
  YYSYMBOL_NO_ELSE = 69,                   /* NO_ELSE  */
  YYSYMBOL_70_ = 70,                       /* '('  */
  YYSYMBOL_71_ = 71,                       /* ')'  */
  YYSYMBOL_72_ = 72,                       /* '['  */
  YYSYMBOL_73_ = 73,                       /* ']'  */
  YYSYMBOL_74_ = 74,                       /* '.'  */
  YYSYMBOL_75_ = 75,                       /* '{'  */
  YYSYMBOL_76_ = 76,                       /* '}'  */
  YYSYMBOL_77_ = 77,                       /* ','  */
  YYSYMBOL_78_ = 78,                       /* '&'  */
  YYSYMBOL_79_ = 79,                       /* '*'  */
  YYSYMBOL_80_ = 80,                       /* '+'  */
  YYSYMBOL_81_ = 81,                       /* '-'  */
  YYSYMBOL_82_ = 82,                       /* '~'  */
  YYSYMBOL_83_ = 83,                       /* '!'  */
  YYSYMBOL_84_ = 84,                       /* '/'  */
  YYSYMBOL_85_ = 85,                       /* '%'  */
  YYSYMBOL_86_ = 86,                       /* '<'  */
  YYSYMBOL_87_ = 87,                       /* '>'  */
  YYSYMBOL_88_ = 88,                       /* '^'  */
  YYSYMBOL_89_ = 89,                       /* '|'  */
  YYSYMBOL_90_ = 90,                       /* '?'  */
  YYSYMBOL_91_ = 91,                       /* ':'  */
  YYSYMBOL_92_ = 92,                       /* '='  */
  YYSYMBOL_93_ = 93,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_primary_expression = 95,        /* primary_expression  */
  YYSYMBOL_constant = 96,                  /* constant  */
  YYSYMBOL_string = 97,                    /* string  */
  YYSYMBOL_postfix_expression = 98,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 99,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 100,         /* unary_expression  */
  YYSYMBOL_unary_operator = 101,           /* unary_operator  */
  YYSYMBOL_cast_expression = 102,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 103, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 104,      /* additive_expression  */
  YYSYMBOL_shift_expression = 105,         /* shift_expression  */
  YYSYMBOL_relational_expression = 106,    /* relational_expression  */
  YYSYMBOL_equality_expression = 107,      /* equality_expression  */
  YYSYMBOL_and_expression = 108,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 109,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 110,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 111,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 112,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 113,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 114,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 115,      /* assignment_operator  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_constant_expression = 117,      /* constant_expression  */
  YYSYMBOL_declaration = 118,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 119,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 120,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 121,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 122,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 123,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 124, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 125,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 126,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 127,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 128, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 129,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 130,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 131,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 132,          /* enumerator_list  */
  YYSYMBOL_enumerator = 133,               /* enumerator  */
  YYSYMBOL_enumeration_constant = 134,     /* enumeration_constant  */
  YYSYMBOL_type_qualifier = 135,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 136,       /* function_specifier  */
  YYSYMBOL_declarator = 137,               /* declarator  */
  YYSYMBOL_direct_declarator = 138,        /* direct_declarator  */
  YYSYMBOL_pointer = 139,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 140,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 141,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 142,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 143,    /* parameter_declaration  */
  YYSYMBOL_type_name = 144,                /* type_name  */
  YYSYMBOL_abstract_declarator = 145,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 146, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 147,              /* initializer  */
  YYSYMBOL_initializer_list = 148,         /* initializer_list  */
  YYSYMBOL_designation = 149,              /* designation  */
  YYSYMBOL_designator_list = 150,          /* designator_list  */
  YYSYMBOL_designator = 151,               /* designator  */
  YYSYMBOL_statement = 152,                /* statement  */
  YYSYMBOL_labeled_statement = 153,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 154,       /* compound_statement  */
  YYSYMBOL_155_1 = 155,                    /* $@1  */
  YYSYMBOL_block_item_list = 156,          /* block_item_list  */
  YYSYMBOL_block_item = 157,               /* block_item  */
  YYSYMBOL_expression_statement = 158,     /* expression_statement  */
  YYSYMBOL_selection_statement = 159,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 160,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 161,           /* jump_statement  */
  YYSYMBOL_translation_unit = 162,         /* translation_unit  */
  YYSYMBOL_external_declaration = 163,     /* external_declaration  */
  YYSYMBOL_function_definition = 164,      /* function_definition  */
  YYSYMBOL_165_2 = 165                     /* $@2  */
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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1596

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  399

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
       2,     2,     2,    83,     2,     2,     2,    85,    78,     2,
      70,    71,    79,    80,    77,    81,    74,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    93,
      86,    92,    87,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    89,    76,    82,     2,     2,     2,
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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   151,   152,   153,   157,   158,   159,   162,
     163,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   179,   180,   184,   185,   186,   187,   188,   189,   193,
     194,   195,   196,   197,   198,   202,   203,   207,   208,   209,
     210,   214,   215,   216,   220,   221,   222,   226,   227,   228,
     229,   230,   234,   235,   236,   240,   241,   245,   246,   250,
     251,   255,   256,   260,   261,   265,   266,   270,   271,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     289,   290,   294,   298,   299,   303,   304,   305,   306,   307,
     308,   309,   310,   314,   315,   319,   320,   324,   325,   326,
     327,   328,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   350,   351,   352,
     356,   357,   361,   362,   366,   370,   371,   372,   373,   377,
     378,   382,   383,   384,   388,   389,   390,   391,   392,   396,
     397,   401,   402,   406,   409,   410,   411,   415,   419,   420,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   440,   441,   442,   443,   447,   448,   453,   454,
     458,   459,   463,   464,   465,   469,   470,   474,   475,   476,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   494,   495,   496,   500,   501,   502,   503,   507,   511,
     512,   516,   517,   521,   522,   523,   524,   525,   526,   530,
     531,   532,   536,   537,   537,   543,   544,   548,   549,   553,
     554,   558,   559,   560,   564,   565,   566,   567,   568,   569,
     573,   574,   575,   576,   577,   581,   582,   586,   587,   591,
     591
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
  "INLINE", "ENUM", "STRUCT", "UNION", "CHAR", "INT", "SHORT", "LONG",
  "FLOAT", "DOUBLE", "BOOL", "VOID", "SIGNED", "UNSIGNED", "CONST",
  "RESTRICT", "VOLATILE", "COMPLEX", "IMAGINARY", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN",
  "OR_ASSIGN", "XOR_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "INCREMENT",
  "DECREMENT", "AND", "OR", "LSHIFT", "RSHIFT", "EQUAL", "NOT_EQUAL",
  "LEQ", "GEQ", "ARROW", "ELLIPSIS", "IDENTIFIER", "TYPEDEF_NAME",
  "ENUM_CONST", "CONST_INT", "CONST_FLOAT", "STR_LITERAL", "FUNC_NAME",
  "SIZEOF", "NO_ELSE", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept",
  "primary_expression", "constant", "string", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
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
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "compound_statement",
  "$@1", "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", "$@2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-307)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-240)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1127,  -307,  -307,  -307,  -307,  -307,  -307,    46,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,   -19,  1127,  1127,
    -307,    47,  -307,  1127,  1127,   882,  -307,  -307,   -32,   -49,
    -307,    24,    13,  -307,   -23,  -307,   -36,   125,    98,  -307,
    -307,    22,  1214,  -307,  -307,  -307,  -307,   -49,  -307,    38,
    -307,    -5,    39,  -307,  -307,    13,    24,  -307,  1302,    77,
     930,   606,   125,  1214,  1214,   498,  -307,    10,  1214,   189,
    -307,     7,  1467,  -307,  -307,  -307,  -307,    64,  1490,  1490,
    -307,  -307,  -307,  -307,  -307,  -307,  1513,   813,  1275,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,   208,   181,
    1467,  -307,   117,   206,   216,   -21,   221,    91,   110,    97,
     155,   -38,  -307,  -307,  -307,   142,  -307,  -307,    12,   164,
     162,  -307,   196,  -307,   187,   190,   660,  1005,  -307,  -307,
    -307,  1467,     9,  -307,   183,  -307,  -307,    14,  -307,  -307,
    -307,  -307,  -307,   813,  -307,  -307,   813,  -307,  -307,    78,
     113,   201,  1467,   218,  -307,   217,  1302,   -11,  -307,  -307,
    -307,   220,  1325,  1467,   231,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  1467,  -307,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  -307,   415,   729,
    1348,  -307,    90,  -307,   144,  -307,  1079,  1010,  -307,  -307,
    1467,  -307,   224,   228,  -307,  -307,    10,  -307,  1467,  -307,
     232,   237,  -307,  1467,   794,   178,  -307,  1373,   242,  -307,
    -307,  1205,  -307,  -307,  -307,  -307,  -307,    86,  -307,   -58,
    -307,  -307,  -307,  -307,  -307,   117,   117,   206,   206,   216,
     216,   216,   216,   -21,   -21,   221,    91,   110,    97,   155,
      70,   225,   240,   247,  1467,   248,   503,   249,   259,   229,
     233,  1117,   230,  -307,    16,  -307,   -19,  -307,  -307,  -307,
     327,  -307,  -307,  -307,  -307,  -307,  -307,   253,   254,  -307,
     255,   256,   144,   987,  1396,  -307,  -307,   293,   294,  -307,
    -307,  -307,  -307,   252,   252,  -307,  1275,  -307,  -307,  -307,
    -307,  1302,  -307,  1467,  -307,  1467,   503,  1467,  1467,   277,
    1467,   361,   582,   278,  -307,  -307,  -307,    18,   503,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,   299,  -307,   300,
     301,  -307,  -307,   219,  -307,  -307,  -307,  -307,   101,   105,
     503,   128,   302,  1141,  1141,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  1240,   503,   503,  -307,   503,  1467,  1421,  1444,
    -307,   370,  -307,  -307,   136,   503,   138,   503,   140,   503,
     285,  -307,   503,  -307,   503,  -307,  -307,  -307,  -307
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    98,    99,   100,   101,   147,     0,   120,   121,
     103,   105,   104,   106,   107,   108,   111,   102,   109,   110,
     144,   145,   146,   112,   113,   116,   238,     0,    85,    87,
     114,     0,   115,    89,    91,     0,   235,   237,   138,     0,
     150,     0,   162,    83,     0,    93,    95,   149,     0,    86,
      88,   119,     0,    90,    92,     1,   236,     0,   143,     0,
     139,   141,     0,   166,   164,   163,     0,    84,     0,     0,
       0,     0,   148,     0,   126,     0,   122,     0,   128,     0,
     134,     0,     0,   151,   167,   165,    94,    95,     0,     0,
       2,     8,     6,     7,     9,    10,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    11,     3,     4,    23,    35,
       0,    37,    41,    44,    47,    52,    55,    57,    59,    61,
      63,    65,    67,   191,    96,   213,   240,   161,   174,     0,
     168,   170,     0,   159,    30,     0,     0,     0,   125,   118,
     123,     0,     0,   129,   131,   127,   135,     0,   136,   140,
      35,    82,   142,     0,    24,    25,     0,    27,    80,     0,
     175,     0,     0,     0,   194,     0,     0,     0,   199,    17,
      18,     0,     0,     0,     0,    73,    74,    70,    71,    72,
      77,    79,    78,    75,    76,    69,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,     0,     0,
       0,   172,   177,   173,   178,   160,     0,     0,   158,   154,
       0,   153,    30,     0,   117,   132,     0,   124,     0,   137,
       0,     0,     5,     0,     0,   177,   176,     0,     0,   202,
     192,     0,   195,   198,   200,    16,    13,     0,    21,     0,
      15,    68,    38,    39,    40,    42,    43,    45,    46,    50,
      51,    48,    49,    53,    54,    56,    58,    60,    62,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,   219,     0,   217,     0,   218,   203,   204,
       0,   215,   205,   206,   207,   208,   187,     0,     0,   181,
      30,     0,   179,     0,     0,   169,   171,     0,     0,   157,
     152,   130,   133,     0,    28,    81,     0,    36,   201,   193,
     196,     0,    14,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   232,   233,     0,     0,   220,
     214,   216,   188,   180,   185,   182,   189,     0,   183,    30,
       0,   155,   156,     0,   197,    22,    66,   211,     0,     0,
       0,     0,     0,     0,     0,   230,   234,   209,   190,   186,
     184,    19,     0,     0,     0,   210,     0,     0,     0,     0,
      20,   221,   223,   224,     0,     0,     0,     0,     0,     0,
       0,   228,     0,   226,     0,   222,   225,   229,   227
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -307,  -307,  -307,  -307,  -307,  -307,   -64,  -307,   -72,   107,
     118,    49,   114,   179,   177,   180,   182,   176,  -307,   -74,
     -67,  -307,   -94,  -132,  -186,     0,  -307,   316,  -307,   115,
    -307,  -307,   311,   -59,   -33,  -307,   159,  -307,   330,   -71,
    -307,   106,  -307,   -22,   -42,   -15,   -60,   -63,  -307,   184,
    -133,  -107,  -195,   -66,    80,  -228,  -307,   234,   -85,  -307,
     329,  -307,  -307,   109,  -306,  -307,  -307,  -307,  -307,   369,
    -307,  -307
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   105,   106,   107,   108,   247,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     158,   186,   284,   152,    26,   128,    44,    45,    28,    29,
      30,    31,    75,    76,    77,   142,   143,    32,    59,    60,
      61,    33,    34,    62,    47,    48,    65,   297,   130,   131,
     161,   298,   214,   164,   165,   166,   167,   168,   287,   288,
     289,   208,   290,   291,   292,   293,   294,   295,    35,    36,
      37,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   123,   124,   159,   135,    46,    72,   129,   151,   225,
     149,   136,    58,   321,   205,   324,   140,   302,   150,   233,
     230,   213,   285,   231,   154,   155,   364,    64,    49,    50,
     238,   123,   157,    53,    54,    27,   195,   196,   187,  -239,
     302,   138,    40,    57,    87,   145,   150,    20,    21,    22,
      85,    41,   206,   236,    66,   144,    68,   378,   379,   159,
      42,   162,   159,   163,   160,   197,   198,   151,    58,   223,
      67,    40,   217,    40,    43,    58,   149,   150,   140,   249,
      41,   243,   209,   148,   210,    40,   226,    82,   151,    42,
     229,    42,    42,   233,    41,   233,   312,    73,   150,   123,
     242,   141,   227,    42,   285,   248,   211,    38,    51,   339,
      83,   366,   270,   212,    80,    81,   252,   253,   254,   251,
     160,    39,    52,   160,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   329,   301,   321,   235,   363,   233,    63,   232,
     307,    40,   125,   308,   151,   233,    68,   322,    78,    40,
     209,   325,   210,   323,   150,   317,   315,    74,    41,   201,
      72,    84,   373,   150,   123,   320,   374,    63,   233,    78,
      78,    78,   233,   234,    78,   210,   203,   337,    74,    74,
      74,   331,    42,    74,   212,    70,   188,    71,   202,   376,
     151,   189,   190,    78,   144,   233,   204,   390,   286,   392,
     150,   394,    74,   233,   303,   233,   304,   233,   207,   235,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      20,    21,    22,   358,   359,   215,   361,   350,    63,   216,
     347,   357,    84,    78,   259,   260,   261,   262,   234,   123,
     210,   356,    74,   367,   123,   354,   355,   169,   170,    78,
     218,   150,    78,   219,    87,   146,   147,   171,    74,   193,
     194,    74,   237,   185,   228,   375,   199,   200,   172,   239,
     173,   245,   174,   384,   386,   388,   191,   192,   381,   382,
     286,   383,   250,   240,   241,   371,   372,   309,   255,   256,
     391,   310,   393,   313,   395,   123,   320,   397,   314,   398,
     327,   257,   258,   263,   264,   318,   326,   328,   330,   332,
     333,   338,   334,    84,   342,   343,   335,   316,   344,   345,
     271,   272,   286,   273,   274,   275,   276,   277,   278,   279,
     280,   281,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   351,   352,   360,   362,
     368,   365,   377,   369,   370,   389,    88,    89,   396,   266,
     265,   269,    86,   267,   137,   311,   268,    79,   282,    25,
      91,    92,    93,    94,    95,    96,   353,    97,   126,   341,
     306,   244,   125,   340,    56,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   271,   272,
     283,   273,   274,   275,   276,   277,   278,   279,   280,   281,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,    25,    91,    92,
      93,    94,    95,    96,     0,    97,     0,     0,     0,     0,
     125,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,   271,   272,   283,   273,
     274,   275,   276,   277,   278,   279,   280,   281,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,   282,     0,    91,    92,    93,    94,
      95,    96,     0,    97,   139,     0,     0,     0,   125,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,   132,     0,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
      20,    21,    22,    90,    25,    91,    92,    93,    94,    95,
      96,     0,    97,     0,     0,    88,    89,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,    90,     0,    91,
      92,    93,    94,    95,    96,   283,    97,   220,     0,   133,
       0,     0,     0,     0,    99,   134,   101,   102,   103,   104,
       0,     0,     0,     0,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,    91,    92,    93,    94,    95,    96,     0,
      97,     0,     0,   221,     0,     0,     0,     0,    99,   222,
     101,   102,   103,   104,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    25,     0,     0,     0,     0,     0,     0,     0,   209,
     296,   210,     0,     0,     0,     0,     0,     0,    42,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    88,    89,   234,   296,   210,     0,     0,     0,
       0,     0,     0,    42,    90,    25,    91,    92,    93,    94,
      95,    96,    55,    97,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    20,    21,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   346,    88,
      89,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    90,     0,    91,    92,    93,    94,    95,    96,     0,
      97,   224,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
       0,    25,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,     0,    25,
      88,    89,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,    90,     0,    91,    92,    93,    94,    95,    96,
     336,    97,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,    91,    92,
      93,    94,    95,    96,     0,    97,    25,   162,     0,   163,
      98,   319,     0,    99,   100,   101,   102,   103,   104,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,    91,    92,    93,    94,    95,    96,     0,
      97,     0,   162,     0,   163,    98,   380,     0,    99,   100,
     101,   102,   103,   104,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,    91,    92,
      93,    94,    95,    96,     0,    97,     0,   162,     0,   163,
      98,    88,    89,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,     0,    88,    89,     0,    98,     0,     0,
      99,   100,   101,   102,   103,   104,    90,     0,    91,    92,
      93,    94,    95,    96,     0,    97,   246,    88,    89,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,    90,
       0,    91,    92,    93,    94,    95,    96,     0,    97,     0,
       0,   299,    88,    89,     0,     0,    99,   300,   101,   102,
     103,   104,     0,     0,    90,     0,    91,    92,    93,    94,
      95,    96,     0,    97,     0,    88,    89,     0,   316,     0,
       0,    99,   100,   101,   102,   103,   104,    90,     0,    91,
      92,    93,    94,    95,    96,     0,    97,     0,     0,   348,
      88,    89,     0,     0,    99,   349,   101,   102,   103,   104,
       0,     0,    90,     0,    91,    92,    93,    94,    95,    96,
       0,    97,   385,    88,    89,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,    90,     0,    91,    92,    93,
      94,    95,    96,     0,    97,   387,    88,    89,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,     0,    88,
      89,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,    90,     0,    91,    92,    93,    94,    95,    96,     0,
     153,     0,    88,    89,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,    90,     0,    91,    92,    93,    94,
      95,    96,     0,   156,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       0,    68,    68,    97,    71,    27,    48,    70,    82,   141,
      81,    71,    61,   241,    52,    73,    75,   212,    82,    77,
     153,   128,   208,   156,    88,    89,   332,    42,    28,    29,
     162,    98,    96,    33,    34,    35,    57,    58,   110,    75,
     235,    74,    61,    75,    66,    78,   110,    34,    35,    36,
      65,    70,    90,   160,    77,    77,    92,   363,   364,   153,
      79,    72,   156,    74,    97,    86,    87,   141,    61,   136,
      93,    61,   132,    61,    93,    61,   147,   141,   137,   173,
      70,    92,    70,    76,    72,    61,    77,    92,   162,    79,
      76,    79,    79,    77,    70,    77,   228,    75,   162,   166,
     166,    91,    93,    79,   290,   172,   128,    61,    61,    93,
      71,    93,   206,   128,    76,    77,   188,   189,   190,   186,
     153,    75,    75,   156,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   274,   210,   372,   160,   332,    77,    42,    71,
     217,    61,    75,   220,   228,    77,    92,    71,    52,    61,
      70,    91,    72,    77,   228,   237,   233,    52,    70,    78,
     212,    65,    71,   237,   241,   241,    71,    71,    77,    73,
      74,    75,    77,    70,    78,    72,    89,   281,    73,    74,
      75,   276,    79,    78,   209,    70,    79,    72,    88,    71,
     274,    84,    85,    97,   226,    77,    51,    71,   208,    71,
     274,    71,    97,    77,    70,    77,    72,    77,    76,   234,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      34,    35,    36,   327,   328,    71,   330,   304,   132,    77,
     303,   326,   136,   137,   195,   196,   197,   198,    70,   316,
      72,   325,   137,   338,   321,   321,   323,    49,    50,   153,
      73,   325,   156,    73,   286,    76,    77,    59,   153,    53,
      54,   156,    71,    92,    91,   360,    55,    56,    70,    61,
      72,    61,    74,   377,   378,   379,    80,    81,   373,   374,
     290,   376,    61,    76,    77,    76,    77,    73,   191,   192,
     385,    73,   387,    71,   389,   372,   372,   392,    71,   394,
      70,   193,   194,   199,   200,    73,    91,    70,    70,    70,
      61,    91,    93,   217,    71,    71,    93,    75,    73,    73,
       3,     4,   332,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    73,    73,    91,     8,
      71,    93,    70,    73,    73,     5,    49,    50,    93,   202,
     201,   205,    66,   203,    73,   226,   204,    57,    61,    62,
      63,    64,    65,    66,    67,    68,   316,    70,    69,   290,
     216,   167,    75,    76,    35,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      93,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    93,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    76,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    49,    50,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    61,    -1,    63,
      64,    65,    66,    67,    68,    93,    70,    17,    -1,    73,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    49,    50,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    34,    35,    36,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    76,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    62,
      49,    50,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    61,    -1,    63,    64,    65,    66,    67,    68,
      93,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    62,    72,    -1,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    72,    -1,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    72,    -1,    74,
      75,    49,    50,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    49,    50,    -1,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    49,    50,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    73,    49,    50,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    49,    50,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,    61,    -1,    63,
      64,    65,    66,    67,    68,    -1,    70,    -1,    -1,    73,
      49,    50,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    61,    -1,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    49,    50,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    61,    -1,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    49,    50,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    49,
      50,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    49,    50,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    62,   118,   119,   122,   123,
     124,   125,   131,   135,   136,   162,   163,   164,    61,    75,
      61,    70,    79,    93,   120,   121,   137,   138,   139,   119,
     119,    61,    75,   119,   119,     0,   163,    75,    61,   132,
     133,   134,   137,   135,   139,   140,    77,    93,    92,   165,
      70,    72,   138,    75,   123,   126,   127,   128,   135,   132,
      76,    77,    92,    71,   135,   139,   121,   137,    49,    50,
      61,    63,    64,    65,    66,    67,    68,    70,    75,    78,
      79,    80,    81,    82,    83,    95,    96,    97,    98,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   147,    75,   154,    71,   119,   141,
     142,   143,    17,    73,    79,   114,   140,   126,   128,    76,
     127,    91,   129,   130,   137,   128,    76,    77,    76,   133,
     100,   113,   117,    70,   100,   100,    70,   100,   114,   116,
     128,   144,    72,    74,   147,   148,   149,   150,   151,    49,
      50,    59,    70,    72,    74,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    92,   115,   102,    79,    84,
      85,    80,    81,    53,    54,    57,    58,    86,    87,    55,
      56,    78,    88,    89,    51,    52,    90,    76,   155,    70,
      72,   137,   139,   145,   146,    71,    77,   140,    73,    73,
      17,    73,    79,   114,    76,   117,    77,    93,    91,    76,
     144,   144,    71,    77,    70,   139,   145,    71,   117,    61,
      76,    77,   147,    92,   151,    61,    71,    99,   114,   116,
      61,   114,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   105,   106,   106,   107,   108,   109,   110,   111,
     116,     3,     4,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    61,    93,   116,   118,   119,   152,   153,   154,
     156,   157,   158,   159,   160,   161,    71,   141,   145,    73,
      79,   114,   146,    70,    72,    60,   143,   114,   114,    73,
      73,   130,   117,    71,    71,   114,    75,   102,    73,    76,
     147,   149,    71,    77,    73,    91,    91,    70,    70,   117,
      70,   152,    70,    61,    93,    93,    93,   116,    91,    93,
      76,   157,    71,    71,    73,    73,    71,   141,    73,    79,
     114,    73,    73,   148,   147,   114,   113,   152,   116,   116,
      91,   116,     8,   118,   158,    93,    93,   152,    71,    73,
      73,    76,    77,    71,    71,   152,    71,    70,   158,   158,
      76,   152,   152,   152,   116,    71,   116,    71,   116,     5,
      71,   152,    71,   152,    71,   152,    93,   152,   152
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     125,   125,   126,   126,   127,   128,   128,   128,   128,   129,
     129,   130,   130,   130,   131,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   135,   135,   135,   136,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   143,   144,   144,   145,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   147,   147,   147,   148,   148,   148,   148,   149,   150,
     150,   151,   151,   152,   152,   152,   152,   152,   152,   153,
     153,   153,   154,   155,   154,   156,   156,   157,   157,   158,
     158,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   165,
     164
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     6,
       7,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     5,     6,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     5,     4,     4,     6,     6,     5,     4,     3,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     2,     3,     4,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     0,     4,     1,     2,     1,     1,     1,
       2,     5,     7,     5,     5,     7,     6,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     0,
       4
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
#line 150 "bison/parser.yacc"
                                { (yyval.expr) = make_id_expr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1788 "parser.c"
    break;

  case 3: /* primary_expression: constant  */
#line 151 "bison/parser.yacc"
                                { (yyval.expr) = make_const_expr((yyvsp[0].constant)); }
#line 1794 "parser.c"
    break;

  case 4: /* primary_expression: string  */
#line 152 "bison/parser.yacc"
                                { (yyval.expr) = make_string_expr((yyvsp[0].sval)); }
#line 1800 "parser.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 153 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1806 "parser.c"
    break;

  case 6: /* constant: CONST_INT  */
#line 157 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_INT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1812 "parser.c"
    break;

  case 7: /* constant: CONST_FLOAT  */
#line 158 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_FLOAT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1818 "parser.c"
    break;

  case 8: /* constant: ENUM_CONST  */
#line 159 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_ENUM, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1824 "parser.c"
    break;

  case 9: /* string: STR_LITERAL  */
#line 162 "bison/parser.yacc"
                    { (yyval.sval) = (yyvsp[0].sval); free((yyvsp[0].sval)); }
#line 1830 "parser.c"
    break;

  case 10: /* string: FUNC_NAME  */
#line 163 "bison/parser.yacc"
                    { (yyval.sval) = func_name(); }
#line 1836 "parser.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 166 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1842 "parser.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 167 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_SUBSCRIPT, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1848 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 168 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-2].expr), 0); }
#line 1854 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 169 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1860 "parser.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 170 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_DOT, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1866 "parser.c"
    break;

  case 16: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 171 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_ARROW, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1872 "parser.c"
    break;

  case 17: /* postfix_expression: postfix_expression INCREMENT  */
#line 172 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_INCR, (yyvsp[-1].expr), 0); }
#line 1878 "parser.c"
    break;

  case 18: /* postfix_expression: postfix_expression DECREMENT  */
#line 173 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_DECR, (yyvsp[-1].expr), 0); }
#line 1884 "parser.c"
    break;

  case 19: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 174 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-4].type_name), (yyvsp[-1].init_list)); }
#line 1890 "parser.c"
    break;

  case 20: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 175 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-5].type_name), (yyvsp[-2].init_list)); }
#line 1896 "parser.c"
    break;

  case 21: /* argument_expression_list: assignment_expression  */
#line 179 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), 0); }
#line 1902 "parser.c"
    break;

  case 22: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 180 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1908 "parser.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 184 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1914 "parser.c"
    break;

  case 24: /* unary_expression: INCREMENT unary_expression  */
#line 185 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_INCR, (yyvsp[0].expr), 0); }
#line 1920 "parser.c"
    break;

  case 25: /* unary_expression: DECREMENT unary_expression  */
#line 186 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_DECR, (yyvsp[0].expr), 0); }
#line 1926 "parser.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 187 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[0].expr), 0); }
#line 1932 "parser.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 188 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_SIZEOF_EXPR, (yyvsp[0].expr), 0); }
#line 1938 "parser.c"
    break;

  case 28: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 189 "bison/parser.yacc"
                                            { (yyval.expr) = make_sizeof_expr((yyvsp[-1].type_name)); }
#line 1944 "parser.c"
    break;

  case 29: /* unary_operator: '&'  */
#line 193 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_ADDREF; }
#line 1950 "parser.c"
    break;

  case 30: /* unary_operator: '*'  */
#line 194 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_DEREF; }
#line 1956 "parser.c"
    break;

  case 31: /* unary_operator: '+'  */
#line 195 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_PLUS; }
#line 1962 "parser.c"
    break;

  case 32: /* unary_operator: '-'  */
#line 196 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_MINUS; }
#line 1968 "parser.c"
    break;

  case 33: /* unary_operator: '~'  */
#line 197 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_BITNOT; }
#line 1974 "parser.c"
    break;

  case 34: /* unary_operator: '!'  */
#line 198 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_LOGNOT; }
#line 1980 "parser.c"
    break;

  case 35: /* cast_expression: unary_expression  */
#line 202 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1986 "parser.c"
    break;

  case 36: /* cast_expression: '(' type_name ')' cast_expression  */
#line 203 "bison/parser.yacc"
                                            { (yyval.expr) = make_cast_expr((yyvsp[-2].type_name), (yyvsp[0].expr)); }
#line 1992 "parser.c"
    break;

  case 37: /* multiplicative_expression: cast_expression  */
#line 207 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1998 "parser.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 208 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2004 "parser.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 209 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2010 "parser.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 210 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2016 "parser.c"
    break;

  case 41: /* additive_expression: multiplicative_expression  */
#line 214 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2022 "parser.c"
    break;

  case 42: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 215 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2028 "parser.c"
    break;

  case 43: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 216 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2034 "parser.c"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 220 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2040 "parser.c"
    break;

  case 45: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 221 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2046 "parser.c"
    break;

  case 46: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 222 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_RSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2052 "parser.c"
    break;

  case 47: /* relational_expression: shift_expression  */
#line 226 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2058 "parser.c"
    break;

  case 48: /* relational_expression: relational_expression '<' shift_expression  */
#line 227 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2064 "parser.c"
    break;

  case 49: /* relational_expression: relational_expression '>' shift_expression  */
#line 228 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2070 "parser.c"
    break;

  case 50: /* relational_expression: relational_expression LEQ shift_expression  */
#line 229 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2076 "parser.c"
    break;

  case 51: /* relational_expression: relational_expression GEQ shift_expression  */
#line 230 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2082 "parser.c"
    break;

  case 52: /* equality_expression: relational_expression  */
#line 234 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2088 "parser.c"
    break;

  case 53: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 235 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2094 "parser.c"
    break;

  case 54: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 236 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2100 "parser.c"
    break;

  case 55: /* and_expression: equality_expression  */
#line 240 "bison/parser.yacc"
                                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2106 "parser.c"
    break;

  case 56: /* and_expression: and_expression '&' equality_expression  */
#line 241 "bison/parser.yacc"
                                                    { (yyval.expr) = make_expr(EXPR_BITAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2112 "parser.c"
    break;

  case 57: /* exclusive_or_expression: and_expression  */
#line 245 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2118 "parser.c"
    break;

  case 58: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 246 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_BITXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2124 "parser.c"
    break;

  case 59: /* inclusive_or_expression: exclusive_or_expression  */
#line 250 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2130 "parser.c"
    break;

  case 60: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 251 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_BITOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2136 "parser.c"
    break;

  case 61: /* logical_and_expression: inclusive_or_expression  */
#line 255 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2142 "parser.c"
    break;

  case 62: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 256 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2148 "parser.c"
    break;

  case 63: /* logical_or_expression: logical_and_expression  */
#line 260 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2154 "parser.c"
    break;

  case 64: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 261 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2160 "parser.c"
    break;

  case 65: /* conditional_expression: logical_or_expression  */
#line 265 "bison/parser.yacc"
                                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2166 "parser.c"
    break;

  case 66: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 266 "bison/parser.yacc"
                                                                            { (yyval.expr) = make_ternary_expr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2172 "parser.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 270 "bison/parser.yacc"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2178 "parser.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 271 "bison/parser.yacc"
                                                                        { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2184 "parser.c"
    break;

  case 69: /* assignment_operator: '='  */
#line 275 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ASSIGN; }
#line 2190 "parser.c"
    break;

  case 70: /* assignment_operator: MUL_ASSIGN  */
#line 276 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MUL_ASSIGN; }
#line 2196 "parser.c"
    break;

  case 71: /* assignment_operator: DIV_ASSIGN  */
#line 277 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_DIV_ASSIGN; }
#line 2202 "parser.c"
    break;

  case 72: /* assignment_operator: MOD_ASSIGN  */
#line 278 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MOD_ASSIGN; }
#line 2208 "parser.c"
    break;

  case 73: /* assignment_operator: ADD_ASSIGN  */
#line 279 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ADD_ASSIGN; }
#line 2214 "parser.c"
    break;

  case 74: /* assignment_operator: SUB_ASSIGN  */
#line 280 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_SUB_ASSIGN; }
#line 2220 "parser.c"
    break;

  case 75: /* assignment_operator: LSHIFT_ASSIGN  */
#line 281 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_LSHIFT_ASSIGN; }
#line 2226 "parser.c"
    break;

  case 76: /* assignment_operator: RSHIFT_ASSIGN  */
#line 282 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_RSHIFT_ASSIGN; }
#line 2232 "parser.c"
    break;

  case 77: /* assignment_operator: AND_ASSIGN  */
#line 283 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_AND_ASSIGN; }
#line 2238 "parser.c"
    break;

  case 78: /* assignment_operator: XOR_ASSIGN  */
#line 284 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_XOR_ASSIGN; }
#line 2244 "parser.c"
    break;

  case 79: /* assignment_operator: OR_ASSIGN  */
#line 285 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_OR_ASSIGN; }
#line 2250 "parser.c"
    break;

  case 80: /* expression: assignment_expression  */
#line 289 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2256 "parser.c"
    break;

  case 81: /* expression: expression ',' assignment_expression  */
#line 290 "bison/parser.yacc"
                                                { (yyval.expr) = make_expr(EXPR_COMMA, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2262 "parser.c"
    break;

  case 82: /* constant_expression: conditional_expression  */
#line 294 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2268 "parser.c"
    break;

  case 83: /* declaration: declaration_specifiers ';'  */
#line 298 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), 0); }
#line 2274 "parser.c"
    break;

  case 84: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 299 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].init_decltr)); }
#line 2280 "parser.c"
    break;

  case 85: /* declaration_specifiers: storage_class_specifier  */
#line 303 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class(0, (yyvsp[0].int_val)); }
#line 2286 "parser.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 304 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2292 "parser.c"
    break;

  case 87: /* declaration_specifiers: type_specifier  */
#line 305 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2298 "parser.c"
    break;

  case 88: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 306 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2304 "parser.c"
    break;

  case 89: /* declaration_specifiers: type_qualifier  */
#line 307 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2310 "parser.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 308 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2316 "parser.c"
    break;

  case 91: /* declaration_specifiers: function_specifier  */
#line 309 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec(0, (yyvsp[0].int_val)); }
#line 2322 "parser.c"
    break;

  case 92: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 310 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2328 "parser.c"
    break;

  case 93: /* init_declarator_list: init_declarator  */
#line 314 "bison/parser.yacc"
                                                    { (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2334 "parser.c"
    break;

  case 94: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 315 "bison/parser.yacc"
                                                    { add_init_decltr((yyvsp[-2].init_decltr), (yyvsp[0].init_decltr)); (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2340 "parser.c"
    break;

  case 95: /* init_declarator: declarator  */
#line 319 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[0].decltr), 0); }
#line 2346 "parser.c"
    break;

  case 96: /* init_declarator: declarator '=' initializer  */
#line 320 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[-2].decltr), (yyvsp[0].initializer)); }
#line 2352 "parser.c"
    break;

  case 97: /* storage_class_specifier: TYPEDEF  */
#line 324 "bison/parser.yacc"
                    { (yyval.int_val) = SC_TYPEDEF; }
#line 2358 "parser.c"
    break;

  case 98: /* storage_class_specifier: EXTERN  */
#line 325 "bison/parser.yacc"
                    { (yyval.int_val) = SC_EXTERN; }
#line 2364 "parser.c"
    break;

  case 99: /* storage_class_specifier: STATIC  */
#line 326 "bison/parser.yacc"
                    { (yyval.int_val) = SC_STATIC; }
#line 2370 "parser.c"
    break;

  case 100: /* storage_class_specifier: AUTO  */
#line 327 "bison/parser.yacc"
                    { (yyval.int_val) = SC_AUTO; }
#line 2376 "parser.c"
    break;

  case 101: /* storage_class_specifier: REGISTER  */
#line 328 "bison/parser.yacc"
                    { (yyval.int_val) = SC_REGISTER; }
#line 2382 "parser.c"
    break;

  case 102: /* type_specifier: VOID  */
#line 332 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_VOID); }
#line 2388 "parser.c"
    break;

  case 103: /* type_specifier: CHAR  */
#line 333 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_CHAR); }
#line 2394 "parser.c"
    break;

  case 104: /* type_specifier: SHORT  */
#line 334 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SHORT); }
#line 2400 "parser.c"
    break;

  case 105: /* type_specifier: INT  */
#line 335 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_INT); }
#line 2406 "parser.c"
    break;

  case 106: /* type_specifier: LONG  */
#line 336 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_LONG); }
#line 2412 "parser.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 337 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_FLOAT); }
#line 2418 "parser.c"
    break;

  case 108: /* type_specifier: DOUBLE  */
#line 338 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_DOUBLE); }
#line 2424 "parser.c"
    break;

  case 109: /* type_specifier: SIGNED  */
#line 339 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SIGNED); }
#line 2430 "parser.c"
    break;

  case 110: /* type_specifier: UNSIGNED  */
#line 340 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_UNSIGNED); }
#line 2436 "parser.c"
    break;

  case 111: /* type_specifier: BOOL  */
#line 341 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_BOOL); }
#line 2442 "parser.c"
    break;

  case 112: /* type_specifier: COMPLEX  */
#line 342 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_COMPLEX); }
#line 2448 "parser.c"
    break;

  case 113: /* type_specifier: IMAGINARY  */
#line 343 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_IMAGINARY); }
#line 2454 "parser.c"
    break;

  case 114: /* type_specifier: struct_or_union_specifier  */
#line 344 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_sou_type_spec((yyvsp[0].sou_spec)); }
#line 2460 "parser.c"
    break;

  case 115: /* type_specifier: enum_specifier  */
#line 345 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_enum_type_spec((yyvsp[0].enum_spec)); }
#line 2466 "parser.c"
    break;

  case 116: /* type_specifier: TYPEDEF_NAME  */
#line 346 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_typedef_type_spec((yyvsp[0].sval)); }
#line 2472 "parser.c"
    break;

  case 117: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 350 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-4].int_val), (yyvsp[-3].sval), (yyvsp[-1].struct_decl_list)); }
#line 2478 "parser.c"
    break;

  case 118: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 351 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-3].int_val), 0, (yyvsp[-1].struct_decl_list)); }
#line 2484 "parser.c"
    break;

  case 119: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 352 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-1].int_val), (yyvsp[0].sval), 0); }
#line 2490 "parser.c"
    break;

  case 120: /* struct_or_union: STRUCT  */
#line 356 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_STRUCT; }
#line 2496 "parser.c"
    break;

  case 121: /* struct_or_union: UNION  */
#line 357 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_UNION; }
#line 2502 "parser.c"
    break;

  case 122: /* struct_declaration_list: struct_declaration  */
#line 361 "bison/parser.yacc"
                                                        { (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2508 "parser.c"
    break;

  case 123: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 362 "bison/parser.yacc"
                                                        { add_struct_decl((yyvsp[-1].struct_decl_list), (yyvsp[0].struct_decl_list)); (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2514 "parser.c"
    break;

  case 124: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 366 "bison/parser.yacc"
                                                                { (yyval.struct_decl_list) = make_struct_decl_list(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].struct_decltr_list)); }
#line 2520 "parser.c"
    break;

  case 125: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 370 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2526 "parser.c"
    break;

  case 126: /* specifier_qualifier_list: type_specifier  */
#line 371 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2532 "parser.c"
    break;

  case 127: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 372 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2538 "parser.c"
    break;

  case 128: /* specifier_qualifier_list: type_qualifier  */
#line 373 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2544 "parser.c"
    break;

  case 129: /* struct_declarator_list: struct_declarator  */
#line 377 "bison/parser.yacc"
                                                        { (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2550 "parser.c"
    break;

  case 130: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 378 "bison/parser.yacc"
                                                        { add_struct_decltr((yyvsp[-2].struct_decltr_list), (yyvsp[0].struct_decltr_list)); (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2556 "parser.c"
    break;

  case 131: /* struct_declarator: declarator  */
#line 382 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[0].decltr), 0); }
#line 2562 "parser.c"
    break;

  case 132: /* struct_declarator: ':' constant_expression  */
#line 383 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list(0, (yyvsp[0].expr)); }
#line 2568 "parser.c"
    break;

  case 133: /* struct_declarator: declarator ':' constant_expression  */
#line 384 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[-2].decltr), (yyvsp[0].expr)); }
#line 2574 "parser.c"
    break;

  case 134: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 388 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-1].enumerator_list)); }
#line 2580 "parser.c"
    break;

  case 135: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 389 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-3].sval), (yyvsp[-1].enumerator_list)); }
#line 2586 "parser.c"
    break;

  case 136: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 390 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-2].enumerator_list)); }
#line 2592 "parser.c"
    break;

  case 137: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 391 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-4].sval), (yyvsp[-2].enumerator_list)); }
#line 2598 "parser.c"
    break;

  case 138: /* enum_specifier: ENUM IDENTIFIER  */
#line 392 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[0].sval), 0); }
#line 2604 "parser.c"
    break;

  case 139: /* enumerator_list: enumerator  */
#line 396 "bison/parser.yacc"
                                            { (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2610 "parser.c"
    break;

  case 140: /* enumerator_list: enumerator_list ',' enumerator  */
#line 397 "bison/parser.yacc"
                                            { add_enumerator((yyvsp[-2].enumerator_list), (yyvsp[0].enumerator_list)); (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2616 "parser.c"
    break;

  case 141: /* enumerator: enumeration_constant  */
#line 401 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[0].sval), 0); free((yyvsp[0].sval)); }
#line 2622 "parser.c"
    break;

  case 142: /* enumerator: enumeration_constant '=' constant_expression  */
#line 402 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[-2].sval), (yyvsp[0].expr)); free((yyvsp[-2].sval)); }
#line 2628 "parser.c"
    break;

  case 143: /* enumeration_constant: IDENTIFIER  */
#line 406 "bison/parser.yacc"
                    { sym_define_enum((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); }
#line 2634 "parser.c"
    break;

  case 144: /* type_qualifier: CONST  */
#line 409 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_CONST; }
#line 2640 "parser.c"
    break;

  case 145: /* type_qualifier: RESTRICT  */
#line 410 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_RESTRICT; }
#line 2646 "parser.c"
    break;

  case 146: /* type_qualifier: VOLATILE  */
#line 411 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_VOLATILE; }
#line 2652 "parser.c"
    break;

  case 147: /* function_specifier: INLINE  */
#line 415 "bison/parser.yacc"
                    { (yyval.int_val) = FS_INLINE; }
#line 2658 "parser.c"
    break;

  case 148: /* declarator: pointer direct_declarator  */
#line 419 "bison/parser.yacc"
                                    { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); (yyval.decltr) = (yyvsp[0].decltr); }
#line 2664 "parser.c"
    break;

  case 149: /* declarator: direct_declarator  */
#line 420 "bison/parser.yacc"
                                    { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2670 "parser.c"
    break;

  case 150: /* direct_declarator: IDENTIFIER  */
#line 425 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_id_decltr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2676 "parser.c"
    break;

  case 151: /* direct_declarator: '(' declarator ')'  */
#line 426 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_nested_decltr((yyvsp[-1].decltr)); }
#line 2682 "parser.c"
    break;

  case 152: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 427 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr), 0, 0); }
#line 2688 "parser.c"
    break;

  case 153: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 428 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), (yyvsp[-1].type_qual_list), 0, 0, 0); }
#line 2694 "parser.c"
    break;

  case 154: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 429 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr), 0, 0); }
#line 2700 "parser.c"
    break;

  case 155: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 430 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-5].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr), 1, 0); }
#line 2706 "parser.c"
    break;

  case 156: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 431 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-5].decltr), (yyvsp[-3].type_qual_list), (yyvsp[-1].expr), 1, 0); }
#line 2712 "parser.c"
    break;

  case 157: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 432 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), 0, 0, 0); }
#line 2718 "parser.c"
    break;

  case 158: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 433 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, 0, 0, 1); }
#line 2724 "parser.c"
    break;

  case 159: /* direct_declarator: direct_declarator '[' ']'  */
#line 434 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0, 0, 0); }
#line 2730 "parser.c"
    break;

  case 160: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 435 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2736 "parser.c"
    break;

  case 161: /* direct_declarator: direct_declarator '(' ')'  */
#line 436 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2742 "parser.c"
    break;

  case 162: /* pointer: '*'  */
#line 440 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, 0); }
#line 2748 "parser.c"
    break;

  case 163: /* pointer: '*' type_qualifier_list  */
#line 441 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[0].type_qual_list), 0); }
#line 2754 "parser.c"
    break;

  case 164: /* pointer: '*' pointer  */
#line 442 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, (yyvsp[0].pointer)); }
#line 2760 "parser.c"
    break;

  case 165: /* pointer: '*' type_qualifier_list pointer  */
#line 443 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[-1].type_qual_list), (yyvsp[0].pointer)); }
#line 2766 "parser.c"
    break;

  case 166: /* type_qualifier_list: type_qualifier  */
#line 447 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list(0, (yyvsp[0].int_val)); }
#line 2772 "parser.c"
    break;

  case 167: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 448 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list((yyvsp[-1].type_qual_list), (yyvsp[0].int_val)); }
#line 2778 "parser.c"
    break;

  case 168: /* parameter_type_list: parameter_list  */
#line 453 "bison/parser.yacc"
                                        { set_param_ellipsis(0); (yyval.param_list) = (yyvsp[0].param_list); }
#line 2784 "parser.c"
    break;

  case 169: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 454 "bison/parser.yacc"
                                        { set_param_ellipsis(1); (yyval.param_list) = (yyvsp[-2].param_list); }
#line 2790 "parser.c"
    break;

  case 170: /* parameter_list: parameter_declaration  */
#line 458 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list(0, (yyvsp[0].decl)); }
#line 2796 "parser.c"
    break;

  case 171: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 459 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list((yyvsp[-2].param_list), (yyvsp[0].decl)); }
#line 2802 "parser.c"
    break;

  case 172: /* parameter_declaration: declaration_specifiers declarator  */
#line 463 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 0); }
#line 2808 "parser.c"
    break;

  case 173: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 464 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 1); }
#line 2814 "parser.c"
    break;

  case 174: /* parameter_declaration: declaration_specifiers  */
#line 465 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[0].decl_spec_list)), 0, 0); }
#line 2820 "parser.c"
    break;

  case 175: /* type_name: specifier_qualifier_list  */
#line 469 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[0].decl_spec_list)), 0); }
#line 2826 "parser.c"
    break;

  case 176: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 470 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr)); }
#line 2832 "parser.c"
    break;

  case 177: /* abstract_declarator: pointer  */
#line 474 "bison/parser.yacc"
                                                { (yyval.decltr) = make_empty_decltr((yyvsp[0].pointer)); }
#line 2838 "parser.c"
    break;

  case 178: /* abstract_declarator: direct_abstract_declarator  */
#line 475 "bison/parser.yacc"
                                                { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2844 "parser.c"
    break;

  case 179: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 476 "bison/parser.yacc"
                                                { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); }
#line 2850 "parser.c"
    break;

  case 180: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 480 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_nested_decltr((yyvsp[-1].decltr)); }
#line 2856 "parser.c"
    break;

  case 181: /* direct_abstract_declarator: '[' ']'  */
#line 481 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0, 0, 0); }
#line 2862 "parser.c"
    break;

  case 182: /* direct_abstract_declarator: '[' assignment_expression ']'  */
#line 482 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, (yyvsp[-1].expr), 0, 0); }
#line 2868 "parser.c"
    break;

  case 183: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 483 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0, 0, 0); }
#line 2874 "parser.c"
    break;

  case 184: /* direct_abstract_declarator: direct_abstract_declarator '[' assignment_expression ']'  */
#line 484 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr), 0, 0); }
#line 2880 "parser.c"
    break;

  case 185: /* direct_abstract_declarator: '[' '*' ']'  */
#line 485 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0, 0, 1); }
#line 2886 "parser.c"
    break;

  case 186: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 486 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, 0, 0, 1); }
#line 2892 "parser.c"
    break;

  case 187: /* direct_abstract_declarator: '(' ')'  */
#line 487 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, 0); }
#line 2898 "parser.c"
    break;

  case 188: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 488 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, (yyvsp[-1].param_list)); }
#line 2904 "parser.c"
    break;

  case 189: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 489 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2910 "parser.c"
    break;

  case 190: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 490 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2916 "parser.c"
    break;

  case 191: /* initializer: assignment_expression  */
#line 494 "bison/parser.yacc"
                                        { (yyval.initializer) = make_expr_init((yyvsp[0].expr)); }
#line 2922 "parser.c"
    break;

  case 192: /* initializer: '{' initializer_list '}'  */
#line 495 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-1].init_list)); }
#line 2928 "parser.c"
    break;

  case 193: /* initializer: '{' initializer_list ',' '}'  */
#line 496 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-2].init_list)); }
#line 2934 "parser.c"
    break;

  case 194: /* initializer_list: initializer  */
#line 500 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, 0, (yyvsp[0].initializer)); }
#line 2940 "parser.c"
    break;

  case 195: /* initializer_list: designation initializer  */
#line 501 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, (yyvsp[-1].designation), (yyvsp[0].initializer)); }
#line 2946 "parser.c"
    break;

  case 196: /* initializer_list: initializer_list ',' initializer  */
#line 502 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-2].init_list), 0, (yyvsp[0].initializer)); }
#line 2952 "parser.c"
    break;

  case 197: /* initializer_list: initializer_list ',' designation initializer  */
#line 503 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-3].init_list), (yyvsp[-1].designation), (yyvsp[0].initializer)); }
#line 2958 "parser.c"
    break;

  case 198: /* designation: designator_list '='  */
#line 507 "bison/parser.yacc"
                                { (yyval.designation) = (yyvsp[-1].designation); }
#line 2964 "parser.c"
    break;

  case 199: /* designator_list: designator  */
#line 511 "bison/parser.yacc"
                                        { (yyval.designation) = (yyvsp[0].designation); }
#line 2970 "parser.c"
    break;

  case 200: /* designator_list: designator_list designator  */
#line 512 "bison/parser.yacc"
                                        { add_designator((yyvsp[-1].designation), (yyvsp[0].designation)); (yyval.designation) = (yyvsp[0].designation); }
#line 2976 "parser.c"
    break;

  case 201: /* designator: '[' constant_expression ']'  */
#line 516 "bison/parser.yacc"
                                        { (yyval.designation) = make_arr_designator((yyvsp[-1].expr)); }
#line 2982 "parser.c"
    break;

  case 202: /* designator: '.' IDENTIFIER  */
#line 517 "bison/parser.yacc"
                                        { (yyval.designation) = make_member_designator((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2988 "parser.c"
    break;

  case 203: /* statement: labeled_statement  */
#line 521 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2994 "parser.c"
    break;

  case 204: /* statement: compound_statement  */
#line 522 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3000 "parser.c"
    break;

  case 205: /* statement: expression_statement  */
#line 523 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3006 "parser.c"
    break;

  case 206: /* statement: selection_statement  */
#line 524 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3012 "parser.c"
    break;

  case 207: /* statement: iteration_statement  */
#line 525 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3018 "parser.c"
    break;

  case 208: /* statement: jump_statement  */
#line 526 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3024 "parser.c"
    break;

  case 209: /* labeled_statement: IDENTIFIER ':' statement  */
#line 530 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_labeled_stmt((yyvsp[-2].sval), (yyvsp[0].stmt)); }
#line 3030 "parser.c"
    break;

  case 210: /* labeled_statement: CASE constant_expression ':' statement  */
#line 531 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_case_stmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3036 "parser.c"
    break;

  case 211: /* labeled_statement: DEFAULT ':' statement  */
#line 532 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_default_stmt((yyvsp[0].stmt)); }
#line 3042 "parser.c"
    break;

  case 212: /* compound_statement: '{' '}'  */
#line 536 "bison/parser.yacc"
                            { (yyval.stmt) = make_compound_stmt(0); }
#line 3048 "parser.c"
    break;

  case 213: /* $@1: %empty  */
#line 537 "bison/parser.yacc"
                            { sym_push_scope(); }
#line 3054 "parser.c"
    break;

  case 214: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 539 "bison/parser.yacc"
                        { sym_pop_scope(); (yyval.stmt) = make_compound_stmt((yyvsp[-1].block_list)); }
#line 3060 "parser.c"
    break;

  case 215: /* block_item_list: block_item  */
#line 543 "bison/parser.yacc"
                                        { (yyval.block_list) = (yyvsp[0].block_list); }
#line 3066 "parser.c"
    break;

  case 216: /* block_item_list: block_item_list block_item  */
#line 544 "bison/parser.yacc"
                                        { add_block_item((yyvsp[-1].block_list), (yyvsp[0].block_list)); (yyval.block_list) = (yyvsp[0].block_list); }
#line 3072 "parser.c"
    break;

  case 217: /* block_item: declaration  */
#line 548 "bison/parser.yacc"
                        { (yyval.block_list) = make_decl_block_item((yyvsp[0].decl)); }
#line 3078 "parser.c"
    break;

  case 218: /* block_item: statement  */
#line 549 "bison/parser.yacc"
                        { (yyval.block_list) = make_stmt_block_item((yyvsp[0].stmt)); }
#line 3084 "parser.c"
    break;

  case 219: /* expression_statement: ';'  */
#line 553 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt(0); }
#line 3090 "parser.c"
    break;

  case 220: /* expression_statement: expression ';'  */
#line 554 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt((yyvsp[-1].expr)); }
#line 3096 "parser.c"
    break;

  case 221: /* selection_statement: IF '(' expression ')' statement  */
#line 558 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3102 "parser.c"
    break;

  case 222: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 559 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 3108 "parser.c"
    break;

  case 223: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 560 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_SWITCH, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3114 "parser.c"
    break;

  case 224: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 564 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_WHILE, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3120 "parser.c"
    break;

  case 225: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 565 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_DO, (yyvsp[-2].expr), (yyvsp[-5].stmt), 0); }
#line 3126 "parser.c"
    break;

  case 226: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 566 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-3].stmt), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3132 "parser.c"
    break;

  case 227: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 567 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3138 "parser.c"
    break;

  case 228: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 568 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-3].decl), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3144 "parser.c"
    break;

  case 229: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 569 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-4].decl), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3150 "parser.c"
    break;

  case 230: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 573 "bison/parser.yacc"
                                { (yyval.stmt) = make_goto_stmt((yyvsp[-1].sval)); }
#line 3156 "parser.c"
    break;

  case 231: /* jump_statement: CONTINUE ';'  */
#line 574 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_CONTINUE); }
#line 3162 "parser.c"
    break;

  case 232: /* jump_statement: BREAK ';'  */
#line 575 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_BREAK); }
#line 3168 "parser.c"
    break;

  case 233: /* jump_statement: RETURN ';'  */
#line 576 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_RETURN); }
#line 3174 "parser.c"
    break;

  case 234: /* jump_statement: RETURN expression ';'  */
#line 577 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt((yyvsp[-1].expr)); }
#line 3180 "parser.c"
    break;

  case 235: /* translation_unit: external_declaration  */
#line 581 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit(0, (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3186 "parser.c"
    break;

  case 236: /* translation_unit: translation_unit external_declaration  */
#line 582 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit((yyvsp[-1].translation_unit), (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3192 "parser.c"
    break;

  case 237: /* external_declaration: function_definition  */
#line 586 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_func_ext_decl((yyvsp[0].func_def)); }
#line 3198 "parser.c"
    break;

  case 238: /* external_declaration: declaration  */
#line 587 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_decl_ext_decl((yyvsp[0].decl)); }
#line 3204 "parser.c"
    break;

  case 239: /* $@2: %empty  */
#line 591 "bison/parser.yacc"
                                                                { set_func_name(get_decltr_id((yyvsp[0].decltr))); }
#line 3210 "parser.c"
    break;

  case 240: /* function_definition: declaration_specifiers declarator $@2 compound_statement  */
#line 593 "bison/parser.yacc"
    {
        func_ended();
        (yyval.func_def) = make_func_def(make_decl_specs((yyvsp[-3].decl_spec_list)), (yyvsp[-2].decltr), (yyvsp[0].stmt));
    }
#line 3219 "parser.c"
    break;


#line 3223 "parser.c"

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

#line 599 "bison/parser.yacc"
