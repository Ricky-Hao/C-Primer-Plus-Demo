#include <stdio.h>
float r(float a,float b);
int main(void)
{
	float a, b;

	printf("请输入两个数(输入q退出）：");

	for (; scanf_s("%f %f", &a, &b, 100, 100) == 2;)
	{
		printf("%f\n",r(a,b));
		printf("请输入两个数(输入q退出）：");
	}
	return 0;
}
float r(float a,float b)
{
	return (a - b) / (a*b);
}