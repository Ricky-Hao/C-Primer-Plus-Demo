#include <stdio.h>
#define MIN 60
int main(void)
{
	int min,hour;

	printf("Please enter the minutes.\n");
	scanf_s("%d", &min, 100);
	
	while (min > 0)
	{
		hour = min/MIN;
		min = min%MIN;
		printf("The time is %d hour(s) and %d minute(s).\n",hour,min);
		printf("Please enter the next minutes.\n");
		scanf_s("%d", &min, 100);
	}
	printf("Done!");
	getchar();
	getchar();
	return 0;
}