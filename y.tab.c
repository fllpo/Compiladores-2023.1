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

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria(); // Gera um nome de variável temporária
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
void imprimeTabela(); // Imprime a tabela de símbolos

vector<map<string, simbolo>> T_simbolo; // Mapa, identificado pelo nome da variável
vector<map<string, simbolo>> T_debug;

int tmp_qnt = 0;
int num_linha = 1;
int bloco_qtd = -1;
int bloco_qtd_debug = -1;
int label_qnt=0;
string declaracoes = "";

#line 142 "y.tab.c"

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
    UNARIOMAIS = 276,              /* UNARIOMAIS  */
    UNARIOMENOS = 277,             /* UNARIOMENOS  */
    MAIOR = 278,                   /* MAIOR  */
    MENOR = 279,                   /* MENOR  */
    MAIOR_IGUAL = 280,             /* MAIOR_IGUAL  */
    MENOR_IGUAL = 281,             /* MENOR_IGUAL  */
    IGUAL = 282,                   /* IGUAL  */
    DIFERENTE = 283,               /* DIFERENTE  */
    E_LOGICO = 284,                /* E_LOGICO  */
    OU_LOGICO = 285,               /* OU_LOGICO  */
    VERDADEIRO = 286,              /* VERDADEIRO  */
    FALSO = 287,                   /* FALSO  */
    NEGAR = 288,                   /* NEGAR  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    WHILE = 291,                   /* WHILE  */
    DO = 292,                      /* DO  */
    FOR = 293,                     /* FOR  */
    CONTINUE = 294,                /* CONTINUE  */
    BREAK = 295,                   /* BREAK  */
    SCAN = 296,                    /* SCAN  */
    PRINT = 297                    /* PRINT  */
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
#define UNARIOMAIS 276
#define UNARIOMENOS 277
#define MAIOR 278
#define MENOR 279
#define MAIOR_IGUAL 280
#define MENOR_IGUAL 281
#define IGUAL 282
#define DIFERENTE 283
#define E_LOGICO 284
#define OU_LOGICO 285
#define VERDADEIRO 286
#define FALSO 287
#define NEGAR 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define DO 292
#define FOR 293
#define CONTINUE 294
#define BREAK 295
#define SCAN 296
#define PRINT 297

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
  YYSYMBOL_UNARIOMAIS = 21,                /* UNARIOMAIS  */
  YYSYMBOL_UNARIOMENOS = 22,               /* UNARIOMENOS  */
  YYSYMBOL_MAIOR = 23,                     /* MAIOR  */
  YYSYMBOL_MENOR = 24,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 25,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 26,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 27,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 28,                 /* DIFERENTE  */
  YYSYMBOL_E_LOGICO = 29,                  /* E_LOGICO  */
  YYSYMBOL_OU_LOGICO = 30,                 /* OU_LOGICO  */
  YYSYMBOL_VERDADEIRO = 31,                /* VERDADEIRO  */
  YYSYMBOL_FALSO = 32,                     /* FALSO  */
  YYSYMBOL_NEGAR = 33,                     /* NEGAR  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_FOR = 38,                       /* FOR  */
  YYSYMBOL_CONTINUE = 39,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 40,                     /* BREAK  */
  YYSYMBOL_SCAN = 41,                      /* SCAN  */
  YYSYMBOL_PRINT = 42,                     /* PRINT  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_S = 53,                         /* S  */
  YYSYMBOL_globais = 54,                   /* globais  */
  YYSYMBOL_global = 55,                    /* global  */
  YYSYMBOL_fn_main = 56,                   /* fn_main  */
  YYSYMBOL_bloco = 57,                     /* bloco  */
  YYSYMBOL_comandos = 58,                  /* comandos  */
  YYSYMBOL_blocofuncao = 59,               /* blocofuncao  */
  YYSYMBOL_comando = 60,                   /* comando  */
  YYSYMBOL_atribuicao = 61,                /* atribuicao  */
  YYSYMBOL_declaracao = 62,                /* declaracao  */
  YYSYMBOL_entradas = 63,                  /* entradas  */
  YYSYMBOL_expressoes = 64,                /* expressoes  */
  YYSYMBOL_expressao = 65,                 /* expressao  */
  YYSYMBOL_relacao = 66,                   /* relacao  */
  YYSYMBOL_converte = 67,                  /* converte  */
  YYSYMBOL_aritmetica = 68,                /* aritmetica  */
  YYSYMBOL_fator = 69                      /* fator  */
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
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      43,    44,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    93,    97,   101,   105,   109,   114,   119,
     129,   134,   140,   149,   153,   157,   161,   172,   184,   196,
     208,   231,   235,   239,   243,   247,   253,   328,   339,   352,
     367,   382,   401,   415,   430,   451,   465,   479,   495,   501,
     509,   513,   520,   528,   536,   545,   553,   562,   570,   578,
     586,   594,   602,   611,   620,   629,   640,   647,   655,   663,
     671,   681,   690,   703,   711,   719,   727,   736,   748,   756,
     764
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
  "MULTIPLICA", "DIVIDE", "UNARIOMAIS", "UNARIOMENOS", "MAIOR", "MENOR",
  "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "E_LOGICO",
  "OU_LOGICO", "VERDADEIRO", "FALSO", "NEGAR", "IF", "ELSE", "WHILE", "DO",
  "FOR", "CONTINUE", "BREAK", "SCAN", "PRINT", "'('", "')'", "'{'", "'}'",
  "';'", "':'", "'['", "']'", "','", "$accept", "S", "globais", "global",
  "fn_main", "bloco", "comandos", "blocofuncao", "comando", "atribuicao",
  "declaracao", "entradas", "expressoes", "expressao", "relacao",
  "converte", "aritmetica", "fator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -121,     4,   148,  -121,    52,     9,    46,    67,    71,    76,
    -121,   148,  -121,  -121,  -121,   133,   -14,    39,    13,     0,
      29,    53,    57,    85,  -121,  -121,  -121,  -121,  -121,  -121,
     150,   150,  -121,  -121,   133,   103,    25,  -121,  -121,   160,
    -121,  -121,  -121,    72,  -121,    78,  -121,   114,  -121,  -121,
    -121,   133,   108,   108,  -121,    89,    98,    35,   133,   133,
    -121,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,  -121,    93,    94,    95,    97,   133,   133,  -121,  -121,
    -121,   108,   108,   108,   108,   105,   105,   105,   105,   105,
     105,  -121,   104,   101,   106,   122,   123,   100,   100,     3,
    -121,  -121,  -121,  -121,    52,   167,   129,   130,  -121,   131,
     128,   142,   147,   149,  -121,   145,     3,  -121,  -121,    30,
     133,   133,   158,    20,  -121,  -121,   191,   133,  -121,  -121,
    -121,    37,    69,   153,   151,   146,   154,   156,     2,  -121,
    -121,   133,    20,   191,   155,   157,   133,   166,  -121,    73,
     159,  -121,  -121,  -121,  -121,  -121,   161,  -121,  -121,  -121,
    -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      12,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       2,     4,     7,     6,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,    67,    63,    64,    65,    66,
       0,     0,    68,    69,     0,     0,     0,    44,    52,    55,
      56,    27,    28,     0,    29,     0,    32,     0,    36,    35,
      37,     0,    61,    62,    51,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,    70,    42,
      43,    57,    58,    59,    60,    47,    48,    49,    50,    45,
      46,     8,     0,     0,     0,     0,     0,    53,    54,    11,
      30,    31,    33,    34,    67,     0,     0,     0,    12,     0,
       0,     0,     0,     0,    13,     0,    11,    15,    23,     0,
       0,     0,     0,     0,    25,    24,     0,     0,     9,    10,
      14,     0,     0,     0,     0,    39,     0,     0,    41,    12,
      12,     0,     0,     0,     0,     0,     0,    16,    18,     0,
       0,    38,    21,    22,    40,    12,     0,    12,    17,    19,
      20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,   194,  -121,  -121,   -70,    90,   207,  -121,   -97,
     -93,    66,    64,   -15,   -29,  -121,    27,  -120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    10,    11,    12,   114,   115,    92,   116,    13,
      14,   136,   137,    57,    37,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    91,   117,   134,     3,    54,   118,   104,    26,    27,
      28,    29,    18,    19,   105,     6,     7,     8,     9,   117,
      30,    31,   150,   118,    25,    26,    27,    28,    29,    79,
      80,    58,    59,    41,    32,    33,    34,   106,   122,   107,
     108,   109,   110,   111,   112,   113,    35,    44,   -12,    45,
      20,    32,    33,   146,    58,    59,    43,    52,    53,    58,
      59,    97,    98,    51,    58,    59,    58,    59,    15,   147,
     148,    21,    60,    16,    17,    22,    46,   130,    47,    78,
      23,   139,    72,    73,   119,   158,    42,   160,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    58,    59,
      48,   119,    58,    59,    49,   131,   132,    25,    26,    27,
      28,    29,   138,   140,    55,    56,    71,   156,    74,    75,
      30,    31,    61,    62,    63,    64,   149,    63,    64,    58,
      59,   138,    50,    76,    32,    33,    34,    25,    26,    27,
      28,    29,    77,    93,    94,    95,    35,    96,   100,    99,
      30,    31,     4,   101,    25,    26,    27,    28,    29,     5,
       6,     7,     8,     9,    32,    33,    34,    30,    31,   102,
     103,    19,   120,   121,   123,   124,    35,    61,    62,    63,
      64,    32,    33,    65,    66,    67,    68,    69,    70,   125,
     126,   128,   127,    51,   133,   135,   141,   143,   144,   142,
     145,   155,   152,   157,   153,    24,   129,     2,   159,   151,
     154
};

