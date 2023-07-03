/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
#include <sstream>
#include <map>
#include <tuple>
#include <vector>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
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
string trad_aritmetica(struct atributos, string, struct atributos, string);
string trad_relacional(struct atributos, string, struct atributos, string);
string trad_if(struct atributos, string, struct atributos, string);
string trad_logico(struct atributos, string, struct atributos, string);
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retorna a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string); // adiciona um símbolo na tabela, com seu tipo, valor e nome_temp
tuple<struct atributos, struct atributos> coercao_tipo(struct atributos, struct atributos);
bool testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
string tipo_simbolo(string); // Retorna o tipo do símbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a tradução de todas as declarações do código intermediário, no topo de seu bloco_qtd
void imprimeTabela(); // Imprime a tabela de símbolos

vector<map<string, simbolo>> T_simbolo; // Mapa, identificado pelo nome da variável
vector<map<string, simbolo>> T_debug;

int tmp_qnt = 0;
int num_linha = 1;
int bloco_qtd = -1;
int bloco_qtd_debug = -1;


#line 125 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MAIN = 258,                    /* MAIN  */
    ID = 259,                      /* ID  */
    NUM = 260,                     /* NUM  */
    REAL = 261,                    /* REAL  */
    CHAR = 262,                    /* CHAR  */
    STRING = 263,                  /* STRING  */
    FIM = 264,                     /* FIM  */
    ERROR = 265,                   /* ERROR  */
    TIPO_INT = 266,                /* TIPO_INT  */
    TIPO_FLOAT = 267,              /* TIPO_FLOAT  */
    TIPO_CHAR = 268,               /* TIPO_CHAR  */
    TIPO_BOOL = 269,               /* TIPO_BOOL  */
    TIPO_STRING = 270,             /* TIPO_STRING  */
    ATRIBUI = 271,                 /* ATRIBUI  */
    SOMA = 272,                    /* SOMA  */
    SUBTRAI = 273,                 /* SUBTRAI  */
    MULTIPLICA = 274,              /* MULTIPLICA  */
    DIVIDE = 275,                  /* DIVIDE  */
    MAIOR = 276,                   /* MAIOR  */
    MENOR = 277,                   /* MENOR  */
    MAIOR_IGUAL = 278,             /* MAIOR_IGUAL  */
    MENOR_IGUAL = 279,             /* MENOR_IGUAL  */
    IGUAL = 280,                   /* IGUAL  */
    DIFERENTE = 281,               /* DIFERENTE  */
    E_LOGICO = 282,                /* E_LOGICO  */
    OU_LOGICO = 283,               /* OU_LOGICO  */
    VERDADEIRO = 284,              /* VERDADEIRO  */
    FALSO = 285,                   /* FALSO  */
    NEGAR = 286,                   /* NEGAR  */
    IF = 287,                      /* IF  */
    WHILE = 288                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define WHILE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIN = 3,                       /* MAIN  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_FIM = 9,                        /* FIM  */
  YYSYMBOL_ERROR = 10,                     /* ERROR  */
  YYSYMBOL_TIPO_INT = 11,                  /* TIPO_INT  */
  YYSYMBOL_TIPO_FLOAT = 12,                /* TIPO_FLOAT  */
  YYSYMBOL_TIPO_CHAR = 13,                 /* TIPO_CHAR  */
  YYSYMBOL_TIPO_BOOL = 14,                 /* TIPO_BOOL  */
  YYSYMBOL_TIPO_STRING = 15,               /* TIPO_STRING  */
  YYSYMBOL_ATRIBUI = 16,                   /* ATRIBUI  */
  YYSYMBOL_SOMA = 17,                      /* SOMA  */
  YYSYMBOL_SUBTRAI = 18,                   /* SUBTRAI  */
  YYSYMBOL_MULTIPLICA = 19,                /* MULTIPLICA  */
  YYSYMBOL_DIVIDE = 20,                    /* DIVIDE  */
  YYSYMBOL_MAIOR = 21,                     /* MAIOR  */
  YYSYMBOL_MENOR = 22,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 23,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 24,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 25,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 26,                 /* DIFERENTE  */
  YYSYMBOL_E_LOGICO = 27,                  /* E_LOGICO  */
  YYSYMBOL_OU_LOGICO = 28,                 /* OU_LOGICO  */
  YYSYMBOL_VERDADEIRO = 29,                /* VERDADEIRO  */
  YYSYMBOL_FALSO = 30,                     /* FALSO  */
  YYSYMBOL_NEGAR = 31,                     /* NEGAR  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_S = 40,                         /* S  */
  YYSYMBOL_bloco = 41,                     /* bloco  */
  YYSYMBOL_comandos = 42,                  /* comandos  */
  YYSYMBOL_fake = 43,                      /* fake  */
  YYSYMBOL_comando = 44,                   /* comando  */
  YYSYMBOL_expressao = 45,                 /* expressao  */
  YYSYMBOL_relacao = 46,                   /* relacao  */
  YYSYMBOL_converte = 47,                  /* converte  */
  YYSYMBOL_aritmetica = 48,                /* aritmetica  */
  YYSYMBOL_fator = 49                      /* fator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    74,    82,    87,    92,   100,   104,   108,
     154,   166,   177,   188,   201,   207,   217,   223,   229,   236,
     242,   249,   255,   261,   267,   273,   279,   286,   294,   302,
     311,   316,   322,   328,   334,   342,   349,   360,   366,   372,
     378,   382,   392,   398,   404
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "ID", "NUM",
  "REAL", "CHAR", "STRING", "FIM", "ERROR", "TIPO_INT", "TIPO_FLOAT",
  "TIPO_CHAR", "TIPO_BOOL", "TIPO_STRING", "ATRIBUI", "SOMA", "SUBTRAI",
  "MULTIPLICA", "DIVIDE", "MAIOR", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL",
  "IGUAL", "DIFERENTE", "E_LOGICO", "OU_LOGICO", "VERDADEIRO", "FALSO",
  "NEGAR", "IF", "WHILE", "'('", "')'", "'{'", "'}'", "';'", "$accept",
  "S", "bloco", "comandos", "fake", "comando", "expressao", "relacao",
  "converte", "aritmetica", "fator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,    25,    75,    43,   -26,    45,   -26,   -26,    42,    56,
      65,   -26,   -26,   -26,   -26,    80,    87,    94,    95,    89,
      89,   -26,   -26,    15,    66,    67,     0,   -26,    68,    56,
      -1,   -26,   -26,    91,   -26,    15,    64,    82,    83,    84,
     -26,    15,   -17,   -17,   -26,    15,    15,    69,    90,    44,
     -26,   -26,    15,    15,   -26,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    38,   -26,   -26,   -26,   -26,
      92,    93,    15,    15,   -26,   -26,   -26,   -17,   -17,   -17,
     -17,    21,    21,    21,    21,    21,    21,   -26,   -26,   -26,
      -3,    -3,   -26,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     6,     2,     0,     5,
      41,    37,    38,    39,    40,     0,     0,     0,     0,     0,
       0,    42,    43,     0,     0,     0,     0,     7,     0,     5,
       0,    18,    26,    29,    30,     0,     0,     0,     0,     0,
      41,     0,    35,    36,    25,     0,     0,     0,     0,     0,
       3,     4,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    13,    12,
       0,     0,     0,     0,    44,    16,    17,    31,    32,    33,
      34,    21,    22,    23,    24,    19,    20,     9,     6,     6,
      27,    28,    14,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,    -6,    74,   -26,   -26,   -25,   -10,   -26,    -5,
     -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    27,    28,     8,    29,    30,    31,    32,    33,
      34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       7,    49,    57,    58,    40,    11,    12,    13,    14,     1,
      65,    47,    48,    44,    42,    43,    49,    19,    20,    40,
      11,    12,    13,    14,    52,    53,    52,    53,     3,    21,
      22,    23,    19,    20,    26,    70,    71,    54,    55,    56,
      57,    58,    75,    76,    21,    22,    23,    90,    91,    26,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      10,    11,    12,    13,    14,    52,    53,    15,    16,    17,
      18,    52,    53,    19,    20,     4,    87,     5,     9,    74,
       6,    35,    92,    93,    36,    21,    22,    23,    24,    25,
      26,    37,    -6,    40,    11,    12,    13,    14,    38,    39,
      45,    46,    66,    51,    72,    50,    19,    20,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    21,    22,
      67,    68,    69,    41,     0,    73,     0,    88,    89
};

static const yytype_int8 yycheck[] =
{
       6,    26,    19,    20,     4,     5,     6,     7,     8,    11,
      35,    11,    12,    23,    19,    20,    41,    17,    18,     4,
       5,     6,     7,     8,    27,    28,    27,    28,     3,    29,
      30,    31,    17,    18,    34,    45,    46,    38,    17,    18,
      19,    20,    52,    53,    29,    30,    31,    72,    73,    34,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       4,     5,     6,     7,     8,    27,    28,    11,    12,    13,
      14,    27,    28,    17,    18,     0,    38,    34,    36,    35,
      35,    16,    88,    89,     4,    29,    30,    31,    32,    33,
      34,     4,    36,     4,     5,     6,     7,     8,     4,     4,
      34,    34,    38,    29,    35,    37,    17,    18,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    29,    30,
      38,    38,    38,    34,    -1,    35,    -1,    35,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    40,     3,     0,    34,    35,    41,    43,    36,
       4,     5,     6,     7,     8,    11,    12,    13,    14,    17,
      18,    29,    30,    31,    32,    33,    34,    41,    42,    44,
      45,    46,    47,    48,    49,    16,     4,     4,     4,     4,
       4,    34,    48,    48,    46,    34,    34,    11,    12,    45,
      37,    42,    27,    28,    38,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    45,    38,    38,    38,    38,
      46,    46,    35,    35,    35,    46,    46,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    38,    35,    35,
      45,    45,    41,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    43,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     0,     0,     1,     2,     4,
       3,     3,     3,     3,     5,     5,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     2,     1,     4,     4,     1,
       1,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* S: TIPO_INT MAIN '(' ')' bloco  */
