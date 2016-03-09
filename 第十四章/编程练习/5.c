#include <stdio.h>
#define FNAME 40
#define LNAME 40
#define CSIZE 4
struct name {
	char fname[FNAME];
	char lname[LNAME];
};

struct student{
	struct name name;
	double grade[3];
	double average;
};

int main()
{
	struct student student[CSIZE];
	int n = 0;
	puts("Please enter your first name (press [enter] at the start of a line to quit):");
	while (gets(student[n].name.fname) != NULL && student[n].name.fname[0] != '\0'&&n < CSIZE)
	{
		puts("Please enter your last name:");
		gets(student[n].name.lname);
		puts("Please enter you scores as score1 score2 score3:");
		scanf("%lf %lf %lf", &student[n].grade[0], &student[n].grade[1], &student[n].grade[2]);
		while (getchar() != '\n')
			continue;
		student[n].average = (student[n].grade[0] + student[n].grade[1] + student[n].grade[2]) / 3;
		n++;
		if (n<CSIZE)
			puts("Please enter your first name (press [enter] at the start of a line to quit):");
	}
	for (int t = 0; t < n; t++)
		printf("%s %s score: %.2lf %.2lf %.2lf average: %.2lf\n", student[t].name.lname, student[t].name.fname, student[t].grade[0], student[t].grade[1], student[t].grade[2], student[t].grade[2], student[t].average);
	for (int i = 0; i < 3; i++)
	{
		double temp = 0;
		for (int t = 0; t < n; t++)
			temp += student[t].grade[i];
		printf("The class %d average is %.2lf\n",i+1, temp/n);
	}
	return 0;
}