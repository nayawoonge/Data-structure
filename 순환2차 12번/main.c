#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int unknown();
int main(void)
{
	unknown();

	return 0;
}
int unknown()
{
	int ch;
	if ((ch = getchar()) != '\n')
		unknown();
	putchar(ch);
}