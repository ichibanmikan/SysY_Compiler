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
#line 1 "SysY_Yacc.y"

#include "SysY_Yacc.h"

// external functions from lex
extern int yylex();
extern FILE* yyin;
// external variables from lexical_analyzer module
extern int lines;
extern char *yytext;
extern int pos_end;
extern int pos_start;
extern void yyrestart  (FILE * input_file );

// Global syntax tree
syntax_tree *gt;

// Error reporting
void yyerror(const char *s);

// Helper functions written for you with love
syntax_tree_node *node(const char *node_name, int children_num, ...);

#line 93 "SysY_Yacc.tab.c"

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
#ifndef YY_YY_SYSY_YACC_TAB_H_INCLUDED
# define YY_YY_SYSY_YACC_TAB_H_INCLUDED
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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    LT = 262,
    LTE = 263,
    GT = 264,
    GTE = 265,
    EQ = 266,
    NEQ = 267,
    AND = 268,
    OR = 269,
    NOT = 270,
    MOD = 271,
    ASSIGN = 272,
    SEMICOLON = 273,
    COMMA = 274,
    LPARENTHESE = 275,
    RPARENTHESE = 276,
    LBRACKET = 277,
    RBRACKET = 278,
    LBRACE = 279,
    RBRACE = 280,
    ELSE = 281,
    IF = 282,
    INT = 283,
    FLOAT = 284,
    RETURN = 285,
    VOID = 286,
    WHILE = 287,
    IDENTIFIER = 288,
    INTEGER = 289,
    FLOATPOINT = 290,
    ARRAY = 291,
    LETTER = 292,
    EOL = 293,
    COMMENT = 294,
    BLANK = 295,
    ERROR = 296,
    CONTINUE = 297,
    BREAK = 298,
    CONST = 299,
    COMMENTONELINE = 300,
    GETINT = 301,
    GETCH = 302,
    GETFLOAT = 303,
    GETARRAY = 304,
    GETFARRAY = 305,
    PUTINT = 306,
    PUTCH = 307,
    PUTFLOAT = 308,
    PUTARRAY = 309,
    PUTFARRAY = 310,
    PUTF = 311,
    STARTTIME = 312,
    STOPTIME = 313,
    CONTROLSTRING = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "SysY_Yacc.y"

    syntax_tree_node* node;

