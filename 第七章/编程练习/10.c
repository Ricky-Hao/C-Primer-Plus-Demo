#include <stdio.h>
#define TAX1 0.15
#define TAX2 0.28
#define ALONE 17850
#define HOST 23900
#define MARRIED 29750
#define DIVORCED 14875
int main(void)
{
	int a, b, n;
	float money, tax;

	do
	{
		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");
		printf("Please choose your type:\n");
		printf("1) Alone     2) Host\n");
		printf("3) Married   4) Divorced\n");
		printf("5) Quit\n");

		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");

		scanf_s("%d", &a, 10);
		for (b = 0; b == 0;)
		{
			switch (a)
			{
			case 1:
				b = ALONE;
				break;
			case 2:
				b = HOST;
				break;
			case 3:
				b = MARRIED;
				break;
			case 4:
				b = DIVORCED;
				break;
			case 5:
				return 0;
			default:
				b = 0;
				printf("Please input a correct number.\n");
			}
		}
		printf("Please input your salary:\n");
		scanf_s("%f", &money, 100);

		if (money<=b)
			tax = money*TAX1;
		else
			tax = TAX1*b + (money - b)*TAX2;

		printf("The tax is %.1f\n", tax);
	} while (1);
	return 0;
}