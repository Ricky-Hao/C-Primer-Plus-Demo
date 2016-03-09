/*funds2.c -- 传递指向结构的指针*/
#include <stdio.h>
#define FUNDLEN 50
struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum(const struct funds *);	/*参数是一个指针*/

int main()
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"lucky's Saving and Loan",
		9237.11,
	};

	printf("Stan has a total if $%.2f.\n", sum(&stan));
	return 0;
}
/*对两个double数值求和*/
double sum(const struct funds *money)
{
	return (money->bankfund+money->savefund);
}