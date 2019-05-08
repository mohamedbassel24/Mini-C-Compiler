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
%type <IntgerValue> type equalFamily expression DataTypes callFunction
%type <dummy> stmt  increments forExpression  function  caseExpression 
%type <dummy> booleanExpression blockScope manyStatements scopeOpen scopeClose
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
	int SCOPE_Number=0;
	FILE * outFile;
	FILE * inFile;
	FILE *outSymbol;
	void ThrowError(char *Message, char *rVar);							//-- A Function to Terminate the Program and Report an Semantic Error
	void CreateID(int type , char*rName,int rID,int ScopeNum);						// -- Create a Symbol given its type and Name 
	void  getIDENTIFIER(char*rName);									//-- set Symbol Value 
	void usedIDENTIFIER(char*rName,int ScopeNum );									// set that Symbol is Used as a RHS in any operation 
	char * conctanteStr(char* str1,char*str2);							// -- a function to conctante two strings 
	bool checktypeIDENTIFER(int LeftType,int RightType,char* Right);		//-- Check Left and Right hand side in Assigment operation;
	char* idtypeString[10] = { "Integer", "Float", "Char", "String", "Bool", "ConstIntger", "ConstFloat", "ConstChar", "ConstString", "ConstBool" };
	int FuncArgTypes[10];//Assuming Max 10 arguments 
	int ArgCounter=0;
	void CreateFunction(int type , char*rName,int rID,int ScopeNum,int rArgCounter,int *ArrOfTypes);
%}


%%
// All Capital Letters are terminals Tokens else are non terminals 
mystart	: 
		startProgram
		;
	
startProgram :      startProgram stmt  
		|
		;
		
stmt:   type IDENTIFIER SEMICOLON	%prec IFX                 				{$$=NULL;CreateID($1,$2,IDCount++,SCOPE_Number);printf("Declaration\n");}

		| IDENTIFIER ASSIGN expression SEMICOLON	          				{$$=NULL;
																			if(checktypeIDENTIFER(getSymbolType($1),$3,$1))
																			{
																				getIDENTIFIER($1);
																				printf("Assignment\n");}
																			else 
																				{
																					char*str1=conctanteStr($1," of Type");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType($1)]);
																			
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}

		| type IDENTIFIER ASSIGN expression	SEMICOLON	      				{$$=NULL;
																			CreateID($1,$2,IDCount++,SCOPE_Number);
																			if(checktypeIDENTIFER(getSymbolType($2),$4,$2))
																			{
																			getIDENTIFIER($2);// setValue here 
																			printf("Declaration and Assignment\n");
																			}
																			else
																				{
																					char*str1=conctanteStr($2," of Type ");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType($2)]);
												
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}

		| CONST type IDENTIFIER ASSIGN expression SEMICOLON   				{
																				$$=NULL;
																				CreateID($2+5,$3,IDCount++,SCOPE_Number);
																			if(checktypeIDENTIFER(getSymbolType($3),$5,$3))
																			{
																				printf("Constant assignment\n");
																			}
																			else
																				{
																					char*str1=conctanteStr($3," of Type ");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType($3)]);
																			
																				ThrowError("Error: incompatible types ",str2);
																				}
																			;}

		
		| WHILE ORBRACKET expression CRBRACKET stmt							{$$=NULL;printf("While loop\n");}// need to check type to booealen

		| DO blockScope WHILE ORBRACKET expression CRBRACKET SEMICOLON		{$$=NULL;printf("Do while\n");}// need to check type to booealen

		| FOR ORBRACKET INT  create ASSIGN INTEGER SEMICOLON 
		  expression SEMICOLON
		  forExpression CRBRACKET
		  blockScope											  			{$$=NULL;printf("For loop\n");}//  TO-DO check types on expression must int 

		
		| IF ORBRACKET expression CRBRACKET blockScope %prec IFX 			{$$=NULL;printf("If statement\n");}

		| IF ORBRACKET expression CRBRACKET blockScope	 ELSE blockScope	{$$=NULL;printf("If-Elsestatement\n");}

		| SWITCH ORBRACKET IDENTIFIER CRBRACKET switchScope      			{$$=NULL;usedIDENTIFIER($3,SCOPE_Number);printf("Switch case\n");}

		
		| PRINT expression 	SEMICOLON	                        				{$$=NULL;printf("Print\n");}
		
		| function	                                            		      {$$=NULL;printf("Function Body\n");}
		|callFunction	                                    			      {$$=NULL;printf("Function Call\n");}
		|IDENTIFIER ASSIGN callFunction	                                      {$$=NULL;
																				if(checktypeIDENTIFER(getSymbolType($1),$3,$1))
																				{
																				getIDENTIFIER($1);
																				printf("Function Call\n");}
																				else 
																				{
																					char*str1=conctanteStr($1," of Type");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType($1)]);
																			
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}
		|type IDENTIFIER ASSIGN callFunction	                              {$$=NULL;
																				CreateID($1,$2,IDCount++,SCOPE_Number);
																				if(checktypeIDENTIFER(getSymbolType($2),$4,$2))
																				{
		
																					getIDENTIFIER($2);// setValue here 
																					printf("Function Call\n");
																				}
																				else
																				{
																					char*str1=conctanteStr($2," of Type ");
																					char* str2=conctanteStr(str1,idtypeString[getSymbolType($2)]);
												
																				ThrowError("Error: incompatible types ",str2);
																				}
																			}

		| blockScope														{$$=NULL;printf("New  block\n");}
		|increments SEMICOLON													{$$=NULL;}			
		
		;
