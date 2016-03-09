#include <stdio.h>

#define ID_MASK 		0xFF
#define SIZE_MASK 		0x7F

struct Font{
	unsigned int id 		:8;
	unsigned int size 		:7;
	unsigned int alignment	:2;
	unsigned int bold		:1;
	unsigned int italic		:1;
	unsigned int underline	:1;
};

int show_menu(struct Font *);
void _id(struct Font *);
void _size(struct Font *);
void _alignment(struct Font *);
void _bold(struct Font *);
void _italic(struct Font *);
void _underline(struct Font *);
void show_font(struct Font);
void eatline();
int main()
{
	struct Font font={1,1,1,1,1,1};
	int k=1;

	while(k==1)
		k=show_menu(&font);

	puts("Bye!");
	return 0;
}

void show_font(struct Font font)
{
	puts("ID 	SIZE 	ALIGNMENT 	B 	I 	U ");
	printf("%-8u%-8u",font.id,font.size);
	if(font.alignment==0)
		printf("  %-14s","left");
	else if(font.alignment==1)
		printf("  %-14s","center");
	else if(font.alignment==2)
		printf("  %-14s","right");
	else
		printf("  %-10s","unknown");
	printf("%-8s",font.bold==0?"off":"on");
	printf("%-8s",font.italic==0?"off":"on");
	printf("%-8s\n\n",font.underline==0?"off":"on");
}

int show_menu(struct Font *font)
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

void _id(struct Font *font)
{
	printf("Enter font id (0-255):");
	int a=0;
	scanf("%d",&a);
	font->id=a&ID_MASK;
}

void _size(struct Font *font)
{
	printf("Enter font size (0-127):");
	int a=0;
	scanf("%d",&a);
	font->size=a&SIZE_MASK;
}

void _alignment(struct Font *font)
{
	puts("Selcet alignment:");
	puts("l)left c)center r)right");
	char ch;
	eatline();
	ch=getchar();

	switch(ch)
	{
		case 'l':font->alignment=0;break;
		case 'c':font->alignment=1;break;
		case 'r':font->alignment=2;break;
		default :font->alignment=3;break;
	}
}

void _bold(struct Font *font)
{
	font->bold=~font->bold;
}

void _italic(struct Font *font)
{
	font->italic=~font->italic;
}

void _underline(struct Font *font)
{
	font->underline=~font->underline;
}

void eatline()
{
	while(getchar()!='\n')
		continue;
}
