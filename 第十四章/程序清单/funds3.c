/*funds3.c -- 把结构作为参数传递*/
#include <stdio.h>
#define FUNDLEN 50

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum(struct funds moolah);	/*参数是一个结构*/

int main()
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"lucky's Saving and Loan",
		9237.11,
	};

	printf("Stan has a total if $%.2f.\n", sum(stan));
	return 0;
}
/*对两个double数值求和*/
double sum(struct funds moolah)
{
	return (moolah.bankfund+moolah.savefund);
}