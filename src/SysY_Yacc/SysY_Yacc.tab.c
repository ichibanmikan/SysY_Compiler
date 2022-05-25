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
#line 20 "SysY_Yacc.y"

    syntax_tree_node* node;

#line 204 "SysY_Yacc.tab.c"

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
#define YYLAST   483

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

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
       0,    36,    36,    40,    43,    46,    49,    52,    55,    58,
      61,    64,    67,    70,    74,    78,    81,    84,    87,    90,
      94,    97,   101,   104,   107,   110,   113,   116,   119,   122,
     125,   128,   132,   135,   138,   141,   144,   147,   150,   153,
     156,   159,   162,   165,   168,   171,   174,   177,   180,   183,
     186,   190,   193,   196,   200,   203,   207,   210,   214,   218,
     221,   224,   227,   231,   235,   238,   242,   245,   249,   252,
     255,   259,   262,   266,   269,   272,   275,   279,   282,   285,
     288,   291,   294,   297,   300,   303,   306,   309,   312,   315,
     318,   321,   324,   328,   331,   335,   336,   339,   344,   347,
     350,   353,   356,   359,   362,   365,   368,   371,   374,   377,
     380,   383,   387,   390,   393,   396
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
  "VOID", "WHILE", "IDENTIFIER", "INTEGER", "FLOATPOINT", "ARRAY",
  "LETTER", "EOL", "COMMENT", "BLANK", "ERROR", "CONTINUE", "BREAK",
  "CONST", "COMMENTONELINE", "GETINT", "GETCH", "GETFLOAT", "GETARRAY",
  "GETFARRAY", "PUTINT", "PUTCH", "PUTFLOAT", "PUTARRAY", "PUTFARRAY",
  "PUTF", "STARTTIME", "STOPTIME", "CONTROLSTRING", "$accept", "program",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,  -179,  -179,  -179,    55,     7,    -1,  -179,  -179,   -10,
    -179,  -179,    13,  -179,  -179,    19,    46,  -179,    40,    50,
    -179,    53,   291,    80,   330,    25,  -179,  -179,    57,    40,
    -179,    13,   291,  -179,  -179,  -179,   425,    47,    18,  -179,
    -179,    59,    92,    97,   105,   106,   107,   108,   109,   110,
     111,   125,   126,   127,  -179,  -179,   131,    73,    28,  -179,
     425,  -179,  -179,  -179,   128,   117,   132,   133,  -179,  -179,
    -179,    10,   291,  -179,    44,  -179,  -179,  -179,   134,  -179,
    -179,    -3,   425,   136,   137,   138,   425,   425,   425,   425,
     425,   425,   425,   101,   140,   142,   425,  -179,  -179,   425,
    -179,  -179,  -179,    86,  -179,  -179,    -4,   147,    55,  -179,
    -179,  -179,   291,  -179,  -179,   143,   153,  -179,  -179,  -179,
     152,   155,   156,   164,   166,   169,   170,   171,  -179,  -179,
    -179,    28,  -179,  -179,    40,  -179,  -179,  -179,  -179,  -179,
     425,  -179,  -179,  -179,  -179,  -179,   425,   425,   425,   179,
    -179,   172,   173,   174,  -179,  -179,   176,   386,   178,   182,
     183,  -179,    57,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
     184,  -179,  -179,  -179,   425,  -179,   187,   425,  -179,  -179,
    -179,   194,   177,   202,    76,    65,    73,  -179,   196,   235,
     425,   425,   425,   425,  -179,  -179,  -179,  -179,   425,   235,
     165,   202,    76,    65,    65,    73,  -179,   235,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    16,    17,     0,     0,     2,     4,     5,     0,
       7,     6,     0,     1,     3,    10,     0,     9,    61,     0,
      57,     0,     0,    25,     0,    12,    19,    14,     0,    62,
      50,     0,     0,    97,    95,    96,     0,     0,    61,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    51,    88,    60,    78,    82,
       0,    94,    89,    92,    17,     0,     0,    23,    27,    21,
      88,     0,     0,    18,    10,     8,    56,    58,     0,    52,
      55,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,     0,
      84,    85,    86,     0,    83,    93,    28,     0,     0,    20,
      13,    87,     0,    53,   115,     0,   112,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
      59,    77,    81,    30,    29,    33,    22,    26,    54,    98,
       0,   102,   103,   104,   105,   106,     0,     0,   113,     0,
     114,     0,     0,     0,    44,    31,     0,     0,     0,     0,
       0,    39,     0,    35,    32,    34,    36,    37,    38,    40,
       0,   107,   108,   109,     0,    48,     0,     0,    42,    41,
      43,     0,    63,    64,    66,    68,    71,    49,     0,     0,
       0,     0,     0,     0,    74,    73,    75,    76,     0,     0,
      45,    65,    67,    69,    70,    72,    47,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,   212,  -179,   191,    20,     2,   -14,   -16,
    -179,  -179,  -179,   112,   135,  -179,  -178,  -179,  -179,  -179,
    -179,    31,   -27,  -179,  -179,   193,   -33,   -12,    64,  -179,
      54,    52,   -70,  -179,   -23,  -179,   146,  -179,   -43,  -179,
     186,  -179,  -179,    99,  -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    16,    17,   161,   162,    25,    26,
      10,    66,    67,    68,   163,   149,   164,   165,   166,   167,
     168,   169,    54,    81,    19,    20,    55,    56,   181,   182,
     183,   184,   185,   198,    57,    99,    58,   103,    59,    60,
      61,    62,    63,   115,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    71,     9,    78,    29,    77,    12,    13,     9,    73,
      80,   200,    70,    73,    97,    98,   112,   104,    24,    21,
       8,   206,   113,    15,    29,    65,     8,     1,     2,   208,
       3,    11,   133,   109,   100,   101,    22,    11,    82,    23,
      24,    24,    72,     4,   102,   110,    18,    24,    70,   114,
      33,    34,    35,   120,   121,   122,   123,   124,   125,   126,
     132,    22,    24,   130,    27,    28,    24,    36,    30,    31,
      32,    37,    79,   194,   195,   196,   197,    97,    98,    83,
      38,    39,    40,     1,     2,   138,     3,    70,   192,   193,
      74,    70,   134,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    36,   150,     1,     2,
      65,    64,    84,   151,   152,   114,   170,    85,    73,    38,
      39,    40,   203,   204,   176,    86,    87,    88,    89,    90,
      91,    92,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    93,    94,    95,    96,   -24,
     106,   186,   108,   107,   186,   111,   170,   117,   118,   119,
     127,   128,    70,   129,   139,    70,   170,   186,   186,   186,
     186,   135,   140,   141,   170,   205,   142,   143,    70,    70,
      70,    70,    33,    34,    35,   144,    70,   145,   146,   147,
     148,   207,   190,   171,   172,   173,   174,   154,   177,    36,
     178,   179,   180,   135,   155,   187,   156,     1,     2,   157,
       3,   158,    38,    39,    40,   189,   191,   199,    14,    75,
     137,   159,   160,     4,    76,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    33,    34,
      35,   188,   136,   202,   201,   131,   105,   153,     0,     0,
       0,     0,     0,   154,     0,    36,     0,     0,     0,   135,
       0,     0,   156,     1,     2,   157,     3,   158,    38,    39,
      40,     0,     0,     0,     0,     0,     0,   159,   160,     4,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,     0,     0,     0,
       0,     0,     0,    33,    34,    35,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      36,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,     0,     0,     0,     0,     0,     0,    33,    34,
      35,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53
};

