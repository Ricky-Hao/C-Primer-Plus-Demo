#include <stdio.h>
int main(void)
{
	int a,temp;
	float b, c, sum;

	printf("请输入需要的次数：");
	scanf_s("%d", &a, 100);
	temp = a;

	for (sum=0,b = 1.0, c = 0; a > 0;a--)
	{
		c += b;
		sum += b / c;
	}
	printf("%f\n", sum);

	for (sum = 0, b = 1.0, c = 0; temp > 0;temp--)
	{
		c += b;
		if (temp % 2 == 0)
			sum += (b / c);
		if (temp % 2 != 0)
			sum += (b / c)*(-1);
	}
	printf("%f\n", sum);
	getchar();
	getchar();
	return 0;
}
