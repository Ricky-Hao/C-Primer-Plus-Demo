/*films1.c -- 使用结构数组*/
#include <stdio.h>
#define TSIZE 45	/*存放片名的数组大小*/
#define FMAX 5		/*最多的影片数*/

struct film
{
	char title[TSIZE];
	int rating;
};
int main()
{
	struct film movies[FMAX];
	int i = 0;
	int j;

	puts("Enter first movie title: ");
	while (i<FMAX&&gets(movies[i].title) != NULL&&movies[i].title[0] != '\0')
	{
		puts("Enter your rating <0-10>: ");
		scanf_s("%d", &movies[i++].rating, 1);
		while (getchar() != '\n')continue;
		puts("Enter next movie title (empty line to stop): ");
	}
	if (i == 0)
		printf("No data entered. ");
	else
		printf("Here is the movie list: \n");

	for (j = 0; j<i; j++)
		printf("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
	printf("Bye\n");
	return 0;
}