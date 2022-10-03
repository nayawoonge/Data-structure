#include <stdio.h>


int factorial(int n)
{
	if (n <= 1) return 1;
	else return n*factorial(n - 1);
}

int main()
{
	int num = 5;

	printf("%d ", factorial(num));

	return 0;
}