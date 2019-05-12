#include"SymbolTable.h"


char* idtype[10] = { "Integer", "Float", "Char", "String", "Bool", "ConstIntger", "ConstFloat", "ConstChar", "ConstString", "ConstBool" };
struct SymbolNode * ListTop = NULL;
struct SymbolData* setSymbol(int rType, int rValue, bool rUsed, int Scope,char* Identifyier,bool rModifiable,int ScopeNum)
{
	struct SymbolData *data = (struct SymbolData*) malloc(sizeof(struct SymbolData));
	data->Type = rType;
	data->Initilzation = rValue;
	data->Used = rUsed;
	data->BracesScope = Scope;
	data->IdentifierName = Identifyier;
	data->Modifiable=rModifiable;// it can be set automatically 
	data->BracesScope = ScopeNum;
	data->IsFunctionSymbol = false;
	

	return data;
}
void pushSymbol(int index, struct SymbolData *data) {
	//--Insert from Begining 
	struct SymbolNode *mySymbolNode = (struct SymbolNode*) malloc(sizeof(struct SymbolNode));
	mySymbolNode->ID = index;
	mySymbolNode->DATA = data;
	mySymbolNode->Next = ListTop;
	ListTop = mySymbolNode;
}
/*
SymbolNode* getSymbolNODE() {
	if (!ListTop)return NULL;
	SymbolNode * SymbolPtr = ListTop;
	// Move The head then
	ListTop = ListTop->Next;
	return SymbolPtr;
}*/


int countNODE()
{
	int mCount = 0;
	SymbolNode * Walker = ListTop;
	while (Walker)
	{
		mCount++;
		Walker = Walker->Next;
	}
	return mCount;
}

bool isEmpty()
{
	return (ListTop == NULL) ? true : false;
}

SymbolData * getSymbol(int rID)
{
	int mCount = 0;
	SymbolNode * Walker = ListTop;
	while (Walker)
	{
		if (Walker->ID == rID)
		{
			return Walker->DATA;
		}
	}
	return NULL;
}

void printList(SymbolNode*rHead)
{
	// Base case  
	if (rHead == NULL)
		return;

	// print the list after head node  
	printList(rHead->Next);

	// After everything else is printed, print head  
//	cout << rHead->DATA->BracesScope << " ";
}

void setTOKENNAME(int ID, char * Value)
{
	SymbolData*rData = getSymbol(ID);
	strcpy_s(rData->IdentifierName,sizeof(Value), Value);
}

void setUsed(int rID)
{
	SymbolData *S = getSymbol(rID);
	if (!S)
	S->Used = true;
}

