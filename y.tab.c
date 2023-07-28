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
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <tuple>
#include <vector>

#define YYSTYPE atributos

#define COERCAO(s1, s3, e1, e3) 				\
	struct atributos e1, e3;					\
	tie(e1,e3) = coercao_tipo(s1,s3)

#define VERIFICACAO_ID(id_nome, num_bloco)													\
		bool teste;																			\
		int num_bloco;																		\
		tie(teste, num_bloco) = testa_simbolo(id_nome);										\
		if (!teste)																			\
		{																					\
			yyerror("A variável \"" + id_nome + "\" não foi declarada!");					\
		}

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
};

struct simbolo
{
	string nome_temp;
	string tipo;
	string valor;
	string tamanho;
	string categoria;
};

struct funcao
{
	string nome;
	string tipo;
	vector<simbolo> param;
};

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria(); // Gera um nome de variável temporária
string geraFuncao();
string geraLabel();
string trad_aritmetica(struct atributos, string, struct atributos, string);
string trad_relacional(struct atributos, string, struct atributos, string);
string trad_if(struct atributos, string, struct atributos, string);
string trad_logico(struct atributos, string, struct atributos, string);
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retorna a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string, string, string); // adiciona um símbolo na tabela, com seu tipo, valor e nome_temp
tuple<struct atributos, struct atributos> coercao_tipo(struct atributos, struct atributos);
tuple<bool, int> testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
string tipo_simbolo(string); // Retorna o tipo do símbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a tradução de todas as declarações do código intermediário, no topo de seu bloco_qtd
inline bool funcao_existe(string nome);
inline string tipo_funcao(string nome);
string verificaFuncao(string tipo, string nome, vector<simbolo> v);
void imprimeTabela(); // Imprime a tabela de símbolos

vector<map<string, simbolo>> T_simbolo; // Mapa, identificado pelo nome da variável
vector<map<string, simbolo>> T_debug;

map<string, funcao> T_funcs; // Mapa identificando funções
vector<simbolo> param;

int tmp_qnt = 0;
int num_linha = 1;
int bloco_qtd = -1;
int bloco_qtd_debug = -1;
int label_qnt = 0;
int func_qnt = 0;
string declaracoes = "";


#line 157 "y.tab.c"

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
    MAIN = 258,
    ID = 259,
    NUM = 260,
    REAL = 261,
    CHAR = 262,
    STRING = 263,
    FIM = 264,
    ERROR = 265,
    TIPO = 266,
    ATRIBUI = 267,
    SOMA = 268,
    SUBTRAI = 269,
    MULTIPLICA = 270,
    DIVIDE = 271,
    UNARIOMAIS = 272,
    UNARIOMENOS = 273,
    MAIOR = 274,
    MENOR = 275,
    MAIOR_IGUAL = 276,
    MENOR_IGUAL = 277,
    IGUAL = 278,
    DIFERENTE = 279,
    E_LOGICO = 280,
    OU_LOGICO = 281,
    VERDADEIRO = 282,
    FALSO = 283,
    NEGAR = 284,
    IF = 285,
    ELSE = 286,
    WHILE = 287,
    DO = 288,
    FOR = 289,
    CONTINUE = 290,
    BREAK = 291,
    SCAN = 292,
    PRINT = 293
  };
