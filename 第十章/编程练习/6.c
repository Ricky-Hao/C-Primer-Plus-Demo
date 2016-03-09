#include <stdio.h>
#define ROWS 2
#define COLS 5
void copy_ptr(double(*p1)[COLS], double(*p2)[COLS]);
int main(void)
{
	double source[ROWS][COLS];
	double target[ROWS][COLS];
	int r, c;

	printf("Please enter %d x %d number into to the array:\n", ROWS, COLS);
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++, fflush(stdin))
			scanf_s("%lf", &source[r][c], 10);

	copy_ptr(source, target);

	return 0;
}

void copy_ptr(double(*p1)[COLS], double(*p2)[COLS])
{
	int r, c;

	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			*(*(p2 + r) + c) = *(*(p1 + r) + c);
}
