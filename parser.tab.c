/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "ast.h"

extern int yylex();
void yyerror(const char*);


#line 83 "parser.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    CHARLIT = 259,                 /* CHARLIT  */
    STRING = 260,                  /* STRING  */
    NUMBER = 261,                  /* NUMBER  */
    INDSEL = 262,                  /* INDSEL  */
    PLUSPLUS = 263,                /* PLUSPLUS  */
    MINUSMINUS = 264,              /* MINUSMINUS  */
    SHL = 265,                     /* SHL  */
    SHR = 266,                     /* SHR  */
    LTEQ = 267,                    /* LTEQ  */
    GTEQ = 268,                    /* GTEQ  */
    EQEQ = 269,                    /* EQEQ  */
    NOTEQ = 270,                   /* NOTEQ  */
    LOGAND = 271,                  /* LOGAND  */
    LOGOR = 272,                   /* LOGOR  */
    ELLIPSIS = 273,                /* ELLIPSIS  */
    TIMESEQ = 274,                 /* TIMESEQ  */
    DIVEQ = 275,                   /* DIVEQ  */
    MODEQ = 276,                   /* MODEQ  */
    PLUSEQ = 277,                  /* PLUSEQ  */
    MINUSEQ = 278,                 /* MINUSEQ  */
    SHLEQ = 279,                   /* SHLEQ  */
    SHREQ = 280,                   /* SHREQ  */
    ANDEQ = 281,                   /* ANDEQ  */
    OREQ = 282,                    /* OREQ  */
    XOREQ = 283,                   /* XOREQ  */
    AUTO = 284,                    /* AUTO  */
    BREAK = 285,                   /* BREAK  */
    CASE = 286,                    /* CASE  */
    CHAR = 287,                    /* CHAR  */
    CONST = 288,                   /* CONST  */
    CONTINUE = 289,                /* CONTINUE  */
    DEFAULT = 290,                 /* DEFAULT  */
    DO = 291,                      /* DO  */
    DOUBLE = 292,                  /* DOUBLE  */
    ELSE = 293,                    /* ELSE  */
    ENUM = 294,                    /* ENUM  */
    EXTERN = 295,                  /* EXTERN  */
    FLOAT = 296,                   /* FLOAT  */
    FOR = 297,                     /* FOR  */
    GOTO = 298,                    /* GOTO  */
    IF = 299,                      /* IF  */
    INLINE = 300,                  /* INLINE  */
    INT = 301,                     /* INT  */
    LONG = 302,                    /* LONG  */
    REGISTER = 303,                /* REGISTER  */
    RESTRICT = 304,                /* RESTRICT  */
    RETURN = 305,                  /* RETURN  */
    SHORT = 306,                   /* SHORT  */
    SIGNED = 307,                  /* SIGNED  */
    SIZEOF = 308,                  /* SIZEOF  */
    STATIC = 309,                  /* STATIC  */
    STRUCT = 310,                  /* STRUCT  */
    SWITCH = 311,                  /* SWITCH  */
    TYPEDEF = 312,                 /* TYPEDEF  */
    UNION = 313,                   /* UNION  */
    UNSIGNED = 314,                /* UNSIGNED  */
    VOID = 315,                    /* VOID  */
    VOLATILE = 316,                /* VOLATILE  */
    WHILE = 317,                   /* WHILE  */
    _BOOL = 318,                   /* _BOOL  */
    _COMPLEX = 319,                /* _COMPLEX  */
    _IMAGINARY = 320               /* _IMAGINARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parser.y"

    /* for single character tokens */
    int c; 

    struct Str{
        char *str;
        int len;
    }str;

    struct Num{
        unsigned long long int_num;
        long double real;
        int type;
        int sign;
    }num;

    char*   ident;
    char    charlit;
    struct astnode *astnode_p;