#line 70 "sintatica.y"
{
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{" << yyvsp[0].traducao << "\n\treturn 0;\n}" << endl;
}
#line 1329 "y.tab.c"
    break;

  case 3: /* bloco: fake '{' comandos '}'  */
#line 75 "sintatica.y"
{	
	yyval.traducao = "\t\n" + traducao_declaracao() + "\n" + yyvsp[-1].traducao;
	bloco_qtd--;
	T_debug.push_back(T_simbolo[bloco_qtd+1]);
	T_simbolo.pop_back();
}
#line 1340 "y.tab.c"
    break;

  case 4: /* comandos: comando comandos  */
#line 83 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1348 "y.tab.c"
    break;

  case 5: /* comandos: %empty  */
#line 87 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1356 "y.tab.c"
    break;

  case 6: /* fake: %empty  */
#line 92 "sintatica.y"
{
	bloco_qtd++;
	bloco_qtd_debug++;
	map<string, simbolo> a;
	T_simbolo.push_back(a);
	yyval.traducao = "";
}
#line 1368 "y.tab.c"
    break;

  case 7: /* comando: bloco  */
#line 101 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1376 "y.tab.c"
    break;

  case 8: /* comando: expressao ';'  */
#line 105 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1384 "y.tab.c"
    break;

  case 9: /* comando: ID ATRIBUI expressao ';'  */
