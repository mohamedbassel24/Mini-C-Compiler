flex mylang.l
bison -dy mylang.y
gcc lex.yy.c y.tab.c -o myLang.exe
myLang.exe < input.txt