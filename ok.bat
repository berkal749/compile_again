flex lex.l
bison -d syn.y
gcc lex.yy.c syn.tab.c TS.c -o result -lfl
.\result < test.txt
