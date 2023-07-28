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


#line 158 "y.tab.c"

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
    TIPO = 266,                    /* TIPO  */
    ATRIBUI = 267,                 /* ATRIBUI  */
    SOMA = 268,                    /* SOMA  */
    SUBTRAI = 269,                 /* SUBTRAI  */
    MULTIPLICA = 270,              /* MULTIPLICA  */
    DIVIDE = 271,                  /* DIVIDE  */
    UNARIOMAIS = 272,              /* UNARIOMAIS  */
    UNARIOMENOS = 273,             /* UNARIOMENOS  */
    MAIOR = 274,                   /* MAIOR  */
    MENOR = 275,                   /* MENOR  */
    MAIOR_IGUAL = 276,             /* MAIOR_IGUAL  */
    MENOR_IGUAL = 277,             /* MENOR_IGUAL  */
    IGUAL = 278,                   /* IGUAL  */
    DIFERENTE = 279,               /* DIFERENTE  */
    E_LOGICO = 280,                /* E_LOGICO  */
    OU_LOGICO = 281,               /* OU_LOGICO  */
    VERDADEIRO = 282,              /* VERDADEIRO  */
    FALSO = 283,                   /* FALSO  */
    NEGAR = 284,                   /* NEGAR  */
    IF = 285,                      /* IF  */
    ELSE = 286,                    /* ELSE  */
    WHILE = 287,                   /* WHILE  */
    DO = 288,                      /* DO  */
    FOR = 289,                     /* FOR  */
    CONTINUE = 290,                /* CONTINUE  */
    BREAK = 291,                   /* BREAK  */
    SCAN = 292,                    /* SCAN  */
    PRINT = 293                    /* PRINT  */
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
  YYSYMBOL_TIPO = 11,                      /* TIPO  */
  YYSYMBOL_ATRIBUI = 12,                   /* ATRIBUI  */
  YYSYMBOL_SOMA = 13,                      /* SOMA  */
  YYSYMBOL_SUBTRAI = 14,                   /* SUBTRAI  */
  YYSYMBOL_MULTIPLICA = 15,                /* MULTIPLICA  */
  YYSYMBOL_DIVIDE = 16,                    /* DIVIDE  */
  YYSYMBOL_UNARIOMAIS = 17,                /* UNARIOMAIS  */
  YYSYMBOL_UNARIOMENOS = 18,               /* UNARIOMENOS  */
  YYSYMBOL_MAIOR = 19,                     /* MAIOR  */
  YYSYMBOL_MENOR = 20,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 21,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 22,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 23,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 24,                 /* DIFERENTE  */
  YYSYMBOL_E_LOGICO = 25,                  /* E_LOGICO  */
  YYSYMBOL_OU_LOGICO = 26,                 /* OU_LOGICO  */
  YYSYMBOL_VERDADEIRO = 27,                /* VERDADEIRO  */
  YYSYMBOL_FALSO = 28,                     /* FALSO  */
  YYSYMBOL_NEGAR = 29,                     /* NEGAR  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_DO = 33,                        /* DO  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 36,                     /* BREAK  */
  YYSYMBOL_SCAN = 37,                      /* SCAN  */
  YYSYMBOL_PRINT = 38,                     /* PRINT  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_S = 49,                         /* S  */
  YYSYMBOL_globais = 50,                   /* globais  */
  YYSYMBOL_global = 51,                    /* global  */
  YYSYMBOL_parametros = 52,                /* parametros  */
  YYSYMBOL_p1 = 53,                        /* p1  */
  YYSYMBOL_parametro = 54,                 /* parametro  */
  YYSYMBOL_bloco = 55,                     /* bloco  */
  YYSYMBOL_comandos = 56,                  /* comandos  */
  YYSYMBOL_blocofuncao = 57,               /* blocofuncao  */
  YYSYMBOL_comando = 58,                   /* comando  */
  YYSYMBOL_atribuicao = 59,                /* atribuicao  */
  YYSYMBOL_declaracao = 60,                /* declaracao  */
  YYSYMBOL_entradas = 61,                  /* entradas  */
  YYSYMBOL_expressoes = 62,                /* expressoes  */
  YYSYMBOL_expressao = 63,                 /* expressao  */
  YYSYMBOL_relacao = 64,                   /* relacao  */
  YYSYMBOL_converte = 65,                  /* converte  */
  YYSYMBOL_aritmetica = 66,                /* aritmetica  */
  YYSYMBOL_fator = 67                      /* fator  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
     305,   380,   385,   393,   407,   421,   441,   460,   485,   490,
     497,   501,   508,   516,   524,   533,   541,   550,   558,   566,
     574,   582,   590,   600,   617,   627,   634,   642,   650,   658,
     668,   677,   690,   698,   706,   714,   723,   735,   743,   751,
     758
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
  "REAL", "CHAR", "STRING", "FIM", "ERROR", "TIPO", "ATRIBUI", "SOMA",
  "SUBTRAI", "MULTIPLICA", "DIVIDE", "UNARIOMAIS", "UNARIOMENOS", "MAIOR",
  "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "E_LOGICO",
  "OU_LOGICO", "VERDADEIRO", "FALSO", "NEGAR", "IF", "ELSE", "WHILE", "DO",
  "FOR", "CONTINUE", "BREAK", "SCAN", "PRINT", "'('", "')'", "'{'", "'}'",
  "','", "';'", "':'", "'['", "']'", "$accept", "S", "globais", "global",
  "parametros", "p1", "parametro", "bloco", "comandos", "blocofuncao",
  "comando", "atribuicao", "declaracao", "entradas", "expressoes",
  "expressao", "relacao", "converte", "aritmetica", "fator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,     9,    15,  -102,     3,   155,    58,  -102,    15,  -102,
    -102,    43,    71,    11,    42,   -34,  -102,  -102,    67,  -102,
    -102,  -102,  -102,   107,   107,  -102,  -102,    71,    53,    -4,
    -102,  -102,   142,  -102,  -102,  -102,  -102,    91,    70,  -102,
      56,    71,    71,   128,   128,  -102,   105,    47,    71,    71,
    -102,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   103,   112,   141,     0,   130,    76,    71,  -102,  -102,
    -102,   128,   128,   128,   128,   161,   161,   161,   161,   161,
     161,    61,    86,   150,   131,  -102,   135,    51,   175,   144,
     145,  -102,   146,   136,   137,   147,   148,  -102,   140,     0,
    -102,  -102,    45,  -102,    71,   143,  -102,   184,  -102,   185,
    -102,   151,   141,   -34,    71,    71,   157,   121,  -102,  -102,
     187,    71,  -102,  -102,  -102,  -102,   149,   152,     0,  -102,
      68,   111,   154,   153,   158,   160,   162,   159,   163,   164,
    -102,  -102,    71,   121,   187,   165,   166,  -102,  -102,  -102,
     173,  -102,   113,   168,  -102,  -102,  -102,  -102,   167,  -102,
    -102,  -102,  -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      16,     0,     0,     1,     0,     0,     0,     2,     0,     6,
       5,     0,     0,     0,     0,    16,     3,    16,    66,    62,
      63,    64,    65,     0,     0,    67,    68,     0,     0,     0,
      44,    52,    54,    55,    31,    32,    33,     0,     0,     4,
       0,     0,     0,    60,    61,    51,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    15,     0,    41,     0,    69,    42,
      43,    56,    57,    58,    59,    47,    48,    49,    50,    45,
      46,     0,     0,     0,     0,     8,    11,    66,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,     0,    15,
      19,    27,     0,    70,     0,    53,    34,     0,    36,     0,
      12,     0,     9,     0,     0,     0,     0,     0,    29,    28,
       0,     0,    13,    14,    18,    40,     0,     0,    15,    10,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
      16,    16,     0,     0,     0,     0,     0,    35,    37,     7,
      20,    22,     0,     0,    38,    25,    26,    16,     0,    16,
      21,    23,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   186,  -102,    83,  -102,  -102,   -17,   -74,   118,
    -102,   114,   139,    69,  -101,   -11,   -25,  -102,    -8,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     8,    84,    85,    86,    97,    98,    40,
      99,   100,   101,   135,    65,    66,    30,    31,    32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    29,    45,   125,    87,    19,    20,    21,    22,     3,
      36,    88,    37,    23,    24,    43,    44,    47,     4,     5,
     136,    48,    49,    69,    70,   123,     6,    25,    26,    27,
      89,    47,    90,    91,    92,    93,    94,    95,    96,    28,
      50,   -16,    11,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   102,   139,    34,   105,    18,    19,    20,
      21,    22,    15,    12,    46,   133,    23,    24,    13,    14,
      48,    49,    48,    49,   116,    18,    19,    20,    21,    22,
      25,    26,    27,    17,    23,    24,    35,    68,   102,   124,
      41,   153,    28,    48,    49,    61,    62,    64,    25,    26,
      27,    48,    49,   130,   131,   106,    41,   107,   140,    63,
      28,    18,    19,    20,    21,    22,     9,   102,     2,   104,
      23,    24,     9,   150,   151,    18,    19,    20,    21,    22,
     108,   152,   109,    38,    25,    26,    48,    49,    48,    49,
     160,    10,   162,    53,    54,    67,    42,    10,    25,    26,
      81,   141,    83,   158,   110,    51,    52,    53,    54,    82,
      42,    55,    56,    57,    58,    59,    60,    12,    48,    49,
     103,   111,    13,    14,    51,    52,    53,    54,   112,   113,
     118,   119,   122,   114,   115,   117,   120,   121,   126,   132,
     127,   134,   128,   142,    16,   129,   137,     0,   143,   138,
     145,   144,   146,   147,   157,     0,   149,   148,   159,   155,
     156,   161,     0,   154
};

static const yytype_int16 yycheck[] =
{
      17,    12,    27,   104,     4,     5,     6,     7,     8,     0,
      44,    11,    46,    13,    14,    23,    24,    28,     3,     4,
     121,    25,    26,    48,    49,    99,    11,    27,    28,    29,
      30,    42,    32,    33,    34,    35,    36,    37,    38,    39,
      44,    41,    39,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    64,   128,    44,    67,     4,     5,     6,
       7,     8,     4,    12,    11,   117,    13,    14,    17,    18,
      25,    26,    25,    26,    91,     4,     5,     6,     7,     8,
      27,    28,    29,    40,    13,    14,    44,    40,    99,    44,
      39,   143,    39,    25,    26,     4,     5,    41,    27,    28,
      29,    25,    26,   114,   115,    44,    39,    46,    40,    39,
      39,     4,     5,     6,     7,     8,     2,   128,     0,    43,
      13,    14,     8,   140,   141,     4,     5,     6,     7,     8,
      44,   142,    46,    15,    27,    28,    25,    26,    25,    26,
     157,     2,   159,    15,    16,    40,    39,     8,    27,    28,
      47,    40,    11,    40,     4,    13,    14,    15,    16,    47,
      39,    19,    20,    21,    22,    23,    24,    12,    25,    26,
      40,    40,    17,    18,    13,    14,    15,    16,    43,     4,
      44,    44,    42,    39,    39,    39,    39,    39,     4,    32,
       5,     4,    41,    39,     8,   112,    47,    -1,    45,    47,
      40,    43,    40,    44,    31,    -1,    42,    44,    40,    44,
      44,    44,    -1,   144
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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
      59,    60,    63,    40,    43,    63,    44,    46,    44,    46,
       4,    40,    43,     4,    39,    39,    55,    39,    44,    44,
      39,    39,    42,    56,    44,    62,     4,     5,    41,    52,
      63,    63,    32,    67,     4,    61,    62,    47,    47,    56,
      40,    40,    39,    45,    43,    40,    40,    44,    44,    42,
      55,    55,    63,    67,    61,    44,    44,    31,    40,    40,
      55,    44,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    52,
      53,    53,    54,    55,    56,    56,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     4,     1,     1,     9,     1,     0,
       3,     1,     2,     4,     2,     0,     0,     1,     2,     1,
       5,     7,     5,     7,     7,     5,     5,     1,     2,     2,
       4,     3,     3,     3,     6,     9,     6,     9,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     4,     1,     1,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       4
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
  case 2: /* S: blocofuncao globais  */
