#include <stdio.h>
void cube(float n);
int main(void)
{
	float  a;

	printf("Please input a number.\n");
	scanf_s("%f", &a, 100);
	cube(a);
	getchar();
	getchar();
	return 0;
}
void cube(float n)
{
	printf("%f", n*n*n);
}