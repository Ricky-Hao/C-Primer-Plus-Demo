#include <stdio.h>
int main(void)
{
	char ch;

	scanf_s("%c", &ch, 100);
	while (ch != 'g')
	{
		printf("%c", ++ch);
		scanf_s("%c", &ch, 100);
	}
	getchar();
	return 0;
}