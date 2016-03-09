#include <stdio.h>
#include <string.h>
#include "str.h"

int main(void)
{
	char string[NUM][STR];
	int num = 0;
	char ch;

	do
	{
		bar('*', 60);
		printf("Please 10 string or EOF:\n");

		for (fflush(stdin), num = 0; (num < NUM); num++, fflush(stdin))
			fgets(string[num], STR, stdin);
		
		bar('*', 60);

		printf("A) Initial            B) ASCII\n");
		printf("C) String long        D) The first long\n");
		printf("E) Quit\n");
		printf("Please select one of above:");
		ch = get_choice();
		putchar('\n');
		bar('*', 60);

		choice(ch,string);

	} while (putchar('\n'));

	return 0;
}