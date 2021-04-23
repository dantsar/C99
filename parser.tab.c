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
#include "parser.tab.h"

/* stuff from lex */
extern int yylex();
extern char filename[256];
extern int lineno;

/* stuff for symbol table */
SYM_TAB curr_scope;

/* global variable for distinguishing between block and function scopes */
bool in_func = false;

void yyerror(const char*);
void yyerror_die(const char *);


#line 95 "parser.tab.c"

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
#line 26 "parser.y"

    /* for single character tokens */
    int c; 

    /* definition in def.h */
    struct Str str;
    struct Num num;

    char*  ident;
    char   charlit;
    struct astnode *astnode_p; /* definition in ast.h */

#line 226 "parser.tab.c"

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  291

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
       2,     2,     2,    88,    70,    89,    80,     2,     2,     2,
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
       0,    94,    94,    95,    98,    99,   103,   104,   105,   106,
     109,   110,   112,   113,   115,   116,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   138,   139,
     141,   143,   144,   145,   146,   147,   148,   149,   150,   153,
     154,   157,   158,   161,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   188,   191,   192,   196,
     197,   200,   201,   202,   203,   206,   207,   210,   214,   215,
     216,   217,   218,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   237,   238,   242,   248,   249,
     252,   253,   256,   259,   260,   261,   262,   265,   266,   269,
     275,   276,   277,   280,   283,   284,   287,   288,   289,   290,
     292,   297,   301,   305,   306,   307,   308,   311,   312,   315,
     316,   319,   320,   324,   325,   335,   336,   340,   341,   342,
     343,   344,   345,   348,   349,   350,   353,   354,   354,   357,
     358,   361,   362,   365,   368,   369,   370,   373,   374,   375,
     375,   378,   379,   382,   383,   384,   385,   389,   397,   400,
     401
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
  "'{'", "'}'", "$accept", "translation_unit", "extern_declaration",
  "prim_expr", "postfix_expr", "assign_expr", "unary_expr", "cond_expr",
  "expr", "const_expr", "arith_expr", "cast_expr", "declaration",
  "declaration_specs", "declaration_spec", "init_decl_list", "init_decl",
  "stg_class_spec", "type_spec", "struct_union_spec", "struct_union",
  "struct_declaration_list", "struct_declaration", "specific_qualif_list",
  "struct_decl_list", "struct_decl", "type_qualif", "func_spec", "decl",
  "direct_decl", "pointer", "type_qualif_list", "param_type_list",
  "param_list", "param_declaration", "ident_list", "statement",
  "label_stmnt", "compound_stmnt", "$@1", "block_item_list", "block_item",
  "expr_stmnt", "select_stmnt", "iterat_stmnt", "$@2", "expr_opt",
  "jump_stmnt", "func_def", "declaration_list", YY_NULLPTR
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
     126,    33,    40,    41,    46,    91,    93,    59,   123,   125
};
# endif

