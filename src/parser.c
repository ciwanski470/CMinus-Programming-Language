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
#define YYLAST   1573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  384

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
     433,   434,   435,   436,   437,   438,   439,   440,   444,   445,
     446,   447,   451,   452,   457,   458,   462,   463,   467,   468,
     469,   473,   474,   478,   479,   480,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   496,   497,   498,   502,   503,
     504,   505,   509,   513,   514,   518,   519,   523,   524,   525,
     526,   527,   528,   532,   533,   534,   538,   539,   539,   545,
     546,   550,   551,   555,   556,   560,   561,   562,   566,   567,
     568,   569,   570,   571,   575,   576,   577,   578,   579,   583,
     584,   588,   589,   593,   593
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

#define YYPACT_NINF (-299)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-234)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1104,  -299,  -299,  -299,  -299,  -299,  -299,    39,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,   -38,  1104,  1104,
    -299,    65,  -299,  1104,  1104,   819,  -299,  -299,   -49,     8,
    -299,     5,   -14,  -299,    -5,  -299,   -45,    36,    12,  -299,
    -299,    -1,  1191,  -299,  -299,  -299,  -299,     8,  -299,   132,
    -299,     9,    75,  -299,  -299,   -14,     5,  -299,  1279,     4,
     867,   947,    36,  1191,  1191,   503,  -299,   -21,  1191,   142,
    -299,   -13,  1444,  -299,  -299,  -299,  -299,    79,  1467,  1467,
    -299,  -299,  -299,  -299,  -299,  -299,  1490,   750,  1252,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,    89,   232,
    1444,  -299,    70,   141,   176,   -19,    63,    56,   112,    94,
     174,   -37,  -299,  -299,  -299,   151,  -299,  -299,    72,   167,
     154,  -299,  -299,  -299,  -299,   178,   987,   942,  -299,  -299,
    -299,  1444,     3,  -299,   162,  -299,  -299,    46,  -299,  -299,
    -299,   750,  -299,  -299,   750,  -299,  -299,   -27,    86,   184,
    1444,   197,  -299,   158,  1279,   -47,  -299,  -299,  -299,   199,
    1302,  1444,   206,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  1444,  -299,  1444,  1444,  1444,  1444,
    1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,
    1444,  1444,  1444,  1444,  1444,  -299,   420,   666,  1325,  -299,
      92,  -299,   135,  -299,  1056,  -299,  -299,   208,  -299,  -299,
     -21,  -299,  1444,  -299,   211,   212,  -299,  1444,   731,   145,
    -299,  1350,   213,  -299,  -299,  1182,  -299,  -299,  -299,  -299,
    -299,   -15,  -299,    64,  -299,  -299,  -299,  -299,  -299,    70,
      70,   141,   141,   176,   176,   176,   176,   -19,   -19,    63,
      56,   112,    94,   174,    59,   194,   217,   218,  1444,   219,
     508,   240,   250,   220,   222,  1094,   221,  -299,    16,  -299,
     -38,  -299,  -299,  -299,   332,  -299,  -299,  -299,  -299,  -299,
    -299,   245,   246,  -299,   247,   135,   924,  1373,  -299,  -299,
    -299,  -299,  -299,   243,   243,  -299,  1252,  -299,  -299,  -299,
    -299,  1279,  -299,  1444,  -299,  1444,   508,  1444,  1444,   228,
    1444,   313,   587,   230,  -299,  -299,  -299,    27,   508,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,   254,  -299,   253,   160,
    -299,  -299,  -299,  -299,    95,    96,   508,   103,   257,  1118,
    1118,  -299,  -299,  -299,  -299,  -299,  -299,  1217,   508,   508,
    -299,   508,  1444,  1398,  1421,  -299,   324,  -299,  -299,   105,
     508,   108,   508,   113,   508,   237,  -299,   508,  -299,   508,
    -299,  -299,  -299,  -299
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    98,    99,   100,   101,   147,     0,   120,   121,
     103,   105,   104,   106,   107,   108,   111,   102,   109,   110,
     144,   145,   146,   112,   113,   116,   232,     0,    85,    87,
     114,     0,   115,    89,    91,     0,   229,   231,   138,     0,
     150,     0,   158,    83,     0,    93,    95,   149,     0,    86,
      88,   119,     0,    90,    92,     1,   230,     0,   143,     0,
     139,   141,     0,   162,   160,   159,     0,    84,     0,     0,
       0,     0,   148,     0,   126,     0,   122,     0,   128,     0,
     134,     0,     0,   151,   163,   161,    94,    95,     0,     0,
       2,     8,     6,     7,     9,    10,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    11,     3,     4,    23,    35,
       0,    37,    41,    44,    47,    52,    55,    57,    59,    61,
      63,    65,    67,   185,    96,   207,   234,   157,   170,     0,
     164,   166,   155,    35,    82,     0,     0,     0,   125,   118,
     123,     0,     0,   129,   131,   127,   135,     0,   136,   140,
     142,     0,    24,    25,     0,    27,    80,     0,   171,     0,
       0,     0,   188,     0,     0,     0,   193,    17,    18,     0,
       0,     0,     0,    73,    74,    70,    71,    72,    77,    79,
      78,    75,    76,    69,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,     0,     0,     0,   168,
     173,   169,   174,   156,     0,   154,   153,     0,   117,   132,
       0,   124,     0,   137,     0,     0,     5,     0,     0,   173,
     172,     0,     0,   196,   186,     0,   189,   192,   194,    16,
      13,     0,    21,     0,    15,    68,    38,    39,    40,    42,
      43,    45,    46,    50,    51,    48,    49,    53,    54,    56,
      58,    60,    62,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,   213,     0,   211,
       0,   212,   197,   198,     0,   209,   199,   200,   201,   202,
     181,     0,     0,   177,     0,   175,     0,     0,   165,   167,
     152,   130,   133,     0,    28,    81,     0,    36,   195,   187,
     190,     0,    14,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,     0,     0,   214,
     208,   210,   182,   176,   178,   183,     0,   179,     0,     0,
     191,    22,    66,   205,     0,     0,     0,     0,     0,     0,
       0,   224,   228,   203,   184,   180,    19,     0,     0,     0,
     204,     0,     0,     0,     0,    20,   215,   217,   218,     0,
       0,     0,     0,     0,     0,     0,   222,     0,   220,     0,
     216,   219,   223,   221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,  -299,  -299,  -299,  -299,   106,  -299,  -101,    73,
      57,    18,    67,   133,   131,   170,   171,   130,  -299,   -65,
     -67,  -299,   -94,   -77,  -195,     0,  -299,   268,  -299,    38,
    -299,  -299,   299,   -56,   -60,  -299,   155,  -299,   319,   -69,
    -299,    50,  -299,   -23,   -40,   -29,   306,   -63,  -299,   164,
      42,  -112,  -168,   -66,    74,  -225,  -299,   214,  -118,  -299,
     314,  -299,  -299,   100,  -298,  -299,  -299,  -299,  -299,   350,
    -299,  -299
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   105,   106,   107,   108,   241,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     156,   184,   278,   135,    26,   128,    44,    45,    28,    29,
      30,    31,    75,    76,    77,   142,   143,    32,    59,    60,
      61,    33,    34,    62,    47,    48,    65,   291,   130,   131,
     159,   292,   212,   162,   163,   164,   165,   166,   281,   282,
     283,   206,   284,   285,   286,   287,   288,   289,    35,    36,
      37,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   123,   124,   157,    46,   150,   134,   129,    72,   185,
     311,   279,   149,    64,   138,   203,   211,   134,   145,   140,
      20,    21,    22,    40,   350,   160,    57,   161,    49,    50,
    -233,   123,    41,    53,    54,    27,    85,   158,   193,   194,
      40,    42,   295,    87,   226,   237,   230,    68,    58,    41,
     227,   363,   364,   204,   144,    43,   312,   157,    42,   217,
     157,   295,   313,   148,   219,    42,    40,   195,   196,    58,
     141,   134,    66,    40,    73,    41,   134,   243,   149,   125,
     220,   140,    41,   232,    42,   246,   247,   248,    67,   279,
      74,   158,    63,   227,   158,   134,   221,   123,   236,   210,
      38,    82,    78,   242,   227,   209,    70,    58,    71,   329,
     264,    74,    74,    74,    39,    84,    74,   245,   197,   198,
     352,    63,   223,    78,    78,    78,    51,   349,    78,   229,
     307,   294,   311,    40,   199,    74,   227,   314,   167,   168,
      52,   227,   207,   134,   208,   302,    83,    78,   169,   186,
     315,    42,   321,    40,   187,   188,   228,   134,   208,   170,
     305,   171,   207,   172,   208,    42,   358,   359,   123,   310,
      72,    68,   227,   227,   361,    74,   375,   133,   210,   377,
     227,   327,   227,   201,   379,   227,    84,    78,   133,    74,
     227,   319,    74,   224,   152,   153,   225,   144,   343,   229,
     200,    78,   155,   134,    78,   296,   280,   297,    80,    81,
     353,   253,   254,   255,   256,   228,   133,   208,   146,   147,
     338,   189,   190,   344,   345,   202,   347,   205,   360,   191,
     192,   214,   134,   336,   234,   235,   356,   357,   213,   123,
     366,   367,   133,   368,   123,   340,   341,   133,   251,   252,
     342,   215,   376,   222,   378,   231,   380,    87,   233,   382,
     239,   383,   249,   250,   257,   258,   133,   244,   369,   371,
     373,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   300,   303,   304,   280,   316,   308,   317,   318,   320,
     123,   310,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     322,   323,   328,   324,   133,   325,   332,   333,   306,   346,
     334,   348,   280,   351,   183,   354,   355,   362,   133,   374,
     381,   260,   259,   263,    86,   265,   266,   133,   267,   268,
     269,   270,   271,   272,   273,   274,   275,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   261,   137,   262,   133,   301,    79,   136,   299,   238,
     339,    88,    89,   126,   331,    56,     0,     0,     0,     0,
       0,     0,     0,   276,    25,    91,    92,    93,    94,    95,
      96,     0,    97,   133,     0,     0,     0,   125,   330,     0,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,   133,     0,   265,   266,   277,   267,   268,   269,   270,
     271,   272,   273,   274,   275,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,    25,    91,    92,    93,    94,    95,    96,     0,
      97,     0,     0,     0,     0,   125,     0,     0,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   277,   267,   268,   269,   270,   271,   272,
     273,   274,   275,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,   276,
       0,    91,    92,    93,    94,    95,    96,     0,    97,   139,
       0,     0,     0,   125,     0,     0,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    25,
      91,    92,    93,    94,    95,    96,     0,    97,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    25,     0,
       0,     0,     0,     0,     0,     0,   207,   290,   208,     0,
       0,     0,     0,     0,     0,    42,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    88,
      89,   228,   290,   208,     0,     0,     0,     0,     0,     0,
      42,    90,    25,    91,    92,    93,    94,    95,    96,    55,
      97,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    20,    21,    22,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,   335,    88,    89,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,   218,     0,
     132,    20,    21,    22,     0,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,     0,     0,
     216,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   298,     0,    25,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,    91,    92,    93,
      94,    95,    96,     0,    97,     0,    25,    88,    89,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,    90,
       0,    91,    92,    93,    94,    95,    96,   326,    97,     0,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,    25,   160,     0,   161,    98,   309,     0,
      99,   100,   101,   102,   103,   104,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    97,     0,   160,
       0,   161,    98,   365,     0,    99,   100,   101,   102,   103,
     104,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,     0,   160,     0,   161,    98,    88,    89,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,    95,    96,     0,    97,
       0,    88,    89,     0,    98,     0,     0,    99,   100,   101,
     102,   103,   104,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    97,   240,    88,    89,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,    90,     0,    91,    92,
      93,    94,    95,    96,     0,    97,     0,     0,   293,    88,
      89,     0,     0,    99,   100,   101,   102,   103,   104,     0,
       0,    90,     0,    91,    92,    93,    94,    95,    96,     0,
      97,     0,    88,    89,     0,   306,     0,     0,    99,   100,
     101,   102,   103,   104,    90,     0,    91,    92,    93,    94,
      95,    96,     0,    97,     0,     0,   337,    88,    89,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,    90,
       0,    91,    92,    93,    94,    95,    96,     0,    97,   370,
      88,    89,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,    90,     0,    91,    92,    93,    94,    95,    96,
       0,    97,   372,    88,    89,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,    90,     0,    91,    92,    93,
      94,    95,    96,     0,    97,     0,    88,    89,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,    90,     0,
      91,    92,    93,    94,    95,    96,     0,   151,     0,    88,
      89,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,    90,     0,    91,    92,    93,    94,    95,    96,     0,
     154,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       0,    68,    68,    97,    27,    82,    71,    70,    48,   110,
     235,   206,    81,    42,    74,    52,   128,    82,    78,    75,
      34,    35,    36,    61,   322,    72,    75,    74,    28,    29,
      75,    98,    70,    33,    34,    35,    65,    97,    57,    58,
      61,    79,   210,    66,    71,    92,   158,    92,    61,    70,
      77,   349,   350,    90,    77,    93,    71,   151,    79,   136,
     154,   229,    77,    76,   141,    79,    61,    86,    87,    61,
      91,   136,    77,    61,    75,    70,   141,   171,   147,    75,
      77,   137,    70,   160,    79,   186,   187,   188,    93,   284,
      52,   151,    42,    77,   154,   160,    93,   164,   164,   128,
      61,    92,    52,   170,    77,   128,    70,    61,    72,    93,
     204,    73,    74,    75,    75,    65,    78,   184,    55,    56,
      93,    71,    76,    73,    74,    75,    61,   322,    78,   158,
     231,   208,   357,    61,    78,    97,    77,    73,    49,    50,
      75,    77,    70,   208,    72,   222,    71,    97,    59,    79,
      91,    79,   270,    61,    84,    85,    70,   222,    72,    70,
     227,    72,    70,    74,    72,    79,    71,    71,   235,   235,
     210,    92,    77,    77,    71,   137,    71,    71,   207,    71,
      77,   275,    77,    89,    71,    77,   136,   137,    82,   151,
      77,   268,   154,   151,    88,    89,   154,   220,   316,   228,
      88,   151,    96,   268,   154,    70,   206,    72,    76,    77,
     328,   193,   194,   195,   196,    70,   110,    72,    76,    77,
     297,    80,    81,   317,   318,    51,   320,    76,   346,    53,
      54,    77,   297,   296,    76,    77,    76,    77,    71,   306,
     358,   359,   136,   361,   311,   311,   313,   141,   191,   192,
     315,    73,   370,    91,   372,    71,   374,   280,    61,   377,
      61,   379,   189,   190,   197,   198,   160,    61,   362,   363,
     364,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    73,    71,    71,   284,    91,    73,    70,    70,    70,
     357,   357,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      70,    61,    91,    93,   208,    93,    71,    71,    75,    91,
      73,     8,   322,    93,    92,    71,    73,    70,   222,     5,
      93,   200,   199,   203,    66,     3,     4,   231,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   201,    73,   202,   268,   220,    57,    71,   214,   165,
     306,    49,    50,    69,   284,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,   297,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,   315,    -1,     3,     4,    93,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    93,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    76,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    49,
      50,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    34,    35,    36,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    76,    -1,
      73,    34,    35,    36,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    62,    49,    50,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    61,
      -1,    63,    64,    65,    66,    67,    68,    93,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    62,    72,    -1,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    74,    75,    49,    50,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    66,    67,    68,    -1,    70,
      -1,    49,    50,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    49,    50,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    49,
      50,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    49,    50,    -1,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    -1,    73,    49,    50,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      49,    50,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    61,    -1,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    49,    50,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    61,    -1,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    49,    50,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    49,
      50,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83
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
     142,   143,    73,   100,   113,   117,   140,   126,   128,    76,
     127,    91,   129,   130,   137,   128,    76,    77,    76,   133,
     117,    70,   100,   100,    70,   100,   114,   116,   128,   144,
      72,    74,   147,   148,   149,   150,   151,    49,    50,    59,
      70,    72,    74,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    92,   115,   102,    79,    84,    85,    80,
      81,    53,    54,    57,    58,    86,    87,    55,    56,    78,
      88,    89,    51,    52,    90,    76,   155,    70,    72,   137,
     139,   145,   146,    71,    77,    73,    73,   117,    76,   117,
      77,    93,    91,    76,   144,   144,    71,    77,    70,   139,
     145,    71,   117,    61,    76,    77,   147,    92,   151,    61,
      71,    99,   114,   116,    61,   114,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   105,   106,   106,   107,
     108,   109,   110,   111,   116,     3,     4,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    61,    93,   116,   118,
     119,   152,   153,   154,   156,   157,   158,   159,   160,   161,
      71,   141,   145,    73,   117,   146,    70,    72,    60,   143,
      73,   130,   117,    71,    71,   114,    75,   102,    73,    76,
     147,   149,    71,    77,    73,    91,    91,    70,    70,   117,
      70,   152,    70,    61,    93,    93,    93,   116,    91,    93,
      76,   157,    71,    71,    73,    71,   141,    73,   117,   148,
     147,   114,   113,   152,   116,   116,    91,   116,     8,   118,
     158,    93,    93,   152,    71,    73,    76,    77,    71,    71,
     152,    71,    70,   158,   158,    76,   152,   152,   152,   116,
      71,   116,    71,   116,     5,    71,   152,    71,   152,    71,
     152,    93,   152,   152
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
     138,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   144,   144,   145,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   148,   148,
     148,   148,   149,   150,   150,   151,   151,   152,   152,   152,
     152,   152,   152,   153,   153,   153,   154,   155,   154,   156,
     156,   157,   157,   158,   158,   159,   159,   159,   160,   160,
     160,   160,   160,   160,   161,   161,   161,   161,   161,   162,
     162,   163,   163,   165,   164
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
       1,     3,     5,     4,     4,     3,     4,     3,     1,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     2,     3,     3,     4,     1,     3,     4,     1,     2,
       3,     4,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     0,     4,     1,
       2,     1,     1,     1,     2,     5,     7,     5,     5,     7,
       6,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     0,     4
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
#line 1778 "parser.c"
    break;

  case 3: /* primary_expression: constant  */
