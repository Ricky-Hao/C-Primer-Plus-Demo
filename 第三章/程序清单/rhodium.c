#include <stdio.h>
int main(void)
{
	float weight;
	float value;
	printf("Are you worth your weight in rhodium?\n");
	printf("Let's check it out!\n");
	printf("Please enter you weight in pounds.\n");
	scanf_s("%f", &weight);
	value = 770 * weight*14.5833;
	printf("Your weight in rhodium is worth $%.2f\n", value);
	printf("You are easily worth that!If rhodium prise drop,\n");
	printf("eat more to maintain you value!");
	getchar();
	getchar();
	return 0;
}
