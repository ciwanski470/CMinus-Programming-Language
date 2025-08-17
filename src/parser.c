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
#define YYLAST   1618

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  391

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
       0,   152,   152,   153,   154,   155,   159,   160,   161,   164,
     165,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   181,   182,   186,   187,   188,   189,   190,   191,   195,
     196,   197,   198,   199,   200,   204,   205,   209,   210,   211,
     212,   216,   217,   218,   222,   223,   224,   228,   229,   230,
     231,   232,   236,   237,   238,   242,   243,   247,   248,   252,
     253,   257,   258,   262,   263,   267,   268,   272,   273,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     291,   292,   296,   300,   301,   309,   310,   311,   312,   313,
     314,   315,   316,   320,   321,   325,   326,   330,   331,   332,
     333,   334,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   356,   357,   358,
     362,   363,   367,   368,   372,   376,   377,   378,   379,   383,
     384,   388,   389,   390,   394,   395,   396,   397,   398,   402,
     403,   407,   408,   412,   415,   416,   417,   421,   427,   428,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     446,   447,   448,   449,   453,   454,   459,   460,   464,   465,
     469,   470,   471,   475,   476,   480,   481,   482,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   498,   499,   500,
     504,   505,   506,   507,   511,   515,   516,   520,   521,   525,
     526,   527,   528,   529,   530,   534,   535,   536,   540,   541,
     541,   547,   548,   552,   553,   557,   558,   562,   563,   564,
     568,   569,   570,   571,   572,   573,   577,   578,   579,   580,
     581,   585,   586,   590,   591,   595,   595
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