#line 153 "bison/parser.yacc"
                                { (yyval.expr) = make_const_expr((yyvsp[0].constant)); }
#line 1784 "parser.c"
    break;

  case 4: /* primary_expression: string  */
#line 154 "bison/parser.yacc"
                                { (yyval.expr) = make_string_expr((yyvsp[0].sval)); }
#line 1790 "parser.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 155 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1796 "parser.c"
    break;

  case 6: /* constant: CONST_INT  */
#line 159 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_INT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1802 "parser.c"
    break;

  case 7: /* constant: CONST_FLOAT  */
#line 160 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_FLOAT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1808 "parser.c"
    break;

  case 8: /* constant: ENUM_CONST  */
#line 161 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_ENUM, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1814 "parser.c"
    break;

  case 9: /* string: STR_LITERAL  */
#line 164 "bison/parser.yacc"
                    { (yyval.sval) = (yyvsp[0].sval); free((yyvsp[0].sval)); }
#line 1820 "parser.c"
    break;

  case 10: /* string: FUNC_NAME  */
#line 165 "bison/parser.yacc"
                    { (yyval.sval) = func_name(); }
#line 1826 "parser.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 168 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1832 "parser.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 169 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_SUBSCRIPT, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1838 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 170 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-2].expr), 0); }
#line 1844 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 171 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1850 "parser.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 172 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_DOT, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1856 "parser.c"
    break;

  case 16: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 173 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_ARROW, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1862 "parser.c"
    break;

  case 17: /* postfix_expression: postfix_expression INCREMENT  */
