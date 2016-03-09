#include <stdio.h>
int main(void)
{
	int n;
	char ch1, ch2;

	for (ch1 = getchar(), n = 0, ch2 = getchar(); ch1 != '#'&&ch2 != '#'; ch2 = getchar())
	{
		if (ch1 == 'e')
		{
			if (ch2 == 'i')
				n++;
		}
		ch1 = ch2;
	}
	printf("%d", n);
	return 0;
}
