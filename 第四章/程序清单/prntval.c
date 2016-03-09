//prntval.c -- 发现printf()函数的返回值
#include <stdio.h>
int main(void)
{
	int bph2o = 212;
	int rv;
	rv = printf("%d F is water's boiling point.\n", bph2o);
	printf("The printf() fuction printed %d characters.\n", rv);
	getchar();
	return 0;
}
