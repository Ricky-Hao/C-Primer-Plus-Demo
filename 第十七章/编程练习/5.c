#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
	char ch;
	struct stack *prev;
}Stack;

int main()
{
	Stack *list;
	Stack *temp;
	Stack *head;

	head = (Stack *)malloc(sizeof(Stack));
	if (head == NULL)
	{
		fprintf(stderr, "Error in malloc\n");
		exit(1);
	}

	list = head;
	list->ch = '\0';
	list->prev = NULL;

	while ((list->ch=getchar()) != EOF)
	{
		temp = (Stack *)malloc(sizeof(Stack));
		if (temp == NULL)
		{
			fprintf(stderr, "Error in malloc\n");
			break;
		}
		temp->prev = list;
		list = temp;
		list->ch = '\0';
	}

	if (list->ch == '\0')
		printf("No data.\n");
	else
	{
		while (list->prev != NULL)
		{
			putchar(list->ch);
			list = list->prev;
		}
	}
	return 0;
}