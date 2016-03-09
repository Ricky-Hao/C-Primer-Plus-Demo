#include <stdio.h>
#define SIZE 5
int arr_max(int ar[SIZE]);
int main(void)
{
	int ar[SIZE];
	int t = 0;

	printf("Please input 5 integer:\n");
	for (t = 0; t < 5; t++)
	{
		scanf_s("%d", &ar[t], 4);
		fflush(stdin);
	}

	printf("The max number in the array is %d.\n", arr_max(ar));
	return 0;
}

int arr_max(int ar[SIZE])
{
	int t = 0;
	int n = 0;
	
	for (t = 0; t < SIZE; )
	{
		n = t;
		while (ar[t]>ar[n+1] && n < SIZE-1)
			n++;
		if (ar[t]>ar[n+1])
			break;
		else
		{
			t = n;
			t++;
		}
	}
	return ar[t];
}