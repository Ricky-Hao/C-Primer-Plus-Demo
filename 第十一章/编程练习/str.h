#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM 3
#define STR 100

void arr_print(char *ar[])
{
	int num;

	for (num = 0; num < NUM; num++)
		printf("%s", ar[num]);
}

void str_INITIAL(char ar[][STR])
{
	int num = 0;

	for (; num < NUM; num++)
		printf("%s", ar[num]);
}

void str_ASCII(char *ar[])
{
	int num = 0;
	int t = 0;
	char *temp;

	for (; num < NUM-1; num++)
		for (t = num + 1; t < NUM; t++)
			if (strcmp(ar[num], ar[t]) > 0)
			{
				temp = ar[num];
				ar[num] = ar[t];
				ar[t] = temp;
			}
}

int first_word(char *ar[],int n)
{
	char word[STR];
	int str = 0;
	int t = 0;

	for (; (str < strlen(ar[n]))&&(t != -1); str++)
		if (isalpha(ar[n][str]))
			word[str] = ar[n][str];
		else
			t = -1;

	word[str-1] = '\0';
	return(strlen(word));
}

void str_LONG(char *ar[])
{
	char *temp;
	int num;
	int t;

	for (num = 0; num < NUM - 1; num++)
		for (t = num + 1; t < NUM;t++)
			if (first_word(ar, num) > first_word(ar, t))
			{
				temp = ar[num];
				ar[num] = ar[t];
				ar[t] = temp;
			}
}

void str_ALLONG(char *ar[])
{
	int num = 0;
	int t = 0;
	char *temp;

	for (num = 0; num < NUM - 1; num++)
		for (t = num + 1; t < NUM; t++)
			if (strlen(ar[num]) > strlen(ar[t]))
			{
				temp = ar[num];
				ar[num] = ar[t];
				ar[t] = temp;
			}
}

void bar(char ch, int n)
{
	for (; n > 0; n--)
		putchar(ch);
	putchar('\n');
}

char get_choice()
{
	char ch;

	fflush(stdin);

	ch = toupper(getchar());
	while (isalpha(ch) == 0)
	{
		printf("Please enter a correct choice.\n");
		ch = toupper(getchar());
	}

	while (ch<'A' || ch>'E')
	{
		printf("Please enter a correct choice.\n");
		ch = toupper(getchar());
	}

	return ch;
}

void choice(char ch,char ar[][STR])
{
	char *ptr[NUM];
	int num;

	for (num = 0; num < NUM; num++)
		ptr[num] = ar[num];

	switch (ch)
	{
	case 'A':
		str_INITIAL(ar);
		break;
	case 'B':
		str_ASCII(ptr);
		arr_print(ptr);
		break;
	case 'C':
		str_ALLONG(ptr);
		arr_print(ptr);
		break;
	case 'D':
		str_LONG(ptr);
		arr_print(ptr);
		break;
	case 'E':
		exit(0);
	}
}