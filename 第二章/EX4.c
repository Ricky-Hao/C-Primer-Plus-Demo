//p31 ex 4
#include <stdio.h>
void con (void);
void last (void);
int main (void)
{
 con ();
 con ();
 con ();
 last ();
 getchar();
 return 0;
 }
  	void con (void)
 {
  printf("For he's a jolly good fellow!\n");
 }
	void last (void)
 {
  printf("Which nobody can deny!");
 }