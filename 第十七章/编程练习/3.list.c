/*list.c -- 支持列表操作的函数*/
#include <stdio.h>
#include <stdlib.h>
#include "3.list.h"

/*接口函数*/
/*把列表设置为空列表*/
void InitializeList(List *plist)
{
	plist->items = 0;
}

/*如果列表为空就返回真*/
bool ListIsEmpty(const List *plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

/*如果列表已满就返回真*/
bool ListIsFull(const List *plist)
{
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

/*返回节点数*/
unsigned int ListItemCount(const List *plist)
{
	return plist->items;
}

/*创建存放项目的节点，并把它添加到*/
/*由plist指向的列表（较慢的实现方法）尾部*/
bool AddItem(Item item, List *plist)
{
	plist->entries[plist->items] = item;
	plist->items++;
	return true;
}

/*访问每个节点并对它们分别执行由pfun指向的函数*/
void Traverse(const List *plist, void(*pfun)(Item item))
{
	int t = plist->items-1;
	while (t >= 0)
	{
		(*pfun)(plist->entries[t]);	/*把函数作用于列表中的项目*/
		t--;
	}
}

/*释放由malloc()分配的内存*/
/*把列表指针设置为NULL*/
void EmptyTheList(List *plist)
{
	;
}
