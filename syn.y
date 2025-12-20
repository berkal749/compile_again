%{
#include <stdio.h>
#include <stdlib.h>
#include "TS.h"

extern int nb_ligne;
int yyerror(char *msg);
%}

%start S

%union {
    char* str;
    int ent;
    char* string_literal;
}

%token mc_main mc_section_var mc_section_code mc_start mc_stop
%token mc_int mc_flt mc_if mc_else mc_while mc_for mc_print
%token mc_lbrace mc_rbrace mc_lparen mc_rparen mc_lbracket mc_rbracket
%token mc_plus mc_mult mc_div mc_pow mc_assign_op mc_semicolon mc_comma mc_colon
%token op_logic

%token <str> mc_identifier mc_real
%token <ent> mc_number
%token <string_literal> string_literal

%%
S: mc_main mc_identifier mc_semicolon SV SC {
    printf("=== Syntaxe correcte ===\n");
    YYACCEPT;
};

SV: mc_section_var DECLARATION_LIST;

DECLARATION_LIST:
      
    | DECLARATION_LIST DEC
;

DEC:
      VAR_LIST mc_colon TYPE mc_semicolon
    | mc_identifier mc_lbracket mc_number mc_rbracket mc_colon TYPE mc_semicolon {
        if (recherche($1))
            printf("Erreur semantique: tableau %s deja declare ligne %d\n", $1, nb_ligne);
        else
            inserer($1, "TAB", "", "", 1);
    }
;

VAR_LIST:
      mc_identifier {
        if (recherche($1))
            printf("Erreur semantique: %s deja declare ligne %d\n",$1,nb_ligne);
        else
            inserer($1,"IDF","", "",1);
      }
    | VAR_LIST mc_comma mc_identifier {
        if (recherche($3))
            printf("Erreur semantique: %s deja declare ligne %d\n",$3,nb_ligne);
        else
            inserer($3,"IDF","", "",1);
      }
;

TYPE:
      mc_int  { affecterType("INTEGER"); }
    | mc_flt  { affecterType("FLOAT"); }
;

SC: mc_section_code mc_start mc_lbrace CODE mc_rbrace mc_stop;

CODE:
      /* empty */
    | CODE INSTRUCTION
;

INSTRUCTION:
      ASSIGNMENT
    | PRINT_STMT
;

ASSIGNMENT:
    mc_identifier mc_assign_op EXPR mc_semicolon {
        if (!recherche($1))
            printf("Erreur semantique: %s non declare ligne %d\n",$1,nb_ligne);
    }
    | mc_identifier mc_assign_op EXPR mc_div mc_number mc_semicolon {
        if (!recherche($1))
            printf("Erreur semantique: %s non declare ligne %d\n",$1,nb_ligne);
        if ($5 == 0)
            printf("Erreur semantique: division par zero ligne %d\n", nb_ligne);
    }
;

PRINT_STMT:
    mc_print mc_lparen string_literal mc_rparen mc_semicolon
;

EXPR:
      mc_number
    | mc_real
    | mc_identifier
    | EXPR mc_plus EXPR
    | EXPR mc_mult EXPR
    | EXPR mc_div EXPR
    | mc_lparen EXPR mc_rparen
;

%%
int yyerror(char *msg) {
    printf("Erreur syntaxique ligne %d\n", nb_ligne);
    return 1;
}

int main() {
    initialization();
    yyparse();
    afficher();
    return 0;
}