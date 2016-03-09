#include <stdio.h>
#include <ctype.h>
void line(char ch, int n);
char g_char(char ch);
float g_num(float num);
int main(void)
{
	char choice;
	float num1, num2;
	num1 = num2 = 1;
	choice = 0;

	while (1)
	{
		line('#', 40);
		printf("Enter the operation of your choice: \n\n");
		printf("a. add         s. subtract\n");
		printf("m. multiply    d. divide\n");
		printf("q. quit\n");
		line('#', 40);

		choice = g_char(choice);
		if (choice == 'q')
		{
			printf("Bye.");
			return 0;
		}

		line('*', 40);
		printf("Enter first number:");
		num1 = g_num(num1);
		printf("\nEnter second number:");
		num2 = g_num(num2);
		for (; num2 == 0;)
		{
			printf("\nEnter a number other than 0:");
			num2=g_num(num2);
		}
		line('*', 40);

		switch (choice)
		{
		case 'a':
			printf("\n%.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
			break;
		case 's':
			printf("\n%.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
			break;
		case 'm':
			printf("\n%.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
			break;
		case 'd':
			printf("\n%.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
			break;
		}
	}
	return 0;
}

void line(char ch, int n)
{
	for (; n-- >= 0;)
		printf("%c", ch);
	printf("\n");
}

char g_char(char ch)
{
	int n = 0;
	do
	{
		for (ch = getchar(); isalpha(ch) <= 0; ch = getchar())
			;
		if (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
		{
			printf("Please enter a correct choice:\n");
			n = 1;
		}
		else
			n = 0;
	} while (n != 0);
	return ch;
}

float g_num(float num)
{
	int n;
	n = scanf_s("%f", &num, 100);
	for (; n != 1;)
	{
		printf("Please enter a number.\n");
		fflush(stdin);
		n = scanf_s("%f", &num, 100);
	}
	return num;
}