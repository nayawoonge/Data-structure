#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

double add(int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("\n%lf", add(n));

}

double add(int n)
{
	double sum = 0;
	if (n == 0) return 0;
	else
	{
		for (int i = 1;i <= n;i++)
		{
			sum += ((double)1 / i);
		}
	}
	
	return sum;
}