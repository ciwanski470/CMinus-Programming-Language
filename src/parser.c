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
  YYSYMBOL_PRINT = 24,                     /* PRINT  */
  YYSYMBOL_MALLOC = 25,                    /* MALLOC  */
  YYSYMBOL_CHAR = 26,                      /* CHAR  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_SHORT = 28,                     /* SHORT  */
  YYSYMBOL_LONG = 29,                      /* LONG  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 31,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 32,                      /* BOOL  */
  YYSYMBOL_VOID = 33,                      /* VOID  */
  YYSYMBOL_SIGNED = 34,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 35,                  /* UNSIGNED  */
  YYSYMBOL_CONST = 36,                     /* CONST  */
  YYSYMBOL_RESTRICT = 37,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 38,                  /* VOLATILE  */
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
  YYSYMBOL_print_statement = 159,          /* print_statement  */
  YYSYMBOL_translation_unit = 160,         /* translation_unit  */
  YYSYMBOL_external_declaration = 161,     /* external_declaration  */
  YYSYMBOL_function_definition = 162,      /* function_definition  */
  YYSYMBOL_163_2 = 163                     /* $@2  */
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
#define YYLAST   1482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  379

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
       0,   151,   151,   152,   153,   154,   158,   159,   160,   163,
     164,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   180,   181,   185,   186,   187,   188,   189,   190,   191,
     195,   196,   197,   198,   199,   200,   204,   205,   209,   210,
     211,   212,   216,   217,   218,   222,   223,   224,   228,   229,
     230,   231,   232,   236,   237,   238,   242,   243,   247,   248,
     252,   253,   257,   258,   262,   263,   267,   268,   272,   273,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   291,   292,   296,   300,   301,   309,   310,   311,   312,
     313,   314,   315,   316,   320,   321,   325,   326,   330,   331,
     332,   333,   334,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   354,   355,   356,   360,
     361,   365,   366,   370,   374,   375,   376,   377,   381,   382,
     386,   387,   388,   392,   393,   394,   395,   396,   400,   401,
     405,   406,   410,   413,   414,   415,   419,   425,   426,   431,
     432,   433,   434,   435,   436,   437,   438,   442,   443,   444,
     445,   449,   450,   455,   456,   460,   461,   465,   466,   467,
     471,   472,   476,   477,   478,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   494,   495,   496,   500,   501,   505,
     506,   507,   508,   509,   510,   511,   515,   516,   517,   521,
     522,   522,   528,   529,   533,   534,   538,   539,   543,   544,
     545,   549,   550,   551,   552,   553,   554,   558,   559,   560,
     561,   562,   566,   570,   571,   575,   576,   580,   580
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
  "INLINE", "ENUM", "STRUCT", "UNION", "PRINT", "MALLOC", "CHAR", "INT",
  "SHORT", "LONG", "FLOAT", "DOUBLE", "BOOL", "VOID", "SIGNED", "UNSIGNED",
  "CONST", "RESTRICT", "VOLATILE", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "OR_ASSIGN",
  "XOR_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "INCREMENT", "DECREMENT",
  "AND", "OR", "LSHIFT", "RSHIFT", "EQUAL", "NOT_EQUAL", "LEQ", "GEQ",
  "ARROW", "ELLIPSIS", "IDENTIFIER", "TYPEDEF_NAME", "ENUM_CONST",
  "CONST_INT", "CONST_FLOAT", "STR_LITERAL", "FUNC_NAME", "SIZEOF",
  "NO_ELSE", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "'='", "';'", "$accept", "primary_expression",
  "constant", "string", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "$@1", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "print_statement", "translation_unit",
  "external_declaration", "function_definition", "$@2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-223)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-228)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1402,  -223,  -223,  -223,  -223,  -223,  -223,    40,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,    24,  1402,  1402,  -223,   120,
    -223,  1402,  1402,   879,  -223,  -223,   -34,   -45,  -223,    21,
     -24,  -223,   -47,  -223,   -52,    38,    81,  -223,  -223,    46,
    1420,  -223,  -223,  -223,  -223,   -45,  -223,    73,  -223,    82,
      88,  -223,  -223,   -24,    21,  -223,   942,   116,  1227,   258,
      38,  1420,  1420,  1247,  -223,    16,  1420,   106,  -223,   -23,
    1112,  -223,  -223,  -223,  -223,    87,   139,  1135,  1135,  -223,
    -223,  -223,  -223,  -223,  -223,  1158,   810,   942,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,   103,    22,  1112,
    -223,   135,   166,   196,     1,   204,   144,   124,   136,   185,
     -43,  -223,  -223,  -223,   168,  -223,  -223,    84,   169,   195,
    -223,  -223,  -223,  -223,   202,   893,  1303,  -223,  -223,  -223,
    1112,    19,  -223,   179,  -223,  -223,    13,  -223,  -223,  -223,
    1112,   810,  -223,  -223,   810,  -223,  -223,    99,   -28,   215,
    -223,   197,  -223,  -223,   227,   965,  1112,   231,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  1112,
    -223,  1112,  1112,  1112,  1112,  1112,  1112,  1112,  1112,  1112,
    1112,  1112,  1112,  1112,  1112,  1112,  1112,  1112,  1112,  1112,
    -223,   430,   726,   988,  -223,   138,  -223,    41,  -223,  1354,
    -223,  -223,   220,  -223,  -223,    16,  -223,  1112,  -223,   125,
     228,   230,  -223,  1112,   791,    76,  -223,  1014,  -223,   495,
    -223,  -223,   127,  -223,    -2,  -223,  -223,  -223,  -223,  -223,
     135,   135,   166,   166,   196,   196,   196,   196,     1,     1,
     204,   144,   124,   136,   185,   101,   211,   233,   234,  1112,
     235,   518,   236,   248,   218,   223,   622,   243,   226,  -223,
      92,  -223,    24,  -223,  -223,  -223,   342,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,   256,   259,  -223,   260,    41,  1284,
    1037,  -223,  -223,  -223,  -223,  -223,  -223,   257,   257,  -223,
     942,  -223,  -223,  -223,  -223,  1112,  -223,  1112,   518,  1112,
    1112,   244,  1112,   326,   587,   249,  -223,  -223,  -223,    94,
    1112,   518,  -223,  -223,  -223,  -223,  -223,  -223,  -223,   272,
    -223,   308,   201,  -223,  -223,  -223,   134,   146,   518,   150,
     312,   657,   657,  -223,  -223,   153,  -223,  -223,  -223,  -223,
     919,   518,   518,  -223,   518,  1112,  1063,  1086,   290,  -223,
     379,  -223,  -223,   161,   518,   162,   518,   164,  -223,   518,
     292,  -223,   518,  -223,   518,  -223,  -223,  -223,  -223
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,    99,   100,   101,   102,   146,     0,   119,   120,
     104,   106,   105,   107,   108,   109,   112,   103,   110,   111,
     143,   144,   145,   115,   226,     0,    86,    88,   113,     0,
     114,    90,    92,     0,   223,   225,   137,     0,   149,     0,
     157,    84,     0,    94,    96,   148,     0,    87,    89,   118,
       0,    91,    93,     1,   224,     0,   142,     0,   138,   140,
       0,   161,   159,   158,     0,    85,     0,     0,     0,     0,
     147,     0,   125,     0,   121,     0,   127,     0,   133,     0,
       0,   150,   162,   160,    95,    96,     0,     0,     0,     2,
       8,     6,     7,     9,    10,     0,     0,     0,    30,    31,
      32,    33,    34,    35,    11,     3,     4,    23,    36,     0,
      38,    42,    45,    48,    53,    56,    58,    60,    62,    64,
      66,    68,   184,    97,   200,   228,   156,   169,     0,   163,
     165,   154,    36,    83,     0,     0,     0,   124,   117,   122,
       0,     0,   128,   130,   126,   134,     0,   135,   139,   141,
       0,     0,    24,    25,     0,    27,    81,     0,   170,     0,
     187,     0,    17,    18,     0,     0,     0,     0,    74,    75,
      71,    72,    73,    78,    80,    79,    76,    77,    70,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,   167,   172,   168,   173,   155,     0,
     153,   152,     0,   116,   131,     0,   123,     0,   136,     0,
       0,     0,     5,     0,     0,   172,   171,     0,   185,     0,
      16,    13,     0,    21,     0,    15,    69,    39,    40,    41,
      43,    44,    46,    47,    51,    52,    49,    50,    54,    55,
      57,    59,    61,    63,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,   206,
       0,   204,     0,   205,   189,   190,     0,   202,   191,   192,
     193,   194,   195,   180,     0,     0,   176,     0,   174,     0,
       0,   164,   166,   151,   129,   132,    29,     0,    28,    82,
       0,    37,   186,   188,    14,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,   219,   220,     0,
       0,     0,   207,   201,   203,   181,   175,   177,   182,     0,
     178,     0,     0,    22,    67,   198,     0,     0,     0,     0,
       0,     0,     0,   217,   221,     0,   196,   183,   179,    19,
       0,     0,     0,   197,     0,     0,     0,     0,     0,    20,
     208,   210,   211,     0,     0,     0,     0,     0,   222,     0,
       0,   215,     0,   213,     0,   209,   212,   216,   214
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,  -223,  -223,   -59,  -223,   -84,    95,
     104,    67,    89,   192,   194,   191,   198,   190,  -223,   -62,
     -63,  -223,   -94,   -56,  -196,     0,  -223,   329,  -223,   193,
    -223,  -223,   319,   -53,   -61,  -223,   181,  -223,   339,   -42,
    -223,   117,  -223,   -21,   -40,   -18,   328,   -60,  -223,   189,
    -102,  -110,  -186,   -65,   100,   -54,  -223,   332,  -223,  -223,
     126,  -222,  -223,  -223,  -223,  -223,  -223,   368,  -223,  -223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   104,   105,   106,   107,   232,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     156,   179,   270,   134,    24,   127,    42,    43,    26,    27,
      28,    29,    73,    74,    75,   141,   142,    30,    57,    58,
      59,    31,    32,    60,    45,    46,    63,   284,   129,   130,
     159,   285,   207,   160,   161,   273,   274,   275,   201,   276,
     277,   278,   279,   280,   281,   282,    33,    34,    35,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   123,   157,   122,    44,   271,    70,   133,   128,   198,
     132,   137,    20,    21,    22,   144,    56,   206,   133,   288,
     139,   132,    62,  -227,   149,   180,    47,    48,   152,   153,
      64,    51,    52,    25,   122,   158,   155,   148,    56,   288,
      66,    55,   224,    85,   203,    83,    65,   199,   226,   220,
     132,    40,   221,   147,   143,    40,   219,   157,   188,   189,
     157,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   306,   234,   133,    56,   223,   132,    38,   133,   212,
     271,   132,    38,   139,   214,    38,    39,   190,   191,   218,
     158,    39,   342,   158,    39,    40,   215,   237,   238,   239,
      40,    36,   233,    40,   148,   255,   204,   140,    68,   205,
      69,   289,   216,   290,   178,    37,   236,    41,   341,   356,
     357,    71,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     225,   133,    38,   301,   132,    38,   224,   287,   203,    78,
      79,    39,   162,   163,   202,   133,   203,    61,   132,    81,
     299,   295,   164,    40,   303,    70,   122,    76,   132,   223,
     222,   223,   319,   165,    80,   166,   223,   167,   223,    66,
      82,    49,   145,   146,   205,   322,    61,   344,    76,    76,
      76,   124,   307,    76,   143,    50,   296,   133,   304,    38,
     132,   272,   223,   311,   305,   351,   225,   313,   202,   150,
     203,   223,   195,    76,   181,   336,   337,   352,   339,   182,
     183,   354,   194,   223,   358,   196,   345,   223,   133,   329,
     223,   132,   370,   372,   331,   374,   197,   122,   223,   223,
     208,   223,   333,    72,   200,   334,   184,   185,   132,   186,
     187,    85,    82,    76,   335,   244,   245,   246,   247,   192,
     193,   363,   365,   367,    72,    72,    72,   346,    76,    72,
     217,    76,   209,   228,   229,   210,   272,   349,   350,   240,
     241,   248,   249,    86,   353,   303,   227,   122,   230,    72,
     242,   243,   235,   293,    20,    21,    22,   360,   361,   297,
     362,   298,   308,   309,   310,   312,   314,    87,    88,   315,
     371,   316,   373,   320,   272,   375,   317,   321,   377,    89,
     378,    90,    91,    92,    93,    94,    95,   325,    96,    72,
     326,   131,   300,   327,   340,   338,    98,    99,   100,   101,
     102,   103,   343,   347,    72,   256,   257,    72,   258,   259,
     260,   261,   262,   263,   264,   265,   266,     1,     2,     3,
       4,     5,     6,     7,     8,     9,   267,    86,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   348,   355,   368,   369,   376,   250,   252,   254,   251,
     136,    87,    88,    84,    77,   253,   294,   135,   292,   125,
     332,    54,   324,   268,    23,    90,    91,    92,    93,    94,
      95,     0,    96,     0,     0,     0,     0,   124,   323,     0,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   256,   257,   269,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     1,     2,     3,     4,     5,
       6,     7,     8,     9,   267,    86,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,    23,    90,    91,    92,    93,    94,    95,     0,
      96,     0,     0,     0,     0,   124,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
      86,   256,   257,   269,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,    90,    91,
      92,    93,    94,    95,     0,    96,     0,    87,    88,     0,
      97,   302,     0,    98,    99,   100,   101,   102,   103,   268,
       0,    90,    91,    92,    93,    94,    95,     0,    96,     0,
       0,     0,     0,   124,     0,     0,    98,    99,   100,   101,
     102,   103,     1,     2,     3,     4,     5,     6,     7,     8,
       9,   269,    86,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    89,    23,
      90,    91,    92,    93,    94,    95,     0,    96,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,    87,    88,     0,     0,     0,     0,     0,     0,     0,
     269,     0,    86,    89,     0,    90,    91,    92,    93,    94,
      95,     0,    96,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,    87,    88,     0,     0,
       0,     0,     0,     0,     0,   318,     0,     0,    89,     0,
      90,    91,    92,    93,    94,    95,     0,    96,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     1,     2,     3,     4,     5,     6,     7,     8,     9,
     269,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    23,     0,
       0,     0,     0,     0,     0,     0,   202,   283,   203,     0,
       0,     0,     0,     0,     0,    40,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     7,     8,     9,     0,    86,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,    87,
      88,   224,   283,   203,     0,     0,     0,     0,     0,     0,
      40,    89,    23,    90,    91,    92,    93,    94,    95,    53,
      96,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    87,    88,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,    90,    91,    92,    93,
      94,    95,     0,    96,     0,     0,   211,    86,    87,    88,
       0,    98,    99,   100,   101,   102,   103,     0,     0,     0,
      89,     0,    90,    91,    92,    93,    94,    95,     0,    96,
      86,    87,    88,     0,    97,   359,     0,    98,    99,   100,
     101,   102,   103,    89,     0,    90,    91,    92,    93,    94,
      95,     0,    96,    86,    87,    88,     0,    97,     0,     0,
      98,    99,   100,   101,   102,   103,    89,     0,    90,    91,
      92,    93,    94,    95,     0,    96,   231,    87,    88,    86,
       0,     0,     0,    98,    99,   100,   101,   102,   103,    89,
       0,    90,    91,    92,    93,    94,    95,     0,    96,     0,
       0,   286,    86,    87,    88,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,    89,     0,    90,    91,    92,
      93,    94,    95,     0,    96,     0,    87,    88,    86,   300,
       0,     0,    98,    99,   100,   101,   102,   103,    89,     0,
      90,    91,    92,    93,    94,    95,     0,    96,     0,     0,
     330,    86,    87,    88,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,    89,     0,    90,    91,    92,    93,
      94,    95,     0,    96,   364,    87,    88,    86,     0,     0,
       0,    98,    99,   100,   101,   102,   103,    89,     0,    90,
      91,    92,    93,    94,    95,     0,    96,   366,     0,     0,
      86,    87,    88,     0,    98,    99,   100,   101,   102,   103,
       0,     0,     0,    89,     0,    90,    91,    92,    93,    94,
      95,     0,    96,    86,    87,    88,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,    89,     0,    90,    91,
      92,    93,    94,    95,     0,   151,     0,    87,    88,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,    89,
       0,    90,    91,    92,    93,    94,    95,     0,   154,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     7,     8,
       9,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    23,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   138,     7,     8,     9,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,   213,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,    23,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     7,     8,     9,     0,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       0,    66,    96,    66,    25,   201,    46,    69,    68,    52,
      69,    72,    36,    37,    38,    76,    61,   127,    80,   205,
      73,    80,    40,    75,    80,   109,    26,    27,    87,    88,
      77,    31,    32,    33,    97,    96,    95,    79,    61,   225,
      92,    75,    70,    64,    72,    63,    93,    90,   158,   151,
     109,    79,   154,    76,    75,    79,   150,   151,    57,    58,
     154,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    73,   166,   135,    61,    77,   135,    61,   140,   135,
     276,   140,    61,   136,   140,    61,    70,    86,    87,    76,
     151,    70,   314,   154,    70,    79,    77,   181,   182,   183,
      79,    61,   165,    79,   146,   199,   127,    91,    70,   127,
      72,    70,    93,    72,    92,    75,   179,    93,   314,   341,
     342,    75,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     158,   203,    61,   227,   203,    61,    70,   203,    72,    76,
      77,    70,    49,    50,    70,   217,    72,    40,   217,    71,
     223,   217,    59,    79,   229,   205,   229,    50,   227,    77,
      71,    77,   266,    70,    92,    72,    77,    74,    77,    92,
      63,    61,    76,    77,   202,    93,    69,    93,    71,    72,
      73,    75,    91,    76,   215,    75,    71,   259,    71,    61,
     259,   201,    77,   259,    77,    71,   224,   261,    70,    70,
      72,    77,    88,    96,    79,   309,   310,    71,   312,    84,
      85,    71,    78,    77,    71,    89,   320,    77,   290,   289,
      77,   290,    71,    71,   290,    71,    51,   300,    77,    77,
      71,    77,   305,    50,    76,   307,    80,    81,   307,    53,
      54,   272,   135,   136,   308,   188,   189,   190,   191,    55,
      56,   355,   356,   357,    71,    72,    73,   321,   151,    76,
      91,   154,    77,    76,    77,    73,   276,    76,    77,   184,
     185,   192,   193,    25,   338,   350,    71,   350,    61,    96,
     186,   187,    61,    73,    36,    37,    38,   351,   352,    71,
     354,    71,    91,    70,    70,    70,    70,    49,    50,    61,
     364,    93,   366,    70,   314,   369,    93,    91,   372,    61,
     374,    63,    64,    65,    66,    67,    68,    71,    70,   136,
      71,    73,    75,    73,     8,    91,    78,    79,    80,    81,
      82,    83,    93,    71,   151,     3,     4,   154,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    73,    70,    93,     5,    93,   194,   196,   198,   195,
      71,    49,    50,    64,    55,   197,   215,    69,   209,    67,
     300,    33,   276,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    93,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      25,     3,     4,    93,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    49,    50,    -1,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    93,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    25,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      93,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    49,
      50,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    49,    50,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    -1,    73,    25,    49,    50,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    66,    67,    68,    -1,    70,
      25,    49,    50,    -1,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    25,    49,    50,    -1,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    49,    50,    25,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    73,    25,    49,    50,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    49,    50,    25,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    61,    -1,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      73,    25,    49,    50,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    49,    50,    25,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    61,    -1,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    -1,    -1,
      25,    49,    50,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    -1,    70,    25,    49,    50,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    61,    -1,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    49,    50,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    61,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    62,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    76,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    76,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    62,   118,   119,   122,   123,   124,   125,
     131,   135,   136,   160,   161,   162,    61,    75,    61,    70,
      79,    93,   120,   121,   137,   138,   139,   119,   119,    61,
      75,   119,   119,     0,   161,    75,    61,   132,   133,   134,
     137,   135,   139,   140,    77,    93,    92,   163,    70,    72,
     138,    75,   123,   126,   127,   128,   135,   132,    76,    77,
      92,    71,   135,   139,   121,   137,    25,    49,    50,    61,
      63,    64,    65,    66,    67,    68,    70,    75,    78,    79,
      80,    81,    82,    83,    95,    96,    97,    98,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   147,    75,   151,    71,   119,   141,   142,
     143,    73,   100,   113,   117,   140,   126,   128,    76,   127,
      91,   129,   130,   137,   128,    76,    77,    76,   133,   117,
      70,    70,   100,   100,    70,   100,   114,   116,   128,   144,
     147,   148,    49,    50,    59,    70,    72,    74,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    92,   115,
     102,    79,    84,    85,    80,    81,    53,    54,    57,    58,
      86,    87,    55,    56,    78,    88,    89,    51,    52,    90,
      76,   152,    70,    72,   137,   139,   145,   146,    71,    77,
      73,    73,   117,    76,   117,    77,    93,    91,    76,   116,
     144,   144,    71,    77,    70,   139,   145,    71,    76,    77,
      61,    71,    99,   114,   116,    61,   114,   102,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     107,   108,   109,   110,   111,   116,     3,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    24,    61,    93,
     116,   118,   119,   149,   150,   151,   153,   154,   155,   156,
     157,   158,   159,    71,   141,   145,    73,   117,   146,    70,
      72,    60,   143,    73,   130,   117,    71,    71,    71,   114,
      75,   102,    76,   147,    71,    77,    73,    91,    91,    70,
      70,   117,    70,   149,    70,    61,    93,    93,    93,   116,
      70,    91,    93,    76,   154,    71,    71,    73,    71,   141,
      73,   117,   148,   114,   113,   149,   116,   116,    91,   116,
       8,   118,   155,    93,    93,   116,   149,    71,    73,    76,
      77,    71,    71,   149,    71,    70,   155,   155,    71,    76,
     149,   149,   149,   116,    71,   116,    71,   116,    93,     5,
      71,   149,    71,   149,    71,   149,    93,   149,   149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   104,   104,   104,   105,   105,   105,   106,   106,
     106,   106,   106,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   124,   125,
     125,   126,   126,   127,   128,   128,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   132,   132,
     133,   133,   134,   135,   135,   135,   136,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   143,
     144,   144,   145,   145,   145,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   150,   150,   150,   151,
     152,   151,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   157,   157,   157,   157,   157,   157,   158,   158,   158,
     158,   158,   159,   160,   160,   161,   161,   163,   162
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     6,
       7,     1,     3,     1,     2,     2,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     5,     6,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     5,     4,     4,     3,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       0,     4,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     6,     7,     3,     2,     2,
       2,     3,     5,     1,     2,     1,     1,     0,     4
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
#line 151 "bison/parser.yacc"
                                { (yyval.expr) = make_id_expr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1750 "parser.c"
    break;

  case 3: /* primary_expression: constant  */
#line 152 "bison/parser.yacc"
                                { (yyval.expr) = make_const_expr((yyvsp[0].constant)); }
#line 1756 "parser.c"
    break;

  case 4: /* primary_expression: string  */
#line 153 "bison/parser.yacc"
                                { (yyval.expr) = make_string_expr((yyvsp[0].sval)); }
#line 1762 "parser.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 154 "bison/parser.yacc"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1768 "parser.c"
    break;

  case 6: /* constant: CONST_INT  */
#line 158 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_INT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1774 "parser.c"
    break;

  case 7: /* constant: CONST_FLOAT  */
#line 159 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_FLOAT, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1780 "parser.c"
    break;

  case 8: /* constant: ENUM_CONST  */
#line 160 "bison/parser.yacc"
                    { (yyval.constant) = make_constant(CONSTANT_ENUM, (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1786 "parser.c"
    break;

  case 9: /* string: STR_LITERAL  */
#line 163 "bison/parser.yacc"
                    { (yyval.sval) = (yyvsp[0].sval); free((yyvsp[0].sval)); }
#line 1792 "parser.c"
    break;

  case 10: /* string: FUNC_NAME  */
#line 164 "bison/parser.yacc"
                    { (yyval.sval) = func_name(); }
#line 1798 "parser.c"
    break;

  case 11: /* postfix_expression: primary_expression  */
#line 167 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1804 "parser.c"
    break;

  case 12: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 168 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_SUBSCRIPT, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1810 "parser.c"
    break;

  case 13: /* postfix_expression: postfix_expression '(' ')'  */
#line 169 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-2].expr), 0); }
#line 1816 "parser.c"
    break;

  case 14: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 170 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_CALL, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1822 "parser.c"
    break;

  case 15: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 171 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_DOT, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1828 "parser.c"
    break;

  case 16: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 172 "bison/parser.yacc"
                                                                { (yyval.expr) = make_member_access_expr(EXPR_MEMBER_ARROW, (yyvsp[-2].expr), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1834 "parser.c"
    break;

  case 17: /* postfix_expression: postfix_expression INCREMENT  */
#line 173 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_INCR, (yyvsp[-1].expr), 0); }
#line 1840 "parser.c"
    break;

  case 18: /* postfix_expression: postfix_expression DECREMENT  */
#line 174 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_POST_DECR, (yyvsp[-1].expr), 0); }
#line 1846 "parser.c"
    break;

  case 19: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 175 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-4].type_name), (yyvsp[-1].init_list)); }
#line 1852 "parser.c"
    break;

  case 20: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 176 "bison/parser.yacc"
                                                                { (yyval.expr) = make_init_expr((yyvsp[-5].type_name), (yyvsp[-2].init_list)); }
#line 1858 "parser.c"
    break;

  case 21: /* argument_expression_list: assignment_expression  */
#line 180 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), 0); }
#line 1864 "parser.c"
    break;

  case 22: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 181 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_ARG, (yyvsp[0].expr), (yyvsp[-2].expr)); }
