//do_while.c -- 退出条件循环
#include <stdio.h>
int main(void)
{
	const int secret_code = 13;
	int code_entered;

	do
	{
		printf("To enter the triskaidekaphobia therapy club,\n");
		printf("please enter the secret code number:");
		scanf_s("%d", &code_entered,100);
	} while (code_entered != secret_code);
	printf("Congratulations! You are cured!\n");
	getchar();
	getchar();
	return 0;
}
