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
	string token;
	string valor;
	string escopo;
};

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria(); // Gera um nome de variável temporária
string geraLabel();
string trad_aritmetica(struct atributos, string, struct atributos, string);
string trad_relacional(struct atributos, string, struct atributos, string);
string trad_if(struct atributos, string, struct atributos, string);
string trad_logico(struct atributos, string, struct atributos, string);
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retorna a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string); // adiciona um símbolo na tabela, com seu tipo, valor e nome_temp
tuple<struct atributos, struct atributos> coercao_tipo(struct atributos, struct atributos);
tuple<bool, int> testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
string tipo_simbolo(string); // Retorna o tipo do símbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a tradução de todas as declarações do código intermediário, no topo de seu bloco_qtd
void imprimeTabela(); // Imprime a tabela de símbolos

vector<map<string, simbolo>> T_simbolo; // Mapa, identificado pelo nome da variável
vector<map<string, simbolo>> T_debug;

int tmp_qnt = 0;
int num_linha = 1;
int bloco_qtd = -1;
int bloco_qtd_debug = -1;
int label_qnt=0;
string declaracoes = "";

#line 141 "y.tab.c"

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
    TIPO_INT = 266,
    TIPO_FLOAT = 267,
    TIPO_CHAR = 268,
    TIPO_BOOL = 269,
    TIPO_STRING = 270,
    ATRIBUI = 271,
    SOMA = 272,
    SUBTRAI = 273,
    MULTIPLICA = 274,
    DIVIDE = 275,
    MAIOR = 276,
    MENOR = 277,
    MAIOR_IGUAL = 278,
    MENOR_IGUAL = 279,
    IGUAL = 280,
    DIFERENTE = 281,
    E_LOGICO = 282,
    OU_LOGICO = 283,
    VERDADEIRO = 284,
    FALSO = 285,
    NEGAR = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    DO = 290,
    FOR = 291,
    CONTINUE = 292,
    BREAK = 293,
    SCAN = 294,
    PRINT = 295
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
#define TIPO_INT 266
#define TIPO_FLOAT 267
#define TIPO_CHAR 268
#define TIPO_BOOL 269
#define TIPO_STRING 270
#define ATRIBUI 271
#define SOMA 272
#define SUBTRAI 273
#define MULTIPLICA 274
#define DIVIDE 275
#define MAIOR 276
#define MENOR 277
#define MAIOR_IGUAL 278
#define MENOR_IGUAL 279
#define IGUAL 280
#define DIFERENTE 281
#define E_LOGICO 282
#define OU_LOGICO 283
#define VERDADEIRO 284
#define FALSO 285
#define NEGAR 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define DO 290
#define FOR 291
#define CONTINUE 292
#define BREAK 293
#define SCAN 294
#define PRINT 295

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
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      41,    42,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    93,    97,   101,   105,   109,   114,   119,
     127,   135,   144,   149,   155,   164,   168,   172,   176,   186,
     196,   206,   216,   237,   241,   245,   251,   319,   334,   348,
     362,   376,   392,   398,   406,   410,   417,   425,   433,   442,
     450,   459,   467,   475,   483,   491,   499,   508,   517,   526,
     537,   544,   552,   560,   568,   578,   587,   600,   608,   616,
     624,   633,   645,   653,   661
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "REAL", "CHAR",
  "STRING", "FIM", "ERROR", "TIPO_INT", "TIPO_FLOAT", "TIPO_CHAR",
  "TIPO_BOOL", "TIPO_STRING", "ATRIBUI", "SOMA", "SUBTRAI", "MULTIPLICA",
  "DIVIDE", "MAIOR", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL",
  "DIFERENTE", "E_LOGICO", "OU_LOGICO", "VERDADEIRO", "FALSO", "NEGAR",
  "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "SCAN", "PRINT",
  "'('", "')'", "'{'", "'}'", "';'", "':'", "','", "$accept", "S",
  "globais", "global", "fn_main", "bloco", "comandos", "blocofuncao",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    40,    41,   123,   125,    59,    58,    44
};
# endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -101,    21,   132,  -101,     9,     1,    51,    52,    59,    70,
    -101,   132,  -101,  -101,  -101,    62,    35,    44,    56,    61,
      67,    84,  -101,  -101,  -101,  -101,  -101,  -101,    92,    92,
    -101,  -101,    62,    42,   -16,  -101,  -101,   145,  -101,    36,
    -101,  -101,  -101,  -101,  -101,    62,     8,     8,  -101,    65,
      90,    60,    62,    62,  -101,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,  -101,    62,    62,  -101,  -101,
    -101,     8,     8,     8,     8,   155,   155,   155,   155,   155,
     155,  -101,    91,    12,    12,     2,     9,   131,   107,   108,
    -101,   135,   136,   137,  -101,    93,     2,  -101,  -101,    37,
      62,    62,   116,   110,   175,    62,     2,     2,  -101,  -101,
    -101,    77,    96,   139,    95,   134,   140,   141,    34,   142,
     143,  -101,  -101,    62,   110,   175,   144,   146,    62,  -101,
    -101,   151,  -101,   100,   148,  -101,  -101,  -101,  -101,  -101,
     147,  -101,  -101,  -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       2,     4,     7,     6,     5,     0,     0,     0,     0,     0,
       0,     0,     3,    61,    57,    58,    59,    60,     0,     0,
      62,    63,     0,     0,     0,    38,    46,    49,    50,     0,
      27,    28,    30,    29,    31,     0,    55,    56,    45,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    64,    36,
      37,    51,    52,    53,    54,    41,    42,    43,    44,    39,
      40,     8,     0,    47,    48,    13,    61,     0,     0,     0,
      14,     0,     0,     0,    15,     0,    13,    17,    25,     0,
       0,     0,     0,     0,     0,     0,    13,    13,     9,    12,
      16,     0,     0,     0,     0,    33,     0,     0,    35,     0,
       0,    14,    14,     0,     0,     0,     0,     0,     0,    10,
      11,    18,    20,     0,     0,    32,    23,    24,    34,    14,
       0,    14,    19,    21,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   174,  -101,  -101,   -64,   -12,   188,  -101,    33,
     109,    68,    66,   -15,   -30,  -101,    97,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    10,    11,    12,    94,    95,    82,    96,    97,
      98,   116,   117,    99,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    81,    48,   114,    16,    17,    86,    24,    25,    26,
      27,    52,    53,    87,     6,     7,     8,     9,    51,    28,
      29,     3,    69,    70,   134,    15,   102,    57,    58,    54,
      51,    30,    31,    32,    88,    13,    89,    90,    91,    52,
      53,    92,    93,    33,    13,   -14,    23,    24,    25,    26,
      27,    83,    84,    49,    50,    18,    19,   131,   132,    28,
      29,    52,    53,    20,    52,    53,    23,    24,    25,    26,
      27,    30,    31,    32,    21,   142,    39,   144,    65,    28,
      29,   128,   110,    33,   109,   111,   112,    52,    53,    40,
     118,    30,    31,    32,   119,   120,    23,    24,    25,    26,
      27,    41,    68,    33,    52,    53,    42,    66,   133,    28,
      29,    14,    43,   118,    23,    24,    25,    26,    27,   121,
      14,    30,    31,    52,    53,    46,    47,    52,    53,    44,
     106,   107,    67,    45,    85,    17,     4,   108,   122,    30,
      31,   124,   140,     5,     6,     7,     8,     9,   100,   101,
     113,    45,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    55,    56,    57,    58,   103,   104,   105,   115,
     123,   125,   126,   127,   139,    22,   129,   130,     2,   136,
     141,   137,   143,   135,   138
};

