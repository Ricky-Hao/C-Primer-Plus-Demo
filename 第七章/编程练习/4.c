#include <stdio.h>
int main(void)
{
	char ch;

	scanf_s("%c", &ch,100);

	while (ch != '#')
	{
		if (ch == '.')
			printf("!");
		else if (ch == '!')
			printf("!!");
		else
			printf("%c", ch);

		scanf_s("%c", &ch,100);
	}
	printf("Done!\n");
	return 0;
}