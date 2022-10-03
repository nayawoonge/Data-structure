#include <stdio.h>
#include <math.h>
#define MAX_terms 101

struct
{
	int coef;
	int expon;
}terms[MAX_terms]={{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};

float coefficient(int s, int e, int t)
{
	float coeff = 0.0;
	for (int i = s;i <= e;i++)
	{
		if (terms[i].expon == t)
			coeff = terms[i].coef;
	}
	return coeff;
}

double eval_poly(int s, int e, int x)
{
	double result = 0.0;
	for (int i = s; i <= e;i++)
		result += terms[i].coef * pow(x, terms[i].expon);
	return result;
}

int main(void)
{
	int As = 0, Ae = 2, Bs = 3, Be = 5;
	printf("3차수의 계수 : %f \n", coefficient(As, Ae, 3));
	printf("x가 2일때 다항식의 값 : %lf\n", eval_poly(Bs, Be, 2));
}
