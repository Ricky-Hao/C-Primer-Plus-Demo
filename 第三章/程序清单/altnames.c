//altnames.c -- 可移植的整数类型
#include <stdio.h>
#include <inttypes.h>
int main(void)
{
	int16_t me16;
	me16 = 4593;
	printf("First assume int16_t is short:");
	printf("me16 = %hd\n", me16);
	printf("Next,let's not make any assumptions.\n");
	printf("Instead, use a \"macro\" from inttypes.h:");//其中的/"是"的转移符号
	printf("me16 = %"PRId16"\n", me16);
	getchar();
	return 0;
}
