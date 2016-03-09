#include <stdio.h>
double min(double x, double y);
int main(void)
{
	double x, y;
	x = y = 0;

	scanf_s("%lf %lf", &x, &y, 10, 10);
	x=min(x, y);
	printf("%.1lf", x);
	return 0;
}

double min(double x, double y)
{
	if (y >= x)
		x = y;
	return x;
}