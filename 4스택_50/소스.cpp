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
	return (s->top == (MAX_STACK_SIZE - 1)); 
	//top�� max_stack_size -1 �̸� 1 �ƴϸ� 0
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

int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int count = 0, pnumber = 0;
	int i;
	int n = strlen(in);
	init_stack(&s);
	for (i = 0; i < n; i++) 
	{
		ch = in[i];
		switch (ch) 
		{
		case '(': case '[': case '{':
			printf("%d", ++count);
			pnumber = count;
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) 
			{ 
				printf("\n�����Դϴ�.");
				return 0; 
			}
			else 
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) 
				{
					printf("\n�����Դϴ�.");
					return 0;
				}
				else 
				{
					printf("%d", pnumber--);
				}

			}
			break;
		}  // switch
	} // for
	if (!is_empty(&s)) 
		printf("\n�����Դϴ�."); //������ ���� ������ ����
	else
		printf("\n�����Դϴ�.");
}
int main(void)
{
	char line[100];
	printf("����: ");
	gets_s(line, 100);
	printf("��ȣ��ȣ: ");
	check_matching(line);
	return 0;
}

//gets_s �Լ��� ǥ�� �Է¿��� ���ڿ��� �Է¹޾Ƽ� �迭�̳� �����Ϳ� ����
//���� Ű�� ������ �Է��� ������ ���� ���� \n�� ������� �ʰ� ��\0���� �ٿ���