static const yytype_uint8 yycheck[] =
{
      15,    71,    99,   123,     0,    34,    99,     4,     5,     6,
       7,     8,     3,     4,    11,    12,    13,    14,    15,   116,
      17,    18,   142,   116,     4,     5,     6,     7,     8,    58,
      59,    29,    30,    47,    31,    32,    33,    34,   108,    36,
      37,    38,    39,    40,    41,    42,    43,    47,    45,    49,
       4,    31,    32,    51,    29,    30,    43,    30,    31,    29,
      30,    76,    77,    43,    29,    30,    29,    30,    16,   139,
     140,     4,    47,    21,    22,     4,    47,    47,    49,    44,
       4,    44,     4,     5,    99,   155,    47,   157,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    29,    30,
      47,   116,    29,    30,    47,   120,   121,     4,     5,     6,
       7,     8,   127,    44,    11,    12,    44,    44,     4,     5,
      17,    18,    17,    18,    19,    20,   141,    19,    20,    29,
      30,   146,    47,    44,    31,    32,    33,     4,     5,     6,
       7,     8,    44,    50,    50,    50,    43,    50,    47,    45,
      17,    18,     4,    47,     4,     5,     6,     7,     8,    11,
      12,    13,    14,    15,    31,    32,    33,    17,    18,    47,
      47,     4,    43,    43,    43,    47,    43,    17,    18,    19,
      20,    31,    32,    23,    24,    25,    26,    27,    28,    47,
      43,    46,    43,    43,    36,     4,    43,    51,    44,    48,
      44,    35,    47,    44,    47,    11,   116,     0,    47,   143,
     146
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    59,     0,     4,    11,    12,    13,    14,    15,
      54,    55,    56,    61,    62,    16,    21,    22,     3,     4,
       4,     4,     4,     4,    54,     4,     5,     6,     7,     8,
      17,    18,    31,    32,    33,    43,    65,    66,    67,    68,
      69,    47,    47,    43,    47,    49,    47,    49,    47,    47,
      47,    43,    68,    68,    66,    11,    12,    65,    29,    30,
      47,    17,    18,    19,    20,    23,    24,    25,    26,    27,
      28,    44,     4,     5,     4,     5,    44,    44,    44,    66,
      66,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    57,    59,    50,    50,    50,    50,    65,    65,    45,
      47,    47,    47,    47,     4,    11,    34,    36,    37,    38,
      39,    40,    41,    42,    57,    58,    60,    61,    62,    65,
      43,    43,    57,    43,    47,    47,    43,    43,    46,    58,
      47,    65,    65,    36,    69,     4,    63,    64,    65,    44,
      44,    43,    48,    51,    44,    44,    51,    57,    57,    65,
      69,    63,    47,    47,    64,    35,    44,    44,    57,    47,
      57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    56,    57,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     5,     4,
       2,     0,     0,     1,     2,     1,     5,     7,     5,     7,
       7,     5,     5,     1,     2,     2,     4,     3,     3,     3,
       6,     6,     3,     6,     6,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     4,     4,     1,     1,     3,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3
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
#line 88 "sintatica.y"
{
	T_debug.push_back(T_simbolo[bloco_qtd]);
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n" + traducao_declaracao() + yyvsp[0].traducao << endl;
}
#line 1437 "y.tab.c"
    break;

  case 3: /* globais: global globais  */
#line 94 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1445 "y.tab.c"
    break;

  case 4: /* globais: global  */
#line 98 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1453 "y.tab.c"
    break;

  case 5: /* global: declaracao  */
#line 102 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1461 "y.tab.c"
    break;

  case 6: /* global: atribuicao  */
#line 106 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1469 "y.tab.c"
    break;

  case 7: /* global: fn_main  */
#line 110 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1477 "y.tab.c"
    break;

  case 8: /* fn_main: TIPO_INT MAIN '(' ')' bloco  */
#line 115 "sintatica.y"
{
	yyval.traducao = "\n\nint main(void)\n{" + declaracoes + yyvsp[0].traducao + "\n\treturn 0;\n}\n";
}
#line 1485 "y.tab.c"
    break;

  case 9: /* bloco: blocofuncao '{' comandos '}'  */
#line 120 "sintatica.y"
{	
	declaracoes = declaracoes + traducao_declaracao();
	yyval.traducao = "\t\n" + yyvsp[-1].traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
}
#line 1497 "y.tab.c"
    break;

  case 10: /* comandos: comando comandos  */
#line 130 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
}
#line 1505 "y.tab.c"
    break;

  case 11: /* comandos: %empty  */