#endif
/* Tokens.  */
#define MAIN 258
#define ID 259
#define NUM 260
#define REAL 261
#define CHAR 262
#define STRING 263
#define FIM 264
#define ERROR 265
#define TIPO 266
#define ATRIBUI 267
#define SOMA 268
#define SUBTRAI 269
#define MULTIPLICA 270
#define DIVIDE 271
#define UNARIOMAIS 272
#define UNARIOMENOS 273
#define MAIOR 274
#define MENOR 275
#define MAIOR_IGUAL 276
#define MENOR_IGUAL 277
#define IGUAL 278
#define DIFERENTE 279
#define E_LOGICO 280
#define OU_LOGICO 281
#define VERDADEIRO 282
#define FALSO 283
#define NEGAR 284
#define IF 285
#define ELSE 286
#define WHILE 287
#define DO 288
#define FOR 289
#define CONTINUE 290
#define BREAK 291
#define SCAN 292
#define PRINT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


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
      39,    40,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   109,   113,   118,   122,   126,   143,   148,
     153,   157,   163,   171,   181,   186,   192,   201,   205,   209,
     213,   224,   236,   248,   260,   283,   287,   291,   295,   299,
     305,   380,   385,   393,   407,   421,   442,   447,   454,   458,
     465,   473,   481,   490,   498,   507,   515,   523,   531,   539,
     547,   557,   574,   584,   591,   599,   607,   615,   625,   634,
     647,   655,   663,   671,   680,   692,   700,   708,   715
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "REAL", "CHAR",
  "STRING", "FIM", "ERROR", "TIPO", "ATRIBUI", "SOMA", "SUBTRAI",
  "MULTIPLICA", "DIVIDE", "UNARIOMAIS", "UNARIOMENOS", "MAIOR", "MENOR",
  "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "E_LOGICO",
  "OU_LOGICO", "VERDADEIRO", "FALSO", "NEGAR", "IF", "ELSE", "WHILE", "DO",
  "FOR", "CONTINUE", "BREAK", "SCAN", "PRINT", "'('", "')'", "'{'", "'}'",
  "','", "';'", "':'", "'['", "']'", "$accept", "S", "globais", "global",
  "parametros", "p1", "parametro", "bloco", "comandos", "blocofuncao",
  "comando", "atribuicao", "declaracao", "entradas", "expressoes",
  "expressao", "relacao", "converte", "aritmetica", "fator", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    40,
      41,   123,   125,    44,    59,    58,    91,    93
};
# endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -113,     9,    15,  -113,     3,    79,    18,  -113,    15,  -113,
    -113,    22,    71,    28,    39,   -34,  -113,  -113,    56,  -113,
    -113,  -113,  -113,   101,   101,  -113,  -113,    71,    53,    29,
    -113,  -113,   144,  -113,  -113,  -113,  -113,    16,    64,  -113,
      75,    71,    71,    78,    78,  -113,   104,    86,    71,    71,
    -113,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,    99,   108,   140,     0,   121,    61,    71,  -113,  -113,
    -113,    78,    78,    78,    78,   156,   156,   156,   156,   156,
     156,   118,   129,   170,   135,  -113,   133,    51,   173,   139,
     141,  -113,   142,   138,   143,   146,   147,  -113,   137,     0,
    -113,  -113,    45,  -113,    71,   123,  -113,  -113,  -113,   148,
     140,   -34,    71,    71,   151,   115,  -113,  -113,   180,    71,
    -113,  -113,  -113,  -113,     0,  -113,   105,   110,   149,   150,
     153,   152,   154,   155,  -113,  -113,    71,   115,   180,   157,
     158,  -113,   159,  -113,   112,   160,  -113,  -113,  -113,  -113,
     161,  -113,  -113,  -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      16,     0,     0,     1,     0,     0,     0,     2,     0,     6,
       5,     0,     0,     0,     0,    16,     3,    16,    64,    60,
      61,    62,    63,     0,     0,    65,    66,     0,     0,     0,
      42,    50,    52,    53,    31,    32,    33,     0,     0,     4,
       0,     0,     0,    58,    59,    49,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    15,     0,    39,     0,    67,    40,
      41,    54,    55,    56,    57,    45,    46,    47,    48,    43,
      44,     0,     0,     0,     0,     8,    11,    64,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,     0,    15,
      19,    27,     0,    68,     0,    51,    34,    35,    12,     0,
       9,     0,     0,     0,     0,     0,    29,    28,     0,     0,
      13,    14,    18,    38,    15,    10,     0,     0,     0,     0,
      37,     0,     0,     0,    16,    16,     0,     0,     0,     0,
       0,     7,    20,    22,     0,     0,    36,    25,    26,    16,
       0,    16,    21,    23,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   183,  -113,    83,  -113,  -113,   -17,   -59,   124,
    -113,   125,   145,    60,    37,   -11,   -25,  -113,    -8,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     7,     8,    84,    85,    86,    97,    98,    40,
      99,   100,   101,   131,    65,    66,    30,    31,    32,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    29,    45,   129,    87,    19,    20,    21,    22,     3,
      36,    88,    37,    23,    24,    43,    44,    47,     4,     5,
      61,    62,    15,    69,    70,   145,     6,    25,    26,    27,
      89,    47,    90,    91,    92,    93,    94,    95,    96,    28,
     121,   -16,    11,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   102,    48,    49,   105,    18,    19,    20,
      21,    22,    17,    12,    46,   133,    23,    24,    13,    14,
      48,    49,    34,    50,   114,    18,    19,    20,    21,    22,
      25,    26,    27,    35,    23,    24,    48,    49,   102,   122,
      41,    12,    28,    53,    54,    41,    13,    14,    25,    26,
      27,   126,   127,    63,   104,    18,    19,    20,    21,    22,
      28,    48,    49,   102,    23,    24,    64,   142,   143,    18,
      19,    20,    21,    22,     2,   144,    68,     9,    25,    26,
      48,    49,   152,     9,   154,    48,    49,    48,    49,    38,
      42,   123,    25,    26,    67,   134,    81,    10,    48,    49,
     135,    83,   150,    10,    42,    82,   132,    51,    52,    53,
      54,   103,   106,    55,    56,    57,    58,    59,    60,    51,
      52,    53,    54,   107,   108,   109,   110,   111,   112,   120,
     113,   115,   116,   128,   130,   118,   119,   117,   136,   124,
     149,    16,   139,   125,   140,   137,   138,   141,   146,     0,
     151,   147,   148,     0,     0,   153
};

