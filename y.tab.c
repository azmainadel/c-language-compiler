/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1405075.y" /* yacc.c:339  */

    #include<iostream>
    #include<cstdlib>
    #include<cstring>
    #include<cmath>
    #include <sstream>
    #include "1405075.h"
    #define YYSTYPE SymbolInfo*

    using namespace std;

    namespace patch
    {
        template < typename T > std::string to_string( const T& n )
        {
            std::ostringstream stm ;
            stm << n ;
            return stm.str() ;
        }
    }

    int yyparse(void);
    int yylex(void);
    extern FILE *yyin;

    extern int line_count;
    extern int error_count;
    extern SymbolTable *table;
    string type;
    string rtype;
    FILE *logo;
    FILE *error;

    ofstream asmO;

    vector<string>list;
    vector<string>name;

    int labelCount=0;
    int tempCount=0;

    char *newLabel(){
        char *lb= new char[4];
        strcpy(lb,"L");
        char b[3];
        sprintf(b,"%d", labelCount);
        labelCount++;
        strcat(lb,b);
        return lb;
    }

    char *newTemp(){
        char *t= new char[4];
        strcpy(t,"t");
        char b[3];
        sprintf(b,"%d", tempCount);
        tempCount++;
        strcat(t,b);
        return t;
    }

    void yyerror(string s){
        fprintf(error,"\nError at Line %d : %s\n", line_count, s.c_str());
    }



#line 134 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CONST_INT = 258,
    CONST_FLOAT = 259,
    CONST_CHAR = 260,
    ID = 261,
    INCOP = 262,
    DECOP = 263,
    MULOP = 264,
    ADDOP = 265,
    RELOP = 266,
    LOGICOP = 267,
    ASSIGNOP = 268,
    LPAREN = 269,
    RPAREN = 270,
    RTHIRD = 271,
    LTHIRD = 272,
    LCURL = 273,
    RCURL = 274,
    COMMA = 275,
    SEMICOLON = 276,
    NOT = 277,
    IF = 278,
    ELSE = 279,
    FOR = 280,
    WHILE = 281,
    DO = 282,
    INT = 283,
    CHAR = 284,
    FLOAT = 285,
    DOUBLE = 286,
    VOID = 287,
    RETURN = 288,
    PRINTLN = 289,
    CONTINUE = 290,
    LOWER_THAN_ELSE = 291
  };
