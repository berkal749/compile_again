%{
#include <stdio.h>
#include <stdlib.h>

extern int nb_ligne;
extern int col;

int yyerror(char *msg) {
    printf("Erreur syntaxique à la ligne %d, colonne %d: %s\n", nb_ligne, col-1, msg);
    return 1;
}
%}

%start S
%union {
    char* string_literal;
    double mc_number;
}


%token <string_literal> string_literal
%token mc_main mc_int mc_flt  cst mc_real err mc_section_var mc_section_code mc_start mc_print
%token mc_number mc_identifier mc_assign_op mc_semicolon mc_comma mc_colon
%token mc_lbrace mc_rbrace mc_lparen mc_rparen mc_mult mc_plus mc_div mc_stop mc_if mc_else op_logic mc_while mc_for  mc_pow  mc_lbracket mc_rbracket


%left OR
%left AND
%right mc_pow
%left mc_plus
%left mc_mult mc_div
%%

S: mc_main mc_identifier mc_semicolon SV SC  {
        printf("------------  Syntaxe correcte -------------------\n");
        YYACCEPT;
    }
;

SV: mc_section_var DECLARATION_LIST;

SC: mc_section_code mc_start mc_lbrace CODE mc_rbrace mc_stop;

DECLARATION_LIST:
      
    | DECLARATION_LIST DEC
;

DEC: VAR_LIST mc_colon TYPE mc_semicolon | "T" mc_lbracket mc_identifier mc_rbracket  mc_colon TYPE mc_semicolon;

VAR_LIST:
      mc_identifier
    | VAR_LIST mc_comma mc_identifier
;

TYPE:
      mc_int
    | mc_flt
;

CODE:
      
    | CODE INSTRUCTION
;

INSTRUCTION:
      ASSIGNMENT
    | PRINT_STMT | IF_STMT | WHILE_STMT | FOR_STMT 
;
IF_STMT: mc_if mc_rparen string_literal mc_rparen mc_lbrace CODE mc_rbrace | mc_if mc_rparen string_literal mc_rparen mc_lbrace CODE mc_rbrace mc_else mc_lbrace CODE mc_rbrace;

ASSIGNMENT: mc_identifier mc_assign_op EXPR mc_semicolon;

PRINT_STMT: mc_print mc_lparen string_literal mc_rparen mc_semicolon;
WHILE_STMT: mc_while mc_rparen condition mc_rparen mc_lbrace CODE mc_rbrace;
FOR_STMT: mc_for mc_rparen ASSIGNMENT condition mc_semicolon ASSIGNMENT mc_rparen mc_lbrace CODE mc_rbrace;
condition:  expr | expr op_logic expr | condition "AND" condition | condition "OR" condition ;
expr: expr mc_plus expr | expr mc_mult expr | expr mc_div expr | expr mc_pow expr | mc_identifier | cst | mc_real  | mc_lparen expr mc_rparen ;


EXPR:
      mc_number | mc_real
    | mc_identifier
    | mc_lparen EXPR mc_rparen
    | EXPR mc_plus EXPR
    | EXPR mc_mult EXPR
    | EXPR mc_div EXPR
;


%%

int main() {
    yyparse();
    return 0;
}
