#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	int n,sum,num,ave;
	n=num=sum=0;
	ave=0;

	printf("Please input the text:\n");
	while((ch=getchar())!=EOF)
	{
		for(;isalpha(ch);n++,ch=getchar())
			;
		if(n!=0)
		{
			sum+=n;
			num++;
			n=0;
		}
	}
	if (num==0)
		num=1;
	ave=sum/num;
	printf("%d",ave);
	return 0;
}
