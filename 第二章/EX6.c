//p31 ex6
#include <stdio.h>
void s(void);
int main(void)
{
	s(), s(), s(), printf("\n");

	s(), s(), printf("\n");

	s(),printf("\n");
	getchar();
}
void s(void)
{
	printf("%s","Smile!");

}