#line 209 "SysY_Yacc.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYSY_YACC_TAB_H_INCLUDED  */



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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    46,    49,    52,    55,    58,    61,    64,
      67,    70,    73,    76,    79,    82,    85,    88,    91,    94,
      97,   100,   103,   106,   109,   113,   116,   119,   122,   125,
     128,   131,   134,   137,   140,   143,   146,   149,   152,   155,
     158,   161,   164,   167,   170,   173,   176,   179,   182,   185,
     188,   191,   194,   197,   200,   203,   206,   209,   212,   215,
     218,   221,   224,   227,   230,   233,   236,   239,   242,   245,
     248,   251,   254,   257,   260,   263,   266,   269,   272,   275,
     278,   281,   284,   287,   290,   293,   296,   299,   302,   305,
     308,   311,   314,   317,   320,   323,   326,   329,   332,   335,
     338,   341,   345,   348,   351,   354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "LT", "LTE",
  "GT", "GTE", "EQ", "NEQ", "AND", "OR", "NOT", "MOD", "ASSIGN",
  "SEMICOLON", "COMMA", "LPARENTHESE", "RPARENTHESE", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "ELSE", "IF", "INT", "FLOAT", "RETURN",
  "VOID", "WHILE", "IDENTIFIER", "INTEGER", "FLOATPOINT", "ARRAY",
  "LETTER", "EOL", "COMMENT", "BLANK", "ERROR", "CONTINUE", "BREAK",
  "CONST", "COMMENTONELINE", "GETINT", "GETCH", "GETFLOAT", "GETARRAY",
  "GETFARRAY", "PUTINT", "PUTCH", "PUTFLOAT", "PUTARRAY", "PUTFARRAY",
  "PUTF", "STARTTIME", "STOPTIME", "CONTROLSTRING", "$accept", "program",
  "declaration_list", "declaration", "var_declaration", "type_specifier",
  "array_size", "fun_declaration", "params", "param_list", "param",
  "compound_stmt", "statement_list", "statement", "expression_stmt",
  "selection_stmt", "iteration_stmt", "return_stmt",
  "local_declartion_assignment", "declartion_assignment_expression",
  "expression", "var", "logic_expression", "logiclop", "simple_expression",
  "relop", "additive_expression", "addop", "term", "mulop", "factor",
  "integer", "float", "call", "calllib", "args", "arg_list", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,  -170,  -170,  -170,    72,    53,    -1,  -170,  -170,    21,
    -170,    65,  -170,  -170,    73,   -17,  -170,    77,   365,    47,
    -170,    52,    81,    71,    91,    67,  -170,     3,    50,   365,
      44,  -170,  -170,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,  -170,     6,    19,  -170,
    -170,  -170,  -170,  -170,  -170,   365,  -170,    90,   108,    72,
    -170,  -170,  -170,  -170,   107,   110,  -170,    48,   365,   112,
     114,   115,   116,   365,   365,   365,   365,   365,   365,   365,
      70,   117,   118,  -170,  -170,  -170,   365,  -170,  -170,  -170,
     365,     8,  -170,  -170,  -170,  -170,  -170,   365,  -170,  -170,
    -170,  -170,  -170,  -170,   365,  -170,   119,   122,  -170,  -170,
    -170,   121,   123,   126,   128,   130,   365,   365,   124,  -170,
    -170,    19,  -170,  -170,   158,  -170,   106,  -170,   365,  -170,
    -170,  -170,  -170,  -170,   131,   133,   365,  -170,  -170,   135,
     270,   139,   142,   145,    72,  -170,   132,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,   146,  -170,  -170,  -170,   147,   326,
    -170,   148,   326,  -170,  -170,   134,    74,   151,   154,  -170,
    -170,   365,   156,   159,    69,  -170,   160,   163,   -17,   161,
      -4,  -170,   365,   106,   214,   214,  -170,  -170,   365,   214,
     214,    45,  -170,   170,  -170,   169,   171,   106,  -170,  -170,
     172,   365,   214,   214,   365,    -2,  -170,  -170,     7,   180,
     181,  -170,  -170
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,    13,     0,     0,     2,     4,     5,     0,
       6,     0,     1,     3,     0,     0,     9,    19,     0,     0,
       7,     0,    13,     0,     0,    17,    21,     0,     0,     0,
      53,    82,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    68,    72,
      79,    80,    78,    81,    10,     0,     8,    22,     0,     0,
      83,    86,    84,    87,     0,    77,    52,    60,   103,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    15,     0,    73,    74,    75,
       0,     0,    23,    26,    16,    20,    76,     0,    62,    61,
      63,    64,    65,    66,     0,   105,     0,   102,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,    67,    71,    14,     0,    51,    59,    88,     0,    92,
      93,    94,    95,    96,     0,     0,   103,    37,    24,     0,
       0,     0,     0,     0,     0,    32,     0,    28,    25,    27,
      29,    30,    31,    33,     0,   104,    97,    98,     0,     0,
      44,     0,     0,    35,    34,     0,    53,     0,     0,    36,
      99,     0,     0,     0,    60,    45,     0,     0,    53,     0,
       0,    47,     0,    56,     0,     0,    57,    58,     0,     0,
       0,     0,    46,     0,    50,    38,    40,    55,    42,    43,
       0,     0,     0,     0,     0,     0,    39,    41,     0,     0,
       0,    49,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,  -170,   197,    36,     2,    -8,  -170,  -170,  -170,
     162,   164,  -170,  -169,  -170,  -170,  -170,  -170,  -170,    54,
     -29,   -15,    58,  -170,  -170,  -170,   -14,  -170,   137,  -170,
     136,  -170,  -170,  -170,  -170,    88,  -107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   145,   146,    19,    10,    24,    25,
      26,   147,   124,   148,   149,   150,   151,   152,   153,   167,
     154,    65,   173,   188,    66,   104,    67,    86,    48,    90,
      49,    50,    51,    52,    53,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    20,     9,    46,    47,    18,    11,    21,     9,    83,
      84,    83,    84,   193,    54,   195,   196,   128,    55,    23,
     198,   199,    69,   209,    87,    88,   128,     1,     2,    85,
       3,   123,   210,   206,   207,    89,     8,    60,    61,   105,
      46,    91,     8,     4,   111,   112,   113,   114,   115,   116,
     117,    83,    84,    12,    14,    98,    99,   100,   101,   102,
     103,    23,   200,    56,    68,    54,    18,    55,   125,    55,
      56,    46,    83,    84,    55,    46,    98,    99,   100,   101,
     102,   103,   186,   187,    62,    63,    59,   134,   135,    46,
     126,    16,    16,    17,   205,    18,    18,   208,    15,   155,
       1,     2,   -18,     3,    57,     1,     2,   105,    22,    83,
      84,   161,    58,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    92,    97,    96,   118,
     172,   168,    93,   176,    55,   108,   109,   110,   119,   120,
     127,   128,   129,   136,   130,   174,   165,   131,   174,   132,
     168,   133,   156,   194,   157,   159,    46,   183,   180,   162,
     163,    27,    28,   164,   169,   166,   175,   178,   170,   181,
     191,   182,   105,    46,   197,   105,   137,   184,    29,   192,
     185,   189,    93,   138,   190,   139,     1,     2,   140,     3,
     141,    30,    31,    32,   201,   202,   204,   203,   211,   212,
     142,   143,   144,    13,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    27,    28,   179,
     177,    95,    94,   121,   158,     0,   122,     0,     0,     0,
       0,     0,   137,     0,    29,     0,     0,     0,    93,     0,
       0,   139,     1,     2,   140,     3,   141,    30,    31,    32,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    27,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45
};

