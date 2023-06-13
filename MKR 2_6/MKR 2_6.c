//MKR2_6.c �������� � ������� ����� ���� ���������� �� ������������ �� ������.
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

struct Point {
	int x, y;
} A[3], B[3]; //������ �������� ��� ��������� �������� �����


double LA[3], LB[3];//����� ������ �����
double SA, SB;//���� ���� ����������
static int i;

void Input(struct Point(*C)[3]); //�������� ������ ����������
void Length(struct Point(*C)[3], double(*LX)[3]); //������� ����� � �����
double Square(double(*LX)[3]); //����� ����������
bool yes_or_no(double(*LX)[3]); //��������, �� ����� ���������� ���������
void Print(struct Point(*C)[3], double(*LX)[3]); //��������� �������� �� ��������� �����

void main(void)
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_CTYPE, "ukr");

	//�������� �� �������� ����� ������ ���������
	printf("\n ����� ���������� ������ ������� ����������:\n");
	do
	{
		Input(&A);
		Length(&A, &LA);
		SA = Square(&LA);
		if (yes_or_no(&LA))
			printf("\n �� ��������� ������������ ����� �� ������� ���������� ���������.\n ����� ���������� ��������:\n");
	} while (yes_or_no(&LA));

	//�������� �� �������� �����  ������ ���������
	printf("\n ����� ���������� ������ ������� ����������:\n");
	do
	{
		Input(&B);
		Length(&B, &LB);
		SB = Square(&LB);
		if (yes_or_no(&LB))
			printf("\n �� ��������� ������������ ����� �� ������� ���������� ���������.\n ����� ���������� ��������:\n");
	} while (yes_or_no(&LB));

	system("cls");

	//��������� �������� ��������� �� ��������� ���������� ���������
	printf("\n �� ����� ������� �����, �� � ��������� ������� ����������:");
	Print(&A, &LA);
	printf("\n ���� ����� S = %0.3lf \n", SA);

	printf("\n �� ����� ������� �����, �� � ��������� ������� ����������:");
	Print(&B, &LB);
	printf("\n ���� ����� S = %0.3lf \n", SB);
	//��������� ���� ����������	
	if (SA == SB) printf("\n ����� ���������� ��� �� �����");
	else
	{
		if (SA > SB) printf("\n ����� ������� ���������� ����� �� ����� �������");
		else printf("\n ����� ������� ���������� ����� �� ����� �������");
	}
	int getch(); getch();
	return 0;
}

//������� �������� ��������� ������ ����������
void Input(struct Point(*C)[3])
{
	for (i = 0; i < 3; i++)
	{
		printf("����� ���������� x �� y ����� �%d ����� ����� �%d=(x%d, y%d)=", i + 1, i + 1, i + 1, i + 1);
		scanf("%d %d", &(*C)[i].x, &(*C)[i].y);
	}
}

//������� ���������� ������� ������ ����� � ��������� ���������� � �����
void Length(struct Point(*C)[3], double(*LX)[3])
{
	(*LX)[0] = sqrt(pow(((*C)[0].x - (*C)[2].x), 2) + pow(((*C)[0].y - (*C)[3].y), 2));
	for (i = 1; i < 3; i++)
		(*LX)[i] = sqrt(pow(((*C)[i].x - (*C)[i + 1].x), 2) + pow(((*C)[i].y - (*C)[i + 1].y), 2));
}

//������� ���������� ����� ���������� (�� �������� ������)
double Square(double(*LX)[3])
{
	double px = 0;
	for (i = 0; i < 3; i++) px = (px + (*LX)[i]);
	px = px / 2;
	double SX = sqrt(px * (px - (*LX)[0]) * (px - (*LX)[1]) * (px - (*LX)[2]));
	return SX;
}

//������� �������� ��������� ���������� ��������� � �������� ���������
bool yes_or_no(double(*LX)[3])
{
	if ((*LX)[0] + (*LX)[1] < (*LX)[2] || (*LX)[1] + (*LX)[2] < (*LX)[0] || (*LX)[2] + (*LX)[0] < (*LX)[1]) return true;
	else return false;
}

//������� ��������� ������� �� ��������� �����
void Print(struct Point(*C)[3], double(*LX)[3])
{
	for (i = 0; i < 3; i++)
		printf("\n\t ����� �%d=(x%d, y%d)=(%d, %d)", i + 1, i + 1, i + 1, (*C)[i].x, (*C)[i].y);

	printf("\n ������� ����� ����������:\n ");
	for (i = 0; i < 3; i++)
		printf("\t L%d= %0.3lf", i + 1, (*LX)[i]);
}

