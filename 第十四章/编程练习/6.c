#include <stdio.h>
#include <stdlib.h>
#define FNAME 40
#define LNAME 40
#define SIZE 18
struct playerdata{
	int number;
	char lname[LNAME];
	char fname[FNAME];
	int attend;
	int hit;
	int base;
	int RBI;
	double rate;
};

int main()
{
	struct playerdata player[SIZE];
	FILE *fp;
	int n = 0;
	char c;
	int attend, hit, base, RBI;

	for (n = 0; n < SIZE; n++)
	{
		player[n].number = n;
		player[n].lname[0] = '\0';
		player[n].fname[0] = '\0';
		player[n].attend = 0;
		player[n].hit = 0;
		player[n].base = 0;
		player[n].RBI = 0;
		player[n].rate = 0;
	}

	puts("Please enter 'write' or 'read' to continue:");
	c=getchar();
	while (getchar() != '\n')
		continue;
	if (c == 'w')
	{
		n = 0;
		if ((fp = fopen("player.data", "a+b")) == NULL)
		{
			fprintf(stderr, "Could open player.data.\n");
			exit(11);
		}
		puts("Open file successfully.");
		puts("Please enter the player data as ");
		puts("No. Lastname Firstname Attend Hit Base RBI");
		while (n<SIZE&&scanf("%d %s %s %d %d %d %d", &player[n].number, player[n].lname, player[n].fname, &player[n].attend, &player[n].hit, &player[n].base, &player[n].RBI) != EOF)
		{
			fseek(fp, 0, SEEK_END);
			fwrite(&player[n], sizeof(player[n]), 1, fp);
			puts("Please enter the player data as ");
			puts("No. Lastname Firstname Attend Hit Base RBI");
		}
		if (fclose(fp) != 0)
		{
			fprintf(stderr, "Error closing player.data.\n");
			exit(22);
		}
	}
	else if (c == 'r')
	{
		if ((fp = fopen("player.data", "rb")) == NULL)
		{
			fprintf(stderr, "Could not open player.data.\n");
			exit(12);
		}
		fseek(fp, 0, SEEK_SET);
		while (fgetc(fp) != EOF)
		{
			n = attend = hit = base = RBI = 0;
			fseek(fp, -1, SEEK_CUR);
			fread(&n, sizeof(int), 1, fp);
			n--;
			player[n].number = n + 1;
			fgets(player[n].lname, LNAME, fp);
			fseek(fp, 1, SEEK_CUR);
			fgets(player[n].fname, FNAME, fp);
			fseek(fp, 1, SEEK_CUR);
			fread(&attend, sizeof(int), 1, fp);
			player[n].attend += attend;
			fread(&hit, sizeof(int), 1, fp);
			player[n].hit += hit;
			fread(&base, sizeof(int), 1, fp);
			player[n].base += base;
			fread(&RBI, sizeof(int), 1, fp);
			player[n].RBI += RBI;
			player[n].rate = (double)player[n].hit / (double)player[n].attend;
			fseek(fp, sizeof(double) + sizeof(int), SEEK_CUR);
		}
		if (fclose(fp) != 0)
		{
			fprintf(stderr, "Error closing player.data.\n");
			exit(22);
		}
		if ((fp = fopen("player.data", "w+b")) == NULL)
		{
			fprintf(stderr, "Could not open player.data.\n");
			exit(14);
		}
		fseek(fp, 0, SEEK_SET);
		for (n = 0; n < SIZE; n++)
		{
			fwrite(&player[n], sizeof(player[n]), 1, fp);
			printf("No.%d %s %s Attend: %d Hit: %d Base: %d RBI: %d Rate: %.2lf\n", player[n].number, player[n].lname, player[n].fname, player[n].attend, player[n].hit, player[n].base, player[n].RBI, player[n].rate);
		}
		if (fclose(fp) != 0)
		{
			fprintf(stderr, "Error closing player.data.\n");
			exit(23);
		}
	}
	return 0;
}