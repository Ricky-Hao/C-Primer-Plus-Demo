/*r_drive.c -- 测试rand0()函数		*/
/*与rand0.c一起编译					*/
#include <stdio.h>
extern int rand0(void);

int main(void)
{
	int count;

	for (count = 0; count < 5; count++)
		printf("%hd\n", rand0());

	return 0;
}