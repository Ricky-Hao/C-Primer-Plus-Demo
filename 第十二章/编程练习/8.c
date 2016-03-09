//pe12-8.c
#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
	int *pa;
	int size, value;

	printf("Enter the number of elements:");
	scanf("%d", &size);
	while (size > 0)
	{
		printf("Enter the initialization value:");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit):");
		scanf("%d", &size);
	}
	printf("Done.\n");
	return 0;
}


int * make_array(int elem, int val)
{
	int * ptr;

	ptr = (int *)malloc(elem*sizeof(int));
	for (int t = 0; t < elem; ptr[t++] = val)
		;
	return ptr;
}

void show_array(const int ar[], int n)
{
	int t = 0;
	for (; t < n; t++)
	{
		if ((t % 8 == 0)&&t!=0)
			printf("\n");
		printf(" %d", ar[t]);
	}
	putchar('\n');
}
