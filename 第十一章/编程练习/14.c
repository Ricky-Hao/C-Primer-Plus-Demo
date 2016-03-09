#include <stdio.h>
#include <string.h>
#define MAX 100
int main()
{
	int n = 0;
	char string[MAX];
	int sum = 0;
	int t = 0;

	fgets(string, MAX, stdin);

	for (; n < strlen(string)&&t!=-1; n++)
	{
		if (string[n] >= '0'&&string[n] <= '9')
		{
			sum = sum*(10) + (string[n] - '0');
			t = 1;
		}
		if (t == 1 && (string[n] < '0' || string[n] > '9'))
			t = -1;
		if (n == strlen(string) - 1 && t != 1)
			t = -2;
	}
	if (t==-1&&t!=-2)
		printf("%d", sum);
	else
		printf("NULL");
	return 0;
}