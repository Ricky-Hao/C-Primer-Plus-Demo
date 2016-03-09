#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int main(void)
{
	char ch[MAX];
	char temp[2];
	int n;
	int number, upper, lower, punct, digit;
	number = upper = lower = punct = digit = 0;

	temp[1] = '\0';
	for (n = 0,fgets(ch,1,stdin); n < MAX && ((temp[0] = getchar()) != EOF); n++)
		strcat_s(ch, temp);

	for (n = 0; n < strlen(ch); n++)
	{
		if (isupper(ch[n]))
			upper++;
		if (islower(ch[n]))
			lower++;
		if (isdigit(ch[n]))
			digit++;
		if (ispunct(ch[n]))
			punct++;
	}

	for (n = 0; n < strlen(ch);n++)
	{
		if (isalpha(ch[n]))
		{
			for (n++; n < strlen(ch) && isalpha(ch[n]); n++);
			number++;
		}
	}
	printf("%d %d %d %d %d\n", upper, lower, digit, punct, number);
	return 0;
}