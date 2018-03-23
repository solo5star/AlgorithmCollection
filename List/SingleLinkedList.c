#include "SingleLinkedList.h"

SLL_Node* SLL_CreateNode(DataType Data)
{
	SLL_Node* NewNode = (SLL_Node*)malloc(sizeof(SLL_Node));

	NewNode->Data = Data;
	NewNode->Next = NULL;

	return NewNode;
}

void SLL_DestroyNode(SLL_Node* Node)
{
	free(Node);
}

void SLL_AppendNode(SLL_Node** Head, SLL_Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		SLL_Node* Current = *Head;

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = NewNode;
	}
}

void SLL_InsertAfter(SLL_Node* Current, SLL_Node* NewNode)
{
	NewNode->Next = Current->Next;
	Current->Next = NewNode;
}

void SLL_InsertNewHead(SLL_Node** Head, SLL_Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		NewNode->Next = *Head;
		*Head = NewNode;
	}
}

void SLL_RemoveNode(SLL_Node** Head, SLL_Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->Next;
		Remove->Next = NULL;
	}
	else
	{
		SLL_Node* Current = *Head;

		while(Current->Next != NULL && Current->Next != Remove)
		{
			Current = Current->Next;
		}

		if (Current->Next != NULL)
		{
			Current->Next = Remove->Next;
			Remove->Next = NULL;
		}
	}
}

SLL_Node* SLL_GetNodeAt(SLL_Node* Head, int Location)
{
	SLL_Node* Current = Head;

	while (Current->Next != NULL && Location--)
	{
		Current = Current->Next;
	}

	return Current;
}

int SLL_GetNodeCount(SLL_Node* Head)
{
	unsigned int Count = 0;
	SLL_Node* Current = Head;

	while (Current->Next != NULL)
	{
		Current = Current->Next;
		Count++;
	}

	return Count;
}