#define YYPACT_NINF (-289)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-236)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1149,  -289,  -289,  -289,  -289,  -289,  -289,    47,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,    -6,  1149,  1149,
    -289,    90,  -289,  1149,  1149,   904,  -289,  -289,   -30,    19,
    -289,    83,   -14,  -289,     4,  -289,    14,    89,    85,  -289,
    -289,    27,  1236,  -289,  -289,  -289,  -289,    19,  -289,   -51,
    -289,    22,    78,  -289,  -289,   -14,    83,  -289,  1324,   104,
     952,   628,    89,  1236,  1236,   520,  -289,     5,  1236,   109,
    -289,   -24,  1489,  -289,  -289,  -289,  -289,    64,  1512,  1512,
    -289,  -289,  -289,  -289,  -289,  -289,  1535,   835,  1297,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,    51,   521,
    1489,  -289,   108,   165,   199,   -16,   206,   125,    94,   134,
     169,   -39,  -289,  -289,  -289,   150,  -289,  -289,    63,   168,
     164,  -289,   180,  -289,  -289,  -289,   170,   682,  1027,  -289,
    -289,  -289,  1489,    26,  -289,   156,  -289,  -289,    84,  -289,
    -289,  -289,   835,  -289,  -289,   835,  -289,  -289,   -53,   111,
     196,  1489,   210,  -289,   187,  1324,   -36,  -289,  -289,  -289,
     213,  1347,  1489,   218,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  1489,  -289,  1489,  1489,  1489,
    1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,
    1489,  1489,  1489,  1489,  1489,  1489,  -289,   437,   751,  1370,
    -289,   106,  -289,   160,  -289,  1101,  1032,  -289,  1489,  -289,
     209,  -289,  -289,     5,  -289,  1489,  -289,   212,   214,  -289,
    1489,   816,   166,  -289,  1395,   211,  -289,  -289,  1227,  -289,
    -289,  -289,  -289,  -289,     6,  -289,    97,  -289,  -289,  -289,
    -289,  -289,   108,   108,   165,   165,   199,   199,   199,   199,
     -16,   -16,   206,   125,    94,   134,   169,    77,   195,   219,
     220,  1489,   221,   525,   222,   227,   200,   201,  1139,   204,
    -289,    54,  -289,    -6,  -289,  -289,  -289,   346,  -289,  -289,
    -289,  -289,  -289,  -289,   225,   228,  -289,   229,   160,  1009,
    1418,  -289,  -289,   230,   249,  -289,  -289,  -289,   226,   226,
    -289,  1297,  -289,  -289,  -289,  -289,  1324,  -289,  1489,  -289,
    1489,   525,  1489,  1489,   232,  1489,   292,   604,   231,  -289,
    -289,  -289,    55,   525,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,   254,  -289,   255,  -289,  -289,   189,  -289,  -289,  -289,
    -289,    81,   124,   525,   131,   259,  1163,  1163,  -289,  -289,
    -289,  -289,  -289,  -289,  1262,   525,   525,  -289,   525,  1489,
    1443,  1466,  -289,   325,  -289,  -289,   133,   525,   140,   525,
     141,   525,   238,  -289,   525,  -289,   525,  -289,  -289,  -289,
    -289
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    98,    99,   100,   101,   147,     0,   120,   121,
     103,   105,   104,   106,   107,   108,   111,   102,   109,   110,
     144,   145,   146,   112,   113,   116,   234,     0,    85,    87,
     114,     0,   115,    89,    91,     0,   231,   233,   138,     0,
     150,     0,   160,    83,     0,    93,    95,   149,     0,    86,
      88,   119,     0,    90,    92,     1,   232,     0,   143,     0,
     139,   141,     0,   164,   162,   161,     0,    84,     0,     0,
       0,     0,   148,     0,   126,     0,   122,     0,   128,     0,
     134,     0,     0,   151,   165,   163,    94,    95,     0,     0,
       2,     8,     6,     7,     9,    10,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    11,     3,     4,    23,    35,
       0,    37,    41,    44,    47,    52,    55,    57,    59,    61,
      63,    65,    67,   187,    96,   209,   236,   159,   172,     0,
     166,   168,     0,   157,    35,    82,     0,     0,     0,   125,
     118,   123,     0,     0,   129,   131,   127,   135,     0,   136,
     140,   142,     0,    24,    25,     0,    27,    80,     0,   173,
       0,     0,     0,   190,     0,     0,     0,   195,    17,    18,
       0,     0,     0,     0,    73,    74,    70,    71,    72,    77,
      79,    78,    75,    76,    69,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,     0,
     170,   175,   171,   176,   158,     0,     0,   154,     0,   153,
       0,   117,   132,     0,   124,     0,   137,     0,     0,     5,
       0,     0,   175,   174,     0,     0,   198,   188,     0,   191,
     194,   196,    16,    13,     0,    21,     0,    15,    68,    38,
      39,    40,    42,    43,    45,    46,    50,    51,    48,    49,
      53,    54,    56,    58,    60,    62,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
     215,     0,   213,     0,   214,   199,   200,     0,   211,   201,
     202,   203,   204,   183,     0,     0,   179,     0,   177,     0,
       0,   167,   169,     0,     0,   152,   130,   133,     0,    28,
      81,     0,    36,   197,   189,   192,     0,    14,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,     0,     0,   216,   210,   212,   184,   178,   180,
     185,     0,   181,     0,   155,   156,     0,   193,    22,    66,
     207,     0,     0,     0,     0,     0,     0,     0,   226,   230,
     205,   186,   182,    19,     0,     0,     0,   206,     0,     0,
       0,     0,    20,   217,   219,   220,     0,     0,     0,     0,
       0,     0,     0,   224,     0,   222,     0,   218,   221,   225,
     223
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -289,  -289,  -289,  -289,  -289,  -289,   117,  -289,   -96,    79,
      80,    61,    82,   132,   135,   136,   137,   130,  -289,   -52,
     -67,  -289,   -94,   -75,  -199,     0,  -289,   271,  -289,    42,
    -289,  -289,   266,   -64,   -15,  -289,   118,  -289,   286,   -69,
    -289,   -25,  -289,   -23,   -42,   -33,   -56,   -65,  -289,   129,
     -95,  -112,  -188,   -66,    34,  -228,  -289,   181,  -144,  -289,
     277,  -289,  -289,    98,  -288,  -289,  -289,  -289,  -289,   313,
    -289,  -289
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   105,   106,   107,   108,   244,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     157,   185,   281,   136,    26,   128,    44,    45,    28,    29,
      30,    31,    75,    76,    77,   143,   144,    32,    59,    60,
      61,    33,    34,    62,    47,    48,    65,   294,   130,   131,
     160,   295,   213,   163,   164,   165,   166,   167,   284,   285,
     286,   207,   287,   288,   289,   290,   291,   292,    35,    36,
      37,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   123,   124,   158,    46,   129,    72,   151,   282,    64,
     316,   141,   150,   204,   186,   137,   212,    63,   229,   135,
      20,    21,    22,   298,   230,    80,    81,    78,    49,    50,
     135,   123,    85,    53,    54,    27,   161,    58,   162,   357,
      84,   194,   195,    87,   298,    57,    63,   233,    78,    78,
      78,   205,   149,    78,   145,    40,   240,   227,   158,   139,
     228,   158,   220,   146,    41,    42,    40,   222,   370,   371,
     196,   197,    78,    42,   141,    41,   216,   317,   246,   150,
      58,    66,   159,   318,    42,   135,   235,    43,   282,  -235,
     135,   249,   250,   251,    74,   211,   142,    67,   123,   239,
     168,   169,    73,   223,   245,   210,    68,    63,    38,   135,
     170,   267,    84,    78,    82,    74,    74,    74,   248,   224,
      74,   171,    39,   172,    40,   173,   232,    78,   356,   326,
      78,   230,   230,   208,   297,   209,   316,   159,   312,    74,
     159,   303,    42,   304,    40,    58,    40,   334,   359,    83,
     307,    51,   365,    41,   230,    41,    68,   135,   230,    70,
     226,    71,    42,   310,   135,    52,   135,    40,   320,    72,
     319,   123,   315,   135,   230,   211,   208,   350,   209,   125,
      74,   231,   201,   209,   332,   147,   148,   187,   134,   360,
      42,    84,   188,   189,    74,   366,   324,    74,   232,   134,
     145,   230,   368,   200,   382,   153,   154,   283,   230,   367,
     230,   384,   386,   156,    20,    21,    22,   230,   230,   135,
     203,   373,   374,   202,   375,   343,   206,   134,   351,   352,
     299,   354,   300,   383,   341,   385,   231,   387,   209,   214,
     389,   215,   390,   217,   123,   190,   191,   225,   135,   123,
     347,   348,   192,   193,   134,   256,   257,   258,   259,   134,
      87,   198,   199,   237,   238,   363,   364,   234,   349,   252,
     253,   236,   254,   255,   242,   376,   378,   380,   134,   247,
     260,   261,   305,   308,   313,   309,   321,   283,   328,   322,
     323,   325,   327,   329,   330,   333,   337,   123,   315,   338,
     355,   311,   339,   344,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   345,   353,   358,   361,   134,   283,   362,   369,
     381,   388,   262,   134,   266,   134,   263,    86,   264,   138,
     265,   306,   134,    79,   302,   346,   126,   241,    56,   268,
     269,   134,   270,   271,   272,   273,   274,   275,   276,   277,
     278,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   336,     0,     0,   134,     0,
       0,     0,     0,     0,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,    25,    91,
      92,    93,    94,    95,    96,     0,    97,   134,     0,     0,
       0,   125,   335,     0,    99,   100,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,   134,     0,   280,
     268,   269,     0,   270,   271,   272,   273,   274,   275,   276,
     277,   278,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,    25,
      91,    92,    93,    94,    95,    96,     0,    97,     0,     0,
       0,     0,   125,     0,     0,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   268,   269,
     280,   270,   271,   272,   273,   274,   275,   276,   277,   278,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
       0,     0,     0,     0,    88,    89,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,   279,     0,    91,    92,
      93,    94,    95,    96,     0,    97,   140,     0,     0,     0,
     125,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,   184,     0,     0,     0,     0,   280,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,   132,     0,     0,     0,     0,
       0,     0,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,    20,    21,    22,    90,    25,    91,    92,    93,
      94,    95,    96,     0,    97,     0,     0,    88,    89,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,    90,
       0,    91,    92,    93,    94,    95,    96,   280,    97,   218,
       0,   133,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,     0,     0,   219,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    25,     0,     0,     0,     0,     0,     0,
       0,   208,   293,   209,     0,     0,     0,     0,     0,     0,
      42,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    88,    89,   231,   293,   209,     0,
       0,     0,     0,     0,     0,    42,    90,    25,    91,    92,
      93,    94,    95,    96,    55,    97,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    20,    21,    22,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
     340,    88,    89,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,   221,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,     0,    25,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,    95,    96,     0,    97,
       0,    25,    88,    89,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,    90,     0,    91,    92,    93,    94,
      95,    96,   331,    97,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,    25,   161,
       0,   162,    98,   314,     0,    99,   100,   101,   102,   103,
     104,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,     0,   161,     0,   162,    98,   372,     0,
      99,   100,   101,   102,   103,   104,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,     0,   161,
       0,   162,    98,    88,    89,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,    90,     0,    91,    92,    93,
      94,    95,    96,     0,    97,     0,    88,    89,     0,    98,
       0,     0,    99,   100,   101,   102,   103,   104,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,   243,    88,
      89,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,    90,     0,    91,    92,    93,    94,    95,    96,     0,
      97,     0,     0,   296,    88,    89,     0,     0,    99,   100,
     101,   102,   103,   104,     0,     0,    90,     0,    91,    92,
      93,    94,    95,    96,     0,    97,     0,    88,    89,     0,
     311,     0,     0,    99,   100,   101,   102,   103,   104,    90,
       0,    91,    92,    93,    94,    95,    96,     0,    97,     0,
       0,   342,    88,    89,     0,     0,    99,   100,   101,   102,
     103,   104,     0,     0,    90,     0,    91,    92,    93,    94,
      95,    96,     0,    97,   377,    88,    89,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,    90,     0,    91,
      92,    93,    94,    95,    96,     0,    97,   379,    88,    89,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
      90,     0,    91,    92,    93,    94,    95,    96,     0,    97,
       0,    88,    89,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,    90,     0,    91,    92,    93,    94,    95,
      96,     0,   152,     0,    88,    89,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,    90,     0,    91,    92,
      93,    94,    95,    96,     0,   155,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       0,    68,    68,    97,    27,    70,    48,    82,   207,    42,
     238,    75,    81,    52,   110,    71,   128,    42,    71,    71,
      34,    35,    36,   211,    77,    76,    77,    52,    28,    29,
      82,    98,    65,    33,    34,    35,    72,    61,    74,   327,
      65,    57,    58,    66,   232,    75,    71,   159,    73,    74,
      75,    90,    76,    78,    77,    61,    92,   152,   152,    74,
     155,   155,   137,    78,    70,    79,    61,   142,   356,   357,
      86,    87,    97,    79,   138,    70,   132,    71,   172,   148,
      61,    77,    97,    77,    79,   137,   161,    93,   287,    75,
     142,   187,   188,   189,    52,   128,    91,    93,   165,   165,
      49,    50,    75,    77,   171,   128,    92,   132,    61,   161,
      59,   205,   137,   138,    92,    73,    74,    75,   185,    93,
      78,    70,    75,    72,    61,    74,   159,   152,   327,   273,
     155,    77,    77,    70,   209,    72,   364,   152,   234,    97,
     155,   216,    79,   218,    61,    61,    61,    93,    93,    71,
     225,    61,    71,    70,    77,    70,    92,   209,    77,    70,
      76,    72,    79,   230,   216,    75,   218,    61,    91,   211,
      73,   238,   238,   225,    77,   208,    70,   321,    72,    75,
     138,    70,    88,    72,   278,    76,    77,    79,    71,   333,
      79,   216,    84,    85,   152,    71,   271,   155,   231,    82,
     223,    77,    71,    78,    71,    88,    89,   207,    77,   353,
      77,    71,    71,    96,    34,    35,    36,    77,    77,   271,
      51,   365,   366,    89,   368,   300,    76,   110,   322,   323,
      70,   325,    72,   377,   299,   379,    70,   381,    72,    71,
     384,    77,   386,    73,   311,    80,    81,    91,   300,   316,
     316,   318,    53,    54,   137,   194,   195,   196,   197,   142,
     283,    55,    56,    76,    77,    76,    77,    71,   320,   190,
     191,    61,   192,   193,    61,   369,   370,   371,   161,    61,
     198,   199,    73,    71,    73,    71,    91,   287,    61,    70,
      70,    70,    70,    93,    93,    91,    71,   364,   364,    71,
       8,    75,    73,    73,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    73,    91,    93,    71,   209,   327,    73,    70,
       5,    93,   200,   216,   204,   218,   201,    66,   202,    73,
     203,   223,   225,    57,   215,   311,    69,   166,    35,     3,
       4,   234,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,   287,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,   300,    -1,    -1,
      -1,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   320,    -1,    93,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      93,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    76,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    93,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    -1,    49,    50,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    61,
      -1,    63,    64,    65,    66,    67,    68,    93,    70,    17,
      -1,    73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    49,    50,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    34,    35,    36,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    62,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    66,    67,    68,    -1,    70,
      -1,    62,    49,    50,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    93,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    62,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    74,    75,    49,    50,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    49,    50,    -1,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    49,
      50,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    49,    50,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    49,    50,    -1,
      75,    -1,    -1,    78,    79,    80,    81,    82,    83,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    73,    49,    50,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    49,    50,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    61,    -1,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    49,    50,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      61,    -1,    63,    64,    65,    66,    67,    68,    -1,    70,
      -1,    49,    50,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    49,    50,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83
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
     142,   143,    17,    73,   100,   113,   117,   140,   126,   128,
      76,   127,    91,   129,   130,   137,   128,    76,    77,    76,
     133,   117,    70,   100,   100,    70,   100,   114,   116,   128,
     144,    72,    74,   147,   148,   149,   150,   151,    49,    50,
      59,    70,    72,    74,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    92,   115,   102,    79,    84,    85,
      80,    81,    53,    54,    57,    58,    86,    87,    55,    56,
      78,    88,    89,    51,    52,    90,    76,   155,    70,    72,
     137,   139,   145,   146,    71,    77,   140,    73,    17,    73,
     117,    76,   117,    77,    93,    91,    76,   144,   144,    71,
      77,    70,   139,   145,    71,   117,    61,    76,    77,   147,
      92,   151,    61,    71,    99,   114,   116,    61,   114,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   107,   108,   109,   110,   111,   116,     3,     4,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    61,
      93,   116,   118,   119,   152,   153,   154,   156,   157,   158,
     159,   160,   161,    71,   141,   145,    73,   117,   146,    70,
      72,    60,   143,   117,   117,    73,   130,   117,    71,    71,
     114,    75,   102,    73,    76,   147,   149,    71,    77,    73,
      91,    91,    70,    70,   117,    70,   152,    70,    61,    93,
      93,    93,   116,    91,    93,    76,   157,    71,    71,    73,
      71,   141,    73,   117,    73,    73,   148,   147,   114,   113,
     152,   116,   116,    91,   116,     8,   118,   158,    93,    93,
     152,    71,    73,    76,    77,    71,    71,   152,    71,    70,
     158,   158,    76,   152,   152,   152,   116,    71,   116,    71,
     116,     5,    71,   152,    71,   152,    71,   152,    93,   152,
     152
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
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   144,   144,   145,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     148,   148,   148,   148,   149,   150,   150,   151,   151,   152,
     152,   152,   152,   152,   152,   153,   153,   153,   154,   155,
     154,   156,   156,   157,   157,   158,   158,   159,   159,   159,
     160,   160,   160,   160,   160,   160,   161,   161,   161,   161,
     161,   162,   162,   163,   163,   165,   164
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
       1,     3,     5,     4,     4,     6,     6,     3,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     3,     4,
       1,     2,     3,     4,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     0,
       4,     1,     2,     1,     1,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     0,     4
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
#line 152 "bison/parser.yacc"
                                { (yyval.expr) = make_id_expr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1789 "parser.c"
    break;

  case 3: /* primary_expression: constant  */
#line 153 "bison/parser.yacc"
                                { (yyval.expr) = make_const_expr((yyvsp[0].constant)); }
#line 1795 "parser.c"
    break;

  case 4: /* primary_expression: string  */
#line 154 "bison/parser.yacc"
                                { (yyval.expr) = make_string_expr((yyvsp[0].sval)); }
#line 1801 "parser.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 155 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1807 "parser.c"
    break;

  case 6: /* constant: CONST_INT  */
#line 159 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_INT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1813 "parser.c"
    break;

  case 7: /* constant: CONST_FLOAT  */
#line 160 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_FLOAT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1819 "parser.c"
    break;

  case 8: /* constant: ENUM_CONST  */
#line 161 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_ENUM, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1825 "parser.c"
    break;

  case 9: /* string: STR_LITERAL  */
#line 164 "bison/parser.yacc"
                    { (yyval.sval) = (yyvsp[0].sval); free((yyvsp[0].sval)); }
#line 1831 "parser.c"
    break;

  case 10: /* string: FUNC_NAME  */
#line 165 "bison/parser.yacc"
                    { (yyval.sval) = func_name(); }
#line 1837 "parser.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 168 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1843 "parser.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 169 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_SUBSCRIPT, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1849 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 170 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-2].expr), 0); }
#line 1855 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 171 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1861 "parser.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 172 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_DOT, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1867 "parser.c"
    break;

  case 16: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 173 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_ARROW, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1873 "parser.c"
    break;

  case 17: /* postfix_expression: postfix_expression INCREMENT  */
#line 174 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_INCR, (yyvsp[-1].expr), 0); }
#line 1879 "parser.c"
    break;

  case 18: /* postfix_expression: postfix_expression DECREMENT  */
#line 175 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_DECR, (yyvsp[-1].expr), 0); }
#line 1885 "parser.c"
    break;

  case 19: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 176 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-4].type_name), (yyvsp[-1].init_list)); }
