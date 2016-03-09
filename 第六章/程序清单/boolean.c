//boolean.c -- 使用_Bool 变量
#include <stdio.h>
int main(void)
{
	long num;
	long sum = 0L;
	bool input_is_good;//不知名原因使得_Bool用不了，遂将其替换为bool

	printf("Please enter an integer to be summed.\n");
	printf("(q to quit):");

	input_is_good = (scanf_s("%ld", &num, 100));
	while (input_is_good)
	{
		sum += num;
		printf("Please enter next integer (q to quit):");
		input_is_good = (scanf_s("%ld", &num) == 1);
	}
	printf("Those integers sum to %ld.\n", sum);
	getchar();
	getchar();
	getchar();
	return 0;
}
