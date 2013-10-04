/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

/* COMPONENTES:
	Clemilson Dias
	Arthur Foscarini
	Rafael Galuschka
*/


#include <stdio.h>
//#include "../include/comp_dict.h"
#include "../include/main.h"

extern int  yylineno;



/* Line 268 of yacc.c  */
#line 88 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_PR_INT = 258,
     TK_PR_FLOAT = 259,
     TK_PR_BOOL = 260,
     TK_PR_CHAR = 261,
     TK_PR_STRING = 262,
     TK_PR_IF = 263,
     TK_PR_THEN = 264,
     TK_PR_ELSE = 265,
     TK_PR_WHILE = 266,
     TK_PR_DO = 267,
     TK_PR_INPUT = 268,
     TK_PR_OUTPUT = 269,
     TK_PR_RETURN = 270,
     TK_OC_LE = 271,
     TK_OC_GE = 272,
     TK_OC_EQ = 273,
     TK_OC_NE = 274,
     TK_OC_AND = 275,
     TK_OC_OR = 276,
     TK_LIT_INT = 277,
     TK_LIT_FLOAT = 278,
     TK_LIT_FALSE = 279,
     TK_LIT_TRUE = 280,
     TK_LIT_CHAR = 281,
     TK_LIT_STRING = 282,
     TK_IDENTIFICADOR = 283,
     TOKEN_ERRO = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 18 "parser.y"
 
  comp_dict_item_t* symbol; 



