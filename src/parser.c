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
  YYSYMBOL_INLINE = 18,                    /* INLINE  */
  YYSYMBOL_ENUM = 19,                      /* ENUM  */
  YYSYMBOL_STRUCT = 20,                    /* STRUCT  */
  YYSYMBOL_UNION = 21,                     /* UNION  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_SHORT = 24,                     /* SHORT  */
  YYSYMBOL_LONG = 25,                      /* LONG  */
  YYSYMBOL_FLOAT = 26,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 27,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 28,                      /* BOOL  */
  YYSYMBOL_VOID = 29,                      /* VOID  */
  YYSYMBOL_SIGNED = 30,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 31,                  /* UNSIGNED  */
  YYSYMBOL_CONST = 32,                     /* CONST  */
  YYSYMBOL_RESTRICT = 33,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 34,                  /* VOLATILE  */
  YYSYMBOL_ADD_ASSIGN = 35,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 36,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 37,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 38,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 39,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 40,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 41,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 42,                /* XOR_ASSIGN  */
  YYSYMBOL_LSHIFT_ASSIGN = 43,             /* LSHIFT_ASSIGN  */
  YYSYMBOL_RSHIFT_ASSIGN = 44,             /* RSHIFT_ASSIGN  */
  YYSYMBOL_INCREMENT = 45,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 46,                 /* DECREMENT  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_OR = 48,                        /* OR  */
  YYSYMBOL_LSHIFT = 49,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 50,                    /* RSHIFT  */
  YYSYMBOL_EQUAL = 51,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 52,                 /* NOT_EQUAL  */
  YYSYMBOL_LEQ = 53,                       /* LEQ  */
  YYSYMBOL_GEQ = 54,                       /* GEQ  */
  YYSYMBOL_ARROW = 55,                     /* ARROW  */
  YYSYMBOL_ELLIPSIS = 56,                  /* ELLIPSIS  */
  YYSYMBOL_IDENTIFIER = 57,                /* IDENTIFIER  */
  YYSYMBOL_TYPEDEF_NAME = 58,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUM_CONST = 59,                /* ENUM_CONST  */
  YYSYMBOL_CONST_CHAR = 60,                /* CONST_CHAR  */
  YYSYMBOL_CONST_SHORT = 61,               /* CONST_SHORT  */
  YYSYMBOL_CONST_INT = 62,                 /* CONST_INT  */
  YYSYMBOL_CONST_LONG = 63,                /* CONST_LONG  */
  YYSYMBOL_CONST_FLOAT = 64,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_DOUBLE = 65,              /* CONST_DOUBLE  */
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
  YYSYMBOL_80_ = 80,                       /* '-'  */
  YYSYMBOL_81_ = 81,                       /* '~'  */
  YYSYMBOL_82_ = 82,                       /* '!'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_84_ = 84,                       /* '%'  */
  YYSYMBOL_85_ = 85,                       /* '+'  */
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
  YYSYMBOL_compound_assignment = 115,      /* compound_assignment  */
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
  YYSYMBOL_statement = 149,                /* statement  */
  YYSYMBOL_labeled_statement = 150,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 151,       /* compound_statement  */
  YYSYMBOL_152_1 = 152,                    /* $@1  */
  YYSYMBOL_block_item_list = 153,          /* block_item_list  */
  YYSYMBOL_block_item = 154,               /* block_item  */
  YYSYMBOL_expression_statement = 155,     /* expression_statement  */
  YYSYMBOL_selection_statement = 156,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 157,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 158,           /* jump_statement  */
  YYSYMBOL_translation_unit = 159,         /* translation_unit  */
  YYSYMBOL_external_declaration = 160,     /* external_declaration  */
  YYSYMBOL_function_definition = 161,      /* function_definition  */
  YYSYMBOL_162_2 = 162                     /* $@2  */
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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1461

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  361

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
       2,     2,     2,    82,     2,     2,     2,    84,    78,     2,
      70,    71,    79,    85,    77,    80,    74,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    93,
      86,    92,    87,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    89,    76,    81,     2,     2,     2,
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
       0,   153,   153,   154,   155,   156,   160,   161,   162,   165,
     166,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   182,   183,   187,   188,   189,   190,   191,   192,   196,
     197,   198,   199,   200,   204,   205,   209,   210,   211,   212,
     216,   217,   218,   222,   223,   224,   228,   229,   230,   231,
     232,   236,   237,   238,   242,   243,   247,   248,   252,   253,
     257,   258,   262,   263,   267,   268,   272,   273,   274,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   291,
     295,   299,   300,   308,   309,   310,   311,   312,   313,   314,
     315,   319,   320,   324,   325,   329,   330,   331,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   351,   352,   353,   357,   358,   362,   363,   367,   371,
     372,   373,   374,   378,   379,   383,   387,   388,   389,   390,
     391,   395,   396,   400,   401,   405,   408,   409,   410,   414,
     420,   421,   426,   427,   428,   429,   430,   431,   432,   433,
     437,   438,   439,   440,   444,   445,   450,   451,   455,   456,
     460,   461,   462,   466,   467,   471,   472,   473,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   489,   490,   491,
     495,   496,   500,   501,   502,   503,   504,   505,   509,   510,
     511,   515,   516,   516,   522,   523,   527,   528,   532,   533,
     537,   538,   539,   543,   544,   545,   546,   547,   548,   552,
     553,   554,   555,   556,   560,   561,   565,   566,   570,   570
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
  "BREAK", "RETURN", "TYPEDEF", "EXTERN", "STATIC", "INLINE", "ENUM",
  "STRUCT", "UNION", "CHAR", "INT", "SHORT", "LONG", "FLOAT", "DOUBLE",
  "BOOL", "VOID", "SIGNED", "UNSIGNED", "CONST", "RESTRICT", "VOLATILE",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LSHIFT_ASSIGN",
  "RSHIFT_ASSIGN", "INCREMENT", "DECREMENT", "AND", "OR", "LSHIFT",
  "RSHIFT", "EQUAL", "NOT_EQUAL", "LEQ", "GEQ", "ARROW", "ELLIPSIS",
  "IDENTIFIER", "TYPEDEF_NAME", "ENUM_CONST", "CONST_CHAR", "CONST_SHORT",
  "CONST_INT", "CONST_LONG", "CONST_FLOAT", "CONST_DOUBLE", "STR_LITERAL",
  "FUNC_NAME", "SIZEOF", "NO_ELSE", "'('", "')'", "'['", "']'", "'.'",
  "'{'", "'}'", "','", "'&'", "'*'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'+'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept",
  "primary_expression", "constant", "string", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
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
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "$@2", YY_NULLPTR
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

