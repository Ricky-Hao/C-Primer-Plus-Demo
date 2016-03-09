#include <stdio.h>
#define N 10
void arr_input(char ar[], int n);
int main(void)
{
	char ar[N+1];

	arr_input(ar, N);
	printf("%s", ar);
	return 0;
}

void arr_input(char ar[], int n)
{
	for (; n > 0; n--)
		scanf_s("%c", &ar[N - n], 10);
	ar[N] = '\0';
}