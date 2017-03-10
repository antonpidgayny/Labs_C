#include <stdio.h>
#include <malloc.h>

int** create_matrix(int n,int m)  //Створення матриці n*m
{
	int **matrix;
	matrix=(int**)malloc(n*sizeof(int*));
	for (int i=0; i<n; i++) 
		matrix[i]=(int*)malloc(m*sizeof(int));
	return matrix;
}

int clear_memory(int **matrix,int n)  //Очистка пам'яті
{
	for (int i=0;i<n;i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}

int min(int x,int y) //Мінімум двох цілих чисел
{
	if (x<y) return x;
	return y;
}

int clrscr(void)  //Очистка консолі
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

int matrix_spirale(int **arr,int n,int m)  //Побудова спіралі
{
	int k=(min(n,m)+1)/2,x=0,y=0,count=0,q=0,sum=n*m;
	while(k>0)
	{
		for (y;y<n-q;y++) arr[y][x]=++count;
		--y;
		if (count>=sum) break;
		for (++x;x<m-q;x++) arr[y][x]=++count;
		--x;
		if (count>=sum) break;
		for (--y;y>0+q;--y) arr[y][x]=++count;
		if (count>=sum) break;
		for (x;x>0+q;--x) arr[y][x]=++count;
		if (count>=sum) break;
		x++;y++;
		q+=1;
		--k;
	}
	return 0;
}

int print_matrix(int **arr,int n,int m)  //Вивід матриці
{
	for (int i=0;i<n;i++)
	{		
		for (int j=0;j<m;j++)
			printf("%3i ",arr[i][j] );
		printf("\n");
	}
	return 0;
}

int menu(void)
{
	int chose=0;
	about(3,"Обробка массивів          ");
	printf(" Виберіть операцію(1-продовжити, 2-exit) >> ");
	scanf("%1i",&chose);
	return chose;
}

int input(int *a,int *b)
{
	int cond=0;
	do
	{
		printf("Введіть висоту матриці(2-31) >> ");
		scanf("%2i",a);
		cond=(*a<2 || *a>31);
		if (cond) printf("Помилка!\n");
	} while (cond);
	do
	{
		printf("Введіть ширину матриці(2-31) >> ");
		scanf("%2i",b);
		cond=(*b<2 || *b>31);
		if (cond) printf("Помилка!\n");
	} while (cond);
	return 0;
}

int main(void)
{
	int **matrix;
	int n,m;
	char ch;
	do
	{
		ch=menu();
		if (ch==1)
		{
			about(2,"Обробка массивів          ");
			input(&n,&m);
			matrix=create_matrix(n,m);	
			matrix_spirale(matrix,n,m);
			print_matrix(matrix,n,m);
			clear_memory(matrix,n);
			getchar(); getchar(); 
		}
		else if (ch!=2){printf("Помилка: Введіть 1 або 2!"); getchar(); getchar();}
	} while (ch!=2);
	clrscr();
	return 0;
}