#line 134 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1513 "y.tab.c"
    break;

  case 12: /* blocofuncao: %empty  */
#line 140 "sintatica.y"
{
	bloco_qtd++;
	bloco_qtd_debug++;
	map<string, simbolo> a;
	T_simbolo.push_back(a);
	yyval.traducao = "";
}
#line 1525 "y.tab.c"
    break;

  case 13: /* comando: bloco  */
#line 150 "sintatica.y"
{	
	yyval.traducao = yyvsp[0].traducao + "\t\n";
}
#line 1533 "y.tab.c"
    break;

  case 14: /* comando: expressao ';'  */
#line 154 "sintatica.y"
{
	yyval.traducao = "";
}
#line 1541 "y.tab.c"
    break;

  case 15: /* comando: atribuicao  */
#line 158 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1549 "y.tab.c"
    break;

  case 16: /* comando: IF '(' expressao ')' bloco  */
#line 162 "sintatica.y"
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	yyval.traducao = yyvsp[-2].traducao + "\t" + neg + " = !" + yyvsp[-2].label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t" + yyvsp[0].traducao + "\n\t" + lbl +":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	if(yyvsp[-2].valor=="true") adicionaTabela(neg, yyvsp[-2].tipo, "false", neg,"","variável");
	else adicionaTabela(neg, yyvsp[-2].tipo, "true", neg, "", "variável");
	
}
#line 1564 "y.tab.c"
    break;

  case 17: /* comando: IF '(' expressao ')' bloco ELSE bloco  */