#line 104 "sintatica.y"
{
	T_debug.push_back(T_simbolo[bloco_qtd]);
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n" + traducao_declaracao() + yyvsp[0].traducao << endl;
}
#line 1442 "y.tab.c"
    break;

  case 3: /* globais: global globais  */
#line 110 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1450 "y.tab.c"
    break;

  case 4: /* globais: MAIN '(' ')' bloco  */
#line 114 "sintatica.y"
{
	yyval.traducao = "\n\nint main(void)\n{" + declaracoes + yyvsp[0].traducao + "\n\treturn 0;\n}\n";
}
#line 1458 "y.tab.c"
    break;

  case 5: /* global: declaracao  */
#line 119 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1466 "y.tab.c"
    break;

  case 6: /* global: atribuicao  */
#line 123 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1474 "y.tab.c"
    break;

  case 7: /* global: TIPO ID blocofuncao '(' parametros ')' '{' comandos '}'  */
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
#line 1493 "y.tab.c"
    break;

  case 8: /* parametros: p1  */
#line 144 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1501 "y.tab.c"
    break;

  case 9: /* parametros: %empty  */
#line 148 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1509 "y.tab.c"
    break;

  case 10: /* p1: parametro ',' parametros  */
#line 154 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao + ", " + yyvsp[-1].traducao;
}
#line 1517 "y.tab.c"
    break;

  case 11: /* p1: parametro  */