#line 219 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_CHARLIT = 4,                    /* CHARLIT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_INDSEL = 7,                     /* INDSEL  */
  YYSYMBOL_PLUSPLUS = 8,                   /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 9,                 /* MINUSMINUS  */
  YYSYMBOL_SHL = 10,                       /* SHL  */
  YYSYMBOL_SHR = 11,                       /* SHR  */
  YYSYMBOL_LTEQ = 12,                      /* LTEQ  */
  YYSYMBOL_GTEQ = 13,                      /* GTEQ  */
  YYSYMBOL_EQEQ = 14,                      /* EQEQ  */
  YYSYMBOL_NOTEQ = 15,                     /* NOTEQ  */
  YYSYMBOL_LOGAND = 16,                    /* LOGAND  */
  YYSYMBOL_LOGOR = 17,                     /* LOGOR  */
  YYSYMBOL_ELLIPSIS = 18,                  /* ELLIPSIS  */
  YYSYMBOL_TIMESEQ = 19,                   /* TIMESEQ  */
  YYSYMBOL_DIVEQ = 20,                     /* DIVEQ  */
  YYSYMBOL_MODEQ = 21,                     /* MODEQ  */
  YYSYMBOL_PLUSEQ = 22,                    /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 23,                   /* MINUSEQ  */
  YYSYMBOL_SHLEQ = 24,                     /* SHLEQ  */
  YYSYMBOL_SHREQ = 25,                     /* SHREQ  */
  YYSYMBOL_ANDEQ = 26,                     /* ANDEQ  */
  YYSYMBOL_OREQ = 27,                      /* OREQ  */
  YYSYMBOL_XOREQ = 28,                     /* XOREQ  */
  YYSYMBOL_AUTO = 29,                      /* AUTO  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CASE = 31,                      /* CASE  */
  YYSYMBOL_CHAR = 32,                      /* CHAR  */
  YYSYMBOL_CONST = 33,                     /* CONST  */
  YYSYMBOL_CONTINUE = 34,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 35,                   /* DEFAULT  */
  YYSYMBOL_DO = 36,                        /* DO  */
  YYSYMBOL_DOUBLE = 37,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_ENUM = 39,                      /* ENUM  */
  YYSYMBOL_EXTERN = 40,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 41,                     /* FLOAT  */
  YYSYMBOL_FOR = 42,                       /* FOR  */
  YYSYMBOL_GOTO = 43,                      /* GOTO  */
  YYSYMBOL_IF = 44,                        /* IF  */
  YYSYMBOL_INLINE = 45,                    /* INLINE  */
  YYSYMBOL_INT = 46,                       /* INT  */
  YYSYMBOL_LONG = 47,                      /* LONG  */
  YYSYMBOL_REGISTER = 48,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 49,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 50,                    /* RETURN  */
  YYSYMBOL_SHORT = 51,                     /* SHORT  */
  YYSYMBOL_SIGNED = 52,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 53,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 54,                    /* STATIC  */
  YYSYMBOL_STRUCT = 55,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 56,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 57,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 58,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 59,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 60,                      /* VOID  */
  YYSYMBOL_VOLATILE = 61,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL__BOOL = 63,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 64,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 65,                /* _IMAGINARY  */
  YYSYMBOL_66_ = 66,                       /* ','  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* '?'  */
  YYSYMBOL_69_ = 69,                       /* ':'  */
  YYSYMBOL_70_ = 70,                       /* '|'  */
  YYSYMBOL_71_ = 71,                       /* '^'  */
  YYSYMBOL_72_ = 72,                       /* '&'  */
  YYSYMBOL_73_ = 73,                       /* '<'  */
  YYSYMBOL_74_ = 74,                       /* '>'  */
  YYSYMBOL_75_ = 75,                       /* '+'  */
  YYSYMBOL_76_ = 76,                       /* '-'  */
  YYSYMBOL_77_ = 77,                       /* '*'  */
  YYSYMBOL_78_ = 78,                       /* '/'  */
  YYSYMBOL_79_ = 79,                       /* '%'  */
  YYSYMBOL_80_ = 80,                       /* '('  */
  YYSYMBOL_81_ = 81,                       /* ')'  */
  YYSYMBOL_82_ = 82,                       /* '.'  */
  YYSYMBOL_83_ = 83,                       /* '['  */
  YYSYMBOL_84_ = 84,                       /* ']'  */
  YYSYMBOL_85_ = 85,                       /* ';'  */
  YYSYMBOL_86_ = 86,                       /* '~'  */
  YYSYMBOL_87_ = 87,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 88,                  /* $accept  */
  YYSYMBOL_statement = 89,                 /* statement  */
  YYSYMBOL_expr = 90,                      /* expr  */
  YYSYMBOL_assign_expr = 91,               /* assign_expr  */
  YYSYMBOL_unary_expr = 92,                /* unary_expr  */
  YYSYMBOL_cond_expr = 93,                 /* cond_expr  */
  YYSYMBOL_arith_expr = 94,                /* arith_expr  */
  YYSYMBOL_cast_expr = 95,                 /* cast_expr  */
  YYSYMBOL_postfix_expr = 96,              /* postfix_expr  */
  YYSYMBOL_prim_expr = 97                  /* prim_expr  */
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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