static const yytype_uint8 yycheck[] =
{
      15,    65,    32,   103,     3,     4,     4,     5,     6,     7,
       8,    27,    28,    11,    12,    13,    14,    15,    33,    17,
      18,     0,    52,    53,   124,    16,    90,    19,    20,    45,
      45,    29,    30,    31,    32,     2,    34,    35,    36,    27,
      28,    39,    40,    41,    11,    43,     4,     5,     6,     7,
       8,    66,    67,    11,    12,     4,     4,   121,   122,    17,
      18,    27,    28,     4,    27,    28,     4,     5,     6,     7,
       8,    29,    30,    31,     4,   139,    41,   141,    42,    17,
      18,    47,    45,    41,    96,   100,   101,    27,    28,    45,
     105,    29,    30,    31,   106,   107,     4,     5,     6,     7,
       8,    45,    42,    41,    27,    28,    45,    42,   123,    17,
      18,     2,    45,   128,     4,     5,     6,     7,     8,    42,
      11,    29,    30,    27,    28,    28,    29,    27,    28,    45,
      37,    38,    42,    41,    43,     4,     4,    44,    42,    29,
      30,    46,    42,    11,    12,    13,    14,    15,    41,    41,
      34,    41,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    17,    18,    19,    20,    41,    41,    41,     4,
      41,    47,    42,    42,    33,    11,    44,    44,     0,    45,
      42,    45,    45,   125,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    55,     0,     4,    11,    12,    13,    14,    15,
      50,    51,    52,    57,    58,    16,     3,     4,     4,     4,
       4,     4,    50,     4,     5,     6,     7,     8,    17,    18,
      29,    30,    31,    41,    61,    62,    63,    64,    65,    41,
      45,    45,    45,    45,    45,    41,    64,    64,    62,    11,
      12,    61,    27,    28,    45,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    42,    42,    42,    42,    62,
      62,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    53,    55,    61,    61,    43,     4,    11,    32,    34,
      35,    36,    39,    40,    53,    54,    56,    57,    58,    61,
      41,    41,    53,    41,    41,    41,    37,    38,    44,    54,
      45,    61,    61,    34,    65,     4,    59,    60,    61,    54,
      54,    42,    42,    41,    46,    47,    42,    42,    47,    44,
      44,    53,    53,    61,    65,    59,    45,    45,    60,    33,
      42,    42,    53,    45,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    53,
      53,    53,    54,    54,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     5,     4,
       6,     6,     2,     0,     0,     1,     2,     1,     5,     7,
       5,     7,     7,     5,     5,     1,     4,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     2,     1,     4,     4,     1,
       1,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3
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
#line 88 "sintatica.y"
{
	T_debug.push_back(T_simbolo[bloco_qtd]);
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n" + traducao_declaracao() + yyvsp[0].traducao << endl;
}
#line 1549 "y.tab.c"
    break;

  case 3:
#line 94 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1557 "y.tab.c"
    break;

  case 4:
#line 98 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1565 "y.tab.c"
    break;

  case 5:
#line 102 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1573 "y.tab.c"
    break;

  case 6:
#line 106 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1581 "y.tab.c"
    break;

  case 7:
#line 110 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1589 "y.tab.c"
    break;

  case 8:
#line 115 "sintatica.y"
{
	yyval.traducao = "\n\nint main(void)\n{" + declaracoes + yyvsp[0].traducao + "\n\treturn 0;\n}\n";
}
#line 1597 "y.tab.c"
    break;

  case 9:
#line 120 "sintatica.y"
{	
	declaracoes = declaracoes + traducao_declaracao();
	yyval.traducao = "\t\n" + yyvsp[-1].traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
}
#line 1609 "y.tab.c"
    break;

  case 10:
#line 128 "sintatica.y"
{	
	declaracoes = declaracoes + traducao_declaracao();
	yyval.traducao = "\t\n" + yyvsp[-5].traducao + "\n" + yyvsp[-3].traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
}
#line 1621 "y.tab.c"
    break;

  case 11:
#line 136 "sintatica.y"
{	
	declaracoes = declaracoes + traducao_declaracao();
	yyval.traducao = "\t\n" + yyvsp[-5].traducao + "\n" + yyvsp[-3].traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
}
#line 1633 "y.tab.c"
    break;

  case 12:
#line 145 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1641 "y.tab.c"
    break;

  case 13:
#line 149 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1649 "y.tab.c"
    break;

  case 14:
#line 155 "sintatica.y"
{
	bloco_qtd++;
	bloco_qtd_debug++;
	map<string, simbolo> a;
	T_simbolo.push_back(a);
	yyval.traducao = "";
}
#line 1661 "y.tab.c"
    break;

  case 15:
#line 165 "sintatica.y"
{	
	yyval.traducao = yyvsp[0].traducao + "\t\n";
}
#line 1669 "y.tab.c"
    break;

  case 16:
#line 169 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1677 "y.tab.c"
    break;

  case 17:
#line 173 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1685 "y.tab.c"
    break;

  case 18:
#line 177 "sintatica.y"
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	yyval.traducao = yyvsp[-2].traducao + "\t" + neg + " = !" + yyvsp[-2].label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t" + yyvsp[0].traducao + "\n\t" + lbl +":\n";
	
	if(yyvsp[-2].valor=="true") adicionaTabela(neg, yyvsp[-2].tipo, "false", neg);
	else adicionaTabela(neg, yyvsp[-2].tipo, "true", neg);
	
}
#line 1699 "y.tab.c"
    break;

  case 19:
