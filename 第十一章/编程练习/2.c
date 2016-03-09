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
	for (; ar[N - n - 1] != ' '&&ar[N - n - 1] != '\n'&&ar[N - n - 1] != '\t'&&n > 0; n--)
		ar[N - n] = getchar();
	ar[N-n] = '\0';
}