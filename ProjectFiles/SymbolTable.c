#include"SymbolTable.h"
struct SymbolNode * ListTop = NULL;
char* idtype[10] = { "Integer", "Float", "Char", "String", "Bool", "ConstIntger", "ConstFloat", "ConstChar", "ConstString", "ConstBool" };
struct SymbolData* setSymbol(int rType, int rValue, bool rUsed, int Scope,char* Identifyier)
{
	struct SymbolData *data = (struct SymbolData*) malloc(sizeof(struct SymbolData));
	data->Type = rType;
	data->Initilzation = rValue;
	data->Used = rUsed;
	data->BracesScope = Scope;
	data->IdentifierName = Identifyier;
	//strcpy_s(data->IdentifierName , strlen(Identifyier), Identifyier);
	//data->IdentifierName =strdup( Identifyier);
	//data->symPerm = perm;

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

SymbolNode* getSymbolNODE() {
	if (!ListTop)return NULL;
	SymbolNode * SymbolPtr = ListTop;
	// Move The head then
	ListTop = ListTop->Next;
	return SymbolPtr;
}


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
int getID(char * Identifiyer, int rBraceSCope)
{
	SymbolNode * Walker = ListTop;
	int index = -1;

	//start from the beginning
	while (Walker)
	{
		if (strcmp(Identifiyer, Walker->DATA->IdentifierName)==0 && Walker->DATA->BracesScope==rBraceSCope)
		{
			return Walker->ID;
		}

		Walker = Walker->Next;
	}

	return-1;
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
/*void DestroyList()
{
	SymbolNode * Walker = ListTop;

	while (Walker)
	{
		SymbolNode *rD = Walker;
		Walker = Walker->Next;
		delete rD;

	}
	
}*/
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