#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define l 5
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int code[l] = { 1111, 2222, 3333, 4444, 5555 };
	int cena[l] = { 54, 60, 42, 20, 35 };
	int itog[l] = { 0 };
	int skidka[l] = { 0 };
	char fruct[5][20] = { {"�������"}, {"��������"}, {"������"}, {"������"}, {"�����"} };
	int i, n, cash, number, end, skidos;
	int itogg = 0;
	int summ = 0;
	int summa[l] = { 0 };

	printf("������������ ��� � ��������� �����!\n������� �������� �� �������������� ����:\n1111\n2222\n3333\n4444\n5555\n���� �� ��������� � ��������, ������� 0 ������ ���������.\n");
	scanf_s("%i", &n);
	for (i = 0; i < l; i++)
	{
		skidka[i] = (rand() % 49 + 1);
	}
	while (n != 0)
	{
		while ((n != 0) && (n != code[1]) && (n != code[2]) && (n != code[3]) && (n != code[4]) && (n != code[0]))
		{
			printf("������� � ����� ���������� ��� � �������! ������ �� ����� ��� ���. ���������� ����� ����� ���� ������ ��� ������� ������ ����� :)\n");
			scanf_s("%i", &n);
		}
		for (i = 0; i < l; i++)
		{
			if (n == 0)
				break;
			else
				if (n == code[i])
				{
					printf("�����: ");
					puts(fruct[i]);
					itog[i] = cena[i] * (100 - skidka[i]) / 100;
					printf("���� �� 100� ������ %i ���.\n������ %i ����.\n���� � ������ ������ %i ���.\n", cena[i], skidka[i], itog[i]);
					printf("������� � ����� ������ ������� ��� ����������� ������: ");
					scanf_s("%i", &number);
					summa[i] += number;
					printf("������� �������� ���������� ������ ��� 0.\n");
					scanf_s("%i", &n);
					break;
				}
		}
	}
	for (i = 0; i < l; i++)
	{
		itog[i] = summa[i] * (cena[i] * (100 - skidka[i]) / 100);
		summ += itog[i];
		itogg += summa[i] * cena[i];
	}
	skidos = itogg - summ;
	printf("*�������� ���*\n");
	for (i = 0; i < l; i++)
	{
		if (summa[i] > 0)
		{
			puts(fruct[i]);
			printf("��� (� ������ �������) %i,  ����� %i ���.\n", summa[i], itog[i]);
		}
	}
	printf("��������� ������� � ������� %i ���.\n��������� ������ %i ���.\n���� %i ���.\n ������� �� ��������� ����� ��������� �����!\n ��, �� �����, ��� ����-��� �����, �� ��� �� �� ���������, � �� ������ ��� �������� ��������� ��� ��������� �������! \n(������ ��� ������� ���������� ������� ����) ", itogg, skidos, summ);
	scanf_s("%i", &end);
}