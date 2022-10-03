#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int bc(int n, int k);

int main(void)
{
	int n, k;
	printf("n과 k의 값을 입력하시오\n");
	scanf("%d %d", &n, &k);
	printf("%d", bc(n, k));
}
int bc(int n, int k)
{
	if (k == 0 || k == n) return 1;
	else return(bc(n - 1, k - 1) + bc(n - 1, k));
}