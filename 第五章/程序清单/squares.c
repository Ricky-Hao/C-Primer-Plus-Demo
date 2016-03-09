//squares.c -- 产生前20个整数的平方表
#include <stdio.h>
int main(void)
{
	int num = 1;
	while (num < 20.5)
	{
		printf("%d %d\n", num, num*num);
		num = num + 1;
	}
	getchar();
	return 0;
}
