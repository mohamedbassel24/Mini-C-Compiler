#include"SymbolTable.h"
struct SymbolNode * ListTop = NULL;
struct SymbolData* setSymbol(int rType, int rValue, int rUsed, int Scope, char * Identifyier, permission perm)
{
	struct SymbolData *data = (struct SymbolData*) malloc(sizeof(struct SymbolData));
	data->Type = rType;
	data->Initilzation = rValue;
	data->Used = rUsed;
	data->BracesScope = Scope;
	strcpy(data->IdentifierName, Identifyier);
	data->symPerm = perm;

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
	if (!ListTop)return nullptr;
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
	return nullptr;
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
	strcpy(rData->IdentifierName, Value);
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