#line 109 "sintatica.y"
{
	if(!(testa_simbolo(yyvsp[-3].label)))
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = yyvsp[-1].traducao + "\t" + var + " = " + T_simbolo[bloco_qtd][yyvsp[-1].label].nome_temp + ";\n";
		adicionaTabela(yyvsp[-3].label, T_simbolo[bloco_qtd][yyvsp[-1].label].tipo, T_simbolo[bloco_qtd][yyvsp[-1].label].valor, var);
		
	}
	else
	{
		if(T_simbolo[bloco_qtd][yyvsp[-3].label].tipo == T_simbolo[bloco_qtd][yyvsp[-1].label].tipo)
		{
			yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloco_qtd][yyvsp[-3].label].nome_temp + " = " + T_simbolo[bloco_qtd][yyvsp[-1].label].nome_temp + ";\n";
		}
		else if(T_simbolo[bloco_qtd][yyvsp[-1].label].tipo == "bool")
		{
			yyerror("Variável esperava tipo " + T_simbolo[bloco_qtd][yyvsp[-3].label].tipo + ", mas recebeu tipo " + T_simbolo[bloco_qtd][yyvsp[-1].label].tipo);
		}
		else if(T_simbolo[bloco_qtd][yyvsp[-3].label].tipo == "float") // Regra para coerção float
		{
			if(T_simbolo[bloco_qtd][yyvsp[-1].label].tipo == "int") // Regra para coerção int
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloco_qtd][yyvsp[-3].label].nome_temp + " = (float) " + T_simbolo[bloco_qtd][yyvsp[-1].label].nome_temp + ";\n";
			}
			else if(T_simbolo[bloco_qtd][yyvsp[-1].label].tipo == "char") // Regra para coerção char
			{
				yyerror("Variável esperava tipo " + T_simbolo[bloco_qtd][yyvsp[-3].label].tipo + ", mas recebeu tipo " + T_simbolo[bloco_qtd][yyvsp[-1].label].tipo);
			}
		}
		else if(T_simbolo[bloco_qtd][yyvsp[-3].label].tipo == "int") // Regra para coerção int
		{
			if(T_simbolo[bloco_qtd][yyvsp[-1].label].tipo == "float") // Regra para coerção float
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloco_qtd][yyvsp[-3].label].nome_temp + " = (int) " + T_simbolo[bloco_qtd][yyvsp[-1].label].nome_temp + ";\n";
			}
			else if(T_simbolo[bloco_qtd][yyvsp[-1].label].tipo == "char") // Regra para coerção de char
			{
				yyval.traducao = yyvsp[-1].traducao + "\t" + T_simbolo[bloco_qtd][yyvsp[-3].label].nome_temp + " = (int) " + T_simbolo[bloco_qtd][yyvsp[-1].label].nome_temp + ";\n";
			}
		}else{
			yyerror("Variável esperava tipo " + T_simbolo[bloco_qtd][yyvsp[-3].label].tipo + ", mas recebeu tipo " + T_simbolo[bloco_qtd][yyvsp[-1].label].tipo);
		}
		T_simbolo[bloco_qtd][yyvsp[-3].label].valor = T_simbolo[bloco_qtd][yyvsp[-1].label].valor;
	}
}
#line 1434 "y.tab.c"
    break;

  case 10: /* comando: TIPO_INT ID ';'  */