#line 1870 "parser.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 185 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1876 "parser.c"
    break;

  case 24: /* unary_expression: INCREMENT unary_expression  */
#line 186 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_INCR, (yyvsp[0].expr), 0); }
#line 1882 "parser.c"
    break;

  case 25: /* unary_expression: DECREMENT unary_expression  */
#line 187 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_PRE_DECR, (yyvsp[0].expr), 0); }
#line 1888 "parser.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 188 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[0].expr), 0); }
#line 1894 "parser.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 189 "bison/parser.yacc"
                                            { (yyval.expr) = make_expr(EXPR_SIZEOF_EXPR, (yyvsp[0].expr), 0); }
#line 1900 "parser.c"
    break;

  case 28: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 190 "bison/parser.yacc"
                                            { (yyval.expr) = make_sizeof_expr((yyvsp[-1].type_name)); }
#line 1906 "parser.c"
    break;

  case 29: /* unary_expression: MALLOC '(' expression ')'  */
#line 191 "bison/parser.yacc"
                                        { (yyval.expr) = make_expr(EXPR_MALLOC, (yyvsp[-1].expr), 0); }
#line 1912 "parser.c"
    break;

  case 30: /* unary_operator: '&'  */
#line 195 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_ADDREF; }
#line 1918 "parser.c"
    break;

  case 31: /* unary_operator: '*'  */