#line 174 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_INCR, (yyvsp[-1].expr), 0); }
#line 1868 "parser.c"
    break;

  case 18: /* postfix_expression: postfix_expression DECREMENT  */
#line 175 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_DECR, (yyvsp[-1].expr), 0); }
#line 1874 "parser.c"
    break;

  case 19: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 176 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-4].type_name), (yyvsp[-1].init_list)); }
#line 1880 "parser.c"
    break;

  case 20: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 177 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-5].type_name), (yyvsp[-2].init_list)); }
#line 1886 "parser.c"
    break;

  case 21: /* argument_expression_list: assignment_expression  */
#line 181 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), 0); }
#line 1892 "parser.c"
    break;

  case 22: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 182 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1898 "parser.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 186 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1904 "parser.c"
    break;

  case 24: /* unary_expression: INCREMENT unary_expression  */
#line 187 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_INCR, (yyvsp[0].expr), 0); }
#line 1910 "parser.c"
    break;

  case 25: /* unary_expression: DECREMENT unary_expression  */
#line 188 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_DECR, (yyvsp[0].expr), 0); }
#line 1916 "parser.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 189 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[0].expr), 0); }
#line 1922 "parser.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 190 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_SIZEOF_EXPR, (yyvsp[0].expr), 0); }
#line 1928 "parser.c"
    break;

  case 28: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 191 "bison/parser.yacc"
                                            { (yyval.expr) = make_sizeof_expr((yyvsp[-1].type_name)); }
