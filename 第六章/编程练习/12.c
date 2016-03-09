#include <stdio.h>
#include <math.h>
int main(void)
{
	int a[8];
	int n;

	for (n = 0; n < 8; n++)
	{
		a[n] = pow((double)2, n);
	}
	n--;

	do
	{
		printf("%d\n", a[n]);
		n--;
	} while (n >= 0);
	getchar();
	return 0;
}