#include <stdio.h>
#define FNAME 40
#define LNAME 40
#define MNAME 100
#define MAXID 5

struct data2{
char fname[FNAME];
char mname[MNAME];
char lname[LNAME];};

struct data1{
int id;
struct data2 name;};

void eatline();
void output(struct data1 person);

int main()
{
    struct data1 person[MAXID];
    int n=0;

    puts("Please enter the ID (press EOF to quit): ");

    while(n<MAXID&&(scanf("%d",&person[n].id)!=EOF))
	{
	    eatline();
		puts("Please enter the first name:");
		gets(person[n].name.fname);
		puts("Please enter the middle name(press [enter] don't have the middle name):");
		gets(person[n].name.mname);
		puts("Please enter the last name:");
		gets(person[n].name.lname);
        if(n<MAXID-1)
            puts("Please enter the ID (press EOF to quit): ");
		n++;
	}
	puts("Your information is: ");
	for(int t=0;t<n;t++)
        output(person[t]);
	puts("Bye.");
	return 0;
}

void eatline()
{
    while(getchar()!='\n')
        continue;
}

void output(struct data1 person)
{
		if(person.name.mname[0]!='\0')
			printf("%s, %s %c. - %d\n",person.name.fname,person.name.lname,person.name.mname[0],person.id);
		else
			printf("%s, %s - %d\n",person.name.fname,person.name.lname,person.id);
}
