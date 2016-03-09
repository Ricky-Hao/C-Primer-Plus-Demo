#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNAME 100
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[100];
	char temp[BUFSIZE];

	if (argc < 3)
	{
		fprintf(stderr, "Please enter a string and a source file.\n");
		exit(1);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Could not open the file %s.\n", argv[2]);
		exit(2);
	}

	while (fgets(temp, BUFSIZE, fp) != NULL)
	{
		if (strstr(temp, argv[1]) != NULL)
		{
			fputs(temp, stdout);
		}
	}

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing %s.\n");

	return 0;
}