#line 158 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1525 "y.tab.c"
    break;

  case 12: /* parametro: TIPO ID  */
#line 164 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	adicionaTabela(yyvsp[0].label, yyvsp[-1].tipo, "N/A", var,"","variável");
	param.push_back(T_simbolo[bloco_qtd][yyvsp[0].label]);
	yyval.traducao = yyvsp[-1].tipo + " " + var;
}
#line 1536 "y.tab.c"
    break;

  case 13: /* bloco: blocofuncao '{' comandos '}'  */
#line 172 "sintatica.y"
{	
	declaracoes = declaracoes + traducao_declaracao();
	yyval.traducao = "\t\n" + yyvsp[-1].traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
}
#line 1548 "y.tab.c"
    break;

  case 14: /* comandos: comando comandos  */
#line 182 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1556 "y.tab.c"
    break;

  case 15: /* comandos: %empty  */
#line 186 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1564 "y.tab.c"
    break;

  case 16: /* blocofuncao: %empty  */
#line 192 "sintatica.y"
{
	bloco_qtd++;
	bloco_qtd_debug++;
	map<string, simbolo> a;
	T_simbolo.push_back(a);
	yyval.traducao = "";
}
#line 1576 "y.tab.c"
    break;

  case 17: /* comando: bloco  */
