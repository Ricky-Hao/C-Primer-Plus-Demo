#include <stdio.h>
int main(void)
{
	int a, b, c, d, e,t;
	b = d = 0;
	c = e = 0;

	scanf_s("%d", &a,100);
	for (; a != 0;)
	{
		t = a % 2;
		switch (t)
		{
		case 0:
			b++;
			c += a;
			break;
		case 1:
			d++;
			e += a;
			break;
		}
		scanf_s("%d", &a,100);
	}

	if (b == 0)
		b++;
	if (d == 0)
		d++;
	printf("%d %d %d %d", b, c / b, d, e / d);
	getchar();
	return 0;
}