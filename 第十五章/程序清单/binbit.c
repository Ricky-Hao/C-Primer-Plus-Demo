/*binbit.c -- 使用位运算符显示二进制数*/
#include <stdio.h>
void itobs(int, char *);
void show_bstr(const char *);
int main()
{
	char bin_str[8 * sizeof(int) + 1];
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Bye!");
	return 0;
}

void itobs(int n, char *ps)
{
	int i;
	int size = 8 * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}

/*4位一组显示二进制字符串*/
void show_bstr(const char*str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}