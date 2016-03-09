#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int l,l2,t;
	l=strlen(argv[1]);
	l2=strlen(argv[2]);
	puts("~");
	for(t=0;t<l;t++)
		printf("%c",argv[1][t]=='1'?'0':'1');
	putchar('\n');
	for(t=0;t<l2;t++)
		printf("%c",argv[2][t]=='1'?'0':'1');
	puts("\n&");
	for(t=0;t<(l>l2?l2:l);t++)
		printf("%c",(argv[1][t]=='1'&&argv[2][t]=='1')?'1':'0');
	for(;t<(l>l2?l:l2);t++)
		printf("%c",argv[l>l2?1:2][t]);
	puts("\n|");
	for(t=0;t<(l>l2?l2:l);t++)
		printf("%c",(argv[1][t]=='1'||argv[2][t]=='1')?'1':'0');
	for(;t<(l>l2?l:l2);t++)
		printf("%c",argv[l>l2?1:2][t]);
	puts("\n^");
	for(t=0;t<(l>l2?l2:l);t++)
		printf("%c",((argv[1][t]=='1'&&argv[2][t]=='0')||(argv[1][t]=='0'&&argv[2][t]=='1'))?'1':'0');
	for(;t<(l>l2?l:l2);t++)
		printf("%c",argv[l>l2?1:2][t]);
	putchar('\n');
	return 0;
}