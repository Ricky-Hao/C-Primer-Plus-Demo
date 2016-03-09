#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 32
#define SIZE 10
struct names
{
	char fname[NAME_SIZE];
	char lname[NAME_SIZE];
};

int mycmp(const void *, const void *);
void get_info(struct names *);
void print_info(struct names[], int n);

int main()
{
	struct names names[SIZE];
	int c = 0;
	int t = 0;
	do
	{
		puts("1) Fill names  2) Sort names ");
		puts("3) Print names 4) Quit");
		scanf_s("%d", &c, 1);
		while (getchar() != '\n')
			continue;
		switch (c)
		{
		case 1:get_info(&names[t++]); break;
		case 2:qsort(names, t, sizeof(struct names), mycmp); break;
		case 3:print_info(names, t); break;
		case 4:exit(0);
		}
	} while (1);
	return 0;
}

int mycmp(const void *p1, const void *p2)
{
	const struct names *a1 = (const struct names *)p1;
	const struct names *a2 = (const struct names *)p2;
	if (a1->fname[0]>a2->fname[0])
		return 1;
	else if (a1->fname[0] == a2->fname[0])
		return 0;
	else
		return -1;
}

void get_info(struct names *names)
{
	puts("Please enter your first name: ");
	scanf_s("%s", names->fname, NAME_SIZE);
	puts("Please enter your last name: ");
	scanf_s("%s", names->lname, NAME_SIZE);
}

void print_info(struct names names[], int n)
{
	for (int t = 0; t<n; t++)
		printf("%s %s\n", names[t].lname, names[t].fname);
}