//praise1.c--使用不同类别的字符串
#include <stdio.h>
#define PRAISE "What a super marvelous name!"
int main(void)
{
	char name[40];
	printf("What is your name.\n");
	scanf_s("%s", name);
	printf("Hello,%s,%s\n", name, PRAISE);
	getchar();
	getchar();
	return 0;
}

