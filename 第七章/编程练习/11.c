#include <stdio.h>
#define ARTICHOKE 1.25
#define BEET 0.65
#define CARROT 0.89
#define DISCOUNT 0.05
#define COST1 3.5
#define COST2 10
#define COST3 8
#define COSTRATE 0.1
#define BREAK1 5
#define BREAK2 20
int main(void)
{
	float a, b, c, discount, sum, weight, freight, cost;
	int n;
	char choice;
	a = b = c = 0;

	while (1)
	{
		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");
		printf("Please select what you had bought( one by one ):\n");
		printf("a) Artichoke    b) Beet\n");
		printf("c) Carrot       n) Cost\n");
		printf("q) Quit\n");
		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");
		for (n = 1; n > 0;)
		{
			choice = getchar();
			switch (choice)
			{
			case 'a':
				printf("How much Artichokes have you bought?\n");
				scanf_s("%f", &a, 100);
				getchar();
				printf("Please select the next one you had bought( one by one ):\n");
				break;
			case 'b':
				printf("How much Beets have you bought?\n");
				scanf_s("%f", &b, 100);
				getchar();
				printf("Please select the next one you had bought( one by one ):\n");
				break;
			case 'c':
				printf("How much Carrots have you bought?\n");
				scanf_s("%f", &c, 100);
				getchar();
				printf("Please select the next one you had bought( one by one ):\n");
				break;
			case 'n':
				printf("Here is your final cost:\n");
				n = 0;
				break;
			case 'q':
				return 0;
			default:
				printf("Please enter the correct choice:\n");
			}
		}

		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");

		if (a > 0)
		{
			printf("The Artichoke is $%.2f per pound.\n", ARTICHOKE);
			printf("You have bought %.2f pound(s)\n", a);
			printf("It will cost $%.2f .\n", a*ARTICHOKE);

			for (n = 0; n < 70; n++, printf("*"))
				;
			printf("\n");
		}

		if (b > 0)
		{
			printf("The Beet is $%.2f per pound.\n", BEET);
			printf("You have bought %.2f pound(s)\n", b);
			printf("It will cost $%.2f .\n", b*BEET);

			for (n = 0; n < 70; n++, printf("*"))
				;
			printf("\n");
		}

		if (c > 0)
		{
			printf("The Carrots is $%.2f per pound.\n", CARROT);
			printf("You have bought %.2f pound(s)\n", c);
			printf("It will cost $%.2f .\n", c*CARROT);

			for (n = 0; n < 70; n++, printf("*"))
				;
			printf("\n");
		}

		sum = (a*ARTICHOKE + b*BEET + c*CARROT);

		if (sum > 100)
		{
			discount = sum*DISCOUNT;
			printf("You will have $%.2f discount.\n", discount);
		}
		printf("Your all cost is $%.2f( without freight ).\n", sum - discount);

		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");

		weight = a + b + c;

		if (weight <= BREAK1)
			freight = COST1;
		else if (weight < BREAK2)
			freight = COST2;
		else
			freight = COST3 + weight*COSTRATE;
		printf("Your freight is $%.2f.\n", freight);

		for (n = 0; n < 70; n++, printf("*"))
			;
		printf("\n");

		cost = sum - discount + freight;
		printf("Your finall cost is $%.2f.\n", cost);
	}
	return 0;
}