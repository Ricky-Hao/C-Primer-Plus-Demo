#include <stdio.h>
int main(void)
{
	float high;
	char name[10];
	scanf_s("%f %s", &high, name);
	printf("%s, you are %.3f feet tall.\n", name, high);
	getchar();
	getchar();
	return 0;
}
