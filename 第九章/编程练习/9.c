#include <stdio.h>
void to_binary(unsigned long n,int x);

int main(void)
{
	unsigned long number;
	int n = 0;
	printf("Enter an integer (q to quit):\n");
	while (scanf_s("%ul", &number) == 1)
	{
		printf("Please enter the base number:");
		fflush(stdin);
		scanf_s("%d", &n, 10);

		printf("\nThe number equivalent :");
		to_binary(number,n);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");

	return 0;
}

void to_binary(unsigned long n,int x)
{
	int r;
	unsigned long temp;
	r = n % x;
	if (n >= x)
	{
		temp = n / x;
		to_binary(temp, x);
	}
	putchar('0' + r);

	return;
}
