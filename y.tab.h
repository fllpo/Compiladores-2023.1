/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
