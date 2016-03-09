#include <stdio.h>
#include <ctype.h>
#define MAX 40
void arr_gets(char ar[], int n);
int main(void)
{
	char ar[MAX];

	arr_gets(ar, MAX);
	printf("%s", ar);
	return 0;
}

void arr_gets(char ar[], int n)
{
	for (ar[MAX - n] = getchar(); isalpha(ar[MAX - n]); n--, ar[MAX - n] = getchar());
	ar[MAX - n] = '\0';
}