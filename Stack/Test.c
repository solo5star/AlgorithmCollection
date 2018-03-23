#include <stdio.h>
#include "ArrayStack.h"
#include "LinkedListStack.h"

int main()
{
	// ArrayStack
	//
	// [][][][][][][][][][][][][][][][]
	printf("\nTesting ArrayStack...\n");
	ArrayStack* AS_Stack;
	AS_CreateStack(&AS_Stack, 50);
	for (int i = 0; i < 50; i++)
	{
		AS_Push(AS_Stack, i * 10);
	}
	for (int i = 0; i < 5; i++)
	{
		AS_Pop(AS_Stack);
	}

	printf("--- Print Start ---\n");
	while (!AS_IsEmpty(AS_Stack))
	{
		printf("%d ", AS_Pop(AS_Stack));
	}
	printf("\n--- Print End ---\n");

	// LinkedListStack
	//
	// [Prev|Data]<-[Prev|Data]<-[Prev|Data]
	printf("\nTesting LinkedListStack...\n");
	LinkedListStack* LLS_Stack;
	LLS_CreateStack(&LLS_Stack);
	for (int i = 0; i < 50; i++)
	{
		LLS_Push(LLS_Stack, LLS_CreateNode(i * 10));
	}
	for (int i = 0; i < 5; i++)
	{
		LLS_Pop(LLS_Stack);
	}

	printf("--- Print Start ---\n");
	while (!LLS_IsEmpty(LLS_Stack))
	{
		printf("%d ", LLS_Pop(LLS_Stack)->Data);
	}
	printf("\n--- Print End ---\n");
	
	system("pause");

	return 0;
}