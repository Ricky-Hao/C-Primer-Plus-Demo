#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void transform(double source[], double destinate[], int n, double(*fun_ptr)(double));
double fun1(double source);
double fun2(double source);

int main()
{
	int k = 0;
	double source[SIZE];
	double destinate[SIZE];
	double(*fun_ptr[])(double) = { sin, cos, fun1, fun2 };
	srand((int)time(0));
	for (int t = 0; t<SIZE; t++)
		source[t] = rand() / 6.28;
	while (k != -1)
	{
		puts("Please choose a function:");
		puts("a) sin() 		b) cos()");
		puts("c) fun1()		d) fun2()");
		puts("q) exit()		");
		switch (getchar())
		{
		case 'a':k = 0; break;
		case 'b':k = 1; break;
		case 'c':k = 2; break;
		case 'd':k = 3; break;
		case 'q':k = -1; break;
		}
		while (getchar() != '\n')
			continue;
		if (k != -1)
		{
			transform(source, destinate, SIZE, fun_ptr[k]);
			for (int i = 0; i < SIZE; i++)
			{
				printf("%.2lf ", destinate[i]);
				if (i == 20)
					putchar('\n');
			}
			putchar('\n');
		}
	}
	return 0;
}

void transform(double source[], double destinate[], int n, double(*fun_ptr)(double))
{
	for (int i = 0; i<n; i++)
		destinate[i] = fun_ptr(source[i]);
}

double fun1(double source)
{
	return source * 100;
}

double fun2(double source)
{
	return source * 10000;
}