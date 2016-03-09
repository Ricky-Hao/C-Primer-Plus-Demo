#include <stdio.h>
#define SIZE 5
void arr_max(double ar[SIZE], double**p);
int main(void)
{
	double ar[SIZE];
	int t = 0;
	double *p;

	printf("Please enter %d number:\n", SIZE);
	for (t = 0; t < 5; t++)
	{
		scanf_s("%lf", &ar[t], 10);
		fflush(stdin);
	}

	arr_max(ar, &p);
	printf("The address of the max number in the array is %p.\n", p);
	return 0;
}

void arr_max(double ar[SIZE], double**p)
{
	int t = 0;
	int n = 0;

	for (t = 0; t < SIZE - 1;)
	{
		n = t;
		while (ar[t]>ar[n + 1] && n < SIZE - 1)
			n++;
		if (ar[t] > ar[n + 1])
			break;
		else
		{
			t = n;
			t++;
		}
	}
	*p = &ar[t];
}