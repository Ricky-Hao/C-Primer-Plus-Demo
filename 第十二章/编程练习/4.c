#include <stdio.h>
int fun(void);
int main(void)
{
	int a = 0;
	int b = 0;
	while (a++ < 10)
		b=fun();
	return 0;
}

int fun(void)
{
	static int n = 0;
	n++;
	return n;
}