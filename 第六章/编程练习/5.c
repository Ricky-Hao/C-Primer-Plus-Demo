#include <stdio.h>
int main(void)
{
	int up, down, n;

	printf("请输入将要输出的数表的上限与下限：");
	scanf_s("%d %d", &up, &down, 100, 100);
	n = up - down;

	for (; n >= 0; down++, n--)
		printf("%5d %5d %5d\n", down, down*down, down*down*down);
	getchar();
	getchar();
	return 0;
}