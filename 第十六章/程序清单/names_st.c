//names_st.c -- 定义names_st函数
#include <stdio.h>
#include "names_st.h"	//包含头文件

//函数定义
void get_names(names *pn)
{
	int i;

	printf("Please enter your first name:");
	fgets(pn->first, SLEN, stdin);
	i = 0;
	while (pn->first[i] != '\n'&&pn->first[i] != '\0')
		i++;
	if (pn->first[i] == '\n')
		pn->first[i] = '\0';
	else
		while (getchar() != '\n')
			continue;

	printf("Please enterr your last name:");
	fgets(pn->last, SLEN, stdin);
	i = 0;
	while (pn->last[i] != '\n'&&pn->last[i] != '\0')
		i++;
	if (pn->last[i] == '\n')
		pn->last[i] = '\0';
	else
		while (getchar() != '\n')
			continue;
}

void show_names(const names *pn)
{
	printf("%s %s", pn->first, pn->last);
}