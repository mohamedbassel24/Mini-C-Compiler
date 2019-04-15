%start program
// Tokens for brackets
	%token OCBRACKET
	%token CCBRACKET
	%token ORBRACKET
	%token CRBRACKET

// Tokens for colons
	%token SEMICOLON
	%token COLON
	%token COMMA

// Tokens for x equal
	%token PLUSEQUAL
	%token MINUSEQUAL
	%token MULTIPLYEQUAL
	%token DIVIDEEQUAL

// Tokens for x equal
	%token GREATERTHAN
	%token LESSTHAN
	%token GREATERTHANOREQUAL
	%token LESSTHANOREQUAL
	%token EQUALEQUAL
	%token NOTEQUAL

// Tokens for x equal
	%token PLUS
	%token MINUS
	%token MULTIPLY
	%token DIVIDE

// Tokens for assign
	%token ASSIGN

// Tokens for remainder
	%token REM

// Tokens for logic operators
	%token AND
	%token OR
	%token NOT

// Tokens for loops
	%token WHILE
	%token DO
	%token FOR

// Tokens for conditions
	%token IF
	%token ELSE

// Tokens for print
	%token PRINT

// Tokens for primitive data types
	%token BOOL
	%token INT
	%token FLOAT
	%token CHAR
	%token STRING
	%token CONST

// Tokens for break
	%token BREAK

// Tokens for switch case
	%token SWITCH
	%token CASE

// Tokens for booleans
	%token FALSE
	%token TRUE

// Tokens for function return
	%token RET

// Associativity
	%left ASSIGN
	%left GREATERTHAN LESSTHAN
	%left GREATERTHANOREQUAL LESSTHANOREQUAL
	%left EQUALEQUAL NOTEQUAL
	%left AND OR NOT
	%left PLUS MINUS 
	%left DIVIDE MULTIPLY REM

%nonassoc IFX
%nonassoc ELSE
%nonassoc UMINUS

%{  
	#include <stdio.h>   
	int yyerror(char *);
	int yylex(void);
	int yylineno;
	FILE * f1;
	FILE * yyin;
%}


%%
program	: 
		function
		;
	
function :      function stmt  
		|
		;
		
stmt:   type IDENTIFIER SEMICOLON	%prec IFX                 				{printf("Declaration\n");}

		| IDENTIFIER ASSIGN expression SEMICOLON	          				{printf("Assignment\n");}

		| type IDENTIFIER ASSIGN expression	SEMICOLON	      				{printf("Declaration and Assignment\n");}

		| CONST type IDENTIFIER ASSIGN expression SEMICOLON   				{printf("Constant assignment\n");}

		| increments SEMICOLON                             					{printf("Increments\n");}
		
		| WHILE ORBRACKET expression ERBRACKET stmt							{printf("While loop\n");}

		| DO braceScope WHILE ORBRACKET expression ERBRACKET SEMICOLON		{printf("Do while\n");}

		| FOR ORBRACKET INT IDENTIFIER ASSIGN INTEGERNUMBER SEMICOLON 
		  expression SEMICOLON
		  forExpression ERBRACKET
		  braceScope											  			{printf("For loop\n");}

		
		| IF ORBRACKET expression ERBRACKET braceScope %prec IFX 			{printf("If statement\n");}

		| IF ORBRACKET expression ERBRACKET braceScope	 ELSE braceScope	{printf("If-Elsestatement\n");}

		| SWITCH ORBRACKET IDENTIFIER ERBRACKET switchScope      			{printf("Switch case\n");}

		
		| PRINT expression 	SEMICOLON	                        			{printf("Print\n");}
		
		| func	                                            	

		| braceScope														{printf("New braces scope\n");}
		
		;

func : type IDENTIFIER ORBRACKET arglist ERBRACKET OBRACE stmtlist RET  expression  SEMICOLON   EBRACE      {printf("function\n");}
	   ;
	   