create :IDENTIFIER {CreateID(0,$1 ,IDCount++,SCOPE_Number+1);getIDENTIFIER($1);}; // a rule to create int i; in For Loop // must be named i ? cant get IDENTIFUER Val 
function : type IDENTIFIER ORBRACKET resetCounter argList CRBRACKET OCBRACKET scopeOpen manyStatements RETURN  expression  SEMICOLON   CCBRACKET scopeClose  
																															{
																																$$=NULL;
																																if($1 !=$11)//check return types 
																																{
																																	ThrowError("Error: incompatible return types of Function ",$2);
																																	ThrowError("Error: incompatible return types of Function ",$2);
																																}
																																else
																																{
																																	CreateFunction($1,$2,IDCount++,SCOPE_Number,ArgCounter,FuncArgTypes);
																																	printf("function\n");
																																}
																															}// create a function symbol 
	   ;
callFunction: IDENTIFIER ORBRACKET resetCounter callList CRBRACKET SEMICOLON// To-DO check here
																{
																	$$=getSymbolType($1);
																	int num =checkArgType(ArgCounter,FuncArgTypes,$1,SCOPE_Number);
																	if(num==-25)
																	{
																		ThrowError("Error: undefined Function With Name ",$1);
																	}
																	else if(num== 0)
																	{
																		ThrowError("Error: mismatch argument number of function ",$1);
																	}
																	else if(num ==-1)
																	{
																		ThrowError("Error: incompatible types of Function ",$1);
																	}
																}
			;

callList:   IDENTIFIER COMMA callList {usedIDENTIFIER($1,SCOPE_Number); FuncArgTypes[ArgCounter++]=getSymbolType($1);}
	      |  IDENTIFIER   {usedIDENTIFIER($1,SCOPE_Number);  FuncArgTypes[ArgCounter++]=getSymbolType($1);}
		  | // it can be empty for print functions maybe
	;		
resetCounter: {ArgCounter=0;};
argList:  type IDENTIFIER COMMA argList {CreateID($1,$2,IDCount++,SCOPE_Number+1); FuncArgTypes[ArgCounter++]=$1;}// bec the scope is yet not incremeneted
	      | type IDENTIFIER   {CreateID($1,$2,IDCount++,SCOPE_Number+1); FuncArgTypes[ArgCounter++]=$1;}// bec the scope is yet not incremeneted
		  | // it can be empty for print functions maybe 
		  //TO DOcheck if , accept parsing? 
	;


blockScope:	 OCBRACKET scopeOpen manyStatements CCBRACKET scopeClose								{$$=NULL;printf("blockScope\n");}
			| OCBRACKET scopeOpen CCBRACKET scopeClose{$$=NULL;}
		;

switchScope:  OCBRACKET scopeOpen caseExpression CCBRACKET	scopeClose				    {printf("Switch Case block\n");}
		;
scopeOpen :{$$=NULL; SCOPE_Number++;}
scopeClose :{$$=NULL;DeadSymbols(SCOPE_Number); SCOPE_Number--;}		
manyStatements:  stmt {$$=$1;} 
        | manyStatements stmt {$$=NULL;}

type:   INT {$$=0;}
	| FLOAT {$$=1;}
	| CHAR  {$$=2;}
	| STRING{$$=3;}
	| BOOL	{$$=4;}
	;

