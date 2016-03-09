//for_13s.c
#include <stdio.h>
int main(void)
{
	int n;//以13计数

	for (n = 2; n < 60; n += 13)
		printf("%d \n", n);
	getchar();
	return 0;
}
