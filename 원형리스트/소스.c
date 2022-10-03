#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _ListNode { 	// ��� Ÿ��
	element data;
	struct _ListNode* link;
} ListNode;

// ���� ����Ʈ�� ���
void print_list(ListNode* tail)
{
	ListNode* p;
	p = tail;
	if (tail == NULL)
		return;
	else  if (tail->link == tail)
		printf("%d->", p->data);
	else {
		p = tail->link;
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p!=tail);
		printf("%d->", p->data); // ������ ���
	}
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}


ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;	// ����� ��� ������ ��ȯ
}

int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}
