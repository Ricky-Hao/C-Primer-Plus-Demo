/*films2.c -- 使用结构链表*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
	struct film *next;
	struct film *prev;
};

int main(void)
{
	struct film *head = NULL;
	struct film *prev, *current;
	char input[TSIZE];

	/*收集并储存信息*/
	puts("Enter first movie title: ");
	while (gets(input) != NULL&&input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)	/*第一个结构*/
		{
			head = current;
			head->prev=NULL;
		}
		else			/*后续结构*/
		{
			current->prev=prev;
			prev->next = current;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>: ");
		scanf_s("%d", &current->rating, 1);
		while (getchar() != '\n')continue;
		puts("Enter next movie title (empty line to stop): ");
		prev = current;
	}

	/*给出电影列表*/
	if (head == NULL)
		printf("No data entered. ");
	else
		printf("Here is the movie list: \n");

	while (current != NULL)
	{
		printf("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->prev;
	}
	current = head;
	while (current != NULL)
	{
		printf("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}
	/*任务已完成，因此释放所分配内存*/
	current = head;
	while (current != NULL)
	{
		struct film *temp = current->next;
		free(current);
		current = temp;
	}
	printf("Bye!\n");
	return 0;
}