void setInitilization(int rID)
{
	SymbolData *S = getSymbol(rID);
	if (!S)
	S->Initilzation = true;
}
SymbolNode *  getID(char * Identifiyer, int rBraceSCope)
{
	SymbolNode * Walker = ListTop;
	//start from the beginning

	while (Walker)
	{
		if ((strcmp(Identifiyer, Walker->DATA->IdentifierName)==0 ) && (Walker->DATA->BracesScope !=-1 )  )
		{
			return Walker;
		}

		Walker = Walker->Next;
	}

	return NULL;
}
bool CheckIDENTIFYER(char * ID)
{
	SymbolNode * Walker = ListTop;

	//start from the beginning
	while (Walker)
	{
		if (strcmp(ID, Walker->DATA->IdentifierName) == 0)
		{
			return true;
		}

		Walker = Walker->Next;
	}

	return-false;

}
void PrintSymbolTable(FILE*F)
{
	printUsed(F);
	printNotUsed(F);
	printInitilized(F);
	printNotInit(F);
	
}
int getSymbolType(char * rID)
{
	SymbolNode * Walker = ListTop;
	while (Walker)
	{
		if (strcmp(rID, Walker->DATA->IdentifierName) == 0)//&& Walker->DATA->BracesScope <=rBraceSCope)
		{
			return Walker->DATA->Type;
		}

		Walker = Walker->Next;
	}
	return -1;

}
void setFuncArg(int ArgCount, int * ArgTypes, SymbolData * rD)
{
	rD->ArrTypes = (int *)malloc(sizeof(int)*ArgCount);
	int i;
	for (i = 0; i < ArgCount; i++)
	{
		rD->ArrTypes[i] = ArgTypes[i];
	}
	rD->IsFunctionSymbol = true;
	rD->ArgNum = ArgCount;

}
int checkArgType(int ArgCount, int * ArgTypes, char * rString,int Scope)
{
	SymbolNode * rD = getID(rString,Scope );
	if (rD == NULL)return -25;// no Decleared Function with this Name
	if (rD->DATA->ArgNum!= ArgCount)
		return 0; //error indicates misArgumentsCount
	int i;
	for (i = 0; i < ArgCount; i++)
	{
		if (rD->DATA->ArrTypes[i] != ArgTypes[i])
			return -1;// MisMatchArg
	}
	return 1;//Accepted		
}
void DeadSymbols(int Brace)
{
	SymbolNode * Walker = ListTop;
	while (Walker)
	{
		if  (Walker->DATA->BracesScope == Brace)
		{
			Walker->DATA->BracesScope = -1;
		}

		Walker = Walker->Next;
	}
}
void DestroyList()
{
	SymbolNode * Walker = ListTop;

	while (Walker)
	{
		SymbolNode *rD = Walker;
		Walker = Walker->Next;
		free (rD);

	}

}
void printUsed(FILE *f)
{
	SymbolNode * Walker = ListTop;
	fprintf(f, "Used Identifiers :- \n");
	while (Walker)
	{
		if (Walker->DATA->Used)
		{
			fprintf(f, "%s of type %s\n", Walker->DATA->IdentifierName, idtype[Walker->DATA->Type]);
		}
		Walker = Walker->Next;
	}

	fprintf(f, "\n");
}
void printNotUsed(FILE *f)
{
	SymbolNode * Walker = ListTop;
	fprintf(f, "UnUsed Identifiers :- \n");
	while (Walker)
	{
		if (!(Walker->DATA->Used))
		{
			fprintf(f, "%s of type %s\n", Walker->DATA->IdentifierName, idtype[Walker->DATA->Type]);
		}
		Walker = Walker->Next;
	}

	fprintf(f, "\n");
}
void printInitilized(FILE *f)
{
	SymbolNode * Walker = ListTop;
	fprintf(f, "Initilized Identifiers :- \n");
	while (Walker)
	{
		if (Walker->DATA->Initilzation)
		{
			fprintf(f, "%s of type %s\n", Walker->DATA->IdentifierName, idtype[Walker->DATA->Type]);
		}
		Walker = Walker->Next;
	}

	fprintf(f, "\n");
}
void printNotInit(FILE *f)
{
	SymbolNode * Walker = ListTop;
	fprintf(f, "UnInitilized Identifiers :- \n");
	while (Walker)
	{
		if (!(Walker->DATA->Initilzation))
		{
			fprintf(f, "%s of type %s\n", Walker->DATA->IdentifierName, idtype[Walker->DATA->Type]);
		}
		Walker = Walker->Next;
	}

	fprintf(f, "\n");
}
//-----------------------------------------------------------------------------------------------------
QuadNode*TopPtr = NULL;
void setQuad(int Op, char* Arg1, char* Arg2,char*Result,int rID)
{
	struct QuadData *data = (struct QuadData*) malloc(sizeof(struct QuadData));
	data->OpCode = Op;
	data->Arg1 = Arg1;
	data->Arg2 = Arg2;
	data->Result = Result;
	InsertQuadruple(data, rID); // insert in list 
	return ;
}
void InsertQuadruple(QuadData*rD, int ID)
{
	if (!TopPtr)
	{
	struct QuadNode *mySymbolNode = (struct QuadNode*) malloc(sizeof(struct QuadNode));
	TopPtr = mySymbolNode;
	mySymbolNode->ID = ID;
	mySymbolNode->DATA = rD;
	TopPtr->Next = NULL;
	return;
	}
	struct QuadNode *Walker = TopPtr;
	while (Walker->Next)
		Walker = Walker->Next;// get last Node
	struct QuadNode *mySymbolNode = (struct QuadNode*) malloc(sizeof(struct QuadNode));
	mySymbolNode->ID = ID;
	mySymbolNode->DATA = rD;
	mySymbolNode->Next = NULL;
	Walker->Next = mySymbolNode; // insert on end "Queue"
}
void PrintQuadList(FILE * f)
{
	struct QuadNode *Walker = TopPtr;
	while (Walker)
	{
		fprintf(f, " OpCode: %d  Arg1:%s  Arg2: %s Result:%s \n", Walker->DATA->OpCode, Walker->DATA->Arg1, Walker->DATA->Arg2, Walker->DATA->Result);
		Walker = Walker->Next;
	}
}
//-------------------------------------------------------------------Quad Functions
QuadNode*getTOP()
{
	return TopPtr;
}
Reg CheckReg();
void SetReg(Reg x);
void ResetReg();
Reg reg[7];
char* CurlyBraces[7];
void ExctractQuad(QuadNode* head,FILE *f)
{
	QuadNode*ptr = head;
	ResetReg();
	Reg free;
	Reg Aux;
	Reg SwitchReg;
	int CbraceCounterIF=0;
	while (ptr != NULL)
	{
		switch (ptr->DATA->OpCode)
		{
		case DECLARE_:
			free = CheckReg();
			if (ptr->DATA->Arg1 == " " && ptr->DATA->Arg2 == " ")
			{
				fprintf(f, "MOV %s , %s \n", free.reg,"NULL");
				fprintf(f, "MOV %s , %s \n", ptr->DATA->Result,free.reg);
			}
			else if (ptr->DATA->Arg1 != " ") {
				fprintf(f, "MOV %s , %s \n", free.reg,ptr->DATA->Arg1);
				fprintf(f, "MOV %s , %s \n", ptr->DATA->Result, free.reg);
			//	output.push_back("MOV " + free.reg + "," + (string)ptr->DATA->Arg1);
			//	output.push_back("MOV " + (string)ptr->DATA->Result + "," + free.var);
			}
			else if (ptr->DATA->Arg2 != " ") {
				fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
				fprintf(f, "MOV %s , %s \n", ptr->DATA->Result, free.reg);
			//	output.push_back("MOV " + free.reg + "," + (string)ptr->DATA->Arg2);
			//	output.push_back("MOV " + (string)ptr->DATA->Result + "," + free.var);
			}
			free.used++;
			free.var = ptr->DATA->Result;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case ASSIGN_:
			free = CheckReg();
			if (ptr->DATA->Arg1 != " ") {
				fprintf(f, "MOV %s , %s \n", free.reg,ptr->DATA->Arg1);
				fprintf(f, "MOV %s , %s \n", ptr->DATA->Result, free.reg);
			//	output.push_back("MOV " + free.reg + "," + (string)ptr->DATA->Arg1);
			//	output.push_back("MOV " + (string)ptr->DATA->Result + "," + free.var);
			}
			else if (ptr->DATA->Arg2 != " ") {
				fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
				fprintf(f, "MOV %s , %s \n", ptr->DATA->Result, free.reg);
			//	output.push_back("MOV " + free.reg + "," + (string)ptr->DATA->Arg2);
			//	output.push_back("MOV " + (string)ptr->DATA->Result + "," + free.var);
			}
			free.used++;
			free.var = ptr->DATA->Result;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case ADD_:
			// TO DO check if Integar value dont move and add directly
			free = CheckReg();
			Aux = free;
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg1);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			fprintf(f, "ADD %s , %s , %s\n", ptr->DATA->Result,Aux.reg, free.reg);// add new REGISTER ! 
			ptr = ptr->Next;
			break;
		case MINUS_:
			free = CheckReg();
			Aux = free;
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg1);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			fprintf(f, "SUB %s , %s , %s\n", ptr->DATA->Result,Aux.reg, free.reg);// add new REGISTER ! 
			ptr = ptr->Next;
			break;
		case MULTIPLY_:
			free = CheckReg();
			Aux = free;
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg1);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			fprintf(f, "IMUL %s , %s , %s\n", ptr->DATA->Result,Aux.reg, free.reg);// add new REGISTER ! 
			ptr = ptr->Next;
			break;
		case DIVIDE_:
			fprintf(f, "MOV %s , %s \n", "R0", ptr->DATA->Arg1);
			free = CheckReg();
			if(free.reg == "R0")
				free.reg = "R6";
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
			fprintf(f, "DIV %s \n", free.reg);
			fprintf(f, "MOV %s , %s \n", ptr->DATA->Result, "R0");
			ptr = ptr->Next;
			break;
		case REM_:
			free = CheckReg();
			Aux = free;
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg1);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg2);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			fprintf(f, "REM %s , %s , %s\n", ptr->DATA->Result,Aux.reg, free.reg);// add new REGISTER ! 
			ptr = ptr->Next;
			break;
		case INC_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Result);
			fprintf(f, "INC %s \n", free.reg);
			fprintf(f, "MOV %s , %s \n", ptr->DATA->Result,free.reg);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case DEC_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Result);
			fprintf(f, "DEC %s \n", free.reg);
			fprintf(f, "MOV %s , %s \n", ptr->DATA->Result,free.reg);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case SWITCH_:
			free = CheckReg();
			fprintf(f, "StartCase: \n");
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Result);
			fprintf(f, "COMPEQVAL %s \n", free.reg);
			fprintf(f, "JNZ Case \n");
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case CASE_:
			fprintf(f, "JMP CloseCase \n");
			free = CheckReg();
			fprintf(f, "Case: \n");
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Result);
			fprintf(f, "COMPEQVAL %s \n", free.reg);
			fprintf(f, "JNZ Case \n");
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case SWITCHDEFAULT_:
			fprintf(f, "JMP CloseCase \n");
			fprintf(f, "DefaultCase: \n");
			ptr = ptr->Next;
			break;
		case CLOSESWITCH_:
			fprintf(f, "CloseSwitch: \n");
			ptr = ptr->Next;
			break;
		case WHILE_:
			fprintf(f, "%s : \n", ptr->DATA->Result);
			fprintf(f, "JF %s \n","CloseWhile");
			ptr = ptr->Next;
			break;
		case CLOSEWHILE_:
			fprintf(f, "JC %s \n", ptr->DATA->Arg2);
			fprintf(f, "%s : \n",ptr->DATA->Result);
			ptr = ptr->Next;
			break;
		case FOR_:
			fprintf(f, "%s : \n", ptr->DATA->Result);
			fprintf(f, "JF %s \n","CloseForLoop");
			ptr = ptr->Next;
			break;
		case CLOSEFORLOOP_:
			fprintf(f, "JC %s \n", ptr->DATA->Arg2);
			fprintf(f, "%s : \n",ptr->DATA->Result);
			ptr = ptr->Next;
			break;
		case IF_:
			fprintf(f, "%s \n", ptr->DATA->Arg2);
			ptr = ptr->Next;
			break;
		case LESSTHAN_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "CMPL %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case GREATERTHAN_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "CMPG %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case LESSTHANOREQUAL_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "CMPLEQ %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case GREATERTHANOREQUAL_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "CMPGEQ %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case EQUALEQUAL_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "CMPEQ %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
			case NOTEQUAL_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "CMPNEQ %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case AND_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "AND %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case ELSE_:
			fprintf(f, "%s \n", "CloseIf");
			fprintf(f, "%s \n", "OpenElse");
			ptr = ptr->Next;
			break;
		case CLOSEELSE_:
			fprintf(f, "%s \n", "CloseElse");
			ptr = ptr->Next;
			break;
		case DOWHILE_:
			fprintf(f, "%s : \n", ptr->DATA->Result);
			ptr = ptr->Next;
			break;
		case CLOSEDOWHILE_:
			fprintf(f, "JC %s \n", "OpenDoWhile");
			ptr = ptr->Next;
			break;
		case OR_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			free.used++;
			free.var = ptr->DATA->Arg1;
			SetReg(free);
			Aux = CheckReg();
			fprintf(f, "MOV %s , %s \n", Aux.reg, ptr->DATA->Arg2);
			Aux.used++;
			Aux.var = ptr->DATA->Arg1;
			SetReg(Aux);
			fprintf(f, "OR %s, %s , %s \n", ptr->DATA->Result, Aux.reg, free.reg);
			ptr = ptr->Next;
			break;
		case PRINT_:
			free = CheckReg();
			fprintf(f, "PRINT %s \n", free.reg);
			free.used++;
			free.var = ptr->DATA->Arg2;
			SetReg(free);
			ptr = ptr->Next;
			break;
		case NOT_:
			free = CheckReg();
			fprintf(f, "MOV %s , %s \n", free.reg, ptr->DATA->Arg1);
			fprintf(f, "NOT %s \n", free.reg);
			fprintf(f, "MOV %s , %s \n", ptr->DATA->Result, free.reg);
			free.used++;
			free.var = ptr->DATA->Arg2;
			ptr = ptr->Next;
			SetReg(free);
			break;
		case OPENFUNC_:
			fprintf(f,"    proc %s \n",ptr->DATA->Arg2);
			ptr = ptr->Next;
			break;
		case CLOSEFUNE_:
			fprintf(f,"RET\n");
			ptr = ptr->Next;
			break;
		case CALLFUNC_:
			fprintf(f,"PUSHA\ncall %s\n	POPA \n",ptr->DATA->Arg2);
			ptr = ptr->Next;
			break;
		
		default:
			break;
		}
	}
}
void ResetReg()
{
	int i;// for c
	for ( i = 0; i<7; i++)
	{
		Reg x;
		x.var = "0";
		x.used = 0;
		reg[i].used=x.used;
		reg[i].var=x.var;
	}
	reg[0].reg="R0";
	reg[1].reg="R1";
	reg[2].reg="R2";
	reg[3].reg="R3";
	reg[4].reg="R4";
	reg[5].reg="R5";
	reg[6].reg="R6";
	CurlyBraces[0]="L00";
	CurlyBraces[1]="L01";
	CurlyBraces[2]="L02";
	CurlyBraces[3]="L03";
	CurlyBraces[4]="L04";
	CurlyBraces[5]="L05";
	CurlyBraces[6]="L06";
	CurlyBraces[7]="L07";
}
void SetReg(Reg x)
{
	int i;
	for ( i = 0; i<7; i++)
	{
		if (reg[i].reg == x.reg)
		{
			reg[i].used = x.used;
			reg[i].var = x.var;
		}
	}
}
Reg CheckReg()
{
	Reg min = reg[0];
	if (min.var == "0")
	{
		return min;
	}
	else
	{
		int i;
		for ( i = 0; i<7; i++)
		{
			if (reg[i].var == "0")
			{
				return reg[i];
			}
			else if (reg[i].used < min.used)
			{
				min = reg[i];
			}
		}
		return min;
	}
}




/*int main()
{
	// -- TEST CASE
	SymbolData*rP = setSymbol(0, 5, false, 0, "X");
	pushSymbol(1, rP);
	pushSymbol(2, rP);
	pushSymbol(3, rP);
	pushSymbol(4, rP);
	getID("Y", 0);
	FILE *f = fopen("dummy.txt","w");
	PrintSymbolTable(f); DestroyList();
}*/