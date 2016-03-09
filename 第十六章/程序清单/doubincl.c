//doubincl.c -- 两次包含同一头文件
#include <stdio.h>
#include "names_st.h"
#include "names_st.h"	//不小心两次包含同一头文件

int main()
{
	names winner={"Less","Ismoor"};
	printf("The winner is %s %s.\n",winner.first,winner.last);
	return 0;
}