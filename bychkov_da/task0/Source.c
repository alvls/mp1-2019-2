#include <stdio.h> 
#include <math.h>
#include <locale.h>
int main(void) {
	setlocale(LC_ALL, "Rus");
	float r1, r2, x1, x2, y1, y2, d, b;
	printf("������� ����� ������ ���������� r1, ���������� � ������ x1 � y1");
	scanf_s("%f %f %f", &r1, &x1, &y1);
	printf("������� ����� ������ ���������� r2, ���������� � ������ x2 � y2");
	scanf_s("%f %f %f", &r2, &x2, &y2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); // ���������� ����� �������� 
	b = r1 + r2;
	if (d == 0, r1 > r2) {
		printf("������ ���������� ��������� ������ ������");
	}
	if (d == 0, r1 < r2) {
		printf("������ ���������� ��������� ������ ������");
	}
	if (d == b) {
		printf("���������� ��������");
	}
	if (d > b) {
		printf("���������� �� �������");
	}
	if ((d < b) *(d !=0) ) {
		printf("���������� ������������");
	}

}










