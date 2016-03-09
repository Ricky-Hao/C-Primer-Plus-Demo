#include <stdio.h>
void power(double x, int y,double a);
int main(void)
{
	double x = 0;
	int y = 0;
	double a = 1;

	printf("Please enter the number:");
	scanf_s("%lf", &x, 100);
	fflush(stdin);
	printf("\nPlease enter the times:");
	scanf_s("%d", &y, 100);
	power(x, y, a);
	return 0;
}

void power(double x, int y, double a)
{
	if (y > 0)
	{
		y--;
		a *= x;
		power(x, y, a);
	}
	else if (y == 0 && a == 1)
		printf("-1");
	else if (y < 0)
	{
		y++;
		a *= 1 / x;
		power(x, y, a);
	}
	else if (y == 0 && a != 1)
		printf("The result is %lf.", a);
}