#line 187 "sintatica.y"
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = yyvsp[-4].traducao + "\t" + neg + " = !" + yyvsp[-4].label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\t" + yyvsp[-2].traducao + "\tgoto " + saida + ";\n\t" + lbl + ":\t" + yyvsp[0].traducao + "\n\t" + saida + ":" + "\n";

	if(yyvsp[-4].valor=="true") adicionaTabela(neg, yyvsp[-4].tipo, "false", neg);
	else adicionaTabela(neg, yyvsp[-4].tipo, "true", neg);
}
#line 1713 "y.tab.c"
    break;

  case 20:
#line 197 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = "\t" + lbl +":\n\n"+ yyvsp[-2].traducao + "\t" + var + " = !" + yyvsp[-2].label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";"+ yyvsp[0].traducao + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(var, yyvsp[-2].tipo, yyvsp[-2].valor, var);

}
#line 1727 "y.tab.c"
    break;

  case 21:
#line 207 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = "\t" + lbl + ":" +yyvsp[-5].traducao + "\n" + yyvsp[-2].traducao + "\t" + var + " = !" + yyvsp[-2].label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(var, yyvsp[-2].tipo, yyvsp[-2].valor, var);

}
#line 1741 "y.tab.c"
    break;

  case 22:
#line 217 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string var2 = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +"\n\t" + lbl +":\n\n\t" + var + " = " + yyvsp[-4].label + " < " + yyvsp[-2].label + "\n\t" +  var2 + " = !" + var + "\t" + "\n\n\tif(" + var2 + ") " + "goto " + saida +";" + yyvsp[0].traducao + "\n\t" + yyvsp[-4].label + " = " + yyvsp[-4].label + " + 1;" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";


	if(yyvsp[-4].valor < yyvsp[-2].valor)
	{
	adicionaTabela(var, "bool", "true", var);
	adicionaTabela(var2, "bool", "false", var2);
	}
	else
	{
		adicionaTabela(var, "bool", "false", var);
		adicionaTabela(var2, "bool", "true", var2);
	}
	
}
#line 1766 "y.tab.c"
    break;

  case 23:
