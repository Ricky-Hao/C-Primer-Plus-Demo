#include <stdio.h>
#include "pe12-2a.h"

int set_mode(int mode)
{
	if (mode == 0)
		mode = 0;
	else if (mode == 1)
		mode = 1;
	else
	{
		printf("Invalid mode specified. Mode 1 (US) used.\n");
		mode = 1;
	}
	return mode;
}

int get_distance()
{
	int distance = 0;

	printf("Enter distance traveled in kilometers:");
	scanf("%d", &distance);
	return distance;
}
double get_info(int mode)
{
	double fuel;

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

	return fuel;
}

void show_info(double fuel, int distance, int mode)
{
	if (mode == 0)
	{
		printf("Fuel consumption is %.2lf liters per 100 km.\n", (fuel * 100) / (double)distance);
	}
	else
	{
		printf("Fuel consumed is %.1lf miles per gallon.\n", (double)distance / fuel);
	}
}