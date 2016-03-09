//pe12-2b.c
#include <stdio.h>
#include "pe12-2a.h"
int main(void)
{
	int mode = 0;
	int distance = 0;
	double fuel = 0;

	printf("Enter 0 for metric mode, 1 for US mode:");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		mode = set_mode(mode);
		distance = get_distance();
		fuel = get_info(mode);
		show_info(fuel, distance, mode);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf("(-1 to quit):");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}