#define YYTABLE_NINF (-219)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1075,  -289,  -289,  -289,  -289,   -42,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,    79,  1075,  1075,  -289,    -8,  -289,  1075,
    1075,   473,  -289,  -289,   -52,    21,  -289,   -11,     8,  -289,
      -3,  -289,   -30,   116,    84,  -289,  -289,    17,  1095,  -289,
    -289,  -289,  -289,    21,  -289,    39,  -289,    59,    93,  -289,
    -289,     8,   -11,  -289,  1142,   112,   852,   880,   116,  1095,
    1095,   774,  -289,   -11,  1095,    68,  -289,     4,  1327,  -289,
    -289,  -289,  -289,    81,  1353,  1353,  -289,  -289,  -289,  -289,
    -289,  -289,  1379,   710,  1142,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,   139,   238,  1327,  -289,    98,   -20,   165,
      89,   171,   -41,    95,   107,   156,   -34,  -289,  -289,  -289,
     131,  -289,  -289,   -22,   145,   141,  -289,  -289,  -289,  -289,
     161,   922,   790,  -289,  -289,  -289,    73,  -289,  -289,  -289,
    -289,    26,  -289,  -289,  -289,   710,  -289,  -289,   710,  -289,
    -289,   167,    83,   170,  -289,   149,  -289,  -289,   185,  1168,
    1327,   187,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  1327,  1327,  -289,  1327,  1327,  1327,  1327,  1327,
    1327,  1327,  1327,  1327,  1327,  1327,  1327,  1327,  1327,  1327,
    1327,  1327,  1327,  1327,  -289,   383,   629,  1195,  -289,   108,
    -289,   132,  -289,  1055,  -289,  -289,   173,  -289,   -11,  -289,
    -289,   176,   181,  -289,   649,   140,  -289,  1221,  -289,  1090,
    -289,  -289,    24,  -289,   180,  -289,  -289,  -289,  -289,  -289,
    -289,    98,    98,   -20,   -20,   165,   165,   165,   165,    89,
      89,   171,   -41,    95,   107,   156,   163,   164,   186,   188,
    1327,   189,   471,   190,   200,   168,   169,   948,   172,  -289,
     174,  -289,    79,  -289,  -289,  -289,   295,  -289,  -289,  -289,
    -289,  -289,  -289,   193,   194,  -289,   195,   132,   872,  1247,
    -289,  -289,  -289,  -289,   208,   208,  1142,  -289,  -289,  -289,
    -289,  1327,  -289,  1327,   471,  1327,  1327,   178,  1327,   262,
     550,   191,  -289,  -289,  -289,   192,   471,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,   215,  -289,   214,   151,  -289,  -289,
    -289,   217,   218,   471,   219,   221,   976,   976,  -289,  -289,
    -289,  -289,  -289,  -289,  1116,   471,   471,  -289,   471,  1327,
    1273,  1300,  -289,   287,  -289,  -289,   222,   471,   223,   471,
     224,   471,   203,  -289,   471,  -289,   471,  -289,  -289,  -289,
    -289
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    95,    96,    97,   139,     0,   114,   115,    99,   101,
     100,   102,   103,   104,   107,    98,   105,   106,   136,   137,
     138,   110,   217,     0,    83,    85,   108,     0,   109,    87,
      89,     0,   214,   216,   130,     0,   142,     0,   150,    81,
       0,    91,    93,   141,     0,    84,    86,   113,     0,    88,
      90,     1,   215,     0,   135,     0,   131,   133,     0,   154,
     152,   151,     0,    82,     0,     0,     0,     0,   140,     0,
     120,     0,   116,     0,   122,     0,   126,     0,     0,   143,
     155,   153,    92,    93,     0,     0,     2,     8,     6,     7,
       9,    10,     0,     0,     0,    29,    30,    31,    32,    33,
      11,     3,     4,    23,    34,     0,    36,    40,    43,    46,
      51,    54,    56,    58,    60,    62,    64,    66,   177,    94,
     192,   219,   149,   162,     0,   156,   158,   147,    34,    80,
       0,     0,     0,   119,   112,   117,     0,   123,   125,   121,
     127,     0,   128,   132,   134,     0,    24,    25,     0,    27,
      79,     0,   163,     0,   180,     0,    17,    18,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,     0,     0,   160,   165,
     161,   166,   148,     0,   146,   145,     0,   111,     0,   118,
     129,     0,     0,     5,     0,   165,   164,     0,   178,     0,
      16,    13,     0,    21,     0,    15,    67,    68,    37,    38,
      39,    42,    41,    44,    45,    49,    50,    47,    48,    52,
      53,    55,    57,    59,    61,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,   198,
       0,   196,     0,   197,   182,   183,     0,   194,   184,   185,
     186,   187,   173,     0,     0,   169,     0,   167,     0,     0,
     157,   159,   144,   124,     0,    28,     0,    35,   179,   181,
      14,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,   211,   212,     0,     0,   199,   193,   195,
     174,   168,   170,   175,     0,   171,     0,     0,    22,    65,
     190,     0,     0,     0,     0,     0,     0,     0,   209,   213,
     188,   176,   172,    19,     0,     0,     0,   189,     0,     0,
       0,     0,    20,   200,   202,   203,     0,     0,     0,     0,
       0,     0,     0,   207,     0,   205,     0,   201,   204,   208,
     206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -289,  -289,  -289,  -289,  -289,  -289,   -58,  -289,   -77,    52,
      56,    16,    53,   109,   142,   143,   144,   146,  -289,   -60,
     -62,  -289,   -90,   -59,  -187,     0,  -289,   270,  -289,   100,
    -289,  -289,   265,   -55,   -57,  -289,   128,  -289,   284,   -66,
    -289,    15,  -289,   -19,   -38,   -17,   272,   -61,  -289,   147,
     -79,  -101,   -47,   -63,    57,  -242,  -289,   277,  -289,  -289,
      78,  -288,  -289,  -289,  -289,  -289,   314,  -289,  -289
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   100,   101,   102,   103,   222,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     150,   173,   260,   130,    22,   123,    40,    41,    24,    25,
      26,    27,    71,    72,    73,   136,   137,    28,    55,    56,
      57,    29,    30,    58,    43,    44,    61,   273,   125,   126,
     153,   274,   201,   154,   155,   263,   264,   265,   195,   266,
     267,   268,   269,   270,   271,    31,    32,    33,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   119,   118,   151,    42,   124,    68,   129,   261,   128,
     299,   143,   327,   133,   192,    34,   135,   139,   129,   144,
     128,    60,   200,    53,    45,    46,   146,   147,   174,    49,
      50,    23,   118,    35,   149,    36,   152,   188,   340,   341,
      18,    19,    20,    83,    81,  -218,    36,   128,   196,    47,
     197,   216,   320,    59,   138,   151,   193,    38,   151,    37,
     178,    54,    64,    74,   330,   179,   211,    48,    38,   212,
     224,   129,   206,   128,    62,   143,    80,   135,    54,   261,
     142,   337,    59,    54,    74,    74,    74,    38,   152,    74,
      63,   152,    69,   343,   344,   290,   345,   223,   228,   229,
     230,   291,   210,   246,   198,   353,   199,   355,    74,   357,
     226,   227,   359,   326,   360,    76,    77,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   215,    36,   129,   276,   128,
     287,    36,   182,   183,   140,   141,    80,    74,    70,    37,
     208,    78,   277,   214,    37,   197,   289,   118,    38,   128,
      74,    68,    38,    74,    79,    36,   209,   305,   277,    70,
      70,    70,    39,    64,    70,   184,   185,   175,   196,   199,
     197,   176,   177,   189,   156,   157,    66,   120,    67,   138,
     129,   297,   128,    70,   158,   262,   190,   215,   235,   236,
     237,   238,   278,   191,   279,   321,   322,   194,   324,   159,
     214,   160,   197,   161,   180,   181,   202,   314,   203,   129,
     316,   128,   186,   187,   118,   218,   219,   333,   334,   318,
     231,   232,    70,   319,   204,   128,   233,   234,   213,   239,
     240,   217,   220,    83,   225,    70,   282,   284,    70,   346,
     348,   350,   285,   292,   293,   294,   295,   301,   296,   298,
     300,   302,   303,   306,   310,   311,   262,   307,   312,   323,
     325,   289,   118,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   286,   328,   329,   331,   332,   335,   336,
     338,   339,   351,   352,   354,   356,   358,   241,   247,   248,
     262,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     172,   242,    82,   243,   132,   244,   283,    75,   245,   131,
      84,    85,   121,   317,   309,    52,     0,     0,     0,     0,
     281,     0,   258,    21,    87,     0,     0,    88,     0,    89,
       0,    90,    91,    92,     0,    93,     0,     0,     0,     0,
     120,   308,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   248,   259,   249,
     250,   251,   252,   253,   254,   255,   256,   257,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,    21,    87,     0,     0,    88,     0,    89,     0,    90,
      91,    92,     0,    93,     0,     0,     0,     0,   120,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,     0,    51,   247,   248,   259,   249,   250,   251,
     252,   253,   254,   255,   256,   257,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
      87,    21,     0,    88,     0,    89,     0,    90,    91,    92,
       0,    93,     0,     0,     0,     0,   120,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    21,    87,
       0,     0,    88,     0,    89,     0,    90,    91,    92,     0,
      93,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    36,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
     272,   197,     0,     0,     0,     0,     0,    21,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     272,   197,     0,     0,     0,     0,     0,     0,    38,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    21,    87,
       0,     0,    88,     0,    89,     0,    90,    91,    92,     0,
      93,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
      21,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,    84,    85,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    86,     0,    87,
       0,     0,    88,   313,    89,     0,    90,    91,    92,     0,
      93,     0,     0,   127,    18,    19,    20,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,    87,     0,     0,    88,     0,    89,     0,    90,    91,
      92,     0,    93,    84,    85,   205,     0,     0,     0,     0,
      95,    96,    97,    98,    99,    86,     0,    87,     0,     0,
      88,     0,    89,     0,    90,    91,    92,     0,    93,     0,
       0,    84,    85,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,    86,     0,    87,     0,     0,    88,     0,
      89,   304,    90,    91,    92,     0,    93,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,   280,     0,    21,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,    21,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    87,
       0,     0,    88,    21,    89,     0,    90,    91,    92,     0,
      93,    84,    85,     0,     0,    94,   288,     0,    95,    96,
      97,    98,    99,    86,     0,    87,     0,     0,    88,     0,
      89,     0,    90,    91,    92,     0,    93,    84,    85,     0,
       0,    94,   342,     0,    95,    96,    97,    98,    99,    86,
       0,    87,     0,     0,    88,     0,    89,     0,    90,    91,
      92,     0,    93,    84,    85,     0,     0,    94,     0,     0,
      95,    96,    97,    98,    99,    86,     0,    87,     0,     0,
      88,     0,    89,     0,    90,    91,    92,     0,    93,   221,
      84,    85,     0,     0,     0,     0,    95,    96,    97,    98,
      99,     0,    86,     0,    87,     0,     0,    88,     0,    89,
       0,    90,    91,    92,     0,    93,    84,    85,   275,     0,
       0,     0,     0,    95,    96,    97,    98,    99,    86,     0,
      87,     0,     0,    88,     0,    89,     0,    90,    91,    92,
       0,    93,    84,    85,     0,     0,   286,     0,     0,    95,
      96,    97,    98,    99,    86,     0,    87,     0,     0,    88,
       0,    89,     0,    90,    91,    92,     0,    93,    84,    85,
     315,     0,     0,     0,     0,    95,    96,    97,    98,    99,
      86,     0,    87,     0,     0,    88,     0,    89,     0,    90,
      91,    92,     0,    93,   347,    84,    85,     0,     0,     0,
       0,    95,    96,    97,    98,    99,     0,    86,     0,    87,
       0,     0,    88,     0,    89,     0,    90,    91,    92,     0,
      93,   349,    84,    85,     0,     0,     0,     0,    95,    96,
      97,    98,    99,     0,    86,     0,    87,     0,     0,    88,
       0,    89,     0,    90,    91,    92,     0,    93,    84,    85,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
      86,     0,    87,     0,     0,    88,     0,    89,     0,    90,
      91,    92,     0,   145,    84,    85,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,    86,     0,    87,     0,
       0,    88,     0,    89,     0,    90,    91,    92,     0,   148,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99
};

