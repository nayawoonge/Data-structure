#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 노드의 타입
typedef struct _ListNode {
	int coef;
	int expon;
	struct _ListNode* link;
} ListNode;

// 리스트 헤더의 타입
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

// plist는 연결 리스트의 헤더를 가리키는 포인터, 
// coef는 계수, expon는 지수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)
		printf("오류");

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
		if (a->expon == b->expon) {   		// a의 차수 == b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  	// a의 차수 > b의 차수 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {				// a의 차수 < b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)  // a중 남아있는 항들을 모두 결과 다항식으로 복사
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)  // b중 남아있는 항들을 모두 결과 다항식으로 복사
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

//다항식 값 계산
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


//다항식 곱셈
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

	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
	list4 = create();

	// 다항식 1을 생성 
	insert_last(list1, 3, 2);
	insert_last(list1, 2, 1);
	insert_last(list1, 1, 0);

	// 다항식 2를 생성 
	insert_last(list2, 8, 3);
	insert_last(list2, -3, 1);
	insert_last(list2, 10, 0);

	poly_print(list1);
	poly_print(list2);

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);

	//다항식3 의 실수 x에 대하여 다항식의 값
	//poly_eval(list3, 2);
	printf("다항식의 값 %lf\n", poly_eval(list3, 2));

	//다항식4 = 다항식 1 * 다항식 2
	poly_mul(list1, list2, list4);
	poly_print(list4);


	free(list1); free(list2); free(list3);
}

