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
#define YYLAST   1211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

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
       0,    99,    99,   100,   103,   104,   108,   109,   113,   114,
     116,   117,   118,   119,   122,   123,   124,   125,   126,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   146,   147,   148,   150,   153,   154,   158,   163,   164,
     167,   168,   171,   174,   175,   176,   177,   180,   181,   184,
     190,   191,   194,   195,   198,   199,   202,   205,   206,   209,
     210,   211,   212,   214,   219,   220,   224,   225,   226,   227,
     230,   231,   234,   235,   238,   239,   258,   265,   267,   268,
     271,   272,   272,   275,   276,   279,   280,   283,   284,   293,
     294,   295,   296,   297,   298,   301,   303,   304,   305,   308,
     309,   310,   313,   314,   315,   316,   318,   319,   322,   323,
     324,   325,   328,   329,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   346,   347,   349,   351,
     352,   353,   354,   355,   356,   357,   358,   361,   364,   365,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   393,   396,   397,   399,   400,   402,   403,   412,
     413,   414,   415,   418,   419
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
  "declaration", "declaration_specs", "declaration_spec", "stg_class_spec",
  "type_spec", "type_qualif", "func_spec", "struct_union_spec",
  "struct_union", "struct_declaration_list", "struct_declaration",
  "specific_qualif_list", "struct_decl_list", "struct_decl",
  "type_qualif_list", "init_decl_list", "init_decl", "init", "decl",
  "direct_decl", "pointer", "param_type_list", "param_list",
  "param_declaration", "func_def", "declaration_list", "compound_stmnt",
  "$@1", "block_item_list", "block_item", "ident_list", "statement",
  "expr_stmnt", "label_stmnt", "select_stmnt", "iterat_stmnt", "expr_opt",
  "jump_stmnt", "expr", "assign_expr", "unary_expr", "const_expr",
  "cond_expr", "arith_expr", "cast_expr", "postfix_expr", "prim_expr",
  "constant", YY_NULLPTR
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

