/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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
#include "sym_tab.h"
#include "ast.h"

/* stuff from lex */
extern int yylex();
extern char filename[256];
extern int lineno;

/* stuff for symbol table */
SYM_TAB curr_scope;

void yyerror(const char*);


#line 90 "parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    CHARLIT = 259,
    STRING = 260,
    NUMBER = 261,
    INDSEL = 262,
    PLUSPLUS = 263,
    MINUSMINUS = 264,
    SHL = 265,
    SHR = 266,
    LTEQ = 267,
    GTEQ = 268,
    EQEQ = 269,
    NOTEQ = 270,
    LOGAND = 271,
    LOGOR = 272,
    ELLIPSIS = 273,
    TIMESEQ = 274,
    DIVEQ = 275,
    MODEQ = 276,
    PLUSEQ = 277,
    MINUSEQ = 278,
    SHLEQ = 279,
    SHREQ = 280,
    ANDEQ = 281,
    OREQ = 282,
    XOREQ = 283,
    AUTO = 284,
    BREAK = 285,
    CASE = 286,
    CHAR = 287,
    CONST = 288,
    CONTINUE = 289,
    DEFAULT = 290,
    DO = 291,
    DOUBLE = 292,
    ELSE = 293,
    ENUM = 294,
    EXTERN = 295,
    FLOAT = 296,
    FOR = 297,
    GOTO = 298,
    IF = 299,
    INLINE = 300,
    INT = 301,
    LONG = 302,
    REGISTER = 303,
    RESTRICT = 304,
    RETURN = 305,
    SHORT = 306,
    SIGNED = 307,
    SIZEOF = 308,
    STATIC = 309,
    STRUCT = 310,
    SWITCH = 311,
    TYPEDEF = 312,
    UNION = 313,
    UNSIGNED = 314,
    VOID = 315,
    VOLATILE = 316,
    WHILE = 317,
    _BOOL = 318,
    _COMPLEX = 319,
    _IMAGINARY = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

    /* for single character tokens */
    int c; 

    /* definition in def.h */
    struct Str str;
    struct Num num;

    char*  ident;
    char   charlit;
    struct astnode *astnode_p; /* definition in ast.h */

#line 221 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   635

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

