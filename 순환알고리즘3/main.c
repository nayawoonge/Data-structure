#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int add(int a);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d", add(a));

}
int add(int a) //�Ʒ� �Լ��� �ٸ��� ������ �����ϰ� �ɾ �Լ�ȣ�� Ƚ���� ����
{
	if (a < 0) return 0;
	else if (a % 3 == 1) return(add(a - 1));
	else if (a % 3 == 2) return(add(a - 2));
	else return(a + add(a - 3));	
}

/*
int add(int a)
{
	if (a < 0) return 0; // ������ ���� �߻��ϴ� ���� ��������
	else if (a < 3) return 0;
	else if (a % 3 == 0) return(a + add(a - 1));
	else return(add(a - 1));
	
}
*/