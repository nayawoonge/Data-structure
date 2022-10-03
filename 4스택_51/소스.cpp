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
	return (s->top == (MAX_STACK_SIZE - 1)); //top�� max_stack_size -1 �̸� 1 �ƴϸ� 0
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

int is_empty(StackType* s)
{
	return (s->top == -1); //top�� -1 �̸� 1 �ƴϸ� 0
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

void main()
{
	char line[100];
	StackType s;
	init_stack(&s);
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(line, 100);
	for (int i = 0; i < (strlen(line) / 2); i++) //line�� ���� ������ ���ÿ� ����
	{
		push(&s, line[i]);
	}
	for (int i = (int)((strlen(line) / 2.0 + 0.5)); i < strlen(line); i++) 
	//���ÿ� ���� ��(line�� ���� ����)�� ������ ������ ��, strlen(line)/2.0+0.5 ���ݺ��� ��ĭ�� int������ ����
	{

		if (pop(&s) != line[i])
		{
			printf("ȸ���� �ƴմϴ�.\n");
			return;
		}
	}
	printf("ȸ���Դϴ�.\n");
}
//ȸ��(palindrome)�̶� �յ� ��� �ʿ��� �о ���� �ܾ �ǹ��Ѵ�. ������, �����̽�, ��ҹ��� ���� �����Ͽ��� �Ѵ�.