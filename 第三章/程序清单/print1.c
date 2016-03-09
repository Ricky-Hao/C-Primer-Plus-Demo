//print1.c -- 说明printf()的一些属性
#include <stdio.h>
int main(void)
{
	int n1;
	int n2;
	printf("Please entre two number.\n");
	scanf_s("%d", &n1,10);
	scanf_s("%d", &n2,10);
	printf("%d minus %d is %d\n", n1, n2, n1 - n2);
	printf("The follow is wrong.\n");
	printf("%d minus %d is %d\n", n1);
	getchar();
	getchar();
	getchar();
	return 0;
}
