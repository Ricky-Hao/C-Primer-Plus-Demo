//for_show.c
#include <stdio.h>
int main(void)
{
	int num = 0;

	for (printf("Keep entering numbers!\n"); num != 6;)
		scanf_s("%d", &num);
	printf("That's the one I want!\n");
	getchar();
	getchar();
	return 0;
}
