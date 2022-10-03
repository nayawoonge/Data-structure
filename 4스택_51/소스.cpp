#include <stdio.h>
#include <string>
#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1)); //top이 max_stack_size -1 이면 1 아니면 0
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

int is_empty(StackType* s)
{
	return (s->top == -1); //top이 -1 이면 1 아니면 0
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

void main()
{
	char line[100];
	StackType s;
	init_stack(&s);
	printf("문자열을 입력하시오: ");
	gets_s(line, 100);
	for (int i = 0; i < (strlen(line) / 2); i++) //line의 왼쪽 절반을 스택에 넣음
	{
		push(&s, line[i]);
	}
	for (int i = (int)((strlen(line) / 2.0 + 0.5)); i < strlen(line); i++) 
	//스택에 넣은 것(line의 왼쪽 절반)과 오른쪽 절반을 비교, strlen(line)/2.0+0.5 절반보다 한칸더 int형으로 받음
	{

		if (pop(&s) != line[i])
		{
			printf("회문이 아닙니다.\n");
			return;
		}
	}
	printf("회문입니다.\n");
}
//회문(palindrome)이란 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다. 구두점, 스페이스, 대소문자 등은 무시하여야 한다.