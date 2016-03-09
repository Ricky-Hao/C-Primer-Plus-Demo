//cmpflt.c -- 浮点数比较
#include <stdio.h>
#include <math.h>
int main(void)
{
	const double ANSWER = 3.14159;
	double response;

	printf("What's the value of pi?\n");
	scanf_s("%lf", &response, 100);

	while (fabs(response - ANSWER) > 0.0001)
	{
		printf("Try again.\n");
		scanf_s("%lf", &response, 100);
	}
	
	printf("Close enough!\n");
	getchar();
	getchar();
	return 0;
}
