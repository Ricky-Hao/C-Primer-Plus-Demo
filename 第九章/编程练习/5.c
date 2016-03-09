#include <stdio.h>
void larger_of(float*a, float*b,float x,float y);
int main(void)
{
	float x = 0, y = 0;

	printf("Please enter two number:\n");
	scanf_s("%f %f", &x, &y, 100, 100);
	larger_of(&x, &y,x,y);
	printf("x = %f y = %f", x, y);
	return 0;
}

void larger_of(float*a, float*b, float x, float y)
{
	if (x > y)
	{
		*a = x;
		*b = x;
	}
	else
	{
		*a = y;
		*b = y;
	}
}