static const yytype_int16 yycheck[] =
{
      17,    12,    27,   115,     4,     5,     6,     7,     8,     0,
      44,    11,    46,    13,    14,    23,    24,    28,     3,     4,
       4,     5,     4,    48,    49,   137,    11,    27,    28,    29,
      30,    42,    32,    33,    34,    35,    36,    37,    38,    39,
      99,    41,    39,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    64,    25,    26,    67,     4,     5,     6,
       7,     8,    40,    12,    11,   124,    13,    14,    17,    18,
      25,    26,    44,    44,    91,     4,     5,     6,     7,     8,
      27,    28,    29,    44,    13,    14,    25,    26,    99,    44,
      39,    12,    39,    15,    16,    39,    17,    18,    27,    28,
      29,   112,   113,    39,    43,     4,     5,     6,     7,     8,
      39,    25,    26,   124,    13,    14,    41,   134,   135,     4,
       5,     6,     7,     8,     0,   136,    40,     2,    27,    28,
      25,    26,   149,     8,   151,    25,    26,    25,    26,    15,
      39,   104,    27,    28,    40,    40,    47,     2,    25,    26,
      40,    11,    40,     8,    39,    47,   119,    13,    14,    15,
      16,    40,    44,    19,    20,    21,    22,    23,    24,    13,
      14,    15,    16,    44,     4,    40,    43,     4,    39,    42,
      39,    39,    44,    32,     4,    39,    39,    44,    39,    41,
      31,     8,    40,   110,    40,    45,    43,    42,   138,    -1,
      40,    44,    44,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    57,     0,     3,     4,    11,    50,    51,    59,
      60,    39,    12,    17,    18,     4,    50,    40,     4,     5,
       6,     7,     8,    13,    14,    27,    28,    29,    39,    63,
      64,    65,    66,    67,    44,    44,    44,    46,    57,    55,
      57,    39,    39,    66,    66,    64,    11,    63,    25,    26,
      44,    13,    14,    15,    16,    19,    20,    21,    22,    23,
      24,     4,     5,    39,    41,    62,    63,    40,    40,    64,
      64,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    47,    47,    11,    52,    53,    54,     4,    11,    30,
      32,    33,    34,    35,    36,    37,    38,    55,    56,    58,
      59,    60,    63,    40,    43,    63,    44,    44,     4,    40,
      43,     4,    39,    39,    55,    39,    44,    44,    39,    39,
      42,    56,    44,    62,    41,    52,    63,    63,    32,    67,
       4,    61,    62,    56,    40,    40,    39,    45,    43,    40,
      40,    42,    55,    55,    63,    67,    61,    44,    44,    31,
      40,    40,    55,    44,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    52,
      53,    53,    54,    55,    56,    56,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     4,     1,     1,     9,     1,     0,
       3,     1,     2,     4,     2,     0,     0,     1,     2,     1,
       5,     7,     5,     7,     7,     5,     5,     1,     2,     2,
       4,     3,     3,     3,     6,     6,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     2,
       1,     4,     1,     1,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     4
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
#line 104 "sintatica.y"
{
	T_debug.push_back(T_simbolo[bloco_qtd]);
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n" + traducao_declaracao() + yyvsp[0].traducao << endl;
}
#line 1566 "y.tab.c"
    break;

  case 3:
#line 110 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1574 "y.tab.c"
    break;

  case 4:
#line 114 "sintatica.y"
{
	yyval.traducao = "\n\nint main(void)\n{" + declaracoes + yyvsp[0].traducao + "\n\treturn 0;\n}\n";
}
#line 1582 "y.tab.c"
    break;

  case 5:
#line 119 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1590 "y.tab.c"
    break;

  case 6:
#line 123 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1598 "y.tab.c"
    break;

  case 7:
#line 127 "sintatica.y"
{
	string var = geraFuncao();
	T_funcs[yyvsp[-7].label] = {var, yyvsp[-8].tipo, param};
	yyval.traducao = "\n\n" + yyvsp[-8].tipo + " " + var + "("+ yyvsp[-4].traducao + ")\n{\n" + declaracoes + "\n" + yyvsp[-1].traducao + "\n\treturn 0;\n}\n";
	
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
	
	vector<simbolo> a;
	param = a;
	declaracoes = "";
	//cout << param.empty() << endl;
}
#line 1617 "y.tab.c"
    break;

  case 8:
#line 144 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1625 "y.tab.c"
    break;

  case 9:
#line 148 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1633 "y.tab.c"
    break;

  case 10:
#line 154 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao + ", " + yyvsp[-1].traducao;
}
#line 1641 "y.tab.c"
    break;

  case 11:
#line 158 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1649 "y.tab.c"
    break;

  case 12:
#line 164 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	adicionaTabela(yyvsp[0].label, yyvsp[-1].tipo, "N/A", var,"","variável");
	param.push_back(T_simbolo[bloco_qtd][yyvsp[0].label]);
	yyval.traducao = yyvsp[-1].tipo + " " + var;
}
#line 1660 "y.tab.c"
    break;

  case 13:
#line 172 "sintatica.y"
{	
	declaracoes = declaracoes + traducao_declaracao();
	yyval.traducao = "\t\n" + yyvsp[-1].traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
}
#line 1672 "y.tab.c"
    break;

  case 14:
#line 182 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1680 "y.tab.c"
    break;

  case 15:
#line 186 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1688 "y.tab.c"
    break;

  case 16:
#line 192 "sintatica.y"
{
	bloco_qtd++;
	bloco_qtd_debug++;
	map<string, simbolo> a;
	T_simbolo.push_back(a);
	yyval.traducao = "";
}
#line 1700 "y.tab.c"
    break;

  case 17:
#line 202 "sintatica.y"
{	
	yyval.traducao = yyvsp[0].traducao + "\t\n";
}
#line 1708 "y.tab.c"
    break;

  case 18:
#line 206 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1716 "y.tab.c"
    break;

  case 19:
#line 210 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1724 "y.tab.c"
    break;

  case 20:
#line 214 "sintatica.y"
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	yyval.traducao = yyvsp[-2].traducao + "\t" + neg + " = !" + yyvsp[-2].label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t" + yyvsp[0].traducao + "\n\t" + lbl +":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	if(yyvsp[-2].valor=="true") adicionaTabela(neg, yyvsp[-2].tipo, "false", neg,"","variável");
	else adicionaTabela(neg, yyvsp[-2].tipo, "true", neg, "", "variável");
	
}
#line 1739 "y.tab.c"
    break;

  case 21:
#line 225 "sintatica.y"
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = yyvsp[-4].traducao + "\t" + neg + " = !" + yyvsp[-4].label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\t" + yyvsp[-2].traducao + "\tgoto " + saida + ";\n\t" + lbl + ":\t" + yyvsp[0].traducao + "\n\t" + saida + ":" + "\n";

	adicionaTabela(lbl, "label", "IN", lbl,"","jump");
	adicionaTabela(saida, "label", "OUT", saida,"","jump");
	if(yyvsp[-4].valor=="true") adicionaTabela(neg, yyvsp[-4].tipo, "false", neg,"","variável");
	else adicionaTabela(neg, yyvsp[-4].tipo, "true", neg,"","variável");
}
#line 1755 "y.tab.c"
    break;

  case 22:
#line 237 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = "\t" + lbl +":\n\n"+ yyvsp[-2].traducao + "\t" + var + " = !" + yyvsp[-2].label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";"+ yyvsp[0].traducao + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	adicionaTabela(var, yyvsp[-2].tipo, yyvsp[-2].valor, var,"","variável");

}
#line 1771 "y.tab.c"
    break;

  case 23:
#line 249 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = "\t" + lbl + ":" +yyvsp[-5].traducao + "\n" + yyvsp[-2].traducao + "\t" + var + " = !" + yyvsp[-2].label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	adicionaTabela(var, yyvsp[-2].tipo, yyvsp[-2].valor, var,"","variável");

}
#line 1787 "y.tab.c"
    break;

  case 24:
#line 261 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string var2 = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +"\n\t" + lbl +":\n\n\t" + var + " = " + yyvsp[-4].label + " < " + yyvsp[-2].label + "\n\t" +  var2 + " = !" + var + "\t" + "\n\n\tif(" + var2 + ") " + "goto " + saida +";" + yyvsp[0].traducao + "\n\t" + yyvsp[-4].label + " = " + yyvsp[-4].label + " + 1;" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";


	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	if(yyvsp[-4].valor < yyvsp[-2].valor)
	{
	adicionaTabela(var, "bool", "true", var,"","variável");
	adicionaTabela(var2, "bool", "false", var2,"","variável");
	}
	else
	{
		adicionaTabela(var, "bool", "false", var,"","variável");
		adicionaTabela(var2, "bool", "true", var2,"","variável");
	}
	
}
#line 1814 "y.tab.c"
    break;

  case 25:
#line 284 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1822 "y.tab.c"
    break;

  case 26:
#line 288 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1830 "y.tab.c"
    break;

  case 27:
#line 292 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1838 "y.tab.c"
    break;

  case 28:
#line 296 "sintatica.y"
{
	yyval.traducao = "\tgoto label\n";
}
#line 1846 "y.tab.c"
    break;

  case 29:
#line 300 "sintatica.y"
{
	yyval.traducao = "\tgoto label\n";
}
#line 1854 "y.tab.c"
    break;

  case 30:
#line 306 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-3].label);

	if ((!teste))
	{
		if(yyvsp[-1].tipo =="string")
		{
			string var = geraVariavelTemporaria();
			yyval.traducao = yyvsp[-1].traducao + "\tstcpy(" + var + ", " + yyvsp[-1].label + ");\n";
			adicionaTabela(yyvsp[-3].label,yyvsp[-1].tipo, yyvsp[-1].valor, var,"","variável");
		}
		else 
		{
			string var = geraVariavelTemporaria();
			yyval.traducao = yyvsp[-1].traducao + "\t" + var + " = " + yyvsp[-1].label + ";\n";
			adicionaTabela(yyvsp[-3].label,yyvsp[-1].tipo, yyvsp[-1].valor, var,"","variável");
		}
	}
	else
	{
		yyvsp[-3].tipo = tipo_simbolo(yyvsp[-3].label);
		//cout << bloc<<endl;
		if(yyvsp[-3].tipo == yyvsp[-1].tipo)
		{
			if(yyvsp[-3].tipo == "string")
			{
				yyval.traducao=yyvsp[-1].traducao+"\n";
			}
			else
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloc][yyvsp[-3].label].nome_temp + " = " + yyvsp[-1].label + ";\n";
			}
		}
		else if(yyvsp[-1].tipo == "bool")
		{
			yyerror("Variável esperava tipo " + yyvsp[-3].tipo + ", mas recebeu tipo " + yyvsp[-1].tipo);
		}
		else if(yyvsp[-3].tipo == "float") // Regra para coerção float
		{
			if(yyvsp[-1].tipo == "int") // Regra para coerção int
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloc][yyvsp[-3].label].nome_temp + " = (float) " + yyvsp[-1].label + ";\n";
			}
			else if(yyvsp[-1].tipo == "char") // Regra para coerção char
			{
				yyerror("Variável esperava tipo " + yyvsp[-3].tipo + ", mas recebeu tipo " + yyvsp[-1].tipo);
			}
		}
		else if(yyvsp[-3].tipo == "int") // Regra para coerção int
		{
			if(yyvsp[-1].tipo == "float") // Regra para coerção float
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloc][yyvsp[-3].label].nome_temp + " = (int) " + yyvsp[-1].label + ";\n";
			}
			else if(yyvsp[-1].tipo == "char") // Regra para coerção de char
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloc][yyvsp[-3].label].nome_temp + " = (int) " + yyvsp[-1].label + ";\n";
			}
		}
		else if(yyvsp[-1].tipo=="string")
		{
			cout<<T_simbolo[bloc][yyvsp[-1].label].valor;
			string var = geraVariavelTemporaria();
			yyval.traducao = yyvsp[-1].traducao;
			//adicionaTabela($$.label,$$.tipo, T_simbolo[bloc][$3.label].valor, var);
		}
		else{
			yyerror("Variável esperava tipo " + yyvsp[-3].tipo + ", mas recebeu tipo " + yyvsp[-1].tipo);
		}
		//T_simbolo[bloc][$1.label].valor = T_simbolo[bloc][$3.label].valor;
	}
}
#line 1933 "y.tab.c"
    break;

  case 31:
#line 381 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)
	yyval.traducao = "\t" + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " = " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " + 1;\n";
}
#line 1942 "y.tab.c"
    break;

  case 32:
#line 386 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)
	yyval.traducao = "\t" + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " = " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " - 1;\n";
}
#line 1951 "y.tab.c"
    break;

  case 33:
#line 394 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, yyvsp[-2].tipo, "N/A", var,"","variável");
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1969 "y.tab.c"
    break;

  case 34:
#line 408 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-4].label);
	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			yyval.traducao = "\n\t"+ var + " = malloc(" + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " * sizeof(" + yyvsp[-5].tipo + "));\n\n";
			adicionaTabela(yyvsp[-4].label, yyvsp[-5].tipo, "N/A", var, T_simbolo[bloco_qtd][yyvsp[-2].label].valor, "vetor");
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1987 "y.tab.c"
    break;

  case 35:
#line 422 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-4].label);

	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			string var2 = geraVariavelTemporaria();
			yyval.traducao = "\t" + var + " = " + yyvsp[-2].traducao +";\n\t"+ var2 + " = malloc(" + var + " * sizeof(" + yyvsp[-5].tipo + "));\n\n";
			
			adicionaTabela(var, "int", yyvsp[-2].traducao, var, "", "variável");
			adicionaTabela(yyvsp[-4].label, yyvsp[-5].tipo, "N/A", var2, yyvsp[-2].traducao, "vetor");

	}else{
		yyerror("Variável já declarada!");
	}
}
#line 2010 "y.tab.c"
    break;

  case 36:
#line 443 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)
	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + ";" + yyvsp[0].traducao;
}
#line 2019 "y.tab.c"
    break;

  case 37:
#line 448 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[0].label, bloc)
	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[0].label].nome_temp + ";\n";
}
#line 2028 "y.tab.c"
    break;

  case 38:
#line 455 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao + "\n\tcout << " + yyvsp[-2].label + ";\n" + yyvsp[0].traducao;
}
#line 2036 "y.tab.c"
    break;

  case 39:
#line 459 "sintatica.y"
{
	yyval.traducao = "\n" + yyvsp[0].traducao + "cout << " + yyvsp[0].label + ";\n";
}
#line 2044 "y.tab.c"
    break;

  case 40:
#line 466 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "&&", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2056 "y.tab.c"
    break;

  case 41:
#line 474 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "||", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2068 "y.tab.c"
    break;

  case 42:
#line 482 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2079 "y.tab.c"
    break;

  case 43:
#line 491 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "==", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2091 "y.tab.c"
    break;

  case 44:
#line 499 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "!=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2103 "y.tab.c"
    break;

  case 45:
#line 508 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2115 "y.tab.c"
    break;

  case 46:
#line 516 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2127 "y.tab.c"
    break;

  case 47:
#line 524 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2139 "y.tab.c"
    break;

  case 48:
#line 532 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2151 "y.tab.c"
    break;

  case 49:
#line 540 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[0], "!", yyvsp[0], yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2163 "y.tab.c"
    break;

  case 50:
#line 548 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2174 "y.tab.c"
    break;

  case 51:
#line 558 "sintatica.y"
{
	if(yyvsp[-2].tipo != "int" || yyvsp[-2].tipo != "float")
	{
		yyerror("A converção explicita para o tipo: \"" + yyvsp[-2].tipo + "\" não é suportada!");
	}
	if(yyvsp[0].tipo == "string")
	{
		yyerror("A converção explicita a partir do tipo: \"string\" não é suportada!");
	}
	yyval.valor = to_string(stoi(yyvsp[0].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (" + yyvsp[-2].tipo + ")" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, yyvsp[-2].tipo, yyval.valor, yyval.label,"","variável");
	yyval.tipo = yyvsp[-2].label;
}
#line 2195 "y.tab.c"
    break;

  case 52:
#line 575 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2206 "y.tab.c"
    break;

  case 53:
#line 585 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2217 "y.tab.c"
    break;

  case 54:
#line 592 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "+", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2229 "y.tab.c"
    break;

  case 55:
#line 600 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "-", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2241 "y.tab.c"
    break;

  case 56:
#line 608 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "*", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2253 "y.tab.c"
    break;

  case 57:
#line 616 "sintatica.y"
{
	if(stof(yyvsp[0].valor)==0) yyerror("Divisão por zero");
	
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "/", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2267 "y.tab.c"
    break;

  case 58:
#line 626 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;

	adicionaTabela(yyval.label, yyvsp[0].tipo, "N/A", yyval.label,"","variável");
}
#line 2280 "y.tab.c"
    break;

  case 59:
#line 635 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + "-" + " " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = "-" + yyvsp[0].valor;

	adicionaTabela(yyval.label, yyval.tipo, "N/A", yyval.label,"","variável");
}
#line 2293 "y.tab.c"
    break;

  case 60:
#line 648 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "int";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo, yyvsp[0].traducao, yyval.label, "","variável");
}
#line 2305 "y.tab.c"
    break;

  case 61:
#line 656 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "float";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo, yyvsp[0].traducao, yyval.label, "","variável");
}
#line 2317 "y.tab.c"
    break;

  case 62:
#line 664 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + "';\n";
	yyval.tipo = "char";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo ,yyval.valor, yyval.label,"","variável");
}
#line 2329 "y.tab.c"
    break;

  case 63:
#line 672 "sintatica.y"
{
	yyval.tipo = "string";
	yyval.valor = yyvsp[0].traducao;
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, yyval.tipo, yyval.valor, yyval.label,"","variável");
	yyval.traducao = "\tstrcpy(" + yyval.label + ", " + yyvsp[0].traducao + ");\n\t";	
	
}
#line 2342 "y.tab.c"
    break;

  case 64:
#line 681 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[0].label, bloc)
	else
	{
		yyval.traducao ="";
		yyval.label = T_simbolo[bloc][yyvsp[0].label].nome_temp;
		//cout<<tipo_simbolo($1.label)<<endl;
		yyval.tipo = tipo_simbolo(yyvsp[0].label);
		yyval.valor = T_simbolo[bloc][yyvsp[0].label].valor;
	}
}
#line 2358 "y.tab.c"
    break;

  case 65:
#line 693 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "true";
	adicionaTabela(yyval.label, "bool", "true", yyval.label,"","variável");
}
#line 2370 "y.tab.c"
    break;

  case 66:
#line 701 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "false";
	adicionaTabela(yyval.label, "bool", "false", yyval.label,"","variável");
}
#line 2382 "y.tab.c"
    break;

  case 67:
#line 709 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao;
	yyval.label = yyvsp[-1].label;
	yyval.tipo = yyvsp[-1].tipo;
	yyval.valor = yyvsp[-1].valor;
}
#line 2393 "y.tab.c"
    break;

  case 68:
#line 716 "sintatica.y"
{

}
#line 2401 "y.tab.c"
    break;


#line 2405 "y.tab.c"

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
#line 720 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + to_string(tmp_qnt++);
}

string geraFuncao()
{
	return "FUNC_" + to_string(func_qnt++);
}

string geraLabel()
{
	return "L" + to_string(label_qnt++);
}

string trad_aritmetica(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(s1.tipo == "bool")
	{
		yyerror("Tipo bool não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if(s1.tipo == "char")
	{
		yyerror("Tipo char não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if((s1.tipo == "float" || s1.tipo == "int"))
	{	
			traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";
			adicionaTabela(temp, s1.tipo, s1.valor + operador + s3.valor, temp,"","aritmetica");
	}

	return traducao;
}

string trad_relacional(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";

	if(s1.tipo == "bool")
	{
		if (operador == "<" || operador == ">" || operador == "<=" || operador == ">=")
		{
			yyerror("Tipo não suporta operações relacionais (<, >, >=, <=)"); // termina a função
		}
		else
		{
			if(operador == "==")
			{
				if(s1.valor == s3.valor)
				{
					adicionaTabela(temp, "bool", "true", temp,"","variável");
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp,"","variável");
				}
			}
			else if (operador == "!=")
			{
				if(s1.valor != s3.valor)
				{
					adicionaTabela(temp, "bool", "true", temp,"","variável");
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp,"","variável");
				}
			}	
		}

	}
	
// tipos numéricos e char
	if (s1.tipo == "float" || s1.tipo == "int" || s1.tipo == "char")
	{
		if(operador == "==")
		{
			if(s1.valor == s3.valor)
			{
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}

		else if (operador == "!=")
		{
			if(s1.valor != s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == ">")
		{
			if(s1.valor > s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == "<")
		{
			if(s1.valor < s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == "<=")
		{
			if(s1.valor <= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == ">=")
		{
			if(s1.valor >= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
	}

	return traducao;
}

string trad_logico(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";

	if(s1.tipo == "bool")
	{
		if((operador == "&&" || operador == "||") && (s1.valor == "true" && s3.valor == "true")){
			adicionaTabela(temp, "bool", "true", temp,"","variável");
		}
		else if(operador == "&&" && (s1.valor == "false" || s3.valor == "false")){

			adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == "||"){
			if((s1.valor == "false" && s3.valor == "true") || (s1.valor == "true" && s3.valor == "false"))
			{
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else if (s1.valor == "false" && s3.valor == "false"){
				adicionaTabela(temp, "bool", "false", temp,"","variável");
			}
		}else
		{
			traducao = s1.traducao + "\t" + temp + " = " + operador + " " + s1.label + ";\n";
			if(s3.valor == "true")
			{
				adicionaTabela(temp, "bool", "false", temp,"","variável");
			}
			else 
			{
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
		}
	}else
	{
		yyerror("Tipo não suporta as operações lógicas (||, &&, !)");
	}

	return traducao;
}

string traducao_expressao(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/"|| operador == "++")
	{
		return trad_aritmetica(s1, operador, s3, temp);
	}
	if(operador == "&&"|| operador == "||" || operador == "!")
	{
		return trad_logico(s1, operador, s3, temp);
	}
	if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=")
	{
		return trad_relacional(s1, operador, s3, temp);
	}

	return traducao;
}

tuple<struct atributos, struct atributos> coercao_tipo(struct atributos s1, struct atributos s3)
{
	tuple <struct atributos, struct atributos> expr(s1,s3);
	string tipo1 = s1.tipo;
	string tipo3 = s3.tipo;
	if(tipo1 == tipo3)
		return expr;

	if(tipo1 == "string" || tipo3 == "string")
		yyerror("Tipo string não suporta coerção");

	if(tipo1 == "bool" || tipo3 == "bool")
		yyerror("Tipo booleano não suporta coerção");
	
	struct atributos novo;
	novo.traducao = "";
	novo.label = geraVariavelTemporaria();
	
	if(tipo1 == "float") // Regra para coerção float
	{
		if(tipo3 == "int") // Regra para coerção int
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (float)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(s3.valor)), novo.label,"","variável");
			get<1>(expr) = novo;
		}
		else if(tipo3 == "char") // Regra para coerção char
		{
			yyerror("Expressão não definida para os tipos float e char");
		}
	}
	else if(tipo3 == "float") // Regra para coerção float
	{
		if(tipo1 == "int") // Regra para coerção int
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (float)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(s1.valor)), novo.label,"","variável");
			get<0>(expr) = novo;
		}
		else if(tipo1 == "char") // Regra para coerção de char
		{
			yyerror("Expressão não definida para os tipos char e float");
		}
	}
	else if(tipo1 == "int") // Regra para coerção int
	{
		if(tipo3 == "char") // Regra para coerção char
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (int)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "int", (s3.valor), novo.label,"","variável");
			get<1>(expr) = novo;
		}
	}else if(tipo3 == "int") // Regra para coerção int
	{
		if(tipo1 == "char") // Regra para coerção char
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (int)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "int", (s3.valor), novo.label,"","variável");
			get<0>(expr) = novo;
		}
	}

	return expr;
}

//retorna True se o símbolo está na tabela e False caso o contrario
tuple<bool, int> testa_simbolo(string nome)
{
	int i;
	bool r = false;
	for(i=bloco_qtd;i>=0;i--)
	{
		r = T_simbolo[i].count(nome)==1;
		if(r)
			break;
	}
	tuple<bool, int> resp(r, i);
	return resp;
}

void adicionaTabela(string nome, string tipo, string valor, string novo_nome, string tamanho, string categoria)
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(nome);
	if ((!teste) || bloc != bloco_qtd)
	{
		simbolo novo;
		novo.tipo = tipo;
		novo.nome_temp = novo_nome;
		novo.valor = valor;
		novo.tamanho = tamanho;
		novo.categoria = categoria;
		T_simbolo[bloco_qtd][nome] = novo;
	}
}