static const yytype_int16 yycheck[] =
{
       0,    64,    64,    93,    23,    66,    44,    67,   195,    67,
     252,    77,   300,    70,    48,    57,    71,    74,    78,    78,
      78,    38,   123,    75,    24,    25,    84,    85,   105,    29,
      30,    31,    94,    75,    92,    57,    93,    78,   326,   327,
      32,    33,    34,    62,    61,    75,    57,   105,    70,    57,
      72,   152,   294,    38,    73,   145,    90,    79,   148,    70,
      80,    57,    92,    48,   306,    85,   145,    75,    79,   148,
     160,   131,   131,   131,    77,   141,    61,   132,    57,   266,
      76,   323,    67,    57,    69,    70,    71,    79,   145,    74,
      93,   148,    75,   335,   336,    71,   338,   159,   175,   176,
     177,    77,    76,   193,   123,   347,   123,   349,    93,   351,
     172,   173,   354,   300,   356,    76,    77,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   152,    57,   197,   197,   197,
     217,    57,    53,    54,    76,    77,   131,   132,    48,    70,
      77,    92,   199,    70,    70,    72,   219,   219,    79,   217,
     145,   199,    79,   148,    71,    57,    93,   257,   215,    69,
      70,    71,    93,    92,    74,    86,    87,    79,    70,   196,
      72,    83,    84,    88,    45,    46,    70,    75,    72,   208,
     250,   250,   250,    93,    55,   195,    89,   214,   182,   183,
     184,   185,    70,    47,    72,   295,   296,    76,   298,    70,
      70,    72,    72,    74,    49,    50,    71,   278,    77,   279,
     279,   279,    51,    52,   286,    76,    77,    76,    77,   291,
     178,   179,   132,   293,    73,   293,   180,   181,    71,   186,
     187,    71,    57,   262,    57,   145,    73,    71,   148,   339,
     340,   341,    71,    73,    91,    91,    70,    57,    70,    70,
      70,    93,    93,    91,    71,    71,   266,    93,    73,    91,
       8,   334,   334,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    75,    93,    93,    71,    73,    71,    71,
      71,    70,     5,    71,    71,    71,    93,   188,     3,     4,
     300,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      92,   189,    62,   190,    69,   191,   208,    53,   192,    67,
      45,    46,    65,   286,   266,    31,    -1,    -1,    -1,    -1,
     203,    -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,
      -1,    66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    93,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    -1,    66,
      67,    68,    -1,    70,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     3,     4,    93,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    58,    -1,    62,    -1,    64,    -1,    66,    67,    68,
      -1,    70,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    -1,    66,    67,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    58,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    -1,    66,    67,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      58,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    45,    46,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    62,    71,    64,    -1,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    32,    33,    34,    -1,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    62,    -1,    64,    -1,    66,    67,
      68,    -1,    70,    45,    46,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    57,    -1,    59,    -1,    -1,
      62,    -1,    64,    -1,    66,    67,    68,    -1,    70,    -1,
      -1,    45,    46,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,    -1,
      64,    93,    66,    67,    68,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    56,    -1,    58,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    58,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    62,    58,    64,    -1,    66,    67,    68,    -1,
      70,    45,    46,    -1,    -1,    75,    76,    -1,    78,    79,
      80,    81,    82,    57,    -1,    59,    -1,    -1,    62,    -1,
      64,    -1,    66,    67,    68,    -1,    70,    45,    46,    -1,
      -1,    75,    76,    -1,    78,    79,    80,    81,    82,    57,
      -1,    59,    -1,    -1,    62,    -1,    64,    -1,    66,    67,
      68,    -1,    70,    45,    46,    -1,    -1,    75,    -1,    -1,
      78,    79,    80,    81,    82,    57,    -1,    59,    -1,    -1,
      62,    -1,    64,    -1,    66,    67,    68,    -1,    70,    71,
      45,    46,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    -1,    57,    -1,    59,    -1,    -1,    62,    -1,    64,
      -1,    66,    67,    68,    -1,    70,    45,    46,    73,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    57,    -1,
      59,    -1,    -1,    62,    -1,    64,    -1,    66,    67,    68,
      -1,    70,    45,    46,    -1,    -1,    75,    -1,    -1,    78,
      79,    80,    81,    82,    57,    -1,    59,    -1,    -1,    62,
      -1,    64,    -1,    66,    67,    68,    -1,    70,    45,    46,
      73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      57,    -1,    59,    -1,    -1,    62,    -1,    64,    -1,    66,
      67,    68,    -1,    70,    71,    45,    46,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    -1,    57,    -1,    59,
      -1,    -1,    62,    -1,    64,    -1,    66,    67,    68,    -1,
      70,    71,    45,    46,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    -1,    57,    -1,    59,    -1,    -1,    62,
      -1,    64,    -1,    66,    67,    68,    -1,    70,    45,    46,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      57,    -1,    59,    -1,    -1,    62,    -1,    64,    -1,    66,
      67,    68,    -1,    70,    45,    46,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    57,    -1,    59,    -1,
      -1,    62,    -1,    64,    -1,    66,    67,    68,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    58,   118,   119,   122,   123,   124,   125,   131,   135,
     136,   159,   160,   161,    57,    75,    57,    70,    79,    93,
     120,   121,   137,   138,   139,   119,   119,    57,    75,   119,
     119,     0,   160,    75,    57,   132,   133,   134,   137,   135,
     139,   140,    77,    93,    92,   162,    70,    72,   138,    75,
     123,   126,   127,   128,   135,   132,    76,    77,    92,    71,
     135,   139,   121,   137,    45,    46,    57,    59,    62,    64,
      66,    67,    68,    70,    75,    78,    79,    80,    81,    82,
      95,    96,    97,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   147,
      75,   151,    71,   119,   141,   142,   143,    73,   100,   113,
     117,   140,   126,   128,    76,   127,   129,   130,   137,   128,
      76,    77,    76,   133,   117,    70,   100,   100,    70,   100,
     114,   116,   128,   144,   147,   148,    45,    46,    55,    70,
      72,    74,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    92,   115,   102,    79,    83,    84,    80,    85,
      49,    50,    53,    54,    86,    87,    51,    52,    78,    88,
      89,    47,    48,    90,    76,   152,    70,    72,   137,   139,
     145,   146,    71,    77,    73,    73,   117,    76,    77,    93,
      76,   144,   144,    71,    70,   139,   145,    71,    76,    77,
      57,    71,    99,   114,   116,    57,   114,   114,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   108,   109,   110,   111,   116,     3,     4,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    57,    93,
     116,   118,   119,   149,   150,   151,   153,   154,   155,   156,
     157,   158,    71,   141,   145,    73,   117,   146,    70,    72,
      56,   143,    73,   130,    71,    71,    75,   102,    76,   147,
      71,    77,    73,    91,    91,    70,    70,   117,    70,   149,
      70,    57,    93,    93,    93,   116,    91,    93,    76,   154,
      71,    71,    73,    71,   141,    73,   117,   148,   114,   113,
     149,   116,   116,    91,   116,     8,   118,   155,    93,    93,
     149,    71,    73,    76,    77,    71,    71,   149,    71,    70,
     155,   155,    76,   149,   149,   149,   116,    71,   116,    71,
     116,     5,    71,   149,    71,   149,    71,   149,    93,   149,
     149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   116,
     117,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   124,   125,   125,   126,   126,   127,   128,
     128,   128,   128,   129,   129,   130,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   135,   135,   135,   136,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   144,   144,   145,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     148,   148,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   151,   152,   151,   153,   153,   154,   154,   155,   155,
     156,   156,   156,   157,   157,   157,   157,   157,   157,   158,
     158,   158,   158,   158,   159,   159,   160,   160,   162,   161
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     6,
       7,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     1,     1,     1,     2,     3,     2,
       1,     2,     1,     1,     3,     1,     4,     5,     5,     6,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     5,     4,     4,     3,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     0,     4,     1,     2,     1,     1,     1,     2,
       5,     7,     5,     5,     7,     6,     7,     6,     7,     3,
       2,     2,     2,     3,     1,     2,     1,     1,     0,     4
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
#line 1739 "parser.c"
    break;

  case 3: /* primary_expression: constant  */
#line 154 "bison/parser.yacc"
                                { (yyval.expr) = make_const_expr((yyvsp[0].constant)); }
#line 1745 "parser.c"
    break;

  case 4: /* primary_expression: string  */
#line 155 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1751 "parser.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 156 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1757 "parser.c"
    break;

  case 6: /* constant: CONST_INT  */
#line 160 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_INT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1763 "parser.c"
    break;

  case 7: /* constant: CONST_FLOAT  */
#line 161 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_FLOAT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1769 "parser.c"
    break;

  case 8: /* constant: ENUM_CONST  */
#line 162 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_ENUM, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1775 "parser.c"
    break;

  case 9: /* string: STR_LITERAL  */
#line 165 "bison/parser.yacc"
                    { (yyval.expr) = make_string_expr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1781 "parser.c"
    break;

  case 10: /* string: FUNC_NAME  */
#line 166 "bison/parser.yacc"
                    { (yyval.expr) = make_string_expr(func_name()); }
#line 1787 "parser.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 169 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1793 "parser.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 170 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_SUBSCRIPT, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1799 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 171 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-2].expr), 0); }
#line 1805 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 172 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1811 "parser.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 173 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_DOT, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1817 "parser.c"
    break;

  case 16: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 174 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_ARROW, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1823 "parser.c"
    break;

  case 17: /* postfix_expression: postfix_expression INCREMENT  */
#line 175 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_INCR, (yyvsp[-1].expr), 0); }
#line 1829 "parser.c"
    break;

  case 18: /* postfix_expression: postfix_expression DECREMENT  */
#line 176 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_DECR, (yyvsp[-1].expr), 0); }
#line 1835 "parser.c"
    break;

  case 19: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 177 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-4].type_name), (yyvsp[-1].init_list)); }
