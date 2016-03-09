//talkback.c --一个能为您提供一些信息的程序
#include <stdio.h>
#include <string.h>
#define DENSITY 62.4
int main(void)
{
	float weight, volume;
	int size, letters;
	char name[40];
	printf("Hi,What's your first name?\n");
	scanf_s("%s", name);
	printf("%s,what's your weight in pounds?\n", name);
	scanf_s("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Well,%s,your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also,your first name has %d letters.\n", letters);
	printf("and we have %d bytes to store it in.\n", size);
	getchar ();
	getchar ();
	return 0;
}
