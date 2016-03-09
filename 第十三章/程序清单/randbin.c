/*randbin.c -- 随机存取，二进制I/O*/
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main()
{
	double numbers[ARSIZE];
	double value;
	const char *file = "numbers.dat";
	int i;
	long pos;
	FILE *iofile;
	//创建一组double类型的值
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0*i + 1.0 / (i + 1);
	//尝试打开文件
	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Couldn't open %s for output.\n", file);
		exit(1);
	}
	//把数组中的数据以二进制形式写到文件中
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Couldn't open %s for random access.\n", file);
		exit(1);
	}
	//从文件中读取所选的项目
	printf("Enter an index in the range 0-%d\n", ARSIZE - 1);
	scanf("%d", &i);
	while (i >= 0 && i < ARSIZE)
	{
		pos = (long)i*sizeof(double);		//计算偏移量
		fseek(iofile, pos, SEEK_SET);		//在文件中定位到那里
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index (out of range to quit): \n");
		scanf("%d", &i);
	}
	fclose(iofile);
	puts("Bye!");
	return 0;
}