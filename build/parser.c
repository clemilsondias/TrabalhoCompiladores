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
	Rafael da Fonte Lopes da Silva
*/


#include <stdio.h>
//#include "../include/comp_dict.h"
#include "../include/main.h"

extern int  yylineno;



/* Line 268 of yacc.c  */
#line 87 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"

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
     TOKEN_ERRO = 284,
     TOKEN_EOF = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 17 "parser.y"
 
  comp_dict_item_t* symbol; 


/* Line 293 of yacc.c  */
#line 22 "parser.y"

 comp_tree_t * tree_node;



/* Line 293 of yacc.c  */
#line 165 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 177 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    35,    33,    41,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
      32,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    32,    40,    44,    50,    54,    57,
      64,    70,    73,    75,    79,    82,    86,    89,    92,    94,
      98,   100,   102,   104,   106,   108,   110,   112,   114,   116,
     120,   124,   128,   135,   142,   149,   152,   155,   157,   161,
     163,   167,   170,   175,   179,   183,   187,   191,   195,   199,
     203,   207,   211,   215,   219,   221,   223,   227,   232,   234,
     236,   239,   241,   243,   245,   248,   250,   252,   256,   258,
     262,   264,   268,   269,   276,   285,   293,   301,   303,   305,
     308,   311,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    30,    -1,    49,    48,    -1,    49,
      -1,    51,    -1,    52,    -1,    54,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    50,    37,    28,
      38,    -1,    50,    37,    28,    39,    22,    40,    38,    -1,
      50,    37,    28,    -1,    50,    37,    28,    41,    53,    -1,
      55,    56,    57,    -1,    55,    57,    -1,    50,    37,    28,
      42,    53,    43,    -1,    50,    37,    28,    42,    43,    -1,
      51,    56,    -1,    51,    -1,    44,    58,    45,    -1,    44,
      45,    -1,    60,    38,    58,    -1,    71,    58,    -1,    60,
      38,    -1,    71,    -1,    57,    38,    58,    -1,    57,    -1,
      38,    -1,    60,    -1,    71,    -1,    61,    -1,    62,    -1,
      63,    -1,    65,    -1,    66,    -1,    28,    31,    69,    -1,
      28,    31,    27,    -1,    28,    31,    26,    -1,    28,    39,
      69,    40,    31,    69,    -1,    28,    39,    69,    40,    31,
      27,    -1,    28,    39,    69,    40,    31,    26,    -1,    13,
      28,    -1,    14,    64,    -1,    27,    -1,    27,    41,    64,
      -1,    69,    -1,    69,    41,    64,    -1,    15,    69,    -1,
      28,    42,    70,    43,    -1,    69,    33,    69,    -1,    69,
      34,    69,    -1,    69,    35,    69,    -1,    69,    36,    69,
      -1,    69,    16,    69,    -1,    69,    17,    69,    -1,    69,
      32,    69,    -1,    69,    18,    69,    -1,    69,    19,    69,
      -1,    69,    20,    69,    -1,    69,    21,    69,    -1,    67,
      -1,    68,    -1,    42,    69,    43,    -1,    28,    39,    69,
      40,    -1,    28,    -1,    22,    -1,    34,    22,    -1,    25,
      -1,    24,    -1,    23,    -1,    34,    23,    -1,    66,    -1,
      26,    -1,    26,    41,    70,    -1,    27,    -1,    27,    41,
      70,    -1,    69,    -1,    69,    41,    70,    -1,    -1,     8,
      42,    68,    43,     9,    73,    -1,     8,    42,    68,    43,
       9,    72,    10,    73,    -1,    11,    42,    68,    43,    12,
      74,    38,    -1,    12,    74,    11,    42,    68,    43,    38,
      -1,    59,    -1,    57,    -1,    59,    38,    -1,    57,    38,
      -1,    59,    -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    77,    78,    81,    82,    83,    89,    90,
      91,    92,    93,    96,    97,   100,   101,   104,   105,   108,
     109,   116,   117,   120,   121,   125,   126,   127,   128,   129,
     130,   131,   134,   135,   138,   139,   140,   141,   142,   145,
     146,   147,   148,   149,   150,   153,   156,   159,   160,   161,
     162,   165,   168,   171,   172,   173,   174,   177,   178,   179,
     180,   181,   182,   183,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   200,   201,   202,   203,
     204,   205,   206,   209,   210,   211,   212,   215,   216,   217,
     218,   220,   221
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
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO",
  "TOKEN_EOF", "'='", "'<'", "'+'", "'-'", "'*'", "'/'", "':'", "';'",
  "'['", "']'", "','", "'('", "')'", "'{'", "'}'", "$accept", "s", "k",
  "declaracoes", "tipo", "decl_variavel", "decl_vetor", "decl_parametro",
  "decl_funcao", "cabecalho", "decl_locais", "bloco", "comandos",
  "comando", "comando_simples", "atribuicao", "entrada", "saida",
  "lista_elementos", "retorno", "chamada_funcao", "expressao_aritmetica",
  "expressao_logica", "expressao", "lista_argumentos", "fluxo_controle",
  "then", "then_else", "comandos_while_do", 0
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
     285,    61,    60,    43,    45,    42,    47,    58,    59,    91,
      93,    44,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    51,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    63,    64,    64,    64,
      64,    65,    66,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     7,     3,     5,     3,     2,     6,
       5,     2,     1,     3,     2,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     6,     6,     6,     2,     2,     1,     3,     1,
       3,     2,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     4,     1,     1,
       2,     1,     1,     1,     2,     1,     1,     3,     1,     3,
       1,     3,     0,     6,     8,     7,     7,     1,     1,     2,
       2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,    10,    11,    12,     0,     0,     4,     0,
       5,     6,     7,     0,     1,     2,     3,     0,     0,     0,
      22,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    24,    30,     0,     0,    34,    35,    36,    37,
      38,    28,     0,    21,    17,    13,     0,     0,     0,     0,
      92,    91,    32,    33,     0,    45,    69,    73,    72,    71,
      47,    68,     0,     0,    46,    75,    64,    65,    49,    51,
       0,     0,    82,     0,    23,    27,    26,     0,     0,    20,
       0,     0,    65,     0,    65,     0,     0,     0,    70,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    40,    39,     0,    76,    78,    80,
       0,    29,    25,     0,     0,    19,     0,     0,     0,    48,
       0,    66,    57,    58,    60,    61,    62,    63,    59,    53,
      54,    55,    56,    50,     0,    82,    82,    82,    52,    14,
      15,     0,     0,    65,    67,     0,    77,    79,    81,     0,
      88,    87,     0,    83,     0,     0,    44,    43,    42,    16,
      90,    89,     0,    85,    86,     0,     0,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    11,    81,    12,    13,
      21,    33,    34,    51,    35,    36,    37,    38,    64,    39,
      65,    66,    67,   109,   110,    41,   152,   153,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
     103,  -112,  -112,  -112,  -112,  -112,    28,    14,   103,    13,
    -112,  -112,  -112,    11,  -112,  -112,  -112,    52,    88,    47,
     103,    43,  -112,    44,    51,    55,    21,    66,   273,   286,
      15,  -112,  -112,    60,    59,    85,  -112,  -112,  -112,  -112,
    -112,    77,    99,  -112,  -112,  -112,   108,    16,   286,   286,
    -112,  -112,  -112,  -112,   120,  -112,  -112,  -112,  -112,  -112,
      93,     3,    30,   286,  -112,  -112,  -112,  -112,   140,   210,
     234,   286,   247,    77,  -112,    77,  -112,    97,    96,  -112,
     100,    98,   101,   210,   104,   106,   273,   286,  -112,  -112,
     134,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   273,  -112,  -112,   210,   176,   102,   105,   166,
     119,  -112,  -112,   125,   114,  -112,   155,   153,   286,  -112,
     201,  -112,   231,   231,   231,   231,    78,    78,   231,    31,
      31,  -112,  -112,  -112,   147,   247,   247,   247,  -112,  -112,
     130,    21,    21,   136,  -112,   260,  -112,  -112,  -112,   103,
     142,   150,   179,  -112,   152,   165,  -112,  -112,   210,  -112,
    -112,  -112,    21,  -112,  -112,   142,   150,  -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   183,  -112,   -10,    18,  -112,    56,  -112,  -112,
     184,   -13,   -34,  -111,   -24,  -112,  -112,  -112,   -59,  -112,
     -17,  -112,   -37,   -23,   -75,   -22,  -112,    53,    64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      22,    40,    52,    19,    53,    68,    69,    76,    44,    40,
      19,    82,    84,    50,     1,     2,     3,     4,     5,     1,
       2,     3,     4,     5,    40,    83,    83,   119,    14,    24,
     151,    20,    25,    26,    27,    28,    29,    80,    20,   111,
      90,   112,    87,   133,    15,    72,    70,   105,   106,    30,
      17,   166,    88,    89,    71,    18,    40,    72,    40,    79,
     146,   147,   148,    68,   120,    18,   100,   101,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    68,
      23,   143,    45,    46,    42,    24,    47,    18,    25,    26,
      27,    28,    29,    48,    55,    83,    24,    49,    73,    25,
      26,    27,    28,    29,    74,    30,     1,     2,     3,     4,
       5,    98,    99,   100,   101,    31,    30,    52,    52,    53,
      53,    18,   158,    75,    40,    40,    31,    77,   150,    50,
      78,    85,    18,    32,    86,    45,   113,   114,    52,    80,
      53,   115,   140,   135,   116,    40,   136,   117,   118,   165,
      91,    92,    93,    94,    95,    96,    91,    92,    93,    94,
      95,    96,   138,   139,   141,   142,    97,    98,    99,   100,
     101,   149,    97,    98,    99,   100,   101,   121,   145,   155,
     160,   102,    91,    92,    93,    94,    95,    96,   161,   162,
     163,    16,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   164,    43,   159,   154,   137,    97,    98,
      99,   100,   101,     0,     0,   167,   134,    91,    92,    93,
      94,    95,    96,     0,     0,     0,    91,    92,    93,    94,
      95,    96,     0,    97,    98,    99,   100,   101,     0,     0,
       0,   144,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    95,    96,     0,     0,     0,    56,    57,    58,    59,
     103,   104,    61,    -1,    98,    99,   100,   101,    62,    56,
      57,    58,    59,   107,   108,    61,    63,     0,     0,     0,
       0,    62,    56,    57,    58,    59,   156,   157,    61,    63,
       0,     0,     0,     0,    62,    56,    57,    58,    59,     0,
      60,    61,    63,     0,     0,     0,     0,    62,    56,    57,
      58,    59,     0,     0,    61,    63,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,     0,    63
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-112))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      13,    18,    26,    13,    26,    28,    29,    41,    21,    26,
      20,    48,    49,    26,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,    41,    48,    49,    86,     0,     8,
     141,    13,    11,    12,    13,    14,    15,    47,    20,    73,
      63,    75,    39,   102,    30,    42,    31,    70,    71,    28,
      37,   162,    22,    23,    39,    44,    73,    42,    75,    43,
     135,   136,   137,    86,    87,    44,    35,    36,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      28,   118,    38,    39,    37,     8,    42,    44,    11,    12,
      13,    14,    15,    42,    28,   118,     8,    42,    38,    11,
      12,    13,    14,    15,    45,    28,     3,     4,     5,     6,
       7,    33,    34,    35,    36,    38,    28,   141,   142,   141,
     142,    44,   145,    38,   141,   142,    38,    28,   141,   142,
      22,    11,    44,    45,    41,    38,    40,    37,   162,   149,
     162,    43,    28,    41,    43,   162,    41,    43,    42,   162,
      16,    17,    18,    19,    20,    21,    16,    17,    18,    19,
      20,    21,    43,    38,     9,    12,    32,    33,    34,    35,
      36,    41,    32,    33,    34,    35,    36,    43,    31,    43,
      38,    41,    16,    17,    18,    19,    20,    21,    38,    10,
      38,     8,    16,    17,    18,    19,    20,    21,    32,    33,
      34,    35,    36,    38,    20,   149,   142,    41,    32,    33,
      34,    35,    36,    -1,    -1,   162,    40,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    32,    33,    34,    35,    36,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    32,    33,    34,    35,    36,    34,    22,
      23,    24,    25,    26,    27,    28,    42,    -1,    -1,    -1,
      -1,    34,    22,    23,    24,    25,    26,    27,    28,    42,
      -1,    -1,    -1,    -1,    34,    22,    23,    24,    25,    -1,
      27,    28,    42,    -1,    -1,    -1,    -1,    34,    22,    23,
      24,    25,    -1,    -1,    28,    42,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    47,    48,    49,    50,
      51,    52,    54,    55,     0,    30,    48,    37,    44,    50,
      51,    56,    57,    28,     8,    11,    12,    13,    14,    15,
      28,    38,    45,    57,    58,    60,    61,    62,    63,    65,
      66,    71,    37,    56,    57,    38,    39,    42,    42,    42,
      57,    59,    60,    71,    74,    28,    22,    23,    24,    25,
      27,    28,    34,    42,    64,    66,    67,    68,    69,    69,
      31,    39,    42,    38,    45,    38,    58,    28,    22,    43,
      50,    53,    68,    69,    68,    11,    41,    39,    22,    23,
      69,    16,    17,    18,    19,    20,    21,    32,    33,    34,
      35,    36,    41,    26,    27,    69,    69,    26,    27,    69,
      70,    58,    58,    40,    37,    43,    43,    43,    42,    64,
      69,    43,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    64,    40,    41,    41,    41,    43,    38,
      28,     9,    12,    68,    40,    31,    70,    70,    70,    41,
      57,    59,    72,    73,    74,    43,    26,    27,    69,    53,
      38,    38,    10,    38,    38,    57,    59,    73
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
#line 71 "parser.y"
    { printf("RECONHECEU ENTRADA!\n");
		 printf("Valor de retorno: %p, Eh funcao: %d\n",(yyvsp[(1) - (2)].tree_node), (yyvsp[(1) - (2)].tree_node)->tipo == IKS_AST_FUNCAO);
		 comp_tree_t * nodo_programa = arvoreCriaNodo(1/*NUMERO DE FILHOS?? 1??*/,IKS_AST_PROGRAMA);
		 arvoreInsereNodo((yyvsp[(1) - (2)].tree_node),nodo_programa);
		 return IKS_SYNTAX_SUCESSO; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 77 "parser.y"
    {printf("Tem mais decls...\n");/*ADD NODE TO THE PARENT NODE, PASS PARENT NODE UP*/(yyval.tree_node) = (yyvsp[(2) - (2)].tree_node);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 78 "parser.y"
    {printf("Eh a ultima decl...\n");/*PASS NODE UP IF FUNCAO*/ (yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 81 "parser.y"
    {printf("BISON -> é variável!\n"); (yyval.tree_node) = NULL;}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 82 "parser.y"
    {printf("BISON -> eh vetor!\n"); (yyval.tree_node) = NULL;}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 83 "parser.y"
    {printf("BISON -> eh funcao!\n");
			  comp_tree_t * nodo_funcao = arvoreCriaNodo(2/*FILHOS - 2? Comando + proxima funcao?*/,IKS_AST_FUNCAO);/*PASS NODE UP*/
			 (yyval.tree_node) = nodo_funcao; 
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 93 "parser.y"
    {printf("BISON -> tipo\n");}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 96 "parser.y"
    {printf("BISON -> decl variavel: %s\n",(yyvsp[(3) - (4)].symbol)->chave);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 97 "parser.y"
    {printf("BISON -> decl vetor: %s\n",(yyvsp[(3) - (7)].symbol)->chave);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 100 "parser.y"
    {printf("BISON -> decl parametro sem separador: %s\n",(yyvsp[(3) - (3)].symbol)->chave);/*MAKE NODE, PASS UP*/}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 101 "parser.y"
    {printf("BISON -> decl parametro com separador: %s\n",(yyvsp[(3) - (5)].symbol)->chave);/*MAKE NODE, ADD CHILDREN NODES*/}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 104 "parser.y"
    {printf("BISON -> decl função\n");}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 105 "parser.y"
    {printf("BISON -> decl funcao\n");}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 108 "parser.y"
    {printf("BISON -> cabeçalho: %s\n",(yyvsp[(3) - (6)].symbol)->chave);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 109 "parser.y"
    {printf("BISON -> cabecalho sem parametros: %s\n", (yyvsp[(3) - (5)].symbol)->chave);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 117 "parser.y"
    {printf("BISON -> decl locais\n");}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    {printf("BISON -> bloco\n");}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    {printf("BISON -> comandos via simples\n");}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 126 "parser.y"
    {printf("BISON -> comandos via fluxo\n");}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    {printf("BISON -> comandos bloco\n");}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 131 "parser.y"
    {printf("BISON -> comandos so ponto e virgula\n");}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    {printf("BISON -> atribuição de expressão: %s = \n",(yyvsp[(1) - (3)].symbol)->chave);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    {printf("BISON -> atribuição de string: %s = %s\n",(yyvsp[(1) - (3)].symbol)->chave,(yyvsp[(3) - (3)].symbol)->chave);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 147 "parser.y"
    {printf("BISON -> atribuição de char: %s = %s\n",(yyvsp[(1) - (3)].symbol)->chave,(yyvsp[(3) - (3)].symbol)->chave);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    {printf("BISON -> atribuição vetor expressao: %s =\n",(yyvsp[(1) - (6)].symbol)->chave);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    {printf("BISON -> atribuição vetor string: %s = %s\n",(yyvsp[(1) - (6)].symbol)->chave,(yyvsp[(6) - (6)].symbol)->chave);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 150 "parser.y"
    {printf("BISON -> atribuição vetor char: %s = %s\n",(yyvsp[(1) - (6)].symbol)->chave,(yyvsp[(6) - (6)].symbol)->chave);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    {printf("BISON -> output\n");}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    { printf("BISON -> chamada de função: %s\n",(yyvsp[(1) - (4)].symbol)->chave);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    { printf("BISON -> aritmetica soma\n");}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    { printf("BISON -> aritmetica subtração\n");}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { printf("BISON -> aritmetica multiplicacao\n");}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    { printf("BISON -> aritmetica divisao\n");}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    {printf("BISON -> teste igualdade\n");}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    {printf("BISON -> teste desigualdade\n");}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 189 "parser.y"
    { printf("BISON -> expressão vetor\n");}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    { printf("BISON -> expressão ID: %s\n",(yyvsp[(1) - (1)].symbol)->chave);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 191 "parser.y"
    { printf("BISON -> expressão literal int: %s\n",(yyvsp[(1) - (1)].symbol)->chave);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 192 "parser.y"
    { printf("BISON -> expressão literal int negativo: %s\n",(yyvsp[(2) - (2)].symbol)->chave);}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 195 "parser.y"
    { printf("BISON -> expressão literal float: %s\n",(yyvsp[(1) - (1)].symbol)->chave);}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 209 "parser.y"
    {printf("BISON -> IF sem else\n");}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    {printf("BISON -> IF com else\n");}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 211 "parser.y"
    {printf("BISON -> while\n");}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 212 "parser.y"
    {printf("BISON -> do while\n");}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 215 "parser.y"
    {printf("BISON -> fim then comando\n");}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 216 "parser.y"
    {printf("BISON -> fim then bloco\n");}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 217 "parser.y"
    {printf("BISON -> fim else comando\n");}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 218 "parser.y"
    {printf("BISON -> fim else bloco\n");}
    break;



/* Line 1806 of yacc.c  */
#line 1931 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"
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
#line 223 "parser.y"


int yyerror (char const *mensagem)
{
  fprintf (stderr, "ERRO %s na linha: %d\n",mensagem,yylineno);
  return IKS_SYNTAX_ERRO;
}

