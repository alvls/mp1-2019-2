#include <stdio.h>

void main()
{
	const float DSV_P = 0.0008; // ��������� ���
	const float DSP_P = 0.00085; // ��������� ���
	const float WOOD_P = 0.0008; // ��������� ������ ��� ������

	float w, h, d;

	printf("w h d \n");
	scanf_s("%f%f%f", &w, &h, &d);

	float DVP_V = w * h * (0.5); //������ ������
	
	float DSP_V = 2 * h * d * (1.5); // ��� ��������

	float WOOD_V = h * w; // �����

	DSP_V += 2 * w * d * (1.5); // ������� � ������ ������

	int S = (h - 3) / (41.5); // ���-�� �����

	DSP_V += S * d * w * (1.5); // �����

	float m = DSP_V * DSP_P + DVP_V * DSV_P + WOOD_V * WOOD_P; // ����� �����

	printf("\n%f", m);

}