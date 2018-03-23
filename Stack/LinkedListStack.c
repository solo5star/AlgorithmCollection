#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	*Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	LLS_Node* Temp;
	LLS_Node* Current = Stack->List;

	while (Current != NULL)
	{
		Temp = Current;
		Current = Current->Prev;
		free(Temp);
	}

	free(Stack);
}

LLS_Node* LLS_CreateNode(DataType Data)
{
	LLS_Node* NewNode = (LLS_Node*)malloc(sizeof(LLS_Node));

	NewNode->Data = Data;
	NewNode->Prev = NULL;

	return NewNode;
}

void LLS_DestroyNode(LLS_Node* Node)
{
	free(Node);
}

void LLS_Push(LinkedListStack* Stack, LLS_Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		NewNode->Prev = Stack->List;
		Stack->List = NewNode;
	}
}

LLS_Node* LLS_Pop(LinkedListStack* Stack)
{
	LLS_Node* Temp = Stack->List;
	Stack->List = Stack->List->Prev;

	return Temp;
}

LLS_Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->List;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	LLS_Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->Prev;
		Count++;
	}

	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return Stack->List == NULL;
}