#endif
/* Tokens.  */
#define CONST_INT 258
#define CONST_FLOAT 259
#define CONST_CHAR 260
#define ID 261
#define INCOP 262
#define DECOP 263
#define MULOP 264
#define ADDOP 265
#define RELOP 266
#define LOGICOP 267
#define ASSIGNOP 268
#define LPAREN 269
#define RPAREN 270
#define RTHIRD 271
#define LTHIRD 272
#define LCURL 273
#define RCURL 274
#define COMMA 275
#define SEMICOLON 276
#define NOT 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define DO 282
#define INT 283
#define CHAR 284
#define FLOAT 285
#define DOUBLE 286
#define VOID 287
#define RETURN 288
#define PRINTLN 289
#define CONTINUE 290
#define LOWER_THAN_ELSE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    38,    36,     2,    37,     2,    39,     2,     2,
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
      35,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,   102,   106,   116,   121,   126,   137,   165,
     165,   236,   240,   249,   260,   271,   283,   301,   307,   317,
     328,   334,   340,   352,   371,   414,   431,   480,   484,   495,
     499,   503,   503,   507,   511,   514,   517,   520,   535,   542,
     551,   554,   565,   576,   611,   615,   656,   660,   706,   710,
     756,   760,   787,   791,   822,   845,   861,   872,   876,   902,
     904,   907,   910,   911,   929,   953,   956,   960,   964
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST_INT", "CONST_FLOAT", "CONST_CHAR",
  "ID", "INCOP", "DECOP", "MULOP", "ADDOP", "RELOP", "LOGICOP", "ASSIGNOP",
  "LPAREN", "RPAREN", "RTHIRD", "LTHIRD", "LCURL", "RCURL", "COMMA",
  "SEMICOLON", "NOT", "IF", "ELSE", "FOR", "WHILE", "DO", "INT", "CHAR",
  "FLOAT", "DOUBLE", "VOID", "RETURN", "PRINTLN", "CONTINUE", "'+'", "'-'",
  "'*'", "'/'", "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "parameter_list",
  "parameters", "compound_statement", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "@2",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    43,    45,    42,    47,
     291
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   -64,   -64,   -64,    20,    10,   -64,   -64,   -64,   -64,
       6,   -64,   -64,    13,   -10,    10,    25,    31,   -64,    24,
      37,    50,    42,    43,    44,    10,   -64,   -64,    59,   -64,
      45,    58,    60,    67,   -64,   -64,   -64,   -64,   -64,   -64,
      36,    12,    12,   -64,   -64,    12,    61,    64,    65,   163,
      66,   -64,    68,    99,   -64,    45,   -64,    28,    62,   -64,
      70,    41,    75,   -64,   -64,    12,    12,    47,   -64,    72,
     -64,    12,   176,    12,    84,    73,    85,    79,   -64,   -64,
     -64,   -64,   -64,    12,   -64,    12,    12,    12,    12,   -64,
      83,    86,    91,   -64,    93,   176,    95,   -64,   -64,    96,
     -64,   -64,    75,   102,   -64,   -64,    12,   -64,   131,    12,
     131,    94,   -64,    90,   101,   -64,   -64,   131,   131,   -64,
     -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    21,    22,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    25,     0,    12,     0,     0,    19,     0,
      11,    16,     0,    23,     9,     0,    15,    26,     0,     8,
       0,    14,     0,    31,    10,    13,    24,    60,    61,    62,
      42,     0,     0,    18,    40,     0,     0,     0,     0,     0,
       0,    29,     0,    31,    27,     0,    30,    57,     0,    44,
      46,    48,    50,    52,    56,    66,     0,    57,    54,     0,
      55,     0,     0,     0,     0,     0,     0,    25,    17,    28,
      32,    63,    64,     0,    41,     0,     0,     0,     0,    68,
       0,    65,     0,    59,     0,     0,     0,    39,    38,     0,
      45,    47,    51,    49,    53,    58,     0,    43,    31,     0,
      31,     0,    67,    34,     0,    36,    37,    31,    31,    35,
      33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   112,   -64,   -64,   -64,   -64,   -64,    71,
      14,     8,   -64,   -64,   -49,   -64,   -63,   -40,   -42,   -62,
      34,    51,    53,   -39,   -64,   -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    30,    19,    20,    34,
      51,    52,    14,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    67,    68,    89,    79,    67,    70,    75,    10,    95,
      17,    18,    13,    10,     9,    37,    38,    39,    40,     9,
      11,   100,    41,    21,    92,    67,    42,    15,    22,    94,
      16,    96,   109,    31,    45,    81,    82,    23,     1,    24,
       2,    83,     3,    67,   112,    67,    67,    67,    67,   104,
      65,    86,    87,    66,    81,    82,    26,    25,    27,   113,
      28,   115,    32,    33,    35,    29,    67,   114,   119,   120,
      37,    38,    39,    40,    77,    71,    36,    41,    72,    73,
      76,    42,    85,    84,    88,    97,    43,    93,    44,    45,
      46,    99,    47,    48,    98,     1,    16,     2,   105,     3,
      49,    50,    37,    38,    39,    40,   106,   107,   108,    41,
     110,   111,    86,    42,   117,   116,   118,    12,    78,   101,
      44,    45,    46,     0,    47,    48,    80,     1,     0,     2,
       0,     3,    49,    50,    37,    38,    39,    40,   103,   102,
       0,    41,     0,     0,     0,    42,     0,     0,     0,     0,
       0,     0,    44,    45,    46,     0,    47,    48,     0,     1,
       0,     2,     0,     3,    49,    50,    37,    38,    39,    40,
       0,     0,     0,    41,     0,     0,     0,    42,     0,    37,
      38,    39,    40,     0,    74,    45,    41,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,    44,    45
};

