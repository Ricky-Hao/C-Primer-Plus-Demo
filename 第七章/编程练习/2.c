#include <stdio.h>
int main(void)
{
	char ch=0;
	int n;

	for (; ch!='#';)
	{
		for (n = 0; n < 8; n++)
		{
			if ((ch=getchar()) != '#')
				printf("%c %d   ", ch, ch);
			else
				break;
		}
		printf("\n");
	}
	getchar();
	return 0;
}