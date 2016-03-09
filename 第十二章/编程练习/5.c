#include <stdio.h>
#include <time.h>
int rand1(unsigned int seed);
unsigned int srand1(int n);
void sort(int ar[]);
int main()
{
	int ar[100];
	for (int n = 0; n < 100; n++)
		ar[n] = rand1(srand1(n));
	sort(ar);
	for (int n = 0; n < 100; n++)
		printf("%d ", ar[n]);
	putchar('\n');
	return 0;
}

unsigned int srand1(int n)
{
	unsigned int seed = 0;
	n++;
	seed = n*(unsigned int)time(0);
	return seed;
}

int rand1(unsigned int seed)
{
	unsigned int next = 0;
	next = seed * 1103515245 + 12345;
	while (next > 10)
		next /= 10;
	return next;
}

void sort(int ar[])
{
	for (int i = 0; i < 100; i++)
		for (int j = i + 1; j < 100; j++)
		{
			if (ar[i]>ar[j])
			{
				int temp = ar[j];
				ar[j] = ar[i];
				ar[i] = temp;
			}
		}
}