/*queue.h -- 队列接口*/
#pragma c9x on
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

/*在此处插入Item的类型定义*/
/*例如： */
typedef struct item
{
	long arrive;		//一位顾客加入队列的时间
	int processtime;	//该顾客需要的咨询时间
}Item;
/*或：typedef struct item {int gumption;int charisma;}Item;*/

#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node *next;
}Node;

typedef struct queue
{
	Node *front;		//指向队列首的指针
	Node *rear;			//指向队列尾的指针
	int items;
}Queue;

//操作：初始化队列
//操作前：pq指向一个队列
//操作后：该队列被初始化为空队列
void InitializeQueue(Queue *pq);

//操作：检查队列是否已满
//操作前：pq指向一个先前已初始化的队列
//操作后：如果该队列已满，则返回true；否则返回false
bool QueueIsFull(const Queue *pq);

//操作：检查队列是否为空
//操作前：pq指向一个先前已初始化的队列
//操作后：如果该队列为空，则发返回true；否则返回false
bool QueueIsEmpty(const Queue *pq);

//操作：确定队列中项目的个数
//操作前：pq指向一个先前已初始化的队列
//操作后：返回队列中项目的个数
int QueueItemCount(const Queue *pq);

//操作：向队列微端添加项目
//操作前：pq指向一个先前已初始化过的队列
//		  item是要添加到队列尾端的项目
//操作后：如果队列未满，item被添加到队列尾部，
//		  函数返回true；否则不改变队列，函数返回false
bool EnQueue(Item item, Queue *pq);

//操作：从队列首端删除项目
//操作前：pq指向一个先前已初始化的队列
//操作后：如果队列非空，队列首端的项目
//		  被复制到*pitem，并被从队列中删除
//		  函数返回true；如果这个操作
//		  使队列为空，把队列重置为空队列
//		  如果队列开始时为空，
//		  不改变队列，函数返回false
bool DeQueue(Item *pitem, Queue *pq);

//操作：清空队列
//操作前：pq指向一个先前已初始化的队列
//操作后：队列被清空
void EmptyTheQueue(Queue *pq);

#endif