//trouble.c -- 误用=
//将导致无限的循环
#include <stdio.h>
int main(void)
{
	long num;
	long sum = 0L;
	int status;

	printf("Please enter an integer to be summed");
	printf("(q to quit):");
	status = scanf_s("%ld", &num,100);
	
	while (status = 1)//将=改为==
	{
		sum = sum + num;
		printf("Please enter next integer (q to quit):");
		status = scanf_s("%ld", &num,100);
	}
	printf("Those integers sum to %ld.\n", sum);
	getchar();
	getchar();
	getchar();
	return 0;
}