#define YYUNDEFTOK  2
#define YYMAXUTOK   320


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,     2,     2,    79,    72,     2,
      82,    83,    77,    75,    66,    76,    84,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    87,
      73,    67,    74,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    70,     2,    80,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    95,    98,   102,   103,   107,   108,   110,
     111,   112,   113,   116,   117,   118,   119,   120,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   140,
     141,   142,   144,   147,   148,   151,   152,   155,   156,   159,
     162,   163,   166,   167,   168,   169,   170,   171,   172,   176,
     177,   178,   179,   182,   183,   186,   187,   190,   191,   192,
     195,   196,   197,   200,   201,   202,   209,   210,   239,   240,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   257,   258,   260,   262,   263,   264,   265,   266,
     267,   268,   269,   275,   276,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   304,   307,   308,
     310,   311,   313,   314,   323,   324,   325,   326,   329,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "CHARLIT", "STRING", "NUMBER",
  "INDSEL", "PLUSPLUS", "MINUSMINUS", "SHL", "SHR", "LTEQ", "GTEQ", "EQEQ",
  "NOTEQ", "LOGAND", "LOGOR", "ELLIPSIS", "TIMESEQ", "DIVEQ", "MODEQ",
  "PLUSEQ", "MINUSEQ", "SHLEQ", "SHREQ", "ANDEQ", "OREQ", "XOREQ", "AUTO",
  "BREAK", "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE",
  "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT",
  "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF",
  "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID",
  "VOLATILE", "WHILE", "_BOOL", "_COMPLEX", "_IMAGINARY", "','", "'='",
  "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'~'", "'!'", "'('", "')'", "'.'", "'['", "']'", "';'",
  "$accept", "translation_unit", "extern_declaration", "declaration",
  "declaration_specs", "declaration_spec", "stg_class_spec", "type_spec",
  "type_qualif", "func_spec", "type_qualif_list", "init_decl_list",
  "init_decl", "init", "decl", "direct_decl", "pointer", "param_type_list",
  "param_list", "param_declaration", "abstract_decl",
  "direct_abstract_decl", "ident_list", "expr", "assign_expr",
  "unary_expr", "cond_expr", "arith_expr", "cast_expr", "postfix_expr",
  "prim_expr", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
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
     126,    33,    40,    41,    46,    91,    93,    59
};
# endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     571,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,   483,  -105,  -105,    63,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,   163,    16,  -105,  -105,   -60,  -105,   -34,
     -57,    20,  -105,   163,  -105,   -44,    16,  -105,   228,   162,
       1,   -57,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
     269,   269,   258,   269,   269,   269,   269,   269,   269,   228,
    -105,  -105,   472,  -105,   304,  -105,    57,  -105,  -105,  -105,
     115,   -43,   -28,  -105,   -46,  -105,  -105,  -105,   -51,  -105,
    -105,   269,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
     281,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,  -105,  -105,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,    39,   177,    41,   228,    12,     4,  -105,
      31,  -105,  -105,  -105,   538,    42,  -105,  -105,   -37,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,   209,   209,   357,   357,    59,    59,   386,   376,   -40,
    -105,   395,   403,   411,   357,   357,   150,   150,     9,     9,
       9,  -105,  -105,   -42,  -105,   -50,   -36,  -105,   -35,  -105,
    -105,  -105,  -105,  -105,   228,   228,  -105,  -105,  -105,  -105,
    -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    19,    29,    24,    15,    23,    32,    21,    22,
      17,    30,    20,    25,    14,    16,    26,    18,    31,    27,
      28,     0,     2,     4,     0,     7,     9,    10,    11,    12,
       1,     3,    42,    49,     0,     5,     8,     0,    35,    37,
      40,     0,    33,    51,    50,     0,     0,     6,     0,     0,
       0,    41,    34,    52,    43,    36,   124,   126,   127,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,   117,    81,    93,   116,    82,   118,    66,    48,
      58,     0,    53,    55,     0,   129,   128,    45,     0,    83,
      84,     0,    85,   117,    87,    89,    90,    88,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      60,    59,    62,    46,     0,     0,    47,    44,     0,   115,
      73,    74,    75,    71,    72,    76,    77,    78,    80,    79,
      70,   104,   103,   107,   108,   109,   110,   111,   112,     0,
      68,    98,    99,   100,   105,   106,    95,    96,    97,   102,
     101,   121,   122,     0,   120,     0,     0,    64,     0,    61,
      54,    56,    67,    86,     0,     0,   123,   119,    63,    65,
      69,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,    29,  -105,   -45,   -15,  -105,  -105,   -12,  -105,
    -105,  -105,     6,  -105,   -31,   -39,   -32,  -105,  -105,   -71,
     -30,   -49,  -105,  -104,   -26,   -48,   -76,   434,   260,  -105,
    -105,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      43,    37,    38,    70,    39,    40,    41,    81,    82,    83,
     141,   142,    84,   169,   170,    93,    73,    74,    75,    76,
      77,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,    44,    51,    45,    80,    85,    46,    86,    85,    36,
      86,    53,    89,    90,    92,    32,   194,   112,   113,    32,
     145,    42,    71,    32,   194,    49,   194,    47,    50,   195,
     183,    52,   185,    48,    32,   147,   197,   146,   144,    54,
     143,   196,   181,   148,   184,   192,   193,   198,   140,   139,
      31,   199,    55,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,   133,    36,    32,   112,   113,   114,
     115,   116,   117,   191,    72,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    72,    87,    72,    33,
     187,   189,     1,    33,   137,     2,     3,   138,    34,    80,
       4,    51,    34,     5,     6,   140,    45,   186,     7,     8,
       9,    10,    11,   137,    12,    13,   138,    14,    32,   201,
      15,   188,    16,    17,    18,     0,    19,    20,     0,     0,
       0,     0,   126,   127,   128,   129,   130,   131,   132,   134,
      33,   135,   136,     0,     1,    34,    72,     2,     3,     0,
      35,     0,     4,     0,     0,     5,     6,     0,   112,   113,
       7,     8,     9,    10,    11,    78,    12,    13,   200,    14,
       0,     0,    15,     0,    16,    17,    18,     0,    19,    20,
      56,    57,    58,    59,     0,    60,    61,     0,     0,     0,
       0,     1,    33,     0,     2,     3,     3,   137,     0,     4,
     138,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    11,    12,    13,     0,    14,   112,   113,    15,
       0,    16,    17,    18,    18,    19,    20,   130,   131,   132,
      62,    56,    57,    58,    59,     0,    60,    61,     0,     0,
      33,     0,     0,     0,     0,    79,     0,     0,     0,    63,
       0,     0,    64,    65,    66,     0,     0,    67,    68,    69,
     182,    56,    57,    58,    59,     0,    60,    61,     0,     0,
       0,     0,    56,    57,    58,    59,     0,    60,    61,     0,
       0,    62,     0,     0,   128,   129,   130,   131,   132,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
      63,     0,     0,    64,    65,    66,     0,     0,    67,    68,
      69,    62,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    62,    94,    95,    96,    97,    98,    99,     0,
      63,     0,     0,    64,    65,    66,     0,     0,    67,    68,
      91,    63,     0,     0,    64,    65,    66,     0,     0,    67,
      68,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,   149,   112,   113,   114,   115,     0,
       0,     0,   122,     0,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   112,   113,   114,   115,   116,   117,   118,   119,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   125,   126,   127,   128,   129,
     130,   131,   132,    30,   126,   127,   128,   129,   130,   131,
     132,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,     0,   111,
      15,     0,    16,    17,    18,     0,    19,    20,   161,   162,
     163,   164,   165,   166,   167,   168,   190,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,     0,     0,    15,     0,    16,    17,    18,
       1,    19,    20,     2,     3,     0,     0,     0,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,     0,    12,    13,     0,    14,     0,     0,    15,     0,
      16,    17,    18,     0,    19,    20
};