#line 173 "sintatica.y"
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
#line 1580 "y.tab.c"
    break;

  case 18: /* comando: WHILE '(' expressao ')' bloco  */
#line 185 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = "\t" + lbl +":\n\n"+ yyvsp[-2].traducao + "\t" + var + " = !" + yyvsp[-2].label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";"+ yyvsp[0].traducao + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	adicionaTabela(var, yyvsp[-2].tipo, yyvsp[-2].valor, var,"","variável");

}
#line 1596 "y.tab.c"
    break;

  case 19: /* comando: DO bloco WHILE '(' expressao ')' ';'  */
#line 197 "sintatica.y"
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	yyval.traducao = "\t" + lbl + ":" +yyvsp[-5].traducao + "\n" + yyvsp[-2].traducao + "\t" + var + " = !" + yyvsp[-2].label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	adicionaTabela(var, yyvsp[-2].tipo, yyvsp[-2].valor, var,"","variável");

}
#line 1612 "y.tab.c"
    break;

  case 20: /* comando: FOR '(' fator ':' fator ')' bloco  */
#line 209 "sintatica.y"
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
#line 1639 "y.tab.c"
    break;

  case 21: /* comando: SCAN '(' entradas ')' ';'  */
#line 232 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1647 "y.tab.c"
    break;

  case 22: /* comando: PRINT '(' expressoes ')' ';'  */
