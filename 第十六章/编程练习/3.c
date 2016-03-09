#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897
struct xy trans(struct position);
struct position
{
	double r;
	double c;
};

struct xy
{
	double x;
	double y;
};

int main()
{
	struct position pos;
	while (scanf("%lf %lf", &pos.r, &pos.c) == 2)
		printf("x = %.4lf y = %.4lf\n", trans(pos).x, trans(pos).y);
	return 0;
}

struct xy trans(struct position pos)
{
	struct xy xy;
	xy.x = pos.r*cos(PI / 180 * pos.c);
	xy.y = pos.r*sin(PI / 180 * pos.c);
	return xy;
}