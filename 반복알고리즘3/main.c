#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int add(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", add(n));

}

int add(int n)
{
	int sum = 0;
	if (n < 3) return 0;
	else
	{
		for (int i = 1;i <= n;i++)
		{
			if (i % 3 == 0) sum += i;
		}
		return sum;
	}
}