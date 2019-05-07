#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h> 
#pragma warning (disable : 4996)

typedef struct SymbolData
{
	int Type;	// representing the type of the token 
	bool Initilzation;//indicate the symbol Initilzed a value or not 
	bool Used;//indicate used or not as it needed in output 
	int BracesScope;//representing the scope number that the variable is decleared
	char * Value;// representing the value of assigned token
	char * IdentifierName;// The name of Varible
	bool Modifiable;// represent var constant or not 

}SymbolData;
//-------------------------------------------------Linked List Node -------------------------------
typedef struct SymbolNode {
	struct SymbolData * DATA;
	int ID;// representing the ID of the Symbol 
	struct SymbolNode *Next;
} SymbolNode;

//---------------------------------------- Needed Functions with the Linked List------------------
struct SymbolData* setSymbol(int type, int init, bool used, int brace, char * name,bool Modifiable);// Get a Symbol Entity
void pushSymbol(int ID, struct SymbolData* data);// to Insert a node in list
struct SymbolNode* getSymbolNODE();// to delete a node in list and return this node
int countNODE();// count the number of NODES
bool isEmpty();//Is the list empty?
struct SymbolData* getSymbol(int rID);// Return a Symbol Entity given his ID in LIST
void printList(SymbolNode*rHead);//Print the SymbolTable in a recussive way 
//void setValue(int index, char * value); //set a string numerical value for Symbol
//void setBrace(int rID);//-- Setters
void setUsed(int rID);
void setInitilization(int rID);

SymbolNode * getID(char * Identifiyer, int rBraceSCope);// given Variable NAME AND SCOPE return ID
bool CheckIDENTIFYER(char * ID);//check weather identifuer is defined before or not
// ----------------------------------------------PRINTING FUNCTIONS------------------------
void printUsed(FILE *f);
void printNotUsed(FILE *f);
void printInitilized(FILE *f);
void printNotInit(FILE *f);
void PrintSymbolTable(FILE*F);
int getSymbolType(char*rID);
