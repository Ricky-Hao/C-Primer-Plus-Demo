#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	FILE *fa, *fs;
	int files = 0;
	int n = 0;

	if (argc < 3)
	{
		fputs("Please enter the append filename and the source filename.\n", stdout);
		exit(1);
	}
	if ((fa = fopen(argv[1], "a")) == NULL)
	{
		fprintf(stderr, "Could not open %s\n", argv[2]);
		exit(2);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Could not create output buffer.\n", stderr);
		exit(3);
	}
	for (n = 2; n < argc; n++)
	{
		if (strcmp(argv[1], argv[n]) == 0)
			fputs("Could not append file to itself.\n", stderr);
		else if ((fs = fopen(argv[n], "r")) == NULL)
			fprintf(stderr, "Could not open %s.\n", argv[n]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Could not create input buffer.\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", argv[n]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error jin writing file %s.\n", argv[1]);
			fclose(fs);
			files++;
			printf("File %s appenned.\n", argv[n]);
		}
	}
	printf("Done. %d files appened.\n", files);
	fclose(fa);
	return 0;
}

void append(FILE *source, FILE*dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}