/* Line 293 of yacc.c  */
#line 159 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 171 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    34,    32,    40,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    37,
      31,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    38,    46,    50,
      56,    60,    63,    70,    76,    79,    81,    84,    86,    90,
      93,    97,   100,   103,   105,   108,   110,   112,   114,   116,
     118,   120,   122,   124,   126,   130,   134,   138,   145,   152,
     159,   162,   165,   167,   171,   173,   177,   180,   185,   189,
     193,   197,   201,   205,   209,   213,   217,   221,   225,   229,
     231,   233,   237,   242,   244,   246,   249,   251,   253,   255,
     258,   260,   262,   266,   268,   272,   274,   278,   279,   286,
     295,   303,   311,   313,   315,   318,   321,   323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    49,    47,    -1,    49,    -1,
      48,    -1,    29,    47,    -1,    29,    -1,    51,    -1,    52,
      -1,    54,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    50,    36,    28,    37,    -1,    50,    36,
      28,    38,    22,    39,    37,    -1,    50,    36,    28,    -1,
      50,    36,    28,    40,    53,    -1,    55,    57,    58,    -1,
      55,    58,    -1,    50,    36,    28,    41,    56,    42,    -1,
      50,    36,    28,    41,    42,    -1,    53,    56,    -1,    53,
      -1,    51,    57,    -1,    51,    -1,    43,    59,    44,    -1,
      43,    44,    -1,    61,    37,    59,    -1,    72,    59,    -1,
      61,    37,    -1,    72,    -1,    58,    59,    -1,    58,    -1,
      37,    -1,    61,    -1,    72,    -1,    62,    -1,    63,    -1,
      64,    -1,    66,    -1,    67,    -1,    28,    30,    70,    -1,
      28,    30,    27,    -1,    28,    30,    26,    -1,    28,    38,
      70,    39,    30,    70,    -1,    28,    38,    70,    39,    30,
      27,    -1,    28,    38,    70,    39,    30,    26,    -1,    13,
      28,    -1,    14,    65,    -1,    27,    -1,    27,    40,    65,
      -1,    70,    -1,    70,    40,    65,    -1,    15,    70,    -1,
      28,    41,    71,    42,    -1,    70,    32,    70,    -1,    70,
      33,    70,    -1,    70,    34,    70,    -1,    70,    35,    70,
      -1,    70,    16,    70,    -1,    70,    17,    70,    -1,    70,
      31,    70,    -1,    70,    18,    70,    -1,    70,    19,    70,
      -1,    70,    20,    70,    -1,    70,    21,    70,    -1,    68,
      -1,    69,    -1,    41,    70,    42,    -1,    28,    38,    70,
      39,    -1,    28,    -1,    22,    -1,    33,    22,    -1,    25,
      -1,    24,    -1,    23,    -1,    33,    23,    -1,    67,    -1,
      26,    -1,    26,    40,    71,    -1,    27,    -1,    27,    40,
      71,    -1,    70,    -1,    70,    40,    71,    -1,    -1,     8,
      41,    69,    42,     9,    74,    -1,     8,    41,    69,    42,
       9,    73,    10,    74,    -1,    11,    41,    69,    42,    12,
      75,    37,    -1,    12,    75,    11,    41,    69,    42,    37,
      -1,    60,    -1,    58,    -1,    60,    37,    -1,    58,    37,
      -1,    60,    -1,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    67,    68,    69,    71,    72,    75,    76,
      77,    80,    81,    82,    83,    84,    87,    88,    91,    92,
      95,    96,    99,   100,   103,   104,   107,   108,   111,   112,
     116,   117,   118,   119,   120,   121,   122,   126,   127,   130,
     131,   132,   133,   134,   137,   138,   139,   140,   141,   142,
     145,   148,   151,   152,   153,   154,   157,   160,   163,   164,
     165,   166,   169,   170,   171,   172,   173,   174,   175,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   192,   193,   194,   195,   196,   197,   198,   201,   202,
     203,   204,   207,   208,   209,   210,   212,   213
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO", "'='",
  "'<'", "'+'", "'-'", "'*'", "'/'", "':'", "';'", "'['", "']'", "','",
  "'('", "')'", "'{'", "'}'", "$accept", "s", "k", "erro", "declaracoes",
  "tipo", "decl_variavel", "decl_vetor", "decl_parametro", "decl_funcao",
  "cabecalho", "parametros", "decl_locais", "bloco", "comandos", "comando",
  "comando_simples", "atribuicao", "entrada", "saida", "lista_elementos",
  "retorno", "chamada_funcao", "expressao_aritmetica", "expressao_logica",
  "expressao", "lista_argumentos", "fluxo_controle", "then", "then_else",
  "comandos_while_do", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      61,    60,    43,    45,    42,    47,    58,    59,    91,    93,
      44,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    50,    50,    50,    51,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    64,    65,    65,    65,    65,    66,    67,    68,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     3,     5,
       3,     2,     6,     5,     2,     1,     2,     1,     3,     2,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     6,     6,     6,
       2,     2,     1,     3,     1,     3,     2,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     4,     1,     1,     2,     1,     1,     1,     2,
       1,     1,     3,     1,     3,     1,     3,     0,     6,     8,
       7,     7,     1,     1,     2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    12,    13,    14,    15,     7,     0,     2,     5,
       4,     0,     8,     9,    10,     0,     6,     1,     3,     0,
       0,     0,    27,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    29,    35,     0,     0,    39,    40,
      41,    42,    43,    33,     0,    26,    20,    16,     0,     0,
       0,     0,    97,    96,    37,    38,     0,    50,    74,    78,
      77,    76,    52,    73,     0,     0,    51,    80,    69,    70,
      54,    56,     0,     0,    87,    34,    28,    32,    31,     0,
       0,    23,     0,    25,     0,    70,     0,    70,     0,     0,
       0,    75,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    45,    44,     0,
      81,    83,    85,     0,    30,     0,     0,    24,    22,     0,
       0,     0,    53,     0,    71,    62,    63,    65,    66,    67,
      68,    64,    58,    59,    60,    61,    55,     0,    87,    87,
      87,    57,    17,    18,     0,     0,    70,    72,     0,    82,
      84,    86,     0,    93,    92,     0,    88,     0,     0,    49,
      48,    47,    19,    95,    94,     0,    90,    91,     0,     0,
      89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    12,    13,    83,    14,
      15,    84,    23,    35,    36,    53,    37,    38,    39,    40,
      66,    41,    67,    68,    69,   112,   113,    43,   155,   156,
      56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -134
