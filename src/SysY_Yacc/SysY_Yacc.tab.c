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

extern int yylex();
extern FILE* yyin;
extern int lines;
extern char *yytext;
extern int pos_end;
extern int pos_start;
extern void yyrestart  (FILE * input_file );

syntax_tree *gt;

void yyerror(const char *s);

syntax_tree_node *node(const char *node_name, int children_num, ...);

#line 88 "SysY_Yacc.tab.c"

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
    NOT = 258,
    ADD = 259,
    SUB = 260,
    MUL = 261,
    DIV = 262,
    LT = 263,
    LTE = 264,
    GT = 265,
    GTE = 266,
    EQ = 267,
    NEQ = 268,
    AND = 269,
    OR = 270,
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
    LETTER = 291,
    EOL = 292,
    COMMENT = 293,
    BLANK = 294,
    ERROR = 295,
    CONTINUE = 296,
    BREAK = 297,
    CONST = 298,
    COMMENTONELINE = 299,
    GETINT = 300,
    GETCH = 301,
    GETFLOAT = 302,
    GETARRAY = 303,
    GETFARRAY = 304,
    PUTINT = 305,
    PUTCH = 306,
    PUTFLOAT = 307,
    PUTARRAY = 308,
    PUTFARRAY = 309,
    PUTF = 310,
    STARTTIME = 311,
    STOPTIME = 312,
    CONTROLSTRING = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "SysY_Yacc.y"

    syntax_tree_node* node;

#line 203 "SysY_Yacc.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   478

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

