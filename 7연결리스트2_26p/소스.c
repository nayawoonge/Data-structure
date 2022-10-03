#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 이중연결 노드 타입 
typedef struct _DListNode {
	element data;
	struct _DListNode* llink;
	struct _DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;		// (1)
	newnode->rlink = before->rlink;	// (2)
	before->rlink->llink = newnode;	// (3)
	before->rlink = newnode;		// (4)
}

// 노드 removed를 삭제
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;		// (1)
	removed->rlink->llink = removed->llink;		// (2)
	free(removed);
}

int get_size(DListNode* head)
{
	DListNode* p;
	int count = 0;
	for (p = head->rlink; p!=head ; p = p->rlink) {
		count++;
	}
	return count;
}
DListNode* search(DListNode* head, element data)
{
	DListNode* p;
	for (p = head->rlink ; p!=head; p = p->rlink) 
	{
		if (p->data==data) return p;  // element가 int이므로 단순한 비교연산 가능
	}
	return  NULL;
}
void print_dlist_reverse(DListNode* head)
{
	DListNode* p;
	for (p=head->llink; p!=head ; p = p->llink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	dinsert(head, 1);
	dinsert(head, 2);
	dinsert(head, 3);
	print_dlist(head);
	print_dlist_reverse(head);
	printf("리스트의 항목수는 % d 입니다.\n", get_size(head));
	element data;
	printf("탐색할 값: ");
	scanf_s("%d", &data);
	if (search(head, data) != NULL)
		printf("값이 리스트 안에 있습니다. \n ");
	else
		printf("값이 리스트 안에 없습니다. \n ");
	return 0;
}