#line 155 "sintatica.y"
{
	if (!(testa_simbolo(yyvsp[-1].label)))
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "int", "N/A", var);
		
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1450 "y.tab.c"
    break;

  case 11: /* comando: TIPO_FLOAT ID ';'  */
#line 167 "sintatica.y"
{
	if (!(testa_simbolo(yyvsp[-1].label)))
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "float", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1465 "y.tab.c"
    break;

  case 12: /* comando: TIPO_BOOL ID ';'  */
#line 178 "sintatica.y"
{
	if (!(testa_simbolo(yyvsp[-1].label)))
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "bool", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1480 "y.tab.c"
    break;

  case 13: /* comando: TIPO_CHAR ID ';'  */
#line 189 "sintatica.y"
{
	if (!(testa_simbolo(yyvsp[-1].label)))
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "char", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1495 "y.tab.c"
    break;

  case 14: /* comando: IF '(' relacao ')' bloco  */
#line 202 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = trad_if(yyvsp[-4], "", yyvsp[-2], yyval.label);
}
#line 1504 "y.tab.c"
    break;

  case 15: /* comando: WHILE '(' relacao ')' bloco  */
#line 208 "sintatica.y"
{
	
	
}
#line 1513 "y.tab.c"
    break;

  case 16: /* expressao: expressao E_LOGICO relacao  */
#line 218 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], "&&", yyvsp[0], yyval.label);
}
#line 1523 "y.tab.c"
    break;

  case 17: /* expressao: expressao OU_LOGICO relacao  */
#line 224 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], "||", yyvsp[0], yyval.label);
}
#line 1533 "y.tab.c"
    break;

  case 18: /* expressao: relacao  */
