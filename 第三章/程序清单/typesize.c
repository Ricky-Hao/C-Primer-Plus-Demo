//typesize.c -- ������͵Ĵ�С
#include <stdio.h>
int main(void)
{
	//c99Ϊ���ʹ�С�ṩһ��%zd˵����
	printf("Type int has a size of %u bytes.\n", sizeof(int));
	printf("Type char has a size of %u bytes.\n", sizeof(char));
	printf("Type long has a size of %u bytes.\n", sizeof(long));
	printf("Type double has a size of %u bytes.\n", sizeof(double));
	getchar();
	return 0;
}
