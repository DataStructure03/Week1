#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(void)
{
	ArrayList *pList = NULL;
	ArrayListNode *pValue = NULL;

	int size;
	printf("Enter Max Size of ArrayList : ");
	scanf("%d", &size);
	pList = createArrayList(size);
	while (1)
	{
		int menu;
		int x;
		int idx;
		printf("(1) ADD (2) DELETE (3) PRINT (4) CLEAR (5) COUNT (0)EXIT : ");
		scanf("%d", &menu);
		if (menu == 1)
		{
			ArrayListNode node;
			printf("Enter Add index : ");
			scanf("%d", &idx);
			printf("Enter Add Number : ");
			scanf("%d", &(node.data));
			addALElement(pList, idx, node);
		}
		else if (menu == 2)
		{
			printf("Enter Delete index : ");
			scanf("%d", &idx);
			removeALElement(pList, idx);
		}
		else if (menu == 3)
		{
			displayArrayList(pList);
		}
		else if (menu == 4)
		{
			clearArrayList(pList);
		}
		else if (menu == 5)
		{
			int arrayCount = getArrayListLength(pList);
			for (int i = 0; i < arrayCount; i++)
			{
				pValue = getALElement(pList, i);
				printf("위치[%d]-%d\n", i, pValue->data);
			}
		}
		else
		{
			break;
		}
	}
	deleteArrayList(pList);
	return (0);
}