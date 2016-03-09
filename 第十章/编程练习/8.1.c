#include <stdio.h>
#define ROWS 2
#define COLS 5
void fill_arr(double ar[][COLS]);
void copy_arr(double source[][COLS], double target[][COLS]);
void print_ptr(double(*p)[COLS]);
int main(void)
{
	double source[ROWS][COLS];
	double target[ROWS][COLS];

	fill_arr(source);
	copy_arr(source, target);
	print_ptr(source);
	print_ptr(target);

	return 0;
}

void fill_arr(double ar[][COLS])
{
	int r, c;

	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			scanf_s("%lf", &ar[r][c], 10);
}

void copy_arr(double source[][COLS], double target[][COLS])
{
	int r, c;

	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			target[r][c] = source[r][c];
	putchar('\n');
}

void print_ptr(double(*p)[COLS])
{
	int r, c;

	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			printf("%lf ", *(*(p + r) + c));
}

