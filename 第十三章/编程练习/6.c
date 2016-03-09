#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main()
{
	FILE *in, *out;
	int ch;
	char file_in[LEN];
	char file_out[LEN];
	int count = 0;

	printf("Please enter a filename: ");
	gets(file_in);

	if ((in = fopen(file_in, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \" %s \"\n", file_in);
		exit(2);
	}

	strcpy(file_out, file_in);
	strcat(file_out, ".red");

	if ((out = fopen(file_out, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}

	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files.\n");

	return 0;
}