/*list.c -- 支持列表操作的函数*/
#include <stdio.h>
#include <stdlib.h>
#include "2.list.h"

/*局部函数原型*/
static void CopyToNode(Item item, Node *pnode);

/*接口函数*/
/*把列表设置为空列表*/
void InitializeList(List *plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

/*如果列表为空就返回真*/
bool ListIsEmpty(const List *plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

/*如果列表已满就返回真*/
bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;
	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;
}

/*返回节点数*/
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = plist->head;	/*设置到列表的开始处*/

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;	/*把l设置为下一个节点*/
	}
	return count;
}

/*创建存放项目的节点，并把它添加到*/
/*由plist指向的列表（较慢的实现方法）尾部*/
bool AddItem(Item item, List *plist)
{
	Node *pnew;
	Node *scan = plist->head;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;		/*失败时退出*/

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)			/*空列表，因此把pnew*/
		plist->head = pnew;		/*放在列表头部*/
	else
	{
		while (scan->next != NULL)
			scan = scan->next;	/*找到列表结尾*/
		scan->next = pnew;	/*把pnew添加到结尾处*/
		plist->end = pnew;
	}
	return true;
}

/*访问每个节点并对它们分别执行由pfun指向的函数*/
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode = plist->head;			/*设置到列表的开始处*/
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);	/*把函数作用于列表中的项目*/
		pnode = pnode->next;
	}
}

/*释放由malloc()分配的内存*/
/*把列表指针设置为NULL*/
void EmptyTheList(List *plist)
{
	Node *psave;
	while (plist->head != NULL)
	{
		psave = (plist -> head)->next;		/*保存下一节点的地址*/
		free(plist->head);
		plist -> head = psave;
	}
}

/*局部函数定义*/
/*把一个项目复制到一个节点中*/
static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}