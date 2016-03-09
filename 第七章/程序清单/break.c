//break.c -- 使用break退出循环
#include <stdio.h>
int main(void)
{
	float length, width;

	printf("Enter the length of the rectangle:\n");

	while (scanf_s("%f", &length, 100) == 1)
	{
		printf("Length = %0.2f: \n", length);
		printf("Enter its width: \n");
		if (scanf_s("%f", &width, 100) != 1)
			break;
		printf("Width %0.2f: \n", width);
		printf("Area = %0.2f \n", length*width);
		printf("Enter the length of the rectangle: \n");
	}
	printf("Done.\n");
	return 0;
}