#line 196 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_DEREF; }
#line 1924 "parser.c"
    break;

  case 32: /* unary_operator: '+'  */
#line 197 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_PLUS; }
#line 1930 "parser.c"
    break;

  case 33: /* unary_operator: '-'  */
#line 198 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_MINUS; }
#line 1936 "parser.c"
    break;

  case 34: /* unary_operator: '~'  */
#line 199 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_BITNOT; }
#line 1942 "parser.c"
    break;

  case 35: /* unary_operator: '!'  */
#line 200 "bison/parser.yacc"
                { (yyval.int_val) = EXPR_LOGNOT; }
#line 1948 "parser.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 204 "bison/parser.yacc"
                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1954 "parser.c"
    break;

  case 37: /* cast_expression: '(' type_name ')' cast_expression  */
#line 205 "bison/parser.yacc"
                                            { (yyval.expr) = make_cast_expr((yyvsp[-2].type_name), (yyvsp[0].expr)); }
#line 1960 "parser.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 209 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1966 "parser.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 210 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1972 "parser.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 211 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1978 "parser.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 212 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1984 "parser.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 216 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 1990 "parser.c"
    break;

  case 43: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 217 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1996 "parser.c"
    break;

  case 44: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 218 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2002 "parser.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 222 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2008 "parser.c"
    break;

  case 46: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 223 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2014 "parser.c"
    break;

  case 47: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 224 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_RSHIFT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2020 "parser.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 228 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2026 "parser.c"
    break;

  case 49: /* relational_expression: relational_expression '<' shift_expression  */
