#include <stdio.h>
int main(void)
{
	int a, n;
	n = 0;

	printf("Please input a number.\n");
	scanf_s("%d", &a, 100);

	while (n++ < 11)
		printf("%d\n", a++);
	printf("Done!");
	getchar();
	getchar();
	return 0;
}