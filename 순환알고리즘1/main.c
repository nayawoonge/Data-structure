#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int add(int a);
int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d", add(a));
	
}

int add(int a)
{
	if (a == 1) return 1;
	else return(a + add(a - 1));
}