static const yytype_int16 yycheck[] =
{
      12,    24,     0,    36,    18,    32,     4,     0,     6,    25,
      37,   189,    24,    29,     4,     5,    19,    60,    22,    31,
       0,   199,    25,    33,    38,    23,     6,    28,    29,   207,
      31,     0,    36,    23,     6,     7,    17,     6,    20,    20,
      22,    22,    17,    44,    16,    72,    33,    22,    60,    82,
       3,     4,     5,    86,    87,    88,    89,    90,    91,    92,
     103,    17,    22,    96,    18,    19,    22,    20,    18,    19,
      17,    24,    25,     8,     9,    10,    11,     4,     5,    20,
      33,    34,    35,    28,    29,   112,    31,    99,    12,    13,
      33,   103,   106,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    20,   140,    28,    29,
     108,    31,    20,   146,   147,   148,   149,    20,   134,    33,
      34,    35,   192,   193,   157,    20,    20,    20,    20,    20,
      20,    20,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    20,    20,    20,    17,    21,
      33,   174,    19,    21,   177,    21,   189,    21,    21,    21,
      59,    21,   174,    21,    21,   177,   199,   190,   191,   192,
     193,    24,    19,    21,   207,   198,    21,    21,   190,   191,
     192,   193,     3,     4,     5,    21,   198,    21,    19,    19,
      19,    26,    15,    21,    21,    21,    20,    18,    20,    20,
      18,    18,    18,    24,    25,    18,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    21,    14,    21,     6,    28,
     108,    42,    43,    44,    31,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     3,     4,
       5,   177,   107,   191,   190,    99,    60,   148,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
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
       0,    28,    29,    31,    44,    61,    62,    63,    66,    67,
      70,    81,    67,     0,    63,    33,    64,    65,    33,    84,
      85,    87,    17,    20,    22,    68,    69,    18,    19,    68,
      18,    19,    17,     3,     4,     5,    20,    24,    33,    34,
      35,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    82,    86,    87,    94,    96,    98,
      99,   100,   101,   102,    31,    67,    71,    72,    73,    23,
      87,    94,    17,    69,    33,    65,    85,    82,    86,    25,
      82,    83,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    17,     4,     5,    95,
       6,     7,    16,    97,    98,   100,    33,    21,    19,    23,
      82,    21,    19,    25,    86,   103,   104,    21,    21,    21,
      86,    86,    86,    86,    86,    86,    86,    59,    21,    21,
      86,    96,    98,    36,    68,    24,    74,    73,    82,    21,
      19,    21,    21,    21,    21,    21,    19,    19,    19,    75,
      86,    86,    86,   103,    18,    25,    27,    30,    32,    42,
      43,    66,    67,    74,    76,    77,    78,    79,    80,    81,
      86,    21,    21,    21,    20,    18,    86,    20,    18,    18,
      18,    88,    89,    90,    91,    92,    94,    18,    88,    21,
      15,    14,    12,    13,     8,     9,    10,    11,    93,    21,
      76,    90,    91,    92,    92,    94,    76,    26,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    66,    67,    67,    67,    68,    68,
      69,    69,    70,    71,    71,    71,    72,    72,    73,    73,
      73,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    80,    80,
      81,    82,    82,    82,    83,    83,    84,    84,    85,    86,
      86,    87,    87,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   100,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     3,     2,     4,     3,     1,     1,     1,     2,     1,
       3,     2,     6,     1,     1,     0,     3,     1,     2,     3,
       3,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     5,     7,     5,     2,     3,
       4,     1,     2,     3,     3,     1,     3,     1,     3,     3,
       1,     1,     2,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     3,     1,     1,
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
            (yyval.node) = node("program", 1, (yyvsp[0].node));
            gt->root = (yyval.node);
        }