#define YYPACT_NINF (-226)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1114,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,   901,  -226,  -226,   413,  -226,  -226,  -226,
    -226,  -226,  -226,     3,  -226,  -226,  -226,  -226,    93,    38,
    -226,  -226,   -50,  -226,   934,   -68,    42,   -76,  1147,  -226,
      93,  -226,   -70,    38,  -226,   596,   -42,  -226,   413,   978,
    -226,   472,     4,   -68,  1147,  1147,  1147,  1012,  -226,    38,
    -226,  -226,  -226,  -226,   -46,  -226,  -226,  -226,  -226,   676,
     676,   655,   676,   676,   676,   676,   676,   676,   596,  -226,
    -226,   667,  -226,   796,  -226,    43,  -226,  -226,   242,  -226,
    -226,  -226,  -226,   593,   -32,    -9,  -226,   -61,  -226,  -226,
    -226,    51,  1045,  -226,  -226,  -226,  -226,   -48,  -226,  -226,
    -226,  -226,   676,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,   688,   596,   596,   596,   596,   596,   596,   596,   596,
     596,   596,   596,  -226,  -226,   596,   596,   596,   596,   596,
     596,   596,   596,   596,   596,   596,   596,   596,   596,   596,
     596,   596,   596,   596,   145,   347,   147,   596,    83,    73,
     596,    74,    97,   359,    80,   162,    85,   596,    86,    89,
    -226,  -226,   180,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
     -47,  -226,  -226,  -226,  1081,   166,  -226,  -226,  -226,    38,
    -226,    90,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,    -5,    -5,    56,    56,   837,   837,
     474,   784,   -13,   813,   821,   829,    56,    56,   103,   103,
      68,    68,    68,  -226,  -226,   -22,  -226,   -24,   359,  -226,
     105,  -226,  -226,   359,   114,   534,    91,   596,    92,   111,
     596,   596,  -226,  -226,   596,  -226,  -226,  -226,  -226,  -226,
    -226,   596,  -226,  -226,  -226,   359,  -226,   109,   596,   100,
    -226,    -8,  -226,    63,    64,  -226,  -226,  -226,   596,   106,
     596,   304,   359,   359,    70,   596,   107,   359,  -226,  -226,
    -226,   108,   115,   596,  -226,  -226,   359,   116,  -226,   359,
    -226
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    20,    31,    25,    16,    24,    34,    22,    23,
      18,    32,    21,    26,    15,    38,    17,    39,    27,    19,
      33,    28,    29,     0,     2,     4,     0,     8,    10,    11,
      12,    13,    30,     0,     5,     1,     3,    59,    66,     0,
       6,     9,     0,    52,    54,    57,     0,    37,     0,    50,
      68,    67,     0,     0,     7,     0,    81,    78,     0,     0,
      76,     0,     0,    58,     0,    43,    45,     0,    40,     0,
      51,    69,    60,    53,    54,   169,   171,   172,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,   162,   125,   138,   161,   126,   163,    80,     0,    79,
      77,    87,    65,    75,     0,    70,    72,     0,   174,   173,
      62,     0,     0,    44,    46,    35,    41,     0,    47,    49,
     127,   128,     0,   129,   162,   131,   133,   134,   132,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
      85,    91,     0,    83,    86,    89,    90,    92,    93,    94,
       0,   112,    74,    63,     0,     0,    64,    61,    36,     0,
      42,     0,   160,   117,   118,   119,   115,   116,   120,   121,
     122,   124,   123,   114,   149,   148,   152,   153,   154,   155,
     156,   157,     0,   143,   144,   145,   150,   151,   140,   141,
     142,   147,   146,   166,   167,     0,   165,     0,     0,   110,
       0,   137,   109,     0,     0,   107,     0,     0,     0,   106,
       0,     0,    82,    84,     0,    95,    71,    73,    88,    48,
     130,     0,   168,   164,    96,     0,    98,     0,   107,     0,
     108,     0,   111,     0,     0,   113,   139,    97,     0,     0,
     107,     0,     0,     0,     0,   107,     0,     0,    99,   101,
     102,     0,     0,   107,   100,   103,     0,     0,   105,     0,
     104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,   169,   -44,     2,    87,  -226,   340,   753,  -226,
    -226,  -226,   133,   -60,    78,  -226,    19,  -226,  -226,   196,
    -226,    20,   207,   -27,  -226,  -226,    60,  -226,  -226,    96,
    -226,  -226,    76,  -226,  -124,  -226,  -226,  -226,  -226,  -225,
    -226,  -129,   -54,   -53,  -226,  -161,   627,   120,  -226,  -226,
    -226
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    58,    27,    28,    29,    30,    31,
      32,    33,    67,    68,    69,   117,   118,    50,    42,    43,
      89,    74,    45,    46,   104,   105,   106,    34,    59,   181,
      98,   182,   183,   107,   184,   185,   186,   187,   188,   248,
     189,   190,   191,    91,   240,    92,    93,    94,    95,    96,
     111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    90,    26,   143,   144,   195,    47,   116,   108,   241,
     109,    51,    64,    72,    61,    99,    53,    62,   199,   254,
     269,    55,   196,    71,   222,    26,   120,   121,   123,   124,
     124,   124,   124,   124,   124,   124,   235,    54,   237,   200,
     255,    37,   254,   279,   254,    37,    44,    97,   249,   244,
     164,   193,   116,   254,   180,   286,   261,   194,   254,    52,
     292,   262,   263,   103,   143,   144,   145,   146,   297,   201,
     159,   160,   161,   162,   163,   281,   143,   144,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   119,
     110,    48,   124,   124,   124,   124,   124,   124,   124,   124,
     276,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   143,   144,    41,   264,    38,   249,   124,   271,   266,
      39,   273,   274,   192,    39,   165,     3,   166,   167,   254,
     254,   159,   160,   161,   162,   163,   254,   197,   180,   249,
      60,   277,    11,   113,   114,    41,   282,   283,   233,   284,
     236,   249,   238,   291,    20,   100,   249,   288,   289,   290,
     239,   242,   245,   294,   249,   246,   243,   247,   250,   258,
      38,   251,   298,   260,   265,   300,   267,   254,   270,   272,
     161,   162,   163,   168,    76,    77,    78,   280,    79,    80,
      41,   278,    36,   285,   293,   295,   103,   112,   296,   299,
     275,   268,   125,   126,   127,   128,   129,   130,   124,     1,
     169,   170,     2,     3,   171,   172,   173,     4,   259,   119,
       5,     6,   174,   175,   176,     7,     8,     9,    10,    11,
     177,    12,    13,    81,    14,    15,   178,    16,    17,    18,
      19,    20,   179,    21,    22,   168,    76,    77,    78,    73,
      79,    80,    82,    63,   257,    83,    84,    85,   253,     0,
      86,    87,    88,     0,     0,     0,     0,     0,    56,   252,
       0,     1,   169,   170,     2,     3,   171,   172,   173,     4,
       0,     0,     5,     6,   174,   175,   176,     7,     8,     9,
      10,    11,   177,    12,    13,    81,    14,    15,   178,    16,
      17,    18,    19,    20,   179,    21,    22,   168,    76,    77,
      78,     0,    79,    80,    82,     0,     0,    83,    84,    85,
       0,     0,    86,    87,    88,     0,     0,     0,     0,     0,
      56,     0,     0,     0,   169,   170,     0,     0,   171,   172,
     173,     0,   287,     0,     0,     0,   174,   175,   176,     0,
      75,    76,    77,    78,   177,    79,    80,    81,     0,     0,
     178,     0,   168,    76,    77,    78,   179,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,    83,
      84,    85,     0,     0,    86,    87,    88,     0,    65,   169,
     170,     0,    56,   171,   172,   173,     0,     0,     0,     0,
      81,   174,   175,   176,    65,    65,    65,    65,     0,   177,
       0,     0,    81,     0,     0,   178,    37,     0,     0,    82,
       0,   179,    83,    84,    85,     0,     0,    86,    87,    88,
     234,    82,     0,     0,    83,    84,    85,     0,     0,    86,
      87,    88,     1,     0,     0,     2,     3,    56,     0,     0,
       4,     0,    65,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,    15,     0,
      16,    17,    18,    19,    20,   101,    21,    22,     0,     0,
       0,     0,   143,   144,   145,   146,   147,   148,   149,   150,
      38,     0,     0,     0,     0,    39,     0,     0,     0,     0,
      40,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,     0,    12,    13,     0,    14,    15,     0,    16,
      17,    18,    19,    20,     0,    21,    22,    75,    76,    77,
      78,     0,    79,    80,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       8,     9,    10,    11,     0,    12,    13,    81,    14,    15,
       0,    16,    17,    18,    19,    20,    37,    21,    22,    75,
      76,    77,    78,     0,    79,    80,    82,     0,     0,    83,
      84,    85,     0,     0,    86,    87,    88,     0,     0,     0,
       0,     0,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,    15,    81,
      16,    17,    18,    19,    20,     0,    21,    22,    75,    76,
      77,    78,     0,    79,    80,     0,     0,     0,    82,     0,
      38,    83,    84,    85,     0,    39,    86,    87,    88,    75,
      76,    77,    78,     0,    79,    80,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,    81,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    81,
      83,    84,    85,     0,   142,    86,    87,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,    83,    84,    85,     0,     0,    86,    87,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,   202,   214,   215,   216,   217,   218,   219,   220,   221,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    49,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    66,     0,    70,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,    66,    66,    66,
      66,   143,   144,   145,   146,   147,   148,   149,   150,   143,
     144,   145,   146,   147,   148,   149,   150,   143,   144,   145,
     146,   147,   148,   149,   150,   143,   144,   145,   146,   147,
     148,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   153,    66,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   156,   157,   158,   159,   160,   161,   162,
     163,    35,   157,   158,   159,   160,   161,   162,   163,     0,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,     0,    12,    13,     0,    14,    15,     0,    16,    17,
      18,    19,    20,     1,    21,    22,     2,     3,     0,     0,
       0,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       8,     9,    10,    11,     0,    12,    13,     0,    14,    15,
       0,    16,    17,    18,    19,    20,     0,    21,    22,     0,
       0,    55,     0,     0,     0,     0,     0,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     0,     5,     6,
       0,     0,    56,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,    15,     0,    16,    17,    18,    19,    20,
       0,    21,    22,     0,     2,     3,     0,     0,     0,     4,
       0,     0,     0,     6,     0,     0,     0,     0,     8,     9,
       0,    11,     0,    12,    13,     0,    56,    15,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     2,     3,     0,
       0,     0,     4,     0,     0,     0,     6,     0,     0,     0,
       0,     8,     9,     0,    11,     0,    12,    13,     0,   256,
      15,   115,     0,    17,    18,    19,    20,     0,    21,    22,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,     0,    12,    13,   198,    14,    15,     0,    16,    17,
      18,    19,    20,     1,    21,    22,     2,     3,     0,     0,
       0,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       8,     9,    10,    11,     0,    12,    13,     0,    14,    15,
       0,    16,    17,    18,    19,    20,     0,    21,    22,     2,
       3,     0,     0,     0,     4,     0,     0,     0,     6,     0,
       0,     0,     0,     8,     9,     0,    11,     0,    12,    13,
       0,     0,    15,     0,     0,    17,    18,    19,    20,     0,
      21,    22
};

