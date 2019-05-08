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
		if ((strcmp(Identifiyer, Walker->DATA->IdentifierName)==0 ) && (Walker->DATA->BracesScope !=-1 ) )
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