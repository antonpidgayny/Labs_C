#include <stdio.h>
#include <locale.h>

struct substance
{
	char name[15];
	unsigned short n;
	int t;
	float v;
}typedef substance;

int main(void)
{
	setlocale(LC_ALL, "Rus");
	substance s1,s2,s3;
	char horizontale_line[100] ="=========================================================================";
	
	////////////////////////Title///////////////////////////
	printf("\n\t Лабораторная робота №1\n");
	printf(" Операции ввода, вывода.  Вывод таблицы.\n\n");
	printf(" Автор: Антон Підгайний.\t Вариант-18\n\n");

	////////////////////////Input///////////////////////////
	printf("Введите вещество 1(Название, Атомный номер, Температура плавления, Вязкость): \n");
	scanf("%s %hu %d %f",s1.name,&s1.n,&s1.t,&s1.v);
	printf("Введите вещество 2(Название, Атомный номер, Температура плавления, Вязкость): \n");
	scanf("%s %hu %d %f",s2.name,&s2.n,&s2.t,&s2.v);
	printf("Введите вещество 3(Название, Атомный номер, Температура плавления, Вязкость): \n");
	scanf("%s %hu %d %f",s3.name,&s3.n,&s3.t,&s3.v);

	////////////////////////Output/////////////////////////
	printf("\n%s\n",horizontale_line);
	printf("|\t\t   Вязкость металлов в жидком состоянии  \t\t|\n");
	printf("%s\n",horizontale_line);
	printf("|  Вещество  | Атомный номер | Температура(град.С) | Вязкость(кг/м*сек) |\n");
	printf("%s\n",horizontale_line);
	printf("| %-10s |      %3hu      | %-19d | %-18.2g |\n",s1.name,s1.n,s1.t,s1.v);
	printf("%s\n",horizontale_line);
	printf("| %-10s |      %3hu      | %-19d | %-18.2g |\n",s2.name,s2.n,s2.t,s2.v);
	printf("%s\n",horizontale_line);
	printf("| %-10s |      %3hu      | %-19d | %-18.2g |\n",s3.name,s3.n,s3.t,s3.v);
	printf("%s\n",horizontale_line);
	printf("|\t Примечание: данные даны для температуры плавления\t\t|\n");
	printf("%s\n",horizontale_line);

	return 0;
}