#line 1595 "SysY_Yacc.tab.c"
    break;

  case 3:
#line 40 "SysY_Yacc.y"
                                                {
                    (yyval.node) = node("declaration_list", 2, (yyvsp[-1].node), (yyvsp[0].node));
                 }
#line 1603 "SysY_Yacc.tab.c"
    break;

  case 4:
#line 43 "SysY_Yacc.y"
                               {
                     (yyval.node) = node("declaration_list", 1, (yyvsp[0].node));
                 }
#line 1611 "SysY_Yacc.tab.c"
    break;

  case 5:
#line 46 "SysY_Yacc.y"
                              {
                (yyval.node) = node("declaration", 1, (yyvsp[0].node));
            }
#line 1619 "SysY_Yacc.tab.c"
    break;

  case 6:
#line 49 "SysY_Yacc.y"
                                        {
                (yyval.node) = node("declaration", 1, (yyvsp[0].node));
            }
#line 1627 "SysY_Yacc.tab.c"
    break;

  case 7:
#line 52 "SysY_Yacc.y"
                             {
                (yyval.node) = node("declaration", 1, (yyvsp[0].node));
            }
#line 1635 "SysY_Yacc.tab.c"
    break;

  case 8:
#line 55 "SysY_Yacc.y"
                                                 {
                (yyval.node) = node("idenfier_size", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1643 "SysY_Yacc.tab.c"
    break;

  case 9:
#line 58 "SysY_Yacc.y"
                             {
                (yyval.node) = node("idenfier_size", 1);
              }
#line 1651 "SysY_Yacc.tab.c"
    break;

  case 10:
#line 61 "SysY_Yacc.y"
                          {
                (yyval.node) = node("idenfier_list", 1, (yyvsp[0].node));
              }
#line 1659 "SysY_Yacc.tab.c"
    break;

  case 11:
#line 64 "SysY_Yacc.y"
                                               {
                (yyval.node) = node("idenfier_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1667 "SysY_Yacc.tab.c"
    break;

  case 12:
#line 67 "SysY_Yacc.y"
                                     {
                (yyval.node) = node("idenfier_list", 2, (yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1675 "SysY_Yacc.tab.c"
    break;

  case 13:
#line 70 "SysY_Yacc.y"
                                                          {
                (yyval.node) = node("idenfier_list", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1683 "SysY_Yacc.tab.c"
    break;

  case 14:
#line 74 "SysY_Yacc.y"
                                                        {
                    (yyval.node) = node("var_declaration", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1691 "SysY_Yacc.tab.c"
    break;

  case 15:
#line 78 "SysY_Yacc.y"
                     {
                    (yyval.node) = node("type_specifier", 1, (yyvsp[0].node));
                }
#line 1699 "SysY_Yacc.tab.c"
    break;

  case 16:
#line 81 "SysY_Yacc.y"
                       {
                    (yyval.node) = node("type_specifier", 1, (yyvsp[0].node));
                }
#line 1707 "SysY_Yacc.tab.c"
    break;

  case 17:
#line 84 "SysY_Yacc.y"
                      {
                    (yyval.node) = node("type_specifier", 1, (yyvsp[0].node));
                }
#line 1715 "SysY_Yacc.tab.c"
    break;

  case 18:
#line 87 "SysY_Yacc.y"
                                  {
              (yyval.node) = node("array_size", 2, (yyvsp[-1].node), (yyvsp[0].node));
           }
#line 1723 "SysY_Yacc.tab.c"
    break;

  case 19:
#line 90 "SysY_Yacc.y"
                       {
              (yyval.node) = node("array_size", 1, (yyvsp[0].node));
           }
#line 1731 "SysY_Yacc.tab.c"
    break;

  case 20:
#line 94 "SysY_Yacc.y"
                                                  {
            (yyval.node) = node("array_cell", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
          }
#line 1739 "SysY_Yacc.tab.c"
    break;

  case 21:
#line 97 "SysY_Yacc.y"
                             {
            (yyval.node) = node("array_cell", 2, (yyvsp[-1].node), (yyvsp[0].node));
          }
#line 1747 "SysY_Yacc.tab.c"
    break;

  case 22:
#line 101 "SysY_Yacc.y"
                                                                                         {
                    (yyval.node) = node("fun_declaration", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1755 "SysY_Yacc.tab.c"
    break;

  case 23:
#line 104 "SysY_Yacc.y"
                    {
            (yyval.node) = node("params", 1, (yyvsp[0].node));
        }
#line 1763 "SysY_Yacc.tab.c"
    break;

  case 24:
#line 107 "SysY_Yacc.y"
              {
            (yyval.node) = node("params" ,1, (yyvsp[0].node));
        }
#line 1771 "SysY_Yacc.tab.c"
    break;

  case 25:
#line 110 "SysY_Yacc.y"
          {
          (yyval.node) = node("param", 0);
        }
#line 1779 "SysY_Yacc.tab.c"
    break;

  case 26:
#line 113 "SysY_Yacc.y"
                                    {
                (yyval.node) = node("param_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1787 "SysY_Yacc.tab.c"
    break;

  case 27:
#line 116 "SysY_Yacc.y"
                   {
                (yyval.node) = node("param_list", 1, (yyvsp[0].node));
            }
#line 1795 "SysY_Yacc.tab.c"
    break;

  case 28:
#line 119 "SysY_Yacc.y"
                                  {
            (yyval.node) = node("param", 2, (yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1803 "SysY_Yacc.tab.c"
    break;

  case 29:
#line 122 "SysY_Yacc.y"
                                            {
        (yyval.node) = node("param", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1811 "SysY_Yacc.tab.c"
    break;

  case 30:
#line 125 "SysY_Yacc.y"
                                      {
        (yyval.node) = node("param", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1819 "SysY_Yacc.tab.c"
    break;

  case 31:
#line 128 "SysY_Yacc.y"
                                             {
                    (yyval.node) = node("compound_stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1827 "SysY_Yacc.tab.c"
    break;

  case 32:
#line 132 "SysY_Yacc.y"
                                          {
                    (yyval.node) = node("statement_list", 2, (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1835 "SysY_Yacc.tab.c"
    break;

  case 33:
#line 135 "SysY_Yacc.y"
                  {
                    (yyval.node) = node("statement_list", 0);
                }
#line 1843 "SysY_Yacc.tab.c"
    break;

  case 34:
#line 138 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1851 "SysY_Yacc.tab.c"
    break;

  case 35:
#line 141 "SysY_Yacc.y"
                           {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1859 "SysY_Yacc.tab.c"
    break;

  case 36:
#line 144 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1867 "SysY_Yacc.tab.c"
    break;

  case 37:
#line 147 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1875 "SysY_Yacc.tab.c"
    break;

  case 38:
#line 150 "SysY_Yacc.y"
                         {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1883 "SysY_Yacc.tab.c"
    break;

  case 39:
#line 153 "SysY_Yacc.y"
                            {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1891 "SysY_Yacc.tab.c"
    break;

  case 40:
#line 156 "SysY_Yacc.y"
                                        {
                (yyval.node) = node("statement", 1, (yyvsp[0].node));
            }
#line 1899 "SysY_Yacc.tab.c"
    break;

  case 41:
#line 159 "SysY_Yacc.y"
                             {
              (yyval.node) = node("statement", 2, (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1907 "SysY_Yacc.tab.c"
    break;

  case 42:
#line 162 "SysY_Yacc.y"
                                {
              (yyval.node) = node("statement", 2, (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1915 "SysY_Yacc.tab.c"
    break;

  case 43:
#line 165 "SysY_Yacc.y"
                                       {
                    (yyval.node) = node("expression_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1923 "SysY_Yacc.tab.c"
    break;

  case 44:
#line 168 "SysY_Yacc.y"
                           {
                    (yyval.node) = node("expression_stmt", 1, (yyvsp[0].node));
                }
#line 1931 "SysY_Yacc.tab.c"
    break;

  case 45:
#line 171 "SysY_Yacc.y"
                                                                       {
                    (yyval.node) = node("selection_stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1939 "SysY_Yacc.tab.c"
    break;

  case 46:
#line 174 "SysY_Yacc.y"
                                                                                      {
                    (yyval.node) = node("selection_stmt", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1947 "SysY_Yacc.tab.c"
    break;

  case 47:
#line 177 "SysY_Yacc.y"
                                                                          {
                    (yyval.node) = node("iteration_stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1955 "SysY_Yacc.tab.c"
    break;

  case 48:
#line 180 "SysY_Yacc.y"
                               {
                (yyval.node) = node("return_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1963 "SysY_Yacc.tab.c"
    break;

  case 49:
#line 183 "SysY_Yacc.y"
                                         {
                (yyval.node) = node("return_stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 1971 "SysY_Yacc.tab.c"
    break;

  case 50:
#line 186 "SysY_Yacc.y"
                                                                                       {
                              (yyval.node) = node("const_declartion_assignment", 3, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
                            }
#line 1979 "SysY_Yacc.tab.c"
    break;

  case 51:
#line 190 "SysY_Yacc.y"
                          {
                (yyval.node) = node("init_val_size", 1, (yyvsp[0].node));
              }
#line 1987 "SysY_Yacc.tab.c"
    break;

  case 52:
#line 193 "SysY_Yacc.y"
                            {
                (yyval.node) = node("init_val_size", 2, (yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1995 "SysY_Yacc.tab.c"
    break;

  case 53:
#line 196 "SysY_Yacc.y"
                                               {
                (yyval.node) = node("init_val_size", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
              }
#line 2003 "SysY_Yacc.tab.c"
    break;

  case 54:
#line 200 "SysY_Yacc.y"
                                                           {
                      (yyval.node) = node("array_init_val_size_size", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 2011 "SysY_Yacc.tab.c"
    break;

  case 55:
#line 203 "SysY_Yacc.y"
                                {
                    (yyval.node) = node("init_val_size_size", 1, (yyvsp[0].node));
                  }
#line 2019 "SysY_Yacc.tab.c"
    break;

  case 56:
#line 207 "SysY_Yacc.y"
                                                                                              {
                            (yyval.node) = node("declartion_assignment_size", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                          }
#line 2027 "SysY_Yacc.tab.c"
    break;

  case 57:
#line 210 "SysY_Yacc.y"
                                                           {
                            (yyval.node) = node("declartion_assignment_size", 1, (yyvsp[0].node));
                          }
#line 2035 "SysY_Yacc.tab.c"
    break;

  case 58:
#line 214 "SysY_Yacc.y"
                                                            {
                                    (yyval.node) = node("declartion_assignment_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                                  }
#line 2043 "SysY_Yacc.tab.c"
    break;

  case 59:
#line 218 "SysY_Yacc.y"
                                   {
                (yyval.node) = node("expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
            }
#line 2051 "SysY_Yacc.tab.c"
    break;

  case 60:
#line 221 "SysY_Yacc.y"
                                 {
                (yyval.node) = node("expression", 1, (yyvsp[0].node));
            }
#line 2059 "SysY_Yacc.tab.c"
    break;

  case 61:
#line 224 "SysY_Yacc.y"
                 {
        (yyval.node) = node("var", 1, (yyvsp[0].node));
    }
#line 2067 "SysY_Yacc.tab.c"
    break;

  case 62:
#line 227 "SysY_Yacc.y"
                           {
        (yyval.node) = node("var", 2, (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2075 "SysY_Yacc.tab.c"
    break;

  case 63:
#line 231 "SysY_Yacc.y"
                                      {
                    (yyval.node) = node("logic_expression", 1, (yyvsp[0].node));
                  }
#line 2083 "SysY_Yacc.tab.c"
    break;

  case 64:
#line 235 "SysY_Yacc.y"
                                          {
                      (yyval.node) = node("logic_or_expression", 1, (yyvsp[0].node));
                    }
#line 2091 "SysY_Yacc.tab.c"
    break;

  case 65:
#line 238 "SysY_Yacc.y"
                                                                {
                      (yyval.node) = node("logic_or_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                    }
#line 2099 "SysY_Yacc.tab.c"
    break;

  case 66:
#line 242 "SysY_Yacc.y"
                                       {
                        (yyval.node) = node("logic_and_expression", 1, (yyvsp[0].node));
                      }
#line 2107 "SysY_Yacc.tab.c"
    break;

  case 67:
#line 245 "SysY_Yacc.y"
                                                                 {
                        (yyval.node) = node("logic_and_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                      }
#line 2115 "SysY_Yacc.tab.c"
    break;

  case 68:
#line 249 "SysY_Yacc.y"
                                   {
            (yyval.node) = node("equal_expression", 1, (yyvsp[0].node));
          }
#line 2123 "SysY_Yacc.tab.c"
    break;

  case 69:
#line 252 "SysY_Yacc.y"
                                                {
            (yyval.node) = node("equal_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
          }
#line 2131 "SysY_Yacc.tab.c"
    break;

  case 70:
#line 255 "SysY_Yacc.y"
                                                 {
            (yyval.node) = node("equal_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
          }
#line 2139 "SysY_Yacc.tab.c"
    break;

  case 71:
#line 259 "SysY_Yacc.y"
                                      {
            (yyval.node) = node("additive_expression", 1, (yyvsp[0].node));
          }
#line 2147 "SysY_Yacc.tab.c"
    break;

  case 72:
#line 262 "SysY_Yacc.y"
                                                     {
            (yyval.node) = node("additive_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
          }
#line 2155 "SysY_Yacc.tab.c"
    break;

  case 73:
#line 266 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2163 "SysY_Yacc.tab.c"
    break;

  case 74:
#line 269 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2171 "SysY_Yacc.tab.c"
    break;

  case 75:
#line 272 "SysY_Yacc.y"
            {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2179 "SysY_Yacc.tab.c"
    break;

  case 76:
#line 275 "SysY_Yacc.y"
             {
            (yyval.node) = node("relop", 1, (yyvsp[0].node));
        }
#line 2187 "SysY_Yacc.tab.c"
    break;

  case 77:
#line 279 "SysY_Yacc.y"
                                                     {
                        (yyval.node) = node("additive_expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
                    }
#line 2195 "SysY_Yacc.tab.c"
    break;

  case 78:
#line 282 "SysY_Yacc.y"
                          {
                        (yyval.node) = node("additive_expression", 1, (yyvsp[0].node));
                    }
#line 2203 "SysY_Yacc.tab.c"
    break;

  case 79:
#line 285 "SysY_Yacc.y"
            {
            (yyval.node) = node("addop", 1, (yyvsp[0].node));
        }
#line 2211 "SysY_Yacc.tab.c"
    break;

  case 80:
#line 288 "SysY_Yacc.y"
             {
            (yyval.node) = node("addop", 1, (yyvsp[0].node));
        }
#line 2219 "SysY_Yacc.tab.c"
    break;

  case 81:
#line 291 "SysY_Yacc.y"
                         {
            (yyval.node) = node("term", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2227 "SysY_Yacc.tab.c"
    break;

  case 82:
#line 294 "SysY_Yacc.y"
                {
            (yyval.node) = node("term", 1, (yyvsp[0].node));
        }
#line 2235 "SysY_Yacc.tab.c"
    break;

  case 83:
#line 297 "SysY_Yacc.y"
                              {
            (yyval.node) = node("term", 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2243 "SysY_Yacc.tab.c"
    break;

  case 84:
#line 300 "SysY_Yacc.y"
            {
            (yyval.node) = node("mulop", 1, (yyvsp[0].node));
        }
#line 2251 "SysY_Yacc.tab.c"
    break;

  case 85:
#line 303 "SysY_Yacc.y"
             {
            (yyval.node) = node("mulop", 1, (yyvsp[0].node));
        }
#line 2259 "SysY_Yacc.tab.c"
    break;

  case 86:
#line 306 "SysY_Yacc.y"
             {
            (yyval.node) = node("mulop", 1, (yyvsp[0].node));
        }
#line 2267 "SysY_Yacc.tab.c"
    break;

  case 87:
#line 309 "SysY_Yacc.y"
                                            {
            (yyval.node) = node("factor", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2275 "SysY_Yacc.tab.c"
    break;

  case 88:
#line 312 "SysY_Yacc.y"
             {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2283 "SysY_Yacc.tab.c"
    break;

  case 89:
#line 315 "SysY_Yacc.y"
              {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2291 "SysY_Yacc.tab.c"
    break;

  case 90:
#line 318 "SysY_Yacc.y"
                 {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2299 "SysY_Yacc.tab.c"
    break;

  case 91:
#line 321 "SysY_Yacc.y"
                    {
            (yyval.node) = node("factor", 1, (yyvsp[0].node));
        }
#line 2307 "SysY_Yacc.tab.c"
    break;

  case 92:
#line 324 "SysY_Yacc.y"
                 {
            (yyval.node) = node("calllib", 1, (yyvsp[0].node));
        }
#line 2315 "SysY_Yacc.tab.c"
    break;

  case 93:
#line 328 "SysY_Yacc.y"
                                         {
                  (yyval.node) = node("unary_ops_size", 2, (yyvsp[-1].node), (yyvsp[0].node));
                }
#line 2323 "SysY_Yacc.tab.c"
    break;

  case 94:
#line 331 "SysY_Yacc.y"
                          {
                  (yyval.node) = node("unary_ops_size", 1, (yyvsp[0].node));
                }
#line 2331 "SysY_Yacc.tab.c"
    break;

  case 95:
#line 335 "SysY_Yacc.y"
               {}
#line 2337 "SysY_Yacc.tab.c"
    break;

  case 96:
#line 336 "SysY_Yacc.y"
              {
            (yyval.node) = node("unary_ops", 1, (yyvsp[0].node));
          }
#line 2345 "SysY_Yacc.tab.c"
    break;

  case 97:
#line 339 "SysY_Yacc.y"
              {
            (yyval.node) = node("unary_ops", 1, (yyvsp[0].node));
          }
#line 2353 "SysY_Yacc.tab.c"
    break;

  case 98:
#line 344 "SysY_Yacc.y"
                                               {
        (yyval.node) = node("call", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
     }
#line 2361 "SysY_Yacc.tab.c"
    break;

  case 99:
#line 347 "SysY_Yacc.y"
                                         {
        (yyval.node) = node("getint", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2369 "SysY_Yacc.tab.c"
    break;

  case 100:
#line 350 "SysY_Yacc.y"
                                    {
        (yyval.node) = node("getch", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2377 "SysY_Yacc.tab.c"
    break;

  case 101:
#line 353 "SysY_Yacc.y"
                                       {
        (yyval.node) = node("getfloat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2385 "SysY_Yacc.tab.c"
    break;

  case 102:
#line 356 "SysY_Yacc.y"
                                                  {
        (yyval.node) = node("getarray", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2393 "SysY_Yacc.tab.c"
    break;

  case 103:
#line 359 "SysY_Yacc.y"
                                                   {
        (yyval.node) = node("getfarray", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2401 "SysY_Yacc.tab.c"
    break;

  case 104:
#line 362 "SysY_Yacc.y"
                                                {
        (yyval.node) = node("putin", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2409 "SysY_Yacc.tab.c"
    break;

  case 105:
#line 365 "SysY_Yacc.y"
                                              {
        (yyval.node) = node("putch", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2417 "SysY_Yacc.tab.c"
    break;

  case 106:
#line 368 "SysY_Yacc.y"
                                                 {
        (yyval.node) = node("putfloat", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2425 "SysY_Yacc.tab.c"
    break;

  case 107:
#line 371 "SysY_Yacc.y"
                                                                  {
        (yyval.node) = node("putin", 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 2433 "SysY_Yacc.tab.c"
    break;

  case 108:
#line 374 "SysY_Yacc.y"
                                                                   {
        (yyval.node) = node("putin", 4, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node));
    }
#line 2441 "SysY_Yacc.tab.c"
    break;

  case 109:
#line 377 "SysY_Yacc.y"
                                                           {
        (yyval.node) = node("putin", 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 2449 "SysY_Yacc.tab.c"
    break;

  case 110:
#line 380 "SysY_Yacc.y"
                                       {
        (yyval.node) = node("getfloat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2457 "SysY_Yacc.tab.c"
    break;

  case 111:
#line 383 "SysY_Yacc.y"
                                      {
        (yyval.node) = node("getfloat", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2465 "SysY_Yacc.tab.c"
    break;

  case 112:
#line 387 "SysY_Yacc.y"
                {
        (yyval.node) = node("args", 1, (yyvsp[0].node));
    }
#line 2473 "SysY_Yacc.tab.c"
    break;

  case 113:
#line 390 "SysY_Yacc.y"
      {
        (yyval.node) = node("args", 0);
    }
#line 2481 "SysY_Yacc.tab.c"
    break;

  case 114:
#line 393 "SysY_Yacc.y"
                                     {
            (yyval.node) = node("arg_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 2489 "SysY_Yacc.tab.c"
    break;

  case 115:
#line 396 "SysY_Yacc.y"
                    {
            (yyval.node) = node("arg_list", 1, (yyvsp[0].node));
        }
#line 2497 "SysY_Yacc.tab.c"
    break;


#line 2501 "SysY_Yacc.tab.c"

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
#line 399 "SysY_Yacc.y"


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
