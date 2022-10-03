#include <stdio.h>
#define SIZE 20
int items = 0;

void insert(int array[], int loc, int value) 
{
	for (int i = items; i >= loc; i--)
		array[i+1]=array[i];
	array[loc] = value;
}

int delete(int array[], int loc) {
	int value = array[loc];
	for (int i = loc; i < items; i++)
		array[i]=array[i+1];
	items--;
	return value;
}

int main(void) 
{
	int list[SIZE] = {1,5,4,6,7,8,9,12,11,10};
	int val;
	items = SIZE;
	val = delete(list, 5);
	insert(list, 6, val);

	for (int i = 0; i < items; i++)
		printf("%d ", list[i]);
	return 0;
}