#define YYUNDEFTOK  2
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    36,    36,    38,    42,    47,    50,    53,    56,    60,
      64,    67,    72,    76,    83,    87,    90,    93,    96,   100,
     105,   108,   112,   115,   118,   121,   124,   128,   132,   135,
     138,   142,   146,   149,   152,   155,   158,   161,   164,   167,
     170,   173,   176,   179,   182,   192,   195,   198,   201,   204,
     208,   211,   214,   218,   222,   227,   231,   236,   242,   247,
     250,   253,   258,   262,   265,   271,   274,   280,   283,   288,
     294,   297,   303,   306,   309,   312,   316,   321,   324,   327,
     330,   335,   347,   350,   372,   375,   378,   381,   384,   387,
     390,   393,   396,   400,   406,   413,   416,   419,   423,   427,
     430,   433,   436,   439,   442,   445,   448,   451,   454,   457,
     460,   463,   467,   470,   473,   477
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NOT", "ADD", "SUB", "MUL", "DIV", "LT",
  "LTE", "GT", "GTE", "EQ", "NEQ", "AND", "OR", "MOD", "ASSIGN",
  "SEMICOLON", "COMMA", "LPARENTHESE", "RPARENTHESE", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "ELSE", "IF", "INT", "FLOAT", "RETURN",
  "VOID", "WHILE", "IDENTIFIER", "INTEGER", "FLOATPOINT", "LETTER", "EOL",
  "COMMENT", "BLANK", "ERROR", "CONTINUE", "BREAK", "CONST",
  "COMMENTONELINE", "GETINT", "GETCH", "GETFLOAT", "GETARRAY", "GETFARRAY",
  "PUTINT", "PUTCH", "PUTFLOAT", "PUTARRAY", "PUTFARRAY", "PUTF",
  "STARTTIME", "STOPTIME", "CONTROLSTRING", "$accept", "program",
  "declaration_list", "declaration", "idenfier_size", "idenfier_list",
  "var_declaration", "type_specifier", "array_size", "array_cell",
  "fun_declaration", "params", "param_list", "param", "compound_stmt",
  "statement_list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "const_declartion_assignment",
  "init_val_size", "init_val_size_size", "declartion_assignment_size",
  "declartion_assignment_expression", "expression", "var",
  "logic_expression", "logic_or_expression", "logic_and_expression",
  "equal_expression", "relop_expression", "relop", "additive_expression",
  "addop", "term", "mulop", "factor", "unary_ops_size", "unary_ops",
  "call", "calllib", "args", "arg_list", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,  -175,  -175,  -175,    40,    62,   -11,  -175,  -175,    37,
    -175,  -175,    47,  -175,  -175,    20,     9,  -175,    57,    28,
    -175,    64,    85,    44,   328,    21,  -175,  -175,    50,    57,
    -175,    47,    85,  -175,  -175,  -175,   421,   290,    54,  -175,
    -175,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,  -175,  -175,    67,    46,    15,  -175,
     421,  -175,  -175,  -175,    87,    89,    90,    93,  -175,  -175,
    -175,    10,    85,  -175,    22,  -175,  -175,  -175,   102,  -175,
    -175,     4,   421,   103,   105,   106,   421,   421,   421,   421,
     421,   421,   421,    70,   108,   122,   421,  -175,  -175,   421,
    -175,  -175,  -175,   421,  -175,  -175,    57,   120,    40,  -175,
    -175,  -175,    85,  -175,  -175,   124,   127,  -175,  -175,  -175,
     126,   128,   129,   130,   132,   135,   137,   139,  -175,  -175,
    -175,    15,  -175,   421,    57,  -175,  -175,  -175,  -175,  -175,
     421,  -175,  -175,  -175,  -175,  -175,   421,   421,   421,  -175,
     180,  -175,   138,   140,   141,  -175,  -175,   144,   383,   145,
     142,   154,  -175,    50,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,   155,  -175,  -175,  -175,   421,  -175,   156,   421,  -175,
    -175,  -175,   157,   133,   163,    48,    56,    46,  -175,   165,
     235,   421,   421,   421,   421,  -175,  -175,  -175,  -175,   421,
     235,   162,   163,    48,    56,    56,    46,  -175,   235,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    16,    17,     0,     0,     2,     4,     5,     0,
       7,     6,     0,     1,     3,    10,     0,     9,    60,     0,
      56,     0,     0,    25,     0,    12,    19,    14,     0,    61,
      49,     0,     0,    97,    95,    96,     0,     0,    60,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    50,    88,    59,    77,    82,
       0,    94,    89,    92,    17,     0,     0,    23,    27,    21,
      88,     0,     0,    18,    10,     8,    55,    57,     0,    51,
      54,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,     0,
      84,    85,    86,     0,    83,    93,    28,     0,     0,    20,
      13,    87,     0,    52,   115,     0,   112,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
      58,    76,    80,     0,    29,    32,    22,    26,    53,    98,
       0,   102,   103,   104,   105,   106,     0,     0,   113,    81,
       0,   114,     0,     0,     0,    43,    30,     0,     0,     0,
       0,     0,    38,     0,    34,    31,    33,    35,    36,    37,
      39,     0,   107,   108,   109,     0,    47,     0,     0,    41,
      40,    42,     0,    62,    63,    65,    67,    70,    48,     0,
       0,     0,     0,     0,     0,    73,    72,    74,    75,     0,
       0,    44,    64,    66,    68,    69,    71,    46,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,   183,  -175,   164,    30,     2,   -14,   -18,
    -175,  -175,  -175,    88,    92,  -175,  -174,  -175,  -175,  -175,
    -175,    35,   -27,  -175,  -175,   159,   -33,   -12,    13,  -175,
       3,     1,  -116,  -175,   -23,  -175,    96,  -175,   -51,    94,
     -47,  -175,  -175,    53,  -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    16,    17,   162,   163,    25,    26,
      10,    66,    67,    68,   164,   150,   165,   166,   167,   168,
     169,   170,    54,    81,    19,    20,    55,    56,   182,   183,
     184,   185,   186,   199,    57,    99,    58,   103,    59,    60,
      61,    62,    63,   115,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    71,     9,    78,    29,    77,    12,    73,     9,   104,
      80,    73,    70,   105,    97,    98,   201,     1,     2,    21,
       3,   100,   101,   112,    29,    65,   207,    27,    28,   113,
       8,   102,     4,   109,   209,    11,     8,    22,    72,    22,
      23,    11,    24,    24,    24,   110,    30,    31,    70,   114,
      97,    98,   132,   120,   121,   122,   123,   124,   125,   126,
     193,   194,    13,   130,   195,   196,   197,   198,     1,     2,
      15,     3,     1,     2,    82,    64,    24,   204,   205,    24,
      18,    32,   149,    74,    96,   138,   105,    70,    33,    34,
      35,    70,   134,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    36,    95,   151,   -24,    37,
      65,   107,   108,   152,   153,   114,    73,   171,    38,    39,
      40,    70,   106,   111,   117,   177,   118,   119,   127,   128,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   129,   135,   139,   140,   141,   191,   142,
     143,   144,   187,   145,   146,   187,   147,   171,   148,   172,
     179,   173,   174,    70,   175,   178,    70,   171,   187,   187,
     187,   187,   180,   181,   188,   171,   206,   192,   190,    70,
      70,    70,    70,    33,    34,    35,   200,    70,   208,    14,
      76,   189,    75,   203,   202,   131,   137,   133,   155,   136,
      36,   154,     0,     0,   135,   156,     0,   157,     1,     2,
     158,     3,   159,    38,    39,    40,     0,     0,     0,     0,
       0,   160,   161,     4,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,    36,     0,     0,     0,   135,
       0,     0,   157,     1,     2,   158,     3,   159,    38,    39,
      40,     0,     0,     0,     0,     0,   160,   161,     4,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,    37,    79,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,     0,     0,
       0,    33,    34,    35,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    36,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,     0,
       0,     0,     0,     0,    33,    34,    35,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

