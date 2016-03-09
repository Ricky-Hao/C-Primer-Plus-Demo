#include <stdio.h>
#include <stdlib.h>

#define FNAME 1000
int main()
{
	int ch;
	FILE *fp;
	long count=0;
	char files[FNAME];

	printf("Enter the file name:");
	scanf("%s", &files);
	if ((fp = fopen(files, "r")) == NULL)
	{
		printf("Can't open %s\n", files);
		exit(1);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters\n", files, count);
	return 0;
}