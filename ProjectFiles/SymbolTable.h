#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h> 

typedef enum { typeCon, typeId, typeOpr } nodeEnum;
typedef enum { Integer, Float, Char, String, Bool, ConstIntger, ConstFloat, ConstChar, ConstString, ConstBool } typeEnum;
typedef enum { Accepted, undeclared, Constant, OutOfScope } permission;// needed ?

typedef struct SymbolData
{
	int Type;	// representing the type of the token 
	bool Initilzation;//indicate the symbol Initilzed a value or not 
	bool Used;//indicate used or not as it needed in output 
	int BracesScope;//representing the scope number that the variable is decleared
	char * symValue;// representing the value of assigned token
	char * IdentifierName;// The name of Varible
	permission symPerm;//needed in debuging and report handles
		
}SymbolData;
//-------------------------------------------------Linked List Node -------------------------------
typedef struct SymbolNode {
	struct SymbolData * DATA;
	int ID;// representing the ID of the Symbol 
	struct SymbolNode *Next;
} SymbolNode;
//---------------------------------------- Needed Functions with the Linked List------------------
struct SymbolData* setSymbol(int type, int init, int used, int brace, char * name, permission perm);// Get a Symbol Entity
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
int getID(char * Identifiyer, int rBraceSCope);// given Variable NAME AND SCOPE return ID