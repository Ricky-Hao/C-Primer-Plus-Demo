#include <stdio.h>
#include <time.h>

void time_delay(double times);

int main()
{
	double times;
	while (scanf("%lf", &times) != EOF)
		time_delay(times);
		return 0;
}

void time_delay(double times)
{
	double start = (double)clock();
	double end;
	times *= CLOCKS_PER_SEC;
	for (end = (double)clock(); end<times + start;end = (double)clock())
		;
	printf("%.4lf %.4lf\n", start/CLOCKS_PER_SEC , end/CLOCKS_PER_SEC );
}