#line 1934 "parser.c"
    break;

  case 29: /* unary_operator: '&'  */
#line 195 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_ADDREF; }
#line 1940 "parser.c"
    break;

  case 30: /* unary_operator: '*'  */
#line 196 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_DEREF; }
#line 1946 "parser.c"
    break;

  case 31: /* unary_operator: '+'  */
#line 197 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_PLUS; }
#line 1952 "parser.c"
    break;

  case 32: /* unary_operator: '-'  */
#line 198 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_MINUS; }
#line 1958 "parser.c"
    break;

  case 33: /* unary_operator: '~'  */
#line 199 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_BITNOT; }
#line 1964 "parser.c"
    break;

  case 34: /* unary_operator: '!'  */
#line 200 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_LOGNOT; }
#line 1970 "parser.c"
    break;

  case 35: /* cast_expression: unary_expression  */
#line 204 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1976 "parser.c"
    break;

  case 36: /* cast_expression: '(' type_name ')' cast_expression  */
#line 205 "bison/parser.yacc"
                                            { (yyval.expr) = make_cast_expr((yyvsp[-2].type_name), (yyvsp[0].expr)); }
#line 1982 "parser.c"
    break;

  case 37: /* multiplicative_expression: cast_expression  */
#line 209 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1988 "parser.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 210 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1994 "parser.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 211 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2000 "parser.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 212 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2006 "parser.c"
    break;

  case 41: /* additive_expression: multiplicative_expression  */
#line 216 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2012 "parser.c"
    break;

  case 42: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 217 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2018 "parser.c"
    break;

  case 43: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 218 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2024 "parser.c"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 222 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2030 "parser.c"
    break;

  case 45: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 223 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2036 "parser.c"
    break;

  case 46: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 224 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_RSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2042 "parser.c"
    break;

  case 47: /* relational_expression: shift_expression  */
#line 228 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2048 "parser.c"
    break;

  case 48: /* relational_expression: relational_expression '<' shift_expression  */
#line 229 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2054 "parser.c"
    break;

  case 49: /* relational_expression: relational_expression '>' shift_expression  */
#line 230 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2060 "parser.c"
    break;

  case 50: /* relational_expression: relational_expression LEQ shift_expression  */
#line 231 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2066 "parser.c"
    break;

  case 51: /* relational_expression: relational_expression GEQ shift_expression  */
#line 232 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2072 "parser.c"
    break;

  case 52: /* equality_expression: relational_expression  */
#line 236 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2078 "parser.c"
    break;

  case 53: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 237 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2084 "parser.c"
    break;

  case 54: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 238 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2090 "parser.c"
    break;

  case 55: /* and_expression: equality_expression  */
#line 242 "bison/parser.yacc"
                                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2096 "parser.c"
    break;

  case 56: /* and_expression: and_expression '&' equality_expression  */
