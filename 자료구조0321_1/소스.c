#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 101

typedef struct
{
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

float coefficient(polynomial p, int t)
{
	return p.coef[(p.degree - t)];
}

int eval_poly(polynomial p, int x)
{
	int result = 0;
	for (int i = 0; i < (p.degree + 1);i++)
	{
		result += p.coef[i] * pow(x, p.degree - i);
	}
	return result;
}

int main()
{
	polynomial s = { 5, { 10,0,0,0,6,3} };

	printf("5의 차수의 계수 값 : %f \n", coefficient(s, 5));

	printf("x = 1 일때 다항식의 값 : %d", eval_poly(s, 1));
}