#include <stdio.h>
#include <stdlib.h>
#define MAX 40
void add(FILE *fp,int n);
int main(void)
{
	FILE *fp;
	char words[MAX];
	int last = 0;
	int num = 0;
	char c[10];

	if ((fp = fopen("words", "a+")) == NULL)
	{
		fprintf(stdout, "Can't oipen \"words\" file.\n");
		exit(1);
	}
	puts("Enter words to add to the file:press the EOF");
	fseek(fp, 0, SEEK_END);
	last = ftell(fp);
	if (last == 0)
	{
		rewind(fp);
		add(fp, 1);
	}
	else
	{
		fseek(fp, -3, SEEK_END);
		fgets(c, 2, fp);
		num=atoi(c);
		fseek(fp,0, SEEK_END);
		add(fp, num+1);
	}
	puts("File contents: ");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
	{
		fprintf(stdout, "%s", words);
		putchar('\n');
	}
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file.\n");
	return 0;
}

void add(FILE *fp, int n)
{
	int count = n;
	char c[MAX];
	char words[MAX];
	while (scanf("%s",&words) ==1)
	{
		_itoa(count, c, 10);
		fprintf(fp, "%s(%s) ", words,c);
		count++;
	}
}