//addemup.c -- 4种类型的语句
#include <stdio.h>
int main(void)
{
	int count, sum;
	count = 0;
	sum = 0;
	while (count++ < 20)
		sum = sum + count;
	printf("sum = %d\n", sum);
	getchar();
	return 0;
}
