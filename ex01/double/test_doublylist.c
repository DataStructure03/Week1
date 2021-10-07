#include "doublylist.h"
#include <stdio.h>

int main()
{
	DoublyList *DL;

	DL = createDoublyList();
	for (int i = 0; i < 10; i++)
	{
		DoublyListNode node;
		node.data = i;
		addDLElement(DL, i, node);
	}
	displayDoublyList(DL);
	printf("current length : %d\n", DL->currentElementCount);
	int amendedIdx;
	amendedIdx = 5;
	{
		DoublyListNode node;
		node.data = amendedIdx + 100;
		addDLElement(DL, amendedIdx, node);
	}
	displayDoublyList(DL);
	removeDLElement(DL,1);
	displayDoublyList(DL);

  return 0;
}