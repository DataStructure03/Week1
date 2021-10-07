#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

void showLL(LinkedList *lst);
//차수가 내림차순.
void polynomialAdd(LinkedList *a, LinkedList *b, LinkedList **c)
{
	ListNode *pA = a->headerNode.pLink;
	ListNode *pB = b->headerNode.pLink;
	int sum;

	int i = 0;
	while (pA && pB)
	{
		if (pA->degree == pB->degree)
		{
			sum = pA->coef + pB->coef;
			ListNode node;
			node.coef = sum;
			node.degree = pA->degree;
			addLLElement(*c, i++, node);
			pA = pA->pLink;
			pB = pB->pLink;
		}
		else if(pA->coef > pB->coef)
		{
			ListNode node;
			node.coef = pA->coef;
			node.degree = pA->degree;
			addLLElement(*c, i++, node);
			pA = pA->pLink;
		}
		else
		{
			ListNode node;
			node.coef = pB->coef;
			node.degree = pB->degree;
			addLLElement(*c, i++, node);
			pB = pB->pLink;
		}
	}
	for (; pA != NULL; pA = pA->pLink)
	{
		ListNode node;
		node.coef = pA->coef;
		node.degree = pA->degree;
		addLLElement(*c, i++, node);
	}
	for (; pB != NULL; pB = pB->pLink)
	{
		ListNode node;
		node.coef = pB->coef;
		node.degree = pB->degree;
		addLLElement(*c, i++, node);
	}
}

void showLL(LinkedList *lst)
{
	ListNode *cur = lst->headerNode.pLink;

	if (lst->headerNode.pLink == NULL)
		return ;
	for (; cur; cur=cur->pLink)
	{
		printf("%3.0dx^%d", cur->coef, cur->degree);
	}
	printf("\n");
}


int main(void)
{
	ListNode element;
	LinkedList *lst_a;
	LinkedList *lst_b;
	LinkedList *lst_c;

  lst_a = createLinkedList();
  lst_b = createLinkedList();
  lst_c = createLinkedList();

	element.coef = 3; element.degree = 12;
	addLLElement(lst_a,0,element);
	element.coef = 2; element.degree = 8;
	addLLElement(lst_a,1,element);
	element.coef = 1; element.degree = 0;
	addLLElement(lst_a,2,element);
	// element.coef = 3; element.degree = 12;
	// addLLElement(lst_a,3,element);
	printf("A = ");
	showLL(lst_a);

	element.coef = 8; element.degree = 12;
	addLLElement(lst_b,0,element);
	element.coef = -3; element.degree = 10;
	addLLElement(lst_b,1,element);
	element.coef = 10; element.degree = 6;
	addLLElement(lst_b,2,element);
	printf("B = ");
	showLL(lst_b);

	polynomialAdd(lst_a, lst_b, &lst_c);
	printf("A + B = ");
	showLL(lst_c);
}