#line 202 "sintatica.y"
{	
	yyval.traducao = yyvsp[0].traducao + "\t\n";
}
#line 1584 "y.tab.c"
    break;

  case 18: /* comando: expressao ';'  */
#line 206 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1592 "y.tab.c"
    break;

  case 19: /* comando: atribuicao  */
#line 210 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1600 "y.tab.c"
    break;

  case 20: /* comando: IF '(' expressao ')' bloco  */
#line 214 "sintatica.y"
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	yyval.traducao = yyvsp[-2].traducao + "\t" + neg + " = !" + yyvsp[-2].label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t" + yyvsp[0].traducao + "\n\t" + lbl +":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	if(yyvsp[-2].valor=="true") adicionaTabela(neg, yyvsp[-2].tipo, "false", neg,"","variável");
	else adicionaTabela(neg, yyvsp[-2].tipo, "true", neg, "", "variável");
	
}
#line 1615 "y.tab.c"
    break;

  case 21: /* comando: IF '(' expressao ')' bloco ELSE bloco  */
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
#line 1631 "y.tab.c"
    break;

  case 22: /* comando: WHILE '(' expressao ')' bloco  */
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
#line 1647 "y.tab.c"
    break;

  case 23: /* comando: DO bloco WHILE '(' expressao ')' ';'  */
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
#line 1663 "y.tab.c"
    break;

  case 24: /* comando: FOR '(' fator ':' fator ')' bloco  */
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
#line 1690 "y.tab.c"
    break;

  case 25: /* comando: SCAN '(' entradas ')' ';'  */
#line 284 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1698 "y.tab.c"
    break;

  case 26: /* comando: PRINT '(' expressoes ')' ';'  */
#line 288 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1706 "y.tab.c"
    break;

  case 27: /* comando: declaracao  */
#line 292 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1714 "y.tab.c"
    break;

  case 28: /* comando: BREAK ';'  */
#line 296 "sintatica.y"
{
	yyval.traducao = "\tgoto label\n";
}
#line 1722 "y.tab.c"
    break;

  case 29: /* comando: CONTINUE ';'  */
#line 300 "sintatica.y"
{
	yyval.traducao = "\tgoto label\n";
}
#line 1730 "y.tab.c"
    break;

  case 30: /* atribuicao: ID ATRIBUI expressao ';'  */
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
#line 1809 "y.tab.c"
    break;

  case 31: /* atribuicao: ID UNARIOMAIS ';'  */
