#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

double add(double a);

int main(void)
{
	double a;
	scanf("%lf", &a);
	printf("%lf", add(a));

}

double add(double a)
{
	if (a == 1) return 1;
	else return((double)1 / a + add(a - 1));
}