#include <stdio.h>
#define ROWS 3
#define COLS 5
void arr_fill(double ar[][COLS]);
void arr_ave_one(double ar[][COLS]);
void arr_ave_all(double ar[][COLS]);
void arr_max(double ar[][COLS]);
int main(void)
{
	double ar[ROWS][COLS];

	arr_fill(ar);
	arr_ave_one(ar);
	arr_ave_all(ar);
	arr_max(ar);

	return 0;
}

void arr_fill(double ar[][COLS])
{
	int r, c;

	for (r = 0; r < ROWS; r++)
		for (fflush(stdin), c = 0; c < COLS; c++, fflush(stdin))
			scanf_s("%lf", &ar[r][c], 10);
}

void arr_ave_one(double ar[][COLS])
{
	int r, c;
	double sum = 0;

	for (r = 0; r < ROWS; r++)
	{
		for (sum = 0, c = 0; c < COLS; c++)
			sum += ar[r][c];
		printf("The %d contain's average is %.1f.\n", r + 1, sum / COLS);
	}
}

void arr_ave_all(double ar[][COLS])
{
	int r, c;
	double sum = 0;

	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			sum += ar[r][c];
	printf("The average of all the number is %.1f.\n", sum / (ROWS*COLS));
}

void arr_max(double ar[][COLS])
{
	int r, c;
	double t[ROWS];
	int temp = 0;
	r = c = 0;

	for (r = 0; r < ROWS; r++)
	{
		for (temp = 0, c = 0; c < COLS; c++)
		{
			while ((ar[r][temp] >= ar[r][c]) && (c < COLS - 1))
				c++;
			if (ar[r][temp] > ar[r][c])
			{
				t[r] = ar[r][temp];
			}
			else if ((ar[r][temp] <= ar[r][c]) && (c == COLS - 1))
			{
				t[r] = ar[r][c];
			}
			else
			{
				temp = c;
			}
		}
	}

	for (temp = r = 0; r < ROWS;)
	{
		while ((t[temp] >= t[r + 1]) && (r < ROWS - 1))
			r++;
		if ((t[temp] >= t[r]) && (r == ROWS - 1))
			break;
		r++;
		temp = r;
	}

	printf("The max number in the array is %.1lf.\n", t[temp]);
}