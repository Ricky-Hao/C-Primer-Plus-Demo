#include <stdio.h>
#include <stdlib.h>
void count(int num,int ar[]);
int main()
{
	int ar[10];
	int seed = 0;
	scanf("%d", &seed);
	srand(seed);
	for (int n = 0; n < 10; ar[n++] = 0);
	for (int n = 0; n < 1000; n++)
		count(rand(), ar);
	for (int n = 0; n < 10; n++)
		printf("%d: %d\n", n + 1, ar[n]);

	return 0;
}

void count(int num, int ar[])
{
	int div = 10;
	ar[num%div]++;
}