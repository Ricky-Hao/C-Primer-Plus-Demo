#include <stdio.h>
int main(void)
{
	float a = 1e6;
	int n;

	for (n = 0; a > 0; n++)
	{
		a += a*0.08;
		a -= 1e5;
	}
	printf("%d", n);
	getchar();
	return 0;
}