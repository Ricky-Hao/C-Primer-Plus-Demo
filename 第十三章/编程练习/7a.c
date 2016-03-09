#include <stdio.h>
#include <stdlib.h>
#define FNAME 1024
#define BUFSIZE 1024
int main()
{
	FILE *f1, *f2;
	char file_1[FNAME];
	char file_2[FNAME];
	char temp[BUFSIZE];
	int k;

	printf("Please enter the first filename: ");
	gets(file_1);
	printf("Please enter the second filename: ");
	gets(file_2);

	if ((f1 = fopen(file_1, "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", file_1);
		exit(1);
	}
	if ((f2 = fopen(file_2, "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", file_2);
		exit(2);
	}

	do
	{
		k = 0;
		if (fgets(temp,BUFSIZE,f1) !=NULL)
		{
			k = 1;
			fputs(temp, stdout);
		}
		if (fgets(temp,BUFSIZE,f2)!=NULL)
		{
			k = 1;
			fputs(temp, stdout);
		}
	} while (k);

	if (fclose(f1) != 0 || fclose(f2) != 0)
		fprintf(stdout, "Could not close the file.\n");

	return 0;
}