#line 229 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2032 "parser.c"
    break;

  case 50: /* relational_expression: relational_expression '>' shift_expression  */
#line 230 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2038 "parser.c"
    break;

  case 51: /* relational_expression: relational_expression LEQ shift_expression  */
#line 231 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_LEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2044 "parser.c"
    break;

  case 52: /* relational_expression: relational_expression GEQ shift_expression  */
#line 232 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_GEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2050 "parser.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 236 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2056 "parser.c"
    break;

  case 54: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 237 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2062 "parser.c"
    break;

  case 55: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 238 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2068 "parser.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 242 "bison/parser.yacc"
                                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2074 "parser.c"
    break;

  case 57: /* and_expression: and_expression '&' equality_expression  */
#line 243 "bison/parser.yacc"
                                                    { (yyval.expr) = make_expr(EXPR_BITAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2080 "parser.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 247 "bison/parser.yacc"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2086 "parser.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 248 "bison/parser.yacc"
                                                        { (yyval.expr) = make_expr(EXPR_BITXOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2092 "parser.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 252 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2098 "parser.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 253 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_BITOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2104 "parser.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 257 "bison/parser.yacc"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2110 "parser.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 258 "bison/parser.yacc"
                                                                { (yyval.expr) = make_expr(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2116 "parser.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 262 "bison/parser.yacc"
                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2122 "parser.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 263 "bison/parser.yacc"
                                                            { (yyval.expr) = make_expr(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2128 "parser.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 267 "bison/parser.yacc"
                                                                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2134 "parser.c"
    break;

  case 67: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 268 "bison/parser.yacc"
                                                                            { (yyval.expr) = make_ternary_expr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2140 "parser.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 272 "bison/parser.yacc"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2146 "parser.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 273 "bison/parser.yacc"
                                                                        { (yyval.expr) = make_expr((yyvsp[-1].int_val), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2152 "parser.c"
    break;

  case 70: /* assignment_operator: '='  */
#line 277 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ASSIGN; }
#line 2158 "parser.c"
    break;

  case 71: /* assignment_operator: MUL_ASSIGN  */
#line 278 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MUL_ASSIGN; }
#line 2164 "parser.c"
    break;

  case 72: /* assignment_operator: DIV_ASSIGN  */
#line 279 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_DIV_ASSIGN; }
#line 2170 "parser.c"
    break;

  case 73: /* assignment_operator: MOD_ASSIGN  */
#line 280 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_MOD_ASSIGN; }
#line 2176 "parser.c"
    break;

  case 74: /* assignment_operator: ADD_ASSIGN  */
#line 281 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_ADD_ASSIGN; }
#line 2182 "parser.c"
    break;

  case 75: /* assignment_operator: SUB_ASSIGN  */
#line 282 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_SUB_ASSIGN; }
#line 2188 "parser.c"
    break;

  case 76: /* assignment_operator: LSHIFT_ASSIGN  */
#line 283 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_LSHIFT_ASSIGN; }
#line 2194 "parser.c"
    break;

  case 77: /* assignment_operator: RSHIFT_ASSIGN  */
#line 284 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_RSHIFT_ASSIGN; }
#line 2200 "parser.c"
    break;

  case 78: /* assignment_operator: AND_ASSIGN  */
#line 285 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_AND_ASSIGN; }
#line 2206 "parser.c"
    break;

  case 79: /* assignment_operator: XOR_ASSIGN  */
#line 286 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_XOR_ASSIGN; }
#line 2212 "parser.c"
    break;

  case 80: /* assignment_operator: OR_ASSIGN  */
#line 287 "bison/parser.yacc"
                        { (yyval.int_val) = EXPR_OR_ASSIGN; }
#line 2218 "parser.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 291 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2224 "parser.c"
    break;

  case 82: /* expression: expression ',' assignment_expression  */
#line 292 "bison/parser.yacc"
                                                { (yyval.expr) = make_expr(EXPR_COMMA, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2230 "parser.c"
    break;

  case 83: /* constant_expression: conditional_expression  */
#line 296 "bison/parser.yacc"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2236 "parser.c"
    break;

  case 84: /* declaration: declaration_specifiers ';'  */
#line 300 "bison/parser.yacc"
                                                            { (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), 0); }
#line 2242 "parser.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 302 "bison/parser.yacc"
    {
        (yyval.decl) = make_normal_decl(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].init_decltr));
        add_typedef_type((yyval.decl));
    }
#line 2251 "parser.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier  */
#line 309 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class(0, (yyvsp[0].int_val)); }
#line 2257 "parser.c"
    break;

  case 87: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 310 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_storage_class((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2263 "parser.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 311 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2269 "parser.c"
    break;

  case 89: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 312 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2275 "parser.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier  */
#line 313 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2281 "parser.c"
    break;

  case 91: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 314 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2287 "parser.c"
    break;

  case 92: /* declaration_specifiers: function_specifier  */
#line 315 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec(0, (yyvsp[0].int_val)); }
#line 2293 "parser.c"
    break;

  case 93: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 316 "bison/parser.yacc"
                                                            { (yyval.decl_spec_list) = add_func_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2299 "parser.c"
    break;

  case 94: /* init_declarator_list: init_declarator  */
#line 320 "bison/parser.yacc"
                                                    { (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2305 "parser.c"
    break;

  case 95: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 321 "bison/parser.yacc"
                                                    { add_init_decltr((yyvsp[-2].init_decltr), (yyvsp[0].init_decltr)); (yyval.init_decltr) = (yyvsp[0].init_decltr); }
#line 2311 "parser.c"
    break;

  case 96: /* init_declarator: declarator  */
#line 325 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[0].decltr), 0); }
#line 2317 "parser.c"
    break;

  case 97: /* init_declarator: declarator '=' initializer  */
#line 326 "bison/parser.yacc"
                                        { (yyval.init_decltr) = make_init_decltr((yyvsp[-2].decltr), (yyvsp[0].initializer)); }
#line 2323 "parser.c"
    break;

  case 98: /* storage_class_specifier: TYPEDEF  */
#line 330 "bison/parser.yacc"
                    { (yyval.int_val) = SC_TYPEDEF; }
#line 2329 "parser.c"
    break;

  case 99: /* storage_class_specifier: EXTERN  */
#line 331 "bison/parser.yacc"
                    { (yyval.int_val) = SC_EXTERN; }
#line 2335 "parser.c"
    break;

  case 100: /* storage_class_specifier: STATIC  */
#line 332 "bison/parser.yacc"
                    { (yyval.int_val) = SC_STATIC; }
#line 2341 "parser.c"
    break;

  case 101: /* storage_class_specifier: AUTO  */
#line 333 "bison/parser.yacc"
                    { (yyval.int_val) = SC_AUTO; }
#line 2347 "parser.c"
    break;

  case 102: /* storage_class_specifier: REGISTER  */
#line 334 "bison/parser.yacc"
                    { (yyval.int_val) = SC_REGISTER; }
#line 2353 "parser.c"
    break;

  case 103: /* type_specifier: VOID  */
#line 338 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_VOID); }
#line 2359 "parser.c"
    break;

  case 104: /* type_specifier: CHAR  */
#line 339 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_CHAR); }
#line 2365 "parser.c"
    break;

  case 105: /* type_specifier: SHORT  */
#line 340 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SHORT); }
#line 2371 "parser.c"
    break;

  case 106: /* type_specifier: INT  */
#line 341 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_INT); }
#line 2377 "parser.c"
    break;

  case 107: /* type_specifier: LONG  */
#line 342 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_LONG); }
#line 2383 "parser.c"
    break;

  case 108: /* type_specifier: FLOAT  */
#line 343 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_FLOAT); }
#line 2389 "parser.c"
    break;

  case 109: /* type_specifier: DOUBLE  */
#line 344 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_DOUBLE); }
#line 2395 "parser.c"
    break;

  case 110: /* type_specifier: SIGNED  */
#line 345 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_SIGNED); }
#line 2401 "parser.c"
    break;

  case 111: /* type_specifier: UNSIGNED  */
#line 346 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_UNSIGNED); }
#line 2407 "parser.c"
    break;

  case 112: /* type_specifier: BOOL  */
#line 347 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_basic_type_spec(TS_BOOL); }
#line 2413 "parser.c"
    break;

  case 113: /* type_specifier: struct_or_union_specifier  */
#line 348 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_sou_type_spec((yyvsp[0].sou_spec)); }
#line 2419 "parser.c"
    break;

  case 114: /* type_specifier: enum_specifier  */
#line 349 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_enum_type_spec((yyvsp[0].enum_spec)); }
#line 2425 "parser.c"
    break;

  case 115: /* type_specifier: TYPEDEF_NAME  */
#line 350 "bison/parser.yacc"
                                    { (yyval.type_spec) = make_typedef_type_spec((yyvsp[0].sval)); }
#line 2431 "parser.c"
    break;

  case 116: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 354 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-4].int_val), (yyvsp[-3].sval), (yyvsp[-1].struct_decl_list)); }
#line 2437 "parser.c"
    break;

  case 117: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 355 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-3].int_val), 0, (yyvsp[-1].struct_decl_list)); }
#line 2443 "parser.c"
    break;

  case 118: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 356 "bison/parser.yacc"
                                                                        { (yyval.sou_spec) = make_sou_spec((yyvsp[-1].int_val), (yyvsp[0].sval), 0); }
#line 2449 "parser.c"
    break;

  case 119: /* struct_or_union: STRUCT  */
#line 360 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_STRUCT; }
#line 2455 "parser.c"
    break;

  case 120: /* struct_or_union: UNION  */
#line 361 "bison/parser.yacc"
                    { (yyval.int_val) = SOU_UNION; }
#line 2461 "parser.c"
    break;

  case 121: /* struct_declaration_list: struct_declaration  */
#line 365 "bison/parser.yacc"
                                                        { (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2467 "parser.c"
    break;

  case 122: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 366 "bison/parser.yacc"
                                                        { add_struct_decl((yyvsp[-1].struct_decl_list), (yyvsp[0].struct_decl_list)); (yyval.struct_decl_list) = (yyvsp[0].struct_decl_list); }
#line 2473 "parser.c"
    break;

  case 123: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 370 "bison/parser.yacc"
                                                                { (yyval.struct_decl_list) = make_struct_decl_list(make_decl_specs((yyvsp[-2].decl_spec_list)), (yyvsp[-1].struct_decltr_list)); }
#line 2479 "parser.c"
    break;

  case 124: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 374 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec((yyvsp[0].decl_spec_list), (yyvsp[-1].type_spec)); }
#line 2485 "parser.c"
    break;

  case 125: /* specifier_qualifier_list: type_specifier  */
#line 375 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_spec(0, (yyvsp[0].type_spec)); }
#line 2491 "parser.c"
    break;

  case 126: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 376 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual((yyvsp[0].decl_spec_list), (yyvsp[-1].int_val)); }
#line 2497 "parser.c"
    break;

  case 127: /* specifier_qualifier_list: type_qualifier  */
#line 377 "bison/parser.yacc"
                                                    { (yyval.decl_spec_list) = add_type_qual(0, (yyvsp[0].int_val)); }
#line 2503 "parser.c"
    break;

  case 128: /* struct_declarator_list: struct_declarator  */
#line 381 "bison/parser.yacc"
                                                        { (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2509 "parser.c"
    break;

  case 129: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 382 "bison/parser.yacc"
                                                        { add_struct_decltr((yyvsp[-2].struct_decltr_list), (yyvsp[0].struct_decltr_list)); (yyval.struct_decltr_list) = (yyvsp[0].struct_decltr_list); }
#line 2515 "parser.c"
    break;

  case 130: /* struct_declarator: declarator  */
#line 386 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[0].decltr), 0); }
#line 2521 "parser.c"
    break;

  case 131: /* struct_declarator: ':' constant_expression  */
#line 387 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list(0, (yyvsp[0].expr)); }
#line 2527 "parser.c"
    break;

  case 132: /* struct_declarator: declarator ':' constant_expression  */
#line 388 "bison/parser.yacc"
                                                { (yyval.struct_decltr_list) = make_struct_decltr_list((yyvsp[-2].decltr), (yyvsp[0].expr)); }
#line 2533 "parser.c"
    break;

  case 133: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 392 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-1].enumerator_list)); }
#line 2539 "parser.c"
    break;

  case 134: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 393 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-3].sval), (yyvsp[-1].enumerator_list)); }
#line 2545 "parser.c"
    break;

  case 135: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 394 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec(0, (yyvsp[-2].enumerator_list)); }
