#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define FNAME 1000
#define SIZE 1024
int main()
{
	FILE *fs, *fd;
	char temp[SIZE];
	char file_s[FNAME];
	char file_d[FNAME];
	char c;

	printf("Please enter the source file name: ");
	scanf("%s", &file_s);
	printf("Please enter the destinate file name: ");
	scanf("%s", &file_d);

	if (strcmp(file_s, file_d) == 0)
	{
		printf("Please enter the different filename.");
		exit(3);
	}
	if ((fs = fopen(file_s, "r")) == NULL)
	{
		printf("Could not open the file %s.", file_s);
		exit(1);
	}
	if ((fd = fopen(file_d, "w")) == NULL)
	{
		printf("Could not create the file %s.", file_d);
		exit(2);
	}

	while (fscanf(fs, "%c", &c) == 1)
	{
		fprintf(fd, "%c", toupper(c));
	}

	if (fclose(fs) != 0)
		printf("Could not close the file %s", file_s);
	if (fclose(fd) != 0)
		printf("Could not close the file %s", file_d);

	return 0;
}