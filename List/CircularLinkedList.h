#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct _CLL_Node {
	DataType Data;
	struct _CLL_Node* Prev;
	struct _CLL_Node* Next;
}CLL_Node;

CLL_Node* CLL_CreateNode(DataType Data);
void CLL_DestroyNode(CLL_Node* Node);
void CLL_AppendNode(CLL_Node** Head, CLL_Node* NewNode);
void CLL_InsertAfter(CLL_Node* Current, CLL_Node* NewNode);
void CLL_InsertBefore(CLL_Node* Current, CLL_Node* NewNode);
void CLL_InsertNewHead(CLL_Node** Head, CLL_Node* NewNode);
void CLL_RemoveNode(CLL_Node** Head, CLL_Node* Remove);
CLL_Node* CLL_GetNodeAt(CLL_Node* Head, int Location);
int CLL_GetNodeCount(CLL_Node* Head);

#endif