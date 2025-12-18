
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
     mc_main = 258,
     mc_section_var = 259,
     mc_section_code = 260,
     mc_start = 261,
     mc_stop = 262,
     mc_int = 263,
     mc_flt = 264,
     mc_if = 265,
     mc_else = 266,
     mc_while = 267,
     mc_for = 268,
     mc_print = 269,
     mc_lbrace = 270,
     mc_rbrace = 271,
     mc_lparen = 272,
     mc_rparen = 273,
     mc_lbracket = 274,
     mc_rbracket = 275,
     mc_plus = 276,
     mc_mult = 277,
     mc_div = 278,
     mc_pow = 279,
     mc_assign_op = 280,
     mc_semicolon = 281,
     mc_comma = 282,
     mc_colon = 283,
     op_logic = 284,
     mc_identifier = 285,
     mc_real = 286,
     mc_number = 287,
     string_literal = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "syn.y"

    char* str;
    int ent;
    char* string_literal;



/* Line 1676 of yacc.c  */
#line 93 "syn.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


