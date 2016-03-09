#include <stdio.h>
int main(void)
{
	int count, sum, days;
	count = 0;
	sum = 0;

	printf("Please input how many days do you want.\n");
	scanf_s("%d", &days, 100);

	while (count++ < days){
		sum = sum + count;
		printf("You will earn %d $ in the %d day\n", sum, count);
	}
	printf("Done!");
	getchar();
	getchar();
	return 0;
}