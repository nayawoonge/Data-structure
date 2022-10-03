#include <stdio.h>
#include <stdlib.h>

typedef int element;

// ���߿��� ��� Ÿ�� 
typedef struct _DListNode {
	element data;
	struct _DListNode* llink;
	struct _DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� ����
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;		// (1)
	newnode->rlink = before->rlink;	// (2)
	before->rlink->llink = newnode;	// (3)
	before->rlink = newnode;		// (4)
}

// ��� removed�� ����
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
		if (p->data==data) return p;  // element�� int�̹Ƿ� �ܼ��� �񱳿��� ����
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
	printf("����Ʈ�� �׸���� % d �Դϴ�.\n", get_size(head));
	element data;
	printf("Ž���� ��: ");
	scanf_s("%d", &data);
	if (search(head, data) != NULL)
		printf("���� ����Ʈ �ȿ� �ֽ��ϴ�. \n ");
	else
		printf("���� ����Ʈ �ȿ� �����ϴ�. \n ");
	return 0;
}

