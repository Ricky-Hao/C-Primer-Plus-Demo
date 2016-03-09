#include <stdio.h>
void rotate(unsigned int num,int n);
int main()
{
	int num=0;
	int n=0;
	while(scanf("%d %d",&num,&n)!=EOF)
		rotate(num,n);
	return 0;
}

void rotate(unsigned int num,int n)
{
	char temp='0';
	int t=0;
	char str[32];
	while(num>0)
	{
		if(num%2==1)
			str[t]='1';
		else
			str[t]='0';
		num/=2;
		t++;
	}
	for(int i=t-1;i>=0;printf("%c",str[i--]))
		;
	putchar('\n');
	for(int i=0;i<n;i++)
	{
		temp=str[t-1];
		for(int j=t-1;j>0;j--)
			str[j]=str[j-1];
		str[0]=temp;
	}
	for(int i=t-1;i>=0;printf("%c",str[i--]))
		;
	putchar('\n');
}