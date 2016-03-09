//manydice.c -- 多次掷骰子的模拟程序
//与diceroll.c 一起编译
#include  "diceroll.h"		//为roll_n_dice()和roll-count函数提供原型
#include <stdio.h>
#include <stdlib.h>			//为srand()函数提供原型
#include <time.h>			//为time()函数提供原型
#include <string.h>


int main(void)
{
	int dice, sides, sets;
	char temp[10];

	srand((unsigned int)time(0));		//随机化种子
	do
	{
		printf("Enter the number of sets; enter q to stop.\n");
		scanf("%s", &temp);
		if (strcmp(temp, "q")==0)
			exit(0);
		sets = atoi(temp);
		printf("How many sides and how many dice ?\n");
		scanf("%d %d", &dice, &sides);
		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		while (sets-- >= 0)
			printf("%d ", roll_n_dice(dice, sides));
		putchar('\n');
	} while (1);

	return 0;
}