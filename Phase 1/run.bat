flex lex.l
bison -dy lex.y
gcc lex.yy.c y.tab.c -o lex.exe
lex.exe < input.txt