#line 236 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao;
}
#line 1655 "y.tab.c"
    break;

  case 23: /* comando: declaracao  */
#line 240 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
}
#line 1663 "y.tab.c"
    break;

  case 24: /* comando: BREAK ';'  */
#line 244 "sintatica.y"
{
	yyval.traducao = "\tgoto label\n";
}
#line 1671 "y.tab.c"
    break;

  case 25: /* comando: CONTINUE ';'  */
#line 248 "sintatica.y"
{
	yyval.traducao = "\tgoto label\n";
}
#line 1679 "y.tab.c"
    break;

  case 26: /* atribuicao: ID ATRIBUI expressao ';'  */
#line 254 "sintatica.y"
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
#line 1758 "y.tab.c"
    break;

  case 27: /* atribuicao: ID UNARIOMAIS ';'  */
#line 329 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-2].label);

	if ((teste))
	{
		yyval.traducao = "\t" + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " = " + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " + 1;\n";
	}
}
#line 1773 "y.tab.c"
    break;

  case 28: /* atribuicao: ID UNARIOMENOS ';'  */
#line 340 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-2].label);

	if ((teste))
	{
		yyval.traducao = "\t" + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " = " + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " - 1;\n";
	}
}
#line 1788 "y.tab.c"
    break;

  case 29: /* declaracao: TIPO_INT ID ';'  */
#line 353 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "int", "N/A", var,"","variável");
		
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1807 "y.tab.c"
    break;

  case 30: /* declaracao: TIPO_INT ID '[' ID ']' ';'  */
#line 368 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-4].label);
	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			yyval.traducao = "\n\t"+ var + " = malloc(" + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " * sizeof(int));\n\n";
			adicionaTabela(yyvsp[-4].label, "int", "N/A", var, T_simbolo[bloco_qtd][yyvsp[-2].label].valor, "vetor");
		
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1826 "y.tab.c"
    break;

  case 31: /* declaracao: TIPO_INT ID '[' NUM ']' ';'  */
#line 383 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-4].label);

	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			string var2 = geraVariavelTemporaria();
			yyval.traducao = "\t" + var + " = " + yyvsp[-2].traducao +";\n\t"+ var2 + " = malloc(" + var + " * sizeof(int));\n\n";
			
			adicionaTabela(var, "int", yyvsp[-2].traducao, var, "", "variável");
			adicionaTabela(yyvsp[-4].label, "int", "N/A", var2, yyvsp[-2].traducao, "vetor");

	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1849 "y.tab.c"
    break;

  case 32: /* declaracao: TIPO_FLOAT ID ';'  */
#line 402 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "float", "N/A", var,"","variável");
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1867 "y.tab.c"
    break;

  case 33: /* declaracao: TIPO_FLOAT ID '[' ID ']' ';'  */
#line 416 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-4].label);
	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			yyval.traducao = "\n\t"+ var + " = malloc(" + T_simbolo[bloco_qtd][yyvsp[-2].label].nome_temp + " * sizeof(float));\n\n";
			adicionaTabela(yyvsp[-4].label, "float", "N/A", var, T_simbolo[bloco_qtd][yyvsp[-2].label].valor, "vetor");
		
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1886 "y.tab.c"
    break;

  case 34: /* declaracao: TIPO_FLOAT ID '[' NUM ']' ';'  */
#line 431 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-4].label);

	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			string var2 = geraVariavelTemporaria();
			
			yyval.traducao = "\t" + var + " = " + yyvsp[-2].traducao +";\n\t"+ var2 + " = malloc(" + var + " * sizeof(float));\n\n";
			
			adicionaTabela(var, "int", yyvsp[-2].traducao, var, "", "variável");
			
			adicionaTabela(yyvsp[-4].label, "float", "N/A", var2, yyvsp[-2].traducao, "vetor");

	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1911 "y.tab.c"
    break;

  case 35: /* declaracao: TIPO_BOOL ID ';'  */
