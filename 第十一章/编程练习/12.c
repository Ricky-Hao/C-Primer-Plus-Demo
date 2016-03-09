#include <stdio.h>
int main(int argc, char *argv[])
{
	for (; argc > 0; argc--)
		printf("%s", argv[argc]);
	return 0;
}