// se o simbolo não estiver na tabela retorna mensagem de erro, caso contrário retorna o tipo do simbolo  
string tipo_simbolo(string nome)
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(nome);
	if (!teste)
	{
		yyerror("Variável não declarada");
	}
	//cout << T_simbolo[nome].tipo << endl;
	return T_simbolo[bloc][nome].tipo;
}

string traducao_declaracao()
{
	string traducao = "\n";
	for(auto const& [key, val]: T_simbolo[bloco_qtd]) {
		if(val.tipo=="bool")
		{
			traducao = traducao + "\t"+ "int" + " " + val.nome_temp + ";\n";
			continue;
		}
		if(val.tipo=="string"){			
			
			traducao = traducao + "\t"+ "char *" + val.nome_temp + ";\n\t" + val.nome_temp + " = malloc("+ to_string(size(val.valor)-1)+ "*sizeof(char));\n";
			continue;
		}
		if(val.tipo=="label"){			
			continue;
		}
		
		
		traducao = traducao + "\t"+ val.tipo + " " + val.nome_temp + ";\n";
		
	}
	return traducao;
}

inline bool funcao_existe(string nome)
{
	return T_funcs.count(nome) == 1;
}

inline string tipo_funcao(string nome)
{
	return T_funcs[nome].tipo;
}

string verificaFuncao(string tipo, string nome, vector<simbolo> v)
{
	struct atributos s1, s3;
	if(funcao_existe(nome))
	{
		if(v.size()!=T_funcs[nome].param.size())
		yyerror("O número de parametros na função não é compátivel");
		for (int i; i<v.size();i++)
		{
			if(T_funcs[nome].param[i].tipo!=v[i].tipo)
			{
				struct simbolo c1 = T_funcs[nome].param[i];
				struct simbolo c2 = v[i];
				s1 = {c1.nome_temp, "", c1.tipo, c1.valor};
				s3 = {c2.nome_temp, "", c2.tipo, c2.valor};
				COERCAO(s1, s3, e1, e3);
				yyerror("A função esperava " + T_funcs[nome].param[i].tipo + ", mas recebeu " + v[i].tipo + " na posição " + to_string(i) + ".");
			}
		}
	}else
	{
		yyerror("Função \"" + nome + "\" não definida!");
	}
	return "";
}

void imprimeTabela()
{
	for (int i = 0; i <= bloco_qtd_debug; i++)
	{
		cout << "\n\n\t\tTABELA DE SíMBOLOS | BLOCO " << i <<"\n\nSÍMBOLO\t\tTIPO\tCATEGORIA\tATRIBUIÇÃO\tTAMANHO\t\tNOME\n------------------------------------------------------------------------------\n";
		for(auto const& [key, val]: T_debug[i]) {
			
			if(val.categoria=="vetor"){
				cout << key << "\t\t" + val.tipo << "\t" + val.categoria << "\t\t" + val.valor << "\t\t" + val.tamanho << "\t\t" + val.nome_temp<<"\n";
				continue;
			}
			cout << key << "\t\t" + val.tipo << "\t" + val.categoria << "\t" + val.valor << "\t\t" + val.tamanho << "\t\t" + val.nome_temp<<"\n";

		}
		cout << "------------------------------------------------------------------------------\n";
	}
}

int main(int argc, char* argv[])
{	
	yyparse();
	imprimeTabela();
	
	return 0;
}

void yyerror(string MSG)
{
	cout << "ERRO! linha " << num_linha << " | " << MSG << endl;
	exit (0);
}				
