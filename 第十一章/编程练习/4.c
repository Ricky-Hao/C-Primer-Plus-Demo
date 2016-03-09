#include <stdio.h>
#include <stdlib.h>
void str_search(char *ptr, char ch);
int main(void)
{
	char ch = 0;
	char *ptr;
	char ar[1000];

	do
	{
		fflush(stdin);
		fgets(ar, 1000, stdin);
		ptr = ar;
		ch = getchar();
		str_search(ptr, ch);
	} while ((ch = getchar()) != 'q');

	return 0;
}

void str_search(char *ptr, char ch)
{
	int n;
	for (n = 0; *(ptr + n) != '\0'; n++)
		if (*(ptr + n) == ch)
		{
			printf("%p\n", ptr + n);
			exit(0);
		}
	printf("%p", NULL);
}