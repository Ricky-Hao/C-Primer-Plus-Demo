//summing.c -- 对用户输入的整数求和
#include <stdio.h>
int main(void)
{
	long num;
	long sum = 0L;
	int status;

	printf("Please enter an integer to be summed.");
	printf("(q to quit):");
	status = scanf_s("%ld", &num, 100);
	while (status == 1)
	{
		sum = sum + num;
		printf("Please enter next intrger (q to quit):");
		status = scanf_s("%ld", &num, 100);
	}
	printf("Those integers sum to %ld .\n", sum);
	getchar();
	getchar();
	getchar();
	return 0;
}
