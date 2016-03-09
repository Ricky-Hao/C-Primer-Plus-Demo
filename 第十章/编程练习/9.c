#include <stdio.h>
#define SIZE 4
void arr_sum_to(int ar1[], int ar2[], int ar3[], int n);
void arr_fill(int ar[], int n);
int main(void)
{
	int ar1[SIZE];
	int ar2[SIZE];
	int ar3[SIZE];

	arr_fill(ar1, SIZE);
	arr_fill(ar2, SIZE);
	arr_sum_to(ar1, ar2, ar3, SIZE);

	return 0;
}

void arr_fill(int ar[], int n)
{
	int t;
	
	for (fflush(stdin),t = 0; t < n; t++, fflush(stdin))
		scanf_s("%d", &ar[t], 10);
}

void arr_sum_to(int ar1[], int ar2[], int ar3[], int n)
{
	int t;
	for (t = 0; t < n; t++)
		ar3[t] = ar1[t] + ar2[t];
}
