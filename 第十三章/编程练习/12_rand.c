#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FNAME 100
#define BUFSIZE 1024
#define ROW 20
#define COLUMN 30

int main()
{
	FILE *fp;
	char temp[BUFSIZE];
	char file[FNAME];

	printf("Please enter a filename: ");
	gets(file);

	if ((fp = fopen(file, "w")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n");
		exit(1);
	}
	srand((unsigned)time(NULL));
	for (int row = 0; row < ROW; row++)
	{
		for (int column = 0; column < COLUMN; column++)
		{
			fputc((rand()%10+'0'), fp);
		}
		fputc('\n', fp);
	}

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing %s.\n", file); 

	return 0;
}