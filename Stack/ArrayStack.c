#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
	(*Stack)->Array = (DataType*)malloc(sizeof(DataType) * Capacity);
}

void AS_DestroyStack(ArrayStack* Stack)
{
	free(Stack->Array);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, DataType Data)
{
	Stack->Array[Stack->Top++] = Data;
}

DataType AS_Pop(ArrayStack* Stack)
{
	Stack->Top--;
	return Stack->Array[Stack->Top];
}

DataType AS_Top(ArrayStack* Stack)
{
	return Stack->Array[Stack->Top - 1];
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return Stack->Top == 0;
}