#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <io.h>
#include <string.h>
#include <io.h> 
#include <time.h>  
#include <locale.h>

#define NFiles 5000

void BubbleSort(struct _finddata_t* files, long q)
{
	struct _finddata_t file;
	for (int i = 0; i < q; i++)
	{
		for (int j = q - 2; j >= i; j--)
		{
			if (files[j + 1].size < files[j].size)
			{
				file = files[j + 1];
				files[j + 1] = files[j];
				files[j] = file;
			}
		}
	}
}

void SelectSort(struct _finddata_t* file, int q)
{
	int i, j, k;
	struct _finddata_t temp;
	for (i = 0; i < q; i++)
	{
		k = i;
		temp = file[i];
		for (j = i + 1; j < q; j++)
			if (file[j].size < temp.size)
			{
				k = j;
				temp = file[j];
			}
		file[k] = file[i];
		file[i] = temp;
	}
}
void InsertSort(struct _finddata_t* files, int q)
{
	int i, j;
	struct _finddata_t temp;
	for (i = 1; i < q; i++)
	{
		temp = files[i];
		for (j = i - 1; j >= 0 && files[j].size > temp.size; j--)
			files[j + 1] = files[j];
		files[j + 1] = temp;
	}
}
void QuickSort(struct _finddata_t* file, int q)
{
	int i = 0, j = q - 1;
	struct _finddata_t temp;
	long p;
	p = file[q >> 1].size;
	do {
		while (file[i].size < p)
			i++;
		while (file[j].size > p)
			j--;
		if (i <= j)
		{
			temp = file[i];
			file[i] = file[j];
			file[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) QuickSort(file, j + 1);
	if (q > i) QuickSort(file + i, q - i);
}

int increment(long inc[], long q)
{
	int w, e, r, t;
	w = e = r = 1;
	t = -1;
	do {
		if (++t % 2)
			inc[t] = 8 * w - 6 * e + 1;
		else
		{
			inc[t] = 9 * w - 9 * r + 1;
			e *= 2;
			r *= 2;
		}
		w *= 2;
	} while (3 * inc[t] < q);
	return t > 0 ? --t : 0;
}
void CountingSort(struct _finddata_t* file, int q)
{
	struct _finddata_t temp;
	unsigned long max, min;
	int i, j, r = 0, * t;
	max = min = file[0].size;
	for (i = 0; i < q; i++)
	{
		if (file[i].size > max)
			max = file[i].size;
		if (file[i].size < min)
			min = file[i].size;
	}
	max++;
	t = (int*)malloc(max * sizeof(int));
	if (t!=0)
	{
		memset(t, 0, max * sizeof(int));
		for (i = 0; i < q; i++)
			t[file[i].size]++;
		for (i = min; i < max; i++)
		{
			if (t[i] != 0)
			{
				for (j = r; j < q; j++)
					if (file[j].size == i)
					{
						temp = file[j];
						file[j] = file[r];
						file[r] = temp;
						r++;
					}
			}
		}
		free(t);
	} 
}
void ShellSort(struct _finddata_t* file, int q)
{
	struct _finddata_t temp;
	long w, i, j, r[40];
	int t;
	t = increment(r, q);
	while (t >= 0)
	{
		w = r[t--];
		for (i = w; i < q; i++)
		{
			temp = file[i];
			for (j = i - w; (j >= 0) && (file[j].size > temp.size); j -= w)
				file[j + w] = file[j];
			file[j + w] = temp;
		}
	}
}

//-------------------------------------------------

void reverse(struct _finddata_t* files, long n)
{
	struct _finddata_t file;
	for (int i = 0; i < n >> 1; i++)
	{
		file = files[i];
		files[i] = files[n - 1 - i];
		files[n - 1 - i] = file;
	}
}
//-------------------------------------------------
struct _finddata_t files[NFiles];

int main(void)
{
	struct _finddata_t file;
	intptr_t hFile;
	char path[200];
	long count = 0;
	int sort = 0, mode = 0, choice=0;
	double timeSpent;
	setlocale(LC_ALL, "Rus");
	printf("������� ���� �� ����������, � ������� ���������� ������������� ����������: ");
	gets(path);
	strcat(path, "*.*");

	if ((hFile = _findfirst(path, &file)) == -1L)
		printf("� ���������, �� ���������� ���� ������ ��� ������, ����������, ���������� ��� ���\n");
	else
	{
		do {
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &file.time_write);
			if (file.attrib & _A_SUBDIR) continue;
			files[count++] = file;
			if (count == NFiles) break;
		} while (_findnext(hFile, &file) == 0);
		_findclose(hFile);
	}
	do
	{
		sort = 0;
		mode = 0;
		while ((sort < 1) || (sort > 6))
		{
			printf("�������� ����� ����������:\n1)���������\n2)�������\n3)���������\n4)����� (������� ����������)\n5)���������\n6)�����\n");
			scanf_s("%d", &sort);
		}
		while ((mode < 1) || (mode > 2))
		{
			printf("�������� ������ ����������:\n1)�� �����������\n2)�� ��������\n");
			scanf_s("%d", &mode);
		}
		clock_t begin = clock();
		switch (sort)
		{
		case 1:
			BubbleSort(files, count);
			break;
		case 2:
			SelectSort(files, count);
			break;
		case 3:
			InsertSort(files, count);
			break;
		case 4:
			QuickSort(files, count);
			break;
		case 5:
			CountingSort(files, count);
			break;
		case 6:
			ShellSort(files, count);
			break;
		}

		if (mode == 2) reverse(files, count);
		clock_t end = clock();
		timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("����    %20c     ���� %24c   ������\n", ' ', ' ');
		printf("----    %20c     ---- %24c   ------\n", ' ', ' ');
		for (int i = 0; i < count; i++)
		{
			printf("%-32.32s   %10lu\n", files[i].name, files[i].size);
		}
		printf("\n����� ����������: %.3lf sec\n", timeSpent);
		printf("������� �������� ����� ����������?\n1 - ��, 2 - ���.\n");
		scanf_s("%i", &choice);
		while ((choice != 1) && (choice != 2))
		{
			printf("������� 1 ��� 12\n");
			scanf_s("%i", &choice);
		}
	} while (choice == 1);
	

	system("pause");
	return 0;
}