#line 230 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
}
#line 1542 "y.tab.c"
    break;

  case 19: /* relacao: aritmetica IGUAL aritmetica  */
#line 237 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], "==", yyvsp[0], yyval.label);
}
#line 1552 "y.tab.c"
    break;

  case 20: /* relacao: aritmetica DIFERENTE aritmetica  */
#line 243 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], "!=", yyvsp[0], yyval.label);
}
#line 1562 "y.tab.c"
    break;

  case 21: /* relacao: aritmetica MAIOR aritmetica  */
#line 250 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], ">", yyvsp[0], yyval.label);
}
#line 1572 "y.tab.c"
    break;

  case 22: /* relacao: aritmetica MENOR aritmetica  */
#line 256 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], "<", yyvsp[0], yyval.label);
}
#line 1582 "y.tab.c"
    break;

  case 23: /* relacao: aritmetica MAIOR_IGUAL aritmetica  */
#line 262 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], ">=", yyvsp[0], yyval.label);
}
#line 1592 "y.tab.c"
    break;

  case 24: /* relacao: aritmetica MENOR_IGUAL aritmetica  */
#line 268 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[-2], "<=", yyvsp[0], yyval.label);
}
#line 1602 "y.tab.c"
    break;

  case 25: /* relacao: NEGAR relacao  */
#line 274 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[0], "!", yyvsp[0], yyval.label);
}
#line 1612 "y.tab.c"
    break;

  case 26: /* relacao: converte  */
#line 280 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
}
#line 1621 "y.tab.c"
    break;

  case 27: /* converte: '(' TIPO_INT ')' expressao  */
#line 287 "sintatica.y"
{
	string conversao = to_string(stoi(T_simbolo[bloco_qtd][yyvsp[0].label].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (int)" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, "int", conversao, yyval.label);
}
#line 1633 "y.tab.c"
    break;

  case 28: /* converte: '(' TIPO_FLOAT ')' expressao  */
#line 295 "sintatica.y"
{
	string conversao = to_string(stof(T_simbolo[bloco_qtd][yyvsp[0].label].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (float)" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, "float", conversao, yyval.label);
}
#line 1645 "y.tab.c"
    break;

  case 29: /* converte: aritmetica  */
#line 303 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
}
#line 1654 "y.tab.c"
    break;

  case 30: /* aritmetica: fator  */
#line 312 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
}
#line 1663 "y.tab.c"
    break;

  case 31: /* aritmetica: aritmetica SOMA aritmetica  */
#line 317 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();

	yyval.traducao = traducao_expressao(yyvsp[-2], "+", yyvsp[0], yyval.label);
}
#line 1673 "y.tab.c"
    break;

  case 32: /* aritmetica: aritmetica SUBTRAI aritmetica  */
#line 323 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();

	yyval.traducao = traducao_expressao(yyvsp[-2], "-", yyvsp[0], yyval.label);
}
#line 1683 "y.tab.c"
    break;

  case 33: /* aritmetica: aritmetica MULTIPLICA aritmetica  */
