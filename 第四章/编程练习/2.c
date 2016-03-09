//调试成功
#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[10];
	scanf_s("%s", a,10);//这里scanf_s少了一个10的限制
	printf("\"%s\"\n", a);
	printf("\"%20s\"", a);
	printf("\"%-20s\"", a);
	printf("\"%*s\"", strlen(a) + 3, a);
	getchar();
	getchar();
	return 0;
}
