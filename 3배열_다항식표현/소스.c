#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 101
typedef struct
{
	int degree; //최고차항 차수
	float coef[MAX_DEGREE];
}polynomial;

float coefficient(polynomial p, int t) //차수 t에서 계수를 읽는 함수
{
	float result = p.coef[p.degree - t];
	printf("%3.1f\n", result);
	return result;
}

double eval_poly(polynomial p, int x)
{
	double result = 0.0;
	for (int i = 0; i <= p.degree;i++)
		result = result + p.coef[i] * pow(x, p.degree-i);
	return result;
}

int main()
{
	polynomial a = { 5,{3,6,0,0,0,10} }; //최고차항 5 계수 3,6,0,0,0,10
	//3x^5 + 6x^4 +10
	printf("%lf", eval_poly(a, 2));
}