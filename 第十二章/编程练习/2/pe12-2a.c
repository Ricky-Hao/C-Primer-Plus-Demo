#include <stdio.h>
#include "pe12-2a.h"

static int mode;
static int distance;
static double fuel;

void set_mode(int a)
{
	if (a == 0)
		mode = 0;
	else if (a == 1)
		mode = 1;
	else
	{
		printf("Invalid mode specified. Mode 1 (US) used.\n");
		mode = 1;
	}
}

void get_info(void)
{
	printf("Enter distance traveled in kilometers:");
	scanf("%d", &distance);

	if (mode == 0)
	{
		printf("Enter fuel consumed in liters:");
		scanf("%lf", &fuel);
	}
	else
	{
		printf("Enter fuel conumed in gallons:");
		scanf("%lf", &fuel);
	}
}

void show_info(void)
{
	if (mode == 0)
	{
		printf("Fuel consumption is %.2lf liters per 100 km.\n", (fuel*100) / (double)distance);
	}
	else
	{
		printf("Fuel consumed is %.1lf miles per gallon.\n", (double)distance/fuel);
	}
}