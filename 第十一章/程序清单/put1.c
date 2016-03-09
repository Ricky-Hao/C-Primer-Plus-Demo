/*put1.c -- 不添加换行符打印一个字符串*/
#include <stdio.h>
void put1(const char*string)		/*不会改变这个字符串*/
{
	while(*string!='\0')
		putchar(*string++);
}
