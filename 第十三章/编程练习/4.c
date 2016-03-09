#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int n = 0;
	FILE *fp;
	char temp[BUFSIZE];

	if (argc == 1)
	{
		printf("Please enter the filename.");
		exit(1);
	}

	for (n = 1; n < argc; n++)
	{
		if ((fp = fopen(argv[n], "r")) == NULL)
		{
			printf("Could not open the file %s.\n", argv[n]);
			exit(2);
		}
		fprintf(stdout, "%s\n", argv[n]);
		while ((fgets(temp, BUFSIZE, fp)) != NULL)
			fputs(temp, stdout);
		if (fclose(fp) != 0)
			printf("Could not close the file %s.\n", argv[n]);
		putchar('\n');
		putchar('\n');
	}
	return 0;
}