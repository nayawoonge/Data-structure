#include <stdio.h>
#include <math.h>
#define MAX_TERMS 101

struct
{
	float coef; //계수
	int expon; //차수
}terms[MAX_TERMS] = { {8,3},{7,1}, {1,0},{10,3},{3,2},{1,0}};

int avail = 6;

void print_poly(int s, int e)
{
	for (int i = s; i <= e;i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
}

float coefficient(int s, int e, int t)
{
	float coeff = 0.0;
	for (int i = s; i <= e;i++)
		if (terms[i].expon == t)
			coeff = terms[i].coef;
	return coeff;
}

double eval_poly(int s, int e, int x)
{
	double result = 0.0;
	for (int i = s; i <= e;i++)
		result = result + terms[i].coef * pow(x, terms[i].expon);
	return result;
}
int main()
{
	int As = 0, Ae = 2, Bs = 3, Be = 5;
	print_poly(As, Ae);
	printf("\n");
	print_poly(Bs, Be);
	printf("\n");

	printf("%f \n",coefficient(As, Ae, 1));
	printf("%lf \n", eval_poly(As, Ae, 2));
}