#line 238 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1774 "y.tab.c"
    break;

  case 24:
#line 242 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1782 "y.tab.c"
    break;

  case 25:
#line 246 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1790 "y.tab.c"
    break;

  case 26:
#line 252 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-3].label);

	if ((!teste))
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = yyvsp[-1].traducao + "\t" + var + " = " + yyvsp[-1].label + ";\n";
		adicionaTabela(yyvsp[-3].label,yyvsp[-1].tipo, yyvsp[-1].valor, var);
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
#line 1860 "y.tab.c"
    break;

  case 27:
#line 320 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "int", "N/A", var);
		
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1879 "y.tab.c"
    break;

  case 28:
#line 335 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "float", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1897 "y.tab.c"
    break;

  case 29:
#line 349 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "bool", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1915 "y.tab.c"
    break;

  case 30:
#line 363 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "char", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1933 "y.tab.c"
    break;

  case 31:
#line 377 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "string", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1951 "y.tab.c"
    break;

  case 32:
#line 393 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)

	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + ";" + yyvsp[0].traducao;
}
#line 1961 "y.tab.c"
    break;

  case 33:
#line 399 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[0].label, bloc)

	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[0].label].nome_temp + ";\n";
}
#line 1971 "y.tab.c"
    break;

  case 34:
