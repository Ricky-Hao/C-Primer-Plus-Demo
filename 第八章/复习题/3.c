//count.c -- 对文件中的字符进行计数
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
	int n = 0;
	char ch;
	FILE*fp;
	char fname[100];

	printf("Please enter your file name:\n");
	scanf_s("%c", fname, 100);
	fp = fopen_s(fname, "r");

	if (fp == NULL)
	{
		printf("Failed to open your file.");
		exit(1);
	}


	while ((ch = getc(fp)) != EOF)
	{
		if (isgraph(ch))
			n++;
		else
			break;
	}

	printf("There are %d characters in your file.\n", n);
	return 0;
}