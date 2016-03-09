//varwid.c -- 使用可变宽度的输出字段
#include<stdio.h>
int main(void)
{
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;
	printf("What field width?\n");
	scanf_s("%d", &width);
	printf("The number is: %*d; \n", width, number);
	printf("Now ehter a wifth and a precision: \n");
	scanf_s("%d %d", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	getchar();
	getchar();
	return 0;
}