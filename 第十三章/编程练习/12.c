#include <stdio.h>
#include <stdlib.h>
#define FNAME 100
#define BUFSIZE 1024
#define ROW 20
#define COLUMN 30

int main()
{
	FILE *fs, *fd;
	char file_s[FNAME];
	char file_d[FNAME];
	char temp[BUFSIZE];
	char ch = 0;
	int t = 0;

	puts("Please enter the source filename:");
	gets(file_s);
	puts("Please enter the destination filename: ");
	gets(file_d);

	if ((fs = fopen(file_s, "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", file_s);
		exit(1);
	}
	if ((fd = fopen(file_d, "w")) == NULL)
	{
		fprintf(stderr, "Could not create %s.\n", file_d);
		exit(2);
	}

	while ((ch = fgetc(fs))!=EOF)
	{
		switch (ch)
		{
		case '0':ch = ' ';
			break;
		case '1':ch = '.';
			break;
		case '2':ch = '\'';
			break;
		case '3':ch = ':';
			break;
		case '4':ch = '~';
			break;
		case '5':ch = '*';
			break;
		case '6':ch = '=';
			break;
		case '7':ch = '&';
			break;
		case '8':ch = '%';
			break;
		case '9':ch = '#';
			break;
		default:;
		}

		temp[t++] = ch;
		if (t == 31)
		{
			temp[t] = '\0';
			fputs(temp, fd);
			t = 0;
		}
	}

	if (fclose(fs) != 0)
		fprintf(stderr, "Error closing %s.\n", file_s);
	if (fclose(fd) != 0)
		fprintf(stderr, "Error closing %s.n", file_d);

	return 0;
}