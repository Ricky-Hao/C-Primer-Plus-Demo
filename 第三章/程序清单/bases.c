//bases.c -- 以十进制。八进制和十六进制形式输出
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
