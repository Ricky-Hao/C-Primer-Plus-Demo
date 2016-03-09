#include <stdio.h>
#include <stdlib.h>
#define FNAME 1024
#define BUFSIZE 1024
int main()
{
	FILE *fp;
	char file[FNAME];
	int n;
	char temp[BUFSIZE];
	
	printf("Please enter a filename: ");
	gets(file);

	if ((fp = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Could not open the file %s.\n", file);
		exit(1);
	}

	puts("Please enter a number: ");
	while (scanf("%d", &n) == 1)
	{
		fseek(fp, n, SEEK_SET);
		fgets(temp, BUFSIZE - 1, fp);
		fputs(temp, stdout);
		putchar('\n');
		n = 0;
	}

	if (fclose(fp) != 0)
		fprintf(stderr, "Could not close the file %s.\n", file);
	
	return 0;
}