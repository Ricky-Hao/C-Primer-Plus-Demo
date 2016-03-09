/*booksave.c -- 把结构内容保存到文件里*/
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 401
#define MAXBKS 10			//图书的最多本数
struct book{				//建立book模板
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main()
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	int size = sizeof(struct book);
	int list[MAXBKS];
	int t = 0;

	puts("Do you want to create or update?");
	puts("(press [c] ot create, press [u] to update)");
	if (getchar() == 'c')
	{
		if ((pbooks = fopen("book.dat", "w+b")) == NULL)
		{
			fputs("Can't open book.dat file\n", stderr);
			exit(1);
		}
	}
	else
	{
		if ((pbooks = fopen("book.dat", "r+b")) == NULL)
		{
			fputs("Can't open book.dat file\n", stderr);
			exit(1);
		}
	}
	while (getchar() != '\n')
		continue;
	rewind(pbooks);
	while (count < MAXBKS&&fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		puts("Would you want to delete it (press [y] to delete or [n] to next)?");
		if (getchar() == 'y')
		{
			list[t++] = count;
		}
		while (getchar() != '\n')
			continue;
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}

	for (; t > 0; t--)
	{
		library[list[t - 1]] = library[count];
		count--;
	}

	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS&&gets(library[t>0 ? list[t - 1] : count].title) != NULL&&library[t>0 ? list[t - 1] : count].title[0] != '\0')
	{
		puts("Now enter the author.");
		gets(library[t>0 ? list[t - 1] : count].author);
		puts("Now enter the value.");
		scanf("%f", &library[t>0 ? list[t - 1] : count++].value);
		t--;
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Enter the next title.");
	}


	if (count > 0)
	{
		puts("Here is the list of your books: ");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		fclose(pbooks);
		pbooks = fopen("book.dat", "w+b");
		fwrite(&library[0], size, count, pbooks);
	}
	else
		puts("No books? Too bad.\n");
	puts("Bye.\n");
	fclose(pbooks);
	return 0;
}