#line 452 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "bool", "N/A", var,"","variável");
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1929 "y.tab.c"
    break;

  case 36: /* declaracao: TIPO_CHAR ID ';'  */
#line 466 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "char", "N/A", var,"","variável");
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1947 "y.tab.c"
    break;

  case 37: /* declaracao: TIPO_STRING ID ';'  */
#line 480 "sintatica.y"
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(yyvsp[-1].label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		yyval.traducao = "";
		adicionaTabela(yyvsp[-1].label, "string", "N/A", var,"","variável");
	}else{
		yyerror("Variável já declarada!");
	}
}
#line 1965 "y.tab.c"
    break;

  case 38: /* entradas: ID ',' entradas  */
#line 496 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[-2].label, bloc)

	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[-2].label].nome_temp + ";" + yyvsp[0].traducao;
}
#line 1975 "y.tab.c"
    break;

  case 39: /* entradas: ID  */
#line 502 "sintatica.y"
{
	VERIFICACAO_ID(yyvsp[0].label, bloc)

	yyval.traducao = "\n\tcin >> " + T_simbolo[bloc][yyvsp[0].label].nome_temp + ";\n";
}
#line 1985 "y.tab.c"
    break;

  case 40: /* expressoes: expressao ',' expressoes  */
#line 510 "sintatica.y"
{
	yyval.traducao = yyvsp[-2].traducao + "\n\tcout << " + yyvsp[-2].label + ";\n" + yyvsp[0].traducao;
}
#line 1993 "y.tab.c"
    break;

  case 41: /* expressoes: expressao  */
#line 514 "sintatica.y"
{
	yyval.traducao = "\n" + yyvsp[0].traducao + "cout << " + yyvsp[0].label + ";\n";
}
#line 2001 "y.tab.c"
    break;

  case 42: /* expressao: expressao E_LOGICO relacao  */
#line 521 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "&&", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2013 "y.tab.c"
    break;

  case 43: /* expressao: expressao OU_LOGICO relacao  */
#line 529 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "||", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2025 "y.tab.c"
    break;

  case 44: /* expressao: relacao  */
#line 537 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2036 "y.tab.c"
    break;

  case 45: /* relacao: aritmetica IGUAL aritmetica  */
#line 546 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "==", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2048 "y.tab.c"
    break;

  case 46: /* relacao: aritmetica DIFERENTE aritmetica  */
#line 554 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "!=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2060 "y.tab.c"
    break;

  case 47: /* relacao: aritmetica MAIOR aritmetica  */
#line 563 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2072 "y.tab.c"
    break;

  case 48: /* relacao: aritmetica MENOR aritmetica  */
#line 571 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2084 "y.tab.c"
    break;

  case 49: /* relacao: aritmetica MAIOR_IGUAL aritmetica  */
#line 579 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, ">=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2096 "y.tab.c"
    break;

  case 50: /* relacao: aritmetica MENOR_IGUAL aritmetica  */
#line 587 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "<=", e3, yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2108 "y.tab.c"
    break;

  case 51: /* relacao: NEGAR relacao  */
#line 595 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	
	yyval.traducao = traducao_expressao(yyvsp[0], "!", yyvsp[0], yyval.label);
	yyval.tipo = "bool";
	yyval.valor = "";
}
#line 2120 "y.tab.c"
    break;

  case 52: /* relacao: converte  */
#line 603 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2131 "y.tab.c"
    break;

  case 53: /* converte: '(' TIPO_INT ')' expressao  */
