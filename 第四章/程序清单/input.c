//input.c -- 什么情况下使用&
#include <stdio.h>
int main(void)
{
	int age;
	float assets;
	char pet[30];
	printf("Enter your age, assets, and favourite pet.\n");
	scanf_s("%d %f", &age, &assets);
	scanf_s("%s", pet);
	printf("%d $%.2f %s\n", age, assets, pet);
	getchar();
	getchar();
	return 0;
}
