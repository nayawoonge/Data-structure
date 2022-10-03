#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ����� Ÿ��
typedef struct _ListNode {
	int coef;
	int expon;
	struct _ListNode* link;
} ListNode;

// ����Ʈ ����� Ÿ��
typedef struct {
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return  plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, 
// coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)
		printf("����");

	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   		// a�� ���� == b�� ����
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  	// a�� ���� > b�� ���� 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {				// a�� ���� < b�� ����
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)  // a�� �����ִ� �׵��� ��� ��� ���׽����� ����
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)  // b�� �����ִ� �׵��� ��� ��� ���׽����� ����
		insert_last(plist3, b->coef, b->expon);
}


void poly_print(ListType* plist)
{
	ListNode* p;

	printf("polynomial = ");
	for (p = plist->head; p != NULL; p = p->link) {
		printf("%d x^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

//���׽� �� ���
double poly_eval(ListType* plist, double x)
{
	ListNode* p;
	double	result = 0.0;
	double temp;

	for (p = plist->head; p != NULL; p = p->link) {
		temp = pow(x, p->expon);
		result += temp*p->coef;
	}
	return result;
}


//���׽� ����
void poly_mul(ListType* plist1, ListType *plist2, ListType *plist4)
{
	int exp[100] = (int*)malloc(sizeof(int)*100);
	int count = 0;
	ListNode* a = plist1->head;
	while (a != NULL)
	{
		ListNode* b = plist2->head;
		while (b != NULL)
		{
			int c = a->coef * b->coef;
			int e = a->expon + b->expon;
			exp[count] = e;
			insert_last(plist4, c, e);
			b = b->link;
			count++;
		}
		a = a->link;
	}
	ListNode* c = plist4->head;
	for (int i = 0;i < count;i++)
	{
		if (exp[i] == c->expon)
		{

		}
	}
}



int main(void) {
	ListType* list1, * list2, * list3, * list4;

	// ���� ����Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create();
	list4 = create();

	// ���׽� 1�� ���� 
	insert_last(list1, 3, 2);
	insert_last(list1, 2, 1);
	insert_last(list1, 1, 0);

	// ���׽� 2�� ���� 
	insert_last(list2, 8, 3);
	insert_last(list2, -3, 1);
	insert_last(list2, 10, 0);

	poly_print(list1);
	poly_print(list2);

	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(list1, list2, list3);
	poly_print(list3);

	//���׽�3 �� �Ǽ� x�� ���Ͽ� ���׽��� ��
	//poly_eval(list3, 2);
	printf("���׽��� �� %lf\n", poly_eval(list3, 2));

	//���׽�4 = ���׽� 1 * ���׽� 2
	poly_mul(list1, list2, list4);
	poly_print(list4);


	free(list1); free(list2); free(list3);
}

