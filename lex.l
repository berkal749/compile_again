%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "syn.tab.h"
    #include "TS.h"

    int nb_ligne = 1;
    int col = 1;
%}

lettre   [a-zA-Z]
chiffre  [0-9]
IDF      {lettre}({lettre}|{chiffre}|_)*
cst      {chiffre}+
real     [+-]?{chiffre}+\.{chiffre}+
string   \"([^\"\\]|\\.)*\"
OPLOGIC  (<=|>=|==|!=|>|<)

%%
"Main"                { rechercher(yytext,"MotCle","MAIN","",2); return mc_main; }
"Section Variables"   { rechercher(yytext,"MotCle","SV","",2); return mc_section_var; }
"Section Code"        { rechercher(yytext,"MotCle","SC","",2); return mc_section_code; }
"Start"               { rechercher(yytext,"MotCle","START","",2); return mc_start; }
"Stop"                { rechercher(yytext,"MotCle","STOP","",2); return mc_stop; }

"Integer"             { rechercher(yytext,"MotCle","INT","",2); return mc_int; }
"Float"               { rechercher(yytext,"MotCle","FLOAT","",2); return mc_flt; }

"if"                  { rechercher(yytext,"MotCle","IF","",2); return mc_if; }
"else"                { rechercher(yytext,"MotCle","ELSE","",2); return mc_else; }
"EndIf"               { rechercher(yytext,"MotCle","ENDIF","",2); return mc_endif; }
"while"               { rechercher(yytext,"MotCle","WHILE","",2); return mc_while; }
"Do"                  { rechercher(yytext,"MotCle","DO","",2); return mc_do; }
"for"                 { rechercher(yytext,"MotCle","FOR","",2); return mc_for; }
"from"                { rechercher(yytext,"MotCle","FROM","",2); return mc_from; }
"to"                  { rechercher(yytext,"MotCle","TO","",2); return mc_to; }
"step"                { rechercher(yytext,"MotCle","STEP","",2); return mc_step; }
"print"               { rechercher(yytext,"MotCle","PRINT","",2); return mc_print; }

"AND"                 { rechercher(yytext,"OP","AND","",3); return mc_and; }
"OR"                  { rechercher(yytext,"OP","OR","",3); return mc_or; }
"!"                   { rechercher(yytext,"OP","NOT","",3); return mc_not; }

{real} {
    rechercher(yytext,"CST","FLOAT",yytext,1);
    yylval.str = strdup(yytext);
    return mc_real;
}

{cst} {
    rechercher(yytext,"CST","INTEGER",yytext,1);    
    yylval.ent = atoi(yytext);
    return mc_number;
}

{IDF} {
    yylval.str = strdup(yytext);
    return mc_identifier;
}

{string} {
    yylval.string_literal = strdup(yytext);
    return string_literal;
}

"%%"[ \t]*.*  {  }

{OPLOGIC}   { rechercher(yytext,"OP","LOGIC","",3); return op_logic; }

":="    { rechercher(":=","OP","ASSIGN","",3); return mc_assign_op; }
";"     { rechercher(";","SEP","SC","",3); return mc_semicolon; }
","     { rechercher(",","SEP","COMMA","",3); return mc_comma; }
":"     { rechercher(":","SEP","COLON","",3); return mc_colon; }

"("     { return mc_lparen; }
")"     { return mc_rparen; }
"{"     { return mc_lbrace; }
"}"     { return mc_rbrace; }
"["     { return mc_lbracket; }
"]"     { return mc_rbracket; }

"+"     { return mc_plus; }
"-"     { return mc_minus; }
"*"     { return mc_mult; }
"/"     { return mc_div; }
"^"     { return mc_pow; }

[ \t]+  { col += yyleng; }
\n      { nb_ligne++; col = 1; }

. { printf("Erreur lexicale ligne %d\n", nb_ligne); }
%%