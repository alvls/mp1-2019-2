#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main(void)
{
	int  a, x, y, n;
	char simbol;
	setlocale(LC_ALL, "Russian");
	printf("�������� ����� ���������: \n 1 (�� ����������� ����� �� 0 �� 1000, ������� �������� ���������) ��� 2 (��������� ���������� ����� �� 0 �� 1000, ������� �������� ��)\n ");//��, ���� � �� ������� � ������� �����, ������ ��� ���� ��������� �� ��������, �� ��� ���� �� ����� ����������� ��������. ������������������������ - ���� ���:)
	scanf_s("%i", &a);
	switch (a)
	{
	case 1:
		x = n = 0;
		y = rand() % 1000 + 1;
		srand(time(NULL));
		while (x != y)
		{
			printf("������� ���� ������� �� 0 �� 1000 \n");
			scanf_s("%i", &x);
			if (x < y)
				printf("���� ����� ������ ����������� \n");
			else if (x > y)
				printf("���� ����� ������ ����������� \n");
			else
				printf("����������, �� �������! \n");
			n++;
		}
		printf("���������� �������: %i \n", n);
		break;
	case 2:
		a = 0;
		x = 1000;
		simbol = n = 0;
		printf("��������� ����� �� 1 �� 1000.\n");
		while (simbol != '=')
		{
			y = (a + x) / 2;
			printf("���� ����� %i? ���� ��, ������� '=', ���� ���, ������� '<' ��� '>'\n", y);
			scanf_s("%c", &simbol);
			scanf_s("%c", &simbol);
			n++;
			switch (simbol)
			{
			case '<':
				x = y;
				break;
			case '>':
				a = y;
				break;

			case '=':

				printf("��������� ������� ���� ����� �� %i �������.\n", n);
				break;
			default:

				printf("������� '=', '<' ��� '>'\n");
				break;
			}
		}
		break;
	default:
		printf("�� ��������� ������ ��� ������ ������ ���������, ����������, ���������� ��� ��� \n");
		break;
	}
	system("pause");
}