#line 329 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();

	yyval.traducao = traducao_expressao(yyvsp[-2], "*", yyvsp[0], yyval.label);
}
#line 1693 "y.tab.c"
    break;

  case 34: /* aritmetica: aritmetica DIVIDE aritmetica  */
#line 335 "sintatica.y"
{
	if(stof(T_simbolo[bloco_qtd][yyvsp[0].label].valor)==0) yyerror("Divisão por zero");
	
	yyval.label = geraVariavelTemporaria();

	yyval.traducao = traducao_expressao(yyvsp[-2], "/", yyvsp[0], yyval.label);
}
#line 1705 "y.tab.c"
    break;

  case 35: /* aritmetica: SOMA aritmetica  */
#line 343 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, tipo_simbolo(yyvsp[0].label), "N/A", yyval.label);

	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + T_simbolo[bloco_qtd][yyvsp[0].label].nome_temp + ";\n";
}
#line 1716 "y.tab.c"
    break;

  case 36: /* aritmetica: SUBTRAI aritmetica  */
#line 350 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, tipo_simbolo(yyvsp[0].label), "N/A", yyval.label);

	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + "-" + " " + T_simbolo[bloco_qtd][yyvsp[0].label].nome_temp + ";\n";
}
#line 1727 "y.tab.c"
    break;

  case 37: /* fator: NUM  */
#line 361 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	adicionaTabela(yyval.label, "int", yyvsp[0].traducao, yyval.label);
}
#line 1737 "y.tab.c"
    break;

  case 38: /* fator: REAL  */
#line 367 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	adicionaTabela(yyval.label, "float" ,yyvsp[0].traducao, yyval.label);
}
#line 1747 "y.tab.c"
    break;

  case 39: /* fator: CHAR  */
#line 373 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + " ;\n";
	adicionaTabela(yyval.label, "char" ,yyvsp[0].traducao, yyval.label);
}
#line 1757 "y.tab.c"
    break;

  case 40: /* fator: STRING  */
#line 379 "sintatica.y"
{
	//Para fazer
}
#line 1765 "y.tab.c"
    break;

  case 41: /* fator: ID  */
#line 383 "sintatica.y"
{
	if(!(testa_simbolo(yyvsp[0].label)))
	{
		yyerror("Variável não declarada!");
	}else
	{
		yyval.traducao = "";
	}
}
#line 1779 "y.tab.c"
    break;

  case 42: /* fator: VERDADEIRO  */
#line 393 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
	adicionaTabela(yyval.label, "bool", "true", yyval.label);
}
#line 1789 "y.tab.c"
    break;

  case 43: /* fator: FALSO  */
#line 399 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
	adicionaTabela(yyval.label, "bool", "false", yyval.label);
}
#line 1799 "y.tab.c"
    break;

  case 44: /* fator: '(' expressao ')'  */
#line 405 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao;
	yyval.label = yyvsp[-1].label;
}
#line 1808 "y.tab.c"
    break;


#line 1812 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 410 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + to_string(tmp_qnt++);
}