#line 243 "bison/parser.yacc"
                                                    { (yyval.expr) = make_expr(EXPR_BITAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2102 "parser.c"
    break;

  case 57: /* exclusive_or_expression: and_expression  */
#line 247 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2108 "parser.c"
    break;

  case 58: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 248 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_BITXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2114 "parser.c"
    break;

  case 59: /* inclusive_or_expression: exclusive_or_expression  */
#line 252 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2120 "parser.c"
    break;

  case 60: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 253 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_BITOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2126 "parser.c"
    break;

  case 61: /* logical_and_expression: inclusive_or_expression  */
#line 257 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2132 "parser.c"
    break;

  case 62: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 258 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2138 "parser.c"
    break;

  case 63: /* logical_or_expression: logical_and_expression  */
#line 262 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2144 "parser.c"
    break;

  case 64: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 263 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2150 "parser.c"
    break;

  case 65: /* conditional_expression: logical_or_expression  */
#line 267 "bison/parser.yacc"
                                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2156 "parser.c"
    break;

  case 66: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 268 "bison/parser.yacc"
                                                                            { (yyval.expr) = make_ternary_expr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2162 "parser.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 272 "bison/parser.yacc"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2168 "parser.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 273 "bison/parser.yacc"
                                                                        { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2174 "parser.c"
    break;

  case 69: /* assignment_operator: '='  */
#line 277 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ASSIGN; }
#line 2180 "parser.c"
    break;

  case 70: /* assignment_operator: MUL_ASSIGN  */
#line 278 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MUL_ASSIGN; }
#line 2186 "parser.c"
    break;

  case 71: /* assignment_operator: DIV_ASSIGN  */
#line 279 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_DIV_ASSIGN; }
#line 2192 "parser.c"
    break;

  case 72: /* assignment_operator: MOD_ASSIGN  */
#line 280 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MOD_ASSIGN; }
#line 2198 "parser.c"
    break;

  case 73: /* assignment_operator: ADD_ASSIGN  */
#line 281 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ADD_ASSIGN; }
#line 2204 "parser.c"
    break;

  case 74: /* assignment_operator: SUB_ASSIGN  */
#line 282 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_SUB_ASSIGN; }
#line 2210 "parser.c"
    break;

  case 75: /* assignment_operator: LSHIFT_ASSIGN  */
#line 283 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_LSHIFT_ASSIGN; }
#line 2216 "parser.c"
    break;

  case 76: /* assignment_operator: RSHIFT_ASSIGN  */
#line 284 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_RSHIFT_ASSIGN; }
#line 2222 "parser.c"
    break;

  case 77: /* assignment_operator: AND_ASSIGN  */
#line 285 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_AND_ASSIGN; }
#line 2228 "parser.c"
    break;

  case 78: /* assignment_operator: XOR_ASSIGN  */
#line 286 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_XOR_ASSIGN; }
#line 2234 "parser.c"
    break;

  case 79: /* assignment_operator: OR_ASSIGN  */
#line 287 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_OR_ASSIGN; }
#line 2240 "parser.c"
    break;

  case 80: /* expression: assignment_expression  */
#line 291 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2246 "parser.c"
    break;

  case 81: /* expression: expression ',' assignment_expression  */
#line 292 "bison/parser.yacc"
                                                { (yyval.expr) = make_expr(EXPR_COMMA, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2252 "parser.c"
    break;

  case 82: /* constant_expression: conditional_expression  */
#line 296 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2258 "parser.c"
    break;

  case 83: /* declaration: declaration_specifiers ';'  */
#line 300 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), 0); }
#line 2264 "parser.c"
    break;

  case 84: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 302 "bison/parser.yacc"
    {
        (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].init_decltr));
        add_typedef_type((yyval.decl));
    }
#line 2273 "parser.c"
    break;

  case 85: /* declaration_specifiers: storage_class_specifier  */
#line 309 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class(0, (yyvsp[0].int_val)); }
#line 2279 "parser.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 310 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2285 "parser.c"
    break;

  case 87: /* declaration_specifiers: type_specifier  */
#line 311 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2291 "parser.c"
    break;

  case 88: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 312 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2297 "parser.c"
    break;

  case 89: /* declaration_specifiers: type_qualifier  */
#line 313 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2303 "parser.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 314 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2309 "parser.c"
    break;

  case 91: /* declaration_specifiers: function_specifier  */
#line 315 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec(0, (yyvsp[0].int_val)); }
#line 2315 "parser.c"
    break;

  case 92: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 316 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2321 "parser.c"
    break;

  case 93: /* init_declarator_list: init_declarator  */
#line 320 "bison/parser.yacc"
                                                    { (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2327 "parser.c"
    break;

  case 94: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 321 "bison/parser.yacc"
                                                    { add_init_decltr((yyvsp[-2].init_decltr), (yyvsp[0].init_decltr)); (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2333 "parser.c"
    break;

  case 95: /* init_declarator: declarator  */
#line 325 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[0].decltr), 0); }
#line 2339 "parser.c"
    break;

  case 96: /* init_declarator: declarator '=' initializer  */
#line 326 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[-2].decltr), (yyvsp[0].initializer)); }
#line 2345 "parser.c"
    break;

  case 97: /* storage_class_specifier: TYPEDEF  */
#line 330 "bison/parser.yacc"
                    { (yyval.int_val) = SC_TYPEDEF; }
#line 2351 "parser.c"
    break;

  case 98: /* storage_class_specifier: EXTERN  */
#line 331 "bison/parser.yacc"
                    { (yyval.int_val) = SC_EXTERN; }
#line 2357 "parser.c"
    break;

  case 99: /* storage_class_specifier: STATIC  */
#line 332 "bison/parser.yacc"
                    { (yyval.int_val) = SC_STATIC; }
#line 2363 "parser.c"
    break;

  case 100: /* storage_class_specifier: AUTO  */
#line 333 "bison/parser.yacc"
                    { (yyval.int_val) = SC_AUTO; }
#line 2369 "parser.c"
    break;

  case 101: /* storage_class_specifier: REGISTER  */
#line 334 "bison/parser.yacc"
                    { (yyval.int_val) = SC_REGISTER; }
#line 2375 "parser.c"
    break;

  case 102: /* type_specifier: VOID  */
#line 338 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_VOID); }
#line 2381 "parser.c"
    break;

  case 103: /* type_specifier: CHAR  */
#line 339 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_CHAR); }
#line 2387 "parser.c"
    break;

  case 104: /* type_specifier: SHORT  */
#line 340 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SHORT); }
#line 2393 "parser.c"
    break;

  case 105: /* type_specifier: INT  */
#line 341 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_INT); }
#line 2399 "parser.c"
    break;

  case 106: /* type_specifier: LONG  */
#line 342 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_LONG); }
#line 2405 "parser.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 343 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_FLOAT); }
#line 2411 "parser.c"
    break;

  case 108: /* type_specifier: DOUBLE  */
#line 344 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_DOUBLE); }
#line 2417 "parser.c"
    break;

  case 109: /* type_specifier: SIGNED  */
#line 345 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SIGNED); }
#line 2423 "parser.c"
    break;

  case 110: /* type_specifier: UNSIGNED  */
#line 346 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_UNSIGNED); }
#line 2429 "parser.c"
    break;

  case 111: /* type_specifier: BOOL  */
#line 347 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_BOOL); }
#line 2435 "parser.c"
    break;

  case 112: /* type_specifier: COMPLEX  */
#line 348 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_COMPLEX); }
#line 2441 "parser.c"
    break;

  case 113: /* type_specifier: IMAGINARY  */
#line 349 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_IMAGINARY); }
#line 2447 "parser.c"
    break;

  case 114: /* type_specifier: struct_or_union_specifier  */
#line 350 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_sou_type_spec((yyvsp[0].sou_spec)); }
#line 2453 "parser.c"
    break;

  case 115: /* type_specifier: enum_specifier  */
#line 351 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_enum_type_spec((yyvsp[0].enum_spec)); }
#line 2459 "parser.c"
    break;

  case 116: /* type_specifier: TYPEDEF_NAME  */
#line 352 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_typedef_type_spec((yyvsp[0].sval)); }
#line 2465 "parser.c"
    break;

  case 117: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 356 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-4].int_val), (yyvsp[-3].sval), (yyvsp[-1].struct_decl_list)); }
#line 2471 "parser.c"
    break;

  case 118: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 357 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-3].int_val), 0, (yyvsp[-1].struct_decl_list)); }
