/* ------ Analyseur lexicale pour : int x=3;  -------------*/
%{
    #include<stdio.h>
    #include "syn.tab.h"
    #include "TS.h"
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
"Main" {    rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("%s reconnu\n",yytext);return mc_main;}
"Section Variables" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("SECTION Variables \n"); return mc_section_var;}
"Section Code" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("SECTION Code \n"); return mc_section_code;}
"Start" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("Start \n"); return mc_start;}
"print" {  rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; return mc_print; }
"if" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("if \n"); return mc_if;}
"else" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("else \n"); return mc_else;}
"while" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("while \n"); return mc_while;}
"for" {rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("for \n"); return mc_for;}
"Stop" { rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf("Stop \n");  return mc_stop; }

{OPLOGIC} {    rechercher(yytext, "OpLogic", "", "", 3); col+=yyleng; printf("nbr_real\n"); return op_logic; }
 


"Integer" {col+=yyleng; printf("KEYWORD\n"); return mc_int;}
"Float" {col+=yyleng; printf("KEYWORD\n"); return mc_flt;}
{real} {col+=yyleng; printf("nbr_real\n"); return mc_real;}
{comment} { /* Ignorer les commentaires */ }


";" {col+=yyleng; printf ("SEMICOLON\n"); return mc_semicolon;}
{IDF} { rechercher(yytext, "Motcle", "", "", 2); col+=yyleng; printf ("IDENTIFIER\n"); return mc_identifier;}
{cst} { rechercher(yytext, "Nombre", "", "", 1); col+=yyleng; printf("NUMBER\n"); return mc_number;}
":="   {rechercher(yytext, "AssignOp", "", "", 3); col+=yyleng; printf ("ASSIGN_OP\n"); return mc_assign_op;}
"," { rechercher(yytext, "Virgule", "", "", 3); col+=yyleng; printf("COMMA\n"); return mc_comma;}
":" { rechercher(yytext, "DeuxPoints", "", "", 3); col+=yyleng; printf("COLON\n"); return mc_colon;}
"{" {rechercher(yytext, "AccoladeOuvrante", "", "", 3); col+=yyleng; printf("{ \n"); return mc_lbrace;}
"}" {rechercher(yytext, "AccoladeFermante", "", "", 3); col+=yyleng; printf("} \n"); return mc_rbrace;}
"(" {rechercher(yytext, "ParentheseOuvrante", "", "", 3); col+=yyleng; printf("( \n"); return mc_lparen;}
"[" {rechercher(yytext, "CrochetOuvrant", "", "", 3); col+=yyleng; printf("[ \n"); return mc_lbracket;}
"]" {rechercher(yytext, "CrochetFermant", "", "", 3); col+=yyleng; printf("] \n"); return mc_rbracket;}
")" {rechercher(yytext, "ParentheseFermante", "", "", 3); col+=yyleng; printf(") \n"); return mc_rparen;}
"*" {rechercher(yytext, "Mult", "", "", 3); col+=yyleng; printf("* \n"); return mc_mult;}
"+" {rechercher(yytext, "Plus", "", "", 3); col+=yyleng; printf("+ \n"); return mc_plus;}
"/" {rechercher(yytext, "Div", "", "", 3); col+=yyleng; printf("/ \n"); return mc_div;}
"^" {rechercher(yytext, "Pow", "", "", 3); col+=yyleng; printf("^ \n"); return mc_pow;}
{string} { yylval.string_literal = strdup(yytext); return string_literal; }
[ \t]+    { col += yyleng; /* skip spaces */ }
\n        { nb_ligne++; col=1; }

. {printf("Erreur lexicale a la ligne %d \n",nb_ligne) ;}
%%