#line 2551 "parser.c"
    break;

  case 136: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 395 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[-4].sval), (yyvsp[-2].enumerator_list)); }
#line 2557 "parser.c"
    break;

  case 137: /* enum_specifier: ENUM IDENTIFIER  */
#line 396 "bison/parser.yacc"
                                                        { (yyval.enum_spec) = make_enum_spec((yyvsp[0].sval), 0); }
#line 2563 "parser.c"
    break;

  case 138: /* enumerator_list: enumerator  */
#line 400 "bison/parser.yacc"
                                            { (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2569 "parser.c"
    break;

  case 139: /* enumerator_list: enumerator_list ',' enumerator  */
#line 401 "bison/parser.yacc"
                                            { add_enumerator((yyvsp[-2].enumerator_list), (yyvsp[0].enumerator_list)); (yyval.enumerator_list) = (yyvsp[0].enumerator_list); }
#line 2575 "parser.c"
    break;

  case 140: /* enumerator: enumeration_constant  */
#line 405 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[0].sval), 0); free((yyvsp[0].sval)); }
#line 2581 "parser.c"
    break;

  case 141: /* enumerator: enumeration_constant '=' constant_expression  */
#line 406 "bison/parser.yacc"
                                                        { (yyval.enumerator_list) = make_enum_list((yyvsp[-2].sval), (yyvsp[0].expr)); free((yyvsp[-2].sval)); }
#line 2587 "parser.c"
    break;

  case 142: /* enumeration_constant: IDENTIFIER  */
#line 410 "bison/parser.yacc"
                    { sym_define_enum((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); }
#line 2593 "parser.c"
    break;

  case 143: /* type_qualifier: CONST  */
#line 413 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_CONST; }
#line 2599 "parser.c"
    break;

  case 144: /* type_qualifier: RESTRICT  */
#line 414 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_RESTRICT; }
#line 2605 "parser.c"
    break;

  case 145: /* type_qualifier: VOLATILE  */
#line 415 "bison/parser.yacc"
                    { (yyval.int_val) = TQ_VOLATILE; }
#line 2611 "parser.c"
    break;

  case 146: /* function_specifier: INLINE  */
#line 419 "bison/parser.yacc"
                    { (yyval.int_val) = FS_INLINE; }
#line 2617 "parser.c"
    break;

  case 147: /* declarator: pointer direct_declarator  */
#line 425 "bison/parser.yacc"
                                    { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); (yyval.decltr) = (yyvsp[0].decltr); }
#line 2623 "parser.c"
    break;

  case 148: /* declarator: direct_declarator  */
#line 426 "bison/parser.yacc"
                                    { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2629 "parser.c"
    break;

  case 149: /* direct_declarator: IDENTIFIER  */
#line 431 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_id_decltr((yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2635 "parser.c"
    break;

  case 150: /* direct_declarator: '(' declarator ')'  */
#line 432 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2641 "parser.c"
    break;

  case 151: /* direct_declarator: direct_declarator '[' type_qualifier_list constant_expression ']'  */
#line 433 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-4].decltr), (yyvsp[-2].type_qual_list), (yyvsp[-1].expr)); }
#line 2647 "parser.c"
    break;

  case 152: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 434 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), (yyvsp[-1].type_qual_list), 0); }
