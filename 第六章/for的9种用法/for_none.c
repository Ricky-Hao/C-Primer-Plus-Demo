//for_none.c
#include <stdio.h>
int main(void)
{
	int ans, n;

	ans = 2;
	for (n = 3; ans <= 25;)
		ans *= n;
	printf("n = %d; ans = %d.\n", n, ans);
	getchar();
	return 0;
}
