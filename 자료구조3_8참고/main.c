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
	printf("%d���� ������ �Է��Ͻÿ�.\n", SIZE);
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
	
	printf("���� �迭\n");
	for (int i = 0; i < SIZE;i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n������ ��ġ loc�� �Է��ϼ���. (0����SIZE-1����)\n");
	scanf("%d", &loc);
	printf("\n������ ���� value�� �Է��ϼ���.\n");
	scanf("%d", &val);
	insert(list, loc, val);
	printf("�ٲ� �迭\n");
	for (int i = 0; i < SIZE;i++)
	{
		printf("%d ", list[i]);
	}

	return 0;
}