#include <stdio.h>
int main(void)
{
	int a, b, c, d;
	char ch, ch1;

	scanf_s("%c", &ch, 100);
	for (a = 0, b = 5, c = 0, d = 0; a < 5; a++, printf("\n"), b--, c++, d++)
	{
		printf("%*c", b, ch);
		for (ch1 = ch + 1,c=a; c > 0;ch1++,c--)
		{
			printf("%c", ch1);
		};
		for (ch1 = ch+a-1, d = a; d > 0; d--,ch1--)
		{
			printf("%c", ch1);
		};
	}
	return 0;
}