#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int a = 12345, a1, a2, a3, a4, a5, s, s1, s2, s3, s4, s5, b = 0, k = 0, mode, n=0;
	printf("�������� ����� ������������� ����� (�� 2 �� 5)\n");
	printf("���� ������ �������, �� ����� ����� ���� ������� 0\n");
	scanf_s("%d", &mode);
	if (mode == 5)
	{
		do {
			a1 = 1 + (rand() % 9);
			a2 = 1 + (rand() % 9);
			a3 = 1 + (rand() % 9);
			a4 = 1 + (rand() % 9);
			a5 = 1 + (rand() % 9);
		} while (a1 == a2 || a1 == a3 || a1 == a4 || a1== a5 || a2 == a3 || a2 == a4 || a2 == a5 || a3 == a4 || a3 == a5 || a4 == a5);
		printf("�������� �������\n");
		while (b != 5)
		{
			scanf_s("%d", &s);
			if (s == 0)
			{
				return 0;
			}
			s5 = s % 10;
			s4 = ((s - s5) / 10) % 10;
			s3 = ((s - (s % 100)) / 100) % 10;
			s2 = ((s - (s % 1000)) / 1000) % 10;
			s1 = ((s - (s % 10000)) / 10000) % 10;
			b = 0, k = 0;
			if (a1 == s1) b++, k--;
			if (a2 == s2) b++, k--;
			if (a3 == s3) b++, k--;
			if (a4 == s4) b++, k--;
			if (a5 == s5) b++, k--;

			if (a1 == s1) k++;
			if (a1 == s2) k++;
			if (a1 == s3) k++;
			if (a1 == s4) k++;
			if (a1 == s5) k++;

			if (a2 == s1) k++;
			if (a2 == s2) k++;
			if (a2 == s3) k++;
			if (a2 == s4) k++;
			if (a2 == s5) k++;

			if (a3 == s1) k++;
			if (a3 == s2) k++;
			if (a3 == s3) k++;
			if (a3 == s4) k++;
			if (a3 == s5) k++;

			if (a4 == s1) k++;
			if (a4 == s2) k++;
			if (a4 == s3) k++;
			if (a4 == s4) k++;
			if (a4 == s5) k++;

			if (a5 == s1) k++;
			if (a5 == s2) k++;
			if (a5 == s3) k++;
			if (a5 == s4) k++;
			if (a5 == s5) k++;
			n++;
			printf("����� ����� = %d \n����� ����� = %d\n", b, k);
			if (b != 5)
			{
				printf("������ ��� \n");
			}
		}
		printf("����������! ���������� ������� = %d \n", n);
	}
		if (mode == 4)
		{
			do {
				a1 = 1 + (rand() % 9);
				a2 = 1 + (rand() % 9);
				a3 = 1 + (rand() % 9);
				a4 = 1 + (rand() % 9);
			} while (a1 == a2 || a1 == a3 || a1 == a4 || a2 == a3 || a2 == a4 ||  a3 == a4 );
			printf ("�������� �������\n");
			while (b != 4)
			{
				scanf_s ("%d", &s);
				if (s == 0)
				{
					return 0;
				}
				s4 = s % 10;
				s1 = (s - s4) / 1000;
				s3 = ((s - (s % 10)) - (s - (s % 100))) / 10;
				s2 = ((s - (s % 100)) - (s - (s % 1000))) / 100;
				b = 0, k = 0;
				if (a1 == s1) b++, k--;
				if (a2 == s2) b++, k--;
				if (a3 == s3) b++, k--;
				if (a4 == s4) b++, k--;

				if (a1 == s1) k++;
				if (a1 == s2) k++;
				if (a1 == s3) k++;
				if (a1 == s4) k++;

				if (a2 == s1) k++;
				if (a2 == s2) k++;
				if (a2 == s3) k++;
				if (a2 == s4) k++;

				if (a3 == s1) k++;
				if (a3 == s2) k++;
				if (a3 == s3) k++;
				if (a3 == s4) k++;

				if (a4 == s1) k++;
				if (a4 == s2) k++;
				if (a4 == s3) k++;
				if (a4 == s4) k++;
				n++;
				printf("����� ����� = %d \n����� ����� = %d\n", b, k);
				if (b!= 4)
				{
					printf ("������ ��� \n");
				}
			}
			printf("����������! ���������� ������� = %d \n", n);
		}
		if (mode == 3)
		{
			do {
				a1 = 1 + (rand() % 9);
				a2 = 1 + (rand() % 9);
				a3 = 1 + (rand() % 9);
			}
			while (a1 == a2 || a1 == a3 || a2 == a3);
			printf("�������� �������\n");
			while (b != 3)
			{
				scanf_s("%d", &s);
				if (s == 0)
				{
					return 0;
				}
				s3 = s % 10;
				s2 = ((s - s3) % 100) / 10;
				s1 = (s - s2 - s3) / 100;
				b = 0, k = 0;
				if (a1 == s1) b++, k--;
				if (a2 == s2) b++, k--;
				if (a3 == s3) b++, k--;

				if (a1 == s1) k++;
				if (a1 == s2) k++;
				if (a1 == s3) k++;

				if (a2 == s1) k++;
				if (a2 == s2) k++;
				if (a2 == s3) k++;

				if (a3 == s1) k++;
				if (a3 == s2) k++;
				if (a3 == s3) k++;
				n++;
				printf("����� ����� = %d \n����� ����� = %d\n", b, k);
				if (b != 3)
				{
					printf("������ ��� \n");
				}
			}
			printf("����������! ���������� ������� = %d \n", n);
		}
		if (mode == 2)
		{
			do {
				a1 = 1 + (rand() % 9);
				a2 = 1 + (rand() % 9);
			} while (a1 == a2 );
			printf("�������� �������\n");
			while (b != 2)
			{
				scanf_s("%d", &s);
				if (s == 0)
				{
					return 0;
				}
				s2 = s % 10 ;
				s1 = (s - s2) / 10;
				b = 0, k = 0;
				if (a1 == s1) b++, k--;
				if (a2 == s2) b++, k--;

				if (a1 == s1) k++;
				if (a1 == s2) k++;

				if (a2 == s1) k++;
				if (a2 == s2) k++;
				n++;
				printf("����� ����� = %d \n����� ����� = %d\n", b, k);
				if (b != 2)
				{
					printf("������ ��� \n");
				}
			}
			printf("����������! ���������� ������� = %d \n", n);
		}
		if (mode == 0)
		{
			return 0;
		}
		system("pause");
}

