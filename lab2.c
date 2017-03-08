#include <stdio.h>
#include <locale.h>

int clrscr()  //Очистка консолі
{
	printf("\033[2J");
	printf("\033[0;0f");
	return 0;
}

int about(int n,char name[47])  //Титулка
{
	clrscr();
	printf("\t************************************************\n");
	printf("\t*           Лабораторная робота №%1d             *\n",n);
	printf("\t*                                              *\n");
	printf("\t* %44s *\n",name);
	printf("\t*                                              *\n");
	printf("\t* Автор: Антон Підгайний.     Вариант-18       *\n");
	printf("\t*                                              *\n");
	printf("\t************************************************\n\n");
	return 0;
}

int chose_menu()  //Меню
{
	int chose=0;
	about(2,"Unpack and Pack                 ");
	printf(" Виберіть операцію(1-упаковка, 2-розпаковка, 3-exit) >> ");
	scanf("%1i",&chose);
	return chose;
}

unsigned short int pack()  //Упаковка
{	
	unsigned short int state_word=0;
	unsigned short int x,y,color;
	about(2,"Pack                 ");
	printf("Введіть X (0-63) >> ");
	scanf("%hu",&x);
	printf("Введіть Y (0-63) >> ");
	scanf("%hu",&y);
	printf("Введіть Color (0-15) >> ");
	scanf("%hu",&color);
	state_word=(x & 0x3f)<<10;
	state_word|=(y & 0x3f)<<4;
	state_word|=(color & 0xf);
	printf("\nОпис точки: %hx",state_word);
	getchar();getchar();
	return state_word;
}

int unpack()  //Розпаковка
{	
	unsigned short int state_word=0;
	about(2,"Unpack                          ");
	printf("Введіть число (0-ffff) >> ");
	scanf("%hx",&state_word);
	printf("\n    X: %hu\n",(state_word >> 10));
	printf("    Y: %hu\n",(state_word >> 4)&0x3f);
	printf("Color: %hu\n",state_word&0xf);
	getchar();getchar();
	return 0;
}

int main(void)
{
	char ch;
	setlocale(LC_ALL, "Rus");
	do
	{
		ch=chose_menu();
		if (ch==1) pack();
		else if (ch==2)  unpack();
		else if (ch!=3){printf("Помилка: Введіть 1,2 або 3!\n"); getchar();getchar();}
	} while (ch!=3);
	clrscr();
	return 0;
}