string trad_aritmetica(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		yyerror("Tipo bool não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if(T_simbolo[bloco_qtd][s1.label].tipo == "char")
	{
		yyerror("Tipo char não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if((T_simbolo[bloco_qtd][s1.label].tipo == "float" || T_simbolo[bloco_qtd][s1.label].tipo == "int"))
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + " " + operador + " " + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n";
		adicionaTabela(temp, T_simbolo[bloco_qtd][s1.label].tipo, T_simbolo[bloco_qtd][s1.label].valor + operador + T_simbolo[bloco_qtd][s3.label].valor, temp);
	}

	return traducao;
}

string trad_relacional(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + " " + operador + " " + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		if (operador == "<" || operador == ">" || operador == "<=" || operador == ">=")
		{
			yyerror("Tipo não suporta operações relacionais (<, >, >=, <=)"); // termina a função
		}
		else
		{
			if(operador == "==")
			{
				if(T_simbolo[bloco_qtd][s1.label].valor == T_simbolo[bloco_qtd][s3.label].valor)
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
				if(T_simbolo[bloco_qtd][s1.label].valor != T_simbolo[bloco_qtd][s3.label].valor)
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
	if (T_simbolo[bloco_qtd][s1.label].tipo == "float" || T_simbolo[bloco_qtd][s1.label].tipo == "int" || T_simbolo[bloco_qtd][s1.label].tipo == "char")
	{
		if(operador == "==")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor == T_simbolo[bloco_qtd][s3.label].valor)
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}

		else if (operador == "!=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor != T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor > T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor < T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor <= T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor >= T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
	}

	return traducao;
}

string trad_if(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t"+temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n\n\tif(" +temp+ ")\n\t{\n"+ "\n\t}\n";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		if (operador == "<" || operador == ">" || operador == "<=" || operador == ">=")
		{
			yyerror("Tipo não suporta operações relacionais (<, >, >=, <=)"); // termina a função
		}
		else
		{
			if(operador == "==")
			{
				if(T_simbolo[bloco_qtd][s1.label].valor == T_simbolo[bloco_qtd][s3.label].valor)
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
				if(T_simbolo[bloco_qtd][s1.label].valor != T_simbolo[bloco_qtd][s3.label].valor)
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
	if (T_simbolo[bloco_qtd][s1.label].tipo == "float" || T_simbolo[bloco_qtd][s1.label].tipo == "int" || T_simbolo[bloco_qtd][s1.label].tipo == "char")
	{
		if(operador == "==")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor == T_simbolo[bloco_qtd][s3.label].valor)
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}

		else if (operador == "!=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor != T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor > T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor < T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor <= T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor >= T_simbolo[bloco_qtd][s3.label].valor)
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
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + " " + operador + " " + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		if((operador == "&&" || operador == "||") && (T_simbolo[bloco_qtd][s1.label].valor == "true" && T_simbolo[bloco_qtd][s3.label].valor == "true")){
			adicionaTabela(temp, "bool", "true", temp);
		}
		else if(operador == "&&" && (T_simbolo[bloco_qtd][s1.label].valor == "false" || T_simbolo[bloco_qtd][s3.label].valor == "false")){

			adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "||"){
			if((T_simbolo[bloco_qtd][s1.label].valor == "false" && T_simbolo[bloco_qtd][s3.label].valor == "true") || (T_simbolo[bloco_qtd][s1.label].valor == "true" && T_simbolo[bloco_qtd][s3.label].valor == "false"))
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else if (T_simbolo[bloco_qtd][s1.label].valor == "false" && T_simbolo[bloco_qtd][s3.label].valor == "false"){
				adicionaTabela(temp, "bool", "false", temp);
			}
		}else
		{
			traducao = s1.traducao + "\t" + temp + " = " + operador + " " + T_simbolo[bloco_qtd][s1.label].nome_temp + ";\n";
			if(T_simbolo[bloco_qtd][s3.label].valor == "true")
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
	struct atributos e1, e3;
	tie(e1,e3) = coercao_tipo(s1,s3);

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/")
	{
		return trad_aritmetica(e1, operador, e3, temp);
	}
	if(operador == "&&"|| operador == "||" || operador == "!")
	{
		return trad_logico(e1, operador, e3, temp);
	}
	if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=")
	{
		return trad_relacional(e1, operador, e3, temp);
	}
	return traducao;
}

tuple<struct atributos, struct atributos> coercao_tipo(struct atributos s1, struct atributos s3)
{
	tuple <struct atributos, struct atributos> expr(s1,s3);
	if(T_simbolo[bloco_qtd][s1.label].tipo == T_simbolo[bloco_qtd][s3.label].tipo)
		return expr;

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool" || T_simbolo[bloco_qtd][s3.label].tipo == "bool")
		yyerror("Tipo booleano não suporta coerção");
	
	struct atributos novo;
	novo.traducao = "";
	novo.label = geraVariavelTemporaria();
	
	if(T_simbolo[bloco_qtd][s1.label].tipo == "float") // Regra para coerção float
	{
		if(T_simbolo[bloco_qtd][s3.label].tipo == "int") // Regra para coerção int
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (float)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(T_simbolo[bloco_qtd][s3.label].valor)), novo.label);
			get<1>(expr) = novo;
		}
		else if(T_simbolo[bloco_qtd][s3.label].tipo == "char") // Regra para coerção char
		{
			yyerror("Expressão não definida para os tipos float e char");
		}
	}
	else if(T_simbolo[bloco_qtd][s3.label].tipo == "float") // Regra para coerção float
	{
		if(T_simbolo[bloco_qtd][s1.label].tipo == "int") // Regra para coerção int
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (float)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(T_simbolo[bloco_qtd][s1.label].valor)), novo.label);
			get<0>(expr) = novo;
		}
		else if(T_simbolo[bloco_qtd][s1.label].tipo == "char") // Regra para coerção de char
		{
			yyerror("Expressão não definida para os tipos char e float");
		}
	}
	else if(T_simbolo[bloco_qtd][s1.label].tipo == "int") // Regra para coerção int
	{
		if(T_simbolo[bloco_qtd][s3.label].tipo == "char") // Regra para coerção char
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (int)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "int", (T_simbolo[bloco_qtd][s3.label].valor), novo.label);
			get<1>(expr) = novo;
		}
	}else if(T_simbolo[bloco_qtd][s3.label].tipo == "int") // Regra para coerção int
	{
		if(T_simbolo[bloco_qtd][s1.label].tipo == "char") // Regra para coerção char
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (int)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "int", (T_simbolo[bloco_qtd][s3.label].valor), novo.label);
			get<0>(expr) = novo;
		}
	}

	return expr;
}

