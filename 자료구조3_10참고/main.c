#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define SIZE 20

int items = 0;
/*
void get_integers(int list[])
{
	printf("%d개의 정수를 입력하시오.", SIZE);
	for (int i = 0; i < SIZE;i++)
	{
		scanf("%d", &list[i]);
	}
}
*/
int delete(int array[], int loc) 
{
	int value = array[loc];
	for (int i = loc; i < SIZE; i++)
		array[i]=array[i+1];
	items--;
	return value;
}


int main(void)
{
	int list[SIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int val;
	items = SIZE;
	//get_integers(list);
	
	val = delete(list, 5);
	printf("삭제한 값 %d\n", val);
	printf("삭제한 후 배열 \n");
	for (int i = 0;i < items;i++)
		printf("%d ", list[i]);
	return 0;
}
