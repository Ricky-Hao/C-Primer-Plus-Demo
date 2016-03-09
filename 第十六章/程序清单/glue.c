//glue.c -- 使用##运算符
#include <stdio.h>
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n"=%d\n",x ## n)

int main()
{
	int XNAME(1)=14;	//变为int x1=14;
	int XNAME(2)=20;	//变为int x2=20;
	PRINT_XN(1);		//变为printf("x1=%d\n",x1);
	PRINT_XN(2);		//变为printf("x2=%d\n",x2);
	return 0;
}