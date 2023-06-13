//MKR2_6.c Обраховує і порівнює площу двох трикутників за координатами їх вершин.
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

struct Point {
	int x, y;
} A[3], B[3]; //Масиви структур для зберігання введених даних


double LA[3], LB[3];//Масив довжин сторін
double SA, SB;//Змінні площ трикутників
static int i;

void Input(struct Point(*C)[3]); //Введення вершин трикутників
void Length(struct Point(*C)[3], double(*LX)[3]); //Довжини сторін в масив
double Square(double(*LX)[3]); //Площа трикутника
bool yes_or_no(double(*LX)[3]); //Перевірка, чи можна побудувати трикутник
void Print(struct Point(*C)[3], double(*LX)[3]); //Виведення введених та отриманих даних

void main(void)
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_CTYPE, "ukr");

	//Введення та перевірка даних ПЕРШИЙ ТРИКУТНИК
	printf("\n Введи координати вершин першого трикутника:\n");
	do
	{
		Input(&A);
		Length(&A, &LA);
		SA = Square(&LA);
		if (yes_or_no(&LA))
			printf("\n За введеними координатами точок не можливо побудувати трикутник.\n Введи координати повторно:\n");
	} while (yes_or_no(&LA));

	//Введення та перевірка даних  ДРУГИЙ ТРИКУТНИК
	printf("\n Введи координати вершин другого трикутника:\n");
	do
	{
		Input(&B);
		Length(&B, &LB);
		SB = Square(&LB);
		if (yes_or_no(&LB))
			printf("\n За введеними координатами точок не можливо побудувати трикутник.\n Введи координати повторно:\n");
	} while (yes_or_no(&LB));

	system("cls");

	//Виведення введених аргументів та отриманих результатів обчислень
	printf("\n Ви ввели наступні точки, що є вершинами ПЕРШОГО ТРИКУТНИКА:");
	Print(&A, &LA);
	printf("\n його площа S = %0.3lf \n", SA);

	printf("\n Ви ввели наступні точки, що є вершинами ДРУГОГО ТРИКУТНИКА:");
	Print(&B, &LB);
	printf("\n його площа S = %0.3lf \n", SB);
	//Порівняння площ трикутників	
	if (SA == SB) printf("\n Площі трикутників рівні між собою");
	else
	{
		if (SA > SB) printf("\n Площа першого трикутника більша за площу другого");
		else printf("\n Площа першого трикутника менша за площу другого");
	}
	int getch(); getch();
	return 0;
}

//Функція введення координат вершин трикутника
void Input(struct Point(*C)[3])
{
	for (i = 0; i < 3; i++)
	{
		printf("Введи координати x та y точки Р%d через пробіл Р%d=(x%d, y%d)=", i + 1, i + 1, i + 1, i + 1);
		scanf("%d %d", &(*C)[i].x, &(*C)[i].y);
	}
}

//Функція розрахунку довжини відрізків сторін з внесенням результату в масив
void Length(struct Point(*C)[3], double(*LX)[3])
{
	(*LX)[0] = sqrt(pow(((*C)[0].x - (*C)[2].x), 2) + pow(((*C)[0].y - (*C)[3].y), 2));
	for (i = 1; i < 3; i++)
		(*LX)[i] = sqrt(pow(((*C)[i].x - (*C)[i + 1].x), 2) + pow(((*C)[i].y - (*C)[i + 1].y), 2));
}

//Функція розрахунку площі трикутника (за рівнянням Герона)
double Square(double(*LX)[3])
{
	double px = 0;
	for (i = 0; i < 3; i++) px = (px + (*LX)[i]);
	px = px / 2;
	double SX = sqrt(px * (px - (*LX)[0]) * (px - (*LX)[1]) * (px - (*LX)[2]));
	return SX;
}

//Функція перевірка можливості побудувати трикутник з заданими сторонами
bool yes_or_no(double(*LX)[3])
{
	if ((*LX)[0] + (*LX)[1] < (*LX)[2] || (*LX)[1] + (*LX)[2] < (*LX)[0] || (*LX)[2] + (*LX)[0] < (*LX)[1]) return true;
	else return false;
}

//Функція виведення заданих та отриманих даних
void Print(struct Point(*C)[3], double(*LX)[3])
{
	for (i = 0; i < 3; i++)
		printf("\n\t точка Р%d=(x%d, y%d)=(%d, %d)", i + 1, i + 1, i + 1, (*C)[i].x, (*C)[i].y);

	printf("\n довжини сторін трикутника:\n ");
	for (i = 0; i < 3; i++)
		printf("\t L%d= %0.3lf", i + 1, (*LX)[i]);
}

