/* ------ Analyseur lexicale pour : int x=3;  -------------*/
%{
    #include<stdio.h>
    #include "syn.tab.h"
    // Partie : Déclarations en C
       int nb_ligne = 1;
int col = 1;
%}
/* -- Partie : Expressions régulières -- */
lettre [a-zA-Z]
real [+-]?[0-9]+\.[0-9]+
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre}|_)*
cst {chiffre}+
string \"([^\"\\]|\\.)*\"
PRINT print[ \t]*\([ \t]*{string}[ \t]*\)[ \t]*;
comment ^%%.*    
OPLOGIC (<=|>=|==|!=|>|<) 

/* -- Partie : Règles de traduction -- */
%%
"Main" {col+=yyleng; printf("%s reconnu\n",yytext);return mc_main;}
"Section Variables" {col+=yyleng; printf("SECTION Variables \n"); return mc_section_var;}
"Section Code" {col+=yyleng; printf("SECTION Code \n"); return mc_section_code;}
"Start" {col+=yyleng; printf("Start \n"); return mc_start;}
"print" { col+=yyleng; return mc_print; }
"if" {col+=yyleng; printf("if \n"); return mc_if;}
"else" {col+=yyleng; printf("else \n"); return mc_else;}
"while" {col+=yyleng; printf("while \n"); return mc_while;}
"for" {col+=yyleng; printf("for \n"); return mc_for;}
"Stop" { col+=yyleng; printf("Stop \n");  return mc_stop; }

{OPLOGIC} { col+=yyleng; printf("nbr_real\n"); return op_logic }
 


"Integer" {col+=yyleng; printf("KEYWORD\n"); return mc_int;}
"Float" {col+=yyleng; printf("KEYWORD\n"); return mc_flt;}
{real} {col+=yyleng; printf("nbr_real\n"); return mc_real;}
{comment} { /* Ignorer les commentaires */ }


";" {col+=yyleng; printf ("SEMICOLON\n"); return mc_semicolon;}
{IDF} {col+=yyleng; printf ("IDENTIFIER\n"); return mc_identifier;}
{cst} {col+=yyleng; printf("NUMBER\n"); return mc_number;}
":="   {col+=yyleng; printf ("ASSIGN_OP\n"); return mc_assign_op;}
"," {col+=yyleng; printf("COMMA\n"); return mc_comma;}
":" {col+=yyleng; printf("COLON\n"); return mc_colon;}
"{" {col+=yyleng; printf("{ \n"); return mc_lbrace;}
"}" {col+=yyleng; printf("} \n"); return mc_rbrace;}
"(" {col+=yyleng; printf("( \n"); return mc_lparen;}
")" {col+=yyleng; printf(") \n"); return mc_rparen;}
"*" {col+=yyleng; printf("* \n"); return mc_mult;}
"+" {col+=yyleng; printf("+ \n"); return mc_plus;}
"/" {col+=yyleng; printf("/ \n"); return mc_div;}
"^" {col+=yyleng; printf("^ \n"); return mc_pow;}
{string} { yylval.string_literal = strdup(yytext); return string_literal; }
[ \t]+    { col += yyleng; /* skip spaces */ }
\n        { nb_ligne++; col=1; }

. {printf("Erreur lexicale a la ligne %d \n",nb_ligne) ;}
%%
