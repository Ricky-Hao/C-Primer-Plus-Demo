//names3.c -- 使用指针和malloc()函数
#include <stdio.h>
#include <string.h>		//为了使用strcpy(),strlen()
#include <stdlib.h>		//为了使用malloc(),free()

struct namect{			//使用指针
	char * fname;
	char * lname;
	int letter;
};
void getinfo(struct namect *);	//分配内存
void makeinfo(struct namect*);
void showinfo(const struct namect *);
void cleanup(struct namect*);	//用完后释放

int main()
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);
	return 0;
}

void getinfo(struct namect * pst)
{
	char temp[81];
	printf("Please enter your first name.\n");
	gets(temp);
	//分配用来存放名字的内存
	pst->fname = (char*)malloc(strlen(temp) + 1);
	//把名字复制到已分配的内存中
	strcpy(pst->fname, temp);
	printf("Please enter your last name.\n");
	gets(temp);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst)
{
	pst->letter = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
	printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letter);
}

void cleanup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}