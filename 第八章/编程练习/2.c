#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	int n = 0;

	printf("Please input the characters:\n");
	while ((ch = getchar()) != 26)
	{
		n++;
		printf(" ");
		if (ch == '\n' || ch == 't')
		{
			if (ch == '\n')
				printf("\\n");
			else
				printf("\\t");
		}
		else if (ch <= 32)
		{
			if (ch == 32)
				printf("space");
			else
				printf("^%c", ch + 64);
		}
		else
			printf("%c", ch);
		printf("%d", ch);
		if (ch == '\n')
		{
			printf("\n");
			n--;
		}
		else if (n == 10)
		{
			printf("\n");
			n = 0;
		}
	}
	return 0;
}
