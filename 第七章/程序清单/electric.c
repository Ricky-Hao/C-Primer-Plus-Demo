//electric.c -- 计算用电账目
#include <stdio.h>
#define RATE1 0.12589//第一个360kWh的费率
#define RATE2 0.17901//下一个320kWh的费率
#define RATE3 0.20971//超过680kWh的费率
#define BREAK1 360.0//费率的第一个分界点
#define BREAK2 680.0//费率的第二个分界点
#define BASE1 (RATE1*BREAK1)//用电360kWh的费用
#define BASE2 (BASE1+(BREAK2-BREAK1))//用电680kWh的费用
int main(void)
{
	double kwh;//用电的千瓦小时数
	double bill;//费用

	printf("Please enter the kwh used.\n");
	scanf_s("%lf", &kwh, 100);//%lf是double的类型说明符

	if (kwh <= BREAK1)
		bill = RATE1*kwh;
	else if (kwh <= BREAK2)//用电在360kWh到680kWh之间时
		bill = BASE1 + (RATE2*(kwh - BREAK1));
	else//用电超出680kWh时
		bill = BASE2 + (RATE3*(kwh - BREAK2));

	printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);
	getchar();
	getchar();
	return 0;
}