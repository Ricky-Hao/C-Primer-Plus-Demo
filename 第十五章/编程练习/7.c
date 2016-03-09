#include <stdio.h>

#define SIZE_MOVE 		8
#define ALIGNMENT_MOVE	15
#define BOLD_MOVE		16
#define ITALIC_MOVE		17
#define UNDERLINE_MOVE	18
#define MASK_ID 		0xFF
#define MASK_SIZE 		0x7F00
#define MASK_ALIGNMENT 	0x18000
#define MASK_BOLD 		0x20000
#define MASK_ITALIC		0x40000
#define MASK_UNDERLINE 	0x80000

int show_menu(long *);
void show_font(long);
void _id(long *);
void _size(long *);
void _alignment(long *);
void _bold(long *);
void _italic(long *);
void _underline(long *);
void eatline();

int main()
{
	long font;
	int k=1;

	while(k==1)
		k=show_menu(&font);
	puts("Bye!");
	return 0;
}

int show_menu(long *font)
{
	char ch;
	int k=1;
	show_font(*font);
	puts("f)change font s)change size a)change alignment");
	puts("b)toggle bold i)toggle italic u)toggle underline");
	puts("q)quit");

	ch=getchar();

	switch(ch)
	{
		case 'f':_id(font);break;
		case 's':_size(font);break;
		case 'a':_alignment(font);break;
		case 'b':_bold(font);break;
		case 'i':_italic(font);break;
		case 'u':_underline(font);break;
		case 'q':k=0;
	}
	eatline();
	return k;
}

void show_font(long font)
{
	puts("ID 	SIZE 	ALIGNMENT 	B 	I 	U ");
	printf("%-8u%-8u",font&&MASK_ID,font>>SIZE_MOVE);
	if(font>>ALIGNMENT_MOVE==0)
		printf("  %-14s","left");
	else if(font>>ALIGNMENT_MOVE==1)
		printf("  %-14s","center");
	else if(font>>ALIGNMENT_MOVE==2)
		printf("  %-14s","right");
	else
		printf("  %-10s","unknown");
	printf("%-8s",font>>BOLD_MOVE==0?"off":"on");
	printf("%-8s",font>>ITALIC_MOVE==0?"off":"on");
	printf("%-8s\n\n",font>>UNDERLINE_MOVE==0?"off":"on");
}

void _id(long *font)
{
	printf("Enter font id (0-255):");
	int a=0;
	scanf("%d",&a);
	*font=a&MASK_ID;
}

void _size(long *font)
{
	printf("Enter font size (0-127):");
	int a=0;
	scanf("%d",&a);
	((*font)>>SIZE_MOVE)=a&MASK_SIZE;
}

void _alignment(long *font)
{
	puts("Selcet alignment:");
	puts("l)left c)center r)right");
	char ch;
	ch=getchar();

	switch(ch)
	{
		case 'l':*font>>ALIGNMENT_MOVE=0;break;
		case 'c':*font>>ALIGNMENT_MOVE=1;break;
		case 'r':*font>>ALIGNMENT_MOVE=2;break;
		default :*font>>ALIGNMENT_MOVE=3;
	}
}

void _bold(long *font)
{
	*font>>BOLD_MOVE=~(*font>>BOLD_MOVE);
}

void _italic(long *font)
{
	*font>>ITALIC_MOVE=~(*font>>ITALIC_MOVE);
}

void _underline(long *font)
{
	*font>>UNDERLINE_MOVE=~(*font>>UNDERLINE_MOVE);
}

void eatline()
{
	while(getchar()!='\n')
		continue;
}
