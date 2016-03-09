/*mod_str.c -- ÐÞ¸ÄÒ»¸ö×Ö·û´®*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 80
void ToUpper(char *);
int PunctCount (const char *);
int main(void)
{
	char line[LIMIT];

	puts("Please enter a line:");
	gets(line);
	ToUpper;
	puts(line);
	printf("That line has %de punctuation characters.\n",PunctCount(line));
	return 0;
}

void ToUpper (char * str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

int PunctCount (const char * str)
{
	int ct = 0;
	while(*str)
	{
		if(ispunct(*str))
			ct++;
		str++;
	}
	return ct;
}