#define YYPACT_NINF (-235)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1033,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,   898,  -235,  -235,   383,  -235,  -235,  -235,
    -235,    21,  -235,  -235,  -235,  -235,  -235,  -235,   -11,    76,
    -235,  -235,   -47,  -235,   848,   -13,    11,   -61,  1066,  -235,
    -235,   -11,   -52,    76,  -235,   -54,  -235,   383,  -235,   848,
     455,   445,   -13,  1066,  -235,   931,  -235,   564,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   267,  -235,  -235,  -235,  -235,
     525,   -28,   -29,  -235,   -27,  -235,  -235,  -235,  -235,   651,
     651,   626,   651,   651,   651,   651,   651,   651,   639,  -235,
    -235,    41,   -19,   642,  -235,   748,  -235,   964,  -235,  -235,
    -235,   -46,  -235,  -235,  -235,     8,    37,   639,    40,    59,
     329,    56,   154,    82,   639,    91,    92,  -235,   -45,  -235,
    -235,  -235,  -235,   205,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  1000,   173,  -235,  -235,  -235,   651,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   672,   174,   470,   176,   639,
    -235,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,  -235,  -235,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,  -235,    76,  -235,   329,  -235,  -235,   112,
    -235,   329,   123,  -235,    99,   639,   122,   103,   639,   639,
     639,  -235,  -235,  -235,  -235,  -235,  -235,   109,  -235,  -235,
    -235,   -23,  -235,   -40,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   151,   151,   213,   213,   847,
     847,   758,   725,    42,   767,   775,   797,   213,   213,    72,
      72,    75,    75,    75,  -235,  -235,   329,  -235,   113,   639,
    -235,   -21,  -235,    -8,    -5,  -235,  -235,  -235,  -235,   639,
    -235,   639,   107,   329,   329,   329,  -235,    -1,   639,   158,
    -235,  -235,   110,   114,   329,  -235,   639,  -235,   116,   329,
    -235
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,    84,   110,    89,    80,    88,   113,    86,    87,
      82,   111,    85,    90,    79,    98,    81,    99,    91,    83,
     112,    92,    93,     0,     2,     4,     0,    69,    71,    72,
      94,     0,    73,    74,     5,     1,     3,   116,   123,     0,
      67,    70,     0,    75,    77,   114,     0,    97,     0,   127,
     124,   125,     0,     0,    68,   147,   169,     0,   167,     0,
       0,     0,   115,     0,   103,     0,   100,     0,   105,   128,
     126,   117,    76,    77,   146,     0,   170,   168,   135,   121,
     134,     0,   129,   131,     0,     6,     8,     9,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
      10,    28,     0,    66,    27,    39,    65,     0,    95,   101,
     104,     0,   107,   106,   109,     6,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,    41,     0,   151,
     152,   138,   139,     0,   149,   137,   140,   141,   142,   133,
     120,     0,     0,   122,    29,    30,     0,    31,    66,    33,
      35,    36,    34,    37,    38,     0,     0,     0,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,   102,     0,   165,    43,     0,
     164,     0,     0,   159,     0,     0,   161,     0,     0,     0,
       0,   153,   148,   150,   130,   132,   136,     0,    64,    13,
      14,     0,    12,     0,    19,    20,    21,    17,    18,    22,
      23,    24,    26,    25,    16,    53,    52,    56,    57,    58,
      59,    60,    61,     0,    47,    48,    49,    54,    55,    44,
      45,    46,    51,    50,   108,   143,     0,   145,     0,   162,
     163,     0,   166,     0,     0,    42,    32,    15,    11,     0,
     144,     0,     0,     0,     0,     0,    40,     0,   162,   154,
     156,   157,     0,     0,     0,   158,   162,   155,     0,     0,
     160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,   177,  -235,  -235,   -49,   -89,  -106,   -53,  -235,
     -44,    74,   -26,    13,   -10,  -235,   149,  -235,   -33,  -235,
    -235,   140,   -48,  -235,  -235,    10,   124,  -235,   -16,   159,
      25,  -235,  -235,  -235,    66,  -235,   -91,  -235,     9,  -235,
    -235,    79,  -235,  -235,  -235,  -235,  -234,  -235,  -235,  -235
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,   100,   101,   127,   103,   104,   128,   199,
     105,   106,    25,    57,    27,    42,    43,    28,    29,    30,
      31,    65,    66,    67,   111,   112,    32,    33,    73,    45,
      46,    51,    81,    82,    83,    84,   130,   131,   132,    75,
     133,   134,   135,   136,   137,   259,   207,   138,    34,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     144,   145,   147,   148,   148,   148,   148,   148,   148,   148,
      44,   198,   102,    26,    37,    64,    41,   109,    56,    53,
     194,   210,     3,    52,    47,   272,   210,    63,   148,   202,
      64,    71,    64,    76,   110,    74,    26,   141,    11,   142,
      54,   195,   211,   210,   283,   210,   268,    41,   156,   129,
      20,   114,   288,    58,   155,   140,   143,   217,   210,   109,
     267,   210,   273,    50,   139,   210,    38,   160,    77,    60,
      41,   206,    61,    80,    64,   274,    70,   196,   275,    37,
     172,   173,   282,   172,   173,   148,   148,   148,   148,   148,
     148,   148,   148,    39,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   221,   255,   223,   129,   210,    48,
     257,   269,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   157,   197,   158,   159,   200,   201,   243,
     235,   236,   237,   238,   239,   240,   241,   242,   203,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   190,
     191,   192,   261,    38,    80,   263,   264,   204,    39,   172,
     173,   265,    49,   276,   205,   270,   149,   150,   151,   152,
     153,   154,    68,   208,   209,    69,   216,   219,   114,   222,
     148,   256,   279,   280,   281,   258,   260,    68,   210,    68,
     262,   113,   266,   287,   278,   271,   284,   285,   290,   289,
      36,   286,    72,   107,   254,    62,   206,   215,   115,    86,
      87,    88,   213,    89,    90,     0,     0,     0,   277,     0,
       0,   172,   173,   174,   175,   206,   188,   189,   190,   191,
     192,    68,     0,   206,     1,   116,   117,     2,     3,   118,
     119,   120,     4,     0,     0,     5,     6,   121,   122,   123,
       7,     8,     9,    10,    11,   124,    12,    13,    91,    14,
      15,   125,    16,    17,    18,    19,    20,   126,    21,    22,
     115,    86,    87,    88,     0,    89,    90,    92,     0,     0,
      93,    94,    95,     0,     0,    96,    97,    98,   188,   189,
     190,   191,   192,    55,   212,     0,     1,   116,   117,     2,
       3,   118,   119,   120,     4,     0,     0,     5,     6,   121,
     122,   123,     7,     8,     9,    10,    11,   124,    12,    13,
      91,    14,    15,   125,    16,    17,    18,    19,    20,   126,
      21,    22,   115,    86,    87,    88,     0,    89,    90,    92,
       0,     0,    93,    94,    95,     0,     0,    96,    97,    98,
       0,     0,     0,     0,     0,    55,     0,     0,     0,   116,
     117,     0,     0,   118,   119,   120,     0,     0,     0,     0,
       0,   121,   122,   123,     0,     0,     0,     0,     0,   124,
       0,     0,    91,     0,     0,   125,    37,     0,     0,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,    95,     0,     0,    96,
      97,    98,     1,     0,     0,     2,     3,    55,     0,     0,
       4,     0,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,    15,     0,
      16,    17,    18,    19,    20,     0,    21,    22,    85,    86,
      87,    88,     0,    89,    90,     0,     0,     0,    78,     0,
      38,     0,     0,     0,     0,    39,     0,     0,     0,     0,
      40,     0,     0,    85,    86,    87,    88,     0,    89,    90,
       0,     0,     0,     0,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     0,     5,     6,     0,    91,     0,
       7,     8,     9,    10,    11,     0,    12,    13,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    92,    21,    22,
      93,    94,    95,    91,     0,    96,    97,    98,    37,     0,
       0,    99,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,    92,     0,     0,    93,    94,    95,     0,     0,
      96,    97,    98,   220,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     0,     5,     6,    37,     0,     0,
       7,     8,     9,    10,    11,     0,    12,    13,     0,    14,
      15,     0,    16,    17,    18,    19,    20,     0,    21,    22,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     4,    38,     0,     0,     6,     0,    39,     0,     0,
       8,     9,     0,    11,     0,    12,    13,     0,     0,    15,
       0,     0,    17,    18,    19,    20,     0,    21,    22,    85,
      86,    87,    88,     0,    89,    90,     0,     0,     0,     0,
       0,    38,    85,    86,    87,    88,    39,    89,    90,     0,
       0,     0,     0,     0,    85,    86,    87,    88,     0,    89,
      90,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,     0,     0,     0,     0,     0,     0,     0,     0,    91,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,    91,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,    95,    91,     0,    96,    97,   146,   171,
       0,    92,     0,     0,    93,    94,    95,     0,     0,    96,
      97,    98,     0,    92,     0,     0,    93,    94,    95,     0,
       0,    96,    97,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,     0,     0,   218,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   172,   173,   174,   175,
     176,   177,   178,   179,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,   182,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   185,   186,   187,
     188,   189,   190,   191,   192,   172,   173,   174,   175,   176,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   187,   188,   189,   190,   191,   192,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,    35,    12,
      13,     0,    14,    15,     0,    16,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
     186,   187,   188,   189,   190,   191,   192,     1,     0,     0,
       2,     3,     0,     0,     0,     4,    55,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,    15,     0,    16,    17,    18,    19,    20,
       0,    21,    22,     2,     3,     0,     0,     0,     4,     0,
       0,     0,     6,     0,     0,     0,     0,     8,     9,     0,
      11,     0,    12,    13,     0,     0,    15,     0,     0,    17,
      18,    19,    20,     0,    21,    22,     2,     3,     0,     0,
       0,     4,     0,     0,     0,     6,     0,     0,     0,     0,
       8,     9,     0,    11,     0,    12,    13,     0,   214,    15,
     108,     0,    17,    18,    19,    20,     0,    21,    22,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     0,
       5,     6,     0,     0,     0,     7,     8,     9,    10,    11,
       0,    12,    13,   193,    14,    15,     0,    16,    17,    18,
      19,    20,     1,    21,    22,     2,     3,     0,     0,     0,
       4,     0,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,    15,     0,
      16,    17,    18,    19,    20,     0,    21,    22,     2,     3,
       0,     0,     0,     4,     0,     0,     0,     6,     0,     0,
       0,     0,     8,     9,     0,    11,     0,    12,    13,     0,
       0,    15,     0,     0,    17,    18,    19,    20,     0,    21,
      22
};

