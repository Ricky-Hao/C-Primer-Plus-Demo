#include <stdio.h>
int main(void)
{
	float a, b, a1;
	int n;
	a = 100;
	b = 100;

	for (a1 = 100, n = 0; b <= a1; n++)
	{
		a1 += a*0.1;
		b += b*0.05;
	}
	printf("%d", n);
	getchar();
	return 0;
}