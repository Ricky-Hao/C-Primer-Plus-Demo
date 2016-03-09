#include <stdio.h>
void a();
void b();
void c();
void d();
void(*fun_ptr[])() = { a, b, c, d };
int k = 1;
int main()
{
	while (k)
	{
		puts("Please choose a function:");
		puts("a) a		b) b");
		puts("c) c 		d) quit");
		fun_ptr[getchar() - 'a']();
		while (getchar() != '\n')
			continue;
	}
	return 0;
}

void a()
{
	puts("a");
}

void b()
{
	puts("b");
}

void c()
{
	puts("c");
}

void d()
{
	k = 0;
}