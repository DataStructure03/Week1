#include "reverseLList.h"


void showLL(LinkedList *lst);
void createLLpList(LinkedList **lst, int amount);
ListNode createListNode(int data);

int main()
{
    LinkedList *lst = createLinkedList();
	createLLpList(&lst, 10);
	printf("[0 ~ 9까지 연결 리스트 생성]\n");
	showLL(lst);
    ListNode *q = reverse(&(lst->headerNode));
    for (int i = 0; i < lst->currentElementCount; i++){
        printf("%d ", q->data);
        q = q->pLink;
        if (i != lst->currentElementCount-1)
            printf("> ");
    }
    printf("\n");
    return (0);
}