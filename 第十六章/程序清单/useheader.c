//useheader.c -- 使用names_st结构
#include <stdio.h>
#include "names_st.h"
//记住链接names_st.h文件

int main()
{
	names candidate;
	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf(" to this program!\n");

	return 0;
}