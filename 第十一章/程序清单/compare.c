/*compare.c -- 这个程序可以满足要求*/
#include <stdio.h>
#include <string.h>
#define MAX 40
#define ANSWER "Grant"
int main(void)
{
	char trys[MAX];

	puts("Who is buried in Grant's tomb?");
	gets(trys);
	while(strcmp(trys,ANSWER)!=0)
	{
		puts("No, that's wrong. Try again. ");
		gets(trys);
	}
	puts("That's right");

	return 0;
}
