#include <stdio.h>

enum months{start,Jan,Feb,Mar,Apr,May,Jun,Jly,Aug,Sep,Oct,Nov,Decz};
struct days{
int year;
int month;
int day;
};
int main()
{
    struct days date;
	enum months data;
	int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	while(scanf("%d %d %d",&date.year,&date.month,&date.day)!=EOF)
		{
			for(data=(enum months)(date.month-1);data>=Jan;data--)
			{
				date.day+=months[data];
			}
			printf("%d\n",date.day);
		}
		return 0;
}
