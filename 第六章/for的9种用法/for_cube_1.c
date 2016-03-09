//for_cube_1.c
#include <stdio.h>
int main(void)
{
	int num;

	printf("    n   n cubed\n");
	for (num = 1; num*num*num <= 216; num++)
		printf("%5d %5d\n", num, num*num*num);
	getchar();
	return 0;
}