#line 2653 "parser.c"
    break;

  case 153: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 435 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2659 "parser.c"
    break;

  case 154: /* direct_declarator: direct_declarator '[' ']'  */
#line 436 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2665 "parser.c"
    break;

  case 155: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 437 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2671 "parser.c"
    break;

  case 156: /* direct_declarator: direct_declarator '(' ')'  */
#line 438 "bison/parser.yacc"
                                                                                        { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2677 "parser.c"
    break;

  case 157: /* pointer: '*'  */
#line 442 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, 0); }
#line 2683 "parser.c"
    break;

  case 158: /* pointer: '*' type_qualifier_list  */
#line 443 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[0].type_qual_list), 0); }
#line 2689 "parser.c"
    break;

  case 159: /* pointer: '*' pointer  */
#line 444 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer(0, (yyvsp[0].pointer)); }
#line 2695 "parser.c"
    break;

  case 160: /* pointer: '*' type_qualifier_list pointer  */
#line 445 "bison/parser.yacc"
                                            { (yyval.pointer) = make_pointer((yyvsp[-1].type_qual_list), (yyvsp[0].pointer)); }
#line 2701 "parser.c"
    break;

  case 161: /* type_qualifier_list: type_qualifier  */
#line 449 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list(0, (yyvsp[0].int_val)); }
#line 2707 "parser.c"
    break;

  case 162: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 450 "bison/parser.yacc"
                                                { (yyval.type_qual_list) = make_type_qual_list((yyvsp[-1].type_qual_list), (yyvsp[0].int_val)); }
#line 2713 "parser.c"
    break;

  case 163: /* parameter_type_list: parameter_list  */
#line 455 "bison/parser.yacc"
                                        { set_param_ellipsis(0); (yyval.param_list) = (yyvsp[0].param_list); }
#line 2719 "parser.c"
    break;

  case 164: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 456 "bison/parser.yacc"
                                        { set_param_ellipsis(1); (yyval.param_list) = (yyvsp[-2].param_list); }
#line 2725 "parser.c"
    break;

  case 165: /* parameter_list: parameter_declaration  */
#line 460 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list(0, (yyvsp[0].decl)); }
#line 2731 "parser.c"
    break;

  case 166: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 461 "bison/parser.yacc"
                                                    { (yyval.param_list) = make_param_list((yyvsp[-2].param_list), (yyvsp[0].decl)); }
#line 2737 "parser.c"
    break;

  case 167: /* parameter_declaration: declaration_specifiers declarator  */
#line 465 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 0); }
#line 2743 "parser.c"
    break;

  case 168: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 466 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr), 1); }
