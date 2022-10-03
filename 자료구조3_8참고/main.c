#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define SIZE 20
int items = 0;
void insert(int array[], int loc, int value)
{
	for (int i = items;i >= loc;i--)
	{
		array[i] = array[i - 1];
	}
	array[loc] = value;
}

void get_integers(int list[])
{
	printf("%d개의 정수를 입력하시오.\n", SIZE);
	for (int i = 0; i < SIZE;i++)
	{
		scanf("%d", &list[i]);
	}
}

int main()
{
	int list[SIZE];
	int val;
	int loc;
	items = SIZE;
	get_integers(list);
	
	printf("현재 배열\n");
	for (int i = 0; i < SIZE;i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n임의의 위치 loc를 입력하세요. (0부터SIZE-1까지)\n");
	scanf("%d", &loc);
	printf("\n삽입할 정수 value를 입력하세요.\n");
	scanf("%d", &val);
	insert(list, loc, val);
	printf("바뀐 배열\n");
	for (int i = 0; i < SIZE;i++)
	{
		printf("%d ", list[i]);
	}

	return 0;
}