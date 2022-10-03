#include <stdio.h>

int add(int n)
{
	if (n < 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return n + add(n - 1);
}

int main()
{
	printf("%d", add(10));
}