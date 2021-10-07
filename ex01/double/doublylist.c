#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
	DoublyList *DL;

	DL = (DoublyList *)malloc(sizeof(DoublyList));
	if (DL == NULL)
		return NULL;
	DL->currentElementCount = 0;
	DL->headerNode.pLLink = NULL;
	DL->headerNode.pRLink = NULL;
  return DL;
}

void deleteDoublyList(DoublyList* pList)
{
  clearDoublyList(pList);
  free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *n;
	DoublyListNode *prev;
  DoublyListNode *cur;
  
	n = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	n->data = element.data;
	n->pLLink = NULL;
	n->pRLink = NULL;
  
  if (position == 0) {
    pList->headerNode.pRLink = n;
    n->pLLink = &(pList->headerNode);
  } else {
    prev = getDLElement(pList, position-1);
    n->pLLink = prev;
    n->pRLink = prev->pRLink;
    prev->pRLink = n;
    if (n->pRLink)
        n->pRLink->pLLink = n;
  }
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position) //예외처리 더 해야하긴 함
{
  DoublyListNode *cur;
  DoublyListNode *prev;
  DoublyListNode *next;

  cur = getDLElement(pList, position);
  prev = cur->pLLink;
  next = cur->pRLink;

  prev->pRLink = next;
  next->pLLink = prev;
  free(cur);
  cur = 0;
  pList->currentElementCount--;
  return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	for (int i = 0; i < pList->currentElementCount; i++){
		removeDLElement(pList, i);
	}
}

int getDoublyListLength(DoublyList* pList)
{
  return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
  DoublyListNode *ret;

  ret = pList->headerNode.pRLink;
  for (int i = 0; i < position; i++)
  {
    ret = ret->pRLink;
  }
  return ret;
}

void displayDoublyList(DoublyList* pList)
{
  DoublyListNode *tmp;

  tmp = pList->headerNode.pRLink;
  for (int i = 0; i < pList->currentElementCount; i++)
  {
    printf("%d > ", tmp->data);
    tmp = tmp->pRLink;
  }
  printf("END\n");
}
