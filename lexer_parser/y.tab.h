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
    COL = 258,
    O_R = 259,
    C_R = 260,
    O_S = 261,
    C_S = 262,
    MOD = 263,
    STRING_CONST = 264,
    SEMI = 265,
    MAIN = 266,
    ARROW = 267,
    INT = 268,
    REAL = 269,
    STRING = 270,
    BOOL = 271,
    TRUE = 272,
    FALSE = 273,
    INT_NUM = 274,
    REAL_NUM = 275,
    AND = 276,
    OR = 277,
    ADD = 278,
    SUB = 279,
    DIV = 280,
    MUL = 281,
    LE = 282,
    GE = 283,
    EQ = 284,
    NE = 285,
    GT = 286,
    LT = 287,
    PRINT = 288,
    FOR = 289,
    IF = 290,
    ELSE = 291,
    FUNC = 292,
    ID = 293
  };
#endif
/* Tokens.  */
#define COL 258
#define O_R 259
#define C_R 260
#define O_S 261
#define C_S 262
#define MOD 263
#define STRING_CONST 264
#define SEMI 265
#define MAIN 266
#define ARROW 267
#define INT 268
#define REAL 269
#define STRING 270
#define BOOL 271
#define TRUE 272
#define FALSE 273
#define INT_NUM 274
#define REAL_NUM 275
#define AND 276
#define OR 277
#define ADD 278
#define SUB 279
#define DIV 280
#define MUL 281
#define LE 282
#define GE 283
#define EQ 284
#define NE 285
#define GT 286
#define LT 287
#define PRINT 288
#define FOR 289
#define IF 290
#define ELSE 291
#define FUNC 292
#define ID 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

	struct {
		char *name;
		int id;
		char *type;
		void* nd;
	} c_token;

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
