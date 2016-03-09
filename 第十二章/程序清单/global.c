/*global.c -- 使用外部变量*/
#include <stdio.h>
int units=0;		//一个外部变量
void critic(void);
int main(void)
{
	extern int units;	//可选的二次声明

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d",&units);
	while(units!=56)
		critic();
	printf("You must have looked it up!\n");
	return 0;
}

void critic(void)
{
	//这里省略了可选的二次声明
	printf("No luck, chummy. Try again.\n");
	scanf("%d",&units);
}