static const yytype_int16 yycheck[] =
{
      44,    55,     0,     8,     9,    66,     3,    67,     4,   170,
       6,    38,    88,    83,    82,    59,    66,    85,    66,    66,
     245,    67,    83,    50,   153,    23,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   165,    87,   167,    87,
      87,     3,    66,   268,    66,     3,    26,    89,   177,   173,
       7,    83,   112,    66,    98,   280,    69,    66,    66,    39,
     285,    83,    86,    61,     8,     9,    10,    11,   293,   122,
      75,    76,    77,    78,    79,    83,     8,     9,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    69,
      86,    88,   145,   146,   147,   148,   149,   150,   151,   152,
     261,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     8,     9,    26,   238,    77,   245,   170,   247,   243,
      82,   250,   251,   103,    82,    82,    33,    84,    85,    66,
      66,    75,    76,    77,    78,    79,    66,    86,   182,   268,
      44,   265,    49,    65,    66,    58,    83,    83,     3,   278,
       3,   280,    69,    83,    61,    59,   285,   281,   282,   283,
      87,    87,    82,   287,   293,     3,    69,    82,    82,     3,
      77,    82,   296,    83,    69,   299,    62,    66,    87,    87,
      77,    78,    79,     3,     4,     5,     6,    87,     8,     9,
     103,    82,    23,    87,    87,    87,   194,    64,    83,    83,
     254,   245,    82,    83,    84,    85,    86,    87,   261,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   199,   199,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     3,     4,     5,     6,    53,
       8,     9,    72,    46,   194,    75,    76,    77,   182,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     3,     4,     5,
       6,    -1,     8,     9,    72,    -1,    -1,    75,    76,    77,
      -1,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    -1,
       3,     4,     5,     6,    50,     8,     9,    53,    -1,    -1,
      56,    -1,     3,     4,     5,     6,    62,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    75,
      76,    77,    -1,    -1,    80,    81,    82,    -1,    48,    30,
      31,    -1,    88,    34,    35,    36,    -1,    -1,    -1,    -1,
      53,    42,    43,    44,    64,    65,    66,    67,    -1,    50,
      -1,    -1,    53,    -1,    -1,    56,     3,    -1,    -1,    72,
      -1,    62,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    72,    -1,    -1,    75,    76,    77,    -1,    -1,    80,
      81,    82,    29,    -1,    -1,    32,    33,    88,    -1,    -1,
      37,    -1,   112,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    61,     3,    63,    64,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      77,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      87,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,
      -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    61,    -1,    63,    64,     3,     4,     5,
       6,    -1,     8,     9,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,     3,    63,    64,     3,
       4,     5,     6,    -1,     8,     9,    72,    -1,    -1,    75,
      76,    77,    -1,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    51,    52,    -1,    54,    55,    53,
      57,    58,    59,    60,    61,    -1,    63,    64,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    72,    -1,
      77,    75,    76,    77,    -1,    82,    80,    81,    82,     3,
       4,     5,     6,    -1,     8,     9,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    53,
      75,    76,    77,    -1,    67,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    75,    76,    77,    -1,    -1,    80,    81,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    83,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    38,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    48,    -1,    50,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    64,    65,    66,
      67,     8,     9,    10,    11,    12,    13,    14,    15,     8,
       9,    10,    11,    12,    13,    14,    15,     8,     9,    10,
      11,    12,    13,    14,    15,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    68,   112,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    73,    74,    75,    76,    77,    78,    79,    -1,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    -1,    51,    52,    -1,    54,    55,    -1,    57,    58,
      59,    60,    61,    29,    63,    64,    32,    33,    -1,    -1,
      -1,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    -1,    63,    64,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      -1,    -1,    88,    45,    46,    47,    48,    49,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    61,
      -1,    63,    64,    -1,    32,    33,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,
      -1,    49,    -1,    51,    52,    -1,    88,    55,    -1,    -1,
      58,    59,    60,    61,    -1,    63,    64,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    46,    47,    -1,    49,    -1,    51,    52,    -1,    18,
      55,    89,    -1,    58,    59,    60,    61,    -1,    63,    64,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    -1,    51,    52,    89,    54,    55,    -1,    57,    58,
      59,    60,    61,    29,    63,    64,    32,    33,    -1,    -1,
      -1,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    61,    -1,    63,    64,    32,
      33,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    -1,    49,    -1,    51,    52,
      -1,    -1,    55,    -1,    -1,    58,    59,    60,    61,    -1,
      63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    32,    33,    37,    40,    41,    45,    46,    47,
      48,    49,    51,    52,    54,    55,    57,    58,    59,    60,
      61,    63,    64,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   117,     0,    92,     3,    77,    82,
      87,    95,   108,   109,   111,   112,   113,     3,    88,    98,
     107,   113,   111,    66,    87,    67,    88,    93,    94,   118,
     119,    82,    85,   112,    88,    97,    98,   102,   103,   104,
      98,   113,    83,   109,   111,     3,     4,     5,     6,     8,
       9,    53,    72,    75,    76,    77,    80,    81,    82,   110,
     132,   133,   135,   136,   137,   138,   139,    89,   120,    93,
     119,     3,    83,    94,   114,   115,   116,   123,     4,     6,
      86,   140,   102,   104,   104,    89,   103,   105,   106,   111,
     133,   133,    82,   133,   133,   137,   137,   137,   137,   137,
     137,   136,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    67,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    68,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     7,    82,    84,    85,     3,    30,
      31,    34,    35,    36,    42,    43,    44,    50,    56,    62,
      93,   119,   121,   122,   124,   125,   126,   127,   128,   130,
     131,   132,   111,    83,    66,    66,    83,    86,    89,    66,
      87,   133,    83,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   136,   136,   136,   136,   136,   136,
     136,   136,   131,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,     3,    83,   131,     3,   131,    69,    87,
     134,   135,    87,    69,   124,    82,     3,    82,   129,   131,
      82,    82,    89,   122,    66,    87,    18,   116,     3,   106,
      83,    69,    83,    86,   124,    69,   124,    62,    93,   129,
      87,   131,    87,   131,   131,   132,   135,   124,    82,   129,
      87,    83,    83,    83,   131,    87,   129,    38,   124,   124,
     124,    83,   129,    87,   124,    87,    83,   129,   124,    83,
     124
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    99,   100,   100,   100,   101,   101,
     102,   102,   103,   104,   104,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   109,   109,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   120,   119,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   125,   126,   126,   126,   127,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   138,   138,   138,   138,   138,   138,   139,
     139,   139,   139,   140,   140
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     1,
       1,     2,     3,     1,     2,     1,     2,     1,     3,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     2,     1,
       3,     4,     3,     4,     4,     3,     1,     2,     2,     3,
       1,     3,     1,     3,     2,     1,     3,     4,     1,     2,
       2,     0,     4,     1,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     5,
       6,     5,     5,     7,     9,     8,     1,     0,     3,     2,
       2,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     2,     2,     2,
       4,     2,     2,     2,     2,     2,     2,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     1,     4,     3,     3,     3,     4,     1,
       1,     1,     1,     1,     1
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
#line 99 "parser.y"
                                                                        {print_sym(curr_scope);}
#line 1813 "parser.tab.c"
    break;

  case 3:
#line 100 "parser.y"
                                                                        {print_sym(curr_scope);}
#line 1819 "parser.tab.c"
    break;

  case 4:
#line 103 "parser.y"
                                                                        {sym_declaration((yyvsp[0].astnode_p), curr_scope);}
#line 1825 "parser.tab.c"
    break;

  case 5:
#line 104 "parser.y"
                                                                        {sym_func_def((yyvsp[0].astnode_p), curr_scope);}
#line 1831 "parser.tab.c"
    break;

  case 6:
#line 108 "parser.y"
                                                                {yyerror("Empty Declaration");}
#line 1837 "parser.tab.c"
    break;

  case 7:
#line 109 "parser.y"
                                                                {(yyval.astnode_p)=alloc_declaration((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));}
#line 1843 "parser.tab.c"
    break;

  case 8:
#line 113 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 1849 "parser.tab.c"
    break;

  case 9:
#line 114 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 1855 "parser.tab.c"
    break;

  case 10:
#line 116 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1861 "parser.tab.c"
    break;

  case 11:
#line 117 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1867 "parser.tab.c"
    break;

  case 12:
#line 118 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1873 "parser.tab.c"
    break;

  case 13:
#line 119 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1879 "parser.tab.c"
    break;

  case 14:
#line 122 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_AUTO);    }
#line 1885 "parser.tab.c"
    break;

  case 15:
#line 123 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_STATIC);  }
#line 1891 "parser.tab.c"
    break;

  case 16:
#line 124 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_EXTERN);  }
#line 1897 "parser.tab.c"
    break;

  case 17:
#line 125 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_TYPEDEF); }
#line 1903 "parser.tab.c"
    break;

  case 18:
#line 126 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(STG_REGISTER);}
#line 1909 "parser.tab.c"
    break;

  case 19:
#line 129 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_VOID);    }
#line 1915 "parser.tab.c"
    break;

  case 20:
#line 130 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_CHAR);    }
#line 1921 "parser.tab.c"
    break;

  case 21:
#line 131 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_SHORT);   }
#line 1927 "parser.tab.c"
    break;

  case 22:
#line 132 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_INT);     }
#line 1933 "parser.tab.c"
    break;

  case 23:
#line 133 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_LONG);    }
#line 1939 "parser.tab.c"
    break;

  case 24:
#line 134 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_FLOAT);   }
#line 1945 "parser.tab.c"
    break;

  case 25:
#line 135 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_DOUBLE);  }
#line 1951 "parser.tab.c"
    break;

  case 26:
#line 136 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_SIGNED);  }
#line 1957 "parser.tab.c"
    break;

  case 27:
#line 137 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE_UNSIGNED);}
#line 1963 "parser.tab.c"
    break;

  case 28:
#line 138 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE__BOOL);   }
#line 1969 "parser.tab.c"
    break;

  case 29:
#line 139 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(TYPE__COMPLEX);}
#line 1975 "parser.tab.c"
    break;

  case 30:
#line 140 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 1981 "parser.tab.c"
    break;

  case 31:
#line 146 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_CONST);}
#line 1987 "parser.tab.c"
    break;

  case 32:
#line 147 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_RESTRICT);}
#line 1993 "parser.tab.c"
    break;

  case 33:
#line 148 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(QUALIF_VOLATILE);}
#line 1999 "parser.tab.c"
    break;

  case 34:
#line 150 "parser.y"
                                                                {(yyval.astnode_p)=alloc_decl_spec(FUNC_INLINE);}
#line 2005 "parser.tab.c"
    break;

  case 35:
#line 153 "parser.y"
                                                                                {(yyval.astnode_p)=(yyvsp[-3].astnode_p); sym_struct_define((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 2011 "parser.tab.c"
    break;

  case 36:
#line 154 "parser.y"
                                                                                {(yyval.astnode_p)=(yyvsp[-4].astnode_p); 
                                                                                 sym_struct_define((yyvsp[-4].astnode_p), (yyvsp[-1].astnode_p));
                                                                                 sym_struct_declare((yyvsp[-3].ident), (yyvsp[-4].astnode_p), curr_scope);
                                                                                }
#line 2020 "parser.tab.c"
    break;

  case 37:
#line 158 "parser.y"
                                                                                { SYM_ENT temp = alloc_sym_ent((yyvsp[0].ident), ENT_SU_TAG, NS_SU);
                                                                                  (yyval.astnode_p) = (temp = sym_lookup(curr_scope, temp)) ? temp->su_tag.st_un : alloc_ident((yyvsp[0].ident));
                                                                                }
#line 2028 "parser.tab.c"
    break;

  case 38:
#line 163 "parser.y"
                                {(yyval.astnode_p)=alloc_st_un(AST_STRUCT, curr_scope->scope_type);}
#line 2034 "parser.tab.c"
    break;

  case 39:
#line 164 "parser.y"
                                {(yyval.astnode_p)=alloc_st_un(AST_UNION, curr_scope->scope_type);}
#line 2040 "parser.tab.c"
    break;

  case 40:
#line 167 "parser.y"
                                                                            {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2046 "parser.tab.c"
    break;

  case 41:
#line 168 "parser.y"
                                                                            {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2052 "parser.tab.c"
    break;

  case 42:
#line 171 "parser.y"
                                                                            {(yyval.astnode_p)=alloc_declaration((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));}
#line 2058 "parser.tab.c"
    break;

  case 43:
#line 174 "parser.y"
                                                            {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2064 "parser.tab.c"
    break;

  case 44:
#line 175 "parser.y"
                                                            {(yyval.astnode_p)=list_append_elem((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2070 "parser.tab.c"
    break;

  case 45:
#line 176 "parser.y"
                                                            {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2076 "parser.tab.c"
    break;

  case 46:
#line 177 "parser.y"
                                                            {(yyval.astnode_p)=list_append_elem((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2082 "parser.tab.c"
    break;

  case 47:
#line 180 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2088 "parser.tab.c"
    break;

  case 48:
#line 181 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 2094 "parser.tab.c"
    break;

  case 49:
#line 184 "parser.y"
                                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2100 "parser.tab.c"
    break;

  case 52:
#line 194 "parser.y"
                                                                     {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2106 "parser.tab.c"
    break;

  case 53:
#line 195 "parser.y"
                                                                     {(yyval.astnode_p)=(yyvsp[-2].astnode_p); list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 2112 "parser.tab.c"
    break;

  case 54:
#line 198 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2118 "parser.tab.c"
    break;

  case 55:
#line 199 "parser.y"
                                                                    {}
#line 2124 "parser.tab.c"
    break;

  case 57:
#line 205 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2130 "parser.tab.c"
    break;

  case 58:
#line 206 "parser.y"
                                                                {(yyval.astnode_p)=list_append((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2136 "parser.tab.c"
    break;

  case 59:
#line 209 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list(alloc_ident((yyvsp[0].ident)));}
#line 2142 "parser.tab.c"
    break;

  case 60:
#line 210 "parser.y"
                                                                {(yyval.astnode_p)=(yyvsp[-1].astnode_p); /* fprintf(stdout, "PAREN\n"); print_ast($$); */}
#line 2148 "parser.tab.c"
    break;

  case 61:
#line 211 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem(alloc_array(NULL,(yyvsp[-1].astnode_p)), (yyvsp[-3].astnode_p));}
#line 2154 "parser.tab.c"
    break;

  case 62:
#line 212 "parser.y"
                                                                {yyerror("not supporting variable length arrays");exit(-1);}
#line 2160 "parser.tab.c"
    break;

  case 63:
#line 214 "parser.y"
                                                                { /* replace the first element(IDENT) with a ast_func */
                                                                 (yyval.astnode_p)=alloc_list(alloc_func((yyvsp[-3].astnode_p)->list.elem, (yyvsp[-1].astnode_p)));
                                                                 (yyval.astnode_p)->list.next = (yyvsp[-3].astnode_p)->list.next;
                                                                 free((yyvsp[-3].astnode_p)); /* SOME semblance of memory managment :^) */
                                                                }
#line 2170 "parser.tab.c"
    break;

  case 64:
#line 219 "parser.y"
                                                                {yyerror("Not supporting old c style function definitons :'("); exit(-1);}
#line 2176 "parser.tab.c"
    break;

  case 65:
#line 220 "parser.y"
                                                                {yyerror("please define your funciton"); exit(-1);}
#line 2182 "parser.tab.c"
    break;

  case 66:
#line 224 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list(alloc_ptr(NULL));}
#line 2188 "parser.tab.c"
    break;

  case 67:
#line 225 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem(alloc_ptr(NULL), (yyvsp[0].astnode_p));}
#line 2194 "parser.tab.c"
    break;

  case 68:
#line 226 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list(alloc_ptr(NULL));}
#line 2200 "parser.tab.c"
    break;

  case 69:
#line 227 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem(alloc_ptr(NULL), (yyvsp[0].astnode_p));}
#line 2206 "parser.tab.c"
    break;

  case 70:
#line 230 "parser.y"
                                                                {}
#line 2212 "parser.tab.c"
    break;

  case 71:
#line 231 "parser.y"
                                                                {}
#line 2218 "parser.tab.c"
    break;

  case 72:
#line 234 "parser.y"
                                                                {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2224 "parser.tab.c"
    break;

  case 73:
#line 235 "parser.y"
                                                                {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-2].astnode_p));}
#line 2230 "parser.tab.c"
    break;

  case 74:
#line 238 "parser.y"
                                                                {(yyval.astnode_p)=alloc_declaration((yyvsp[-1].astnode_p), (yyvsp[0].astnode_p));}
#line 2236 "parser.tab.c"
    break;

  case 75:
#line 239 "parser.y"
                                                                {yyerror("incomplete definition");}
#line 2242 "parser.tab.c"
    break;

  case 76:
#line 258 "parser.y"
                                                                                    { /* populate astnode with elements */
                                                                                     (yyval.astnode_p)=(yyvsp[-1].astnode_p)->list.elem;
                                                                                     (yyval.astnode_p)->func.ret = list_append((yyvsp[-2].astnode_p), (yyvsp[-1].astnode_p));
                                                                                     (yyval.astnode_p)->func.ret = (yyval.astnode_p)->func.ret->list.next;
                                                                                     (yyval.astnode_p)->func.block = (yyvsp[0].astnode_p);
                                                                                     (yyval.astnode_p)->func.block->comp.type = SCOPE_FUNC;
                                                                                    }
#line 2254 "parser.tab.c"
    break;

  case 77:
#line 265 "parser.y"
                                                                                    {yyerror("not handling old c style function definitions :'("); exit(-1);}
#line 2260 "parser.tab.c"
    break;

  case 80:
#line 271 "parser.y"
                                                    {(yyval.astnode_p)=alloc_compound(NULL, NULL);}
#line 2266 "parser.tab.c"
    break;

  case 81:
#line 272 "parser.y"
                              {curr_scope=sym_tab_push(SCOPE_BLOCK, curr_scope);}
#line 2272 "parser.tab.c"
    break;

  case 82:
#line 272 "parser.y"
                                                                                                         {print_sym(curr_scope); (yyval.astnode_p)=alloc_compound((yyvsp[-1].astnode_p), curr_scope); curr_scope=sym_tab_pop(curr_scope);}
#line 2278 "parser.tab.c"
    break;

  case 83:
#line 275 "parser.y"
                                                        {(yyval.astnode_p)=alloc_list((yyvsp[0].astnode_p));}
#line 2284 "parser.tab.c"
    break;

  case 84:
#line 276 "parser.y"
                                                        {(yyval.astnode_p)=list_append_elem((yyvsp[0].astnode_p), (yyvsp[-1].astnode_p));}
#line 2290 "parser.tab.c"
    break;

  case 85:
#line 279 "parser.y"
                                                        {(yyval.astnode_p)=(yyvsp[0].astnode_p); sym_declaration((yyvsp[0].astnode_p), curr_scope);}
#line 2296 "parser.tab.c"
    break;

  case 86:
#line 280 "parser.y"
                                                        {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2302 "parser.tab.c"
    break;

  case 87:
#line 283 "parser.y"
                                                    {(yyval.astnode_p)=alloc_list(alloc_ident((yyvsp[0].ident)));}
#line 2308 "parser.tab.c"
    break;

  case 88:
#line 284 "parser.y"
                                                    {(yyval.astnode_p)=list_append_elem(alloc_ident((yyvsp[0].ident)), (yyvsp[-2].astnode_p));}
#line 2314 "parser.tab.c"
    break;

  case 89:
#line 293 "parser.y"
                                                               {print_ast((yyvsp[0].astnode_p)); putchar('\n');}
#line 2320 "parser.tab.c"
    break;

  case 90:
#line 294 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2326 "parser.tab.c"
    break;

  case 91:
#line 295 "parser.y"
                                                            {}
#line 2332 "parser.tab.c"
    break;

  case 92:
#line 296 "parser.y"
                                                            {}
#line 2338 "parser.tab.c"
    break;

  case 93:
#line 297 "parser.y"
                                                            {}
#line 2344 "parser.tab.c"
    break;

  case 94:
#line 298 "parser.y"
                                                             {}
#line 2350 "parser.tab.c"
    break;

  case 95:
#line 301 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 2356 "parser.tab.c"
    break;

  case 96:
#line 303 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2362 "parser.tab.c"
    break;

  case 97:
#line 304 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2368 "parser.tab.c"
    break;

  case 98:
#line 305 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2374 "parser.tab.c"
    break;

  case 99:
#line 308 "parser.y"
                                                            {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2380 "parser.tab.c"
    break;

  case 100:
#line 309 "parser.y"
                                                            {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2386 "parser.tab.c"
    break;

  case 101:
#line 310 "parser.y"
                                                            {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2392 "parser.tab.c"
    break;

  case 102:
#line 313 "parser.y"
                                                                           {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2398 "parser.tab.c"
    break;

  case 103:
#line 314 "parser.y"
                                                                           {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2404 "parser.tab.c"
    break;

  case 104:
#line 315 "parser.y"
                                                                           {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2410 "parser.tab.c"
    break;

  case 105:
#line 316 "parser.y"
                                                                           {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2416 "parser.tab.c"
    break;

  case 106:
#line 318 "parser.y"
                                    {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2422 "parser.tab.c"
    break;

  case 107:
#line 319 "parser.y"
                                    {(yyval.astnode_p)=NULL;}
#line 2428 "parser.tab.c"
    break;

  case 108:
#line 322 "parser.y"
                                                        {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2434 "parser.tab.c"
    break;

  case 109:
#line 323 "parser.y"
                                                        {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2440 "parser.tab.c"
    break;

  case 110:
#line 324 "parser.y"
                                                        {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2446 "parser.tab.c"
    break;

  case 111:
#line 325 "parser.y"
                                                        {(yyval.astnode_p)=astnode_alloc(AST_IDENT);}
#line 2452 "parser.tab.c"
    break;

  case 112:
#line 328 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2458 "parser.tab.c"
    break;

  case 113:
#line 329 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP, (yyvsp[-2].astnode_p), ',', (yyvsp[0].astnode_p));}
#line 2464 "parser.tab.c"
    break;

  case 114:
#line 332 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(ASSIGN, (yyvsp[-2].astnode_p), '=', (yyvsp[0].astnode_p));}
#line 2470 "parser.tab.c"
    break;

  case 115:
#line 333 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 2476 "parser.tab.c"
    break;

  case 116:
#line 334 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 2482 "parser.tab.c"
    break;

  case 117:
#line 335 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 2488 "parser.tab.c"
    break;

  case 118:
#line 336 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 2494 "parser.tab.c"
    break;

  case 119:
#line 337 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 2500 "parser.tab.c"
    break;

  case 120:
#line 338 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 2506 "parser.tab.c"
    break;

  case 121:
#line 339 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 2512 "parser.tab.c"
    break;

  case 122:
#line 340 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 2518 "parser.tab.c"
    break;

  case 123:
#line 341 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 2524 "parser.tab.c"
    break;

  case 124:
#line 342 "parser.y"
                                                            {(yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 2530 "parser.tab.c"
    break;

  case 125:
#line 343 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2536 "parser.tab.c"
    break;

  case 126:
#line 346 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2542 "parser.tab.c"
    break;

  case 127:
#line 347 "parser.y"
                                                            {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '+', temp);}
#line 2549 "parser.tab.c"
    break;

  case 128:
#line 349 "parser.y"
                                                            {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                (yyval.astnode_p)=alloc_and_expand_assignment((yyvsp[0].astnode_p), '-', temp);}
#line 2556 "parser.tab.c"
    break;

  case 129:
#line 351 "parser.y"
                                                            {(yyval.astnode_p)=alloc_sizeof((yyvsp[0].astnode_p));}
#line 2562 "parser.tab.c"
    break;

  case 130:
#line 352 "parser.y"
                                                            {(yyval.astnode_p)=alloc_sizeof((yyvsp[-1].astnode_p));}
#line 2568 "parser.tab.c"
    break;

  case 131:
#line 353 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('&',(yyvsp[0].astnode_p));}
#line 2574 "parser.tab.c"
    break;

  case 132:
#line 354 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('*',(yyvsp[0].astnode_p));}
#line 2580 "parser.tab.c"
    break;

  case 133:
#line 355 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('+',(yyvsp[0].astnode_p));}
#line 2586 "parser.tab.c"
    break;

  case 134:
#line 356 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('-',(yyvsp[0].astnode_p));}
#line 2592 "parser.tab.c"
    break;

  case 135:
#line 357 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('~',(yyvsp[0].astnode_p));}
#line 2598 "parser.tab.c"
    break;

  case 136:
#line 358 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('!',(yyvsp[0].astnode_p));}
#line 2604 "parser.tab.c"
    break;

  case 137:
#line 361 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2610 "parser.tab.c"
    break;

  case 138:
#line 364 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2616 "parser.tab.c"
    break;

  case 139:
#line 365 "parser.y"
                                                            {(yyval.astnode_p)=alloc_ternary((yyvsp[-4].astnode_p), (yyvsp[-2].astnode_p), (yyvsp[0].astnode_p));}
#line 2622 "parser.tab.c"
    break;

  case 140:
#line 368 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '+', (yyvsp[0].astnode_p));}
#line 2628 "parser.tab.c"
    break;

  case 141:
#line 369 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '-', (yyvsp[0].astnode_p));}
#line 2634 "parser.tab.c"
    break;

  case 142:
#line 370 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '*', (yyvsp[0].astnode_p));}
#line 2640 "parser.tab.c"
    break;

  case 143:
#line 371 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '|', (yyvsp[0].astnode_p));}
#line 2646 "parser.tab.c"
    break;

  case 144:
#line 372 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '^', (yyvsp[0].astnode_p));}
#line 2652 "parser.tab.c"
    break;

  case 145:
#line 373 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '&', (yyvsp[0].astnode_p));}
#line 2658 "parser.tab.c"
    break;

  case 146:
#line 374 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '%', (yyvsp[0].astnode_p));}
#line 2664 "parser.tab.c"
    break;

  case 147:
#line 375 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '/', (yyvsp[0].astnode_p));}
#line 2670 "parser.tab.c"
    break;

  case 148:
#line 376 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), SHR, (yyvsp[0].astnode_p));}
#line 2676 "parser.tab.c"
    break;

  case 149:
#line 377 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), SHL, (yyvsp[0].astnode_p));}
#line 2682 "parser.tab.c"
    break;

  case 150:
#line 378 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '<', (yyvsp[0].astnode_p));}
#line 2688 "parser.tab.c"
    break;

  case 151:
#line 379 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), '>', (yyvsp[0].astnode_p));}
#line 2694 "parser.tab.c"
    break;

  case 152:
#line 380 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LTEQ, (yyvsp[0].astnode_p));}
#line 2700 "parser.tab.c"
    break;

  case 153:
#line 381 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), GTEQ, (yyvsp[0].astnode_p));}
#line 2706 "parser.tab.c"
    break;

  case 154:
#line 382 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), EQEQ, (yyvsp[0].astnode_p));}
#line 2712 "parser.tab.c"
    break;

  case 155:
#line 383 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), NOTEQ, (yyvsp[0].astnode_p));}
#line 2718 "parser.tab.c"
    break;

  case 156:
#line 384 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LOGAND, (yyvsp[0].astnode_p));}
#line 2724 "parser.tab.c"
    break;

  case 157:
#line 385 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP,(yyvsp[-2].astnode_p), LOGOR, (yyvsp[0].astnode_p));}
#line 2730 "parser.tab.c"
    break;

  case 158:
#line 386 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary(PLUSPLUS,(yyvsp[-1].astnode_p));}
#line 2736 "parser.tab.c"
    break;

  case 159:
#line 387 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary(MINUSMINUS,(yyvsp[-1].astnode_p));}
#line 2742 "parser.tab.c"
    break;

  case 160:
#line 388 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[-1].astnode_p);}
#line 2748 "parser.tab.c"
    break;

  case 161:
#line 389 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2754 "parser.tab.c"
    break;

  case 162:
#line 393 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2760 "parser.tab.c"
    break;

  case 163:
#line 396 "parser.y"
                                                            {(yyval.astnode_p)=(yyvsp[0].astnode_p);}
#line 2766 "parser.tab.c"
    break;

  case 164:
#line 397 "parser.y"
                                                            {(yyval.astnode_p)=alloc_binary(BINOP, (yyvsp[-3].astnode_p), '+', (yyvsp[-1].astnode_p));
                                                                (yyval.astnode_p)=alloc_unary('*', (yyval.astnode_p));}
#line 2773 "parser.tab.c"
    break;

  case 165:
#line 399 "parser.y"
                                                            {(yyval.astnode_p)=alloc_select((yyvsp[-2].astnode_p), (yyvsp[0].ident));}
#line 2779 "parser.tab.c"
    break;

  case 166:
#line 400 "parser.y"
                                                            {(yyval.astnode_p)=alloc_unary('*', (yyvsp[-2].astnode_p));
                                                                (yyval.astnode_p)=alloc_select((yyval.astnode_p), (yyvsp[0].ident));}
#line 2786 "parser.tab.c"
    break;

  case 167:
#line 402 "parser.y"
                                                              {(yyval.astnode_p)=alloc_fncall((yyvsp[-2].astnode_p), NULL);}
#line 2792 "parser.tab.c"
    break;

  case 168:
#line 403 "parser.y"
                                                              {(yyval.astnode_p)=alloc_fncall((yyvsp[-3].astnode_p), (yyvsp[-1].astnode_p));}
#line 2798 "parser.tab.c"
    break;

  case 169:
#line 412 "parser.y"
                                                {(yyval.astnode_p)=alloc_ident((yyvsp[0].ident));}
#line 2804 "parser.tab.c"
    break;

  case 170:
#line 413 "parser.y"
                                                {(yyval.astnode_p)=alloc_num((yyvsp[0].num).int_num, (yyvsp[0].num).real, (yyvsp[0].num).type, (yyvsp[0].num).sign);}
#line 2810 "parser.tab.c"
    break;

  case 171:
#line 414 "parser.y"
                                                {(yyval.astnode_p)=alloc_charlit((yyvsp[0].charlit));}
#line 2816 "parser.tab.c"
    break;

  case 172:
#line 415 "parser.y"
                                                {(yyval.astnode_p)=alloc_string((yyvsp[0].str).str, (yyvsp[0].str).len);}
#line 2822 "parser.tab.c"
    break;

  case 173:
#line 418 "parser.y"
                                                {(yyval.astnode_p)=alloc_num((yyvsp[0].num).int_num, (yyvsp[0].num).real, (yyvsp[0].num).type, (yyvsp[0].num).sign);}
#line 2828 "parser.tab.c"
    break;

  case 174:
#line 419 "parser.y"
                                                {(yyval.astnode_p)=alloc_charlit((yyvsp[0].charlit));}
#line 2834 "parser.tab.c"
    break;


#line 2838 "parser.tab.c"

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
#line 422 "parser.y"
 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s:%d %s\n", filename, lineno, msg);
}

int main(){

    /* creating global symbol table */
    curr_scope = sym_tab_create(SCOPE_GLOBAL);

    yyparse();
    return 1;
}
