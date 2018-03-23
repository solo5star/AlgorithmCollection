#include "CircularLinkedList.h"

CLL_Node* CLL_CreateNode(DataType Data)
{
	CLL_Node* NewNode = (CLL_Node*)malloc(sizeof(CLL_Node));

	NewNode->Data = Data;
	NewNode->Prev = NULL;
	NewNode->Next = NULL;

	return NewNode;
}

void CLL_DestroyNode(CLL_Node* Node)
{
	free(Node);
}

void CLL_AppendNode(CLL_Node** Head, CLL_Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
		(*Head)->Next = *Head;
		(*Head)->Prev = *Head;
	}
	else
	{
		NewNode->Prev = (*Head)->Prev;
		NewNode->Next = *Head;

		(*Head)->Prev->Next = NewNode;
		(*Head)->Prev = NewNode;
	}
}

void CLL_InsertAfter(CLL_Node* Current, CLL_Node* NewNode)
{
	NewNode->Prev = Current;
	NewNode->Next = Current->Next;
	Current->Next->Prev = NewNode;
	Current->Next = NewNode;
}

void CLL_InsertBefore(CLL_Node* Current, CLL_Node* NewNode)
{
	NewNode->Next = Current;
	NewNode->Prev = Current->Prev;
	Current->Prev->Next = NewNode;
	Current->Prev = NewNode;
}

void CLL_InsertNewHead(CLL_Node** Head, CLL_Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		NewNode->Next = *Head;
		NewNode->Prev = (*Head)->Prev;
		(*Head)->Prev = NewNode;
		*Head = NewNode;
	}
}

void CLL_RemoveNode(CLL_Node** Head, CLL_Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head)->Next->Prev = (*Head)->Prev;
		*Head = Remove->Next;
		(*Head)->Prev = NULL;
		Remove->Next = NULL;
	}
	else
	{
		CLL_Node* Temp = Remove;

		Temp->Prev->Next = Temp->Next;
		Temp->Next->Prev = Temp->Prev;

		Temp->Next = NULL;
		Temp->Prev = NULL;
	}
}

CLL_Node* CLL_GetNodeAt(CLL_Node* Head, int Location)
{
	CLL_Node* Current = Head;

	while (Current->Next != NULL && Location--)
	{
		Current = Current->Next;
	}

	return Current;
}

int CLL_GetNodeCount(CLL_Node* Head)
{
	unsigned int Count = 0;
	CLL_Node* Current = Head;

	do
	{
		Current = Current->Next;
		Count++;
	} while (Current != Head);

	return Count;
}