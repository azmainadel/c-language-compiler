/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    CONST_INT = 258,
    CONST_FLOAT = 259,
    CONST_CHAR = 260,
    ID = 261,
    INCOP = 262,
    DECOP = 263,
    MULOP = 264,
    ADDOP = 265,
    RELOP = 266,
    LOGICOP = 267,
    ASSIGNOP = 268,
    LPAREN = 269,
    RPAREN = 270,
    RTHIRD = 271,
    LTHIRD = 272,
    LCURL = 273,
    RCURL = 274,
    COMMA = 275,
    SEMICOLON = 276,
    NOT = 277,
    IF = 278,
    ELSE = 279,
    FOR = 280,
    WHILE = 281,
    DO = 282,
    INT = 283,
    CHAR = 284,
    FLOAT = 285,
    DOUBLE = 286,
    VOID = 287,
    RETURN = 288,
    PRINTLN = 289,
    CONTINUE = 290,
    LOWER_THAN_ELSE = 291
  };
#endif
/* Tokens.  */
#define CONST_INT 258
#define CONST_FLOAT 259
#define CONST_CHAR 260
#define ID 261
#define INCOP 262
#define DECOP 263
#define MULOP 264
#define ADDOP 265
#define RELOP 266
#define LOGICOP 267
#define ASSIGNOP 268
#define LPAREN 269
#define RPAREN 270
#define RTHIRD 271
#define LTHIRD 272
#define LCURL 273
#define RCURL 274
#define COMMA 275
#define SEMICOLON 276
#define NOT 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define DO 282
#define INT 283
#define CHAR 284
#define FLOAT 285
#define DOUBLE 286
#define VOID 287
#define RETURN 288
#define PRINTLN 289
#define CONTINUE 290
#define LOWER_THAN_ELSE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
