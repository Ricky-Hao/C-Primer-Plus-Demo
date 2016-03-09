#include <stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
	int i, j;
	i = j = 0;
	char ch;

	printf("Please enter the line:");
	scanf_s("%d %d", &i, &j, 100, 100);
	fflush(stdin);
	printf("\nPlease enter the character:");
	scanf_s("%c", &ch, 100);
	chline(ch, i, j);
	return 0;
}

void chline(char ch, int i, int j)
{
	for (; i-- > 1; printf(" "))
		;
	for (; j-- > 1; printf("%c", ch))
		;
}