static const yytype_int16 yypact[] =
{
      40,  -134,  -134,  -134,  -134,  -134,    40,    19,  -134,  -134,
      40,    -5,  -134,  -134,  -134,    22,  -134,  -134,  -134,     8,
      99,    30,    56,    32,  -134,   -20,    31,    54,    88,    76,
     300,   312,    -8,  -134,  -134,   140,    62,    72,  -134,  -134,
    -134,  -134,  -134,   140,    80,  -134,  -134,  -134,    93,    35,
     312,   312,  -134,  -134,  -134,  -134,   106,  -134,  -134,  -134,
    -134,  -134,    82,    29,    71,   312,  -134,  -134,  -134,  -134,
     173,   256,   134,   312,   276,  -134,  -134,   140,  -134,    86,
      85,  -134,    92,    56,    91,    95,   256,    96,    94,   300,
     312,  -134,  -134,   153,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   300,  -134,  -134,   256,   223,
     104,   105,   198,   107,  -134,    97,   119,  -134,  -134,   154,
     152,   312,  -134,   232,  -134,   262,   262,   262,   262,    18,
      18,   262,    63,    63,  -134,  -134,  -134,   135,   276,   276,
     276,  -134,  -134,   126,    88,    88,   136,  -134,   288,  -134,
    -134,  -134,    56,   139,   142,   170,  -134,   144,   145,  -134,
    -134,   256,  -134,  -134,  -134,    88,  -134,  -134,   139,   142,
    -134
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,    58,  -134,  -134,   -12,    33,  -134,    44,  -134,
    -134,   114,   176,   -15,   -23,  -133,   -26,  -134,  -134,  -134,
     -82,  -134,   -19,  -134,   -45,   -16,   -48,   -24,  -134,    34,
      55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      24,    42,    54,    21,    55,    85,    87,   122,    46,    42,
      21,   154,    75,    52,    70,    71,    42,    47,    48,    17,
      78,    49,    72,   136,    42,     1,     2,     3,     4,     5,
      73,    19,   169,    74,    86,    86,    25,    82,     1,     2,
       3,     4,     5,     1,     2,     3,     4,     5,    22,    93,
     101,   102,   103,   104,   114,    22,   108,   109,    42,     1,
       2,     3,     4,     5,    16,    20,    44,    90,    18,     6,
      74,    82,    50,    70,   123,    20,   146,    81,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    70,
     149,   150,   151,    91,    92,    51,    26,   103,   104,    27,
      28,    29,    30,    31,    57,    86,    76,    26,    79,    77,
      27,    28,    29,    30,    31,    80,    32,    88,    54,    54,
      55,    55,    89,    47,   115,    42,    42,    32,   116,   153,
      52,    20,   161,   118,   142,   121,    33,   119,   120,    54,
      82,    55,    20,    34,   138,   139,    42,   143,    26,   141,
     168,    27,    28,    29,    30,    31,    58,    59,    60,    61,
     106,   107,    63,   144,   145,   148,   152,    64,    32,    94,
      95,    96,    97,    98,    99,    65,   163,    33,   158,   164,
     165,   166,   167,    20,   100,   101,   102,   103,   104,    94,
      95,    96,    97,    98,    99,   124,   162,   117,    45,   170,
     157,     0,     0,     0,   100,   101,   102,   103,   104,     0,
       0,     0,     0,   105,    94,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,     0,     0,     0,     0,   140,    94,
      95,    96,    97,    98,    99,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   137,   100,   101,   102,   103,   104,     0,     0,
       0,   147,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    98,    99,     0,     0,     0,   100,   101,   102,
     103,   104,     0,    -1,   101,   102,   103,   104,    58,    59,
      60,    61,   110,   111,    63,     0,     0,     0,     0,    64,
      58,    59,    60,    61,   159,   160,    63,    65,     0,     0,
       0,    64,    58,    59,    60,    61,     0,    62,    63,    65,
       0,     0,     0,    64,    58,    59,    60,    61,     0,     0,
      63,    65,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,    65
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-134))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      15,    20,    28,    15,    28,    50,    51,    89,    23,    28,
      22,   144,    35,    28,    30,    31,    35,    37,    38,     0,
      43,    41,    30,   105,    43,     3,     4,     5,     6,     7,
      38,    36,   165,    41,    50,    51,    28,    49,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    15,    65,
      32,    33,    34,    35,    77,    22,    72,    73,    77,     3,
       4,     5,     6,     7,     6,    43,    36,    38,    10,    29,
      41,    83,    41,    89,    90,    43,   121,    42,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     138,   139,   140,    22,    23,    41,     8,    34,    35,    11,
      12,    13,    14,    15,    28,   121,    44,     8,    28,    37,
      11,    12,    13,    14,    15,    22,    28,    11,   144,   145,
     144,   145,    40,    37,    39,   144,   145,    28,    36,   144,
     145,    43,   148,    42,    37,    41,    37,    42,    42,   165,
     152,   165,    43,    44,    40,    40,   165,    28,     8,    42,
     165,    11,    12,    13,    14,    15,    22,    23,    24,    25,
      26,    27,    28,     9,    12,    30,    40,    33,    28,    16,
      17,    18,    19,    20,    21,    41,    37,    37,    42,    37,
      10,    37,    37,    43,    31,    32,    33,    34,    35,    16,
      17,    18,    19,    20,    21,    42,   152,    83,    22,   165,
     145,    -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    16,    17,    18,    19,    20,    21,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    -1,    31,    32,    33,    34,    35,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,
      22,    23,    24,    25,    26,    27,    28,    41,    -1,    -1,
      -1,    33,    22,    23,    24,    25,    -1,    27,    28,    41,
      -1,    -1,    -1,    33,    22,    23,    24,    25,    -1,    -1,
      28,    41,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    29,    46,    47,    48,
      49,    50,    51,    52,    54,    55,    47,     0,    47,    36,
      43,    50,    51,    57,    58,    28,     8,    11,    12,    13,
      14,    15,    28,    37,    44,    58,    59,    61,    62,    63,
      64,    66,    67,    72,    36,    57,    58,    37,    38,    41,
      41,    41,    58,    60,    61,    72,    75,    28,    22,    23,
      24,    25,    27,    28,    33,    41,    65,    67,    68,    69,
      70,    70,    30,    38,    41,    59,    44,    37,    59,    28,
      22,    42,    50,    53,    56,    69,    70,    69,    11,    40,
      38,    22,    23,    70,    16,    17,    18,    19,    20,    21,
      31,    32,    33,    34,    35,    40,    26,    27,    70,    70,
      26,    27,    70,    71,    59,    39,    36,    56,    42,    42,
      42,    41,    65,    70,    42,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    65,    39,    40,    40,
      40,    42,    37,    28,     9,    12,    69,    39,    30,    71,
      71,    71,    40,    58,    60,    73,    74,    75,    42,    26,
      27,    70,    53,    37,    37,    10,    37,    37,    58,    60,
      74
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 65 "parser.y"
    { printf("RECONHECEU ENTRADA!\n"); return IKS_SYNTAX_SUCESSO; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 67 "parser.y"
    {printf("Tem mais decls...\n");}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 68 "parser.y"
    {printf("Eh a ultima decl...\n");}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 69 "parser.y"
    {printf("Token de erro na entrada!\n"); return IKS_SYNTAX_ERRO;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 75 "parser.y"
    {printf("BISON -> é variável!\n");}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 76 "parser.y"
    {printf("BISON -> eh vetor!\n");}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 77 "parser.y"
    {printf("BISON -> eh funcao!\n");}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 84 "parser.y"
    {printf("BISON -> tipo\n");}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 87 "parser.y"
    {printf("BISON -> decl variavel: %s\n",(yyvsp[(3) - (4)].symbol)->chave);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 88 "parser.y"
    {printf("BISON -> decl vetor: %s\n",(yyvsp[(3) - (7)].symbol)->chave);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 91 "parser.y"
    {printf("BISON -> decl parametro sem separador: %s\n",(yyvsp[(3) - (3)].symbol)->chave);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 92 "parser.y"
    {printf("BISON -> decl parametro com separador: %s\n",(yyvsp[(3) - (5)].symbol)->chave);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 95 "parser.y"
    {printf("BISON -> decl função\n");}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 96 "parser.y"
    {printf("BISON -> decl funcao\n");}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 99 "parser.y"
    {printf("BISON -> cabeçalho: %s\n",(yyvsp[(3) - (6)].symbol)->chave);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 100 "parser.y"
    {printf("BISON -> cabecalho sem parametros: %s\n", (yyvsp[(3) - (5)].symbol)->chave);}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 104 "parser.y"
    {printf("BISON -> parametros\n");}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 108 "parser.y"
    {printf("BISON -> decl locais\n");}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 111 "parser.y"
    {printf("BISON -> bloco\n");}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 116 "parser.y"
    {printf("BISON -> comandos via simples\n");}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 117 "parser.y"
    {printf("BISON -> comandos via fluxo\n");}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    {printf("BISON -> comandos bloco\n");}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 122 "parser.y"
    {printf("BISON -> comandos so ponto e virgula\n");}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    {printf("BISON -> atribuição de expressão: %s = \n",(yyvsp[(1) - (3)].symbol)->chave);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 138 "parser.y"
    {printf("BISON -> atribuição de string: %s = %s\n",(yyvsp[(1) - (3)].symbol)->chave,(yyvsp[(3) - (3)].symbol)->chave);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    {printf("BISON -> atribuição de char: %s = %s\n",(yyvsp[(1) - (3)].symbol)->chave,(yyvsp[(3) - (3)].symbol)->chave);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    {printf("BISON -> atribuição vetor expressao: %s =\n",(yyvsp[(1) - (6)].symbol)->chave);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    {printf("BISON -> atribuição vetor string: %s = %s\n",(yyvsp[(1) - (6)].symbol)->chave,(yyvsp[(6) - (6)].symbol)->chave);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    {printf("BISON -> atribuição vetor char: %s = %s\n",(yyvsp[(1) - (6)].symbol)->chave,(yyvsp[(6) - (6)].symbol)->chave);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    {printf("BISON -> output\n");}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { printf("BISON -> chamada de função: %s\n",(yyvsp[(1) - (4)].symbol)->chave);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    { printf("BISON -> aritmetica soma\n");}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 164 "parser.y"
    { printf("BISON -> aritmetica subtração\n");}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 165 "parser.y"
    { printf("BISON -> aritmetica multiplicacao\n");}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { printf("BISON -> aritmetica divisao\n");}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    {printf("BISON -> teste igualdade\n");}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    {printf("BISON -> teste desigualdade\n");}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    { printf("BISON -> expressão vetor\n");}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 182 "parser.y"
    { printf("BISON -> expressão ID: %s\n",(yyvsp[(1) - (1)].symbol)->chave);}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    { printf("BISON -> expressão literal int: %s\n",(yyvsp[(1) - (1)].symbol)->chave);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    { printf("BISON -> expressão literal int negativo: %s\n",(yyvsp[(2) - (2)].symbol)->chave);}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { printf("BISON -> expressão literal float: %s\n",(yyvsp[(1) - (1)].symbol)->chave);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 201 "parser.y"
    {printf("BISON -> IF sem else\n");}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    {printf("BISON -> IF com else\n");}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    {printf("BISON -> while\n");}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    {printf("BISON -> do while\n");}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    {printf("BISON -> fim then comando\n");}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    {printf("BISON -> fim then bloco\n");}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 209 "parser.y"
    {printf("BISON -> fim else comando\n");}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    {printf("BISON -> fim else bloco\n");}
    break;



/* Line 1806 of yacc.c  */
#line 1944 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 215 "parser.y"


int yyerror (char const *mensagem)
{
  fprintf (stderr, "ERRO %s na linha: %d\n",mensagem,yylineno);
  return IKS_SYNTAX_ERRO;
}

