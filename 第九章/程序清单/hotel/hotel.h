//hotel.h -- hotel.c中的常量定义和函数声明
#include <stdio.h>
#define QUIT 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define DISCOUNT 0.95
#define STARS "**********************************"

//给出选项列表
int menu(void)
{
	int code, status;

	printf("\n%s%s\n", STARS, STARS);
	printf("Enter the number of the desired hotel: \n");
	printf("1) Fairfield Arms 2) Hotel Olympic\n");
	printf("3) Chertworthy Plaza 4) The Stockton\n");
	printf("5) Qiut\n");
	printf("%s%s\n", STARS, STARS);

	while ((status = scanf_s("%d", &code, 100)) != 1 || (code < 1 || code>5))
	{
		if (status != 1)
			scanf_s("%*s");
		printf("Enter an integer from 1 to 5, please.\n");
	}
	return code;
}

//返回预定天数
int getnights(void)
{
	int nights;

	printf("How many nights are needed? ");

	while (scanf_s("%d", &nights, 100) != 1)
	{
		scanf_s("%*s");
		printf("Please enter an inteer, such as 2.\n");
	}
	return nights;
}

//按饭店的星级和预定天数计算价格并显示出来
void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for (n = 1; n <= nights; n++, factor *= DISCOUNT)
		total += rate*factor;
	printf("The total cost will be $%0.2f.\n", total);
}
