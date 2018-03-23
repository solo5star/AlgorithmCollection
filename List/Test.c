#include <stdio.h>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "CircularLinkedList.h"

int main()
{
	// SingleLinkedList
	//
	// [Data|Next]->[Data|Next]->[Data|Next]->NULL
	printf("\nTesting SingleLinkedList...\n");
	SLL_Node* SLL_List = NULL;
	for (int i = 0; i < 20; i++)
	{
		SLL_AppendNode(&SLL_List, SLL_CreateNode(i * 10));
	}
	SLL_InsertAfter(SLL_GetNodeAt(SLL_List, 5), SLL_CreateNode(99));
	SLL_RemoveNode(&SLL_List, SLL_GetNodeAt(SLL_List, 10));

	printf("--- Print Start ---\n");

	SLL_Node* SLL_Current = SLL_List;
	while (SLL_Current != NULL)
	{
		printf("%d ", SLL_Current->Data);

		SLL_Current = SLL_Current->Next;
	}

	printf("\n--- Print End ---\n");

	// DoubleLinkedList
	//
	// [Prev|Data|Next]--[Prev|Data|Next]--[Prev|Data|Next]-NULL
	printf("\nTesting DoubleLinkedList...\n");
	DLL_Node* DLL_List = NULL;
	for (int i = 0; i < 20; i++)
	{
		DLL_AppendNode(&DLL_List, DLL_CreateNode(i * 10));
	}
	DLL_InsertAfter(DLL_GetNodeAt(DLL_List, 5), DLL_CreateNode(99));
	DLL_RemoveNode(&DLL_List, DLL_GetNodeAt(DLL_List, 10));

	printf("--- Print Start ---\n");
	
	DLL_Node* DLL_Current = DLL_List;
	while (DLL_Current != NULL)
	{
		printf("%d ", DLL_Current->Data);

		DLL_Current = DLL_Current->Next;
	}

	printf("\n--- Print End ---\n");

	// CircularLinkedList
	//
	// ...--[Prev|Data|Next]--[Prev|Data|Next]--[Prev|Data|Next]--...
	printf("\nTesting CircularLinkedList...\n");
	CLL_Node* CLL_List = NULL;
	for (int i = 0; i < 20; i++)
	{
		CLL_AppendNode(&CLL_List, CLL_CreateNode(i * 10));
	}
	CLL_InsertAfter(CLL_GetNodeAt(CLL_List, 5), CLL_CreateNode(99));
	CLL_RemoveNode(&CLL_List, CLL_GetNodeAt(CLL_List, 10));
	
	printf("--- Print Start ---\n");

	CLL_Node* CLL_Current = CLL_List;
	do
	{
		printf("%d ", CLL_Current->Data);

		CLL_Current = CLL_Current->Next;
	} while (CLL_Current != CLL_List);

	printf("\n--- Print End ---\n");

	system("pause");

	return 0;
}