#line 407 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao + "\n\tcout << " + yyvsp[-2].label + ";\n" + yyvsp[0].traducao;
}
#line 1979 "y.tab.c"
    break;

  case 35:
#line 411 "sintatica.y"
{
	yyval.traducao = "\n" + yyvsp[0].traducao + "\tcout << " + yyvsp[0].label + ";\n";
}
#line 1987 "y.tab.c"
    break;

  case 36:
#line 418 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "&&", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 1999 "y.tab.c"
    break;

  case 37:
#line 426 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "||", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2011 "y.tab.c"
    break;

  case 38:
#line 434 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2022 "y.tab.c"
    break;

  case 39:
#line 443 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "==", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2034 "y.tab.c"
    break;

  case 40:
#line 451 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "!=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2046 "y.tab.c"
    break;

  case 41:
#line 460 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2058 "y.tab.c"
    break;

  case 42:
#line 468 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2070 "y.tab.c"
    break;

  case 43:
#line 476 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2082 "y.tab.c"
    break;

  case 44:
#line 484 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2094 "y.tab.c"
    break;

  case 45:
#line 492 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[0], "!", yyvsp[0], yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2106 "y.tab.c"
    break;

  case 46:
#line 500 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2117 "y.tab.c"
    break;

  case 47:
#line 509 "sintatica.y"
{
	yyval.valor = to_string(stoi(yyvsp[0].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (int)" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, "int", yyval.valor, yyval.label);
	yyval.tipo = "int";
}
#line 2130 "y.tab.c"
    break;

  case 48:
#line 518 "sintatica.y"
{
	yyval.valor = to_string(stof(yyvsp[0].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (float)" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, "float", yyval.valor, yyval.label);
	yyval.tipo = "float";
}
#line 2143 "y.tab.c"
    break;

  case 49:
#line 527 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2154 "y.tab.c"
    break;

  case 50:
#line 538 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2165 "y.tab.c"
    break;

  case 51:
#line 545 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "+", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2177 "y.tab.c"
    break;

  case 52:
#line 553 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "-", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2189 "y.tab.c"
    break;

  case 53:
#line 561 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "*", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2201 "y.tab.c"
    break;

  case 54:
#line 569 "sintatica.y"
{
	if(stof(yyvsp[0].valor)==0) yyerror("Divisão por zero");
	
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "/", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2215 "y.tab.c"
    break;

  case 55:
#line 579 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, yyvsp[0].tipo, "N/A", yyval.label);

	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2228 "y.tab.c"
    break;

  case 56:
#line 588 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, yyvsp[0].tipo, "N/A", yyval.label);

	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + "-" + " " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = "-" + yyvsp[0].valor;
}
#line 2241 "y.tab.c"
    break;

  case 57:
#line 601 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "int";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, "int", yyvsp[0].traducao, yyval.label);
}
#line 2253 "y.tab.c"
    break;

  case 58:
#line 609 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "float";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, "float" ,yyvsp[0].traducao, yyval.label);
}
#line 2265 "y.tab.c"
    break;

  case 59:
#line 617 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + "';\n";
	yyval.tipo = "char";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo ,yyval.valor, yyval.label);
}
#line 2277 "y.tab.c"
    break;

  case 60:
