#include <stdio.h>
int main(void)
{
	int a, b;
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 8; b++)
			printf("$");
		printf("\n");
	}
	getchar();
	return 0;
}