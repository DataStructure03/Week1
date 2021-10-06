#include "linkedlist.h"
#include <stdio.h>

void showLL(LinkedList *lst);
void createLLpList(LinkedList **lst, int amount);
ListNode createListNode(int data);

int main()
{
	LinkedList *lst = createLinkedList();

	createLLpList(&lst, 10);
	printf("[0 ~ 9까지 연결 리스트 생성]\n");
	showLL(lst);
	printf("getLinkedListLength() : %d\n", getLinkedListLength(lst));
	printf("[node.data == 100일 때 addLLElement(lst, 5, node)]\n");
	ListNode node = createListNode(100);
	addLLElement(lst, 5, node);
	showLL(lst);
	printf("removeLLElement(lst, 5)\n");
	removeLLElement(lst, 5);
	removeLLElement(lst, 9);
	showLL(lst);
	printf("clearLinkedList(lst)\n");
	clearLinkedList(lst);
	showLL(lst);
	printf("deleteLinkedList(lst)\n");
	deleteLinkedList(lst);
}