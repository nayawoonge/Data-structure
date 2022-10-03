#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct test
{
	int i;
	char str[20];
};

int main(void)
{
	
	struct test* p;

	p = (struct test*)malloc(sizeof(struct test));
	if (p == NULL) {
		printf("memory error");
		return;
	}
	p->i = 100;
	strcpy(p->str, "just testing");

	printf("%d\n", p->i);
	printf("%s\n", p->str);
	free(p);
}
