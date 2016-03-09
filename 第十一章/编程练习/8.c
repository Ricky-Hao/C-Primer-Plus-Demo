#include <stdio.h>
#include <string.h>
#define STR 100
void str_turn(char ar[]);
int main(void)
{
	char string[STR];

	do
	{
		fflush(stdin);
		fgets(string, STR, stdin);
		str_turn(string);
		fflush(stdin);
	} while (getchar() != 'q');

	return 0;
}

void str_turn(char ar[])
{
	int str = 0;

	str = strlen(ar);

	for (; str >= 0; str--)
		putchar(ar[str]);
}