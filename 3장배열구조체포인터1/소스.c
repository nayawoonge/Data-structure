#include <stdio.h>
#include <math.h>
int main(void)
{
	int three_square[8];
	for (int i = 0;i < 8;i++) 
	{
		three_square[i] = pow(3, i);
	}
	for (int i = 0;i < 8;i++) 
	{
		printf("3 ^ %d = %d \n", i, three_square[i]);
	}
}