#line 2477 "parser.c"
    break;

  case 119: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 358 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-1].int_val), (yyvsp[0].sval), 0); }
#line 2483 "parser.c"
    break;

  case 120: /* struct_or_union: STRUCT  */
#line 362 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_STRUCT; }
#line 2489 "parser.c"
    break;

  case 121: /* struct_or_union: UNION  */
#line 363 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_UNION; }
#line 2495 "parser.c"
    break;

  case 122: /* struct_declaration_list: struct_declaration  */
#line 367 "bison/parser.yacc"
                                                        { (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2501 "parser.c"
    break;

  case 123: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 368 "bison/parser.yacc"
                                                        { add_struct_decl((yyvsp[-1].struct_decl_list), (yyvsp[0].struct_decl_list)); (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2507 "parser.c"
    break;

  case 124: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 372 "bison/parser.yacc"
                                                                { (yyval.struct_decl_list) = make_struct_decl_list(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].struct_decltr_list)); }
#line 2513 "parser.c"
    break;

  case 125: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 376 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2519 "parser.c"
    break;

  case 126: /* specifier_qualifier_list: type_specifier  */
#line 377 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2525 "parser.c"
    break;

  case 127: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 378 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2531 "parser.c"
    break;

  case 128: /* specifier_qualifier_list: type_qualifier  */
#line 379 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2537 "parser.c"
    break;

  case 129: /* struct_declarator_list: struct_declarator  */
#line 383 "bison/parser.yacc"
                                                        { (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2543 "parser.c"
    break;

  case 130: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 384 "bison/parser.yacc"
                                                        { add_struct_decltr((yyvsp[-2].struct_decltr_list), (yyvsp[0].struct_decltr_list)); (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2549 "parser.c"
    break;

  case 131: /* struct_declarator: declarator  */
#line 388 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[0].decltr), 0); }
#line 2555 "parser.c"
    break;

  case 132: /* struct_declarator: ':' constant_expression  */
#line 389 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list(0, (yyvsp[0].expr)); }
#line 2561 "parser.c"
    break;

  case 133: /* struct_declarator: declarator ':' constant_expression  */
#line 390 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[-2].decltr), (yyvsp[0].expr)); }
#line 2567 "parser.c"
    break;

  case 134: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 394 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-1].enumerator_list)); }
#line 2573 "parser.c"
    break;

  case 135: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 395 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-3].sval), (yyvsp[-1].enumerator_list)); }
#line 2579 "parser.c"
    break;

  case 136: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 396 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-2].enumerator_list)); }
#line 2585 "parser.c"
    break;

  case 137: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 397 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-4].sval), (yyvsp[-2].enumerator_list)); }
#line 2591 "parser.c"
    break;

  case 138: /* enum_specifier: ENUM IDENTIFIER  */
#line 398 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[0].sval), 0); }
#line 2597 "parser.c"
    break;

  case 139: /* enumerator_list: enumerator  */
