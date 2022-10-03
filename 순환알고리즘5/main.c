#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

ak(int m, int n);

int main(void)
{
	int m, n;
	printf("m,n의 값을 입력하시오\n");
	scanf("%d %d", &m, &n);
	printf("%d", ak(m, n));

}

ak(int m, int n)
{
	if (m == 0) return n + 1;
	else if (n == 0) return ak(m - 1, n);
	else if (m >= 1 && n >= 1) return(ak(m - 1, ak(m, n - 1)));

}
/*
ak(int m, int n)
{
	if(n==0) return ak(m-1,n);
	else if(m==0) return n+1;
	else if (m >= 1 && n >= 1) return(ak(m - 1, ak(m, n - 1)));
}
*/