#include <stdio.h>
#define YEARS 5
#define MONTHS 12
void arr_sum_rows(const float ar[][MONTHS], int rows);
void arr_sum_cols(const float ar[][MONTHS], int rows);
int main(void)
{
	const float rain[YEARS][MONTHS] = {
			{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
			{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
			{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
			{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
			{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};

	printf(" YEAR RAINFALL (inches) \n");
	arr_sum_rows(rain, YEARS);

	printf("MONTHLY AVERAGES:\n\n");
	arr_sum_cols(rain, YEARS);

	return 0;
}

void arr_sum_rows(const float ar[][MONTHS], int rows)
{
	int r, c;
	float sum = 0;
	float tot = 0;

	for (r = 0; r < rows; r++, printf("%5d %15.1f\n", 2000 + rows, sum), tot += sum)
		for (c = 0, sum = 0; c < MONTHS; c++)
			sum += ar[r][c];

	printf("\nThe yearly average is %.1f inches.\n\n", tot / rows);
}

void arr_sum_cols(const float ar[][MONTHS], int rows)
{
	int r, c;
	float sum = 0;

	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
	for (c = 0; c < MONTHS; c++, printf("%4.1f ", sum / YEARS))
		for (r = 0, sum = 0; r < rows; r++)
			sum += ar[r][c];
}