#line 1891 "parser.c"
    break;

  case 20: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 177 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-5].type_name), (yyvsp[-2].init_list)); }
#line 1897 "parser.c"
    break;

  case 21: /* argument_expression_list: assignment_expression  */
#line 181 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), 0); }
#line 1903 "parser.c"
    break;

  case 22: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 182 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1909 "parser.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 186 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1915 "parser.c"
    break;

  case 24: /* unary_expression: INCREMENT unary_expression  */
#line 187 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_INCR, (yyvsp[0].expr), 0); }
#line 1921 "parser.c"
    break;

  case 25: /* unary_expression: DECREMENT unary_expression  */
#line 188 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_DECR, (yyvsp[0].expr), 0); }
#line 1927 "parser.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 189 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[0].expr), 0); }
#line 1933 "parser.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 190 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_SIZEOF_EXPR, (yyvsp[0].expr), 0); }
#line 1939 "parser.c"
    break;

  case 28: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 191 "bison/parser.yacc"
                                            { (yyval.expr) = make_sizeof_expr((yyvsp[-1].type_name)); }
#line 1945 "parser.c"
    break;

  case 29: /* unary_operator: '&'  */
#line 195 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_ADDREF; }
#line 1951 "parser.c"
    break;

  case 30: /* unary_operator: '*'  */