#line 2749 "parser.c"
    break;

  case 169: /* parameter_declaration: declaration_specifiers  */
#line 467 "bison/parser.yacc"
                                                        { (yyval.decl) = make_param_decl(make_decl_specs((yyvsp[0].decl_spec_list)), 0, 0); }
#line 2755 "parser.c"
    break;

  case 170: /* type_name: specifier_qualifier_list  */
#line 471 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[0].decl_spec_list)), 0); }
#line 2761 "parser.c"
    break;

  case 171: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 472 "bison/parser.yacc"
                                                        { (yyval.type_name) = make_type_name(make_decl_specs((yyvsp[-1].decl_spec_list)), (yyvsp[0].decltr)); }
#line 2767 "parser.c"
    break;

  case 172: /* abstract_declarator: pointer  */
#line 476 "bison/parser.yacc"
                                                { (yyval.decltr) = make_empty_decltr((yyvsp[0].pointer)); }
#line 2773 "parser.c"
    break;

  case 173: /* abstract_declarator: direct_abstract_declarator  */
#line 477 "bison/parser.yacc"
                                                { (yyval.decltr) = (yyvsp[0].decltr); }
#line 2779 "parser.c"
    break;

  case 174: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 478 "bison/parser.yacc"
                                                { add_pointer((yyvsp[-1].pointer), (yyvsp[0].decltr)); }
#line 2785 "parser.c"
    break;

  case 175: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 482 "bison/parser.yacc"
                                                                    { (yyval.decltr) = (yyvsp[-1].decltr); }
#line 2791 "parser.c"
    break;

  case 176: /* direct_abstract_declarator: '[' ']'  */
#line 483 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, 0); }
#line 2797 "parser.c"
    break;

  case 177: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 484 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix(0, 0, (yyvsp[-1].expr)); }
#line 2803 "parser.c"
    break;

  case 178: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 485 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-2].decltr), 0, 0); }
#line 2809 "parser.c"
    break;

  case 179: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 486 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_array_suffix((yyvsp[-3].decltr), 0, (yyvsp[-1].expr)); }
#line 2815 "parser.c"
    break;

  case 180: /* direct_abstract_declarator: '(' ')'  */
#line 487 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, 0); }
#line 2821 "parser.c"
    break;

  case 181: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 488 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix(0, (yyvsp[-1].param_list)); }
#line 2827 "parser.c"
    break;

  case 182: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 489 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-2].decltr), 0); }
#line 2833 "parser.c"
    break;

  case 183: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 490 "bison/parser.yacc"
                                                                    { (yyval.decltr) = make_decltr_proto_suffix((yyvsp[-3].decltr), (yyvsp[-1].param_list)); }
#line 2839 "parser.c"
    break;

  case 184: /* initializer: assignment_expression  */
#line 494 "bison/parser.yacc"
                                        { (yyval.initializer) = make_expr_init((yyvsp[0].expr)); }
#line 2845 "parser.c"
    break;

  case 185: /* initializer: '{' initializer_list '}'  */
#line 495 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-1].init_list)); }
#line 2851 "parser.c"
    break;

  case 186: /* initializer: '{' initializer_list ',' '}'  */
#line 496 "bison/parser.yacc"
                                        { (yyval.initializer) = make_list_init((yyvsp[-2].init_list)); }
#line 2857 "parser.c"
    break;

  case 187: /* initializer_list: initializer  */
#line 500 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list(0, (yyvsp[0].initializer)); }
#line 2863 "parser.c"
    break;

  case 188: /* initializer_list: initializer_list ',' initializer  */
