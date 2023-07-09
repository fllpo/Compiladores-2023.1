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
    ELSE = 288,                    /* ELSE  */
    WHILE = 289,                   /* WHILE  */
    DO = 290,                      /* DO  */
    FOR = 291,                     /* FOR  */
    CONTINUE = 292,                /* CONTINUE  */
    BREAK = 293                    /* BREAK  */
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
#define ELSE 288
#define WHILE 289
#define DO 290
#define FOR 291
#define CONTINUE 292
#define BREAK 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