arglist:  type IDENTIFIER cont
          |
	;

cont:  COMMA type IDENTIFIER cont 
	| 
	;	   
	   
		
braceScope:	 OBRACE stmtlist EBRACE								{printf("Stmt brace\n");}
			 | OBRACE EBRACE	
		;

switchScope:  OBRACE caseExpression EBRACE					    {printf("Case brace\n");}		
		;
		
stmtlist:  stmt 
          | stmtlist stmt ;

type:   INT
	| FLOAT
	| DOUBLE
	| LONG
	| CHAR
	| STRING
	| BOOL
	;

no_declaration:   FLOATNUMBER                  { $$ = $1; }
		| INTEGERNUMBER                        { $$ = $1; }
		| IDENTIFIER                           { $$ = $1; }
		| no_declaration PLUS	no_declaration { $$ = $1 + $3;}
		| no_declaration MINUS no_declaration  { $$ = $1 - $3; }
		| no_declaration MUL no_declaration    { $$ = $1 * $3; }
		| no_declaration  DIV	no_declaration { $$ = $1 / $3; }
		| no_declaration  REM	no_declaration { $$ = $1 % $3; }
		| no_declaration  POWER	no_declaration { $$ = $1 % $3; }
		| MINUS no_declaration %prec UMINUS    { $$ = -$1; }
		| IDENTIFIER INCREMENT                 { $$ = $1+1; }
		| IDENTIFIER DECREMENT                 { $$ = $1+1; }
		| ORBRACKET no_declaration ERBRACKET   { $$ = $2; } ;

increments: IDENTIFIER  INCREMENT              { $$ = $1+1; }
		 | IDENTIFIER DECREMENT                { $$ = $1+1; }
		 | IDENTIFIER PEQUAL no_declaration    { $1 = $1+$3; }
		 | IDENTIFIER MEQUAL no_declaration    { $1 = $1-$3; }
		 | IDENTIFIER MULEQUAL no_declaration  { $1 = $1*$3; }
		 | IDENTIFIER DIVEQUAL no_declaration  { $1 = $1/$3; }
		 ;


forExpression : increments                 {$$=$1;}
			   | IDENTIFIER ASSIGN no_declaration ;
		 
booleanExpression: expression AND expression          { $$ = $1 && $3; }
			| expression OR expression                { $$ = $1 || $3; }
			| NOT expression                          { $$ = ! $2; }
			| DataTypes GREATER DataTypes  			  { $$ = $1 > $3; }
			| DataTypes LESS DataTypes                { $$ = $1 < $3; }
			| DataTypes GE DataTypes                  { $$ = $1 >= $3; }
			| DataTypes LE DataTypes                  { $$ = $1 <= $3; }
			| DataTypes NE DataTypes                  { $$ = $1 != $3; }
			| DataTypes EQ DataTypes                  { $$ = $1 == $3; }
			| ORBRACKET booleanExpression ERBRACKET
			;
		

		
			
DataTypes:no_declaration
		| CHARACTER
		| FALSE 
	    | TRUE
		| TEXT;
			

		      

expression:	DataTypes
		| booleanExpression ;

caseExpression:	DEFAULT COLON stmtlist BREAK SEMICOLON                              
		| CASE INTEGERNUMBER COLON stmtlist BREAK SEMICOLON   caseExpression  		
		   ;

%% 
 int yyerror(char *s) {  int lineno=++yylineno;   fprintf(stderr, "line number : %d %s\n", lineno,s);     return 0; }
 
 int main(void) {
	
	yyin = fopen("input.txt", "r");
 
	f1=fopen("output.txt","w");
	
	if(!yyparse()) {
		printf("\nParsing complete\n");
		fprintf(f1,"hello there");
	}
	else {
		printf("\nParsing failed\n");
		return 0;
	}
	
	fclose(yyin);
	fclose(f1);
    return 0;
}