static const yytype_int16 yycheck[] =
{
      12,    24,     0,    36,    18,    32,     4,    25,     6,    60,
      37,    29,    24,    60,     4,     5,   190,    28,    29,    31,
      31,     6,     7,    19,    38,    23,   200,    18,    19,    25,
       0,    16,    43,    23,   208,     0,     6,    17,    17,    17,
      20,     6,    22,    22,    22,    72,    18,    19,    60,    82,
       4,     5,   103,    86,    87,    88,    89,    90,    91,    92,
      12,    13,     0,    96,     8,     9,    10,    11,    28,    29,
      33,    31,    28,    29,    20,    31,    22,   193,   194,    22,
      33,    17,   133,    33,    17,   112,   133,    99,     3,     4,
       5,   103,   106,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,   140,    21,    24,
     108,    21,    19,   146,   147,   148,   134,   150,    33,    34,
      35,   133,    33,    21,    21,   158,    21,    21,    58,    21,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    21,    24,    21,    19,    21,    15,    21,
      21,    21,   175,    21,    19,   178,    19,   190,    19,    21,
      18,    21,    21,   175,    20,    20,   178,   200,   191,   192,
     193,   194,    18,    18,    18,   208,   199,    14,    21,   191,
     192,   193,   194,     3,     4,     5,    21,   199,    26,     6,
      31,   178,    28,   192,   191,    99,   108,   103,    18,   107,
      20,   148,    -1,    -1,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    20,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,    31,    43,    60,    61,    62,    65,    66,
      69,    80,    66,     0,    62,    33,    63,    64,    33,    83,
      84,    86,    17,    20,    22,    67,    68,    18,    19,    67,
      18,    19,    17,     3,     4,     5,    20,    24,    33,    34,
      35,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    81,    85,    86,    93,    95,    97,
      98,    99,   100,   101,    31,    66,    70,    71,    72,    23,
      86,    93,    17,    68,    33,    64,    84,    81,    85,    25,
      81,    82,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    17,     4,     5,    94,
       6,     7,    16,    96,    97,    99,    33,    21,    19,    23,
      81,    21,    19,    25,    85,   102,   103,    21,    21,    21,
      85,    85,    85,    85,    85,    85,    85,    58,    21,    21,
      85,    95,    97,    98,    67,    24,    73,    72,    81,    21,
      19,    21,    21,    21,    21,    21,    19,    19,    19,    97,
      74,    85,    85,    85,   102,    18,    25,    27,    30,    32,
      41,    42,    65,    66,    73,    75,    76,    77,    78,    79,
      80,    85,    21,    21,    21,    20,    18,    85,    20,    18,
      18,    18,    87,    88,    89,    90,    91,    93,    18,    87,
      21,    15,    14,    12,    13,     8,     9,    10,    11,    92,
      21,    75,    89,    90,    91,    91,    93,    75,    26,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    66,    66,    66,    67,    67,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      73,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    79,    79,    80,
      81,    81,    81,    82,    82,    83,    83,    84,    85,    85,
      86,    86,    87,    88,    88,    89,    89,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    96,    96,    96,    97,    97,    97,
      97,    97,    97,    98,    98,    99,    99,    99,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     3,     2,     4,     3,     1,     1,     1,     2,     1,
       3,     2,     6,     1,     1,     0,     3,     1,     2,     3,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     5,     7,     5,     2,     3,     4,
       1,     2,     3,     3,     1,     3,     1,     3,     3,     1,
       1,     2,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     4,     1,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     4,     3,
       3,     3,     4,     4,     4,     4,     4,     6,     6,     6,
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
#line 36 "SysY_Yacc.y"
                           {
        }
#line 1590 "SysY_Yacc.tab.c"
    break;

  case 3:
#line 38 "SysY_Yacc.y"
                                                {
                    (yyval.node) = (yyvsp[-1].node);
                    syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                 }
#line 1599 "SysY_Yacc.tab.c"
    break;

  case 4:
#line 42 "SysY_Yacc.y"
                               {
                     (yyval.node) = new_syntax_tree_node("declarations");
                     gt->root = (yyval.node);
                     syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                 }
#line 1609 "SysY_Yacc.tab.c"
    break;

  case 5:
#line 47 "SysY_Yacc.y"
                              {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1617 "SysY_Yacc.tab.c"
    break;

  case 6:
#line 50 "SysY_Yacc.y"
                                        {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1625 "SysY_Yacc.tab.c"
    break;

  case 7:
#line 53 "SysY_Yacc.y"
                             {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1633 "SysY_Yacc.tab.c"
    break;

  case 8:
#line 56 "SysY_Yacc.y"
                                                 {
                (yyval.node) = (yyvsp[-2].node);
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
              }
#line 1642 "SysY_Yacc.tab.c"
    break;

  case 9:
#line 60 "SysY_Yacc.y"
                             {
                (yyval.node) = new_syntax_tree_node("idenfiers");
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
              }
#line 1651 "SysY_Yacc.tab.c"
    break;

  case 10:
#line 64 "SysY_Yacc.y"
                          {
                (yyval.node) = (yyvsp[0].node);
              }
#line 1659 "SysY_Yacc.tab.c"
    break;

  case 11:
#line 67 "SysY_Yacc.y"
                                               {
                (yyval.node) = (yyvsp[-1].node);
                syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
              }
#line 1669 "SysY_Yacc.tab.c"
    break;

  case 12:
#line 72 "SysY_Yacc.y"
                                     {
                (yyval.node) = (yyvsp[-1].node);
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
              }
#line 1678 "SysY_Yacc.tab.c"
    break;

  case 13:
#line 76 "SysY_Yacc.y"
                                                          {
                (yyval.node) = (yyvsp[-1].node);
                syntax_tree_add_child((yyvsp[-3].node), (yyvsp[-2].node));
                syntax_tree_add_child((yyval.node), (yyvsp[-3].node));
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
              }
#line 1689 "SysY_Yacc.tab.c"
    break;

  case 14:
#line 83 "SysY_Yacc.y"
                                                        {
                    (yyval.node) = node("var_declaration", 2, (yyvsp[-2].node), (yyvsp[-1].node));
                }
#line 1697 "SysY_Yacc.tab.c"
    break;

  case 15:
#line 87 "SysY_Yacc.y"
                     {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1705 "SysY_Yacc.tab.c"
    break;

  case 16:
#line 90 "SysY_Yacc.y"
                       {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1713 "SysY_Yacc.tab.c"
    break;

  case 17:
#line 93 "SysY_Yacc.y"
                      {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1721 "SysY_Yacc.tab.c"
    break;

  case 18:
#line 96 "SysY_Yacc.y"
                                  {
              (yyval.node) = (yyvsp[-1].node);
              syntax_tree_add_child((yyval.node), (yyvsp[0].node));
           }
#line 1730 "SysY_Yacc.tab.c"
    break;

  case 19:
#line 100 "SysY_Yacc.y"
                       {
                (yyval.node) = new_syntax_tree_node("array_size");
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
           }
#line 1739 "SysY_Yacc.tab.c"
    break;

  case 20:
#line 105 "SysY_Yacc.y"
                                                  {
            (yyval.node) = (yyvsp[-1].node);
          }
#line 1747 "SysY_Yacc.tab.c"
    break;

  case 21:
#line 108 "SysY_Yacc.y"
                             {
            (yyval.node) = new_syntax_tree_node("void");
          }
#line 1755 "SysY_Yacc.tab.c"
    break;

  case 22:
#line 112 "SysY_Yacc.y"
                                                                                         {
                    (yyval.node) = node("func_declaration", 4, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1763 "SysY_Yacc.tab.c"
    break;

  case 23:
#line 115 "SysY_Yacc.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1771 "SysY_Yacc.tab.c"
    break;

  case 24:
#line 118 "SysY_Yacc.y"
              {
            (yyval.node) = new_syntax_tree_node("void");
        }
#line 1779 "SysY_Yacc.tab.c"
    break;

  case 25:
#line 121 "SysY_Yacc.y"
          {
          (yyval.node) = new_syntax_tree_node("void");
        }
#line 1787 "SysY_Yacc.tab.c"
    break;

  case 26:
#line 124 "SysY_Yacc.y"
                                    {
                (yyval.node) = (yyvsp[-2].node);
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
            }
#line 1796 "SysY_Yacc.tab.c"
    break;

  case 27:
#line 128 "SysY_Yacc.y"
                   {
                (yyval.node) = new_syntax_tree_node("params");
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
            }
#line 1805 "SysY_Yacc.tab.c"
    break;

  case 28:
#line 132 "SysY_Yacc.y"
                                  {
        (yyval.node) = node("param", 2, (yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1813 "SysY_Yacc.tab.c"
    break;

  case 29:
#line 135 "SysY_Yacc.y"
                                            {
        (yyval.node) = node("param_array", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1821 "SysY_Yacc.tab.c"
    break;

  case 30:
#line 138 "SysY_Yacc.y"
                                             {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1829 "SysY_Yacc.tab.c"
    break;

  case 31:
#line 142 "SysY_Yacc.y"
                                          {
                    (yyval.node) = (yyvsp[-1].node);
                    syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                }
#line 1838 "SysY_Yacc.tab.c"
    break;

  case 32:
#line 146 "SysY_Yacc.y"
                  {
                    (yyval.node) = new_syntax_tree_node("stmts");
                }
#line 1846 "SysY_Yacc.tab.c"
    break;

  case 33:
#line 149 "SysY_Yacc.y"
                            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1854 "SysY_Yacc.tab.c"
    break;

  case 34:
#line 152 "SysY_Yacc.y"
                           {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1862 "SysY_Yacc.tab.c"
    break;

  case 35:
#line 155 "SysY_Yacc.y"
                            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1870 "SysY_Yacc.tab.c"
    break;

  case 36:
#line 158 "SysY_Yacc.y"
                            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1878 "SysY_Yacc.tab.c"
    break;

  case 37:
#line 161 "SysY_Yacc.y"
                         {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1886 "SysY_Yacc.tab.c"
    break;

  case 38:
#line 164 "SysY_Yacc.y"
                            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1894 "SysY_Yacc.tab.c"
    break;

  case 39:
#line 167 "SysY_Yacc.y"
                                        {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1902 "SysY_Yacc.tab.c"
    break;

  case 40:
#line 170 "SysY_Yacc.y"
                             {
              (yyval.node) = (yyvsp[-1].node);
            }
#line 1910 "SysY_Yacc.tab.c"
    break;

  case 41:
#line 173 "SysY_Yacc.y"
                                {
              (yyval.node) = (yyvsp[-1].node);
            }
#line 1918 "SysY_Yacc.tab.c"
    break;

  case 42:
#line 176 "SysY_Yacc.y"
                                       {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1926 "SysY_Yacc.tab.c"
    break;

  case 43:
#line 179 "SysY_Yacc.y"
                           {

                }
#line 1934 "SysY_Yacc.tab.c"
    break;

  case 44:
#line 182 "SysY_Yacc.y"
                                                                       {
                    syntax_tree_node* stn;
                    if(!strcmp((yyvsp[0].node)->name, "stmts")){
                      stn = (yyvsp[0].node);
                    } else {
                     stn=new_syntax_tree_node("stmts");
                     syntax_tree_add_child(stn, (yyvsp[0].node));
                    }
                    (yyval.node) = node("if_stmt", 2, (yyvsp[-2].node), stn);
                }
#line 1949 "SysY_Yacc.tab.c"
    break;

  case 45:
#line 192 "SysY_Yacc.y"
                                                                                      {
                    (yyval.node) = node("if_else_stmt", 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1957 "SysY_Yacc.tab.c"
    break;

  case 46:
#line 195 "SysY_Yacc.y"
                                                                          {
                    (yyval.node) = node("while_stmt", 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1965 "SysY_Yacc.tab.c"
    break;

  case 47:
#line 198 "SysY_Yacc.y"
                               {
                (yyval.node) = node("return_stmt", 0);
            }
#line 1973 "SysY_Yacc.tab.c"
    break;

  case 48:
#line 201 "SysY_Yacc.y"
                                         {
                (yyval.node) = node("return_stmt", 1, (yyvsp[-1].node));
            }
#line 1981 "SysY_Yacc.tab.c"
    break;

  case 49:
#line 204 "SysY_Yacc.y"
                                                                                       {
                              (yyval.node) = node("const_declartion_assignment", 2, (yyvsp[-2].node), (yyvsp[-1].node));
                            }
#line 1989 "SysY_Yacc.tab.c"
    break;

  case 50:
#line 208 "SysY_Yacc.y"
                          {
                (yyval.node) = (yyvsp[0].node);
              }
#line 1997 "SysY_Yacc.tab.c"
    break;

  case 51:
#line 211 "SysY_Yacc.y"
                            {
                (yyval.node) = new_syntax_tree_node("unknow_size");
              }
#line 2005 "SysY_Yacc.tab.c"
    break;

  case 52:
#line 214 "SysY_Yacc.y"
                                               {
                (yyval.node) = (yyvsp[-1].node);
              }
#line 2013 "SysY_Yacc.tab.c"
    break;

  case 53:
#line 218 "SysY_Yacc.y"
                                                           {
                      (yyval.node) = (yyvsp[-2].node);
                      syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                  }
#line 2022 "SysY_Yacc.tab.c"
    break;

  case 54:
#line 222 "SysY_Yacc.y"
                                {
                      (yyval.node) = new_syntax_tree_node("init_vals");
                      syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                  }
#line 2031 "SysY_Yacc.tab.c"
    break;

  case 55:
#line 227 "SysY_Yacc.y"
                                                                                              {
                            (yyval.node) = (yyvsp[-2].node);
                            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                          }
#line 2040 "SysY_Yacc.tab.c"
    break;

  case 56:
#line 231 "SysY_Yacc.y"
                                                           {
                            (yyval.node) = new_syntax_tree_node("declartion_assignments");
                            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                          }
#line 2049 "SysY_Yacc.tab.c"
    break;

  case 57:
#line 236 "SysY_Yacc.y"
                                                            {
                                    (yyval.node) = (yyvsp[-1].node);
                                    syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
                                    syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                                  }
#line 2059 "SysY_Yacc.tab.c"
    break;

  case 58:
#line 242 "SysY_Yacc.y"
                                   {
                (yyval.node) = (yyvsp[-1].node);
                syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
                syntax_tree_add_child((yyval.node), (yyvsp[0].node));
            }
#line 2069 "SysY_Yacc.tab.c"
    break;

  case 59:
#line 247 "SysY_Yacc.y"
                                 {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2077 "SysY_Yacc.tab.c"
    break;

  case 60:
#line 250 "SysY_Yacc.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2085 "SysY_Yacc.tab.c"
    break;

  case 61:
#line 253 "SysY_Yacc.y"
                           {
        (yyval.node) = (yyvsp[-1].node);
        syntax_tree_add_child((yyval.node), (yyvsp[0].node));
    }
#line 2094 "SysY_Yacc.tab.c"
    break;

  case 62:
#line 258 "SysY_Yacc.y"
                                      {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 2102 "SysY_Yacc.tab.c"
    break;

  case 63:
#line 262 "SysY_Yacc.y"
                                          {
                      (yyval.node) = (yyvsp[0].node);
                    }
#line 2110 "SysY_Yacc.tab.c"
    break;

  case 64:
#line 265 "SysY_Yacc.y"
                                                                {
                      (yyval.node) = (yyvsp[-1].node);
                      syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
                      syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                    }
#line 2120 "SysY_Yacc.tab.c"
    break;

  case 65:
#line 271 "SysY_Yacc.y"
                                       {
                        (yyval.node) = (yyvsp[0].node);
                      }
#line 2128 "SysY_Yacc.tab.c"
    break;

  case 66:
#line 274 "SysY_Yacc.y"
                                                                 {
                        (yyval.node) = (yyvsp[-1].node);
                        syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
                        syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                      }
#line 2138 "SysY_Yacc.tab.c"
    break;

  case 67:
#line 280 "SysY_Yacc.y"
                                   {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2146 "SysY_Yacc.tab.c"
    break;

  case 68:
#line 283 "SysY_Yacc.y"
                                                {
            (yyval.node) = (yyvsp[-1].node);
            syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
          }
#line 2156 "SysY_Yacc.tab.c"
    break;

  case 69:
#line 288 "SysY_Yacc.y"
                                                 {
            (yyval.node) = (yyvsp[-1].node);
            syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
          }
#line 2166 "SysY_Yacc.tab.c"
    break;

  case 70:
#line 294 "SysY_Yacc.y"
                                      {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2174 "SysY_Yacc.tab.c"
    break;

  case 71:
#line 297 "SysY_Yacc.y"
                                                     {
            (yyval.node) = (yyvsp[-1].node);
            syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
          }
#line 2184 "SysY_Yacc.tab.c"
    break;

  case 72:
#line 303 "SysY_Yacc.y"
            {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2192 "SysY_Yacc.tab.c"
    break;

  case 73:
#line 306 "SysY_Yacc.y"
            {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2200 "SysY_Yacc.tab.c"
    break;

  case 74:
#line 309 "SysY_Yacc.y"
            {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2208 "SysY_Yacc.tab.c"
    break;

  case 75:
#line 312 "SysY_Yacc.y"
             {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2216 "SysY_Yacc.tab.c"
    break;

  case 76:
#line 316 "SysY_Yacc.y"
                                                     {
                        (yyval.node) = (yyvsp[-1].node);
                        syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
                        syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                    }
#line 2226 "SysY_Yacc.tab.c"
    break;

  case 77:
#line 321 "SysY_Yacc.y"
                          {
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 2234 "SysY_Yacc.tab.c"
    break;

  case 78:
#line 324 "SysY_Yacc.y"
            {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2242 "SysY_Yacc.tab.c"
    break;

  case 79:
#line 327 "SysY_Yacc.y"
             {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2250 "SysY_Yacc.tab.c"
    break;

  case 80:
#line 330 "SysY_Yacc.y"
                         {
            (yyval.node) = (yyvsp[-1].node);
            syntax_tree_add_child((yyval.node), (yyvsp[-2].node));
            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
        }
#line 2260 "SysY_Yacc.tab.c"
    break;

  case 81:
#line 335 "SysY_Yacc.y"
                                         {
          (yyval.node) = (yyvsp[-2].node);
          syntax_tree_add_child((yyval.node), (yyvsp[-3].node));
          syntax_tree_add_child((yyval.node), node("unary_ops_factor", 2, (yyvsp[-1].node), (yyvsp[0].node)));

          int temp=(yyval.node)->children[1]->children[0]->children_num;
          if(temp%2==0){
            (yyval.node)->children[1] = (yyvsp[0].node);
          } else {
            (yyval.node)->children[1]->children[0]=new_syntax_tree_node("-");
          }
        }
#line 2277 "SysY_Yacc.tab.c"
    break;

  case 82:
#line 347 "SysY_Yacc.y"
                {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2285 "SysY_Yacc.tab.c"
    break;

  case 83:
#line 350 "SysY_Yacc.y"
                              {
            (yyval.node) = node("unary_ops_factor", 2, (yyvsp[-1].node), (yyvsp[0].node));
            int tempSub=0, tempNot=0;
            for(int i=0; i<(yyval.node)->children[0]->children_num; i++){
              if((yyval.node)->children[0]->children[i]->name[0]=='!'){
                tempNot++;
              }else if((yyval.node)->children[0]->children[i]->name[0]=='-'){
                tempSub++;
              }
            }
            if(tempNot%2==0&&tempSub%2==0){
              (yyval.node) = (yyvsp[0].node);
            } else {
              if(tempNot%2==1&&tempSub%2==1){
                (yyval.node)->children[0]=new_syntax_tree_node("!-");
              } else if(tempNot%2==0) {
                (yyval.node)->children[0]=new_syntax_tree_node("-");
              } else if(tempSub%2==0) {
                (yyval.node)->children[0]=new_syntax_tree_node("!");
              }
            }
        }
#line 2312 "SysY_Yacc.tab.c"
    break;

  case 84:
#line 372 "SysY_Yacc.y"
            {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2320 "SysY_Yacc.tab.c"
    break;

  case 85:
#line 375 "SysY_Yacc.y"
             {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2328 "SysY_Yacc.tab.c"
    break;

  case 86:
#line 378 "SysY_Yacc.y"
             {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2336 "SysY_Yacc.tab.c"
    break;

  case 87:
#line 381 "SysY_Yacc.y"
                                            {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2344 "SysY_Yacc.tab.c"
    break;

  case 88:
#line 384 "SysY_Yacc.y"
             {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2352 "SysY_Yacc.tab.c"
    break;

  case 89:
#line 387 "SysY_Yacc.y"
              {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2360 "SysY_Yacc.tab.c"
    break;

  case 90:
#line 390 "SysY_Yacc.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2368 "SysY_Yacc.tab.c"
    break;

  case 91:
#line 393 "SysY_Yacc.y"
                    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2376 "SysY_Yacc.tab.c"
    break;

  case 92:
#line 396 "SysY_Yacc.y"
                 {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2384 "SysY_Yacc.tab.c"
    break;

  case 93:
#line 400 "SysY_Yacc.y"
                                         {
                  (yyval.node) = (yyvsp[-1].node);
                  if((yyvsp[0].node)->name[0]!='+'){
                    syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                  }
                }
#line 2395 "SysY_Yacc.tab.c"
    break;

  case 94:
#line 406 "SysY_Yacc.y"
                          {
                  (yyval.node) = new_syntax_tree_node("unary_ops");
                  if((yyvsp[0].node)->name[0]!='+'){
                    syntax_tree_add_child((yyval.node), (yyvsp[0].node));
                  }
                }
#line 2406 "SysY_Yacc.tab.c"
    break;

  case 95:
#line 413 "SysY_Yacc.y"
              {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2414 "SysY_Yacc.tab.c"
    break;

  case 96:
#line 416 "SysY_Yacc.y"
              {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2422 "SysY_Yacc.tab.c"
    break;

  case 97:
#line 419 "SysY_Yacc.y"
              {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2430 "SysY_Yacc.tab.c"
    break;

  case 98:
#line 423 "SysY_Yacc.y"
                                               {
        (yyval.node) = (yyvsp[-3].node);
        syntax_tree_add_child((yyval.node), (yyvsp[-1].node));
     }
#line 2439 "SysY_Yacc.tab.c"
    break;

  case 99:
#line 427 "SysY_Yacc.y"
                                         {
        (yyval.node) = node("getint", 0);
    }
#line 2447 "SysY_Yacc.tab.c"
    break;

  case 100:
#line 430 "SysY_Yacc.y"
                                    {
        (yyval.node) = node("getch", 0);
    }
#line 2455 "SysY_Yacc.tab.c"
    break;

  case 101:
#line 433 "SysY_Yacc.y"
                                       {
        (yyval.node) = node("getfloat", 0);
    }
#line 2463 "SysY_Yacc.tab.c"
    break;

  case 102:
#line 436 "SysY_Yacc.y"
                                                  {
        (yyval.node) = node("getarray", 1, (yyvsp[-1].node));
    }
#line 2471 "SysY_Yacc.tab.c"
    break;

  case 103:
#line 439 "SysY_Yacc.y"
                                                   {
        (yyval.node) = node("getfarray", 1, (yyvsp[-1].node));
    }
#line 2479 "SysY_Yacc.tab.c"
    break;

  case 104:
#line 442 "SysY_Yacc.y"
                                                {
        (yyval.node) = node("putint", 1, (yyvsp[-1].node));
    }
#line 2487 "SysY_Yacc.tab.c"
    break;

  case 105:
#line 445 "SysY_Yacc.y"
                                              {
        (yyval.node) = node("putch", 1, (yyvsp[-1].node));
    }
#line 2495 "SysY_Yacc.tab.c"
    break;

  case 106:
#line 448 "SysY_Yacc.y"
                                                 {
        (yyval.node) = node("putfloat", 1, (yyvsp[-1].node));
    }
#line 2503 "SysY_Yacc.tab.c"
    break;

  case 107:
#line 451 "SysY_Yacc.y"
                                                                  {
        (yyval.node) = node("putarray", 2, (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2511 "SysY_Yacc.tab.c"
    break;

  case 108:
#line 454 "SysY_Yacc.y"
                                                                   {
        (yyval.node) = node("putfarray", 2, (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2519 "SysY_Yacc.tab.c"
    break;

  case 109:
#line 457 "SysY_Yacc.y"
                                                           {
        (yyval.node) = node("putf", 2, (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 2527 "SysY_Yacc.tab.c"
    break;

  case 110:
#line 460 "SysY_Yacc.y"
                                       {
        (yyval.node) = node("starttime", 0);
    }
#line 2535 "SysY_Yacc.tab.c"
    break;

  case 111:
#line 463 "SysY_Yacc.y"
                                      {
        (yyval.node) = node("stoptime", 0);
    }
#line 2543 "SysY_Yacc.tab.c"
    break;

  case 112:
#line 467 "SysY_Yacc.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2551 "SysY_Yacc.tab.c"
    break;

  case 113:
#line 470 "SysY_Yacc.y"
      {
        (yyval.node) = new_syntax_tree_node("epsilon");
    }
#line 2559 "SysY_Yacc.tab.c"
    break;

  case 114:
#line 473 "SysY_Yacc.y"
                                     {
            (yyval.node) = (yyvsp[-2].node);
            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
        }
#line 2568 "SysY_Yacc.tab.c"
    break;

  case 115:
#line 477 "SysY_Yacc.y"
                    {
            (yyval.node) = new_syntax_tree_node("args");
            syntax_tree_add_child((yyval.node), (yyvsp[0].node));
        }
#line 2577 "SysY_Yacc.tab.c"
    break;


#line 2581 "SysY_Yacc.tab.c"

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
#line 481 "SysY_Yacc.y"


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
