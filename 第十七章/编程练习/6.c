#include <stdio.h>

int binary(int ar[], int size, int n);

int main()
{
	int ar[10];
	int n = 0;

	for (int t = 0; t<10; t++)
		scanf("%d", &ar[t]);

	while (scanf("%d", &n)!=EOF)
		printf("%d\n", binary(ar, 10, n));

	return 0;
}


int binary(int ar[], int size, int n)
{
	for (int t = size / 2, temp1 = size, temp2 = 0; (temp1 - t) >= 1 && (t - temp2) >= 1;)
	{
		if (n>ar[t])
		{
			temp2 = t;
			t = (temp1 + t) / 2;
		}
		else
		{
			temp1 = t;
			t = (t - temp2) / 2;
		}
		if (ar[t] == n)
			return 1;
	}
	return 0;
}