#include <iostream>

int sub(int n);

int main(void)
{
	int n;
	std::cin >> n;
	std::cout << sub(n);

}
int sub(int n)
{
	int sum=0;
	if (n < 0) return 0;
	else
	{
		for (int i = n;i > 0;i = i - 3)
		{
			sum += i;
		}
	}
	return sum;
}