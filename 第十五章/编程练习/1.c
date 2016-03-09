#include <stdio.h>
#include <string.h>
#include <math.h>
int fun(char *ptr);
int main()
{
	char str[33];
	int num;
	while(scanf("%s",str)!=EOF)
	{
		num=fun(str);
		printf("%d\n",num);
	}
	return 0;
}

int fun(char *str)
{
	int num;
	num=0;
	int l=strlen(str);
	for(int t=l-1;t>=0;t--)
	{
		num+=(str[t]-'0')*pow(2.0,l-t-1);
	}
	return num;
}
