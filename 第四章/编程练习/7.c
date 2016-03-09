#include <stdio.h>
#define L 3.785
#define KM 1.609
int main(void)
{
	float mile, ga;
	printf("Please input the mile and gallon.\n");
	scanf_s("%f %f", &mile, &ga);
	printf("You drive %.1f mile per gallon\n", mile / ga);
	printf("And you consume %.1f L per 100KM.\n", (mile / ga) * 100 * (L / KM));
	getchar();
	getchar();
	return 0;
}