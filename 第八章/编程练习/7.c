#include <stdio.h>
#define OVERTIME 1.5
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
#define BREAK1 300
#define BREAK2 150
int main(void)
{
	int hours, t;
	char n;
	float sum, net, tax, STSALARY;



	for (sum = net = tax = 0, t = 1; t != 0;)
	{
		for (n = 0; n < 70; n++)
			printf("*");

		printf("\n");
		printf("Enter the number corresponding to the desired pay rate or action( q to quit):\n");
		printf("A ) $8.75/hr                     B ) $9.33/hr\n");
		printf("C ) $10.00/hr                    D ) $11.20/hr\n");
		printf("Q ) quit\n");

		for (n = 0; n < 70; n++, printf("*"))
			;

		printf("\n");

		for (STSALARY = 0; (STSALARY == 0);)
		{
			scanf_s("%c", &n, 100);
			switch (n)
			{
			case 'A':
				STSALARY = 8.75;
				break;
			case 'B':
				STSALARY = 9.33;
				break;
			case 'C':
				STSALARY = 10.00;
				break;
			case 'D':
				STSALARY = 11.20;
				break;
			case 'Q':
				STSALARY = 0.1;
				break;
			default:printf("Please input a correct number:");
			}
		}

		if (STSALARY >= 1)
		{
			printf("Please input your work hours ( q to quit):\n");
			t = scanf_s("%d", &hours, 100);


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
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
		else
			t = 0;
		STSALARY = 0;
	}
	printf("Done!\n");
	return 0;
}