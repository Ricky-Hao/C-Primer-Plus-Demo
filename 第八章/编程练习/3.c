#include <stdio.h>
#include <ctype.h>
int main()
{
	int upper = 0;
	int lower = 0;
	char ch;

	printf("Please input your characters:\n");

	while ((ch = getchar()) != 26)
	{
		if (isupper(ch))
			upper++;
		else if (islower(ch))
			lower++;
	}
	printf("The upper is %d, lower is %d.", upper, lower);
	return 0;
}
