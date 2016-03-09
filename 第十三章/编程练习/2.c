#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FNAME 1000
#define BUFFER 1024

int main(int argc,char *argv[])
{
	FILE *fs, *fd;
	char temp[BUFFER];
	size_t bytes;

	if (argc <3)
	{
		printf("Please enter a source file name and a destinate file name.");
		exit(3);
	}
	if ((strcmp(argv[0], argv[1]) == 0) || (strcmp(argv[0], argv[2]) == 0) || (strcmp(argv[1], argv[2]) == 0))
	{
		printf("Please enter different file name.\n");
		exit(4);
	}
	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		printf("Could not open %s.\n", argv[1]);
		exit(1);
	}

	if ((fd = fopen(argv[2], "wb")) == NULL)
	{
		printf("Could not create %s.\n", argv[2]);
		exit(2);
	}

	while ((bytes = fread(temp, sizeof(char), BUFFER, fs)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, fd);
	}

	if (fclose(fs) != 0)
		printf("Could not close the file %s.\n", argv[1]);
	if (fclose(fd) != 0)
		printf("Could not close the file %s.\n", argv[2]);

	return 0;
}