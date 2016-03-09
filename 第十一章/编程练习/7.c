#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
void string_in(char *p1, char *p2);
int main(void)
{
	char ar[MAX];
	char ar2[MAX];

	do
	{
		fflush(stdin);
		fgets(ar, MAX, stdin);
		fflush(stdin);
		fgets(ar2, MAX, stdin);
		fflush(stdin);
		string_in(ar, ar2);
	} while (getchar() != 'q');

	return 0;
}

void string_in(char *p1, char *p2)
{
	int n = 0;
	int t = 0;

	for (;n<strlen(p1); n++)
	{
		if (*(p1 + n) == *p2)
			for (; t < strlen(p2)-1 && t != -1; t++)
				if (*(p1 + n + t) != *(p2 + t) && strlen(p2) != 2)
					t = -2;
		if (t == strlen(p2)-1 && *p2 != '\n')
		{
			printf("%p\n", p1 + n);
			n = strlen(p1);
		}
	}
	if (n != strlen(p1)+1)
		printf("%p\n", NULL);
	printf("%p", p1);
}