#include <stdio.h>
#define N 1000
int is_within(char ch, char *ptr);
int main(void)
{
	char ar[N];
	char ch;

	do
	{
		fflush(stdin);
		fgets(ar, N, stdin);
		ch = getchar();
		printf("%d", is_within(ch, ar));
		fflush(stdin);
		putchar('\n');
	}
	while (getchar() != 'q');
	return 0;
}

int is_within(char ch, char *ptr)
{
	int n = 0;
	for (n = 0; n < N; n++)
	{
		if (*(ptr + n) == ch)
			return 1;
	}

	return 0;
}