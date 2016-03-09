//sweetie2.c -- 一个使用for的计数循环
#include <stdio.h>
int main(void)
{
	const int NUMBER = 22;
	int count;

	for (count = 1; count < +NUMBER; count++)
		printf("Be my Valentine!\n");
	getchar();
	return 0;
}
