#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	double temp;
	long int n;
	char * end;

	temp = strtod(argv[1], &end);
	n = atoi(argv[2]);

	for (; n > 0; n--)
		temp *= strtod(argv[1], &argv[2]);
	printf("%.2lf\n", temp);
	return 0;
}