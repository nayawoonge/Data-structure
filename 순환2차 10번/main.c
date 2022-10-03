#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int recursive(int n);
int main(void)
{
	recursive(5);

	return 0;
}
recursive(int n)
{
	if (n != 1) recursive(n - 1);
	printf("%d\n", n);
}