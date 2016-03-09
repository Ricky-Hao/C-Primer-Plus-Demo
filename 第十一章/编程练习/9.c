#include <stdio.h>
#include <string.h>
#define STR 100
void str_blank(char ar[]);
int main(void)
{
	char string[STR];

	do
	{
		fflush(stdin);
		fgets(string, STR, stdin);
		str_blank(string);
		fflush(stdin);
	} while (getchar() != '\n');

	return 0;
}

void str_blank(char ar[])
{
	int str = 0;


	for (; str < strlen(ar); str++)
		if (ar[str] != ' ')
			printf("%c", ar[str]);
}