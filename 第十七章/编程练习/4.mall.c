//mall.c -- 使用Queue接口
//与queue2.c一起编译
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue2.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);		//有新顾客到来吗？
Item customertime(long when);	//设置顾客参量

struct shop
{
	Queue line;
	Item temp;					//关于新顾客的数据
	int hours;					//模拟小时数
	int perhour;				//每小时顾客的平均数
	long cycle, cyclelimit;		//循环计数器，计数器的上界
	long turnaways;				//因队列已满而被拒绝的顾客数
	long customers;				//被加入队列的顾客数
	long served;				//在模拟期间得到服务的顾客数
	long sum_line;				//累计的队列长度
	int wait_time;				//从当前到Sigmund空闲所需的时间
	double min_per_cust;		//顾客到来的平均时间间隔
	long line_wait;				//队列累计等待时间
};

int main()
{
	struct shop shop1;
	struct shop shop2;

	InitializeQueue(&(shop1.line));
	InitializeQueue(&(shop2.line));
	
	shop1.turnaways = 0;
	shop1.customers = 0;
	shop1.served = 0;
	shop1.sum_line = 0;
	shop1.wait_time = 0;
	shop1.line_wait = 0;

	shop2.turnaways = 0;
	shop2.customers = 0;
	shop2.served = 0;
	shop2.sum_line = 0;
	shop2.wait_time = 0;
	shop2.line_wait = 0;

	srand(time(0));
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours (shop1 shop2): ");
	scanf("%d %d", &shop1.hours, &shop2.hours);
	shop1.cyclelimit = MIN_PER_HR*shop1.hours;
	shop2.cyclelimit = MIN_PER_HR*shop2.hours;
	puts("Enter the average number of customer per hour (shop1 shop2): ");
	scanf("%d %d", &shop1.perhour, &shop2.perhour);
	shop1.min_per_cust = MIN_PER_HR / shop1.perhour;
	shop2.min_per_cust = MIN_PER_HR / shop2.perhour;

	for (shop1.cycle = 0; shop1.cycle<shop1.cyclelimit; shop1.cycle++)
	{
		if (newcustomer(shop1.min_per_cust))
		{
			if (QueueIsFull(&(shop1.line)))
				shop1.turnaways++;
			else
			{
				shop1.customers++;
				shop1.temp = customertime((shop1.cycle));
				EnQueue(shop1.temp, (&shop1.line));
			}
		}
		if (shop1.wait_time == 0 && !QueueIsEmpty(&(shop1.line)))
		{
			DeQueue(&shop1.temp, &shop1.line);
			shop1.wait_time = shop1.temp.processtime;
			shop1.line_wait += shop1.cycle - shop1.temp.arrive;
			shop1.served++;
		}
		if (shop1.wait_time>0)
			shop1.wait_time--;
		shop1.sum_line += QueueItemCount(&(shop1.line));
	}

	if (shop1.customers>0)
	{
		printf("customers accepted: %ld\n", shop1.customers);
		printf("  customers served: %ld\n", shop1.served);
		printf("      turnaways: %ld\n", shop1.turnaways);
		printf("average queue size: %.2f\n", (double)shop1.sum_line / shop1.cyclelimit);
		printf(" average wait time: %.2f minutes\n", (double)shop1.line_wait / shop1.served);
	}
	else
		puts("No customers!");
	EmptyTheQueue(&(shop1.line));

	for (shop2.cycle = 0; shop2.cycle<shop2.cyclelimit; shop2.cycle++)
	{
		if (newcustomer(shop2.min_per_cust))
		{
			if (QueueIsFull(&shop2.line))
				shop2.turnaways++;
			else
			{
				shop2.customers++;
				shop2.temp = customertime(shop2.cycle);
				EnQueue(shop2.temp, &shop2.line);
			}
		}
		if (shop2.wait_time == 0 && !QueueIsEmpty(&shop2.line))
		{
			DeQueue(&shop2.temp, &shop2.line);
			shop2.wait_time = shop2.temp.processtime;
			shop2.line_wait += shop2.cycle - shop2.temp.arrive;
			shop2.served++;
		}
		if (shop2.wait_time>0)
			shop2.wait_time--;
		shop2.sum_line += QueueItemCount(&(shop2.line));
	}

	if (shop2.customers>0)
	{
		printf("customers accepted: %ld\n", shop2.customers);
		printf("  customers served: %ld\n", shop2.served);
		printf("      turnaways: %ld\n", shop2.turnaways);
		printf("average queue size: %.2f\n", (double)shop2.sum_line / shop2.cyclelimit);
		printf(" average wait time: %.2f minutes\n", (double)shop2.line_wait / shop2.served);
	}
	else
		puts("No customers!");
	EmptyTheQueue(&shop2.line);
	puts("Bye!");

	return 0;
}

//x是顾客到来的平均间隔时间（以秒计）
//如果这1分钟内有顾客到来，则返回true
bool newcustomer(double x)
{
	if (rand()*x / RAND_MAX<1)
		return true;
	else
		return false;
}

//when是顾客到来的时间
//函数返回一个Item结构，该结构的顾客到来时间设置为when
//需要的咨询时间设置为一个范围在1到3之间的随机值
Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}