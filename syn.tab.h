
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     string_literal = 258,
     mc_main = 259,
     mc_int = 260,
     mc_flt = 261,
     cst = 262,
     mc_real = 263,
     err = 264,
     mc_section_var = 265,
     mc_section_code = 266,
     mc_start = 267,
     mc_print = 268,
     mc_number = 269,
     mc_identifier = 270,
     mc_assign_op = 271,
     mc_semicolon = 272,
     mc_comma = 273,
     mc_colon = 274,
     mc_lbrace = 275,
     mc_rbrace = 276,
     mc_lparen = 277,
     mc_rparen = 278,
     mc_mult = 279,
     mc_plus = 280,
     mc_div = 281,
     mc_stop = 282,
     mc_if = 283,
     mc_else = 284,
     op_logic = 285,
     mc_while = 286,
     mc_for = 287,
     mc_pow = 288,
     mc_lbracket = 289,
     mc_rbracket = 290,
     OR = 291,
     AND = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "syn.y"

    char* string_literal;
    double mc_number;



/* Line 1676 of yacc.c  */
#line 96 "syn.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


