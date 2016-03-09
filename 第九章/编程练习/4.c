#include <stdio.h>
void average(double x, double y);
int main(void)
{
	double x = 0, y = 0;

	printf("Please enter tow number:\n");
	scanf_s("%lf %lf", &x, &y, 100, 100);
	average(x, y);
	return 0;
}

void average(double x, double y)
{
	x = 1 / x;
	y = 1 / y;
	x = 1 / ((x + y) / 2);
	printf("%lf", x);
}
