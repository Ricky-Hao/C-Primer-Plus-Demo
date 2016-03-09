//调试成功
#include <stdio.h>
int main(void)
{
	char a[100], b[100];
	scanf_s("%s %s", a,100, b,100);//少了100的限制
	printf("%s,%s", a, b);
	getchar();
	getchar();
	return 0;
}
