#include <stdio.h>
int main(void)
{
	char ch;

	do{
		scanf_s("%c", &ch, 100);
		printf("%c", ch);
	} while (ch != 'g');
	getchar();
	return 0;
}