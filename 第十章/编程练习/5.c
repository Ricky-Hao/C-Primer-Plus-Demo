#include <stdio.h>
#define SIZE 5
double array(double ar[SIZE]);
int main(void)
{
	double ar[SIZE];
	int t = 0;

	printf("Please enter %d number:\n", SIZE);
	for (t = 0; t < SIZE; t++)
	{
		scanf_s("%lf", &ar[t], 10);
		fflush(stdin);
	}

	printf("%lf", array(ar));
	return 0;
}

double array(double ar[SIZE])
{
	int t = 0;
	int n = 0;
	int c[2 * SIZE];
	int d = 0;

	for (t = 0; t < SIZE - 1; t++)
	{
		for (n = t + 1; n <= SIZE - 1; n++, d++)
		{
			c[d] = ar[t] - ar[n];
			if (c[d] < 0)
				c[d] = -c[d];
		}
	}

	for (t = 0; t < (2 * SIZE - 1);)
	{
		
		n = t;
		while (c[t]>c[n+1] && n < (2 * SIZE - 1))
			n++;
		if (c[t] > c[n+1])
			break;
		else
		{
			t = n;
			t++;
		}
	}
	return c[t];
}