#line 501 "bison/parser.yacc"
                                                        { (yyval.init_list) = make_init_list((yyvsp[-2].init_list), (yyvsp[0].initializer)); }
#line 2869 "parser.c"
    break;

  case 189: /* statement: labeled_statement  */
#line 505 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2875 "parser.c"
    break;

  case 190: /* statement: compound_statement  */
#line 506 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2881 "parser.c"
    break;

  case 191: /* statement: expression_statement  */
#line 507 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2887 "parser.c"
    break;

  case 192: /* statement: selection_statement  */
#line 508 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2893 "parser.c"
    break;

  case 193: /* statement: iteration_statement  */
#line 509 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2899 "parser.c"
    break;

  case 194: /* statement: jump_statement  */
#line 510 "bison/parser.yacc"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2905 "parser.c"
    break;

  case 195: /* statement: print_statement  */
#line 511 "bison/parser.yacc"
                            { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2911 "parser.c"
    break;

  case 196: /* labeled_statement: IDENTIFIER ':' statement  */
#line 515 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_labeled_stmt((yyvsp[-2].sval), (yyvsp[0].stmt)); }
#line 2917 "parser.c"
    break;

  case 197: /* labeled_statement: CASE constant_expression ':' statement  */
#line 516 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_case_stmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2923 "parser.c"
    break;

  case 198: /* labeled_statement: DEFAULT ':' statement  */
#line 517 "bison/parser.yacc"
                                                    { (yyval.stmt) = make_default_stmt((yyvsp[0].stmt)); }
#line 2929 "parser.c"
    break;

  case 199: /* compound_statement: '{' '}'  */
#line 521 "bison/parser.yacc"
                            { (yyval.stmt) = make_compound_stmt(0); }
#line 2935 "parser.c"
    break;

  case 200: /* $@1: %empty  */
#line 522 "bison/parser.yacc"
                            { sym_push_scope(); }
#line 2941 "parser.c"
    break;

  case 201: /* compound_statement: '{' $@1 block_item_list '}'  */
#line 524 "bison/parser.yacc"
                        { sym_pop_scope(); (yyval.stmt) = make_compound_stmt((yyvsp[-1].block_list)); }
#line 2947 "parser.c"
    break;

  case 202: /* block_item_list: block_item  */
#line 528 "bison/parser.yacc"
                                        { (yyval.block_list) = (yyvsp[0].block_list); }
#line 2953 "parser.c"
    break;

  case 203: /* block_item_list: block_item_list block_item  */
#line 529 "bison/parser.yacc"
                                        { add_block_item((yyvsp[-1].block_list), (yyvsp[0].block_list)); (yyval.block_list) = (yyvsp[0].block_list); }
#line 2959 "parser.c"
    break;

  case 204: /* block_item: declaration  */
#line 533 "bison/parser.yacc"
                        { (yyval.block_list) = make_decl_block_item((yyvsp[0].decl)); }
#line 2965 "parser.c"
    break;

  case 205: /* block_item: statement  */
#line 534 "bison/parser.yacc"
                        { (yyval.block_list) = make_stmt_block_item((yyvsp[0].stmt)); }
#line 2971 "parser.c"
    break;

  case 206: /* expression_statement: ';'  */
#line 538 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt(0); }
#line 2977 "parser.c"
    break;

  case 207: /* expression_statement: expression ';'  */
#line 539 "bison/parser.yacc"
                            { (yyval.stmt) = make_expr_stmt((yyvsp[-1].expr)); }
#line 2983 "parser.c"
    break;

  case 208: /* selection_statement: IF '(' expression ')' statement  */
#line 543 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 2989 "parser.c"
    break;

  case 209: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 544 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_IF, (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 2995 "parser.c"
    break;

  case 210: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 545 "bison/parser.yacc"
                                                            { (yyval.stmt) = make_conditional_stmt(STMT_SWITCH, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3001 "parser.c"
    break;

  case 211: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 549 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_WHILE, (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 3007 "parser.c"
    break;

  case 212: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 550 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_conditional_stmt(STMT_DO, (yyvsp[-2].expr), (yyvsp[-5].stmt), 0); }
#line 3013 "parser.c"
    break;

  case 213: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 551 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-3].stmt), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3019 "parser.c"
    break;

  case 214: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 552 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_expr_stmt((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3025 "parser.c"
    break;

  case 215: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 553 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-3].decl), (yyvsp[-2].stmt), 0, (yyvsp[0].stmt)); }
#line 3031 "parser.c"
    break;

  case 216: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 554 "bison/parser.yacc"
                                                                                        { (yyval.stmt) = make_for_decl_stmt((yyvsp[-4].decl), (yyvsp[-3].stmt), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 3037 "parser.c"
    break;

  case 217: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 558 "bison/parser.yacc"
                                { (yyval.stmt) = make_goto_stmt((yyvsp[-1].sval)); }
#line 3043 "parser.c"
    break;

  case 218: /* jump_statement: CONTINUE ';'  */
#line 559 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_CONTINUE); }
#line 3049 "parser.c"
    break;

  case 219: /* jump_statement: BREAK ';'  */
#line 560 "bison/parser.yacc"
                                { (yyval.stmt) = make_empty_stmt(STMT_BREAK); }
#line 3055 "parser.c"
    break;

  case 220: /* jump_statement: RETURN ';'  */
#line 561 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt(0); }
#line 3061 "parser.c"
    break;

  case 221: /* jump_statement: RETURN expression ';'  */
#line 562 "bison/parser.yacc"
                                { (yyval.stmt) = make_return_stmt((yyvsp[-1].expr)); }
#line 3067 "parser.c"
    break;

  case 222: /* print_statement: PRINT '(' expression ')' ';'  */
#line 566 "bison/parser.yacc"
                                    { (yyval.stmt) = make_print_stmt((yyvsp[-2].expr)); }
#line 3073 "parser.c"
    break;

  case 223: /* translation_unit: external_declaration  */
#line 570 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit(0, (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3079 "parser.c"
    break;

  case 224: /* translation_unit: translation_unit external_declaration  */
#line 571 "bison/parser.yacc"
                                                { (yyval.translation_unit) = make_trans_unit((yyvsp[-1].translation_unit), (yyvsp[0].ext_decl)); ast_root = (yyval.translation_unit); }
#line 3085 "parser.c"
    break;

  case 225: /* external_declaration: function_definition  */
#line 575 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_func_ext_decl((yyvsp[0].func_def)); }
#line 3091 "parser.c"
    break;

  case 226: /* external_declaration: declaration  */
#line 576 "bison/parser.yacc"
                                { (yyval.ext_decl) = make_decl_ext_decl((yyvsp[0].decl)); }
#line 3097 "parser.c"
    break;

  case 227: /* $@2: %empty  */
#line 580 "bison/parser.yacc"
                                                                { set_func_name(get_decltr_id((yyvsp[0].decltr))); }
#line 3103 "parser.c"
    break;

  case 228: /* function_definition: declaration_specifiers declarator $@2 compound_statement  */
#line 582 "bison/parser.yacc"
    {
        func_ended();
        (yyval.func_def) = make_func_def(make_decl_specs((yyvsp[-3].decl_spec_list)), (yyvsp[-2].decltr), (yyvsp[0].stmt));
    }
#line 3112 "parser.c"
    break;


#line 3116 "parser.c"

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

#line 588 "bison/parser.yacc"