#line 196 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_DEREF; }
#line 1957 "parser.c"
    break;

  case 31: /* unary_operator: '+'  */
#line 197 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_PLUS; }
#line 1963 "parser.c"
    break;

  case 32: /* unary_operator: '-'  */
#line 198 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_MINUS; }
#line 1969 "parser.c"
    break;

  case 33: /* unary_operator: '~'  */
#line 199 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_BITNOT; }
#line 1975 "parser.c"
    break;

  case 34: /* unary_operator: '!'  */
#line 200 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_LOGNOT; }
#line 1981 "parser.c"
    break;

  case 35: /* cast_expression: unary_expression  */
#line 204 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1987 "parser.c"
    break;

  case 36: /* cast_expression: '(' type_name ')' cast_expression  */
#line 205 "bison/parser.yacc"
                                            { (yyval.expr) = make_cast_expr((yyvsp[-2].type_name), (yyvsp[0].expr)); }
#line 1993 "parser.c"
    break;

  case 37: /* multiplicative_expression: cast_expression  */
#line 209 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1999 "parser.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 210 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2005 "parser.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 211 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2011 "parser.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 212 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2017 "parser.c"
    break;

  case 41: /* additive_expression: multiplicative_expression  */
#line 216 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2023 "parser.c"
    break;

  case 42: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 217 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2029 "parser.c"
    break;

  case 43: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 218 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2035 "parser.c"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 222 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2041 "parser.c"
    break;

  case 45: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 223 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2047 "parser.c"
    break;

  case 46: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 224 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_RSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2053 "parser.c"
    break;

  case 47: /* relational_expression: shift_expression  */
#line 228 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2059 "parser.c"
    break;

  case 48: /* relational_expression: relational_expression '<' shift_expression  */
#line 229 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2065 "parser.c"
    break;

  case 49: /* relational_expression: relational_expression '>' shift_expression  */
#line 230 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2071 "parser.c"
    break;

  case 50: /* relational_expression: relational_expression LEQ shift_expression  */
#line 231 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2077 "parser.c"
    break;

  case 51: /* relational_expression: relational_expression GEQ shift_expression  */
#line 232 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2083 "parser.c"
    break;

  case 52: /* equality_expression: relational_expression  */
#line 236 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2089 "parser.c"
    break;

  case 53: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 237 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2095 "parser.c"
    break;

  case 54: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 238 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2101 "parser.c"
    break;

  case 55: /* and_expression: equality_expression  */
#line 242 "bison/parser.yacc"
                                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2107 "parser.c"
    break;

  case 56: /* and_expression: and_expression '&' equality_expression  */
