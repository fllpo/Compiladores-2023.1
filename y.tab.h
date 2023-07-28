/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