#line 1841 "parser.c"
    break;

  case 20: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 178 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-5].type_name), (yyvsp[-2].init_list)); }
#line 1847 "parser.c"
    break;

  case 21: /* argument_expression_list: assignment_expression  */
#line 182 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), 0); }
#line 1853 "parser.c"
    break;

  case 22: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 183 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1859 "parser.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 187 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1865 "parser.c"
    break;

  case 24: /* unary_expression: INCREMENT unary_expression  */
#line 188 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_INCR, (yyvsp[0].expr), 0); }
#line 1871 "parser.c"
    break;

  case 25: /* unary_expression: DECREMENT unary_expression  */
#line 189 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_DECR, (yyvsp[0].expr), 0); }
#line 1877 "parser.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 190 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[0].expr), 0); }
#line 1883 "parser.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 191 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_SIZEOF_EXPR, (yyvsp[0].expr), 0); }
#line 1889 "parser.c"
    break;

  case 28: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 192 "bison/parser.yacc"
                                            { (yyval.expr) = make_sizeof_expr((yyvsp[-1].type_name)); }
#line 1895 "parser.c"
    break;

  case 29: /* unary_operator: '&'  */
#line 196 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_ADDREF; }
#line 1901 "parser.c"
    break;

  case 30: /* unary_operator: '*'  */
