#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNAME 40
#define LNAME 40
#define SEAT 12
#define FLIGHT 4

struct seats{
	int number;
	int empty;
	char fname[FNAME];
	char lname[LNAME];
};

void show_menu();
void get_menu();
void show_flight();
void show_a();
void show_b();
void show_c();
void sign_in();
void delete();
void return_empty();
void line();

int empty[SEAT];
struct seats seat[FLIGHT][SEAT];
int unempty[SEAT];
int flight = 0;
char flights[][10] = { "102", "311", "444", "519" };

int main()
{

	FILE *fp;
	int t = 0;

	for (int i = 0; i<FLIGHT; i++)
		for (t = 0; t<SEAT; t++)
		{
			seat[i][t].number = t + 1;
			seat[i][t].empty = 1;
			seat[i][t].fname[0] = '\0';
			seat[i][t].lname[0] = '\0';
		}

	if ((fp = fopen("seat.dat", "r+b")) == NULL)
	{
		fp = fopen("seat.dat", "w+b");
	}

	for (int i = 0; i<FLIGHT; i++)
		for (t = 0; fread(&seat[i][t], sizeof(struct seats), 1, fp) == 1; t++)
			;
	show_flight();

	rewind(fp);
	fwrite(&seat[0][0], sizeof(struct seats), FLIGHT*SEAT, fp);
	fclose(fp);
	return 0;
}

void show_menu()
{
	line();
	printf("Your are in Flight %s.\n", flights[flight]);
	puts("To choose a function,enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Back to Flight menu");
	get_menu();
}

void get_menu()
{
	line();
	char ch = getchar();
	while (getchar() != '\n')
		continue;
	switch (ch)
	{
	case 'a':show_a(); break;
	case 'b':show_b(); break;
	case 'c':show_c(); break;
	case 'd':sign_in(); break;
	case 'e':delete(); break;
	case 'f':show_flight(); break;
	}
}

void return_empty()
{
	for (int t = 0; t<SEAT; empty[t++] = -1)
		;
	for (int t = 0, i = 0; t<SEAT; t++)
		if (seat[flight][t].empty == 1)
			empty[i++] = t;
}

void return_unempty()
{
	line();
	for (int t = 0; t<SEAT; unempty[t++] = -1)
		;
	for (int t = 0, i = 0; t<SEAT; t++)
		if (seat[flight][t].empty == 0)
			unempty[i++] = t;

}

void show_a()
{
	line();
	printf("Current in Flight %s.\n", flights[flight]);
	int num = 0;
	return_empty();
	for (int t = 0; t<SEAT&&empty[t] != -1; t++)
		num++;
	printf("There are %d empty seats.\n", num);
	show_menu();
}

void show_b()
{
	line();
	printf("Current in Flight %s.\n", flights[flight]);
	return_empty();
	puts("The list of empty seats :");
	for (int t = 0; t<SEAT&&empty[t] != -1; t++)
	{
		printf("%d ", empty[t] + 1);
	}
	putchar('\n');
	show_menu();
}

void show_c()
{
	line();
	printf("Current in Flight %s.\n", flights[flight]);
	int t = 0;
	int i = 0;
	struct seats temp[SEAT], temp2;
	return_unempty();
	for (t = 0, i = 0; t<SEAT&&unempty[t] != -1; t++)
		temp[i++] = seat[flight][unempty[t]];
	for (i = 0; i<t; i++)
		for (int j = i + 1; j<t; j++)
		{
			if (temp[i].lname[0]>temp[j].lname[0])
			{
				temp2 = temp[i];
				temp[i] = temp[j];
				temp[j] = temp2;
			}
		}
	puts("Here is the list of seats:");
	for (int j = 0; j<i; j++)
	{
		printf("No.%d %s %s\n", temp[j].number, temp[j].lname, temp[j].fname);
	}
	show_menu();
}

void sign_in()
{
	line();
	printf("Current in Flight %s.\n", flights[flight]);
	return_empty();
	int t = 0;
	if (empty[0] == -1)
		puts("The seats is full.\n");
	else
	{
		puts("Please enter your first name:");
		puts("(Press [enter] at the start of a line to quit)");
		while (empty[t] != -1 && fgets(seat[flight][empty[t]].fname, FNAME, stdin) != NULL && seat[flight][empty[t]].fname[0] != '\n')
		{
			seat[flight][empty[t]].fname[strlen(seat[flight][empty[t]].fname) - 1] = '\0';
			puts("Please enter your last name.");
			fscanf(stdin, "%s", seat[flight][empty[t]].lname);
			while (getchar() != '\n')
				continue;
			seat[flight][empty[t++]].empty = 0;
			puts("Sign in successfully.");
			puts("Please enter your first name:");
			puts("(Press [enter] at the start of a line to quit)");
		}
	}
	show_menu();
}

void delete()
{
	line();
	int key = 0;
	printf("Current in Flight %s.\n", flights[flight]);
	char fname[FNAME];
	char lname[LNAME];
	puts("Please enter your first name:");
	scanf("%s", fname);
	while (getchar() != '\n')
		continue;
	puts("Please enter your last name:");
	scanf("%s", lname);
	while (getchar() != '\n')
		continue;
	for (int t = 0; t<SEAT; t++)
	{
		if (strcmp(seat[flight][t].fname, fname) == 0 && strcmp(seat[flight][t].lname, lname) == 0)
		{
			seat[flight][t].empty = 1;
			seat[flight][t].fname[0] = '\0';
			seat[flight][t].lname[0] = '\0';
			puts("Delete successful.");
			key = 1;
		}
	}
	if (key == 0)
		puts("Delete nsccessfully.");
	show_menu();
}

void show_flight()
{
	line();
	puts("Please choose a flight:");
	puts("a) Flight 102		b) Flight 311");
	puts("c) Flight 444		d) Flight 519");
	puts("q) Quit");

	char ch = getchar();
	while (getchar() != '\n')
		continue;
	switch (ch)
	{
	case 'a':flight = 0; show_menu(); break;
	case 'b':flight = 1; show_menu(); break;
	case 'c':flight = 2; show_menu(); break;
	case 'd':flight = 3; show_menu(); break;
	case 'q':break;
	}
}

void line()
{
	puts("****************************************************");
}