equalFamily:   FLOATNUMBER                     {$$=1;}// TO-DO needed to return the type of varible here
		| INTEGER		                       {$$=0;}
		| IDENTIFIER                           {$$=getSymbolType($1);usedIDENTIFIER($1,SCOPE_Number);}// getType here
		| equalFamily PLUS	equalFamily        {if($1==$3) $$=$1; else ThrowError("Conflict dataTypes in Addition \n "," "); }//TO -DO  create a message and a boolean variable indiactes type conflict
		| equalFamily MINUS equalFamily        {if($1==$3) $$=$1; else ThrowError("Conflict dataTypes in Subtraction \n "," "); }// i cant get the Name of var result ?
		| equalFamily MULTIPLY equalFamily     {if($1==$3) $$=$1; else ThrowError("Conflict dataTypes in Multipication \n "," "); }// check in con
		| equalFamily  DIVIDE	equalFamily    {if($1==$3) $$=$1; else ThrowError("Conflict dataTypes in Divison \n "," "); }
		| equalFamily  REM	equalFamily        {if($1==$3) $$=$1; else ThrowError("Conflict dataTypes in reminder \n "," "); }
		| IDENTIFIER INC                       {$$=getSymbolType($1);usedIDENTIFIER($1,SCOPE_Number);}// getSymbolType
		| IDENTIFIER DEC                       {$$=getSymbolType($1);usedIDENTIFIER($1,SCOPE_Number);}
		| ORBRACKET equalFamily CRBRACKET       {$$=$2;}
		;

increments: IDENTIFIER  INC            			  {$$=NULL;} // To DO add used here 
		| IDENTIFIER DEC               			 {$$=NULL;}
		| IDENTIFIER PLUSEQUAL equalFamily    	{$$=NULL;}// check type here
		| IDENTIFIER MINUSEQUAL equalFamily   	 {$$=NULL;}
		| IDENTIFIER MULTIPLYEQUAL equalFamily  {$$=NULL;}
		| IDENTIFIER DIVIDEEQUAL equalFamily {$$=NULL;}
		;


forExpression : increments                 {$$=NULL;}
			| IDENTIFIER ASSIGN equalFamily {$$=NULL; };// add check type and initizlation
		 
booleanExpression: expression AND expression          {$$=NULL;}
			| expression OR expression                {$$=NULL;}
			| NOT expression                          {$$=NULL;}// check types here 
			| DataTypes GREATERTHAN DataTypes         {$$=NULL;}
			| DataTypes LESSTHAN DataTypes            {$$=NULL;}
			| DataTypes GREATERTHANOREQUAL DataTypes  {$$=NULL;}
			| DataTypes LESSTHANOREQUAL DataTypes     {$$=NULL;}
			| DataTypes NOTEQUAL DataTypes            {$$=NULL;}
			| DataTypes EQUALEQUAL DataTypes          {$$=NULL;}
			| ORBRACKET booleanExpression CRBRACKET   {$$=NULL;}
			;
			
DataTypes:equalFamily{$$=$1;}
		| CHARACTER {$$=2;}
		| FALSE {$$=4;}
	    | TRUE{$$=4;}
		| TEXT{$$=3;}
		;	

/*		      
dummyRules : {printf("ImHere \n");};// for debug
*/
expression:	DataTypes{{$$=$1;}}
		| booleanExpression{{$$=4;}} ;

caseExpression:	DEFAULT COLON manyStatements BREAK SEMICOLON    		     {$$=NULL;printf(" Case Statment\n");}	  // with default and must end with default statment                    
		| CASE INTEGER COLON manyStatements BREAK SEMICOLON caseExpression 	 {$$=NULL;printf(" Case Statment\n");}	 // without default
		| CASE INTEGER COLON manyStatements  caseExpression					 {$$=NULL;printf(" Case Statment\n");}		// without break as break is not necessary
		   ;