#line 197 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_DEREF; }
#line 1907 "parser.c"
    break;

  case 31: /* unary_operator: '-'  */
#line 198 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_MINUS; }
#line 1913 "parser.c"
    break;

  case 32: /* unary_operator: '~'  */
#line 199 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_BITNOT; }
#line 1919 "parser.c"
    break;

  case 33: /* unary_operator: '!'  */
#line 200 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_LOGNOT; }
#line 1925 "parser.c"
    break;

  case 34: /* cast_expression: unary_expression  */
#line 204 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1931 "parser.c"
    break;

  case 35: /* cast_expression: '(' type_name ')' cast_expression  */
#line 205 "bison/parser.yacc"
                                            { (yyval.expr) = make_cast_expr((yyvsp[-2].type_name), (yyvsp[0].expr)); }
#line 1937 "parser.c"
    break;

  case 36: /* multiplicative_expression: cast_expression  */
#line 209 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1943 "parser.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 210 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1949 "parser.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 211 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1955 "parser.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 212 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1961 "parser.c"
    break;

  case 40: /* additive_expression: multiplicative_expression  */
#line 216 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1967 "parser.c"
    break;

  case 41: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 217 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1973 "parser.c"
    break;

  case 42: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 218 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1979 "parser.c"
    break;

  case 43: /* shift_expression: additive_expression  */
#line 222 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1985 "parser.c"
    break;

  case 44: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 223 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1991 "parser.c"
    break;

  case 45: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 224 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_RSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1997 "parser.c"
    break;

  case 46: /* relational_expression: shift_expression  */
#line 228 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2003 "parser.c"
    break;

  case 47: /* relational_expression: relational_expression '<' shift_expression  */
#line 229 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2009 "parser.c"
    break;

  case 48: /* relational_expression: relational_expression '>' shift_expression  */
#line 230 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2015 "parser.c"
    break;

  case 49: /* relational_expression: relational_expression LEQ shift_expression  */
#line 231 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2021 "parser.c"
    break;

  case 50: /* relational_expression: relational_expression GEQ shift_expression  */
#line 232 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2027 "parser.c"
    break;

  case 51: /* equality_expression: relational_expression  */
#line 236 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2033 "parser.c"
    break;

  case 52: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 237 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2039 "parser.c"
    break;

  case 53: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 238 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2045 "parser.c"
    break;

  case 54: /* and_expression: equality_expression  */
#line 242 "bison/parser.yacc"
                                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2051 "parser.c"
    break;

  case 55: /* and_expression: and_expression '&' equality_expression  */
