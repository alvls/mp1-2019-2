#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	double x1, y1, R1, x2, y2, R2, d, branch;
	printf("������� �������� ������ ���������� (x, y), R: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &R1);

	printf("������� �������� ������ ���������� (x, y), R: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &R2);
	
	d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

	//���������� � ������� x1, y1, R1 ������ ���� ������ ��� ������.
	if (R2 > R1)
	{
		branch = R2;
		R2 = R1;
		R1 = branch;
	}

	//���������� �������� ������������ ���� �����������.
	if ((R1 == R2) && (x1 == x2) && (y1 == y2))
	{
		printf("���������� ���������.");
	}
	else if (R1 + R2 < d)
	{
		printf("�� ����� ����� �����.");
	}
	else if ((R1 + R2 == d) || (R1 - R2 == d))
	{
		printf("���������� �������������.");
	}
	else if ((R1 + R2 > d) && (R1 - R2 < d))
	{
		printf("���������� ������������.");
	}
	else if (R1 - R2 > d)
	{
		printf("���������� � ������� �������� ������ ������.");
	}
	_getch();
}