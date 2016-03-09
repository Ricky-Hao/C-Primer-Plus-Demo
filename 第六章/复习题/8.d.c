#include <stdio.h>
int main(void)
{
	char ch;

	scanf_s("%c", &ch, 100);
	for (ch = '$'; ch != 'g'; scanf_s("%c", &ch, 100))
		putchar(ch);
	getchar();
	return 0;
}