#line 243 "bison/parser.yacc"
                                                    { (yyval.expr) = make_expr(EXPR_BITAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2057 "parser.c"
    break;

  case 56: /* exclusive_or_expression: and_expression  */
#line 247 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2063 "parser.c"
    break;

  case 57: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 248 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_BITXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2069 "parser.c"
    break;

  case 58: /* inclusive_or_expression: exclusive_or_expression  */
#line 252 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2075 "parser.c"
    break;

  case 59: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 253 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_BITOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2081 "parser.c"
    break;

  case 60: /* logical_and_expression: inclusive_or_expression  */
#line 257 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2087 "parser.c"
    break;

  case 61: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 258 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2093 "parser.c"
    break;

  case 62: /* logical_or_expression: logical_and_expression  */
#line 262 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2099 "parser.c"
    break;

  case 63: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 263 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2105 "parser.c"
    break;

  case 64: /* conditional_expression: logical_or_expression  */
#line 267 "bison/parser.yacc"
                                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2111 "parser.c"
    break;

  case 65: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 268 "bison/parser.yacc"
                                                                            { (yyval.expr) = make_ternary_expr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2117 "parser.c"
    break;

  case 66: /* assignment_expression: conditional_expression  */
#line 272 "bison/parser.yacc"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2123 "parser.c"
    break;

  case 67: /* assignment_expression: unary_expression '=' assignment_expression  */
#line 273 "bison/parser.yacc"
                                                                        { (yyval.expr) = make_expr(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2129 "parser.c"
    break;

  case 68: /* assignment_expression: unary_expression compound_assignment assignment_expression  */
#line 274 "bison/parser.yacc"
                                                                    { (yyval.expr) = make_expr(EXPR_ASSIGN, (yyvsp[-2].expr), make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 2135 "parser.c"
    break;

  case 69: /* compound_assignment: ADD_ASSIGN  */
#line 278 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ADD; }
#line 2141 "parser.c"
    break;

  case 70: /* compound_assignment: SUB_ASSIGN  */
#line 279 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_SUB; }
#line 2147 "parser.c"
    break;

  case 71: /* compound_assignment: MUL_ASSIGN  */
#line 280 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_MUL; }
#line 2153 "parser.c"
    break;

  case 72: /* compound_assignment: DIV_ASSIGN  */
#line 281 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_DIV; }
#line 2159 "parser.c"
    break;

  case 73: /* compound_assignment: MOD_ASSIGN  */
#line 282 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_MOD; }
#line 2165 "parser.c"
    break;

  case 74: /* compound_assignment: AND_ASSIGN  */
#line 283 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_BITAND; }
#line 2171 "parser.c"
    break;

  case 75: /* compound_assignment: OR_ASSIGN  */
#line 284 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_BITOR; }
#line 2177 "parser.c"
    break;

  case 76: /* compound_assignment: XOR_ASSIGN  */
#line 285 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_BITXOR; }
#line 2183 "parser.c"
    break;

  case 77: /* compound_assignment: LSHIFT_ASSIGN  */
#line 286 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_LSHIFT; }
#line 2189 "parser.c"
    break;

  case 78: /* compound_assignment: RSHIFT_ASSIGN  */
#line 287 "bison/parser.yacc"
                    { (yyval.int_val) = EXPR_RSHIFT; }
#line 2195 "parser.c"
    break;

  case 79: /* expression: assignment_expression  */
#line 291 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2201 "parser.c"
    break;

  case 80: /* constant_expression: conditional_expression  */
#line 295 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2207 "parser.c"
    break;

  case 81: /* declaration: declaration_specifiers ';'  */
#line 299 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), 0); }
#line 2213 "parser.c"
    break;

  case 82: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 301 "bison/parser.yacc"
    {
        (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].init_decltr));
        add_typedef_type((yyval.decl));
    }
#line 2222 "parser.c"
    break;

  case 83: /* declaration_specifiers: storage_class_specifier  */
#line 308 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class(0, (yyvsp[0].int_val)); }
#line 2228 "parser.c"
    break;

  case 84: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 309 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2234 "parser.c"
    break;

  case 85: /* declaration_specifiers: type_specifier  */
#line 310 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2240 "parser.c"
    break;

  case 86: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 311 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2246 "parser.c"
    break;

  case 87: /* declaration_specifiers: type_qualifier  */
#line 312 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2252 "parser.c"
    break;

  case 88: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 313 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2258 "parser.c"
    break;

  case 89: /* declaration_specifiers: function_specifier  */
#line 314 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec(0, (yyvsp[0].int_val)); }
#line 2264 "parser.c"
    break;

  case 90: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 315 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2270 "parser.c"
    break;

  case 91: /* init_declarator_list: init_declarator  */
#line 319 "bison/parser.yacc"
                                                    { (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2276 "parser.c"
    break;

  case 92: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 320 "bison/parser.yacc"
                                                    { add_init_decltr((yyvsp[-2].init_decltr), (yyvsp[0].init_decltr)); (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2282 "parser.c"
    break;

  case 93: /* init_declarator: declarator  */
#line 324 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[0].decltr), 0); }
#line 2288 "parser.c"
    break;

  case 94: /* init_declarator: declarator '=' initializer  */
#line 325 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[-2].decltr), (yyvsp[0].initializer)); }
#line 2294 "parser.c"
    break;

  case 95: /* storage_class_specifier: TYPEDEF  */
#line 329 "bison/parser.yacc"
                    { (yyval.int_val) = SC_TYPEDEF; }
#line 2300 "parser.c"
    break;

  case 96: /* storage_class_specifier: EXTERN  */
#line 330 "bison/parser.yacc"
                    { (yyval.int_val) = SC_EXTERN; }
#line 2306 "parser.c"
    break;

  case 97: /* storage_class_specifier: STATIC  */
#line 331 "bison/parser.yacc"
                    { (yyval.int_val) = SC_STATIC; }
#line 2312 "parser.c"
    break;

  case 98: /* type_specifier: VOID  */
#line 335 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_VOID); }
#line 2318 "parser.c"
    break;

  case 99: /* type_specifier: CHAR  */
#line 336 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_CHAR); }
#line 2324 "parser.c"
    break;

  case 100: /* type_specifier: SHORT  */
#line 337 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SHORT); }
#line 2330 "parser.c"
    break;

  case 101: /* type_specifier: INT  */
#line 338 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_INT); }
#line 2336 "parser.c"
    break;

  case 102: /* type_specifier: LONG  */
#line 339 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_LONG); }
#line 2342 "parser.c"
    break;

  case 103: /* type_specifier: FLOAT  */
#line 340 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_FLOAT); }
#line 2348 "parser.c"
    break;

  case 104: /* type_specifier: DOUBLE  */
#line 341 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_DOUBLE); }
#line 2354 "parser.c"
    break;

  case 105: /* type_specifier: SIGNED  */
#line 342 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SIGNED); }
#line 2360 "parser.c"
    break;

  case 106: /* type_specifier: UNSIGNED  */
#line 343 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_UNSIGNED); }
#line 2366 "parser.c"
    break;

  case 107: /* type_specifier: BOOL  */
#line 344 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_BOOL); }
#line 2372 "parser.c"
    break;

  case 108: /* type_specifier: struct_or_union_specifier  */
#line 345 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_sou_type_spec((yyvsp[0].sou_spec)); }
#line 2378 "parser.c"
    break;

  case 109: /* type_specifier: enum_specifier  */
#line 346 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_enum_type_spec((yyvsp[0].enum_spec)); }
#line 2384 "parser.c"
    break;

  case 110: /* type_specifier: TYPEDEF_NAME  */
#line 347 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_typedef_type_spec((yyvsp[0].sval)); }
#line 2390 "parser.c"
    break;

  case 111: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 351 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-4].int_val), (yyvsp[-3].sval), (yyvsp[-1].struct_decl_list)); }
#line 2396 "parser.c"
    break;

  case 112: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 352 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-3].int_val), 0, (yyvsp[-1].struct_decl_list)); }
#line 2402 "parser.c"
    break;

  case 113: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 353 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-1].int_val), (yyvsp[0].sval), 0); }
#line 2408 "parser.c"
    break;

  case 114: /* struct_or_union: STRUCT  */
#line 357 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_STRUCT; }
#line 2414 "parser.c"
    break;

  case 115: /* struct_or_union: UNION  */
#line 358 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_UNION; }
#line 2420 "parser.c"
    break;

  case 116: /* struct_declaration_list: struct_declaration  */
#line 362 "bison/parser.yacc"
                                                        { (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2426 "parser.c"
    break;

  case 117: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 363 "bison/parser.yacc"
                                                        { add_struct_decl((yyvsp[-1].struct_decl_list), (yyvsp[0].struct_decl_list)); (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2432 "parser.c"
    break;

  case 118: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 367 "bison/parser.yacc"
                                                                { (yyval.struct_decl_list) = make_struct_decl_list(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].struct_decltr_list)); }
#line 2438 "parser.c"
    break;

  case 119: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 371 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2444 "parser.c"
    break;

  case 120: /* specifier_qualifier_list: type_specifier  */
#line 372 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2450 "parser.c"
    break;

  case 121: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 373 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2456 "parser.c"
    break;

  case 122: /* specifier_qualifier_list: type_qualifier  */
#line 374 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2462 "parser.c"
    break;

  case 123: /* struct_declarator_list: struct_declarator  */
#line 378 "bison/parser.yacc"
                                                        { (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2468 "parser.c"
    break;

  case 124: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 379 "bison/parser.yacc"
                                                        { add_struct_decltr((yyvsp[-2].struct_decltr_list), (yyvsp[0].struct_decltr_list)); (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2474 "parser.c"
    break;

  case 125: /* struct_declarator: declarator  */
#line 383 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[0].decltr)); }
#line 2480 "parser.c"
    break;

  case 126: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 387 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-1].enumerator_list)); }
#line 2486 "parser.c"
    break;

  case 127: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 388 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-3].sval), (yyvsp[-1].enumerator_list)); }
