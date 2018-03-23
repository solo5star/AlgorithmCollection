#include "DoubleLinkedList.h"

DLL_Node* DLL_CreateNode(DataType Data)
{
	DLL_Node* NewNode = (DLL_Node*)malloc(sizeof(DLL_Node));

	NewNode->Data = Data;
	NewNode->Prev = NULL;
	NewNode->Next = NULL;

	return NewNode;
}

void DLL_DestroyNode(DLL_Node* Node)
{
	free(Node);
}

void DLL_AppendNode(DLL_Node** Head, DLL_Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		DLL_Node* Current = *Head;

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = NewNode;
		NewNode->Prev = Current;
	}
}

void DLL_InsertAfter(DLL_Node* Current, DLL_Node* NewNode)
{
	NewNode->Prev = Current;
	NewNode->Next = Current->Next;
	Current->Next->Prev = NewNode;
	Current->Next = NewNode;
}

void DLL_InsertBefore(DLL_Node* Current, DLL_Node* NewNode)
{
	NewNode->Next = Current;
	NewNode->Prev = Current->Prev;
	Current->Prev->Next = NewNode;
	Current->Prev = NewNode;
}

void DLL_InsertNewHead(DLL_Node** Head, DLL_Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		NewNode->Next = *Head;
		(*Head)->Prev = NewNode;
		*Head = NewNode;
	}
}

void DLL_RemoveNode(DLL_Node** Head, DLL_Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->Next;
		(*Head)->Prev = NULL;
		Remove->Next = NULL;
	}
	else
	{
		DLL_Node* Temp = Remove;

		Temp->Prev->Next = Temp->Next;
		if (Temp->Next != NULL)
		{
			Temp->Next->Prev = Temp->Prev;
		}

		Temp->Next = NULL;
		Temp->Prev = NULL;
	}
}

DLL_Node* DLL_GetNodeAt(DLL_Node* Head, int Location)
{
	DLL_Node* Current = Head;

	while (Current->Next != NULL && Location--)
	{
		Current = Current->Next;
	}

	return Current;
}

int DLL_GetNodeCount(DLL_Node* Head)
{
	unsigned int Count = 0;
	DLL_Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->Next;
		Count++;
	}

	return Count;
}