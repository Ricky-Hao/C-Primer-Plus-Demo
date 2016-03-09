#include <stdio.h>
#define WEEK 7
int main(void)
{
	int weeks, days1, days2;

	printf("Please input the days.\n");
	scanf_s("%d", &days1, 100);

	while (days1 > 0)
	{
		weeks = days1 / WEEK;
		days2 = days1%WEEK;
		printf("%d days are %d weeks, %d days.\n", days1, weeks, days2);
		printf("Please input the another days.\n");
		scanf_s("%d", &days1, 100);
	}
	printf("Done!");
	getchar();
	getchar();
	return 0;
}