#line 2492 "parser.c"
    break;

  case 128: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 389 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-2].enumerator_list)); }
#line 2498 "parser.c"
    break;

  case 129: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 390 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-4].sval), (yyvsp[-2].enumerator_list)); }
#line 2504 "parser.c"
    break;

  case 130: /* enum_specifier: ENUM IDENTIFIER  */
#line 391 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[0].sval), 0); }
#line 2510 "parser.c"
    break;

  case 131: /* enumerator_list: enumerator  */
#line 395 "bison/parser.yacc"
                                            { (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2516 "parser.c"
    break;

  case 132: /* enumerator_list: enumerator_list ',' enumerator  */
#line 396 "bison/parser.yacc"
                                            { add_enumerator((yyvsp[-2].enumerator_list), (yyvsp[0].enumerator_list)); (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2522 "parser.c"
    break;

  case 133: /* enumerator: enumeration_constant  */
#line 400 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[0].sval), 0); free((yyvsp[0].sval)); }
#line 2528 "parser.c"
    break;

  case 134: /* enumerator: enumeration_constant '=' constant_expression  */
#line 401 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[-2].sval), (yyvsp[0].expr)); free((yyvsp[-2].sval)); }
#line 2534 "parser.c"
    break;

  case 135: /* enumeration_constant: IDENTIFIER  */
#line 405 "bison/parser.yacc"
                    { sym_define_enum((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); }
#line 2540 "parser.c"
    break;

  case 136: /* type_qualifier: CONST  */
#line 408 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_CONST; }
#line 2546 "parser.c"
    break;

  case 137: /* type_qualifier: RESTRICT  */
#line 409 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_RESTRICT; }
#line 2552 "parser.c"
    break;

  case 138: /* type_qualifier: VOLATILE  */
#line 410 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_VOLATILE; }
#line 2558 "parser.c"
    break;

  case 139: /* function_specifier: INLINE  */
#line 414 "bison/parser.yacc"
                    { (yyval.int_val) = FS_INLINE; }
#line 2564 "parser.c"
    break;

  case 140: /* declarator: pointer direct_declarator  */
#line 420 "bison/parser.yacc"
                                    { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); (yyval.decltr) = (yyvsp[0].decltr); }
#line 2570 "parser.c"
    break;

  case 141: /* declarator: direct_declarator  */
#line 421 "bison/parser.yacc"
                                    { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2576 "parser.c"
    break;

  case 142: /* direct_declarator: IDENTIFIER  */
#line 426 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_id_decltr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2582 "parser.c"
    break;

  case 143: /* direct_declarator: '(' declarator ')'  */
#line 427 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2588 "parser.c"
    break;

  case 144: /* direct_declarator: direct_declarator '[' type_qualifier_list constant_expression ']'  */
#line 428 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr)); }
#line 2594 "parser.c"
    break;

  case 145: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 429 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), (yyvsp[-1].type_qual_list), 0); }
#line 2600 "parser.c"
    break;

  case 146: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 430 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2606 "parser.c"
    break;

  case 147: /* direct_declarator: direct_declarator '[' ']'  */
#line 431 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2612 "parser.c"
    break;

  case 148: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 432 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_type_list)); }
#line 2618 "parser.c"
    break;

  case 149: /* direct_declarator: direct_declarator '(' ')'  */
#line 433 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2624 "parser.c"
    break;

  case 150: /* pointer: '*'  */
#line 437 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, 0); }
#line 2630 "parser.c"
    break;

  case 151: /* pointer: '*' type_qualifier_list  */
#line 438 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[0].type_qual_list), 0); }
#line 2636 "parser.c"
    break;

  case 152: /* pointer: '*' pointer  */
#line 439 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, (yyvsp[0].pointer)); }
#line 2642 "parser.c"
    break;

  case 153: /* pointer: '*' type_qualifier_list pointer  */
#line 440 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[-1].type_qual_list), (yyvsp[0].pointer)); }
#line 2648 "parser.c"
    break;

  case 154: /* type_qualifier_list: type_qualifier  */
#line 444 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list(0, (yyvsp[0].int_val)); }
#line 2654 "parser.c"
    break;

  case 155: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 445 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list((yyvsp[-1].type_qual_list), (yyvsp[0].int_val)); }
#line 2660 "parser.c"
    break;

  case 156: /* parameter_type_list: parameter_list  */
#line 450 "bison/parser.yacc"
                                        { (yyval.param_type_list) = make_param_type_list((yyvsp[0].param_list), 0); }
#line 2666 "parser.c"
    break;

  case 157: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 451 "bison/parser.yacc"
                                    { (yyval.param_type_list) = make_param_type_list((yyvsp[-2].param_list), 1); }
#line 2672 "parser.c"
    break;

  case 158: /* parameter_list: parameter_declaration  */
#line 455 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list(0, (yyvsp[0].decl)); }
#line 2678 "parser.c"
    break;

  case 159: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 456 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list((yyvsp[-2].param_list), (yyvsp[0].decl)); }
#line 2684 "parser.c"
    break;

  case 160: /* parameter_declaration: declaration_specifiers declarator  */
#line 460 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 0); }
#line 2690 "parser.c"
    break;

  case 161: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 461 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 1); }
#line 2696 "parser.c"
    break;

  case 162: /* parameter_declaration: declaration_specifiers  */
#line 462 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[0].decl_spec_list)), 0, 0); }
#line 2702 "parser.c"
    break;

  case 163: /* type_name: specifier_qualifier_list  */
#line 466 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[0].decl_spec_list)), 0); }
#line 2708 "parser.c"
    break;

  case 164: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 467 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr)); }
#line 2714 "parser.c"
    break;

  case 165: /* abstract_declarator: pointer  */
#line 471 "bison/parser.yacc"
                                                { (yyval.decltr) = make_empty_decltr((yyvsp[0].pointer)); }
#line 2720 "parser.c"
    break;

  case 166: /* abstract_declarator: direct_abstract_declarator  */
#line 472 "bison/parser.yacc"
                                                { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2726 "parser.c"
    break;

  case 167: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 473 "bison/parser.yacc"
                                                { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); }
#line 2732 "parser.c"
    break;

  case 168: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 477 "bison/parser.yacc"
                                                                    { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2738 "parser.c"
    break;

  case 169: /* direct_abstract_declarator: '[' ']'  */
#line 478 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0); }
#line 2744 "parser.c"
    break;

  case 170: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 479 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, (yyvsp[-1].expr)); }
