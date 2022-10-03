#include <iostream>

int factorial(int n);

int main(void)
{
	int bc, n, k;
	std::cin >> n >> k;
	if (n < k) false;
	else
	{
		bc = factorial(n) / (factorial(k) * factorial(n - k));
		std::cout << bc;
	}
}

int factorial(int n)
{
	int ft = 1;
	for (int i = n;i > 0;i--)
	{
		ft = ft * i;
	}
	return ft;

}