#line 402 "bison/parser.yacc"
                                            { (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2603 "parser.c"
    break;

  case 140: /* enumerator_list: enumerator_list ',' enumerator  */
#line 403 "bison/parser.yacc"
                                            { add_enumerator((yyvsp[-2].enumerator_list), (yyvsp[0].enumerator_list)); (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2609 "parser.c"
    break;

  case 141: /* enumerator: enumeration_constant  */
#line 407 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[0].sval), 0); free((yyvsp[0].sval)); }
#line 2615 "parser.c"
    break;

  case 142: /* enumerator: enumeration_constant '=' constant_expression  */
#line 408 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[-2].sval), (yyvsp[0].expr)); free((yyvsp[-2].sval)); }
#line 2621 "parser.c"
    break;

  case 143: /* enumeration_constant: IDENTIFIER  */
#line 412 "bison/parser.yacc"
                    { sym_define_enum((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); }
#line 2627 "parser.c"
    break;

  case 144: /* type_qualifier: CONST  */
#line 415 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_CONST; }
#line 2633 "parser.c"
    break;

  case 145: /* type_qualifier: RESTRICT  */
#line 416 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_RESTRICT; }
#line 2639 "parser.c"
    break;

  case 146: /* type_qualifier: VOLATILE  */
#line 417 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_VOLATILE; }
#line 2645 "parser.c"
    break;

  case 147: /* function_specifier: INLINE  */
#line 421 "bison/parser.yacc"
                    { (yyval.int_val) = FS_INLINE; }
#line 2651 "parser.c"
    break;

  case 148: /* declarator: pointer direct_declarator  */
#line 427 "bison/parser.yacc"
                                    { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); (yyval.decltr) = (yyvsp[0].decltr); }
#line 2657 "parser.c"
    break;

  case 149: /* declarator: direct_declarator  */
#line 428 "bison/parser.yacc"
                                    { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2663 "parser.c"
    break;

  case 150: /* direct_declarator: IDENTIFIER  */
#line 433 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_id_decltr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2669 "parser.c"
    break;

  case 151: /* direct_declarator: '(' declarator ')'  */
#line 434 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2675 "parser.c"
    break;

  case 152: /* direct_declarator: direct_declarator '[' type_qualifier_list constant_expression ']'  */
#line 435 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr)); }
#line 2681 "parser.c"
    break;

  case 153: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 436 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), (yyvsp[-1].type_qual_list), 0); }
#line 2687 "parser.c"
    break;

  case 154: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 437 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2693 "parser.c"
    break;

  case 155: /* direct_declarator: direct_declarator '[' ']'  */
#line 438 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2699 "parser.c"
    break;

  case 156: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 439 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2705 "parser.c"
    break;

  case 157: /* direct_declarator: direct_declarator '(' ')'  */
#line 440 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2711 "parser.c"
    break;

  case 158: /* pointer: '*'  */
#line 444 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, 0); }
#line 2717 "parser.c"
    break;

  case 159: /* pointer: '*' type_qualifier_list  */
#line 445 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[0].type_qual_list), 0); }
#line 2723 "parser.c"
    break;

  case 160: /* pointer: '*' pointer  */
#line 446 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, (yyvsp[0].pointer)); }
#line 2729 "parser.c"
    break;

  case 161: /* pointer: '*' type_qualifier_list pointer  */
#line 447 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[-1].type_qual_list), (yyvsp[0].pointer)); }
#line 2735 "parser.c"
    break;

  case 162: /* type_qualifier_list: type_qualifier  */
#line 451 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list(0, (yyvsp[0].int_val)); }
#line 2741 "parser.c"
    break;

  case 163: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 452 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list((yyvsp[-1].type_qual_list), (yyvsp[0].int_val)); }
#line 2747 "parser.c"
    break;

  case 164: /* parameter_type_list: parameter_list  */
#line 457 "bison/parser.yacc"
                                        { set_param_ellipsis(0); (yyval.param_list) = (yyvsp[0].param_list); }
#line 2753 "parser.c"
    break;

  case 165: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 458 "bison/parser.yacc"
                                        { set_param_ellipsis(1); (yyval.param_list) = (yyvsp[-2].param_list); }
#line 2759 "parser.c"
    break;

  case 166: /* parameter_list: parameter_declaration  */
#line 462 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list(0, (yyvsp[0].decl)); }
#line 2765 "parser.c"
    break;

  case 167: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 463 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list((yyvsp[-2].param_list), (yyvsp[0].decl)); }
#line 2771 "parser.c"
    break;

  case 168: /* parameter_declaration: declaration_specifiers declarator  */
#line 467 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 0); }
#line 2777 "parser.c"
    break;

  case 169: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 468 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 1); }
#line 2783 "parser.c"
    break;

  case 170: /* parameter_declaration: declaration_specifiers  */
#line 469 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[0].decl_spec_list)), 0, 0); }
#line 2789 "parser.c"
    break;

  case 171: /* type_name: specifier_qualifier_list  */
#line 473 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[0].decl_spec_list)), 0); }
#line 2795 "parser.c"
    break;

  case 172: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 474 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr)); }
#line 2801 "parser.c"
    break;

  case 173: /* abstract_declarator: pointer  */
#line 478 "bison/parser.yacc"
                                                { (yyval.decltr) = make_empty_decltr((yyvsp[0].pointer)); }
#line 2807 "parser.c"
    break;

  case 174: /* abstract_declarator: direct_abstract_declarator  */
#line 479 "bison/parser.yacc"
                                                { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2813 "parser.c"
    break;

  case 175: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 480 "bison/parser.yacc"
                                                { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); }
#line 2819 "parser.c"
    break;

  case 176: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 484 "bison/parser.yacc"
                                                                    { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2825 "parser.c"
    break;

  case 177: /* direct_abstract_declarator: '[' ']'  */
#line 485 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0); }
#line 2831 "parser.c"
    break;

  case 178: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 486 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, (yyvsp[-1].expr)); }
#line 2837 "parser.c"
    break;

  case 179: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 487 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2843 "parser.c"
    break;

  case 180: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 488 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2849 "parser.c"
    break;

  case 181: /* direct_abstract_declarator: '(' ')'  */
#line 489 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, 0); }
#line 2855 "parser.c"
    break;

  case 182: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 490 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, (yyvsp[-1].param_list)); }
#line 2861 "parser.c"
    break;

  case 183: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 491 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2867 "parser.c"
    break;

  case 184: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 492 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2873 "parser.c"
    break;

  case 185: /* initializer: assignment_expression  */
#line 496 "bison/parser.yacc"
                                        { (yyval.initializer) = make_expr_init((yyvsp[0].expr)); }
#line 2879 "parser.c"
    break;

  case 186: /* initializer: '{' initializer_list '}'  */
#line 497 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-1].init_list)); }
#line 2885 "parser.c"
    break;

  case 187: /* initializer: '{' initializer_list ',' '}'  */
#line 498 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-2].init_list)); }
#line 2891 "parser.c"
    break;

  case 188: /* initializer_list: initializer  */
#line 502 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, 0, (yyvsp[0].initializer)); }
#line 2897 "parser.c"
    break;

  case 189: /* initializer_list: designation initializer  */
#line 503 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, (yyvsp[-1].designation), (yyvsp[0].initializer)); }
#line 2903 "parser.c"
    break;

  case 190: /* initializer_list: initializer_list ',' initializer  */
#line 504 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-2].init_list), 0, (yyvsp[0].initializer)); }
#line 2909 "parser.c"
    break;

  case 191: /* initializer_list: initializer_list ',' designation initializer  */
#line 505 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-3].init_list), (yyvsp[-1].designation), (yyvsp[0].initializer)); }
#line 2915 "parser.c"
    break;

  case 192: /* designation: designator_list '='  */
#line 509 "bison/parser.yacc"
                                { (yyval.designation) = (yyvsp[-1].designation); }
#line 2921 "parser.c"
    break;

  case 193: /* designator_list: designator  */
#line 513 "bison/parser.yacc"
                                        { (yyval.designation) = (yyvsp[0].designation); }
#line 2927 "parser.c"
    break;

  case 194: /* designator_list: designator_list designator  */
#line 514 "bison/parser.yacc"
                                        { add_designator((yyvsp[-1].designation), (yyvsp[0].designation)); (yyval.designation) = (yyvsp[0].designation); }
