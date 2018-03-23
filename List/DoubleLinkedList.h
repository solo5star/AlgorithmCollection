#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct _DLL_Node {
	DataType Data;
	struct _DLL_Node* Prev;
	struct _DLL_Node* Next;
}DLL_Node;

DLL_Node* DLL_CreateNode(DataType Data);
void DLL_DestroyNode(DLL_Node* Node);
void DLL_AppendNode(DLL_Node** Head, DLL_Node* NewNode);
void DLL_InsertAfter(DLL_Node* Current, DLL_Node* NewNode);
void DLL_InsertBefore(DLL_Node* Current, DLL_Node* NewNode);
void DLL_InsertNewHead(DLL_Node** Head, DLL_Node* NewNode);
void DLL_RemoveNode(DLL_Node** Head, DLL_Node* Remove);
DLL_Node* DLL_GetNodeAt(DLL_Node* Head, int Location);
int DLL_GetNodeCount(DLL_Node* Head);

#endif