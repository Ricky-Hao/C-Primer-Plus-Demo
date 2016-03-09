#include <stdio.h>
void choutput(char ch, int i, int j);
int main(void)
{
	int i, j;
	i = j = 0;
	char ch;

	printf("Please enter the number:");
	scanf_s("%d", &i, 100);
	fflush(stdin);
	printf("\nPlease enter the line:");
	scanf_s("%d", &j, 100);
	fflush(stdin);
	printf("\nPlease enter the character:");
	scanf_s("%c", &ch, 100);
	choutput(ch, i, j);
	return 0;
}

void choutput(char ch, int i, int j)
{
	int temp = i;

	for (; j-- >= 0; printf("\n"), i = temp)
		for (; i-- > 0; printf("%c", ch));
}