static const yytype_int16 yycheck[] =
{
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      26,   117,    61,     0,     3,    48,    26,    65,    44,    66,
      66,    66,    33,    39,     3,   259,    66,    88,   117,   120,
      63,    83,    65,    59,    67,    89,    23,    66,    49,    66,
      87,    87,    87,    66,   278,    66,    86,    57,     7,    75,
      61,    67,   286,    44,    98,    83,    83,   146,    66,   107,
      83,    66,    83,    38,    80,    66,    77,    86,    59,    82,
      80,   124,    85,    60,   107,    83,    51,    69,    83,     3,
       8,     9,    83,     8,     9,   174,   175,   176,   177,   178,
     179,   180,   181,    82,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   157,   196,   159,   133,    66,    88,
     201,    69,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    82,    87,    84,    85,    87,    69,   182,
     174,   175,   176,   177,   178,   179,   180,   181,    82,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    77,
      78,    79,   205,    77,   141,   208,   209,     3,    82,     8,
       9,   210,    38,   269,    82,   256,    92,    93,    94,    95,
      96,    97,    48,    82,    82,    51,     3,     3,   194,     3,
     269,    69,   273,   274,   275,    62,    87,    63,    66,    65,
      87,    67,    83,   284,    87,    82,    38,    87,   289,    83,
      23,    87,    53,    63,   194,    46,   259,   141,     3,     4,
       5,     6,   133,     8,     9,    -1,    -1,    -1,   271,    -1,
      -1,     8,     9,    10,    11,   278,    75,    76,    77,    78,
      79,   107,    -1,   286,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       3,     4,     5,     6,    -1,     8,     9,    72,    -1,    -1,
      75,    76,    77,    -1,    -1,    80,    81,    82,    75,    76,
      77,    78,    79,    88,    89,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     3,     4,     5,     6,    -1,     8,     9,    72,
      -1,    -1,    75,    76,    77,    -1,    -1,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    56,     3,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    75,    76,    77,    -1,    -1,    80,
      81,    82,    29,    -1,    -1,    32,    33,    88,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    61,    -1,    63,    64,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,     3,    -1,
      77,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      87,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    40,    41,    -1,    53,    -1,
      45,    46,    47,    48,    49,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    58,    59,    60,    61,    72,    63,    64,
      75,    76,    77,    53,    -1,    80,    81,    82,     3,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    72,    -1,    -1,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    29,    -1,    -1,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    40,    41,     3,    -1,    -1,
      45,    46,    47,    48,    49,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    58,    59,    60,    61,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    37,    77,    -1,    -1,    41,    -1,    82,    -1,    -1,
      46,    47,    -1,    49,    -1,    51,    52,    -1,    -1,    55,
      -1,    -1,    58,    59,    60,    61,    -1,    63,    64,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    77,     3,     4,     5,     6,    82,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    75,    76,    77,    53,    -1,    80,    81,    82,    67,
      -1,    72,    -1,    -1,    75,    76,    77,    -1,    -1,    80,
      81,    82,    -1,    72,    -1,    -1,    75,    76,    77,    -1,
      -1,    80,    81,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    83,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    72,    73,    74,
      75,    76,    77,    78,    79,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,     0,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    61,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    37,    88,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    61,
      -1,    63,    64,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    -1,    -1,    58,
      59,    60,    61,    -1,    63,    64,    32,    33,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    -1,    49,    -1,    51,    52,    -1,    18,    55,
      89,    -1,    58,    59,    60,    61,    -1,    63,    64,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    51,    52,    89,    54,    55,    -1,    57,    58,    59,
      60,    61,    29,    63,    64,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    61,    -1,    63,    64,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    -1,    49,    -1,    51,    52,    -1,
      -1,    55,    -1,    -1,    58,    59,    60,    61,    -1,    63,
      64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    32,    33,    37,    40,    41,    45,    46,    47,
      48,    49,    51,    52,    54,    55,    57,    58,    59,    60,
      61,    63,    64,    91,    92,   102,   103,   104,   107,   108,
     109,   110,   116,   117,   138,     0,    92,     3,    77,    82,
      87,   104,   105,   106,   118,   119,   120,     3,    88,   116,
     120,   121,   118,    66,    87,    88,   102,   103,   128,   139,
      82,    85,   119,    88,   108,   111,   112,   113,   116,   116,
     120,    83,   106,   118,    89,   129,   102,   128,     3,    83,
     103,   122,   123,   124,   125,     3,     4,     5,     6,     8,
       9,    53,    72,    75,    76,    77,    80,    81,    82,    86,
      93,    94,    95,    96,    97,   100,   101,   111,    89,   112,
     108,   114,   115,   116,   118,     3,    30,    31,    34,    35,
      36,    42,    43,    44,    50,    56,    62,    95,    98,   102,
     126,   127,   128,   130,   131,   132,   133,   134,   137,   118,
      83,    66,    66,    83,    96,    96,    82,    96,    96,   101,
     101,   101,   101,   101,   101,   100,     7,    82,    84,    85,
      86,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    67,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    68,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    89,    66,    87,    69,    87,    97,    99,
      87,    69,   126,    82,     3,    82,    98,   136,    82,    82,
      66,    87,    89,   131,    18,   124,     3,    96,    83,     3,
      83,    98,     3,    98,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,   100,   100,   100,   100,   100,
     100,   100,   100,    98,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   115,   126,    69,   126,    62,   135,
      87,    98,    87,    98,    98,    95,    83,    83,    86,    69,
     126,    82,   136,    83,    83,    83,    97,    98,    87,   126,
     126,   126,    83,   136,    38,    87,    87,   126,   136,    83,
     126
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   105,   105,   106,   107,   107,
     107,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   112,   113,   113,   113,   113,   114,   114,   115,
     116,   116,   116,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   128,   129,   128,   130,
     130,   131,   131,   132,   133,   133,   133,   134,   134,   135,
     134,   136,   136,   137,   137,   137,   137,   138,   138,   139,
     139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     4,     2,     2,     2,     2,     2,     2,     1,
       5,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     1,
       1,     2,     3,     1,     2,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     4,     3,
       4,     3,     4,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     0,     4,     1,
       2,     1,     1,     2,     5,     7,     5,     5,     7,     0,
      10,     1,     0,     3,     2,     2,     3,     3,     4,     1,
       2
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
                                                                        {print_sym(curr_scope);}
#line 1796 "parser.tab.c"
    break;

  case 3:
#line 95 "parser.y"
                                                                        {print_sym(curr_scope);}
#line 1802 "parser.tab.c"
    break;

  case 4:
#line 98 "parser.y"
                                                                        {sym_declaration((yyvsp[0].astnode_p), curr_scope);}
#line 1808 "parser.tab.c"
    break;

  case 5:
#line 99 "parser.y"
                                                                        {sym_func_def((yyvsp[0].astnode_p), curr_scope);}
#line 1814 "parser.tab.c"
    break;

  case 6:
#line 103 "parser.y"
                                                    {(yyval.astnode_p)=alloc_ident((yyvsp[0].ident));}
#line 1820 "parser.tab.c"
    break;

  case 7:
#line 104 "parser.y"
                                                    {(yyval.astnode_p)=alloc_num((yyvsp[0].num).int_num, (yyvsp[0].num).real, (yyvsp[0].num).type, (yyvsp[0].num).sign);}
#line 1826 "parser.tab.c"
    break;

  case 8:
#line 105 "parser.y"
                                                    {(yyval.astnode_p)=alloc_charlit((yyvsp[0].charlit));}
#line 1832 "parser.tab.c"
    break;

  case 9:
#line 106 "parser.y"
                                                    {(yyval.astnode_p)=alloc_string((yyvsp[0].str).str, (yyvsp[0].str).len);}
#line 1838 "parser.tab.c"
    break;

  case 10:
#line 109 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1844 "parser.tab.c"
    break;

  case 11:
#line 110 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP, (yyvsp[-3].astnode_p), '+', (yyvsp[-1].astnode_p));
                                                                    (yyval.astnode_p)=alloc_unary('*', (yyval.astnode_p));}
