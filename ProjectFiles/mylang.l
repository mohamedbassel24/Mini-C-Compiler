%{   
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include<string.h>
	void yyerror (char *s);
	int yylineno;
	int yylex();
%}

%%	
\{                      						return OCBRACKET;   
\}                      						return CCBRACKET;
\(												return ORBRACKET;
\)												return CRBRACKET;
;                       						return SEMICOLON;
:                       						return COLON; 
,                       						return COMMA;
"++"			                        		return INC;
"--"	                         				return DEC;
"+="											return PLUSEQUAL;
"-="											return MINUSEQUAL;
"*="											return MULTIPLYEQUAL;
"/="											return DIVIDEEQUAL;
">"         	 								return GREATERTHAN;
"<"         	 								return LESSTHAN;
">="         	 								return GREATERTHANOREQUAL;
"<="             								return LESSTHANOREQUAL;
"=="             								return EQUALEQUAL;
"!="             								return NOTEQUAL;
"+"												return PLUS;
"-"												return MINUS;
"*"												return MULTIPLY;
"/"												return DIVIDE;
"="												return ASSIGN;
"%"												return REM;
"&&"											return AND;
"||"											return OR;
"!"												return NOT;
"while"          								return WHILE;
"for"          									return FOR;
"if"             								return IF;
"else"           								return ELSE;
"print"        									return PRINT;
"bool"				    						return BOOL;
"int"											return INT;
"float"											return FLOAT;
"char"											return CHAR;
"string"										return STRING;
"const"                 						return CONST;
"do"											return DO;
"break"                 						return BREAK;
"switch"                						return SWITCH;
"case"                  						return CASE;
"false"											return FALSE;
"true"											return TRUE;
"return"                						return RETURN;
"exit"											return EXIT;			
"default"										return DEFAULT;


[0-9]+											{yylval.IntgerValue = atoi(yytext); return INTEGER;}
[0-9]+\.[0-9]+									{yylval.FloatValue = atof(yytext); return FLOATNUMBER;}
\".*\"											{yylval.StringValue=strdup(yytext);return TEXT;} // for copying the i/p token
\'.?\'											{yylval.ChValue=strdup(yytext);return CHARACTER;}
[a-zA-Z][_a-zA-Z0-9]*							{yylval.ID=strdup(yytext);return IDENTIFIER;} 
[\t  ]+											/* ignore whitespace */;
[\n]											{yylineno = yylineno+1;}
.                                               {yyerror("UnExpectedToken");}
%% 

int yywrap (void) {
	return 1;
}