static const yytype_int16 yycheck[] =
{
      48,    33,    41,    34,    49,     4,    66,     6,     4,    24,
       6,    43,    60,    61,    62,     3,    66,     8,     9,     3,
      66,    33,    48,     3,    66,    82,    66,    87,    85,    69,
     134,    43,   136,    67,     3,    86,    86,    83,    66,    83,
      83,    83,     3,    91,     3,     3,    83,    83,    80,    80,
      21,    86,    46,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     7,    80,     3,     8,     9,    10,
      11,    12,    13,   144,   122,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   134,    86,   136,    77,
      86,   140,    29,    77,    82,    32,    33,    85,    82,   144,
      37,   140,    82,    40,    41,   137,   137,   137,    45,    46,
      47,    48,    49,    82,    51,    52,    85,    54,     3,   195,
      57,   138,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    82,
      77,    84,    85,    -1,    29,    82,   194,    32,    33,    -1,
      87,    -1,    37,    -1,    -1,    40,    41,    -1,     8,     9,
      45,    46,    47,    48,    49,     3,    51,    52,   194,    54,
      -1,    -1,    57,    -1,    59,    60,    61,    -1,    63,    64,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    29,    77,    -1,    32,    33,    33,    82,    -1,    37,
      85,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    49,    51,    52,    -1,    54,     8,     9,    57,
      -1,    59,    60,    61,    61,    63,    64,    77,    78,    79,
      53,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    72,
      -1,    -1,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    53,    -1,    -1,    75,    76,    77,    78,    79,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      72,    -1,    -1,    75,    76,    77,    -1,    -1,    80,    81,
      82,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    53,    63,    64,    65,    66,    67,    68,    -1,
      72,    -1,    -1,    75,    76,    77,    -1,    -1,    80,    81,
      82,    72,    -1,    -1,    75,    76,    77,    -1,    -1,    80,
      81,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    83,     8,     9,    10,    11,    -1,
      -1,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,     8,     9,    10,    11,    12,    13,    14,    15,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    73,    74,    75,    76,    77,    78,
      79,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    51,    52,    -1,    54,    -1,    67,
      57,    -1,    59,    60,    61,    -1,    63,    64,   114,   115,
     116,   117,   118,   119,   120,   121,    18,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,    51,
      52,    -1,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      29,    63,    64,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    -1,    51,    52,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    61,    -1,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    32,    33,    37,    40,    41,    45,    46,    47,
      48,    49,    51,    52,    54,    57,    59,    60,    61,    63,
      64,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,    90,     3,    77,    82,    87,    93,    99,   100,   102,
     103,   104,    96,    98,   104,   102,    66,    87,    67,    82,
      85,   103,    96,   104,    83,   100,     3,     4,     5,     6,
       8,     9,    53,    72,    75,    76,    77,    80,    81,    82,
     101,   112,   113,   114,   115,   116,   117,   118,     3,    83,
      92,   105,   106,   107,   110,     4,     6,    86,   119,   113,
     113,    82,   113,   113,   116,   116,   116,   116,   116,   116,
     115,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    67,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    68,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     7,    82,    84,    85,    82,    85,   102,
     104,   108,   109,    83,    66,    66,    83,    86,   113,    83,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   115,   115,   115,   115,   115,   115,   115,   115,   111,
     112,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,     3,    83,   111,     3,   111,   108,    86,   119,   109,
      18,   107,     3,    83,    66,    69,    83,    86,    83,    86,
     112,   114
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    88,    89,    89,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    97,    98,    98,    99,    99,   100,   100,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     108,   108,   108,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   117,   117,
     117,   117,   117,   117,   118,   118,   118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     3,     1,     3,     2,     1,     2,
       1,     2,     1,     3,     2,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     2,     2,     4,     2,     2,     2,
       2,     2,     2,     1,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     1,     1,     1,     4,
       3,     3,     3,     4,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
#line 94 "parser.y"
                                                                        {}
#line 1643 "parser.tab.c"
    break;

  case 3:
#line 95 "parser.y"
                                                                        {}
#line 1649 "parser.tab.c"
    break;

  case 4:
#line 98 "parser.y"
                                                                        {print_sym(curr_scope);}
#line 1655 "parser.tab.c"
    break;

  case 5:
#line 102 "parser.y"
                                                                {yyerror("Empty Declaration");}
#line 1661 "parser.tab.c"
    break;

  case 6:
#line 103 "parser.y"
                                                                {sym_decl((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));}
#line 1667 "parser.tab.c"
    break;

  case 7:
#line 107 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 1673 "parser.tab.c"
    break;

  case 8:
#line 108 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 1679 "parser.tab.c"
    break;

  case 9:
#line 110 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1685 "parser.tab.c"
    break;

  case 10:
#line 111 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1691 "parser.tab.c"
    break;

  case 11:
#line 112 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1697 "parser.tab.c"
    break;

  case 12:
#line 113 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1703 "parser.tab.c"
    break;

  case 13:
#line 116 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_AUTO);    }
#line 1709 "parser.tab.c"
    break;

  case 14:
#line 117 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_STATIC);  }
#line 1715 "parser.tab.c"
    break;

  case 15:
#line 118 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_EXTERN);  }
#line 1721 "parser.tab.c"
    break;

  case 16:
#line 119 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_TYPEDEF); }
#line 1727 "parser.tab.c"
    break;

  case 17:
#line 120 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_REGISTER);}
#line 1733 "parser.tab.c"
    break;

  case 18:
#line 123 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_VOID);    }
#line 1739 "parser.tab.c"
    break;

  case 19:
#line 124 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_CHAR);    }
#line 1745 "parser.tab.c"
    break;

  case 20:
#line 125 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_SHORT);   }
#line 1751 "parser.tab.c"
    break;

  case 21:
#line 126 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_INT);     }
#line 1757 "parser.tab.c"
    break;

  case 22:
#line 127 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_LONG);    }
#line 1763 "parser.tab.c"
    break;

  case 23:
#line 128 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_FLOAT);   }
#line 1769 "parser.tab.c"
    break;

  case 24:
#line 129 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_DOUBLE);  }
#line 1775 "parser.tab.c"
    break;

  case 25:
#line 130 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_SIGNED);  }
#line 1781 "parser.tab.c"
    break;

  case 26:
#line 131 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_UNSIGNED);}
#line 1787 "parser.tab.c"
    break;

  case 27:
#line 132 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE__BOOL);   }
#line 1793 "parser.tab.c"
    break;

  case 28:
#line 133 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE__COMPLEX);}
#line 1799 "parser.tab.c"
    break;

  case 29:
#line 140 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_CONST);}
#line 1805 "parser.tab.c"
    break;

  case 30:
#line 141 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_RESTRICT);}
#line 1811 "parser.tab.c"
    break;

  case 31:
#line 142 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_VOLATILE);}
#line 1817 "parser.tab.c"
    break;

  case 32:
#line 144 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(FUNC_INLINE);}
#line 1823 "parser.tab.c"
    break;

  case 35:
#line 151 "parser.y"
                                                                     {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 1829 "parser.tab.c"
    break;

  case 36:
#line 152 "parser.y"
                                                                     {(yyval.astnode_p)=(yyvsp[-2].astnode_p); list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 1835 "parser.tab.c"
    break;

  case 37:
#line 155 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1841 "parser.tab.c"
    break;

  case 38:
#line 156 "parser.y"
                                                              {}
#line 1847 "parser.tab.c"
    break;

  case 40:
#line 162 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1853 "parser.tab.c"
    break;

  case 41:
#line 163 "parser.y"
                                                                {(yyval.astnode_p)=list_append((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 1859 "parser.tab.c"
    break;

  case 42:
#line 166 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list(alloc_ident((yyvsp[0].ident)));}
#line 1865 "parser.tab.c"
    break;

  case 43:
#line 167 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[-1].astnode_p); /* fprintf(stdout, "PAREN\n"); print_ast($$); */}
#line 1871 "parser.tab.c"
    break;

  case 44:
#line 168 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem(alloc_array(NULL,(yyvsp[-1].astnode_p)), (yyvsp[-3].astnode_p));}
#line 1877 "parser.tab.c"
    break;

  case 45:
#line 169 "parser.y"
                                                                {yyerror("not supporting variable length arrays");exit(-1);}
#line 1883 "parser.tab.c"
    break;

  case 47:
#line 171 "parser.y"
                                                        {fprintf(stdout, "func paren\n");}
#line 1889 "parser.tab.c"
    break;

  case 49:
#line 176 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list(alloc_ptr(NULL));}
#line 1895 "parser.tab.c"
    break;

  case 50:
#line 177 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem(alloc_ptr(NULL), (yyvsp[0].astnode_p));}
#line 1901 "parser.tab.c"
    break;

  case 51:
#line 178 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list(alloc_ptr(NULL));}
#line 1907 "parser.tab.c"
    break;

  case 52:
#line 179 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem(alloc_ptr(NULL), (yyvsp[0].astnode_p));}
#line 1913 "parser.tab.c"
    break;

  case 53:
#line 182 "parser.y"
                                                                {}
#line 1919 "parser.tab.c"
    break;

  case 54:
#line 183 "parser.y"
                                                                {}
#line 1925 "parser.tab.c"
    break;

  case 55:
#line 186 "parser.y"
                                                                {}
#line 1931 "parser.tab.c"
    break;

  case 56:
#line 187 "parser.y"
                                                                {}
#line 1937 "parser.tab.c"
    break;

  case 63:
#line 200 "parser.y"
                                                                {fprintf(stdout, "ABSTRACT DECL"); (yyval.astnode_p)=alloc_ident("TESTTESTTEST"); /* PLACE HOLDER FOR NOW!!!*/}
#line 1943 "parser.tab.c"
    break;

  case 64:
#line 201 "parser.y"
                                                                {(yyval.astnode_p)=alloc_ident("TESTTESTTEST"); /* PLACE HOLDER FOR NOW!!!*/}
#line 1949 "parser.tab.c"
    break;

  case 65:
#line 202 "parser.y"
                                                                {(yyval.astnode_p)=alloc_ident("TESTTESTTEST"); /* PLACE HOLDER FOR NOW!!!*/}
#line 1955 "parser.tab.c"
    break;

  case 66:
#line 209 "parser.y"
                                                    {(yyval.astnode_p)=alloc_ident("TESTTESTTEST");}
#line 1961 "parser.tab.c"
    break;

  case 67:
#line 210 "parser.y"
                                                    {(yyval.astnode_p)=alloc_ident("TESTTESTTEST");}
#line 1967 "parser.tab.c"
    break;

  case 68:
#line 239 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1973 "parser.tab.c"
    break;

  case 69:
#line 240 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP, (yyvsp[-2].astnode_p), ',', (yyvsp[0].astnode_p));}
#line 1979 "parser.tab.c"
    break;

  case 70:
#line 243 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(ASSIGN, (yyvsp[-2].astnode_p), '=', (yyvsp[0].astnode_p));}
#line 1985 "parser.tab.c"
    break;

  case 71:
#line 244 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 1991 "parser.tab.c"
    break;

  case 72:
#line 245 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 1997 "parser.tab.c"
    break;

  case 73:
#line 246 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 2003 "parser.tab.c"
    break;

  case 74:
#line 247 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 2009 "parser.tab.c"
    break;

  case 75:
#line 248 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 2015 "parser.tab.c"
    break;

  case 76:
#line 249 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 2021 "parser.tab.c"
    break;

  case 77:
#line 250 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 2027 "parser.tab.c"
    break;

  case 78:
#line 251 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 2033 "parser.tab.c"
    break;

  case 79:
#line 252 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 2039 "parser.tab.c"
    break;

  case 80:
#line 253 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 2045 "parser.tab.c"
    break;

  case 81:
#line 254 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2051 "parser.tab.c"
    break;

  case 82:
#line 257 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2057 "parser.tab.c"
    break;

  case 83:
#line 258 "parser.y"
                                                            {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '+', temp);}
#line 2064 "parser.tab.c"
    break;

  case 84:
#line 260 "parser.y"
                                                            {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '-', temp);}
#line 2071 "parser.tab.c"
    break;

  case 85:
#line 262 "parser.y"
                                                            {(yyval.astnode_p)=alloc_sizeof((yyvsp[0].astnode_p));}
#line 2077 "parser.tab.c"
    break;

  case 86:
#line 263 "parser.y"
                                                            {(yyval.astnode_p)=alloc_sizeof((yyvsp[-1].astnode_p));}
#line 2083 "parser.tab.c"
    break;

  case 87:
#line 264 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('&',(yyvsp[0].astnode_p));}
#line 2089 "parser.tab.c"
    break;

  case 88:
#line 265 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('*',(yyvsp[0].astnode_p));}
#line 2095 "parser.tab.c"
    break;

  case 89:
#line 266 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('+',(yyvsp[0].astnode_p));}
#line 2101 "parser.tab.c"
    break;

  case 90:
#line 267 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('-',(yyvsp[0].astnode_p));}
#line 2107 "parser.tab.c"
    break;

  case 91:
#line 268 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('~',(yyvsp[0].astnode_p));}
#line 2113 "parser.tab.c"
    break;

  case 92:
#line 269 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('!',(yyvsp[0].astnode_p));}
#line 2119 "parser.tab.c"
    break;

  case 93:
#line 275 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2125 "parser.tab.c"
    break;

  case 94:
#line 276 "parser.y"
                                                            {(yyval.astnode_p)=alloc_ternary((yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2131 "parser.tab.c"
    break;

  case 95:
#line 279 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 2137 "parser.tab.c"
    break;

  case 96:
#line 280 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 2143 "parser.tab.c"
    break;

  case 97:
#line 281 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 2149 "parser.tab.c"
    break;

  case 98:
#line 282 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 2155 "parser.tab.c"
    break;

  case 99:
#line 283 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 2161 "parser.tab.c"
    break;

  case 100:
#line 284 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 2167 "parser.tab.c"
    break;

  case 101:
#line 285 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 2173 "parser.tab.c"
    break;

  case 102:
#line 286 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 2179 "parser.tab.c"
    break;

  case 103:
#line 287 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 2185 "parser.tab.c"
    break;

  case 104:
#line 288 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 2191 "parser.tab.c"
    break;

  case 105:
#line 289 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '<', (yyvsp[0].astnode_p));}
#line 2197 "parser.tab.c"
    break;

  case 106:
#line 290 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '>', (yyvsp[0].astnode_p));}
#line 2203 "parser.tab.c"
    break;

  case 107:
#line 291 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LTEQ, (yyvsp[0].astnode_p));}
#line 2209 "parser.tab.c"
    break;

  case 108:
#line 292 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), GTEQ, (yyvsp[0].astnode_p));}
#line 2215 "parser.tab.c"
    break;

  case 109:
#line 293 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), EQEQ, (yyvsp[0].astnode_p));}
#line 2221 "parser.tab.c"
    break;

  case 110:
#line 294 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), NOTEQ, (yyvsp[0].astnode_p));}
#line 2227 "parser.tab.c"
    break;

  case 111:
#line 295 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LOGAND, (yyvsp[0].astnode_p));}
#line 2233 "parser.tab.c"
    break;

  case 112:
#line 296 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LOGOR, (yyvsp[0].astnode_p));}
#line 2239 "parser.tab.c"
    break;

  case 113:
#line 297 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary(PLUSPLUS,(yyvsp[-1].astnode_p));}
#line 2245 "parser.tab.c"
    break;

  case 114:
#line 298 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary(MINUSMINUS,(yyvsp[-1].astnode_p));}
#line 2251 "parser.tab.c"
    break;

  case 115:
#line 299 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 2257 "parser.tab.c"
    break;

  case 116:
#line 300 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2263 "parser.tab.c"
    break;

  case 117:
#line 304 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2269 "parser.tab.c"
    break;

  case 118:
#line 307 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2275 "parser.tab.c"
    break;

  case 119:
#line 308 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP, (yyvsp[-3].astnode_p), '+', (yyvsp[-1].astnode_p));
                                                                (yyval.astnode_p)=alloc_unary('*', (yyval.astnode_p));}
#line 2282 "parser.tab.c"
    break;

  case 120:
#line 310 "parser.y"
                                                            {(yyval.astnode_p)=alloc_select((yyvsp[-2].astnode_p), (yyvsp[0].ident));}
#line 2288 "parser.tab.c"
    break;

  case 121:
#line 311 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('*', (yyvsp[-2].astnode_p));
                                                                (yyval.astnode_p)=alloc_select((yyval.astnode_p), (yyvsp[0].ident));}
#line 2295 "parser.tab.c"
    break;

  case 122:
#line 313 "parser.y"
                                                              {(yyval.astnode_p)=alloc_fncall((yyvsp[-2].astnode_p), NULL);}
#line 2301 "parser.tab.c"
    break;

  case 123:
#line 314 "parser.y"
                                                              {(yyval.astnode_p)=alloc_fncall((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 2307 "parser.tab.c"
    break;

  case 124:
#line 323 "parser.y"
                                                {(yyval.astnode_p)=alloc_ident((yyvsp[0].ident));}
#line 2313 "parser.tab.c"
    break;

  case 125:
#line 324 "parser.y"
                                                {(yyval.astnode_p)=alloc_num((yyvsp[0].num).int_num, (yyvsp[0].num).real, (yyvsp[0].num).type, (yyvsp[0].num).sign);}
#line 2319 "parser.tab.c"
    break;

  case 126:
#line 325 "parser.y"
                                                {(yyval.astnode_p)=alloc_charlit((yyvsp[0].charlit));}
#line 2325 "parser.tab.c"
    break;

  case 127:
#line 326 "parser.y"
                                                {(yyval.astnode_p)=alloc_string((yyvsp[0].str).str, (yyvsp[0].str).len);}
#line 2331 "parser.tab.c"
    break;

  case 128:
#line 329 "parser.y"
                                                {(yyval.astnode_p)=alloc_num((yyvsp[0].num).int_num, (yyvsp[0].num).real, (yyvsp[0].num).type, (yyvsp[0].num).sign);}
#line 2337 "parser.tab.c"
    break;

  case 129:
#line 330 "parser.y"
                                                {(yyval.astnode_p)=alloc_charlit((yyvsp[0].charlit));}
#line 2343 "parser.tab.c"
    break;


#line 2347 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 333 "parser.y"
 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s:%d %s\n", filename, lineno, msg);
}

int main(){

    /* creating global symbol table */
    curr_scope = sym_create(SCOPE_GLOBAL);

    yyparse();
    // print_sym(curr_scope);
    return 1;
}
