//cypher2.c -- 改变输入，只保留非字母字符
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))
			putchar(ch+1);
		else
			putchar(ch);
	}
	putchar(ch);
	getchar();
	return 0;
}