static const yytype_int16 yycheck[] =
{
      29,    18,     0,    18,    18,    22,     4,    15,     6,     3,
       4,     3,     4,    17,    18,   184,   185,    19,    22,    17,
     189,   190,    30,    25,     5,     6,    19,    28,    29,    23,
      31,    23,    25,   202,   203,    16,     0,    34,    35,    68,
      55,    55,     6,    44,    73,    74,    75,    76,    77,    78,
      79,     3,     4,     0,    33,     7,     8,     9,    10,    11,
      12,    59,    17,    18,    20,    18,    22,    22,    97,    22,
      18,    86,     3,     4,    22,    90,     7,     8,     9,    10,
      11,    12,    13,    14,    34,    35,    19,   116,   117,   104,
     104,    18,    18,    20,   201,    22,    22,   204,    33,   128,
      28,    29,    21,    31,    33,    28,    29,   136,    31,     3,
       4,   140,    21,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    36,    17,    21,    59,
     159,   146,    24,   162,    22,    21,    21,    21,    21,    21,
      21,    19,    21,    19,    21,   159,   144,    21,   162,    21,
     165,    21,    21,   182,    21,    20,   171,   171,   166,    20,
      18,     3,     4,    18,    18,    33,    18,    33,    21,    18,
     178,    17,   201,   188,   188,   204,    18,    21,    20,    18,
      21,    21,    24,    25,    21,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    24,    26,    24,    26,    18,    18,
      42,    43,    44,     6,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     3,     4,   165,
     162,    59,    58,    86,   136,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,    31,    44,    61,    62,    63,    64,    65,
      67,    65,     0,    63,    33,    33,    18,    20,    22,    66,
      18,    66,    31,    65,    68,    69,    70,     3,     4,    20,
      33,    34,    35,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    81,    86,    88,    90,
      91,    92,    93,    94,    18,    22,    18,    33,    21,    19,
      34,    35,    34,    35,    80,    81,    84,    86,    20,    66,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,     3,     4,    23,    87,     5,     6,    16,
      89,    86,    36,    24,    71,    70,    21,    17,     7,     8,
       9,    10,    11,    12,    85,    80,    95,    96,    21,    21,
      21,    80,    80,    80,    80,    80,    80,    80,    59,    21,
      21,    88,    90,    23,    72,    80,    86,    21,    19,    21,
      21,    21,    21,    21,    80,    80,    19,    18,    25,    27,
      30,    32,    42,    43,    44,    64,    65,    71,    73,    74,
      75,    76,    77,    78,    80,    80,    21,    21,    95,    20,
      18,    80,    20,    18,    18,    65,    33,    79,    81,    18,
      21,    15,    80,    82,    86,    18,    80,    82,    33,    79,
      66,    18,    17,    86,    21,    21,    13,    14,    83,    21,
      21,    66,    18,    17,    80,    73,    73,    86,    73,    73,
      17,    24,    26,    26,    24,    96,    73,    73,    96,    25,
      25,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    67,    68,    68,    68,
      69,    69,    70,    70,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    92,    92,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     5,     3,
       4,     1,     1,     1,     4,     3,     6,     1,     1,     0,
       3,     1,     2,     3,     3,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     5,     7,
       5,     7,     5,     5,     2,     3,     4,     3,     9,     8,
       3,     3,     1,     1,     2,     3,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     4,     3,
       3,     3,     4,     4,     4,     4,     4,     5,     5,     6,
       3,     3,     1,     0,     3,     1
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
#line 42 "SysY_Yacc.y"
                           {
            (yyval.node) = node("program", 1, (yyvsp[0].node));
            gt->root = (yyval.node);
        }
#line 1583 "SysY_Yacc.tab.c"
    break;

  case 3:
#line 46 "SysY_Yacc.y"
                                                {
                    (yyval.node) = node("declaration_list", 2, (yyvsp[-1].node), (yyvsp[0].node));
                 }
#line 1591 "SysY_Yacc.tab.c"
    break;

  case 4:
#line 49 "SysY_Yacc.y"
                               {
                     (yyval.node) = node("declaration_list", 1, (yyvsp[0].node));
                 }
#line 1599 "SysY_Yacc.tab.c"
    break;

  case 5:
#line 52 "SysY_Yacc.y"
                              {
                (yyval.node) = node("declaration", 1, (yyvsp[0].node));
            }
#line 1607 "SysY_Yacc.tab.c"
    break;

  case 6:
#line 55 "SysY_Yacc.y"
                             {
                (yyval.node) = node("declaration", 1, (yyvsp[0].node));
            }
#line 1615 "SysY_Yacc.tab.c"
    break;

  case 7:
#line 58 "SysY_Yacc.y"
                                                           {
                    (yyval.node) = node("var_declaration", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1623 "SysY_Yacc.tab.c"
    break;

  case 8:
#line 61 "SysY_Yacc.y"
                                                                     {
                    (yyval.node) = node("var_declaration", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1631 "SysY_Yacc.tab.c"
    break;

  case 9:
#line 64 "SysY_Yacc.y"
                                                     {
                    (yyval.node) = node("var_declaration", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1639 "SysY_Yacc.tab.c"
    break;

  case 10:
#line 67 "SysY_Yacc.y"
                                                               {
                    (yyval.node) = node("var_declaration", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1647 "SysY_Yacc.tab.c"
    break;

  case 11:
#line 70 "SysY_Yacc.y"
                     {
                    (yyval.node) = node("type_specifier", 1, (yyvsp[0].node));
                }
#line 1655 "SysY_Yacc.tab.c"
    break;

  case 12:
#line 73 "SysY_Yacc.y"
                       {
                    (yyval.node) = node("type_specifier", 1, (yyvsp[0].node));
                }
#line 1663 "SysY_Yacc.tab.c"
    break;

  case 13:
#line 76 "SysY_Yacc.y"
                      {
                    (yyval.node) = node("type_specifier", 1, (yyvsp[0].node));
                }
#line 1671 "SysY_Yacc.tab.c"
    break;

  case 14:
#line 79 "SysY_Yacc.y"
                                                             {
              (yyval.node) = node("array_size", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
           }
#line 1679 "SysY_Yacc.tab.c"
    break;

  case 15:
#line 82 "SysY_Yacc.y"
                                                  {
              (yyval.node) = node("array_size", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
           }
#line 1687 "SysY_Yacc.tab.c"
    break;

  case 16:
#line 85 "SysY_Yacc.y"
                                                                                         {
                    (yyval.node) = node("fun_declaration", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1695 "SysY_Yacc.tab.c"
    break;

  case 17:
#line 88 "SysY_Yacc.y"
                    {
            (yyval.node) = node("params", 1, (yyvsp[0].node));
        }
#line 1703 "SysY_Yacc.tab.c"
    break;

  case 18:
#line 91 "SysY_Yacc.y"
              {
            (yyval.node) = node("params" ,1, (yyvsp[0].node));
        }
#line 1711 "SysY_Yacc.tab.c"
    break;

  case 19:
#line 94 "SysY_Yacc.y"
          {
          (yyval.node) = node("param", 0);
        }
#line 1719 "SysY_Yacc.tab.c"
    break;

  case 20:
#line 97 "SysY_Yacc.y"
                                    {
                (yyval.node) = node("param_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1727 "SysY_Yacc.tab.c"
    break;

  case 21:
#line 100 "SysY_Yacc.y"
                   {
                (yyval.node) = node("param_list", 1, (yyvsp[0].node));
            }
#line 1735 "SysY_Yacc.tab.c"
    break;

  case 22:
#line 103 "SysY_Yacc.y"
                                  {
            (yyval.node) = node("param", 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1743 "SysY_Yacc.tab.c"
    break;

  case 23:
#line 106 "SysY_Yacc.y"
                                     {
        (yyval.node) = node("param", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1751 "SysY_Yacc.tab.c"
    break;

  case 24:
#line 109 "SysY_Yacc.y"
                                             {
                    (yyval.node) = node("compound_stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1759 "SysY_Yacc.tab.c"
    break;

  case 25:
#line 113 "SysY_Yacc.y"
                                          {
                    (yyval.node) = node("statement_list", 2, (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1767 "SysY_Yacc.tab.c"
    break;

  case 26:
#line 116 "SysY_Yacc.y"
                  {
                    (yyval.node) = node("statement_list", 0);
                }
#line 1775 "SysY_Yacc.tab.c"
    break;

  case 27:
#line 119 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1783 "SysY_Yacc.tab.c"
    break;

  case 28:
#line 122 "SysY_Yacc.y"
                           {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1791 "SysY_Yacc.tab.c"
    break;

  case 29:
#line 125 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1799 "SysY_Yacc.tab.c"
    break;

  case 30:
#line 128 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1807 "SysY_Yacc.tab.c"
    break;

  case 31:
#line 131 "SysY_Yacc.y"
                         {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1815 "SysY_Yacc.tab.c"
    break;

  case 32:
#line 134 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1823 "SysY_Yacc.tab.c"
    break;

  case 33:
#line 137 "SysY_Yacc.y"
                                        {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1831 "SysY_Yacc.tab.c"
    break;

  case 34:
#line 140 "SysY_Yacc.y"
                             {
              (yyval.node) = node("statement", 2, (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1839 "SysY_Yacc.tab.c"
    break;

  case 35:
#line 143 "SysY_Yacc.y"
                                {
              (yyval.node) = node("statement", 2, (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1847 "SysY_Yacc.tab.c"
    break;

  case 36:
#line 146 "SysY_Yacc.y"
                                       {
                    (yyval.node) = node("expression_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1855 "SysY_Yacc.tab.c"
    break;

  case 37:
#line 149 "SysY_Yacc.y"
                           {
                    (yyval.node) = node("expression_stmt", 1, (yyvsp[0].node));
                }
#line 1863 "SysY_Yacc.tab.c"
    break;

  case 38:
#line 152 "SysY_Yacc.y"
                                                                 {
                    (yyval.node) = node("selection_stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1871 "SysY_Yacc.tab.c"
    break;

  case 39:
#line 155 "SysY_Yacc.y"
                                                                                {
                    (yyval.node) = node("selection_stmt", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1879 "SysY_Yacc.tab.c"
    break;

  case 40:
#line 158 "SysY_Yacc.y"
                                                                       {
                    (yyval.node) = node("selection_stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1887 "SysY_Yacc.tab.c"
    break;

  case 41:
#line 161 "SysY_Yacc.y"
                                                                                      {
                    (yyval.node) = node("selection_stmt", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1895 "SysY_Yacc.tab.c"
    break;

  case 42:
#line 164 "SysY_Yacc.y"
                                                                    {
                    (yyval.node) = node("iteration_stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1903 "SysY_Yacc.tab.c"
    break;

  case 43:
#line 167 "SysY_Yacc.y"
                                                                          {
                    (yyval.node) = node("iteration_stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1911 "SysY_Yacc.tab.c"
    break;

  case 44:
#line 170 "SysY_Yacc.y"
                               {
                (yyval.node) = node("return_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1919 "SysY_Yacc.tab.c"
    break;

  case 45:
#line 173 "SysY_Yacc.y"
                                         {
                (yyval.node) = node("return_stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1927 "SysY_Yacc.tab.c"
    break;

  case 46:
#line 176 "SysY_Yacc.y"
                                                                                             {
                              (yyval.node) = node("local_declartion_assignment", 3, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
                            }
#line 1935 "SysY_Yacc.tab.c"
    break;

  case 47:
#line 179 "SysY_Yacc.y"
                                                                                      {
                              (yyval.node) = node("local_declartion_assignment", 2, (yyvsp[-2].node), (yyvsp[-1].node));
                            }
#line 1943 "SysY_Yacc.tab.c"
    break;

  case 48:
#line 182 "SysY_Yacc.y"
                                                                                                               {
                              (yyval.node) = node("local_declartion_assignment", 9, (yyvsp[-8].node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                            }
#line 1951 "SysY_Yacc.tab.c"
    break;

  case 49:
#line 185 "SysY_Yacc.y"
                                                                                                         {
                              (yyval.node) = node("local_declartion_assignment", 8, (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                            }
#line 1959 "SysY_Yacc.tab.c"
    break;

  case 50:
#line 188 "SysY_Yacc.y"
                                                         {
                                    (yyval.node) = node("declartion_assignment_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                                  }
#line 1967 "SysY_Yacc.tab.c"
    break;

  case 51:
#line 191 "SysY_Yacc.y"
                                   {
                (yyval.node) = node("expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1975 "SysY_Yacc.tab.c"
    break;

  case 52:
#line 194 "SysY_Yacc.y"
                               {
                (yyval.node) = node("expression", 1, (yyvsp[0].node));
            }
#line 1983 "SysY_Yacc.tab.c"
    break;

  case 53:
#line 197 "SysY_Yacc.y"
                 {
        (yyval.node) = node("var", 1, (yyvsp[0].node));
    }
#line 1991 "SysY_Yacc.tab.c"
    break;

  case 54:
#line 200 "SysY_Yacc.y"
                           {
        (yyval.node) = node("var", 2, (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1999 "SysY_Yacc.tab.c"
    break;

  case 55:
#line 203 "SysY_Yacc.y"
                                                                   {
                   (yyval.node) = node("logic_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                 }
#line 2007 "SysY_Yacc.tab.c"
    break;

  case 56:
#line 206 "SysY_Yacc.y"
                                          {
                   (yyval.node) = node("logic_expression", 2, (yyvsp[-1].node), (yyvsp[0].node));
                 }
#line 2015 "SysY_Yacc.tab.c"
    break;

  case 57:
#line 209 "SysY_Yacc.y"
              {
            (yyval.node) = node("logiclop", 1, (yyvsp[0].node));
          }
#line 2023 "SysY_Yacc.tab.c"
    break;

  case 58:
#line 212 "SysY_Yacc.y"
             {
            (yyval.node) = node("logiclop", 1, (yyvsp[0].node));
          }
#line 2031 "SysY_Yacc.tab.c"
    break;

  case 59:
#line 215 "SysY_Yacc.y"
                                                                  {
                        (yyval.node) = node("simple_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                    }
#line 2039 "SysY_Yacc.tab.c"
    break;

  case 60:
#line 218 "SysY_Yacc.y"
                                         {
                        (yyval.node) = node("simple_expression", 1, (yyvsp[0].node));
                    }
#line 2047 "SysY_Yacc.tab.c"
    break;

  case 61:
#line 221 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2055 "SysY_Yacc.tab.c"
    break;

  case 62:
#line 224 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2063 "SysY_Yacc.tab.c"
    break;

  case 63:
#line 227 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2071 "SysY_Yacc.tab.c"
    break;

  case 64:
#line 230 "SysY_Yacc.y"
             {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2079 "SysY_Yacc.tab.c"
    break;

  case 65:
#line 233 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2087 "SysY_Yacc.tab.c"
    break;

  case 66:
#line 236 "SysY_Yacc.y"
             {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2095 "SysY_Yacc.tab.c"
    break;

  case 67:
#line 239 "SysY_Yacc.y"
                                                     {
                        (yyval.node) = node("additive_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                    }
#line 2103 "SysY_Yacc.tab.c"
    break;

  case 68:
#line 242 "SysY_Yacc.y"
                          {
                        (yyval.node) = node("additive_expression", 1, (yyvsp[0].node));
                    }
#line 2111 "SysY_Yacc.tab.c"
    break;

  case 69:
#line 245 "SysY_Yacc.y"
            {
            (yyval.node) = node("addop", 1, (yyvsp[0].node));
        }
#line 2119 "SysY_Yacc.tab.c"
    break;

  case 70:
#line 248 "SysY_Yacc.y"
             {
            (yyval.node) = node("addop", 1, (yyvsp[0].node));
        }
#line 2127 "SysY_Yacc.tab.c"
    break;

  case 71:
#line 251 "SysY_Yacc.y"
                         {
            (yyval.node) = node("term", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2135 "SysY_Yacc.tab.c"
    break;

  case 72:
#line 254 "SysY_Yacc.y"
                {
            (yyval.node) = node("term", 1, (yyvsp[0].node));
        }
#line 2143 "SysY_Yacc.tab.c"
    break;

  case 73:
#line 257 "SysY_Yacc.y"
            {
            (yyval.node) = node("mulop", 1, (yyvsp[0].node));
        }
#line 2151 "SysY_Yacc.tab.c"
    break;

  case 74:
#line 260 "SysY_Yacc.y"
             {
            (yyval.node) = node("mulop", 1, (yyvsp[0].node));
        }
#line 2159 "SysY_Yacc.tab.c"
    break;

  case 75:
#line 263 "SysY_Yacc.y"
             {
            (yyval.node) = node("mulop", 1, (yyvsp[0].node));
        }
#line 2167 "SysY_Yacc.tab.c"
    break;

  case 76:
#line 266 "SysY_Yacc.y"
                                            {
            (yyval.node) = node("factor", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2175 "SysY_Yacc.tab.c"
    break;

  case 77:
#line 269 "SysY_Yacc.y"
             {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2183 "SysY_Yacc.tab.c"
    break;

  case 78:
#line 272 "SysY_Yacc.y"
              {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2191 "SysY_Yacc.tab.c"
    break;

  case 79:
#line 275 "SysY_Yacc.y"
                 {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2199 "SysY_Yacc.tab.c"
    break;

  case 80:
#line 278 "SysY_Yacc.y"
               {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2207 "SysY_Yacc.tab.c"
    break;

  case 81:
#line 281 "SysY_Yacc.y"
                 {
            (yyval.node) = node("calllib", 1, (yyvsp[0].node));
        }
#line 2215 "SysY_Yacc.tab.c"
    break;

  case 82:
#line 284 "SysY_Yacc.y"
                  {
            (yyval.node) = node("integer", 1, (yyvsp[0].node));
        }
#line 2223 "SysY_Yacc.tab.c"
    break;

  case 83:
#line 287 "SysY_Yacc.y"
                     {
            (yyval.node) = node("integer", 1, (yyvsp[0].node));
        }
#line 2231 "SysY_Yacc.tab.c"
    break;

  case 84:
#line 290 "SysY_Yacc.y"
                     {
            (yyval.node) = node("integer", 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2239 "SysY_Yacc.tab.c"
    break;

  case 85:
#line 293 "SysY_Yacc.y"
                   {
            (yyval.node) = node("float", 1, (yyvsp[0].node));
        }
#line 2247 "SysY_Yacc.tab.c"
    break;

  case 86:
#line 296 "SysY_Yacc.y"
                        {
            (yyval.node) = node("float", 1, (yyvsp[0].node));
        }
#line 2255 "SysY_Yacc.tab.c"
    break;

  case 87:
#line 299 "SysY_Yacc.y"
                        {
            (yyval.node) = node("float", 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2263 "SysY_Yacc.tab.c"
    break;

  case 88:
#line 302 "SysY_Yacc.y"
                                               {
        (yyval.node) = node("call", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
     }
#line 2271 "SysY_Yacc.tab.c"
    break;

  case 89:
#line 305 "SysY_Yacc.y"
                                         {
        (yyval.node) = node("getint", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2279 "SysY_Yacc.tab.c"
    break;

  case 90:
#line 308 "SysY_Yacc.y"
                                    {
        (yyval.node) = node("getch", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2287 "SysY_Yacc.tab.c"
    break;

  case 91:
#line 311 "SysY_Yacc.y"
                                       {
        (yyval.node) = node("getfloat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2295 "SysY_Yacc.tab.c"
    break;

  case 92:
#line 314 "SysY_Yacc.y"
                                                  {
        (yyval.node) = node("getarray", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2303 "SysY_Yacc.tab.c"
    break;

  case 93:
#line 317 "SysY_Yacc.y"
                                                   {
        (yyval.node) = node("getfarray", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2311 "SysY_Yacc.tab.c"
    break;

  case 94:
#line 320 "SysY_Yacc.y"
                                                {
        (yyval.node) = node("putin", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2319 "SysY_Yacc.tab.c"
    break;

  case 95:
#line 323 "SysY_Yacc.y"
                                              {
        (yyval.node) = node("putch", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2327 "SysY_Yacc.tab.c"
    break;

  case 96:
#line 326 "SysY_Yacc.y"
                                                 {
        (yyval.node) = node("putfloat", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2335 "SysY_Yacc.tab.c"
    break;

  case 97:
#line 329 "SysY_Yacc.y"
                                                            {
        (yyval.node) = node("putin", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2343 "SysY_Yacc.tab.c"
    break;

  case 98:
#line 332 "SysY_Yacc.y"
                                                             {
        (yyval.node) = node("putin", 4, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 2351 "SysY_Yacc.tab.c"
    break;

  case 99:
#line 335 "SysY_Yacc.y"
                                                           {
        (yyval.node) = node("putin", 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 2359 "SysY_Yacc.tab.c"
    break;

  case 100:
#line 338 "SysY_Yacc.y"
                                       {
        (yyval.node) = node("getfloat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2367 "SysY_Yacc.tab.c"
    break;

  case 101:
#line 341 "SysY_Yacc.y"
                                      {
        (yyval.node) = node("getfloat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2375 "SysY_Yacc.tab.c"
    break;

  case 102:
#line 345 "SysY_Yacc.y"
                {
        (yyval.node) = node("args", 1, (yyvsp[0].node));
    }
#line 2383 "SysY_Yacc.tab.c"
    break;

  case 103:
#line 348 "SysY_Yacc.y"
      {
        (yyval.node) = node("args", 0);
    }
#line 2391 "SysY_Yacc.tab.c"
    break;

  case 104:
#line 351 "SysY_Yacc.y"
                                     {
            (yyval.node) = node("arg_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2399 "SysY_Yacc.tab.c"
    break;

  case 105:
#line 354 "SysY_Yacc.y"
                    {
            (yyval.node) = node("arg_list", 1, (yyvsp[0].node));
        }
#line 2407 "SysY_Yacc.tab.c"
    break;


#line 2411 "SysY_Yacc.tab.c"

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
#line 357 "SysY_Yacc.y"


void yyerror(const char *s) {
    fprintf(stderr, "error at line %d column %d: %s\n", lines, pos_start, s);
}

syntax_tree *parse() {
    lines = pos_start = pos_end = 1;
    gt = new_syntax_tree();
    yyrestart(yyin);
    yyparse();
    return gt;
}

syntax_tree_node *node(const char *name, int children_num, ...) {
    syntax_tree_node *p = new_syntax_tree_node(name);
    syntax_tree_node *child;
    if (children_num == 0) {
        child = new_syntax_tree_node("epsilon");
        syntax_tree_add_child(p, child);
    } else {
        va_list ap;
        va_start(ap, children_num);
        for (int i = 0; i < children_num; ++i) {
            child = va_arg(ap, syntax_tree_node *);
            syntax_tree_add_child(p, child);
        }
        va_end(ap);
    }
    return p;
}
