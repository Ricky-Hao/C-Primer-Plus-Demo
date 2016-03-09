//while.c -- 注意花括号的使用
#include <stdio.h>
int main(void)
{
	int n = 0;

	while (n < 3)
	{
		printf("n is %d\n", n);
		n++;
	}
	printf("That's all this program does.\n");
	getchar();
	return 0;
}
