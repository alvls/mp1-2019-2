#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	double DVPp, DVPv, DSPp, DSPv, WOODp, WOODv, h, w, d, m;
	int k;
	DVPp = 850;
	DSPp = 800;
	WOODp = 800;

	printf("Vvedite h, w, d\n");
	scanf_s("%lf%lf%lf", &h, &w, &d);

	if ((h <= 2.2) && (h >= 1.8) && (w <= 1.2) && (w >= 0.8) && (d <= 0.9) && (d >= 0.5))
	{
		DVPv = 0.005 * h * w; // ����� ������ ������
		DSPv = 2 * 0.015 * h * d + 2 * 0.015 * d * w; // ����� 2 �������, ������� � ������ ������
		WOODv = 0.01 * h * w; // ����� ������
		k = h / 0.415 - 1; // ���������� �����
		m = DVPp * DVPv + DSPp * DSPv + WOODp * WOODv + k * 0.015 * (d - 0.005) * (w - 2 * 0.015);
		printf("%.2f\n", m);
	}
	else
		printf("error 404\n"); //��������� ������������� ���������
	system("pause");
}