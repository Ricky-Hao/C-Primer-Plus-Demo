#include <stdio.h>
int return_open(int num);
int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("%d\n",return_open(num));
	}
	return 0;
}

int return_open(int num)
{
	int k=0;
	int t=0;
	for(t=0;num>0;t++)
	{
		if(num%2==1)
			k++;
		num/=2;
	}
	return k;
}