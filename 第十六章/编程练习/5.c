#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100
void select_random(int[], int, int);

int main(void)
{
	int ar[100];
	int n;
	for (int t = 0; t<SIZE; ar[t++] = t)
		;
	while (scanf("%d", &n) != EOF)
	{
		if (n>SIZE)
			printf("Error!");
		else
			select_random(ar, SIZE, n);
	}
	return 0;
}

void select_random(int ar[], int size, int n)
{
	int num[SIZE];
	srand((double)clock());
	for (int k = 0, t = 0, s = rand() % size, c = 0; t<n&&n<size;)
	{
		for (int i = 0; i<k; i++)
			if (num[i] == s)
				c = 1;
		if (c == 1)
		{
			c = 0;
			continue;
		}
		else
		{
			printf("%d\n", ar[s]);
			num[k++] = s;
			t++;
		}
		s = rand() % size;
	}
}