#include <stdio.h>
#define FEET 30.48
#define INCHES 0.3937
int main(void)
{
	float cm, inches;
	int feet;

	printf("Enter a height in centimeters:");
	scanf_s("%f", &cm, 100);

	while (cm > 0)
	{
		feet = cm / FEET;
		inches = (cm-feet*FEET)*INCHES;
		printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inches);
		printf("Enter a height in centimeters (<=0 to quit):");
		scanf_s("%f", &cm, 100);
	}
	printf("bye");
	getchar();
	getchar();
	return 0;
}