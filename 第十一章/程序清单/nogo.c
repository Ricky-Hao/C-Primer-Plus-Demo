/*nogo.c -- �������������Ҫ����*/
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
