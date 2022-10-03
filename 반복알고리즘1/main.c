#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int add(int n);
int sum = 0;
int main(void)
{
	int n;
	scanf("%d",&n);
	printf("%d", add(n));

}

int add(int n)
{
	for (int i = 0;i <= n;i++)
	{
		sum += i;
	}
	return sum;
}