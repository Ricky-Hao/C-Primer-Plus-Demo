#include <stdio.h>
int main(void)
{
	int a, b, sum;

	printf("Ehter lower and upper integer limits:");
	scanf_s("%d %d", &a, &b, 100, 100);

	for (sum=0; a < b;sum=0)
	{
		printf("The sums of the squares from %d to %d ",a*a,b*b);
		for (; b - a >= 0; a++)
		{
			sum += a*a;
		}
		printf("is %d\n", sum);
		printf("Ehter lower and upper integer limits:");
		scanf_s("%d %d", &a, &b, 100, 100);
	}
	return 0;
}