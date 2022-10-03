#include <stdio.h>


int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n;i++)
	{
		result = result * i;
	}
	return result;
}
int main()
{
	int num;
	num = 5;

	printf("%d ", factorial(num));

}