%% 
void CreateID(int type , char*rName,int rID,int ScopeNum)
{
	if(CheckIDENTIFYER(rName))
	ThrowError("Already Declared IDENTIFIER with Name ",rName);
	//printf("IDENTIFIER with Name %s is Already Declared \n",rName);
	else
	{
		bool isConstant=(type>4)?true:false;
		SymbolData* rSymbol=setSymbol(type,0,false,0,rName,!isConstant,ScopeNum);
		if(isConstant)
		{
			rSymbol->Initilzation=true;
			pushSymbol(rID,rSymbol);
			printf("Constant Symbol is created with Name %s \n",rName);	
		}
		else 
		{
			pushSymbol(rID,rSymbol);
			printf(" Symbol is created with Name %s \n",rName);
		}
	}
}
void CreateFunction(int type , char*rName,int rID,int ScopeNum,int rArgCounter,int *ArrOfTypes)
{
	if(CheckIDENTIFYER(rName))
	ThrowError("Already Declared IDENTIFIER with Name ",rName);
	//printf("IDENTIFIER with Name %s is Already Declared \n",rName);
	else
	{
		bool isConstant=(type>4)?true:false;// constant function ? XD
		SymbolData* rSymbol=setSymbol(type,0,false,0,rName,!isConstant,ScopeNum);
		if(isConstant)
		{
			rSymbol->Initilzation=true;
			setFuncArg(rArgCounter,ArrOfTypes,rSymbol);
			pushSymbol(rID,rSymbol);
			printf("Constant Symbol Function is created with Name %s \n",rName);	
		}
		else 
		{
			setFuncArg(rArgCounter,ArrOfTypes,rSymbol);
			pushSymbol(rID,rSymbol);
			printf(" Symbol Function is created with Name %s \n",rName);
		}
		
	}

}
void getIDENTIFIER(char*rName)
{
	SymbolNode * rSymbol=getID(rName, 0);
	if(!rSymbol)
	//printf("IDENTIFIER with Name %s is not Declared with this scope\n",rName);
	ThrowError("Not Declared in This Scope Identifiyer with Name \n ",rName);
	else
	{
		//printf("IDENTIFIER with Name is Initilized %s \n",rName);
		if(!rSymbol->DATA->Modifiable)
			ThrowError("Can't Modify a Constant Identifiyer with Name \n ",rName);
		else
			rSymbol->DATA->Initilzation=true;
	}
}
void usedIDENTIFIER(char*rName,int ScopeNum)
{
	SymbolNode * rSymbol=getID(rName, ScopeNum);
	if(!rSymbol)
	ThrowError("Not Declared in This Scope Identifiyer with Name \n ",rName);
	else
	{
		printf("IDENTIFIER with Name is Used %s \n",rName);
		if(!rSymbol->DATA->Initilzation)printf("Warning :IDENTIFIER with Name %s is not Initilized and is being used.  \n",rName);// don't quit just a warning
		rSymbol->DATA->Used=true;
	}
}
bool checktypeIDENTIFER(int LeftType,int RightType,char* Right)
{
	/*if(LeftType!=RightType)
	{
		printf("IDENTIFIER with Name  %s has error Type conflict \n",Right);
		return false;
	}
	else
	{
		printf("IDENTIFIER with Name  %s has correct type \n",Right);
		return true;
	}*/
	bool correct = ((LeftType==RightType) || (LeftType-5 ==RightType))?true:false; // here i check both constants types and types 
	return correct;

}
void ThrowError(char *Message, char *rVar)
{
	fclose(inFile);
	//int x = remove("output.txt");
	inFile = fopen("output.txt","w");
	fprintf(inFile, "Syntax Error Could not parse quadruples\n");
 	fprintf(inFile, "line number: %d %s : %s\n", yylineno,Message,rVar);
	printf("line number: %d %s : %s\n", yylineno,Message,rVar);
	fclose(outSymbol);
	 remove("mySymbols.txt");
	outSymbol = fopen("mySymbols.txt","w");
	fprintf(outSymbol, "Syntax Error was Found\n");
 	fprintf(outSymbol, "line number: %d %s : %s\n", yylineno,Message,rVar);
 	exit(0);
};
// needed ?
 int yyerror(char *s) {  int lineno=++yylineno;   fprintf(stderr, "line number : %d %s\n", lineno,s);     return 0; }
 
 char * conctanteStr(char* str1,char*str2)
 {  
      char * str3 = (char *) malloc(1 + strlen(str1)+ strlen(str2) );
      strcpy(str3, str1);
      strcat(str3, str2);
	return str3;
 
 }
 int main(void) {
	
	inFile = fopen("input.txt", "r");
	outFile=fopen("output.txt","w");
	outSymbol=fopen("mySymbols.txt","w");
	if(!yyparse()) {
		printf("\nParsing complete\n");
		PrintSymbolTable(outSymbol);
		DestroyList();
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