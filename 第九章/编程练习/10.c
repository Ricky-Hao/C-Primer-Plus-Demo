#include <stdio.h>
void Fibonacci(int n);
int main(void)
{
	int n;

	printf("Please enter the number:");
	scanf_s("%d", &n, 100);
	fflush(stdin);
	Fibonacci(n);
	return 0;
}

void Fibonacci(int n)
{
	int t = 0;
	int x = 1;
	int temp = 1;
	int temp1 = 1;

	for (; n > 0; n--,t++)
	{
		if (t < 2)
			printf("1 ");
		else
		{
			if (t % 2 == 0)
				temp = x;
			if (t % 2 != 0)
				temp1 = x;
			x = temp + temp1;
			printf("%d ", x);
		}
	}
}