static const yytype_int8 yycheck[] =
{
      42,    41,    41,    65,    53,    45,    45,    49,     0,    72,
      20,    21,     6,     5,     0,     3,     4,     5,     6,     5,
       0,    83,    10,    15,    66,    65,    14,    14,     3,    71,
      17,    73,    95,    25,    22,     7,     8,     6,    28,    15,
      30,    13,    32,    83,   106,    85,    86,    87,    88,    88,
      14,    10,    11,    17,     7,     8,     6,    20,    16,   108,
      17,   110,     3,    18,     6,    21,   106,   109,   117,   118,
       3,     4,     5,     6,     6,    14,    16,    10,    14,    14,
      14,    14,    12,    21,     9,     1,    19,    15,    21,    22,
      23,     6,    25,    26,    21,    28,    17,    30,    15,    32,
      33,    34,     3,     4,     5,     6,    20,    16,    15,    10,
      15,    15,    10,    14,    24,    21,    15,     5,    19,    85,
      21,    22,    23,    -1,    25,    26,    55,    28,    -1,    30,
      -1,    32,    33,    34,     3,     4,     5,     6,    87,    86,
      -1,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    30,    -1,    32,    33,    34,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    14,    -1,     3,
       4,     5,     6,    -1,    21,    22,    10,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    30,    32,    42,    43,    44,    45,    46,    51,
      52,     0,    44,     6,    53,    14,    17,    20,    21,    48,
      49,    52,     3,     6,    15,    20,     6,    16,    17,    21,
      47,    52,     3,    18,    50,     6,    16,     3,     4,     5,
       6,    10,    14,    19,    21,    22,    23,    25,    26,    33,
      34,    51,    52,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    14,    17,    58,    64,    59,
      64,    14,    14,    14,    21,    59,    14,     6,    19,    55,
      50,     7,     8,    13,    21,    12,    10,    11,     9,    60,
      66,    67,    59,    15,    59,    57,    59,     1,    21,     6,
      60,    61,    63,    62,    64,    15,    20,    16,    15,    57,
      15,    15,    60,    55,    59,    55,    21,    24,    15,    55,
      55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    47,
      46,    48,    48,    49,    49,    49,    49,    50,    50,    51,
      52,    52,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    55,    55,    55,    55,    55,    55,    55,    55,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     0,
       7,     1,     0,     4,     3,     2,     1,     3,     2,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     0,     2,     7,     5,     7,     5,     5,     3,     3,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     1,     2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 82 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : start : program\n",line_count);
    fprintf(logo,"\nTotal Lines: %d\n",line_count-1);
    fprintf(logo,"\nTotal Errors: %d\n",error_count);

    string s = "";
    s += ".MODEL SMALL\n\n.STACK 100H\n\n.DATA\n";
    s += "\n.CODE\nMAIN PROC\n";
    s += "MOV AX, @DATA\nMOV DS, AX\n";
    s += (yyvsp[0])->code;
    s += "MAIN ENDP\nEND MAIN";

    asmO<<s;
}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : program : program unit\n",line_count);
}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 106 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : program : unit\n",line_count);
}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : unit : var_declaration\n",line_count);
}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 122 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : unit : func_declaration\n",line_count);
}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : unit : func_definition\n",line_count);
    (yyval)=(yyvsp[0]);
}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 138 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n%s\n", line_count, (yyvsp[-4])->getName().c_str());
    (yyvsp[-4])->var_type = (yyvsp[-5])->getType();
    (yyvsp[-4])->a_size = 0;

    if (table->Insert((yyvsp[-4]))){
        SymbolInfo *sp = table->Lookup((yyvsp[-4])->getName());
        if (sp->var_type == "INT") sp->ival = 10;
        else if (sp->var_type == "FLOAT") sp->fval = 10.0;
        for (int i = 0; i < list.size(); i++){
            sp->param_list.push_back(list[i]);
            sp->param_name.push_back(name[i]);
        }
        list.clear();
        name.clear();
    }
    else {
        yyerror("Multiple declaration of "+(yyvsp[-4])->getName());
        error_count++;
    }
}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 165 "1405075.y" /* yacc.c:1646  */
    {
    int flag = 0;
    SymbolInfo *sp = table->Lookup((yyvsp[-3])->getName());
    if (sp){
        table->EnterScope(table->len);
        if (sp->param_list.size() == list.size()){
            for (int i = 0; i < list.size(); i++){
                if (sp->param_list[i] != list[i]){
                    string s = patch::to_string(i+1);
                    yyerror(s+"th parameter mismatch in function "+sp->getName());
                    error_count++;
                    flag = 1;
                    break;
                }
            }
        }
        else {
            yyerror("Number of parameters mismatch");
            error_count++;
            flag = 1;
        }
        list.clear();
        name.clear();
    }

    else{
        (yyvsp[-3])->var_type = (yyvsp[-4])->getType();
        (yyvsp[-3])->a_size = 0;
        table->Insert((yyvsp[-3]));
        sp = table->Lookup((yyvsp[-3])->getName());
        table->EnterScope(table->len);
        if (sp->var_type == "INT") sp->ival = 10;
        else if (sp->var_type == "FLOAT") sp->fval = 10.0;
        else sp->ival = 0;
        for (int i = 0; i < list.size(); i++){
            sp->param_list.push_back(list[i]);
            sp->param_name.push_back(name[i]);
        }
        list.clear();
        name.clear();
    }
    if (flag == 0){
        for (int i = 0; i < sp->param_list.size(); i++){
            SymbolInfo *sp1 = new SymbolInfo();
            sp1->setName(sp->param_name[i]);
            sp1->setType("ID");
            sp1->var_type = sp->param_list[i];

            if (sp->getName() != ""){
                if (table->Insert(sp1) == false){
                    yyerror("Multiple definition of"+sp->getName());
                    error_count++;
                }
            }
        }
    }
    rtype = sp->var_type;
}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 224 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n%s\n",line_count, (yyvsp[-5])->getName().c_str());
    /*cout<<$7->code;*/
    (yyval)=(yyvsp[0]);

}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 236 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : parameter_list  : parameters\n",line_count);
    (yyval)=(yyvsp[0]);
}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 240 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : parameter_list  :\n",line_count);
}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 249 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : parameters : parameters COMMA type_specifier ID\n%s\n",line_count,(yyvsp[0])->getName().c_str());
    if (type != "VOID"){
        list.push_back(type);
        name.push_back((yyvsp[0])->getName());
    }
    else {
        yyerror("Variable can not be of void type");
        error_count++;
    }
}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 260 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : parameters  : parameters COMMA type_specifier\n",line_count);
    if (type != "VOID"){
        list.push_back(type);
        name.push_back("");
    }
    else {
        yyerror("Variable can not be of void type");
        error_count++;
    }
}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 271 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : parameters  : type_specifier ID\n%s\n",line_count,(yyvsp[0])->getName().c_str());

    if (type != "VOID"){
        list.push_back(type);
        name.push_back((yyvsp[0])->getName());
    }
    else {
        yyerror("Variable can not be of void type");
        error_count++;
    }
}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 283 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : parameters  : type_specifier\n",line_count);

    if (type != "VOID"){
        list.push_back(type);
        name.push_back("");
    }
    else {
        yyerror("Variable can not be of void type");
        error_count++;
    }
}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 301 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : compound_statement : LCURL statements RCURL\n",line_count);
    table->ExitScope();

    (yyval)=(yyvsp[-1]);
}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 307 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : compound_statement : LCURL RCURL\n",line_count);
    table->ExitScope();
}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 317 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
    (yyval)=(yyvsp[-1]);
}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 328 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : type_specifier : INT\n",line_count);
    type = "INT";
    (yyval) = new SymbolInfo();
    (yyval)->setType("INT");
}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 334 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : type_specifier : FLOAT\n",line_count);
    type = "FLOAT";
    (yyval) = new SymbolInfo();
    (yyval)->setType("FLOAT");
}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 340 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : type_specifier : VOID\n",line_count);
    type = "VOID";
    (yyval) = new SymbolInfo();
    (yyval)->setType("VOID");
}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 352 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : declaration_list : declaration_list COMMA ID\n%s\n",line_count,(yyvsp[0])->getName().c_str());
    if (type != "VOID"){
        (yyvsp[0])->var_type = type;

        (yyval)=(yyvsp[-2]);
        (yyval)->code += string((yyvsp[0])->symbol)+" DW " + "?\n";

        if (table->Insert((yyvsp[0])) == false){

            yyerror("Multiple Declaration of " + (yyvsp[0])->getName());
            error_count++;
        }
    }
    else{
        yyerror("Variable can not be of void type");
        error_count++;
    }
}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 371 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n%s\n",line_count,(yyvsp[-3])->getName().c_str());

    if (table->LookupCurr((yyvsp[-3])->getName()) != NULL) {
        yyerror("Multiple Declaration of " + (yyvsp[-3])->getName());
        error_count++;
    }
    else if ((yyvsp[-1])->var_type == "FLOAT")  {
        yyerror("Array index must be of 'int' type");
        error_count++;
    }
    else if((yyvsp[-1])->ival < 1) {
        yyerror("Invalid array size");
        error_count++;
    }
    else {
        if (type != "VOID"){
            (yyvsp[-3])->var_type = type;
            (yyvsp[-3])->a_size = (yyvsp[-1])->ival;
            table->Insert((yyvsp[-3]));
            SymbolInfo *sp = table->Lookup((yyvsp[-3])->getName());
            sp->arr = new SymbolInfo[(yyvsp[-1])->ival];
            sp->a_size = (yyvsp[-1])->ival;

            (yyval)=(yyvsp[-5]);
            (yyval)->code += (string)(yyvsp[-3])->symbol + " DW ";

            for (int i = 0; i < (yyvsp[-1])->ival; i++){
                if (type == "INT") sp->arr[i].ival = -1;
                else sp->arr[i].fval = -1.0;
                sp->arr[i].var_type = type;
                sp->arr[i].setType("ID");

                (yyval)->code += "? ";
            }
            (yyval)->code += "\n";
        }
        else{
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 414 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : declaration_list : ID\n%s\n",line_count,(yyvsp[0])->getName().c_str());
    if (type != "VOID"){
        (yyvsp[0])->var_type = type;
        if (table->Insert((yyvsp[0])) == false){
            yyerror("Multiple Declaration of " + (yyvsp[0])->getName());
            error_count++;
        }
    }
    else{
        yyerror("Variable can not be of void type");
        error_count++;
    }
    (yyval) = (yyvsp[0]);
    (yyval) = new SymbolInfo();
    (yyval)->code = string((yyvsp[0])->symbol)+" DW " + "?\n";
}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 431 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : declaration_list : ID LTHIRD CONST_INT RTHIRD\n%s\n",line_count,(yyvsp[-3])->getName().c_str());

    if (table->LookupCurr((yyvsp[-3])->getName()) != NULL) {
        yyerror("Multiple Declaration of " + (yyvsp[-3])->getName());
        error_count++;
    }
    else if ((yyvsp[-1])->var_type == "FLOAT"){
        yyerror("Array index must be of 'int' type");
        error_count++;
    }
    else if((yyvsp[-1])->ival < 1) {
        yyerror("Invalid array size");
        error_count++;
    }
    else {
        if (type != "VOID"){
            (yyvsp[-3])->var_type = type;
            (yyvsp[-3])->a_size = (yyvsp[-1])->ival;
            table->Insert((yyvsp[-3]));
            SymbolInfo *sp = table->Lookup((yyvsp[-3])->getName());
            sp->arr = new SymbolInfo[(yyvsp[-1])->ival];
            sp->a_size = (yyvsp[-1])->ival;

            (yyval)=(yyvsp[-3]);
            (yyval)->code = (string)(yyvsp[-3])->symbol +" DW ";

            for (int i = 0; i < (yyvsp[-1])->ival; i++){
                if (type == "INT") sp->arr[i].ival = -1;
                else sp->arr[i].fval = -1.0;
                sp->arr[i].var_type = type;
                sp->arr[i].setType("ID");

                (yyval)->code += "? ";
            }
            (yyval)->code += "\n";
        }
        else{
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 480 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statements : statement\n",line_count);
    (yyval)=(yyvsp[0]);
}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 484 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statements : statements statement\n",line_count);
    (yyval)=(yyvsp[-1]);
    (yyval)->code += (yyvsp[0])->code;
}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 495 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : var_declaration\n",line_count);
    (yyval)=(yyvsp[0]);
}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 499 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : expression_statement\n",line_count);
    (yyval)=(yyvsp[0]);
}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 503 "1405075.y" /* yacc.c:1646  */
    {table->EnterScope(table->len);}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 503 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : compound_statement\n",line_count);
    (yyval)=(yyvsp[-1]);
}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 507 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
    //BISHAL KAJ
}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 511 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : IF LPAREN expression RPAREN statement\n",line_count);
}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 514 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 517 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : WHILE LPAREN expression RPAREN statement\n",line_count);
}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 520 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n%s\n",line_count,(yyvsp[-2])->getName().c_str());
    SymbolInfo *sp = table->Lookup((yyvsp[-2])->getName());

    if (sp == NULL) {
        yyerror((yyvsp[-2])->getName() + " was not declared in this scope" );
        error_count++;
    }
    else{
        (yyval) = new SymbolInfo();
        (yyval)->code += "MOV DX, " + (yyvsp[-2])->symbol + "\nMOV AH, 2\nINT 21H\n";
    }

    /*cout<<$$->code;*/
}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 535 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : RETURN expression SEMICOLON\n",line_count);
    if (rtype != (yyvsp[-1])->var_type){
        yyerror("Return type does not match");
        error_count++;
    }
}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 542 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : statement : RETURN SEMICOLON error\n",line_count);
}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 551 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : expression_statement : SEMICOLON\n",line_count);
}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 554 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : expression_statement : expression SEMICOLON\n",line_count);
    (yyval) = (yyvsp[-1]);

}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 565 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : variable : ID\n%s\n",line_count,(yyvsp[0])->getName().c_str());
    SymbolInfo* sp = table->Lookup((yyvsp[0])->getName().c_str());

    if (sp != NULL) (yyval) = (yyvsp[0]);
    else{
        (yyval) = NULL;
        yyerror("Undeclared Variable "+(yyvsp[0])->getName());
        error_count++;
    }
}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 576 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : variable : ID LTHIRD expression RTHIRD\n%s\n",line_count,(yyvsp[-3])->getName().c_str());
    SymbolInfo* sp = table->Lookup((yyvsp[-3])->getName().c_str());

    if(sp == NULL){
        yyerror("Undeclared Variable "+(yyvsp[-3])->getName());
        error_count++;
    }
    else if(sp->a_size == -1){
        yyerror("Index on non-array");
        error_count++;
    }
    else if((yyvsp[-1])->var_type == "FLOAT"){
        yyerror("Array index must be of 'int' type");
        error_count++;
    }
    else if((yyvsp[-1])->ival < 0 || (yyvsp[-1])->ival >= sp->a_size){
        yyerror("Array index out of bound");
        error_count++;
    }
    else{
        (yyval) = (yyvsp[-3]);
        (yyval) = &(sp->arr[(yyvsp[-1])->ival]);
        (yyval) = new SymbolInfo();
        (yyval)->code = (yyvsp[-1])->code+"MOV BX, " + (yyvsp[-1])->symbol + "\nADD BX, BX\n";

        /*cout<<$$->code;*/
    }
}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 611 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : expression : logic_expression\n",line_count);
    (yyval) = (yyvsp[0]);
}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 615 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : expression : variable ASSIGNOP logic_expression\n",line_count);
    if ((yyvsp[-2])){
        if ((yyvsp[-2])->var_type != (yyvsp[0])->var_type){
            yyerror("Type not matched");
            error_count++;
        }
        else if ((yyvsp[-2])->a_size == 0){
            yyerror((yyvsp[-2])->getName() + " is not a variable");
            error_count++;
        }
        else if ((yyvsp[-2])->a_size > 0 ){
            yyerror("Index not in Array"); error_count++;
        }
        else if ((yyvsp[-2])->getName() == "" && (yyvsp[0])->var_type == "INT"){
            (yyvsp[-2])->ival = (yyvsp[0])->ival;
        }
        else if ((yyvsp[-2])->getName() == "" && (yyvsp[0])->var_type == "FLOAT"){
            (yyvsp[-2])->fval = (yyvsp[0])->fval;
        }
        else if ((yyvsp[-2])->var_type == "INT" && (yyvsp[0])->var_type == "INT"){
            (yyvsp[-2])->ival = (yyvsp[0])->ival;
        }
        else if ((yyvsp[-2])->var_type == "FLOAT" && (yyvsp[0])->var_type == "FLOAT"){
            (yyvsp[-2])->fval = (yyvsp[0])->fval;
        }
        (yyval) = (yyvsp[-2]);
    }
    table->PrintAllScopeTable();

    (yyval)->code += "MOV AX, " + (yyvsp[0])->symbol + " \n";
    (yyval)->code += "MOV " + (yyvsp[-2])->symbol+", AX\n";


}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 656 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : logic_expression : rel_expression\n",line_count);
    (yyval) = (yyvsp[0]);
}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 660 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
    (yyval) = new SymbolInfo();

    (yyval)=(yyvsp[-2]);
    (yyval)->code += (yyvsp[0])->code;

    char* temp = newTemp();
    char* label1 = newLabel();
    char* label2 = newLabel();

    if((yyvsp[-1])->getName() == "&&"){
        (yyval)->code += "MOV " + (string)temp + ", 1\n";
        (yyval)->code += "MOV AX," + (yyvsp[-2])->getName() + "\n";
        (yyval)->code += "CMP AX, 0\n";
        (yyval)->code += "JE " + (string)label1 + "\n";
        (yyval)->code += "MOV AX, " + (yyvsp[0])->getName() + "\n";
        (yyval)->code += "CMP AX, 0\n";
        (yyval)->code += "JNE " + (string)label2 + "\n";
        (yyval)->code += (string)label1 + ":\n";
        (yyval)->code += "MOV " + (string)temp + ", 0\n";
        (yyval)->code += (string)label2 + ":\n";
        (yyval)->symbol = (string)temp;
    }
    else if((yyvsp[-1])->getName() == "||"){
        (yyval)->code += "MOV " + (string)temp + ", 1\n";
        (yyval)->code += "MOV AX, " +(yyvsp[-2])->getName() + "\n";
        (yyval)->code += "CMP AX, 1\n";
        (yyval)->code += "JE "+ (string)label2 + "\n";
        (yyval)->code += "MOV AX, " + (yyvsp[0])->getName() + "\n";
        (yyval)->code += "CMP AX, 1\n";
        (yyval)->code += "JE " + (string)label2 + "\n";
        (yyval)->code += (string)label1 + ":\n";
        (yyval)->code += "MOV " + (string)temp + ", 0\n";
        (yyval)->code += (string)label2 + ":\n";
        (yyval)->symbol = (string)temp;
    }

    cout<<(yyval)->code;
}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 706 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : rel_expression : simple_expression\n",line_count);
    (yyval) = (yyvsp[0]);
}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 710 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : rel_expression : simple_expression RELOP simple_expression\n",line_count);
    (yyval) = new SymbolInfo();
    (yyval)->setType((yyvsp[-2])->getType());
    (yyval)=(yyvsp[-2]);

    (yyval)->code += (yyvsp[0])->code;
    (yyval)->code += "MOV AX, " + string((yyvsp[-2])->getName()) + "\n";
    (yyval)->code += "CMP AX, " + string((yyvsp[0])->getName()) + "\n";

    char *temp = newTemp();
    char *label1 = newLabel();
    char *label2 = newLabel();

    if((yyvsp[-1])->getName() == "<"){
        (yyval)->code += "JL " + string(label1)+"\n";
    }
    else if((yyvsp[-1])->getName() == "<="){
        (yyval)->code += "JLE " + string(label1)+"\n";
    }
    else if((yyvsp[-1])->getName() == ">"){
        (yyval)->code += "JG " + string(label1)+"\n";
    }
    else if((yyvsp[-1])->getName() == ">="){
        (yyval)->code += "JNL " + string(label1)+"\n";
    }
    else if((yyvsp[-1])->getName() == "=="){
        (yyval)->code+="JE " + string(label1)+"\n";
    }
    else{
        (yyval)->code+="JNE " + string(label1)+"\n";
    }

    (yyval)->code += "MOV "+ string(temp) + ", 0\n";
    (yyval)->code += "JMP " + string(label2) + "\n";
    (yyval)->code += string(label1) + ":\nMOV " + string(temp)+ ", 1\n";
    (yyval)->code += string(label2) + ":\n";
    (yyval)->symbol = temp;

    /*cout<<$$->code;*/
}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 756 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : simple_expression : term\n",line_count);
    (yyval) = (yyvsp[0]);
}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 760 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : simple_expression : simple_expression ADDOP term\n",line_count);
    (yyval) = new SymbolInfo();
    (yyval)->setType((yyvsp[-2])->getType());

    (yyval)=(yyvsp[-2]);
    (yyval)->code += (yyvsp[0])->code;

    if((yyvsp[-1])->getName() == "+"){
        char *temp = newTemp();
        (yyval)->code += "MOV AX, "+ (yyvsp[0])->symbol + "\nADD AX, " + (yyvsp[-2])->symbol + "\nMOV "+ string(temp)+ ", AX\n";

    }
    else{
        char *temp = newTemp();
        (yyval)->code += "MOV AX, "+ (yyvsp[-2])->symbol + "\nSUB AX, " + (yyvsp[0])->symbol + "\nMOV "+ string(temp)+ ", AX\n";
    }
    delete (yyvsp[0]);

    /*cout<<$$->code;*/
}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 787 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : term : unary_expression\n",line_count);
    (yyval) = (yyvsp[0]);
    }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 791 "1405075.y" /* yacc.c:1646  */
    {
        fprintf(logo,"\nLine no %d : term MULOP unary_expression\n",line_count);
        (yyval) = new SymbolInfo();
        (yyval)=(yyvsp[-2]);

        (yyval)->code += (yyvsp[0])->code;
        (yyval)->code += "MOV AX, " + (yyvsp[-2])->symbol +"\n";
        (yyval)->code += "MOV BX, " + (yyvsp[0])->symbol + "\n";

        char *temp = newTemp();

        if((yyvsp[-1])->getName() == "*"){
            (yyval)->code += "MUL BX\n";
            (yyval)->code += "MOV " + string(temp) + ", AX\n";
        }
        else if((yyvsp[-1])->getName() == "/"){
            (yyval)->code += "XOR DX, DX\nDIV BX\nMOV "+ string(temp)+", AX\n";
        }
        else{
            (yyval)->code += "XOR DX, DX\nDIV BX\nMOV "+ string(temp)+", DX\n";
        }
        (yyval)->symbol = temp;

        /*cout<<$$->code;*/
    }
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 822 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : unary_expression : ADDOP unary_expression\n",line_count);
    (yyval) = new SymbolInfo();
    (yyval)->setType((yyvsp[0])->getType());
    (yyval)->var_type = (yyvsp[0])->var_type;

    (yyval)=(yyvsp[0]);

    if ((yyvsp[-1])->getName() == "+"){
        (yyval)->ival = (yyvsp[0])->ival;
        (yyval)->fval = (yyvsp[0])->fval;
    }
    else{
        (yyval)->ival = -(yyvsp[0])->ival;
        (yyval)->fval = -(yyvsp[0])->fval;

        (yyval)->code += "MOV AX, " + (yyvsp[0])->symbol + " \n";
        (yyval)->code += "NEG AX\n";
        (yyval)->code += "MOV " + (yyvsp[0])->symbol + ", AX\n";

        cout<<(yyval)->code;
    }
}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 845 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : unary_expression : NOT unary_expression\n",line_count);
    (yyval) = new SymbolInfo();
    (yyval)->setType((yyvsp[0])->getType());
    (yyval)->var_type = "INT";
    if ((yyvsp[0])->var_type == "INT") (yyval)->ival = !((yyvsp[0])->ival);
    else if ((yyvsp[0])->var_type == "FLOAT") (yyval)->ival = !((yyvsp[0])->fval);

    (yyval)=(yyvsp[0]);
    char *temp=newTemp();
    (yyval)->code="MOV AX, " + (yyvsp[0])->symbol + "\n";
    (yyval)->code+="NOT AX\n";
    (yyval)->code+="MOV "+ string(temp)+ ", AX\n";
    (yyvsp[0])->symbol = string(temp);

}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 861 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : unary_expression : factor\n",line_count);
    (yyval) = (yyvsp[0]);
}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 872 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : factor : variable\n",line_count);
    (yyval) = (yyvsp[0]);
}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 876 "1405075.y" /* yacc.c:1646  */
    {
    SymbolInfo *sp = table->Lookup((yyvsp[-3])->getName());
    if (sp == NULL) {yyerror("Undeclared Function "+(yyvsp[-3])->getName()); error_count++;}
    else{
        fprintf(logo,"\nLine no %d : factor : ID LPAREN argument_list RPAREN\n%s\n",line_count,(yyvsp[-3])->getName().c_str());
        if (sp->a_size != 0){
            yyerror(sp->getName()+" is not a function");
            error_count++;
        }
        else if (sp->param_list.size() == list.size()){
            for (int i = 0; i < sp->param_list.size(); i++){
                if (sp->param_list[i] != list[i]){
                    string s = patch::to_string(i+1);
                    yyerror(s+"th argument mismatch in function"+sp->getName());
                    error_count++;
                    break;
                }
            }
        }
        else {
            yyerror("Number of arguments mismatch");
            error_count++;
        }
    }
    list.clear();
}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 902 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : factor : LPAREN expression RPAREN\n",line_count); (yyval) = (yyvsp[-1]);}
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 904 "1405075.y" /* yacc.c:1646  */
    {
        fprintf(logo,"\nLine no %d : factor : CONST_INT\n%s\n",line_count,(yyvsp[0])->getName().c_str()); (yyval) = (yyvsp[0]);
    }
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 907 "1405075.y" /* yacc.c:1646  */
    {
        fprintf(logo,"\nLine no %d : factor : CONST_FLOAT\n%s\n",line_count,(yyvsp[0])->getName().c_str()); (yyval) = (yyvsp[0]);
    }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 910 "1405075.y" /* yacc.c:1646  */
    {;}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 911 "1405075.y" /* yacc.c:1646  */
    {
        SymbolInfo *sp = table->Lookup((yyvsp[-1])->getName());
        if (sp){
            if ((yyvsp[-1])->var_type == "INT"){
                (yyvsp[-1])->ival++;
                sp->ival = (yyvsp[-1])->ival;
            }
            else if ((yyvsp[-1])->var_type == "FLOAT"){
                (yyvsp[-1])->fval++;
                sp->fval = (yyvsp[-1])->fval;
            }
        }
        else yyerror("");
        (yyval) = (yyvsp[-1]);
        fprintf(logo,"\nLine no %d : factor : variable INCOP\n",line_count);

        (yyval)->code += "INC " + (yyvsp[-1])->symbol + " \n";
    }
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 929 "1405075.y" /* yacc.c:1646  */
    {
        SymbolInfo *sp = table->Lookup((yyvsp[-1])->getName());
        if (sp){
            if ((yyvsp[-1])->var_type == "INT"){
                (yyvsp[-1])->ival--;
                sp->ival = (yyvsp[-1])->ival;
            }
            else if ((yyvsp[-1])->var_type == "FLOAT"){
                (yyvsp[-1])->fval--;
                sp->fval = (yyvsp[-1])->fval;
            }
        }
        else yyerror("");
        (yyval) = (yyvsp[-1]);
        fprintf(logo,"\nLine no %d : factor : variable DECOP\n",line_count);

        (yyval)->code += "DEC " + (yyvsp[-1])->symbol + " \n";
    }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 953 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : argument_list : arguments\n",line_count);
}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 956 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : argument_list : \n",line_count);
}
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 960 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : arguments : arguments COMMA logic_expression\n",line_count);
    list.push_back((yyvsp[0])->var_type);
}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 964 "1405075.y" /* yacc.c:1646  */
    {
    fprintf(logo,"\nLine no %d : arguments : logic_expression\n",line_count);
    list.push_back((yyvsp[0])->var_type);
}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2513 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 974 "1405075.y" /* yacc.c:1906  */


int main(int argc,char *argv[])
{
    FILE *fp;
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Cannot Open Input File.\n");
        exit(1);
    }
    logo = fopen("log.txt","w");
    error = fopen("error.txt","w");
    /*asmOut = fopen("code.asm","w");*/

    asmO.open("code.asm");

    yyin=fp;
    yyparse();
    fprintf(logo,"\nTotal Lines: %d\n",line_count-1);
    fprintf(logo,"\nTotal Errors: %d\n",error_count);

    fclose(fp);
    fclose(logo);
    fclose(error);
    /*fclose(asmOut);*/
    return 0;
}
