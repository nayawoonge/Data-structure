#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _ListNode { 		// 노드 타입을 구조체로 정의한다.
	element data;
	struct _ListNode* link;
} ListNode;

ListNode* delete_node(ListNode* head, int value)
{
	ListNode* p;
	ListNode* removed = NULL;
	ListNode* pre = NULL;

	for (p = head; p != NULL; pre=p, p = p->link) 
	{
		if (p->data == value) 
		{
			if (p == head) 
			{
				removed = head;
				head = head->link;
			}
			else 
			{
				pre->link = p->link;
				free(p);
				p = pre;
			}
		}
	}
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p!=NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main()
{
	ListNode* head;
	head = (ListNode *)malloc(sizeof(ListNode));
	head->data = 2;

	ListNode* p1;
	p1= (ListNode *)malloc(sizeof(ListNode));
	p1->data = 3;
	p1->link = NULL;

	ListNode* p2;
	p2 = (ListNode *)malloc(sizeof(ListNode));
	p2->data = 3;

	ListNode* p3;
	p3 = (ListNode *)malloc(sizeof(ListNode));
	p3->data = 4;
	

	head->link = p1;
	p1->link = p2;
	p2->link = p3;
	p3->link = NULL;

	print_list(head);
	printf("\n");
	delete_node(head, 2);
	print_list(head);

	return 0;
}