#line 625 "sintatica.y"
{
	yyval.tipo = "string";
	yyval.valor = yyvsp[0].traducao;
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyvsp[0].label, yyval.tipo, yyval.valor, yyval.label);
	yyval.traducao = "\tstrcpy(" + yyval.label + ", " + yyvsp[0].traducao + ");\n\t";	
	
}
#line 2290 "y.tab.c"
    break;

  case 61:
#line 634 "sintatica.y"
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
#line 2306 "y.tab.c"
    break;

  case 62:
#line 646 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "true";
	adicionaTabela(yyval.label, "bool", "true", yyval.label);
}
#line 2318 "y.tab.c"
    break;

  case 63:
#line 654 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "false";
	adicionaTabela(yyval.label, "bool", "false", yyval.label);
}
#line 2330 "y.tab.c"
    break;

  case 64:
#line 662 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao;
	yyval.label = yyvsp[-1].label;
	yyval.tipo = yyvsp[-1].tipo;
	yyval.valor = yyvsp[-1].valor;
}
#line 2341 "y.tab.c"
    break;


#line 2345 "y.tab.c"

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
#line 669 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + to_string(tmp_qnt++);
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
		adicionaTabela(temp, s1.tipo, s1.valor + operador + s3.valor, temp);
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
					adicionaTabela(temp, "bool", "true", temp);
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp);
				}
			}
			else if (operador == "!=")
			{
				if(s1.valor != s3.valor)
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp);
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
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}

		else if (operador == "!=")
		{
			if(s1.valor != s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">")
		{
			if(s1.valor > s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<")
		{
			if(s1.valor < s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<=")
		{
			if(s1.valor <= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">=")
		{
			if(s1.valor >= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
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
			adicionaTabela(temp, "bool", "true", temp);
		}
		else if(operador == "&&" && (s1.valor == "false" || s3.valor == "false")){

			adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "||"){
			if((s1.valor == "false" && s3.valor == "true") || (s1.valor == "true" && s3.valor == "false"))
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else if (s1.valor == "false" && s3.valor == "false"){
				adicionaTabela(temp, "bool", "false", temp);
			}
		}else
		{
			traducao = s1.traducao + "\t" + temp + " = " + operador + " " + s1.label + ";\n";
			if(s3.valor == "true")
			{
				adicionaTabela(temp, "bool", "false", temp);
			}
			else 
			{
				adicionaTabela(temp, "bool", "true", temp);
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

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/")
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
			adicionaTabela(novo.label, "float", to_string(stof(s3.valor)), novo.label);
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
			adicionaTabela(novo.label, "float", to_string(stof(s1.valor)), novo.label);
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
			adicionaTabela(novo.label, "int", (s3.valor), novo.label);
			get<1>(expr) = novo;
		}
	}else if(tipo3 == "int") // Regra para coerção int
	{
		if(tipo1 == "char") // Regra para coerção char
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (int)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "int", (s3.valor), novo.label);
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

void adicionaTabela(string nome, string tipo, string valor, string novo_nome)
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
			
			traducao = traducao + "\t"+ "char" + " " + val.nome_temp + "["+ to_string(size(val.valor)-1)+ "]" +";\n";
			continue;
		}
		
		traducao = traducao + "\t"+ val.tipo + " " + val.nome_temp + ";\n";
		
	}
	return traducao;
}

void imprimeTabela()
{
	for (int i = 0; i <= bloco_qtd_debug; i++)
	{
		cout << "\n\n\t\tTABELA DE SíMBOLOS | BLOCO " << i <<"\n\nSÍMBOLO\t\tTIPO\tATRIBUIÇÃO\tNOME\n-------------------------------------------------------------\n";
		for(auto const& [key, val]: T_debug[i]) {
			cout << key << "\t\t" + val.tipo << "\t" + val.valor << "\t\t" + val.nome_temp<<"\n";
		}
		cout << "-------------------------------------------------------------\n";
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