#define YYMAXUTOK   320


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
       2,     2,     2,    87,     2,     2,     2,    79,    72,     2,
      80,    81,    77,    75,    66,    76,    82,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    85,
      73,    67,    74,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    83,     2,    84,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    70,     2,    86,     2,     2,     2,
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
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    67,    70,    71,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    88,    89,
      91,    93,    94,    95,    96,    97,    98,    99,   100,   103,
     104,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   134,   137,   138,   140,   141,
     147,   148,   149,   150
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "CHARLIT",
  "STRING", "NUMBER", "INDSEL", "PLUSPLUS", "MINUSMINUS", "SHL", "SHR",
  "LTEQ", "GTEQ", "EQEQ", "NOTEQ", "LOGAND", "LOGOR", "ELLIPSIS",
  "TIMESEQ", "DIVEQ", "MODEQ", "PLUSEQ", "MINUSEQ", "SHLEQ", "SHREQ",
  "ANDEQ", "OREQ", "XOREQ", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL",
  "_COMPLEX", "_IMAGINARY", "','", "'='", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'",
  "'.'", "'['", "']'", "';'", "'~'", "'!'", "$accept", "statement", "expr",
  "assign_expr", "unary_expr", "cond_expr", "arith_expr", "cast_expr",
  "postfix_expr", "prim_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    44,    61,    63,    58,
     124,    94,    38,    60,    62,    43,    45,    42,    47,    37,
      40,    41,    46,    91,    93,    59,   126,    33
};
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,   -93,   -93,   -93,   -93,    52,    52,    39,    52,    52,
      52,    52,    26,    52,    52,     0,   -65,   -93,   139,   -93,
     173,   -93,    58,   -93,   -93,   -93,    52,   -93,   -93,   -93,
     -93,   -93,   -93,   138,   -93,   -93,   -93,   -59,    26,   -93,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,   -93,   -93,    52,    52,    52,    52,    52,    52,    52,
      52,    26,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    13,    -1,    12,    26,   -58,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -55,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -54,   -93,   -93,   -56,   -93,    26,   -93,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    60,    62,    63,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    55,    17,
      29,    54,    18,    56,    19,    20,     0,    21,    55,    23,
      25,    26,    24,     0,    27,    28,     1,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     3,     5,
       9,    10,    11,     7,     8,    12,    13,    14,    16,    15,
       6,    40,    39,    43,    44,    45,    46,    47,    48,     0,
      34,    35,    36,    41,    42,    31,    32,    33,    38,    37,
      51,     0,    59,    58,     0,    22,     0,    52,    57,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,    -2,   189,   130,   -92,    21,   212,   -93,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    17,    28,    19,    20,    21,    22,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    38,   112,     1,     2,     3,     4,    38,     5,     6,
      38,    38,    38,    37,   116,   113,     1,     2,     3,     4,
      39,     5,     6,   115,   119,     0,    78,   117,   118,     1,
       2,     3,     4,    33,     5,     6,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     0,     5,     6,     0,
       0,     0,     0,     7,     0,     1,     2,     3,     4,    99,
       5,     6,     0,     0,     0,    73,     7,     0,     0,     0,
     111,     0,     8,   114,     0,     9,    10,    11,     0,     7,
      12,     0,     0,     0,     0,     8,    13,    14,     9,    10,
      11,     0,     7,    12,   110,     0,     0,     0,     8,    13,
      14,     9,    10,    11,     0,     7,    12,     0,     0,     0,
       0,     8,    13,    14,     9,    10,    11,     0,     0,    26,
       0,     0,     0,     0,     8,    13,    14,     9,    10,    11,
      18,     0,     0,     0,     0,    24,    25,    27,    13,    14,
      74,    75,     0,     0,     0,    18,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    76,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    18,     0,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,    18,    50,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    77,
      29,    30,    31,    32,     0,    34,    35,    79,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    61,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109
};

