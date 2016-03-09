#include <stdio.h>
int main(void)
{
	float a;
	scanf_s("%f", &a);
	printf("The input is %.1f or %.1e .\n", a, a);
	printf("The input is %+.3f or %.3E .\n", a, a);
	getchar();
	getchar();
	return 0;
}
