#include <stdio.h>
int return_value(int num,int k);
int main()
{
	int num,k;
	while(scanf("%d %d",&num,&k)!=EOF)
		printf("%d\n",return_value(num,k-1));
	return 0;
}

int return_value(int num,int k)
{
	int c=0;
	for(int t=0;t<=k;t++)
	{
		if(t==k)
			c=(num%2==1)?1:0;
		num/=2;
	}
	return c;
}
