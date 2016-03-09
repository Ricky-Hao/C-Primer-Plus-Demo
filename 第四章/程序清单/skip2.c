//skip2.c -- 跳过输入的头两个整数
#include <stdio.h>
int main(void)
{
	int n;

	printf("Please enter three integers: \n");
	scanf_s("%*d %*d %d", &n);
	printf("The last integersis %d .\n", n);
	getchar();
	getchar();
	return 0;
}
