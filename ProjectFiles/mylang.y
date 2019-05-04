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

// Tokens for Increments used in loops m
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
	
	
//	%token FLOATNUMBER
//	%token TEXT
//	%token CHARACTER
	%token DEFAULT
//%token IDENTIFIER
	//%token INTEGER // note int is data type integer is for the number itslef
	
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
// -- To Bring The String & 
%union {
    int IntgerValue;                 /* integer value */
	float FloatValue;               /* float Value */
    char * StringValue;              /* string value */
	char * ChValue;               /* character value */
	char * ID ;                    /*IDENTIFIER Value */
	int* dummy;
};
%token <IntgerValue> INTEGER 
%token <FloatValue> FLOATNUMBER 
%token <StringValue> TEXT 
%token <ChValue> CHARACTER 
%token <ID>     IDENTIFIER
%type <IntgerValue> type 
%type <dummy> stmt equalFamily increments forExpression DataTypes function expression caseExpression 
%type <dummy> booleanExpression blockScope manyStatements
//%type <nPtr> 
	
%{ 
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
	#include"SymbolTable.h"
	int yyerror(char *);
	int yylex(void);
	int yylineno;
	int IDCount=0;
int brace=0;
extern struct SymbolData* setSymbol(int type, int init, int used, int brace, char * name);// Get a Symbol Entity
extern void pushSymbol(int ID, struct SymbolData* data);// to Insert a node in list
extern struct SymbolNode* getSymbolNODE();// to delete a node in list and return this node
extern int getID(char * Identifiyer, int rBraceSCope);// given Variable NAME AND SCOPE return ID
	FILE * outFile;
	FILE * inFile;
	void CreateID(int type , char*rName,int rID);	
%}


%%
// All Capital Letters are terminals Tokens else are non terminals 
mystart	: 
		startProgram
		;
	
startProgram :      startProgram stmt // here i want to call a quadrable function 
		|
		;
		
stmt:   type IDENTIFIER SEMICOLON	%prec IFX                 				{$$=NULL;CreateID($1,$2,0);printf("Declaration\n");IDCount=IDCount+1;}

		| IDENTIFIER ASSIGN expression SEMICOLON	          				{$$=NULL;printf("Assignment\n");}

		| type IDENTIFIER ASSIGN expression	SEMICOLON	      				{$$=NULL;printf("Declaration and Assignment\n");}

		| CONST type IDENTIFIER ASSIGN expression SEMICOLON   				{$$=NULL;printf("Constant assignment\n");}

		
		| WHILE ORBRACKET expression CRBRACKET stmt							{$$=NULL;printf("While loop\n");}

		| DO blockScope WHILE ORBRACKET expression CRBRACKET SEMICOLON		{$$=NULL;printf("Do while\n");}

		| FOR ORBRACKET INT IDENTIFIER ASSIGN INTEGER SEMICOLON 
		  expression SEMICOLON
		  forExpression CRBRACKET
		  blockScope											  			{$$=NULL;printf("For loop\n");}

		
		| IF ORBRACKET expression CRBRACKET blockScope %prec IFX 			{$$=NULL;printf("If statement\n");}

		| IF ORBRACKET expression CRBRACKET blockScope	 ELSE blockScope	{$$=NULL;printf("If-Elsestatement\n");}

		| SWITCH ORBRACKET IDENTIFIER CRBRACKET switchScope      			{$$=NULL;printf("Switch case\n");}

		
		| PRINT expression 	SEMICOLON	                        			{$$=NULL;printf("Print\n");}
		
		| function	                                            	         {$$=NULL;printf("Function Body\n");}
		| callFunction	                                            	         {$$=NULL;printf("Function Call\n");}

		| blockScope														{$$=NULL;printf("New  block\n");}
		|increments SEMICOLON													{$$=NULL;}			
		
		;

function : type IDENTIFIER ORBRACKET argList CRBRACKET OCBRACKET manyStatements RETURN  expression  SEMICOLON   CCBRACKET      {$$=NULL;printf("function\n");}
	   ;
callFunction: IDENTIFIER ORBRACKET callList CRBRACKET SEMICOLON
			;
callList : IDENTIFIER callList 
		| IDENTIFIER COMMA callList
		|			
		;
