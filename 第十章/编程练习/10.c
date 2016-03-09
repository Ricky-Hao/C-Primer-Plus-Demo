#include <stdio.h>
#define ROWS 3
#define COLS 5
void arr_print(int ar[][COLS], int rows);
void arr_double(int ar[][COLS], int rows);
void arr_fill(int ar[][COLS], int rows);

int main(void)
{
	int ar[ROWS][COLS];

	arr_fill(ar, ROWS);
	arr_print(ar, ROWS);
	arr_double(ar, ROWS);
	arr_print(ar, ROWS);

	return 0;
}

void arr_fill(int ar[][COLS], int rows)
{
	int r, c;

	for (r = 0; r < rows; r++)
		for (fflush(stdin), c = 0; c < COLS; c++, fflush(stdin))
			scanf_s("%d", &ar[r][c], 10);
}

void arr_print(int ar[][COLS], int rows)
{
	int r, c;

	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++ )
			printf("%d ", ar[r][c]);
	putchar('\n');
}

void arr_double(int ar[][COLS], int rows)
{
	int r, c;

	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			ar[r][c] = 2 * ar[r][c];
}
