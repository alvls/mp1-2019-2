#define _USE_MATH_DEFINES
#define N 25

#include <stdio.h>
#include <math.h>
#include <locale.h>
void farctg (double p, float E, int k)
{
	int i;
	double arc_tg = atan(p) , func = p, delta = fabs(arc_tg - func), number = p;
	for (i = 1; (i <= k) && (delta > E); i++) {
		number = (-1) * p * p * number;
		func = func + (number / (2 * i + 1));
		delta = fabs(arc_tg - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i , func , delta);
}
void farcctg(double p, float E, int k)
{
	int i;
	double arc_ctg = M_PI / 2 - atan(p), func = M_PI / 2 - p, delta = fabs(arc_ctg - func), number = - p;
	for (i = 1; (i <= k) && (delta > E); i++) {
		number = (-1) * p * p * number;
		func = func + (number / (2 * i + 1));
		delta = fabs(arc_ctg - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i , func, delta);
}
void fsin(double x, float E, int k)
{
	int i;
	double sin_c = sin(x), func = x, delta = fabs(sin_c - func), term = x;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = (-1) * term * x * x / ((2 * i - 1) * (2 * i - 2));
		func = func + term;
		delta = fabs(sin_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}

void fcos(double x, float E, int k)
{
	int i;
	double cos_c = cos(x), func = 1, delta = fabs(cos_c - func), term = 1;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = (-1) * term * x * x / ((2 * i - 2) * (2 * i - 3));
		func = func + term;
		delta = fabs(cos_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}

void fexp(double x, float E, int k)
{
	int i;
	double exp_c = exp(x), func = 1, delta = fabs(exp_c - func), term = 1;
	for (i = 2; (i <= k) && (delta > E); i++)
	{
		term = term * x / (i - 1);
		func = func + term;
		delta = fabs(exp_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}
void output_one(void(*f)(double, float, int), double x, double func)
{
	float E;
	int k;
	printf("������� �������� ���������� (>= 0,000001)\n");
	scanf_s("%f", &E);
	printf("������� ���������� ��������� �� 1 �� 1000\n");
	scanf_s("%d", &k);
	printf("��������� ��������: %lf\n", func);
	printf("���-�� ���������   ����������� ������ �������   ������� ����� ������� � ��������\n");
	f(x, E, k);
}

void output_two(void(*f)(double, float, int), double x, double func)
{
	float E[N];
	int k[N], experience, i;
	printf("������� ���������� ������������� �� 1 �� 25?\n");
	scanf_s("%d", &experience);
	for (i = 0; i < experience; i++)
	{
		printf("������� �������� ���������� (>= 0,000001) ��� %d-��� ������������\n", i + 1);
		scanf_s("%f", &E[i]);
		printf("������� ���������� ��������� �� 1 �� 1000 ��� %d-��� ������������\n", i + 1);
		scanf_s("%d", &k[i]);
	}
	printf("��������� ��������: %lf\n", func);
	printf("���-�� ���������   ����������� ������ �������   ������� ����� ������� � ��������\n");
	for (i = 0; i < k[i]; i++)
		f(x, E[i], k[i]);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	void(*f)(double, float, int) = NULL;
	double x, func;
	int mode, fun ;
	printf("�������� �����\n 1 - ������� � ���������� \n 2 - ���������������)) \n");
	scanf_s("%d", &mode);
	printf("�������� �������\n 1 - sin(x)\n 2 - cos(x)\n 3 - exp(x)\n 4 - arctg(x)\n 5 - arcctg(x) \n");
	scanf_s("%d", &fun);
	printf("������� x\n");
	scanf_s("%lf", &x);
	switch (fun)
	{
	case 1:
		f = fsin;
		x = x / 180 * M_PI;
		func = sin(x);
		break;
	case 2:
		f = fcos;
		x = x / 180 * M_PI;
		func = cos(x);
		break;
	case 3:
		f = fexp;
		func = exp(x);
		break;
	case 4:
		f = farctg;
		func = atan(x);
		break;
	case 5:
		f = farcctg;
		func = M_PI / 2 - atan(x);
		break;
	}
	if (mode == 1)
		output_one(f, x, func);
	else
		output_two(f, x, func);
	system("pause");
}