#line 243 "bison/parser.yacc"
                                                    { (yyval.expr) = make_expr(EXPR_BITAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2113 "parser.c"
    break;

  case 57: /* exclusive_or_expression: and_expression  */
#line 247 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2119 "parser.c"
    break;

  case 58: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 248 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_BITXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2125 "parser.c"
    break;

  case 59: /* inclusive_or_expression: exclusive_or_expression  */
#line 252 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2131 "parser.c"
    break;

  case 60: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 253 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_BITOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2137 "parser.c"
    break;

  case 61: /* logical_and_expression: inclusive_or_expression  */
#line 257 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2143 "parser.c"
    break;

  case 62: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 258 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2149 "parser.c"
    break;

  case 63: /* logical_or_expression: logical_and_expression  */
#line 262 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2155 "parser.c"
    break;

  case 64: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 263 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2161 "parser.c"
    break;

  case 65: /* conditional_expression: logical_or_expression  */
#line 267 "bison/parser.yacc"
                                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2167 "parser.c"
    break;

  case 66: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 268 "bison/parser.yacc"
                                                                            { (yyval.expr) = make_ternary_expr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2173 "parser.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 272 "bison/parser.yacc"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2179 "parser.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 273 "bison/parser.yacc"
                                                                        { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2185 "parser.c"
    break;

  case 69: /* assignment_operator: '='  */
#line 277 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ASSIGN; }
#line 2191 "parser.c"
    break;

  case 70: /* assignment_operator: MUL_ASSIGN  */
#line 278 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MUL_ASSIGN; }
#line 2197 "parser.c"
    break;

  case 71: /* assignment_operator: DIV_ASSIGN  */
#line 279 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_DIV_ASSIGN; }
#line 2203 "parser.c"
    break;

  case 72: /* assignment_operator: MOD_ASSIGN  */
#line 280 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MOD_ASSIGN; }
#line 2209 "parser.c"
    break;

  case 73: /* assignment_operator: ADD_ASSIGN  */
#line 281 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ADD_ASSIGN; }
#line 2215 "parser.c"
    break;

  case 74: /* assignment_operator: SUB_ASSIGN  */
#line 282 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_SUB_ASSIGN; }
#line 2221 "parser.c"
    break;

  case 75: /* assignment_operator: LSHIFT_ASSIGN  */
#line 283 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_LSHIFT_ASSIGN; }
#line 2227 "parser.c"
    break;

  case 76: /* assignment_operator: RSHIFT_ASSIGN  */
#line 284 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_RSHIFT_ASSIGN; }
#line 2233 "parser.c"
    break;

  case 77: /* assignment_operator: AND_ASSIGN  */
#line 285 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_AND_ASSIGN; }
#line 2239 "parser.c"
    break;

  case 78: /* assignment_operator: XOR_ASSIGN  */
#line 286 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_XOR_ASSIGN; }
#line 2245 "parser.c"
    break;

  case 79: /* assignment_operator: OR_ASSIGN  */
#line 287 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_OR_ASSIGN; }
#line 2251 "parser.c"
    break;

  case 80: /* expression: assignment_expression  */
#line 291 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2257 "parser.c"
    break;

  case 81: /* expression: expression ',' assignment_expression  */
#line 292 "bison/parser.yacc"
                                                { (yyval.expr) = make_expr(EXPR_COMMA, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2263 "parser.c"
    break;

  case 82: /* constant_expression: conditional_expression  */
#line 296 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); (yyval.expr)->constant = 1; }
#line 2269 "parser.c"
    break;

  case 83: /* declaration: declaration_specifiers ';'  */
#line 300 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), 0); }
#line 2275 "parser.c"
    break;

  case 84: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 302 "bison/parser.yacc"
    {
        (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].init_decltr));
        add_typedef_type((yyval.decl));
    }
#line 2284 "parser.c"
    break;

  case 85: /* declaration_specifiers: storage_class_specifier  */
#line 309 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class(0, (yyvsp[0].int_val)); }
#line 2290 "parser.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 310 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2296 "parser.c"
    break;

  case 87: /* declaration_specifiers: type_specifier  */
#line 311 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2302 "parser.c"
    break;

  case 88: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 312 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2308 "parser.c"
    break;

  case 89: /* declaration_specifiers: type_qualifier  */
#line 313 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2314 "parser.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 314 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2320 "parser.c"
    break;

  case 91: /* declaration_specifiers: function_specifier  */
#line 315 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec(0, (yyvsp[0].int_val)); }
#line 2326 "parser.c"
    break;

  case 92: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 316 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2332 "parser.c"
    break;

  case 93: /* init_declarator_list: init_declarator  */
#line 320 "bison/parser.yacc"
                                                    { (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2338 "parser.c"
    break;

  case 94: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 321 "bison/parser.yacc"
                                                    { add_init_decltr((yyvsp[-2].init_decltr), (yyvsp[0].init_decltr)); (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2344 "parser.c"
    break;

  case 95: /* init_declarator: declarator  */
#line 325 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[0].decltr), 0); }
#line 2350 "parser.c"
    break;

  case 96: /* init_declarator: declarator '=' initializer  */
#line 326 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[-2].decltr), (yyvsp[0].initializer)); }
#line 2356 "parser.c"
    break;

  case 97: /* storage_class_specifier: TYPEDEF  */
#line 330 "bison/parser.yacc"
                    { (yyval.int_val) = SC_TYPEDEF; }
#line 2362 "parser.c"
    break;

  case 98: /* storage_class_specifier: EXTERN  */
#line 331 "bison/parser.yacc"
                    { (yyval.int_val) = SC_EXTERN; }
#line 2368 "parser.c"
    break;

  case 99: /* storage_class_specifier: STATIC  */
#line 332 "bison/parser.yacc"
                    { (yyval.int_val) = SC_STATIC; }
#line 2374 "parser.c"
    break;

  case 100: /* storage_class_specifier: AUTO  */
#line 333 "bison/parser.yacc"
                    { (yyval.int_val) = SC_AUTO; }
#line 2380 "parser.c"
    break;

  case 101: /* storage_class_specifier: REGISTER  */
#line 334 "bison/parser.yacc"
                    { (yyval.int_val) = SC_REGISTER; }
#line 2386 "parser.c"
    break;

  case 102: /* type_specifier: VOID  */
#line 338 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_VOID); }
#line 2392 "parser.c"
    break;

  case 103: /* type_specifier: CHAR  */
#line 339 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_CHAR); }
#line 2398 "parser.c"
    break;

  case 104: /* type_specifier: SHORT  */
#line 340 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SHORT); }
#line 2404 "parser.c"
    break;

  case 105: /* type_specifier: INT  */
#line 341 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_INT); }
#line 2410 "parser.c"
    break;

  case 106: /* type_specifier: LONG  */
#line 342 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_LONG); }
#line 2416 "parser.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 343 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_FLOAT); }
#line 2422 "parser.c"
    break;

  case 108: /* type_specifier: DOUBLE  */
#line 344 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_DOUBLE); }
#line 2428 "parser.c"
    break;

  case 109: /* type_specifier: SIGNED  */
#line 345 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SIGNED); }
#line 2434 "parser.c"
    break;

  case 110: /* type_specifier: UNSIGNED  */
#line 346 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_UNSIGNED); }
#line 2440 "parser.c"
    break;

  case 111: /* type_specifier: BOOL  */
#line 347 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_BOOL); }
#line 2446 "parser.c"
    break;

  case 112: /* type_specifier: COMPLEX  */
#line 348 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_COMPLEX); }
#line 2452 "parser.c"
    break;

  case 113: /* type_specifier: IMAGINARY  */
#line 349 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_IMAGINARY); }
#line 2458 "parser.c"
    break;

  case 114: /* type_specifier: struct_or_union_specifier  */
#line 350 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_sou_type_spec((yyvsp[0].sou_spec)); }
#line 2464 "parser.c"
    break;

  case 115: /* type_specifier: enum_specifier  */
#line 351 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_enum_type_spec((yyvsp[0].enum_spec)); }
#line 2470 "parser.c"
    break;

  case 116: /* type_specifier: TYPEDEF_NAME  */
#line 352 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_typedef_type_spec((yyvsp[0].sval)); }
#line 2476 "parser.c"
    break;

  case 117: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 356 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-4].int_val), (yyvsp[-3].sval), (yyvsp[-1].struct_decl_list)); }
#line 2482 "parser.c"
    break;

  case 118: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 357 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-3].int_val), 0, (yyvsp[-1].struct_decl_list)); }