static const yytype_int8 yycheck[] =
{
       0,    66,     3,     3,     4,     5,     6,    66,     8,     9,
      66,    66,    66,    15,    69,     3,     3,     4,     5,     6,
      85,     8,     9,    81,   116,    -1,    85,    81,    84,     3,
       4,     5,     6,    12,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    53,    -1,     3,     4,     5,     6,    61,
       8,     9,    -1,    -1,    -1,     7,    53,    -1,    -1,    -1,
      72,    -1,    72,    75,    -1,    75,    76,    77,    -1,    53,
      80,    -1,    -1,    -1,    -1,    72,    86,    87,    75,    76,
      77,    -1,    53,    80,    81,    -1,    -1,    -1,    72,    86,
      87,    75,    76,    77,    -1,    53,    80,    -1,    -1,    -1,
      -1,    72,    86,    87,    75,    76,    77,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    72,    86,    87,    75,    76,    77,
       0,    -1,    -1,    -1,    -1,     5,     6,     7,    86,    87,
      82,    83,    -1,    -1,    -1,    15,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    26,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    75,    67,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       8,     9,    10,    11,    -1,    13,    14,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    53,    72,    75,
      76,    77,    80,    86,    87,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    92,    92,    80,    92,    92,    95,
      95,    95,    95,    94,    95,    95,     0,    90,    66,    85,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      67,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    68,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     7,    82,    83,    92,    81,    85,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    95,    95,    95,    95,    95,    95,    95,    95,    90,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      81,    90,     3,     3,    90,    81,    69,    81,    84,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    96,    96,    96,    96,
      97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     4,     2,     2,     2,     2,     2,     2,     1,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     4,     3,     1,     1,     1,     4,     3,     3,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2:
#line 66 "parser.y"
                                                            {print_ast((yyvsp[-1].astnode_p)); putchar('\n');}
#line 1420 "parser.tab.c"
    break;

  case 3:
#line 67 "parser.y"
                                                            {print_ast((yyvsp[-1].astnode_p)); putchar('\n');}
#line 1426 "parser.tab.c"
    break;

  case 4:
#line 70 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1432 "parser.tab.c"
    break;

  case 5:
#line 71 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP, (yyvsp[-2].astnode_p), ',', (yyvsp[0].astnode_p));}
#line 1438 "parser.tab.c"
    break;

  case 6:
#line 74 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(ASSIGN, (yyvsp[-2].astnode_p), '=', (yyvsp[0].astnode_p));}
#line 1444 "parser.tab.c"
    break;

  case 7:
#line 75 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 1450 "parser.tab.c"
    break;

  case 8:
#line 76 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 1456 "parser.tab.c"
    break;

  case 9:
#line 77 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 1462 "parser.tab.c"
    break;

  case 10:
#line 78 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 1468 "parser.tab.c"
    break;

  case 11:
#line 79 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 1474 "parser.tab.c"
    break;

  case 12:
#line 80 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 1480 "parser.tab.c"
    break;

  case 13:
#line 81 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 1486 "parser.tab.c"
    break;

  case 14:
#line 82 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 1492 "parser.tab.c"
    break;

  case 15:
#line 83 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 1498 "parser.tab.c"
    break;

  case 16:
#line 84 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 1504 "parser.tab.c"
    break;

  case 17:
#line 85 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1510 "parser.tab.c"
    break;

  case 18:
#line 88 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1516 "parser.tab.c"
    break;

  case 19:
#line 89 "parser.y"
                                                            {ASTNODE temp = alloc_and_set_num(1, 0.0, N_INT, N_SIGNED);
                                                                (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '+', temp);}
#line 1523 "parser.tab.c"
    break;

  case 20:
#line 91 "parser.y"
                                                            {ASTNODE temp = alloc_and_set_num(1, 0.0, N_INT, N_SIGNED);
                                                                (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '-', temp);}
#line 1530 "parser.tab.c"
    break;

  case 21:
#line 93 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_sizeof((yyvsp[0].astnode_p));}
#line 1536 "parser.tab.c"
    break;

  case 22:
#line 94 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_sizeof((yyvsp[-1].astnode_p));}
#line 1542 "parser.tab.c"
    break;

  case 23:
#line 95 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('&',(yyvsp[0].astnode_p));}
#line 1548 "parser.tab.c"
    break;

  case 24:
#line 96 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('*',(yyvsp[0].astnode_p));}
#line 1554 "parser.tab.c"
    break;

  case 25:
#line 97 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('+',(yyvsp[0].astnode_p));}
#line 1560 "parser.tab.c"
    break;

  case 26:
#line 98 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('-',(yyvsp[0].astnode_p));}
#line 1566 "parser.tab.c"
    break;

  case 27:
#line 99 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('~',(yyvsp[0].astnode_p));}
#line 1572 "parser.tab.c"
    break;

  case 28:
#line 100 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('!',(yyvsp[0].astnode_p));}
#line 1578 "parser.tab.c"
    break;

  case 29:
#line 103 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1584 "parser.tab.c"
    break;

  case 30:
#line 104 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_ternary((yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 1590 "parser.tab.c"
    break;

  case 31:
#line 107 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 1596 "parser.tab.c"
    break;

  case 32:
#line 108 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 1602 "parser.tab.c"
    break;

  case 33:
#line 109 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 1608 "parser.tab.c"
    break;

  case 34:
#line 110 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 1614 "parser.tab.c"
    break;

  case 35:
#line 111 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 1620 "parser.tab.c"
    break;

  case 36:
#line 112 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 1626 "parser.tab.c"
    break;

  case 37:
#line 113 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 1632 "parser.tab.c"
    break;

  case 38:
#line 114 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 1638 "parser.tab.c"
    break;

  case 39:
#line 115 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 1644 "parser.tab.c"
    break;

  case 40:
#line 116 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 1650 "parser.tab.c"
    break;

  case 41:
#line 117 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '<', (yyvsp[0].astnode_p));}
#line 1656 "parser.tab.c"
    break;

  case 42:
#line 118 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), '>', (yyvsp[0].astnode_p));}
#line 1662 "parser.tab.c"
    break;

  case 43:
#line 119 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), LTEQ, (yyvsp[0].astnode_p));}
#line 1668 "parser.tab.c"
    break;

  case 44:
#line 120 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), GTEQ, (yyvsp[0].astnode_p));}
#line 1674 "parser.tab.c"
    break;

  case 45:
#line 121 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), EQEQ, (yyvsp[0].astnode_p));}
#line 1680 "parser.tab.c"
    break;

  case 46:
#line 122 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), NOTEQ, (yyvsp[0].astnode_p));}
#line 1686 "parser.tab.c"
    break;

  case 47:
#line 123 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), LOGAND, (yyvsp[0].astnode_p));}
#line 1692 "parser.tab.c"
    break;

  case 48:
#line 124 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP,(yyvsp[-2].astnode_p), LOGOR, (yyvsp[0].astnode_p));}
#line 1698 "parser.tab.c"
    break;

  case 49:
#line 125 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary(PLUSPLUS,(yyvsp[-1].astnode_p));}
#line 1704 "parser.tab.c"
    break;

  case 50:
#line 126 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary(MINUSMINUS,(yyvsp[-1].astnode_p));}
#line 1710 "parser.tab.c"
    break;

  case 51:
#line 127 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_fncall((yyvsp[-2].astnode_p), NULL);}
#line 1716 "parser.tab.c"
    break;

  case 52:
#line 128 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_fncall((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 1722 "parser.tab.c"
    break;

  case 53:
#line 129 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 1728 "parser.tab.c"
    break;

  case 54:
#line 130 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1734 "parser.tab.c"
    break;

  case 55:
#line 134 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1740 "parser.tab.c"
    break;

  case 56:
#line 137 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1746 "parser.tab.c"
    break;

  case 57:
#line 138 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_binary(BINOP, (yyvsp[-3].astnode_p), '+', (yyvsp[-1].astnode_p));
                                                                (yyval.astnode_p)=alloc_and_set_unary('*', (yyval.astnode_p));}
