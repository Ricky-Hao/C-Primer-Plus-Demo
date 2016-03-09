#include <stdio.h>
#define FUN(x,y) (1/((1/x+1/y)/2))

int main()
{
	double x, y;
	while (scanf("%lf %lf", &x, &y) == 2)
		printf("%.2lf\n", FUN(x, y));
	return 0;
}