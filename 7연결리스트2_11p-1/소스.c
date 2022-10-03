#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _ListNode { 	// 노드 타입
	element data;
	struct _ListNode* link;
} ListNode;

// 원형 리스트의 출력
void print_list(ListNode* tail)
{
	ListNode* p=NULL;

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
		printf("%d->", p->data); // 마지막 노드
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
	return head;	// 변경된 헤드 포인터 반환
}

ListNode* search(ListNode* head, element data)
{
	ListNode* p;
	if (head == NULL) return NULL;
	p = head->link;
	do {
		if (p->data == data) return p;   // element가 int이면 단순한 비교연산도 가능
		p = p->link;
	} while (p!=head);
	return NULL;
}
int get_size(ListNode* head)
{
	ListNode* p;
	int count = 0;
	if (head == NULL) return count;
	count++;
	p = head->link;
	while (p!=head) {
		count++;
		p = p->link;
	}
	return count;
}



int main(void)
{
	ListNode* p;
	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	
	p = search(head, 30);
	printf("\n특정 값 30 탐색 후 노드 데이터 출력 : %d \n", p->data);
	printf("\n노드 개수 출력 : %d \n", get_size(head));

	return 0;
}
