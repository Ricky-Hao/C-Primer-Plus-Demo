#include <stdio.h>
#include <ctype.h>
#define UPPER 100
#define LOWER 0
char get(char);
int main()
{
	int guess = 1;
	char ch = 0;
	int tu=UPPER;
	int tl = LOWER;
	int temp1 = 0;
	int temp = 0;
	int t = 0;

	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Respond with a y if my guess if right with n if it it wrong:\n");
	printf("My first guess is %d.\n", guess);

	do
	{
		if (t != 0)
		{
			if (t % 2 == 0)
				temp = guess;
			else
				temp1 = guess;
		}
		ch = get(ch);
		if (ch == 'y')
		{
			printf("I knew i could do it.");
			return 0;
		}
		else if (ch == 'n')
		{
			printf("Respond with 'u' if your number bigger than my guess,\n with 'l' if your number lower than my guess:\n");
			ch = get(ch);
			if (ch == 'u')
			{
				if (temp > temp1 && t!=0 && t!=1)
				{
					if (tu > temp && temp > guess)
						tu = temp;
				}
				else if (t!=0 && t!=1)
				{
					if (tu > temp1 && temp1 > guess)
						tu = temp1;
				}
				
				guess += (tu - guess) / 2;
				printf("The next number is %d ?\n", guess);
			}
			else if (ch == 'l')
			{
				if (temp< temp1 && t!=0 && t!=1)
				{ 
					if (tl < temp && temp < guess)
						tl = temp;
				}
				else if (t!=0 && t!=1)
				{
					if (tl < temp1 && temp1 < guess)
						tl = temp1;
				}
				guess -= (guess - tl) / 2;
				printf("The next number is %d ?\n", guess);
			}
			t++;
		}
		else
			printf("Please input a correct answer.\n");
	} while (ch != EOF);
	return 0;
}

char get(char)
{
	char ch;
	for (ch = 0; (islower(ch = getchar())) <= 0;);
	return ch;
}
