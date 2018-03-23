#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct _LLS_Node {
	DataType Data;
	struct _LLS_Node* Prev;
}LLS_Node;

typedef struct _LinkedListStack {
	LLS_Node* List;
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);
LLS_Node* LLS_CreateNode(DataType Data);
void LLS_DestroyNode(LLS_Node* Node);
void LLS_Push(LinkedListStack* Stack, LLS_Node* NewNode);
LLS_Node* LLS_Pop(LinkedListStack* Stack);
LLS_Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

#endif