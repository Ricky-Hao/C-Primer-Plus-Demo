#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, r;
	char a[100];
	n = 0;

	printf("请输入一个单词：");
	scanf_s("%c", &a[n], 100);

	for (n = 1; a[n-1]!= '\n'; n++)
	{
		scanf_s("%c", &a[n], 100);
	}

	for (n -= 1; n >= 0; n--)
		printf("%c", a[n]);
	getchar();
	return 0;
}
