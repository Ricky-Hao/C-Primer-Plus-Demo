/*nogo.c -- 这个程序能满足要求吗？*/
#include <stdio.h>
#define ANSWER "Grant"
int main(void)
{
	char trys[40];

	puts("Who is buried in Grant's tomb?");
	gets(trys);
	while(trys!=ANSWER)
	{
		puts("No, that's wrong. Try again. ");
		gets(trys);
	}
	puts("That's right");

	return 0;
}
