#include <stdio.h>
#include <ctype.h>
void report(FILE*);
int main(void)
{
	printf("Please enter a text:\n");
	report(stdin);
	return 0;
}

void report(FILE*)
{
	char ch;
	while (1)
	{
		ch = getchar();
		if (isalpha(ch))
		{
			ch = tolower(ch);
			printf("%d ", ch - 96);
		}
		else
			printf("-1 ");
	}
}
