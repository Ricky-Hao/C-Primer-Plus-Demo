#include <stdio.h>
#include <string.h>

struct{
	char month[10];
	int day;
	int number;
}days;

int main()
{
	puts("Please enter the month: ");
	gets(days.month);
	puts("Please enter the day: ");
	scanf("%d", &days.day);
	puts("Please enter the number of month: ");
	scanf("%d", &days.number);

	printf("This is input:  %s(%d) %d.\n", days.month, days.number, days.day);

	return 0;
}