/*complit.c -- 复合文字*/
#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book{	//结构模板;标记是book
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main()
{
	struct book readfirst;
	int score;

	printf("Enter test score: ");
	scanf("%d", &score);

	if (score >= 84)
		readfirst = (struct book){
		"Crime and Punishment",
			"Fyodor Doestoyevsky",
			9.99
	};

	else
		readfirst = (struct book){
		"Mr. Bouncy's Nice Hat",
			"Fred Winsome",
			5.99
	};
	printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);
	return 0;
}