argList:  type IDENTIFIER commas  // argumenets list
          | // it can be empty for print functions maybe
	;

commas:  COMMA type IDENTIFIER commas {}
	|
	;
blockScope:	 OCBRACKET manyStatements CCBRACKET								{$$=NULL; brace++;printf("blockScope\n");}
			| OCBRACKET CCBRACKET{$$=NULL;}
		;

switchScope:  OCBRACKET caseExpression CCBRACKET					    {printf("Switch Case block\n");}
		;
		
manyStatements:  stmt {$$=NULL;}
        | manyStatements stmt {$$=NULL;}

type:   INT {$$=0;}
	| FLOAT {$$=1;}
	| CHAR  {$$=2;}
	| STRING{$$=3;}
	| BOOL	{$$=4;}
	;

equalFamily:   FLOATNUMBER                     {$$=NULL;}
		| INTEGER		                       {$$=NULL;}
		| IDENTIFIER                          {$$=NULL;}
		| equalFamily PLUS	equalFamily        {$$=NULL;}
		| equalFamily MINUS equalFamily        {$$=NULL;}
		| equalFamily MULTIPLY equalFamily     {$$=NULL;}
		| equalFamily  DIVIDE	equalFamily    {$$=NULL;}
		| equalFamily  REM	equalFamily        {$$=NULL;}
		| IDENTIFIER INC                       {$$=NULL;}
		| IDENTIFIER DEC                       {$$=NULL;}
		| ORBRACKET equalFamily CRBRACKET       {$$=NULL;}
		;

increments: IDENTIFIER  INC              {$$=NULL;}
		| IDENTIFIER DEC                {$$=NULL;}
		| IDENTIFIER PLUSEQUAL equalFamily    {$$=NULL;}
		| IDENTIFIER MINUSEQUAL equalFamily    {$$=NULL;}
		| IDENTIFIER MULTIPLYEQUAL equalFamily  {$$=NULL;}
		| IDENTIFIER DIVIDEEQUAL equalFamily {$$=NULL;}
		;


forExpression : increments                 {$$=NULL;}
			| IDENTIFIER ASSIGN equalFamily {$$=NULL;};
		 
booleanExpression: expression AND expression          {$$=NULL;}
			| expression OR expression                {$$=NULL;}
			| NOT expression                          {$$=NULL;}
			| DataTypes GREATERTHAN DataTypes  			{$$=NULL;}
			| DataTypes LESSTHAN DataTypes               {$$=NULL;}
			| DataTypes GREATERTHANOREQUAL DataTypes       {$$=NULL;}
			| DataTypes LESSTHANOREQUAL DataTypes               {$$=NULL;}
			| DataTypes NOTEQUAL DataTypes                  {$$=NULL;}
			| DataTypes EQUALEQUAL DataTypes                {$$=NULL;}
			| ORBRACKET booleanExpression CRBRACKET      {$$=NULL;}
			;
			
DataTypes:equalFamily{$$=NULL;}
		| CHARACTER {$$=NULL;}
		| FALSE {$$=NULL;}
	    | TRUE{$$=NULL;}
		| TEXT{$$=NULL;}
		;	

		      

expression:	DataTypes{{$$=NULL;}}
		| booleanExpression{{$$=NULL;}} ;

caseExpression:	DEFAULT COLON manyStatements BREAK SEMICOLON    		     {$$=NULL;printf(" Case Statment\n");}	  // with default and must end with default statment                    
		| CASE INTEGER COLON manyStatements BREAK SEMICOLON caseExpression 	 {$$=NULL;printf(" Case Statment\n");}	 // without default
		| CASE INTEGER COLON manyStatements  caseExpression					 {$$=NULL;printf(" Case Statment\n");}		// without break as break is not necessary
		   ;

%% 
void CreateID(int type , char*rName,int rID)
{
//printf(" Identifiyer is created with Name %s \n",rName);
//	int mID=getID(rName,0);
	
	int mID=1;
	if(mID!=-1)printf("Already Declared\n");
	
		SymbolData* rSymbol=setSymbol(type,-1,false,0,rName);
		pushSymbol(rID,rSymbol);
		printf(" Identifiyer is created with Name %s \n",rName);




}
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