#include <stdio.h>
#include <stdlib.h>
#define FNAME 100
#define BUFSIZE 1024
#define ROW 20
#define COLUMN 30
void compare(char ar[][COLUMN + 1], int r, int c, int m);
int k = 0;

int main()
{
	FILE *fs, *fd;
	char file_s[FNAME];
	char file_d[FNAME];
	char temp[ROW][COLUMN+1];
	char contain[ROW][COLUMN+1];
	int r = 0, c = 0;

	puts("Please enter the source filename:");
	gets(file_s);
	puts("Please enter the destination filename: ");
	gets(file_d);

	if ((fs = fopen(file_s, "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", file_s);
		exit(1);
	}
	if ((fd = fopen(file_d, "w")) == NULL)
	{
		fprintf(stderr, "Could not create %s.\n", file_d);
		exit(2);
	}

	while (fgets(contain[r++], COLUMN + 2, fs) != NULL)
		;

	for (r = 0; r < ROW; r++)
		for (c = 0; c <= COLUMN; c++)
			temp[r][c] = contain[r][c];

	for (r = c = 0; r < ROW; r++)
	{
		for (c = 0; c < COLUMN; c++)
		{
			if (r == 0 && c == 0)
			{
				compare(contain, r, c, 2);
				compare(contain, r, c, 4);
				if (k == 0)
					temp[r][c] = (contain[r][c + 1] + contain[r + 1][c]) / 2;
				k = 0;
			}
			else if (r == 0 && c == COLUMN-1)
			{
				compare(contain, r, c, 2);
				compare(contain, r, c, 3);
				if (k == 0)
					temp[r][c] = (contain[r][c - 1] + contain[r + 1][c]) / 2;
				k = 0;
			}
			else if (r == ROW-1&&c == 0)
			{
				compare(contain, r, c, 1);
				compare(contain, r, c, 4);
				if (k == 0)
					temp[r][c] = (contain[r - 1][c] + contain[r][c + 1]) / 2;
				k = 0;
			}
			else if (r == ROW-1&&c == COLUMN-1)
			{
				compare(contain, r, c, 1);
				compare(contain, r, c, 3);
				if (k == 0)
					temp[r][c] = (contain[r - 1][c] + contain[r][c - 1]) / 2;
				k = 0;
			}
			else if (r == 0)
			{
				compare(contain, r, c, 2);
				compare(contain, r, c, 3);
				compare(contain, r, c, 4);
				if (k == 0)
					temp[r][c] = (contain[r][c - 1] + contain[r][c + 1] + contain[r + 1][c]) / 3;
				k = 0;
			}
			else if (r == ROW-1)
			{
				compare(contain, r, c, 1);
				compare(contain, r, c, 3);
				compare(contain, r, c, 4);
				if (k == 0)
					temp[r][c] = (contain[r][c - 1] + contain[r][c + 1] + contain[r - 1][c]) / 3;
				k = 0;
			}
			else if (c == 0)
			{
				compare(contain, r, c, 1);
				compare(contain, r, c, 2);
				compare(contain, r, c, 4);
				if (k == 0)
					temp[r][c] = (contain[r - 1][c] + contain[r + 1][c] + contain[r][c + 1]) / 3;
				k = 0;
			}
			else if (c == COLUMN-1)
			{
				compare(contain, r, c, 1);
				compare(contain, r, c, 2);
				compare(contain, r, c, 3);
				if (k == 0)
					temp[r][c] = (contain[r - 1][c] + contain[r + 1][c] + contain[r][c - 1]) / 3;
				k = 0;
			}
			else
			{
				compare(contain, r, c, 1);
				compare(contain, r, c, 2);
				compare(contain, r, c, 3);
				compare(contain, r, c, 4);
				if (k == 0)
					temp[r][c] = (contain[r][c + 1] + contain[r][c - 1] + contain[r + 1][c] + contain[r - 1][c]) / 4;
				k = 0;
			}
		}
	}

	for (r = 0; r < ROW; r++)
		for (c = 0; c < COLUMN; c++)
		{
			switch (temp[r][c])
			{
			case '0':contain[r][c] = ' ';
				break;
			case '1':contain[r][c] = '.';
				break;
			case '2':contain[r][c] = '\'';
				break;
			case '3':contain[r][c] = ':';
				break;
			case '4':contain[r][c] = '~';
				break;
			case '5':contain[r][c] = '*';
				break;
			case '6':contain[r][c] = '=';
				break;
			case '7':contain[r][c] = '&';
				break;
			case '8':contain[r][c] = '%';
				break;
			case '9':contain[r][c] = '#';
				break;
			default:;
			}
		}

	fprintf(fd, "%s", contain[0]);

	if (fclose(fs) != 0)
		fprintf(stderr, "Error closing %s.\n", file_s);
	if (fclose(fd) != 0)
		fprintf(stderr, "Error closing %s.n", file_d);

	return 0;
}

void compare(char ar[][COLUMN + 1], int r, int c, int m)
{
	if (k != 0)
		return;
	if (m == 1)
	{
		if (abs(ar[r][c] - ar[r - 1][c]) < 1)
			k = 1;
	}
	else if (m == 2)
	{
		if (abs(ar[r][c] - ar[r + 1][c]) < 1)
			k = 1;
	}
	else if (m == 3)
	{
		if (abs(ar[r][c] - ar[r][c - 1]) < 1)
			k = 1;
	}
	else if (m == 4)
	{
		if (abs(ar[r][c] - ar[r][c + 1]) < 1)
			k = 1;
	}
}