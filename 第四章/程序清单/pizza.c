//pizza.c -- 在比萨饼的例子中使用定义常量
#include <stdio.h>
#define PI 3.14159
int main(void)
{
	float area, circum, radius;
	printf("What is the radius of your pizza?\n");
	scanf_s("%f", &radius);
	area = PI*radius*radius;
	circum = 2.0*PI*radius;
	printf("Your basic pizza parameters are as follows:\n");
	printf("circumference = %.2f,area = %.2f\n", circum, area);
	getchar();
	getchar();
	return 0;
}
