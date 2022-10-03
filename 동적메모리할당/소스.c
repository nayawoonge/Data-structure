#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));
	for (int i = 0;i < SIZE;i++)
		p[i] = i;
	for (int i = 0;i < SIZE;i++)
		printf("%d ", p[i]);
	free(p);

	return 0;
}