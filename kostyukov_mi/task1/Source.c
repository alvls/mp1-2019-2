#include <stdio.h>

void main()
{
	const double DSP_P = 0.00085; // ��������� ���
	const double DVP_P = 0.0008; // ��������� ���
	const double WOOD_P = 0.0008; // ��������� ������ ��� ������

	double h, w, d;

	printf("h w d \n");
	scanf_s("%lf%lf%lf", &h, &w, &d);

	// ������������ ���������� �����
	// double m = 1.5 * DSP_P * d * (2 * (h + w) + (w - 3) * ((int)((h - 3) / 41.5))) + WOOD_P * h * w + DVP_P * 0.5 * h * w;
	//	printf("%lf", m);

	// ��������� ���������� �����
	double DVP_V = h * w * 0.5; // ����� ������ ������

	double DSP_V = 2 * h * d * 1.5; // ����� �������

	double WOOD_V = h * w; // ����� ������

	DSP_V += 2 * w * d * 1.5; // ����� ������� � ������ ������

	int S = (h - 3) / 41.5; // ���-�� �����

	DSP_V += S * (w - 3) * d * (1.5); // ����� �����

	double m = DSP_V * DSP_P + DVP_V * DVP_P + WOOD_V * WOOD_P; // ����� �����

	printf("\n%lf", m);
}