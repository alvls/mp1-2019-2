#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include "TaylorFuncs.h"

struct t_func
{
	char name[250];
	void(*func)(mode1Res *, long double, long double, long long);
};
struct t_func_series
{
	char name[250];
	void(*func)(mode2Res *, long double, long long);
};

int main()
{
	setlocale(LC_ALL, "Rus");
	t_func t_funcs[] = 
	{
		"Cинус", t_sin,
		"Коcинус", t_cos,
		"Экспонента", t_exp,
		"Арктангенс", t_arctg,
	};
	t_func_series t_funcs_series[] =
	{
		"Cинус", t_sin,
		"Коcинус", t_cos,
		"Экспонента", t_exp,
		"Арктангенс", t_arctg,
	};
	while (true)
	{
		printf("Выберите функцию\n");
		for (int i = 0; i < (sizeof(t_funcs) / sizeof(*t_funcs)); i++)
		{
			printf("%d) %s\n", i + 1, t_funcs[i].name);
		}
		int func_id = 0, mode = 0;
		long double x = 0;
		long long n = 0;
		mode1Res resultMode1 = {};
		mode2Res resultMode2 = {};
		long double delta = 0;
		scanf("%d", &func_id);

		printf("Выберите режим\n");
		scanf("%d", &mode);

		switch (mode)
		{
		case 1:
			printf("Введите точку, точность вычисления, кол-во элементов ряда\n");
			scanf("%lf %lf %ld", &x, &delta, &n);
			t_funcs[func_id - 1].func(&resultMode1, x, delta, n);
			printf("Эталонное значение: %lf\n", resultMode1.referenceResult);
			printf("Вычисленное значение: %lf\n", resultMode1.result);
			printf("Разница между эталонным и вычисленным значением: %lf\n", resultMode1.delta);
			printf("Кол-во вычисленных слагаемых: %ld\n", resultMode1.n);
			break;
		case 2:
			printf("Введите точку, число экспериментов\n");
			scanf("%lf %ld", &x, &n);
			printf("\n%ld\n", n);
			t_funcs_series[func_id - 1].func(&resultMode2, x, n);
			printf("Кол-во слагаемых  Вычисленное значение Разница с эталонным значением\n"); 
			for (int i = 1; i <= resultMode2.NMax; i++)
			{
				printf("%ld\t\t%lf\t\t%lf\n", i, resultMode2.results[i], resultMode2.deltas[i]);
			}
			break;
		default:
			continue;
		}
	}
}