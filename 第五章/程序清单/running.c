//running.c -- 一个对于长跑运动员有用的程序
#include <stdio.h>
const int S_PER_M = 60;//每分钟的秒数
const int S_PER_H = 3600;//每小时的秒数
const double M_PER_K = 0.62137;//每公里的英里数
int main(void)
{
	double distk, distm;//分别以公里和英里记的跑过的距离
	double rate;//以英里/小时为单位的平均速度
	int min, sec;//跑步用时的分钟数和秒数
	int time;//用秒表示的跑步用时
	double mtime;//跑完1英里所用的时间，以秒计
	int mmin, msec;//跑完1英里所用的时间，以分钟和秒计
	printf("This program converts your time for metric race\n");
	printf("to a time fpr running a mile and to your average\n");
	printf("speed in miles per hour.\n");
	printf("Please enter, in kilometers, the distance run.\n");
	scanf_s("%lf", &distk, 100);// %lf 表示读取一个double类型的数值
	printf("Next enter the time in minutes and seconds.\n");
	printf("Begin by entering the minutes.\n");
	scanf_s("%d", &min, 100);
	printf("Now enter the seconds.\n");
	scanf_s("%d", &sec, 100);
	time = S_PER_M*min + sec;//把时间转化为全部用秒表示
	distm = M_PER_K*distk;//把公里转化为英里
	rate = distm / time*S_PER_H;//英里/秒*秒/小时=英里/小时
	mtime = (double)time / distm;//时间/距离=跑完每英里的用时
	mmin = (int)mtime / S_PER_M;//求出分钟数
	msec = (int)mtime%S_PER_M;//求出剩余时间
	printf("You ran %1.2f km(%1.2f miles) in %d min, %d sec.\n", distk, distm, min, sec);
	printf("That pace corresponds to running a mile in %d min,", mmin);
	printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
	getchar();
	getchar();
	return 0;
}