#line 2488 "parser.c"
    break;

  case 119: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 358 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-1].int_val), (yyvsp[0].sval), 0); }
#line 2494 "parser.c"
    break;

  case 120: /* struct_or_union: STRUCT  */
#line 362 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_STRUCT; }
#line 2500 "parser.c"
    break;

  case 121: /* struct_or_union: UNION  */
#line 363 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_UNION; }
#line 2506 "parser.c"
    break;

  case 122: /* struct_declaration_list: struct_declaration  */
#line 367 "bison/parser.yacc"
                                                        { (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2512 "parser.c"
    break;

  case 123: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 368 "bison/parser.yacc"
                                                        { add_struct_decl((yyvsp[-1].struct_decl_list), (yyvsp[0].struct_decl_list)); (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2518 "parser.c"
    break;

  case 124: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 372 "bison/parser.yacc"
                                                                { (yyval.struct_decl_list) = make_struct_decl_list(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].struct_decltr_list)); }
#line 2524 "parser.c"
    break;

  case 125: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 376 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2530 "parser.c"
    break;

  case 126: /* specifier_qualifier_list: type_specifier  */
#line 377 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2536 "parser.c"
    break;

  case 127: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 378 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2542 "parser.c"
    break;

  case 128: /* specifier_qualifier_list: type_qualifier  */
#line 379 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2548 "parser.c"
    break;

  case 129: /* struct_declarator_list: struct_declarator  */
#line 383 "bison/parser.yacc"
                                                        { (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2554 "parser.c"
    break;

  case 130: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 384 "bison/parser.yacc"
                                                        { add_struct_decltr((yyvsp[-2].struct_decltr_list), (yyvsp[0].struct_decltr_list)); (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2560 "parser.c"
    break;

  case 131: /* struct_declarator: declarator  */
#line 388 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[0].decltr), 0); }
#line 2566 "parser.c"
    break;

  case 132: /* struct_declarator: ':' constant_expression  */
#line 389 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list(0, (yyvsp[0].expr)); }
#line 2572 "parser.c"
    break;

  case 133: /* struct_declarator: declarator ':' constant_expression  */
#line 390 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[-2].decltr), (yyvsp[0].expr)); }
#line 2578 "parser.c"
    break;

  case 134: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 394 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-1].enumerator_list)); }
#line 2584 "parser.c"
    break;

  case 135: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 395 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-3].sval), (yyvsp[-1].enumerator_list)); }
#line 2590 "parser.c"
    break;

  case 136: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 396 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-2].enumerator_list)); }
#line 2596 "parser.c"
    break;

  case 137: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 397 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-4].sval), (yyvsp[-2].enumerator_list)); }
#line 2602 "parser.c"
    break;

  case 138: /* enum_specifier: ENUM IDENTIFIER  */
#line 398 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[0].sval), 0); }
#line 2608 "parser.c"
    break;

  case 139: /* enumerator_list: enumerator  */
#line 402 "bison/parser.yacc"
                                            { (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2614 "parser.c"
    break;

  case 140: /* enumerator_list: enumerator_list ',' enumerator  */
#line 403 "bison/parser.yacc"
                                            { add_enumerator((yyvsp[-2].enumerator_list), (yyvsp[0].enumerator_list)); (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2620 "parser.c"
    break;

  case 141: /* enumerator: enumeration_constant  */
#line 407 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[0].sval), 0); free((yyvsp[0].sval)); }
#line 2626 "parser.c"
    break;

  case 142: /* enumerator: enumeration_constant '=' constant_expression  */
#line 408 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[-2].sval), (yyvsp[0].expr)); free((yyvsp[-2].sval)); }
#line 2632 "parser.c"
    break;

  case 143: /* enumeration_constant: IDENTIFIER  */
#line 412 "bison/parser.yacc"
                    { sym_define_enum((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); }
#line 2638 "parser.c"
    break;

  case 144: /* type_qualifier: CONST  */
#line 415 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_CONST; }
#line 2644 "parser.c"
    break;

  case 145: /* type_qualifier: RESTRICT  */
#line 416 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_RESTRICT; }
#line 2650 "parser.c"
    break;

  case 146: /* type_qualifier: VOLATILE  */
#line 417 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_VOLATILE; }
#line 2656 "parser.c"
    break;

  case 147: /* function_specifier: INLINE  */
#line 421 "bison/parser.yacc"
                    { (yyval.int_val) = FS_INLINE; }
#line 2662 "parser.c"
    break;

  case 148: /* declarator: pointer direct_declarator  */
#line 427 "bison/parser.yacc"
                                    { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); (yyval.decltr) = (yyvsp[0].decltr); }
#line 2668 "parser.c"
    break;

  case 149: /* declarator: direct_declarator  */
#line 428 "bison/parser.yacc"
                                    { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2674 "parser.c"
    break;

  case 150: /* direct_declarator: IDENTIFIER  */
#line 433 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_id_decltr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2680 "parser.c"
    break;

  case 151: /* direct_declarator: '(' declarator ')'  */
#line 434 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2686 "parser.c"
    break;

  case 152: /* direct_declarator: direct_declarator '[' type_qualifier_list constant_expression ']'  */
#line 435 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr), 0); }
#line 2692 "parser.c"
    break;

  case 153: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 436 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), (yyvsp[-1].type_qual_list), 0, 0); }
#line 2698 "parser.c"
    break;

  case 154: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 437 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr), 0); }
