flex mylang.l
bison -dy mylang.y
gcc SymbolTable.c lex.yy.c y.tab.c -o myLang.exe
myLang.exe < input.txt
pause