#line 2933 "parser.c"
    break;

  case 195: /* designator: '[' constant_expression ']'  */
#line 518 "bison/parser.yacc"
                                        { (yyval.designation) = make_arr_designator((yyvsp[-1].expr)); }
#line 2939 "parser.c"
    break;

  case 196: /* designator: '.' IDENTIFIER  */
#line 519 "bison/parser.yacc"
                                        { (yyval.designation) = make_member_designator((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2945 "parser.c"
    break;

  case 197: /* statement: labeled_statement  */
#line 523 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2951 "parser.c"
    break;

  case 198: /* statement: compound_statement  */
#line 524 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2957 "parser.c"
    break;

  case 199: /* statement: expression_statement  */
#line 525 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2963 "parser.c"
    break;

  case 200: /* statement: selection_statement  */
#line 526 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2969 "parser.c"
    break;

  case 201: /* statement: iteration_statement  */
#line 527 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2975 "parser.c"
    break;

  case 202: /* statement: jump_statement  */
#line 528 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2981 "parser.c"
    break;

  case 203: /* labeled_statement: IDENTIFIER ':' statement  */
#line 532 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_labeled_stmt((yyvsp[-2].sval), (yyvsp[0].stmt)); }
#line 2987 "parser.c"
    break;

  case 204: /* labeled_statement: CASE constant_expression ':' statement  */
#line 533 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_case_stmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2993 "parser.c"
    break;

  case 205: /* labeled_statement: DEFAULT ':' statement  */
#line 534 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_default_stmt((yyvsp[0].stmt)); }
#line 2999 "parser.c"
    break;

  case 206: /* compound_statement: '{' '}'  */
#line 538 "bison/parser.yacc"
                            { (yyval.stmt) = make_compound_stmt(0); }
#line 3005 "parser.c"
    break;

  case 207: /* $@1: %empty  */
#line 539 "bison/parser.yacc"
                            { sym_push_scope(); }
#line 3011 "parser.c"
    break;

  case 208: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 541 "bison/parser.yacc"
                        { sym_pop_scope(); (yyval.stmt) = make_compound_stmt((yyvsp[-1].block_list)); }
#line 3017 "parser.c"
    break;

  case 209: /* block_item_list: block_item  */
#line 545 "bison/parser.yacc"
                                        { (yyval.block_list) = (yyvsp[0].block_list); }
#line 3023 "parser.c"
    break;

  case 210: /* block_item_list: block_item_list block_item  */
#line 546 "bison/parser.yacc"
                                        { add_block_item((yyvsp[-1].block_list), (yyvsp[0].block_list)); (yyval.block_list) = (yyvsp[0].block_list); }
#line 3029 "parser.c"
    break;

  case 211: /* block_item: declaration  */
#line 550 "bison/parser.yacc"
                        { (yyval.block_list) = make_decl_block_item((yyvsp[0].decl)); }
#line 3035 "parser.c"
    break;

  case 212: /* block_item: statement  */
#line 551 "bison/parser.yacc"
                        { (yyval.block_list) = make_stmt_block_item((yyvsp[0].stmt)); }
#line 3041 "parser.c"
    break;

  case 213: /* expression_statement: ';'  */
#line 555 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt(0); }
#line 3047 "parser.c"
    break;

  case 214: /* expression_statement: expression ';'  */
#line 556 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt((yyvsp[-1].expr)); }
#line 3053 "parser.c"
    break;

  case 215: /* selection_statement: IF '(' expression ')' statement  */
#line 560 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3059 "parser.c"
    break;

  case 216: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 561 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 3065 "parser.c"
    break;

  case 217: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 562 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_SWITCH, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3071 "parser.c"
    break;

  case 218: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 566 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_WHILE, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3077 "parser.c"
    break;

  case 219: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 567 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_DO, (yyvsp[-2].expr), (yyvsp[-5].stmt), 0); }
#line 3083 "parser.c"
    break;

  case 220: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 568 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-3].stmt), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3089 "parser.c"
    break;

  case 221: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 569 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3095 "parser.c"
    break;

  case 222: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 570 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-3].decl), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3101 "parser.c"
    break;

  case 223: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 571 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-4].decl), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3107 "parser.c"
    break;

  case 224: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 575 "bison/parser.yacc"
                                { (yyval.stmt) = make_goto_stmt((yyvsp[-1].sval)); }
#line 3113 "parser.c"
    break;

  case 225: /* jump_statement: CONTINUE ';'  */
#line 576 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_CONTINUE); }
#line 3119 "parser.c"
    break;

  case 226: /* jump_statement: BREAK ';'  */
#line 577 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_BREAK); }
#line 3125 "parser.c"
    break;

  case 227: /* jump_statement: RETURN ';'  */
#line 578 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_RETURN); }
#line 3131 "parser.c"
    break;

  case 228: /* jump_statement: RETURN expression ';'  */
#line 579 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt((yyvsp[-1].expr)); }
#line 3137 "parser.c"
    break;

  case 229: /* translation_unit: external_declaration  */
#line 583 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit(0, (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3143 "parser.c"
    break;

  case 230: /* translation_unit: translation_unit external_declaration  */
#line 584 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit((yyvsp[-1].translation_unit), (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3149 "parser.c"
    break;

  case 231: /* external_declaration: function_definition  */
#line 588 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_func_ext_decl((yyvsp[0].func_def)); }
#line 3155 "parser.c"
    break;

  case 232: /* external_declaration: declaration  */
#line 589 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_decl_ext_decl((yyvsp[0].decl)); }
#line 3161 "parser.c"
    break;

  case 233: /* $@2: %empty  */
#line 593 "bison/parser.yacc"
                                                                { set_func_name(get_decltr_id((yyvsp[0].decltr))); }
#line 3167 "parser.c"
    break;

  case 234: /* function_definition: declaration_specifiers declarator $@2 compound_statement  */
#line 595 "bison/parser.yacc"
    {
        func_ended();
        (yyval.func_def) = make_func_def(make_decl_specs((yyvsp[-3].decl_spec_list)), (yyvsp[-2].decltr), (yyvsp[0].stmt));
    }
#line 3176 "parser.c"
    break;


#line 3180 "parser.c"

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

#line 601 "bison/parser.yacc"