//retorna True se o símbolo está na tabela e False caso o contrario
bool testa_simbolo(string nome)
{
	for(int i=bloco_qtd;i>=0;i--)
		return T_simbolo[bloco_qtd].count(nome)==1;
	return false;
}

void adicionaTabela(string nome, string tipo, string valor, string novo_nome)
{
	if (!(testa_simbolo(nome)))
	{
		simbolo novo;
		novo.tipo = tipo;
		novo.nome_temp = novo_nome;
		novo.valor = valor;
		T_simbolo[bloco_qtd][nome] = novo;
		
	}else if (tipo_simbolo(nome) != tipo)
	{
		// TODO: adicionar conversão e casos de erro
	}
}

// se o simbolo não estiver na tabela retorna mensagem de erro, caso contrário retorna o tipo do simbolo  
string tipo_simbolo(string nome)
{
	if (!(testa_simbolo(nome)))
	{
		yyerror("Variável não declarada");
	}
	//cout << T_simbolo[nome].tipo << endl;
	return T_simbolo[bloco_qtd][nome].tipo;
}

string traducao_declaracao()
{
	string traducao = "";
	for(auto const& [key, val]: T_simbolo[bloco_qtd]) {
		if(val.tipo=="bool")
		{
			traducao = traducao + "\t"+ "int" + " " + val.nome_temp + ";\n";
			continue;
		}
		traducao = traducao + "\t"+ val.tipo + " " + val.nome_temp + ";\n";
	}
	return traducao;
}

void imprimeTabela()
{
	for (int i = 0; i <= bloco_qtd_debug ;i++)
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
