#include <stdio.h>
void Temperature(double a);
int main(void)
{
	double f;
	int p;

	printf("Please input a Fahrenheit.\n");
	p = scanf_s("%lf", &f, 10);

	while (p>0)
	{
		Temperature(f);
		printf("Please input a Fahrenheit.\n");
		p=scanf_s("%f", &f, 10);
	}
	printf("Done!");
	getchar();
	getchar();
	getchar();
	return 0;
}
void Temperature(double a)
{
	const double n1 = 1.8;
	const double n2 = 32.0;
	const double n3 = 273.16;
	printf("Fahrenheit = %.2f\nClesius = %.2f\nKelvin = %.2f\n", a, n1*a + n2, n1*a + n2 + n2);
}