#line 1851 "parser.tab.c"
    break;

  case 12:
#line 112 "parser.y"
                                                                {(yyval.astnode_p)=alloc_select((yyvsp[-2].astnode_p), (yyvsp[0].ident));}
#line 1857 "parser.tab.c"
    break;

  case 13:
#line 113 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('*', (yyvsp[-2].astnode_p));
                                                                    (yyval.astnode_p)=alloc_select((yyval.astnode_p), (yyvsp[0].ident));}
#line 1864 "parser.tab.c"
    break;

  case 14:
#line 115 "parser.y"
                                                                {(yyval.astnode_p)=alloc_fncall((yyvsp[-2].astnode_p), NULL);}
#line 1870 "parser.tab.c"
    break;

  case 15:
#line 116 "parser.y"
                                                                {(yyval.astnode_p)=alloc_fncall((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 1876 "parser.tab.c"
    break;

  case 16:
#line 124 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(ASSIGN, (yyvsp[-2].astnode_p), '=', (yyvsp[0].astnode_p));}
#line 1882 "parser.tab.c"
    break;

  case 17:
#line 125 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 1888 "parser.tab.c"
    break;

  case 18:
#line 126 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 1894 "parser.tab.c"
    break;

  case 19:
#line 127 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 1900 "parser.tab.c"
    break;

  case 20:
#line 128 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 1906 "parser.tab.c"
    break;

  case 21:
#line 129 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 1912 "parser.tab.c"
    break;

  case 22:
#line 130 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 1918 "parser.tab.c"
    break;

  case 23:
#line 131 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 1924 "parser.tab.c"
    break;

  case 24:
#line 132 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 1930 "parser.tab.c"
    break;

  case 25:
#line 133 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 1936 "parser.tab.c"
    break;

  case 26:
#line 134 "parser.y"
                                                                {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 1942 "parser.tab.c"
    break;

  case 27:
#line 135 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1948 "parser.tab.c"
    break;

  case 28:
#line 138 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1954 "parser.tab.c"
    break;

  case 29:
#line 139 "parser.y"
                                                                {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                    (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '+', temp);}
#line 1961 "parser.tab.c"
    break;

  case 30:
#line 141 "parser.y"
                                                                {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                    (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '-', temp);}
#line 1968 "parser.tab.c"
    break;

  case 31:
#line 143 "parser.y"
                                                                {(yyval.astnode_p)=alloc_sizeof((yyvsp[0].astnode_p));}
#line 1974 "parser.tab.c"
    break;

  case 32:
#line 144 "parser.y"
                                                                {(yyval.astnode_p)=alloc_sizeof((yyvsp[-1].astnode_p));}
#line 1980 "parser.tab.c"
    break;

  case 33:
#line 145 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('&',(yyvsp[0].astnode_p));}
#line 1986 "parser.tab.c"
    break;

  case 34:
#line 146 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('*',(yyvsp[0].astnode_p));}
#line 1992 "parser.tab.c"
    break;

  case 35:
#line 147 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('+',(yyvsp[0].astnode_p));}
#line 1998 "parser.tab.c"
    break;

  case 36:
#line 148 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('-',(yyvsp[0].astnode_p));}
#line 2004 "parser.tab.c"
    break;

  case 37:
#line 149 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('~',(yyvsp[0].astnode_p));}
#line 2010 "parser.tab.c"
    break;

  case 38:
#line 150 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary('!',(yyvsp[0].astnode_p));}
#line 2016 "parser.tab.c"
    break;

  case 39:
#line 153 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2022 "parser.tab.c"
    break;

  case 40:
#line 154 "parser.y"
                                                                {(yyval.astnode_p)=alloc_ternary((yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2028 "parser.tab.c"
    break;

  case 41:
#line 157 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2034 "parser.tab.c"
    break;

  case 42:
#line 158 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP, (yyvsp[-2].astnode_p), ',', (yyvsp[0].astnode_p));}
#line 2040 "parser.tab.c"
    break;

  case 43:
#line 161 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2046 "parser.tab.c"
    break;

  case 44:
#line 164 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 2052 "parser.tab.c"
    break;

  case 45:
#line 165 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 2058 "parser.tab.c"
    break;

  case 46:
#line 166 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 2064 "parser.tab.c"
    break;

  case 47:
#line 167 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 2070 "parser.tab.c"
    break;

  case 48:
#line 168 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 2076 "parser.tab.c"
    break;

  case 49:
#line 169 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 2082 "parser.tab.c"
    break;

  case 50:
#line 170 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 2088 "parser.tab.c"
    break;

  case 51:
#line 171 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 2094 "parser.tab.c"
    break;

  case 52:
#line 172 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 2100 "parser.tab.c"
    break;

  case 53:
#line 173 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 2106 "parser.tab.c"
    break;

  case 54:
#line 174 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '<', (yyvsp[0].astnode_p));}
#line 2112 "parser.tab.c"
    break;

  case 55:
#line 175 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '>', (yyvsp[0].astnode_p));}
#line 2118 "parser.tab.c"
    break;

  case 56:
#line 176 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LTEQ, (yyvsp[0].astnode_p));}
#line 2124 "parser.tab.c"
    break;

  case 57:
#line 177 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), GTEQ, (yyvsp[0].astnode_p));}
#line 2130 "parser.tab.c"
    break;

  case 58:
#line 178 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), EQEQ, (yyvsp[0].astnode_p));}
#line 2136 "parser.tab.c"
    break;

  case 59:
#line 179 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), NOTEQ, (yyvsp[0].astnode_p));}
#line 2142 "parser.tab.c"
    break;

  case 60:
#line 180 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LOGAND, (yyvsp[0].astnode_p));}
#line 2148 "parser.tab.c"
    break;

  case 61:
#line 181 "parser.y"
                                                                {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LOGOR, (yyvsp[0].astnode_p));}
#line 2154 "parser.tab.c"
    break;

  case 62:
#line 182 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary(PLUSPLUS,(yyvsp[-1].astnode_p));}
#line 2160 "parser.tab.c"
    break;

  case 63:
#line 183 "parser.y"
                                                                {(yyval.astnode_p)=alloc_unary(MINUSMINUS,(yyvsp[-1].astnode_p));}
#line 2166 "parser.tab.c"
    break;

  case 64:
#line 184 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 2172 "parser.tab.c"
    break;

  case 65:
#line 185 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2178 "parser.tab.c"
    break;

  case 66:
#line 188 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2184 "parser.tab.c"
    break;

  case 67:
#line 191 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_declaration((yyvsp[-1].astnode_p), NULL);}
#line 2190 "parser.tab.c"
    break;

  case 68:
#line 192 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_declaration((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));}
#line 2196 "parser.tab.c"
    break;

  case 69:
#line 196 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2202 "parser.tab.c"
    break;

  case 70:
#line 197 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2208 "parser.tab.c"
    break;

  case 71:
#line 200 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2214 "parser.tab.c"
    break;

  case 72:
#line 201 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2220 "parser.tab.c"
    break;

  case 73:
#line 202 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2226 "parser.tab.c"
    break;

  case 74:
#line 203 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2232 "parser.tab.c"
    break;

  case 75:
#line 206 "parser.y"
                                                                         {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2238 "parser.tab.c"
    break;

  case 76:
#line 207 "parser.y"
                                                                         {(yyval.astnode_p)=(yyvsp[-2].astnode_p); list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 2244 "parser.tab.c"
    break;

  case 77:
#line 210 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2250 "parser.tab.c"
    break;

  case 78:
#line 214 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_AUTO, AST_DECL_STG);    }
#line 2256 "parser.tab.c"
    break;

  case 79:
#line 215 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_STATIC, AST_DECL_STG);  }
#line 2262 "parser.tab.c"
    break;

  case 80:
#line 216 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_EXTERN, AST_DECL_STG);  }
#line 2268 "parser.tab.c"
    break;

  case 81:
#line 217 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_TYPEDEF, AST_DECL_STG); }
#line 2274 "parser.tab.c"
    break;

  case 82:
#line 218 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_REGISTER, AST_DECL_STG);}
#line 2280 "parser.tab.c"
    break;

  case 83:
#line 221 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_VOID, AST_DECL_TYPE_SPEC);    }
#line 2286 "parser.tab.c"
    break;

  case 84:
#line 222 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_CHAR, AST_DECL_TYPE_SPEC);    }
#line 2292 "parser.tab.c"
    break;

  case 85:
#line 223 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_SHORT, AST_DECL_TYPE_SPEC);   }
#line 2298 "parser.tab.c"
    break;

  case 86:
#line 224 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_INT, AST_DECL_TYPE_SPEC);     }
#line 2304 "parser.tab.c"
    break;

  case 87:
#line 225 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_LONG, AST_DECL_TYPE_SPEC);    }
#line 2310 "parser.tab.c"
    break;

  case 88:
#line 226 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_FLOAT, AST_DECL_TYPE_SPEC);   }
#line 2316 "parser.tab.c"
    break;

  case 89:
#line 227 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_DOUBLE, AST_DECL_TYPE_SPEC);  }
#line 2322 "parser.tab.c"
    break;

  case 90:
#line 228 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_SIGNED, AST_DECL_TYPE_SPEC);  }
#line 2328 "parser.tab.c"
    break;

  case 91:
#line 229 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE_UNSIGNED, AST_DECL_TYPE_SPEC);}
#line 2334 "parser.tab.c"
    break;

  case 92:
#line 230 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE__BOOL, AST_DECL_TYPE_SPEC);   }
#line 2340 "parser.tab.c"
    break;

  case 93:
#line 231 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_decl_spec(TYPE__COMPLEX, AST_DECL_TYPE_SPEC);}
#line 2346 "parser.tab.c"
    break;

  case 94:
#line 232 "parser.y"
                                                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2352 "parser.tab.c"
    break;

  case 95:
#line 237 "parser.y"
                                                                                {(yyval.astnode_p)=(yyvsp[-3].astnode_p); sym_struct_define((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 2358 "parser.tab.c"
    break;

  case 96:
#line 238 "parser.y"
                                                                                {(yyval.astnode_p)=(yyvsp[-4].astnode_p); 
                                                                                 sym_struct_define((yyvsp[-4].astnode_p), (yyvsp[-1].astnode_p));
                                                                                 sym_struct_declare((yyvsp[-3].ident), (yyvsp[-4].astnode_p), curr_scope);
                                                                                }
#line 2367 "parser.tab.c"
    break;

  case 97:
#line 242 "parser.y"
                                                                                { /* either a forward declartion or getting the type (I will be ignoring/not handling forward declarations) */
                                                                                  SYM_ENT temp = alloc_sym_ent((yyvsp[0].ident), ENT_SU_TAG, NS_SU);
                                                                                  (yyval.astnode_p) = (temp = sym_lookup(curr_scope, temp)) ? temp->su_tag.st_un : (yyvsp[-1].astnode_p);
                                                                                }
#line 2376 "parser.tab.c"
    break;

  case 98:
#line 248 "parser.y"
                                {(yyval.astnode_p)=alloc_st_un(AST_STRUCT, curr_scope->scope_type);}
#line 2382 "parser.tab.c"
    break;

  case 99:
#line 249 "parser.y"
                                {(yyval.astnode_p)=alloc_st_un(AST_UNION, curr_scope->scope_type);}
#line 2388 "parser.tab.c"
    break;

  case 100:
#line 252 "parser.y"
                                                                            {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2394 "parser.tab.c"
    break;

  case 101:
#line 253 "parser.y"
                                                                            {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2400 "parser.tab.c"
    break;

  case 102:
#line 256 "parser.y"
                                                                        {(yyval.astnode_p)=alloc_declaration((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));}
#line 2406 "parser.tab.c"
    break;

  case 103:
#line 259 "parser.y"
                                                            {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2412 "parser.tab.c"
    break;

  case 104:
#line 260 "parser.y"
                                                            {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2418 "parser.tab.c"
    break;

  case 105:
#line 261 "parser.y"
                                                            {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2424 "parser.tab.c"
    break;

  case 106:
#line 262 "parser.y"
                                                            {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2430 "parser.tab.c"
    break;

  case 107:
#line 265 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2436 "parser.tab.c"
    break;

  case 108:
#line 266 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 2442 "parser.tab.c"
    break;

  case 109:
#line 269 "parser.y"
                                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2448 "parser.tab.c"
    break;

  case 110:
#line 275 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_CONST, AST_DECL_TYPE_QUALIF);}
#line 2454 "parser.tab.c"
    break;

  case 111:
#line 276 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_RESTRICT, AST_DECL_TYPE_QUALIF);}
#line 2460 "parser.tab.c"
    break;

  case 112:
#line 277 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_VOLATILE, AST_DECL_TYPE_QUALIF);}
#line 2466 "parser.tab.c"
    break;

  case 113:
#line 280 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(FUNC_INLINE, AST_DECL_FUNC_SPEC);}
#line 2472 "parser.tab.c"
    break;

  case 114:
#line 283 "parser.y"
                                                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2478 "parser.tab.c"
    break;

  case 115:
#line 284 "parser.y"
                                                                    {(yyval.astnode_p)=list_append((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2484 "parser.tab.c"
    break;

  case 116:
#line 287 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_list(alloc_ident((yyvsp[0].ident)));}
#line 2490 "parser.tab.c"
    break;

  case 117:
#line 288 "parser.y"
                                                                    {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 2496 "parser.tab.c"
    break;

  case 118:
#line 289 "parser.y"
                                                                       {(yyval.astnode_p)=list_append_elem(alloc_array(NULL,(yyvsp[-1].astnode_p)), (yyvsp[-3].astnode_p));}
#line 2502 "parser.tab.c"
    break;

  case 119:
#line 290 "parser.y"
                                                                    {yyerror_die("not supporting variable length arrays");}
#line 2508 "parser.tab.c"
    break;

  case 120:
#line 292 "parser.y"
                                                                    { /* replace the first element(IDENT) with a ast_func */
                                                                     (yyval.astnode_p)=alloc_list(alloc_func((yyvsp[-3].astnode_p)->list.elem, (yyvsp[-1].astnode_p)));
                                                                     (yyval.astnode_p)->list.next = (yyvsp[-3].astnode_p)->list.next;
                                                                     free((yyvsp[-3].astnode_p)); /* SOME semblance of memory managment :^) */
                                                                    }
#line 2518 "parser.tab.c"
    break;

  case 121:
#line 297 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_list(alloc_func((yyvsp[-2].astnode_p)->list.elem, NULL));
                                                                     (yyval.astnode_p)->list.next = (yyvsp[-2].astnode_p)->list.next;
                                                                     free((yyvsp[-2].astnode_p)); /* SOME semblance of memory managment :^) */
                                                                    }
#line 2527 "parser.tab.c"
    break;

  case 122:
#line 301 "parser.y"
                                                                    {yyerror_die("Not supporting old c style function definitons :'(");}
#line 2533 "parser.tab.c"
    break;

  case 123:
#line 305 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_list(alloc_ptr(NULL));}
#line 2539 "parser.tab.c"
    break;

  case 124:
#line 306 "parser.y"
                                                                    {(yyval.astnode_p)=list_append_elem(alloc_ptr(NULL), (yyvsp[0].astnode_p));}
#line 2545 "parser.tab.c"
    break;

  case 125:
#line 307 "parser.y"
                                                                    {(yyval.astnode_p)=alloc_list(alloc_ptr(NULL));}
#line 2551 "parser.tab.c"
    break;

  case 126:
#line 308 "parser.y"
                                                                    {(yyval.astnode_p)=list_append_elem(alloc_ptr(NULL), (yyvsp[0].astnode_p));}
#line 2557 "parser.tab.c"
    break;

  case 129:
#line 315 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2563 "parser.tab.c"
    break;

  case 130:
#line 316 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[-2].astnode_p);}
#line 2569 "parser.tab.c"
    break;

  case 131:
#line 319 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2575 "parser.tab.c"
    break;

  case 132:
#line 320 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 2581 "parser.tab.c"
    break;

  case 133:
#line 324 "parser.y"
                                                                {(yyval.astnode_p)=alloc_declaration((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2587 "parser.tab.c"
    break;

  case 134:
#line 325 "parser.y"
                                                                {(yyval.astnode_p)=list_last((yyvsp[0].astnode_p)); /* KLUDGE!!! -_- there is a bug! can you see it?? */
                                                                 if((yyval.astnode_p)->list.elem->type == AST_DECL_SPEC){
                                                                     if((yyval.astnode_p)->list.elem->decl_spec.decl_spec == TYPE_VOID)
                                                                        (yyval.astnode_p)=alloc_declaration((yyvsp[0].astnode_p), NULL);
                                                                 }else{ 
                                                                     yyerror_die("incomplete function definition"); 
                                                                 }
                                                                }
#line 2600 "parser.tab.c"
    break;

  case 135:
#line 335 "parser.y"
                                                    {(yyval.astnode_p)=alloc_list(alloc_ident((yyvsp[0].ident)));}
#line 2606 "parser.tab.c"
    break;

  case 136:
#line 336 "parser.y"
                                                    {(yyval.astnode_p)=list_append_elem(alloc_ident((yyvsp[0].ident)), (yyvsp[-2].astnode_p));}
#line 2612 "parser.tab.c"
    break;

  case 137:
#line 340 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2618 "parser.tab.c"
    break;

  case 138:
#line 341 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2624 "parser.tab.c"
    break;

  case 139:
#line 342 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2630 "parser.tab.c"
    break;

  case 140:
#line 343 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2636 "parser.tab.c"
    break;

  case 141:
#line 344 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2642 "parser.tab.c"
    break;

  case 142:
#line 345 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2648 "parser.tab.c"
    break;

  case 143:
#line 348 "parser.y"
                                                                {(yyval.astnode_p)=alloc_label_stmnt(AST_LABEL, (yyvsp[0].astnode_p), (yyvsp[-2].ident), NULL);}
#line 2654 "parser.tab.c"
    break;

  case 144:
#line 349 "parser.y"
                                                                {(yyval.astnode_p)=alloc_label_stmnt(AST_LABEL_CASE, (yyvsp[0].astnode_p), NULL, (yyvsp[-2].astnode_p));}
#line 2660 "parser.tab.c"
    break;

  case 145:
#line 350 "parser.y"
                                                                {(yyval.astnode_p)=alloc_label_stmnt(AST_LABEL_DEFAULT, (yyvsp[0].astnode_p), NULL, NULL);}
#line 2666 "parser.tab.c"
    break;

  case 146:
#line 353 "parser.y"
                                                {(yyval.astnode_p)=alloc_compound(NULL, NULL);}
#line 2672 "parser.tab.c"
    break;

  case 147:
#line 354 "parser.y"
                          {curr_scope=sym_tab_push(SCOPE_BLOCK, curr_scope);}
#line 2678 "parser.tab.c"
    break;

  case 148:
#line 354 "parser.y"
                                                                                                     {(yyval.astnode_p)=alloc_compound((yyvsp[-1].astnode_p), curr_scope); curr_scope=sym_tab_pop(curr_scope);}
#line 2684 "parser.tab.c"
    break;

  case 149:
#line 357 "parser.y"
                                                    {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2690 "parser.tab.c"
    break;

  case 150:
#line 358 "parser.y"
                                                    {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2696 "parser.tab.c"
    break;

  case 151:
#line 361 "parser.y"
                                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p); sym_declaration((yyvsp[0].astnode_p), curr_scope);}
#line 2702 "parser.tab.c"
    break;

  case 152:
#line 362 "parser.y"
                                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2708 "parser.tab.c"
    break;

  case 153:
#line 365 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 2714 "parser.tab.c"
    break;

  case 154:
#line 368 "parser.y"
                                                                {(yyval.astnode_p)=alloc_select_stmnt(AST_IF_STMNT, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p), NULL);}
#line 2720 "parser.tab.c"
    break;

  case 155:
#line 369 "parser.y"
                                                                {(yyval.astnode_p)=alloc_select_stmnt(AST_IF_STMNT, (yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2726 "parser.tab.c"
    break;

  case 156:
#line 370 "parser.y"
                                                                {(yyval.astnode_p)=alloc_select_stmnt(AST_SWITCH_STMNT, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p), NULL);}
#line 2732 "parser.tab.c"
    break;

  case 157:
#line 373 "parser.y"
                                                                               {(yyval.astnode_p)=alloc_iterat_stmnt(AST_WHILE_STMNT, (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p), NULL, NULL);}
#line 2738 "parser.tab.c"
    break;

  case 158:
#line 374 "parser.y"
                                                                               {(yyval.astnode_p)=alloc_iterat_stmnt(AST_DO_STMNT, (yyvsp[-2].astnode_p), (yyvsp[-5].astnode_p), NULL, NULL);}
#line 2744 "parser.tab.c"
    break;

  case 159:
#line 375 "parser.y"
                              {curr_scope=sym_tab_push(SCOPE_BLOCK, curr_scope);}
#line 2750 "parser.tab.c"
    break;

  case 160:
#line 375 "parser.y"
                                                                                                                                   {(yyval.astnode_p)=alloc_iterat_stmnt(AST_FOR_STMNT, (yyvsp[-4].astnode_p), (yyvsp[0].astnode_p), (yyvsp[-6].astnode_p), (yyvsp[-2].astnode_p)); curr_scope=sym_tab_pop(curr_scope);}
#line 2756 "parser.tab.c"
    break;

  case 161:
#line 378 "parser.y"
                                      {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2762 "parser.tab.c"
    break;

  case 162:
#line 379 "parser.y"
                                        {(yyval.astnode_p)=NULL;}
#line 2768 "parser.tab.c"
    break;

  case 163:
#line 382 "parser.y"
                                                            {(yyval.astnode_p)=alloc_jump_stmnt(AST_GOTO, (yyvsp[-1].ident), NULL);}
#line 2774 "parser.tab.c"
    break;

  case 164:
#line 383 "parser.y"
                                                            {(yyval.astnode_p)=alloc_jump_stmnt(AST_CONTINUE, NULL, NULL);}
#line 2780 "parser.tab.c"
    break;

  case 165:
#line 384 "parser.y"
                                                            {(yyval.astnode_p)=alloc_jump_stmnt(AST_BREAK, NULL, NULL);}
#line 2786 "parser.tab.c"
    break;

  case 166:
#line 385 "parser.y"
                                                            {(yyval.astnode_p)=alloc_jump_stmnt(AST_RETURN, NULL, (yyvsp[-1].astnode_p));}
#line 2792 "parser.tab.c"
    break;

  case 167:
#line 389 "parser.y"
                                                                                 { /* populate astnode with elements */
                                                                                    (yyval.astnode_p)=(yyvsp[-1].astnode_p)->list.elem; /* first element is astnode_func */
                                                                                    (yyval.astnode_p)->func.ret = list_append((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));
                                                                                    (yyval.astnode_p)->func.ret = (yyval.astnode_p)->func.ret->list.next;
                                                                                    (yyval.astnode_p)->func.block = (yyvsp[0].astnode_p);
                                                                                    (yyval.astnode_p)->func.block->comp.tab->scope_type = SCOPE_FUNC;
                                                                                    free((yyvsp[-1].astnode_p));
                                                                                }
#line 2805 "parser.tab.c"
    break;

  case 168:
#line 397 "parser.y"
                                                                                {yyerror_die("not handling old c style function definitions :'(");}
#line 2811 "parser.tab.c"
    break;


#line 2815 "parser.tab.c"

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
#line 403 "parser.y"
 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s:%d %s\n", filename, lineno, msg);
}
void yyerror_die(const char *msg){
    yyerror(msg);
    exit(-1);
}

int main(){
    /* creating global symbol table */
    curr_scope = sym_tab_create(SCOPE_GLOBAL);

    yyparse();
    return 1;
}
