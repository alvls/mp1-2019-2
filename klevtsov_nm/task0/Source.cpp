#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
	double x1, y1, R1, x2, y2, R2, d, branch;
	printf("First (x, y), R: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &R1);

	printf("Second (x, y), R: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &R2);
	
	d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

	//���������� � ������� x1, y1, R1 ������ ���� ������ ��� ������.
	if (R2 > R1)
	{
		branch = x2; x2 = x1; x1 = branch;
		branch = y2; y2 = y1; y1 = branch;
		branch = R2; R2 = R1; R1 = branch;
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