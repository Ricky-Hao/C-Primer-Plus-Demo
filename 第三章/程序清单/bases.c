//bases.c -- ��ʮ���ơ��˽��ƺ�ʮ��������ʽ���
#include <stdio.h>
int main(void)
{
	int x;
	printf("Please enter a number.\n");
	scanf_s("%d", &x, 10);
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
	getchar();
	getchar();
	return 0;
}
