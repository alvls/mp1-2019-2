#include <stdio.h>        
#include <locale.h>
int main(void)
{
	char *locale = setlocale(LC_ALL, "");
	float h, w, d, t = 1.5, t1 = 0.5, P_ldsp, Pdvp, Pmdf, m;  // h - ������ w - ������ d- ������� t- ������� ���� t1- ������� ��� , P_ldsp - ��������� ���� , Pdvp - ��������� ���, Pmdf- ���������� ��� ������, ����� m
	int k; // ���-�� �����
	printf("������� ������ , ������� � ������ ����� � ���-�� ����� \n");
	scanf_s("%f %f %f", &h, &d, &w);
	printf("������� ��������� ���� P_ldsp = , ��������� ��� Pdvp = , ��������� ��� Pmdf = \n");
	scanf_s("%f %f %f", &P_ldsp, &Pdvp, &Pmdf);
	k = (h - 3) / 41.5; // ������� ���-�� �����
	m = (k + 2)* d * (w - 3) * t * P_ldsp + 2 * d * h * t * P_ldsp + w * h * t1 * Pdvp + w  * h * Pmdf * t; // ������� �����
	printf("���������� ����� m = %f", m / 1000);

	//scanf_s("%f", &h); // ��-������� ��������
	system("pause");
}