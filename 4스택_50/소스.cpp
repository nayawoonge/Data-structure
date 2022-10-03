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
	//top이 max_stack_size -1 이면 1 아니면 0
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
				printf("\n오류입니다.");
				return 0; 
			}
			else 
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) 
				{
					printf("\n오류입니다.");
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
		printf("\n오류입니다."); //스택이 남아 있으면 오류
	else
		printf("\n정상입니다.");
}
int main(void)
{
	char line[100];
	printf("수식: ");
	gets_s(line, 100);
	printf("괄호번호: ");
	check_matching(line);
	return 0;
}

//gets_s 함수는 표준 입력에서 문자열을 입력받아서 배열이나 포인터에 저장
//엔터 키를 누르면 입력이 끝나며 개행 문자 \n은 저장되지 않고 ‘\0’를 붙여줌