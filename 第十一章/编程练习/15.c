#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
int main(int n,char *in[])
{
	FILE *fp=NULL;
	int i=0;
	char ch[MAX];
	unsigned int num=0;

	/*in[0]="test";
	in[1]="1.txt";
	in[2]="-p";
	in[3]="-u";
	in[4]="-l";
	n=5;*/

	fp=freopen(in[1],"r",stdin);
	while(scanf("%c",&ch[i++])!=EOF);
	ch[i-1]='\0';
	printf("%s\n",ch);
	for (i=0; i < n; i++)
	{
		if (strcmp(in[i],"-p")==0)
			printf("%s\n", ch);
		if (strcmp(in[i],"-u")==0)
		{
			for (num = 0; num < strlen(ch); num++)
				*(ch + num) = toupper(*(ch + num));
			printf("%s\n", ch);
		}
		if (strcmp(in[i],"-l")==0)
		{
			for (num = 0; num < strlen(ch); num++)
				*(ch + num) = tolower(*(ch + num));
			printf("%s\n", ch);
		}
	}
	
	return 0;
}