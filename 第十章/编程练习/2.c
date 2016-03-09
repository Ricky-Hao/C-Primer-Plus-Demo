#include <stdio.h>
void copy_arr(double ar[][5], double ar1[][5], int n);
void copy_ptr(double ar[][5], double(*p)[5], int n);
int main(void)
{
	double ar[2][5] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 0 } };
	double ar1[2][5];
	double ar2[2][5];

	copy_arr(ar, ar1, 2);
	copy_ptr(ar, ar2, 2);

	return 0;
}

void copy_arr(double ar[][5], double ar1[][5], int n)
{
	int t = 0;
	for (; n > 0; n--)
		for (t = 0; t < 5; t++)
			ar1[n-1][t] = ar[n-1][t];
}

void copy_ptr(double(*p)[5], double(*p1)[5], int n)
{
	int t = 0;
	for (; n > 0; n--)
		for (t = 0; t < 5; t++)
			*(*(p1 + n-1) + t) = *(*(p + n-1) + t);
}