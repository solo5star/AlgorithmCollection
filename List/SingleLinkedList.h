#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct _SLL_Node {
	DataType Data;
	struct _SLL_Node* Next;
}SLL_Node;

SLL_Node* SLL_CreateNode(DataType Data);
void SLL_DestroyNode(SLL_Node* Node);
void SLL_AppendNode(SLL_Node** Head, SLL_Node* NewNode);
void SLL_InsertAfter(SLL_Node* Current, SLL_Node* NewNode);
void SLL_InsertNewHead(SLL_Node** Head, SLL_Node *NewNode);
void SLL_RemoveNode(SLL_Node** Head, SLL_Node* Remove);
SLL_Node* SLL_GetNodeAt(SLL_Node* Head, int Location);
int SLL_GetNodeCount(SLL_Node* Head);

#endif