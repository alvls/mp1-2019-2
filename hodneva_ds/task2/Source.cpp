#include "stdio.h"

#include "math.h"

#include<locale.h>

#include <stdlib.h>

#include <time.h>

int main()

{
	setlocale(LC_ALL, "Russian");
	int num = rand() % 1000;
		printf("%d", num);
	int a;
		printf("������� �����: ");
		scanf_s("%d", &a);
	while (a != num);
	{
		printf("������� �����: ");
		scanf_s("%d", &a);
		if (num < a) {
			printf("���������� ����� ������");
		}
		else {
			if (num > a) {
				printf("���������� ����� ������");
			}
		}
	}
	printf("�������");
	return 0;
}