#line 2704 "parser.c"
    break;

  case 155: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list constant_expression ']'  */
#line 438 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-5].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr), 1); }
#line 2710 "parser.c"
    break;

  case 156: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC constant_expression ']'  */
#line 439 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-5].decltr), (yyvsp[-3].type_qual_list), (yyvsp[-1].expr), 1); }
#line 2716 "parser.c"
    break;

  case 157: /* direct_declarator: direct_declarator '[' ']'  */
#line 440 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0, 0); }
#line 2722 "parser.c"
    break;

  case 158: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 441 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2728 "parser.c"
    break;

  case 159: /* direct_declarator: direct_declarator '(' ')'  */
#line 442 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2734 "parser.c"
    break;

  case 160: /* pointer: '*'  */
#line 446 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, 0); }
#line 2740 "parser.c"
    break;

  case 161: /* pointer: '*' type_qualifier_list  */
#line 447 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[0].type_qual_list), 0); }
#line 2746 "parser.c"
    break;

  case 162: /* pointer: '*' pointer  */
#line 448 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, (yyvsp[0].pointer)); }
#line 2752 "parser.c"
    break;

  case 163: /* pointer: '*' type_qualifier_list pointer  */
#line 449 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[-1].type_qual_list), (yyvsp[0].pointer)); }
#line 2758 "parser.c"
    break;

  case 164: /* type_qualifier_list: type_qualifier  */
#line 453 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list(0, (yyvsp[0].int_val)); }
#line 2764 "parser.c"
    break;

  case 165: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 454 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list((yyvsp[-1].type_qual_list), (yyvsp[0].int_val)); }
#line 2770 "parser.c"
    break;

  case 166: /* parameter_type_list: parameter_list  */
#line 459 "bison/parser.yacc"
                                        { set_param_ellipsis(0); (yyval.param_list) = (yyvsp[0].param_list); }
#line 2776 "parser.c"
    break;

  case 167: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 460 "bison/parser.yacc"
                                        { set_param_ellipsis(1); (yyval.param_list) = (yyvsp[-2].param_list); }
#line 2782 "parser.c"
    break;

  case 168: /* parameter_list: parameter_declaration  */
#line 464 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list(0, (yyvsp[0].decl)); }
#line 2788 "parser.c"
    break;

  case 169: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 465 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list((yyvsp[-2].param_list), (yyvsp[0].decl)); }
#line 2794 "parser.c"
    break;

  case 170: /* parameter_declaration: declaration_specifiers declarator  */
#line 469 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 0); }
#line 2800 "parser.c"
    break;

  case 171: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 470 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 1); }
#line 2806 "parser.c"
    break;

  case 172: /* parameter_declaration: declaration_specifiers  */
#line 471 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[0].decl_spec_list)), 0, 0); }
#line 2812 "parser.c"
    break;

  case 173: /* type_name: specifier_qualifier_list  */
#line 475 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[0].decl_spec_list)), 0); }
#line 2818 "parser.c"
    break;

  case 174: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 476 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr)); }
#line 2824 "parser.c"
    break;

  case 175: /* abstract_declarator: pointer  */
#line 480 "bison/parser.yacc"
                                                { (yyval.decltr) = make_empty_decltr((yyvsp[0].pointer)); }
#line 2830 "parser.c"
    break;

  case 176: /* abstract_declarator: direct_abstract_declarator  */
#line 481 "bison/parser.yacc"
                                                { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2836 "parser.c"
    break;

  case 177: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 482 "bison/parser.yacc"
                                                { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); }
#line 2842 "parser.c"
    break;

  case 178: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 486 "bison/parser.yacc"
                                                                    { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2848 "parser.c"
    break;

  case 179: /* direct_abstract_declarator: '[' ']'  */
#line 487 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0, 0); }
#line 2854 "parser.c"
    break;

  case 180: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 488 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, (yyvsp[-1].expr), 0); }
#line 2860 "parser.c"
    break;

  case 181: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 489 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0, 0); }
#line 2866 "parser.c"
    break;

  case 182: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 490 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr), 0); }
#line 2872 "parser.c"
    break;

  case 183: /* direct_abstract_declarator: '(' ')'  */
#line 491 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, 0); }
#line 2878 "parser.c"
    break;

  case 184: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 492 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, (yyvsp[-1].param_list)); }
#line 2884 "parser.c"
    break;

  case 185: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 493 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2890 "parser.c"
    break;

  case 186: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 494 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2896 "parser.c"
    break;

  case 187: /* initializer: assignment_expression  */
#line 498 "bison/parser.yacc"
                                        { (yyval.initializer) = make_expr_init((yyvsp[0].expr)); }
#line 2902 "parser.c"
    break;

  case 188: /* initializer: '{' initializer_list '}'  */
#line 499 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-1].init_list)); }
#line 2908 "parser.c"
    break;

  case 189: /* initializer: '{' initializer_list ',' '}'  */
#line 500 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-2].init_list)); }
#line 2914 "parser.c"
    break;

  case 190: /* initializer_list: initializer  */
#line 504 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, 0, (yyvsp[0].initializer)); }
#line 2920 "parser.c"
    break;

  case 191: /* initializer_list: designation initializer  */
#line 505 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, (yyvsp[-1].designation), (yyvsp[0].initializer)); }
#line 2926 "parser.c"
    break;

  case 192: /* initializer_list: initializer_list ',' initializer  */
#line 506 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-2].init_list), 0, (yyvsp[0].initializer)); }
#line 2932 "parser.c"
    break;

  case 193: /* initializer_list: initializer_list ',' designation initializer  */
#line 507 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-3].init_list), (yyvsp[-1].designation), (yyvsp[0].initializer)); }
#line 2938 "parser.c"
    break;

  case 194: /* designation: designator_list '='  */
#line 511 "bison/parser.yacc"
                                { (yyval.designation) = (yyvsp[-1].designation); }
#line 2944 "parser.c"
    break;

  case 195: /* designator_list: designator  */
