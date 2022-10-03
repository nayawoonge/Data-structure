#include <stdio.h>

double add(int n)
{
	if (n <= 0) return 0;
	else if (n == 1)
		return 1;
	else
		return (1 / (double)n + add(n - 1));
}

int main()
{
	printf("%f", add(2));
}