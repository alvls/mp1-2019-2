#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int z, num, i, j, end; //n - ����� �����, num - ����� ������, i, j - �������� ��� ������
	int cow = 0; // ���������� �����
	int bull = 0; // ���������� �����
	int comp[5] = { 0 }; // ������ ��� ����� ����������
	int number[5] = { 0 }; // ������ ��� ����� ������
	int a, b; // d - ��������, a - ��������������� ����������
	int attempt = 0;
	srand(time(NULL));
	printf("���� '���� � ������'!\n�������� ����� ������������� �����.\n������� 2, 3, 4 ��� 5.\n");
	scanf_s("%i", &z);
	while ((z < 2) || (z > 5))
	{
		printf("���������� �������� ����� ���� ������ 2, 3, 4 ��� 5. ������� ����� ������.\n");
		scanf_s("%i", &z);
	}
	for (i = 0; i < z; i++)
	{
		comp[i] = (rand() % 9 + 1);
		for (j = 0; j < i; j++)
		{
			while (comp[i] == comp[j])
			{
				comp[i] = (rand() % 9 + 1);
			}
		}
	}
	printf("������� ��� ������� ����� � ���������������� �������.\n");
	scanf_s("%i", &num);
	while (bull != z)
	{
		while ((num < pow(10, (z - 1))) || (num >= pow(10, (z + 1))))
		{
			printf("����� �� ������ � ��������� ��������!\n");
			scanf_s("%i", &num);
		}
		attempt++;
		b = num;
		for (i = z - 1; i >= 0; i--)
		{
			a = pow(10, i);
			number[i] = b / a;
			b %= a;
		}
		bull = 0;
		cow = 0;
		for (i = 0; i < z; i++)
		{
			if (number[i] == comp[i])
				bull++;
			else
				for (j = 0; j < z; j++)
				{
					if ((i != j) && (number[i] == comp[j]))
						cow++;
				}
		}
		if (bull == n)
			break;
		printf("�����: %i\n�����: %i\n", bull, cow);
		scanf_s("%i", &num);
	}
	printf("� ����� ����! ��� ����� %i. ���������� �������: %i\n", num, attempt);
	scanf_s("%i", &end);
	return 0;
}

void merge(struct _finddata_t* files, long lb, long split, long ub)
{
	long pos1 = lb;
	long pos2 = split + 1;
	long pos3 = 0;
	struct _finddata_t file;
	struct  _finddata_t* temp = (struct _finddata_t*)malloc((ub - lb + 1) * sizeof(struct _finddata_t));
	while (pos1 <= split && pos2 <= ub)
	{
		if (files[pos1].size < files[pos2].size)
			temp[pos3++] = files[pos1++];
		else
			temp[pos3++] = files[pos2++];
	}
	while (pos2 <= ub)
		temp[pos3++] = files[pos2++];
	while (pos1 <= split)
		temp[pos3++] = files[pos1++];
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
		files[lb + pos3] = temp[pos3];
	free(temp);
}
void mergeSort(struct _finddata_t* files, long lb, long ub)
{
	long split;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		mergeSort(files, lb, split);
		mergeSort(files, split + 1, ub);
		merge(files, lb, split, ub);
	}
}
void mergeSort(struct _finddata_t* files, long n)
{
	mergeSort(files, 0, n - 1);
}