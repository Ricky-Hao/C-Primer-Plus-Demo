#include <stdio.h>
#define SIZE 7
#define SIZE2 3
#define START 3
void copy_arr(double source[SIZE],double target[SIZE2], int n);
int main(void)
{
	double source[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = SIZE2;
	double target[SIZE2];

	copy_arr(source, target, SIZE2);

	return 0;
}

void copy_arr(double source[SIZE], double target[SIZE2], int n)
{
	int t;
	int c = START-1;

	for (t = 0; t < n; t++, c++)
		target[t] = source[c];
}