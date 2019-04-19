#include <stdio.h>
#include"defs.h"
extern int yylex(); // gets token id
extern int yylineno; // has token line number
extern char* yytext; // has token value
int main(void)
{
		int token;
	token = yylex();
	while (token) {
		printf("%d %d\n", token, yylineno);
		token = yylex();
	}
	return 0;
}