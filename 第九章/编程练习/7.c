#include <stdio.h>
double power(double x, int y);
int main(void)
{
	double x = 0;
	int y = 0;

	printf("Please enter the number:");
	scanf_s("%lf", &x, 100);
	fflush(stdin);
	printf("\nPlease enter the times:");
	scanf_s("%d", &y, 100);
	printf("The result is %lf.", power(x, y));
	return 0;
}

double power(double x, int y)
{
	if (y > 0)
		for (y -= 1; y-- > 0; x *= x);
	else if (y == 0)
	{
		if (x == 0)
			x = 0;
		else
			x = 1;
	}
	else
		for (x = 1 / x,y+=1; y++ < 0; x *= x);
	return x;
}
