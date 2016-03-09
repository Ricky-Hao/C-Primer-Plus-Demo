#include <stdio.h>
int main(void)
{
	double a[10], b[10], sum;
	int n;

	for (n = 0; n < 8; n++)
		scanf_s("%lf", &a[n],10);

	for (n = 0; n < 8; n++)
		printf("%.1lf     ", a[n]);

	printf("\n");

	for (sum = 0, n = 0; n < 8; n++)
	{
		sum += a[n];
		b[n] = sum;
		printf("%.1lf     ", b[n]);
	}
	
	getchar();
	getchar();
	return 0;
}