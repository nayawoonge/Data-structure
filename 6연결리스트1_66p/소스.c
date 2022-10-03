#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct struct_ListNode {
    int coef;
    int expon;
    struct struct_ListNode* link;
}ListNode;

typedef struct {
    int size;
    ListNode* head;
    ListNode* tail;
}ListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if (temp == NULL) error("메모리 할당 에러");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = plist->tail->link;
    }
    plist->size++;
}

int expon_value(int e, int x) {
    int sum = 1;
    for (int i = 0; i < e; i++) {
        sum *= x;
    }
    return sum;
}
// 다항식 값 계산하는 함수
int poly_eval(ListType* plist, int x) {
    ListNode* p;
    int sum = 0;
    for (p = plist->head; p != NULL; p = p->link) {
        sum += p->coef * expon_value(p->expon, x);
    }
    return sum;
}
// 다향식 출력하는 함수
void printlist(ListType* plist) {
    for (ListNode* p = plist->head; p != NULL; p = p->link) {
        printf("%dx^%d ", p->coef, p->expon);
        if (p->link != NULL) printf("+ ");
    }
    printf("\n");
}
//두 다항식을 곰셉하는 함수 작성
void poly_mul(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* p1;
    ListNode* p2;
    ListNode* p3;

    for (p1 = plist1->head; p1 != NULL; p1 = p1->link) {
        for (p2 = plist2->head; p2 != NULL; p2 = p2->link) {
            int check = 0;
            int c = p1->coef * p2->coef;
            int e = p1->expon + p2->expon;

            if (plist3->tail == NULL && plist3->head == NULL) {
                ListNode* new = (ListNode*)malloc(sizeof(ListNode));
                new->coef = c;
                new->expon = e;
                plist3->head = plist3->tail = new;
                plist3->size++;
            }
            else {
                for (p3 = plist3->head; p3 != NULL; p3 = p3->link) {
                    if (p3->expon == e) { p3->coef += c; check = 1; };
                }
                if (check == 0) {
                    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
                    new->coef = c;
                    new->expon = e;
                    plist3->tail->link = new;
                    plist3->tail = new;
                    plist3->size++;
                }
            }
        }
    }
}

int main() {
    ListType* list1;
    ListType* list2;
    ListType* list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_last(list1, 3, 2);
    insert_last(list1, 2, 1);
    insert_last(list1, 1, 0);

    insert_last(list2, 1, 2);
    insert_last(list2, 2, 1);
    insert_last(list2, 3, 0);

    printf("list1의 내용 출력\n");
    printlist(list1);
    printf("list2의 내용 출력\n");
    printlist(list2);

    printf("list1의 x 값이 2일 때 결과 값 : %d\n", poly_eval(list1, 2));

    printf("list1과 list2의 다항식 곱셈한 결과 list3 출력\n");
    poly_mul(list1, list2, list3);
    printlist(list3);

    return 0;
}