#line 515 "bison/parser.yacc"
                                        { (yyval.designation) = (yyvsp[0].designation); }
#line 2950 "parser.c"
    break;

  case 196: /* designator_list: designator_list designator  */
#line 516 "bison/parser.yacc"
                                        { add_designator((yyvsp[-1].designation), (yyvsp[0].designation)); (yyval.designation) = (yyvsp[0].designation); }
#line 2956 "parser.c"
    break;

  case 197: /* designator: '[' constant_expression ']'  */
#line 520 "bison/parser.yacc"
                                        { (yyval.designation) = make_arr_designator((yyvsp[-1].expr)); }
#line 2962 "parser.c"
    break;

  case 198: /* designator: '.' IDENTIFIER  */
#line 521 "bison/parser.yacc"
                                        { (yyval.designation) = make_member_designator((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2968 "parser.c"
    break;

  case 199: /* statement: labeled_statement  */
#line 525 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2974 "parser.c"
    break;

  case 200: /* statement: compound_statement  */
#line 526 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2980 "parser.c"
    break;

  case 201: /* statement: expression_statement  */
#line 527 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2986 "parser.c"
    break;

  case 202: /* statement: selection_statement  */
#line 528 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2992 "parser.c"
    break;

  case 203: /* statement: iteration_statement  */
#line 529 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2998 "parser.c"
    break;

  case 204: /* statement: jump_statement  */
#line 530 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3004 "parser.c"
    break;

  case 205: /* labeled_statement: IDENTIFIER ':' statement  */
#line 534 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_labeled_stmt((yyvsp[-2].sval), (yyvsp[0].stmt)); }
#line 3010 "parser.c"
    break;

  case 206: /* labeled_statement: CASE constant_expression ':' statement  */
#line 535 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_case_stmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3016 "parser.c"
    break;

  case 207: /* labeled_statement: DEFAULT ':' statement  */
#line 536 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_default_stmt((yyvsp[0].stmt)); }
#line 3022 "parser.c"
    break;

  case 208: /* compound_statement: '{' '}'  */
#line 540 "bison/parser.yacc"
                            { (yyval.stmt) = make_compound_stmt(0); }
#line 3028 "parser.c"
    break;

  case 209: /* $@1: %empty  */
#line 541 "bison/parser.yacc"
                            { sym_push_scope(); }
#line 3034 "parser.c"
    break;

  case 210: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 543 "bison/parser.yacc"
                        { sym_pop_scope(); (yyval.stmt) = make_compound_stmt((yyvsp[-1].block_list)); }
#line 3040 "parser.c"
    break;

  case 211: /* block_item_list: block_item  */
#line 547 "bison/parser.yacc"
                                        { (yyval.block_list) = (yyvsp[0].block_list); }
#line 3046 "parser.c"
    break;

  case 212: /* block_item_list: block_item_list block_item  */
#line 548 "bison/parser.yacc"
                                        { add_block_item((yyvsp[-1].block_list), (yyvsp[0].block_list)); (yyval.block_list) = (yyvsp[0].block_list); }
#line 3052 "parser.c"
    break;

  case 213: /* block_item: declaration  */
#line 552 "bison/parser.yacc"
                        { (yyval.block_list) = make_decl_block_item((yyvsp[0].decl)); }
#line 3058 "parser.c"
    break;

  case 214: /* block_item: statement  */
#line 553 "bison/parser.yacc"
                        { (yyval.block_list) = make_stmt_block_item((yyvsp[0].stmt)); }
#line 3064 "parser.c"
    break;

  case 215: /* expression_statement: ';'  */
#line 557 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt(0); }
#line 3070 "parser.c"
    break;

  case 216: /* expression_statement: expression ';'  */
#line 558 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt((yyvsp[-1].expr)); }
#line 3076 "parser.c"
    break;

  case 217: /* selection_statement: IF '(' expression ')' statement  */
#line 562 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3082 "parser.c"
    break;

  case 218: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 563 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 3088 "parser.c"
    break;

  case 219: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 564 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_SWITCH, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3094 "parser.c"
    break;

  case 220: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 568 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_WHILE, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3100 "parser.c"
    break;

  case 221: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 569 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_DO, (yyvsp[-2].expr), (yyvsp[-5].stmt), 0); }
#line 3106 "parser.c"
    break;

  case 222: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 570 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-3].stmt), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3112 "parser.c"
    break;

  case 223: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 571 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3118 "parser.c"
    break;

  case 224: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 572 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-3].decl), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3124 "parser.c"
    break;

  case 225: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 573 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-4].decl), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3130 "parser.c"
    break;

  case 226: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 577 "bison/parser.yacc"
                                { (yyval.stmt) = make_goto_stmt((yyvsp[-1].sval)); }
#line 3136 "parser.c"
    break;

  case 227: /* jump_statement: CONTINUE ';'  */
#line 578 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_CONTINUE); }
#line 3142 "parser.c"
    break;

  case 228: /* jump_statement: BREAK ';'  */
#line 579 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_BREAK); }
#line 3148 "parser.c"
    break;

  case 229: /* jump_statement: RETURN ';'  */
#line 580 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_RETURN); }
#line 3154 "parser.c"
    break;

  case 230: /* jump_statement: RETURN expression ';'  */
#line 581 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt((yyvsp[-1].expr)); }
#line 3160 "parser.c"
    break;

  case 231: /* translation_unit: external_declaration  */
#line 585 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit(0, (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3166 "parser.c"
    break;

  case 232: /* translation_unit: translation_unit external_declaration  */
#line 586 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit((yyvsp[-1].translation_unit), (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3172 "parser.c"
    break;

  case 233: /* external_declaration: function_definition  */
#line 590 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_func_ext_decl((yyvsp[0].func_def)); }
#line 3178 "parser.c"
    break;

  case 234: /* external_declaration: declaration  */
#line 591 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_decl_ext_decl((yyvsp[0].decl)); }
#line 3184 "parser.c"
    break;

  case 235: /* $@2: %empty  */
#line 595 "bison/parser.yacc"
                                                                { set_func_name(get_decltr_id((yyvsp[0].decltr))); }
#line 3190 "parser.c"
    break;

  case 236: /* function_definition: declaration_specifiers declarator $@2 compound_statement  */
#line 597 "bison/parser.yacc"
    {
        func_ended();
        (yyval.func_def) = make_func_def(make_decl_specs((yyvsp[-3].decl_spec_list)), (yyvsp[-2].decltr), (yyvsp[0].stmt));
    }
#line 3199 "parser.c"
    break;


#line 3203 "parser.c"

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

#line 603 "bison/parser.yacc"
