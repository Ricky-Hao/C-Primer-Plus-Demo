//badcount.c -- 不正确的参数
#include <stdio.h>
int main(void)
{
	int f = 4;
	int g = 5;
	float h = 5.0f;
	printf("%d\n", f, g);
	printf("%d %d\n", f);
	printf("%d %f\n", h, g);
	getchar();
	return 0;
}