#line 1753 "parser.tab.c"
    break;

  case 58:
#line 140 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_select((yyvsp[-2].astnode_p), (yyvsp[0].ident));}
#line 1759 "parser.tab.c"
    break;

  case 59:
#line 141 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_set_unary('*', (yyvsp[-2].astnode_p));
                                                                (yyval.astnode_p)=alloc_and_set_select((yyval.astnode_p), (yyvsp[0].ident));}
#line 1766 "parser.tab.c"
    break;

  case 60:
#line 147 "parser.y"
                                                {(yyval.astnode_p)=alloc_and_set_ident((yyvsp[0].ident));}
#line 1772 "parser.tab.c"
    break;

  case 61:
#line 148 "parser.y"
                                                {(yyval.astnode_p)=alloc_and_set_num((yyvsp[0].num).int_num, (yyvsp[0].num).real, (yyvsp[0].num).type, (yyvsp[0].num).sign);}
#line 1778 "parser.tab.c"
    break;

  case 62:
#line 149 "parser.y"
                                                {(yyval.astnode_p)=alloc_and_set_charlit((yyvsp[0].charlit));}
#line 1784 "parser.tab.c"
    break;

  case 63:
#line 150 "parser.y"
                                                {(yyval.astnode_p)=alloc_and_set_string((yyvsp[0].str).str, (yyvsp[0].str).len);}
#line 1790 "parser.tab.c"
    break;


#line 1794 "parser.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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

#line 152 "parser.y"
 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s\n", msg);
}

int main(){
    yyparse();
    return 1;
}