#line 381 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)
	yyval.traducao = "\t" + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " = " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " + 1;\n";
}
#line 1818 "y.tab.c"
    break;

  case 32: /* atribuicao: ID UNARIOMENOS ';'  */
#line 386 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)
	yyval.traducao = "\t" + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " = " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + " - 1;\n";
}
#line 1827 "y.tab.c"
    break;

  case 33: /* declaracao: TIPO ID ';'  */
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
#line 1845 "y.tab.c"
    break;

  case 34: /* declaracao: TIPO ID '[' ID ']' ';'  */
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
#line 1863 "y.tab.c"
    break;

  case 35: /* declaracao: TIPO ID '[' ID ']' '[' ID ']' ';'  */
#line 422 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-7].label);
	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			yyval.traducao = "\n\t"+ var + " = malloc(" + T_simbolo[bloco_qtd][yyvsp[-5].label].nome_temp + " * " + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " * sizeof(" + yyvsp[-8].tipo + "));\n\n";
			
			
			string tamanho = to_string(stoi(T_simbolo[bloco_qtd][yyvsp[-5].label].valor) * stoi(T_simbolo[bloco_qtd][yyvsp[-2].label].valor));

			adicionaTabela(yyvsp[-7].label, yyvsp[-8].tipo, "N/A", var, tamanho, "vetor");


	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1887 "y.tab.c"
    break;

  case 36: /* declaracao: TIPO ID '[' NUM ']' ';'  */
#line 442 "sintatica.y"
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
#line 1910 "y.tab.c"
    break;

  case 37: /* declaracao: TIPO ID '[' NUM ']' '[' NUM ']' ';'  */
#line 461 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-7].label);

	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			string var2 = geraVariavelTemporaria();
			string var3 = geraVariavelTemporaria();
			yyval.traducao = "\t" + var + " = " + yyvsp[-5].traducao +";\n\t" + var2 + " = " + yyvsp[-2].traducao +";\n\t"+ var3 + " = malloc(" + var + " * " + var2 +" * sizeof(" + yyvsp[-8].tipo + "));\n\n";
			
			adicionaTabela(var, "int", yyvsp[-5].traducao, var, "", "variável");
			adicionaTabela(var2, "int", yyvsp[-2].traducao, var2, "", "variável");

            string tamanho = to_string(stoi(yyvsp[-5].traducao) * stoi(yyvsp[-2].traducao));
			adicionaTabela(yyvsp[-7].label, yyvsp[-8].tipo, "N/A", var3, tamanho, "vetor");

	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1937 "y.tab.c"
    break;

  case 38: /* entradas: ID ',' entradas  */
#line 486 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)
	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + ";" + yyvsp[0].traducao;
}
#line 1946 "y.tab.c"
    break;

  case 39: /* entradas: ID  */
#line 491 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[0].label, bloc)
	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[0].label].nome_temp + ";\n";
}
#line 1955 "y.tab.c"
    break;

  case 40: /* expressoes: expressao ',' expressoes  */
#line 498 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao + "\n\tcout << " + yyvsp[-2].label + ";\n" + yyvsp[0].traducao;
}
#line 1963 "y.tab.c"
    break;

  case 41: /* expressoes: expressao  */
#line 502 "sintatica.y"
{
	yyval.traducao = "\n" + yyvsp[0].traducao + "cout << " + yyvsp[0].label + ";\n";
}
#line 1971 "y.tab.c"
    break;

  case 42: /* expressao: expressao E_LOGICO relacao  */
#line 509 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "&&", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 1983 "y.tab.c"
    break;

  case 43: /* expressao: expressao OU_LOGICO relacao  */
#line 517 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "||", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 1995 "y.tab.c"
    break;

  case 44: /* expressao: relacao  */
#line 525 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2006 "y.tab.c"
    break;

  case 45: /* relacao: aritmetica IGUAL aritmetica  */
#line 534 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "==", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2018 "y.tab.c"
    break;

  case 46: /* relacao: aritmetica DIFERENTE aritmetica  */
#line 542 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "!=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2030 "y.tab.c"
    break;

  case 47: /* relacao: aritmetica MAIOR aritmetica  */
