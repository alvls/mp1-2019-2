#include <stdio.h>
#include <locale.h>
int main(void) {
	double  h, w, Sdvp, d, Sdsp, Sder, s, n, m1, m2, m3, m4, m5, m;
	setlocale(LC_ALL, "Russian");
	printf("������� ������, ������ ������ ��������� ������ (� ������) � ��������� ��� (� ��/�^3): h, w, Sdvp "); //������ �������
	scanf_s("%lf %lf %lf", &h, &w, &Sdvp);
	printf("������� ������� �������� (� ������) � ��������� ��� � ������ (� ��/�^3): d, Sdsp "); //��������
	scanf_s("%lf %lf %lf", &d, &Sdsp, &Sder);
	if ((h > 1.8) && (h < 2.2) && (w > 0.8) && (w < 1.2) && (d < 0.9) && (d > 0.5))
	{
		m1 = h * w * 0.005 * Sdvp; //����� ������ ������ � ��
		m2 = 2 * h * d * 0.015 * Sdsp; //����� ������� � ��
		m3 = 2 * w * d * 0.015 * Sdsp; //����� ������� � ������ ������ � ��
		m4 = h * w * 0.01 * Sder; //����� ������ � ��
		s = w - 2 * 0.015; //������ ����� � �
		if (h < 207.5)
		{
			n = 4;
			m5 = 4 * s * d * 0.015 * Sdsp; //����� ����� � ��, ���� �� 4
		}
		else
		{
			n = 5;
			m5 = 5 * s * d * 0.015 * Sdsp; //����� ����� � ��, ���� �� 5
		}
		m = m1 + m2 + m3 + m4 + m5;
		printf("m=%f", m);
	}
	else
	{
		printf("�� ��������� ������ ��� ����� ������, ����������, ���������� ��� ���");
	}
}