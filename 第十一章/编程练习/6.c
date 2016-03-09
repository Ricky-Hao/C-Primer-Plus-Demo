#include <stdio.h>
#define AR1 1000
#define AR2 100
#define COPY 10
void strncpy_c(char *p1, char *p2, int n);
int main(void)
{
	char ar[AR1];
	char ar2[AR2];

	do
	{
		fflush(stdin);
		fgets(ar, AR1-COPY, stdin);
		fflush(stdin);
		fgets(ar2, AR2, stdin);
		strncpy_c(ar, ar2, COPY);
		printf("%s", ar);
		fflush(stdin);
	} while (getchar() != 'q');

	return 0;
}

void strncpy_c(char *p1, char *p2, int n)
{
	int t = 0;
	int t2 = 0;

	for (; *(p1 + t) != '\n'; t++);

	for (; n >= 0; n--)
		*(p1 + t + n) = *(p2 + n);

	for (; *(p2 + t2) != '\n'&&t < AR2; t2++);

	if (t2 > n)
		*(p1 + t + COPY) = '\0';
	else if (*(p2 + t2) != '\0')
		*(p1 + t + t2) = '\0';
}