/*str_cat.c -- 连续两个字符串*/
#include <stdio.h>
#include <string.h>/*声明strcat()函数*/
#define SIZE 80
int main(void)
{
	char flower[SIZE];
	char addon[]="s smell like old shoes.";

	puts("What is your favourite flower?");
	gets(flower);
	strcat(flower,addon);
	puts(flower);
	puts(addon);

	return 0;
}
