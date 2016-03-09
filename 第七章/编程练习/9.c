#include <stdio.h>
int main(void)
{
	int a, t, n,k;

	printf("Please input a number( q to quit):\n");
	t = scanf_s("%d", &a, 100);

	while (t > 0)
	{
		printf("The prime is :\n");

		for (; a > 2; a--)
		{
			for (n = 2; n < a; n++)
			{
				if (a%n == 0)
				{
					k = 1;
					break;
				}
				else
					k = 0;
			}
			if (k == 0)
				printf("%d\n", a);
		}
		printf("Please input a number( q to quit):\n");
		t = scanf_s("%d", &a, 100);
	}
	return 0;
}