%start mystart
// Tokens for brackets
	%token OCBRACKET // open curly brackets ||braces 
	%token CCBRACKET
	%token ORBRACKET // open round brackers 
	%token CRBRACKET

// Tokens for colons
	%token SEMICOLON
	%token COLON // :
	%token COMMA // , used in arguments lists 

// Tokens for Increments used in loops 
	%token PLUSEQUAL
	%token MINUSEQUAL
	%token MULTIPLYEQUAL
	%token DIVIDEEQUAL
	%token INC;
    %token DEC;

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
	%token RETURN
	
	
	%token FLOATNUMBER
	%token TEXT
	%token CHARACTER
	%token DEFAULT
	%token IDENTIFIER
	%token INTEGER // note int is data type integer is for the number itslef
	
	%token EXIT
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
	FILE * outFile;
	FILE * inFile;
%}


%%
// All Capital Letters are terminals Tokens else are non terminals 
mystart	: 
		startProgram
		;
	
startProgram :      startProgram stmt  
		|
		;
		
stmt:   type IDENTIFIER SEMICOLON	%prec IFX                 				{printf("Declaration\n");}

		| IDENTIFIER ASSIGN expression SEMICOLON	          				{printf("Assignment\n");}

		| type IDENTIFIER ASSIGN expression	SEMICOLON	      				{printf("Declaration and Assignment\n");}

		| CONST type IDENTIFIER ASSIGN expression SEMICOLON   				{printf("Constant assignment\n");}

		
		| WHILE ORBRACKET expression CRBRACKET stmt							{printf("While loop\n");}

		| DO blockScope WHILE ORBRACKET expression CRBRACKET SEMICOLON		{printf("Do while\n");}

		| FOR ORBRACKET INT IDENTIFIER ASSIGN INTEGER SEMICOLON 
		  expression SEMICOLON
		  forExpression CRBRACKET
		  blockScope											  			{printf("For loop\n");}

		| FOR ORBRACKET SEMICOLON SEMICOLON CRBRACKET
		  blockScope														{printf("empty condition for loop \n");}

		| FOR ORBRACKET SEMICOLON SEMICOLON CRBRACKET 
		  SEMICOLON  														{printf("empty condition infinite for loop \n");}

		
		| IF ORBRACKET expression CRBRACKET blockScope %prec IFX 			{printf("If statement\n");}

		| IF ORBRACKET expression CRBRACKET blockScope	 ELSE blockScope	{printf("If-Elsestatement\n");}

		| SWITCH ORBRACKET IDENTIFIER CRBRACKET switchScope      			{printf("Switch case\n");}

		
		| PRINT expression 	SEMICOLON	                        			{printf("Print\n");}
		
		| function	                                            	         {printf("Function Body\n");}
		| callFunction	                                            	         {printf("Function Call\n");}

		| blockScope														{printf("New  block\n");}
		|increments SEMICOLON
		
		;

function : type IDENTIFIER ORBRACKET argList CRBRACKET OCBRACKET manyStatements RETURN  expression  SEMICOLON   CCBRACKET      {printf("function\n");}
	   ;
callFunction: IDENTIFIER ORBRACKET callList CRBRACKET SEMICOLON
			;
callList : IDENTIFIER callList 
		| IDENTIFIER COMMA callList
		|			
		;
argList:  type IDENTIFIER commas // argumenets list
          | // it can be empty for print functions maybe
	;

commas:  COMMA type IDENTIFIER commas
	|
	;
blockScope:	 OCBRACKET manyStatements CCBRACKET								{printf("blockScope\n");}
			| OCBRACKET CCBRACKET
		;

switchScope:  OCBRACKET caseExpression CCBRACKET					    {printf("Switch Case block\n");}
		;
		
manyStatements:  stmt
        | manyStatements stmt ;

type:   INT
	| FLOAT
	| CHAR
	| STRING
	| BOOL
	;

equalFamily:   FLOATNUMBER                     { $$ = $1; }
		| INTEGER		                       { $$ = $1; }
		| IDENTIFIER                           { $$ = $1; }
		| equalFamily PLUS	equalFamily        { $$ = $1 + $3;}
		| equalFamily MINUS equalFamily        { $$ = $1 - $3; }
		| equalFamily MULTIPLY equalFamily     { $$ = $1 * $3; }
		| equalFamily  DIVIDE	equalFamily    { $$ = $1 / $3; }
		| equalFamily  REM	equalFamily        { $$ = $1 % $3; }
		| IDENTIFIER INC                       { $$ = $1+1; }
		| IDENTIFIER DEC                       { $$ = $1+1; }
		| ORBRACKET equalFamily CRBRACKET       { $$ = $2; }
		;

increments: IDENTIFIER  INC              { $$ = $1+1; }
		| IDENTIFIER DEC                { $$ = $1-1; }
		| IDENTIFIER PLUSEQUAL equalFamily    { $1 = $1+$3; }
		| IDENTIFIER MINUSEQUAL equalFamily    { $1 = $1-$3; }
		| IDENTIFIER MULTIPLYEQUAL equalFamily  { $1 = $1*$3; }
		| IDENTIFIER DIVIDEEQUAL equalFamily  { $1 = $1/$3; }
		;


forExpression : increments                 {$$=$1;}
			| IDENTIFIER ASSIGN equalFamily ;
		 
booleanExpression: expression AND expression          { $$ = $1 && $3; }
			| expression OR expression                { $$ = $1 || $3; }
			| NOT expression                          { $$ = ! $2; }
			| DataTypes GREATERTHAN DataTypes  			  { $$ = $1 > $3; }
			| DataTypes LESSTHAN DataTypes                { $$ = $1 < $3; }
			| DataTypes GREATERTHANOREQUAL DataTypes                  { $$ = $1 >= $3; }
			| DataTypes LESSTHANOREQUAL DataTypes                  { $$ = $1 <= $3; }
			| DataTypes NOTEQUAL DataTypes                  { $$ = $1 != $3; }
			| DataTypes EQUALEQUAL DataTypes                  { $$ = $1 == $3; }
			| ORBRACKET booleanExpression CRBRACKET
			;
			
DataTypes:equalFamily
		| CHARACTER
		| FALSE 
	  | TRUE
		| TEXT;
			

		      

expression:	DataTypes
		| booleanExpression ;

caseExpression:	DEFAULT COLON manyStatements BREAK SEMICOLON    		     {printf(" Case Statment\n");}	  // with default and must end with default statment                    
		| CASE INTEGER COLON manyStatements BREAK SEMICOLON caseExpression 	 {printf(" Case Statment\n");}	 // without default
		| CASE INTEGER COLON manyStatements  caseExpression					 {printf(" Case Statment\n");}		// without break as break is not necessary
		   ;

%% 
 int yyerror(char *s) {  int lineno=++yylineno;   fprintf(stderr, "line number : %d %s\n", lineno,s);     return 0; }
 
 int main(void) {
	
	inFile = fopen("input.txt", "r");
 
	outFile=fopen("output.txt","w");
	
	if(!yyparse()) {
		printf("\nParsing complete\n");
		fprintf(outFile,"Completed");
	}
	else {
		printf("\nParsing failed\n %d",yylineno);
		return 0;
	}
	
	fclose(inFile);
	fclose(outFile);
    return 0;
}