#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int count = 0;
	char c;

	if (argc < 3)
	{
		puts("Please enter the character and the filenames.\n");
		exit(1);
	}

	for (int n = 2; n < argc; n++)
	{
		if ((fp = fopen(argv[n], "r")) == NULL)
		{
			printf("Could not open the file %s.\n");
		}
		else
		{
			while ((c = fgetc(fp)) != EOF)
			{
				if (ferror(fp) != 0)
				{
					printf("Error in reading %s.\n", argv[n]);
					continue;
				}
				if (c == argv[1][0])
					count++;
			}
			if (ferror(fp) != 0)
				continue;
			printf("The character %c has been showed in the file %s %d times.\n", argv[1][0], argv[n], count);
			count = 0;
		}
		if (fclose(fp) != 0)
			printf("Error in closing %s.\n", argv[n]);
	}

	return 0;
}