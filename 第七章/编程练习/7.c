#include <stdio.h>
#define STSALARY 10
#define OVERTIME 1.5
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
#define BREAK1 300
#define BREAK2 150
int main(void)
{
	int hours, t;
	float sum, net, tax;

	printf("Please input your work hours ( q to quit):\n");
	t = scanf_s("%d", &hours,100);

	for (sum = net = tax = 0; t != 0; t = scanf_s("%d", &hours,100))
	{
		if (hours <= 40)
			sum = hours*STSALARY;
		else
			sum = 40 * STSALARY + (hours - 40)*1.5*STSALARY;
		if (sum <= BREAK1)
			tax = sum*TAX1;
		else if (sum <= BREAK2)
			tax = BREAK1 + (sum - BREAK1)*TAX2;
		else
			tax = BREAK1 + BREAK2 + (sum - BREAK1 - BREAK2)*TAX3;
		net = sum - tax;
		printf("sum = $%.1f, net = $%.1f, tax =$%.1f\n", sum, net, tax);
		sum = net = tax = 0;
	}
	printf("Done!\n");
	return 0;
}