/* ------ Analyseur lexicale pour : int x=3;  -------------*/
%{
    #include<stdio.h>
    // Partie : Déclarations en C
        int nb_ligne=1;
%}
/* -- Partie : Expressions régulières -- */
lettre [a-zA-Z]

chiffre [0-9]
IDF {lettre}({lettre}|{chiffre}|_)*
cst {chiffre}+
comment ^%%.*     

/* -- Partie : Règles de traduction -- */
%%
"Main" printf("MAIN \n");
"Section Variables" printf("SECTION Variables \n");
"Section Code" printf("SECTION Code \n");
"Start" printf("Start \n");
"int" printf("KEYWORD\n");
{comment} printf("comment \n");
";" printf("SEMI_COLON\n");
{IDF} printf ("IDENTIFIER\n");
{cst} printf("NUMBER\n");
"="   printf ("ASSIGN_OP\n");
"," printf("fasila\n");
":" printf(" SEMI_COLON\n");

[ \t] 
\n {nb_ligne++;}
. {printf("Erreur lexicale a la ligne %d \n",nb_ligne) ;}
%%
int main () 
{
    /* lancement de l'analyse lexicale */
    yylex () ;
    return 0;
}