#line 551 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2042 "y.tab.c"
    break;

  case 48: /* relacao: aritmetica MENOR aritmetica  */
#line 559 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2054 "y.tab.c"
    break;

  case 49: /* relacao: aritmetica MAIOR_IGUAL aritmetica  */
#line 567 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2066 "y.tab.c"
    break;

  case 50: /* relacao: aritmetica MENOR_IGUAL aritmetica  */
#line 575 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2078 "y.tab.c"
    break;

  case 51: /* relacao: NEGAR relacao  */
#line 583 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[0], "!", yyvsp[0], yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2090 "y.tab.c"
    break;

  case 52: /* relacao: converte  */
#line 591 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2101 "y.tab.c"
    break;

  case 53: /* converte: '(' TIPO ')' expressao  */
#line 601 "sintatica.y"
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
#line 2122 "y.tab.c"
    break;

  case 54: /* converte: aritmetica  */
#line 618 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2133 "y.tab.c"
    break;

  case 55: /* aritmetica: fator  */
#line 628 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2144 "y.tab.c"
    break;

  case 56: /* aritmetica: aritmetica SOMA aritmetica  */
#line 635 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "+", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2156 "y.tab.c"
    break;

  case 57: /* aritmetica: aritmetica SUBTRAI aritmetica  */
#line 643 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "-", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2168 "y.tab.c"
    break;

  case 58: /* aritmetica: aritmetica MULTIPLICA aritmetica  */
#line 651 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "*", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2180 "y.tab.c"
    break;

  case 59: /* aritmetica: aritmetica DIVIDE aritmetica  */
#line 659 "sintatica.y"
{
	if(stof(yyvsp[0].valor)==0) yyerror("Divisão por zero");
	
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "/", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2194 "y.tab.c"
    break;

  case 60: /* aritmetica: SOMA aritmetica  */
#line 669 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;

	adicionaTabela(yyval.label, yyvsp[0].tipo, "N/A", yyval.label,"","variável");
}
#line 2207 "y.tab.c"
    break;

  case 61: /* aritmetica: SUBTRAI aritmetica  */
#line 678 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + "-" + " " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = "-" + yyvsp[0].valor;

	adicionaTabela(yyval.label, yyval.tipo, "N/A", yyval.label,"","variável");
}
#line 2220 "y.tab.c"
    break;

  case 62: /* fator: NUM  */
#line 691 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "int";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo, yyvsp[0].traducao, yyval.label, "","variável");
}
#line 2232 "y.tab.c"
    break;

  case 63: /* fator: REAL  */
#line 699 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "float";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo, yyvsp[0].traducao, yyval.label, "","variável");
}
#line 2244 "y.tab.c"
    break;

  case 64: /* fator: CHAR  */
#line 707 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + "';\n";
	yyval.tipo = "char";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo ,yyval.valor, yyval.label,"","variável");
}
#line 2256 "y.tab.c"
    break;

  case 65: /* fator: STRING  */
#line 715 "sintatica.y"
{
	yyval.tipo = "string";
	yyval.valor = yyvsp[0].traducao;
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, yyval.tipo, yyval.valor, yyval.label,"","variável");
	yyval.traducao = "\tstrcpy(" + yyval.label + ", " + yyvsp[0].traducao + ");\n\t";	
	
}
#line 2269 "y.tab.c"
    break;

  case 66: /* fator: ID  */
#line 724 "sintatica.y"
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
#line 2285 "y.tab.c"
    break;

  case 67: /* fator: VERDADEIRO  */
#line 736 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "true";
	adicionaTabela(yyval.label, "bool", "true", yyval.label,"","variável");
}
#line 2297 "y.tab.c"
    break;

  case 68: /* fator: FALSO  */
#line 744 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "false";
	adicionaTabela(yyval.label, "bool", "false", yyval.label,"","variável");
}
#line 2309 "y.tab.c"
    break;

  case 69: /* fator: '(' expressao ')'  */
#line 752 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao;
	yyval.label = yyvsp[-1].label;
	yyval.tipo = yyvsp[-1].tipo;
	yyval.valor = yyvsp[-1].valor;
}
#line 2320 "y.tab.c"
    break;

  case 70: /* fator: ID '(' expressoes ')'  */
#line 759 "sintatica.y"
{

}
#line 2328 "y.tab.c"
    break;


#line 2332 "y.tab.c"

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

#line 763 "sintatica.y"


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
