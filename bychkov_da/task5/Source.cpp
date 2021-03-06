#define _CRT_SECURE_NO_WARNINGS
#define MAX 5000
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h> 
#include <conio.h>
#include <time.h>  
#include <malloc.h>
#include <cstring>
#include <locale.h>
//c:\temp\*.*
void mergeSort(long size[MAX], char* name[MAX], int lb, int ub);
void quickSortR(int count, long size[MAX], char* name[MAX]);
void shellSort(int count, long size[MAX], char* name[MAX]);
int main(void)
{	
	setlocale(LC_ALL, "Russian");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	int typesort;
	long size[MAX];
	char* name[MAX];											
	int i;
	int stop;
		printf("Введите путь до дирректории \n");
		gets_s(path);
		do {
			if ((hFile = _findfirst(path, &c_file)) == -1L)
				printf("No files in current directory!\n");
			else
			{
				do {
					if (c_file.name[0] == '.') continue;
					name[count] = (char*)malloc(strlen(c_file.name) + 1);
					strcpy(name[count], c_file.name);
					size[count] = c_file.size;
					count++;

				} while (_findnext(hFile, &c_file) == 0);
				_findclose(hFile);
			}
			printf("Выберите метод сортировки:\n1 бузырек\n2 выбором \n3 вставками \n4 слиянием\n5 Хоара\n6 Шелла\n");
			printf("Выберите метод сортировки: ");
			scanf_s("%d", &typesort);
			if (typesort == 1)
			{
				clock_t begin = clock();
				int i, j;
				long x;
				char* y;
				for (i = 0; i < count; i++)
				{
					for (j = count - 1; j > i; j--)
					{
						if (size[j - 1] > size[j])
						{
							x = size[j - 1];
							size[j - 1] = size[j];
							size[j] = x;
							y = name[j - 1];
							name[j - 1] = name[j];
							name[j] = y;
						}
					}
				}
				clock_t end = clock();
				float time = (float)(end - begin) / CLOCKS_PER_SEC;

				printf("\nВремя работы сортировки: %f ceк\n", time);

				for (i = 0; i < count; i++)
				{
					printf("Файл: %s    Размер: %ld \n", name[i], size[i]);
					free(name[i]);
				}
				printf("Попробуем другой способ? Введите 1 (Введите 0 если хотите закончить)  \n");
				scanf_s("%d", &stop);
			}
			if (typesort == 2)
			{
				clock_t begin = clock();
				long i, j, k;
				long x;
				char* y;
				for (i = 0; i < count; i++)
				{
					k = i;
					x = size[i];
					y = name[i];
					for (j = i + 1; j < count; j++)
						if (size[j] < x)
						{
							k = j;
							x = size[j];
							y = name[j];
						}
					size[k] = size[i];
					size[i] = x;

					name[k] = name[i];
					name[i] = y;
				}
				clock_t end = clock();
				float time = (float)(end - begin) / CLOCKS_PER_SEC;
				printf("\nВремя работы сортировки: %f ceк\n", time);
				for (i = 0; i < count; i++)
				{
					printf("Файл: %s    Размер: %ld \n", name[i], size[i]);
				}
				printf("Попробуем другой способ? Введите 1 (Введите 0 если хотите закончить)  \n");
				scanf_s("%d", &stop);
			}
			if (typesort == 3)
			{
				clock_t begin = clock();
				long i, j;
				long x;
				char* y;
				for (i = 0; i < count; i++)
				{
					x = size[i];
					y = name[i];
					for (j = i - 1; j >= 0 && size[j] > x; j--)
					{
						size[j + 1] = size[j];
						name[j + 1] = name[j];
					}
					size[j + 1] = x;
					name[j + 1] = y;
				}
				clock_t end = clock();
				float time = (float)(end - begin) / CLOCKS_PER_SEC;
				printf("\nВремя работы сортировки: %f ceк\n", time);
				for (i = 0; i < count; i++)
				{
					printf("Файл: %s    Размер: %ld \n", name[i], size[i]);
				}
				printf("Попробуем другой способ? Введите 1 (Введите 0 если хотите закончить)  \n");
				scanf_s("%d", &stop);
			}
			if (typesort == 4)
			{
				clock_t begin = clock();
				mergeSort(size, name, 0, count - 1);
				clock_t end = clock();
				float time = (float)(end - begin) / CLOCKS_PER_SEC;
				printf("\nВремя работы сортировки: %f ceк\n", time);
				for (i = 0; i < count; i++)
				{
					printf("Файл: %s    Размер: %ld \n", name[i], size[i]);
				}
				printf("Попробуем другой способ? Введите 1 (Введите 0 если хотите закончить)  \n");
				scanf_s("%d", &stop);
			}
			if (typesort == 5)
			{
				clock_t begin = clock();
				quickSortR(count, size, name);
				clock_t end = clock();
				float time = (float)(end - begin) / CLOCKS_PER_SEC;
				printf("\nВремя работы сортировки: %f ceк\n", time);
				for (i = 0; i < count; i++)
				{
					printf("Файл: %s    Размер: %ld \n", name[i], size[i]);
				}
				printf("Попробуем другой способ? Введите 1 (Введите 0, если хотите закончить)  \n");
				scanf_s("%d", &stop);
			}
			if (typesort == 6)
			{
				clock_t begin = clock();
				shellSort(count, size, name);
				clock_t end = clock();
				float time = (float)(end - begin) / CLOCKS_PER_SEC;
				printf("\nВремя работы сортировки: %f ceк\n", time);
				for (i = 0; i < count; i++)
				{
					printf("Файл: %s    Размер: %ld \n", name[i], size[i]);
				}
				printf("Попробуем другой способ? Введите 1 (Введите 0, если хотите закончить)  \n");
				scanf_s("%d", &stop);
			}
			count = 0;
		} while (stop != 0);
}
void merge(long size[MAX], char* name[MAX], int lb, int split, int ub)
{
	long pos1 = lb;
	long pos2 = split + 1;
	long pos3 = 0;
	long* temp1 = new long[ub - lb + 1];
	char** temp2 = new char* [ub - lb + 1];
	while (pos1 <= split && pos2 <= ub)
	{
		if (size[pos1] < size[pos2])
		{
			temp1[pos3] = size[pos1];
			temp2[pos3++] = name[pos1++];
		}
		else
		{
			temp1[pos3] = size[pos2];
			temp2[pos3++] = name[pos2++];
		}
	}
	while (pos2 <= ub)
	{
		temp1[pos3] = size[pos2];
		temp2[pos3++] = name[pos2++];
	}
	while (pos1 <= split)
	{
		temp1[pos3] = size[pos1];
		temp2[pos3++] = name[pos1++];
	}
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
	{
		size[lb + pos3] = temp1[pos3];
		name[lb + pos3] = temp2[pos3];
	}
	delete[] temp1;
	delete[] temp2;
}
void mergeSort(long size[MAX], char* name[MAX], int lb, int ub)
{
	long split;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		mergeSort(size, name, lb, split);
		mergeSort(size, name, split + 1, ub);
		merge(size, name, lb, split, ub);
	}
}
void quickSortR(int count, long size[MAX], char* name[MAX])
{
	long i = 0, j = count - 1;
	long temp1, p;
	char* temp2;
	p = size[count >> 1];
	do
	{
		while (size[i] < p) i++;
		while (size[j] > p) j--;
		if (i <= j)
		{
			temp1 = size[i];
			size[i] = size[j];
			size[j] = temp1;

			temp2 = name[i];
			name[i] = name[j];
			name[j] = temp2;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) quickSortR(j, size, name);
	if (count > i) quickSortR(count - i, size + i, name + i);
}
int increment(long inc[], long size)
{
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
		if (++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}
void shellSort(int count, long size[MAX], char* name[MAX])
{
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, count);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < count; i++)
		{
			long temp1 = size[i];
			char* temp2 = name[i];
			for (j = i - inc; (j >= 0) && (size[j] > temp1); j -= inc)
			{
				size[j + inc] = size[j];
				name[j + inc] = name[j];
			}
			size[j + inc] = temp1;
			name[j + inc] = temp2;
		}
	}
}
