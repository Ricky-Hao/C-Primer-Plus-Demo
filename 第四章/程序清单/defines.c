//defines.c -- 使用limits.h和float.h中定义的常量
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void)
{
	printf("Some number limits for this system;\n");
	printf("Bigger int: %d\n", INT_MAX);
	printf("Smallest unsigned long: %lld\n", LLONG_MIN);
	printf("One byte = %d bits on this system.\n", CHAR_BIT);
	printf("Largest double: %e\n", DBL_MAX);
	printf("Smallest normal float: %e\n", FLT_MIN);
	printf("float precsion = %d digits\n", FLT_DIG);
	printf("float epsilon = %e\n", FLT_EPSILON);
	getchar();
	return 0;
}