#line 2750 "parser.c"
    break;

  case 171: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 480 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2756 "parser.c"
    break;

  case 172: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 481 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2762 "parser.c"
    break;

  case 173: /* direct_abstract_declarator: '(' ')'  */
#line 482 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, 0); }
#line 2768 "parser.c"
    break;

  case 174: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 483 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, (yyvsp[-1].param_type_list)); }
#line 2774 "parser.c"
    break;

  case 175: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 484 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2780 "parser.c"
    break;

  case 176: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 485 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_type_list)); }
#line 2786 "parser.c"
    break;

  case 177: /* initializer: assignment_expression  */
#line 489 "bison/parser.yacc"
                                        { (yyval.initializer) = make_expr_init((yyvsp[0].expr)); }
#line 2792 "parser.c"
    break;

  case 178: /* initializer: '{' initializer_list '}'  */
#line 490 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-1].init_list)); }
#line 2798 "parser.c"
    break;

  case 179: /* initializer: '{' initializer_list ',' '}'  */
#line 491 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-2].init_list)); }
#line 2804 "parser.c"
    break;

  case 180: /* initializer_list: initializer  */
#line 495 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, (yyvsp[0].initializer)); }
#line 2810 "parser.c"
    break;

  case 181: /* initializer_list: initializer_list ',' initializer  */
#line 496 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-2].init_list), (yyvsp[0].initializer)); }
#line 2816 "parser.c"
    break;

  case 182: /* statement: labeled_statement  */
#line 500 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2822 "parser.c"
    break;

  case 183: /* statement: compound_statement  */
#line 501 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2828 "parser.c"
    break;

  case 184: /* statement: expression_statement  */
#line 502 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2834 "parser.c"
    break;

  case 185: /* statement: selection_statement  */
#line 503 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2840 "parser.c"
    break;

  case 186: /* statement: iteration_statement  */
#line 504 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2846 "parser.c"
    break;

  case 187: /* statement: jump_statement  */
#line 505 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2852 "parser.c"
    break;

  case 188: /* labeled_statement: IDENTIFIER ':' statement  */
#line 509 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_labeled_stmt((yyvsp[-2].sval), (yyvsp[0].stmt)); }
#line 2858 "parser.c"
    break;

  case 189: /* labeled_statement: CASE constant_expression ':' statement  */
#line 510 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_case_stmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2864 "parser.c"
    break;

  case 190: /* labeled_statement: DEFAULT ':' statement  */
#line 511 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_default_stmt((yyvsp[0].stmt)); }
#line 2870 "parser.c"
    break;

  case 191: /* compound_statement: '{' '}'  */
#line 515 "bison/parser.yacc"
                            { (yyval.stmt) = make_compound_stmt(0); }
#line 2876 "parser.c"
    break;

  case 192: /* $@1: %empty  */
#line 516 "bison/parser.yacc"
                            { sym_push_scope(); }
#line 2882 "parser.c"
    break;

  case 193: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 518 "bison/parser.yacc"
                        { sym_pop_scope(); (yyval.stmt) = make_compound_stmt((yyvsp[-1].block_list)); }
#line 2888 "parser.c"
    break;

  case 194: /* block_item_list: block_item  */
#line 522 "bison/parser.yacc"
                                        { (yyval.block_list) = (yyvsp[0].block_list); }
#line 2894 "parser.c"
    break;

  case 195: /* block_item_list: block_item_list block_item  */
#line 523 "bison/parser.yacc"
                                        { add_block_item((yyvsp[-1].block_list), (yyvsp[0].block_list)); (yyval.block_list) = (yyvsp[0].block_list); }
#line 2900 "parser.c"
    break;

  case 196: /* block_item: declaration  */
#line 527 "bison/parser.yacc"
                        { (yyval.block_list) = make_decl_block_item((yyvsp[0].decl)); }
#line 2906 "parser.c"
    break;

  case 197: /* block_item: statement  */
#line 528 "bison/parser.yacc"
                        { (yyval.block_list) = make_stmt_block_item((yyvsp[0].stmt)); }
#line 2912 "parser.c"
    break;

  case 198: /* expression_statement: ';'  */
#line 532 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt(0); }
#line 2918 "parser.c"
    break;

  case 199: /* expression_statement: expression ';'  */
#line 533 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt((yyvsp[-1].expr)); }
#line 2924 "parser.c"
    break;

  case 200: /* selection_statement: IF '(' expression ')' statement  */
#line 537 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 2930 "parser.c"
    break;

  case 201: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 538 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 2936 "parser.c"
    break;

  case 202: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 539 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_SWITCH, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 2942 "parser.c"
    break;

  case 203: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 543 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_WHILE, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 2948 "parser.c"
    break;

  case 204: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 544 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_DO, (yyvsp[-2].expr), (yyvsp[-5].stmt), 0); }
#line 2954 "parser.c"
    break;

  case 205: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 545 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-3].stmt), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 2960 "parser.c"
    break;

  case 206: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 546 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2966 "parser.c"
    break;

  case 207: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 547 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-3].decl), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 2972 "parser.c"
    break;

  case 208: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 548 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-4].decl), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2978 "parser.c"
    break;

  case 209: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 552 "bison/parser.yacc"
                                { (yyval.stmt) = make_goto_stmt((yyvsp[-1].sval)); }
#line 2984 "parser.c"
    break;

  case 210: /* jump_statement: CONTINUE ';'  */
#line 553 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_CONTINUE); }
#line 2990 "parser.c"
    break;

  case 211: /* jump_statement: BREAK ';'  */
#line 554 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_BREAK); }
#line 2996 "parser.c"
    break;

  case 212: /* jump_statement: RETURN ';'  */
#line 555 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt(0); }
#line 3002 "parser.c"
    break;

  case 213: /* jump_statement: RETURN expression ';'  */
#line 556 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt((yyvsp[-1].expr)); }
#line 3008 "parser.c"
    break;

  case 214: /* translation_unit: external_declaration  */
#line 560 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit(0, (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3014 "parser.c"
    break;

  case 215: /* translation_unit: translation_unit external_declaration  */
#line 561 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit((yyvsp[-1].translation_unit), (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3020 "parser.c"
    break;

  case 216: /* external_declaration: function_definition  */
#line 565 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_func_ext_decl((yyvsp[0].func_def)); }
#line 3026 "parser.c"
    break;

  case 217: /* external_declaration: declaration  */
#line 566 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_decl_ext_decl((yyvsp[0].decl)); }
#line 3032 "parser.c"
    break;

  case 218: /* $@2: %empty  */
#line 570 "bison/parser.yacc"
                                                                { set_func_name(get_decltr_id((yyvsp[0].decltr))); }
#line 3038 "parser.c"
    break;

  case 219: /* function_definition: declaration_specifiers declarator $@2 compound_statement  */
#line 572 "bison/parser.yacc"
    {
        func_ended();
        (yyval.func_def) = make_func_def(make_decl_specs((yyvsp[-3].decl_spec_list)), (yyvsp[-2].decltr), (yyvsp[0].stmt));
    }
#line 3047 "parser.c"
    break;


#line 3051 "parser.c"

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

#line 578 "bison/parser.yacc"