#line 612 "sintatica.y"
{
	yyval.valor = to_string(stoi(yyvsp[0].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (int)" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, "int", yyval.valor, yyval.label,"","variável");
	yyval.tipo = "int";
}
#line 2144 "y.tab.c"
    break;

  case 54: /* converte: '(' TIPO_FLOAT ')' expressao  */
#line 621 "sintatica.y"
{
	yyval.valor = to_string(stof(yyvsp[0].valor));

	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (float)" + yyvsp[0].label + ";\n";
	adicionaTabela(yyval.label, "float", yyval.valor, yyval.label,"","variável");
	yyval.tipo = "float";
}
#line 2157 "y.tab.c"
    break;

  case 55: /* converte: aritmetica  */
#line 630 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2168 "y.tab.c"
    break;

  case 56: /* aritmetica: fator  */
#line 641 "sintatica.y"
{
	yyval.traducao = yyvsp[0].traducao;
	yyval.label = yyvsp[0].label;
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;
}
#line 2179 "y.tab.c"
    break;

  case 57: /* aritmetica: aritmetica SOMA aritmetica  */
#line 648 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "+", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2191 "y.tab.c"
    break;

  case 58: /* aritmetica: aritmetica SUBTRAI aritmetica  */
#line 656 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "-", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2203 "y.tab.c"
    break;

  case 59: /* aritmetica: aritmetica MULTIPLICA aritmetica  */
#line 664 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "*", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2215 "y.tab.c"
    break;

  case 60: /* aritmetica: aritmetica DIVIDE aritmetica  */
#line 672 "sintatica.y"
{
	if(stof(yyvsp[0].valor)==0) yyerror("Divisão por zero");
	
	yyval.label = geraVariavelTemporaria();
	COERCAO(yyvsp[-2], yyvsp[0], e1, e3);
	yyval.traducao = traducao_expressao(e1, "/", e3, yyval.label);
	yyval.tipo = e1.tipo;
	yyval.valor = "";
}
#line 2229 "y.tab.c"
    break;

  case 61: /* aritmetica: SOMA aritmetica  */
#line 682 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = yyvsp[0].valor;

	adicionaTabela(yyval.label, yyvsp[0].tipo, "N/A", yyval.label,"","variável");
}
#line 2242 "y.tab.c"
    break;

  case 62: /* aritmetica: SUBTRAI aritmetica  */
#line 691 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + "-" + " " + yyvsp[0].label + ";\n";
	yyval.tipo = yyvsp[0].tipo;
	yyval.valor = "-" + yyvsp[0].valor;

	adicionaTabela(yyval.label, yyval.tipo, "N/A", yyval.label,"","variável");
}
#line 2255 "y.tab.c"
    break;

  case 63: /* fator: NUM  */
#line 704 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "int";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo, yyvsp[0].traducao, yyval.label, "","variável");
}
#line 2267 "y.tab.c"
    break;

  case 64: /* fator: REAL  */
#line 712 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
	yyval.tipo = "float";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo, yyvsp[0].traducao, yyval.label, "","variável");
}
#line 2279 "y.tab.c"
    break;

  case 65: /* fator: CHAR  */
#line 720 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + "';\n";
	yyval.tipo = "char";
	yyval.valor = yyvsp[0].traducao;
	adicionaTabela(yyval.label, yyval.tipo ,yyval.valor, yyval.label,"","variável");
}
#line 2291 "y.tab.c"
    break;

  case 66: /* fator: STRING  */
#line 728 "sintatica.y"
{
	yyval.tipo = "string";
	yyval.valor = yyvsp[0].traducao;
	yyval.label = geraVariavelTemporaria();
	adicionaTabela(yyval.label, yyval.tipo, yyval.valor, yyval.label,"","variável");
	yyval.traducao = "\tstrcpy(" + yyval.label + ", " + yyvsp[0].traducao + ");\n\t";	
	
}
#line 2304 "y.tab.c"
    break;

  case 67: /* fator: ID  */
#line 737 "sintatica.y"
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
#line 2320 "y.tab.c"
    break;

  case 68: /* fator: VERDADEIRO  */
#line 749 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "true";
	adicionaTabela(yyval.label, "bool", "true", yyval.label,"","variável");
}
#line 2332 "y.tab.c"
    break;

  case 69: /* fator: FALSO  */
#line 757 "sintatica.y"
{
	yyval.label = geraVariavelTemporaria();
	yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
	yyval.tipo = "bool";
	yyval.valor = "false";
	adicionaTabela(yyval.label, "bool", "false", yyval.label,"","variável");
}
#line 2344 "y.tab.c"
    break;

  case 70: /* fator: '(' expressao ')'  */
#line 765 "sintatica.y"
{
	yyval.traducao = yyvsp[-1].traducao;
	yyval.label = yyvsp[-1].label;
	yyval.tipo = yyvsp[-1].tipo;
	yyval.valor = yyvsp[-1].valor;
}
#line 2355 "y.tab.c"
    break;


#line 2359 "y.tab.c"

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

#line 772 "sintatica.y"


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
