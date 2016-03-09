//出错
#include <stdio.h>
#include <string.h>
int main(void)
{
	int width1, width2;
	char n1[10], n2[10];
	scanf_s("%s %s", n1, n2);
	printf("%s %s", n1, n2);
	width1 = strlen(n1);
	width2 = strlen(n2);
	printf("%*s %*s", width1, width1, width2, width2);
	printf("%s %s", n1, n2);
	printf("%-*s %-*s", width1, width1, width2, width2);
	getchar();
	getchar();
	return 0;
}