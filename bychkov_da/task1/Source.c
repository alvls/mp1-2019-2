#include <stdio.h> 
#include <math.h>
#include <locale.h>
int main(void) {
	setlocale(LC_ALL, "Rus");
	double h, w, d, pDVP, pDSP, pD, q, mZ, mB, mP, mD, M, k, x, y;
	printf("������� ������(�� 180 �� 220 ��), ������(�� 80 �� 120 ��), �������(�� 50 �� 90 ��) � ����������� ");
	scanf_s("%lf %lf %lf", &h, &w, &d);
	k = 0.5;
	x = 1.5;
	y = 1;
	pDVP = 0.00085; //�� �� ���������� ���������
	pDSP = 0.00065; 
	pD = 0.00045;
	q  = (int) (h - (1.5 * 2)) / 41.5;
	mZ = k * h * w * pDVP; //����� ������ ������
	mB = x * h * d * 2 * pDSP; //����� ������� ������
	mP = x * w * d * (2 + q) * pDSP; //����� ����� � ������
	mD = y * w * h * 2 * pD; // ����� ������
	M = mZ + mB + mP + mD;
	printf("����� ����� ����� %lf ��.    ", M);
	system("pause");




}