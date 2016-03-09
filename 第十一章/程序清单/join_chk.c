/*join_chk.c -- 连接两个字符串，并检查第一个字符串的大小*/
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
int main(void)
{
	char flower[SIZE];
	char addon[]="s smell like old shoes.";
	char bug[BUGSIZE];
	int available;

	puts("What is your favourite flower?");
	gets(flower);
	if((strlen(addon)+strlen(flower)+1)<=SIZE)
		strcat(flower,addon);
	puts(flower);
	puts("What is your favourite bug?");
	gets(bug);
	available=BUGSIZE-strlen(bug)-1;
	strncat(bug,addon,available);
	puts(bug);

	return 0;
}
