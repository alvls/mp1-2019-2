#include <stdio.h>
#include <locale.h>

void main()
{


	setlocale(LC_ALL, "Rus");

	int code[4] = { 1001, 1002, 1003, 1004 }, price[4] = { 90, 40 , 60, 80 }, discount[4] = { 10, 20, 30, 40 }, lowerprice[4], kolvo[4] = { 0 }, j, scode, total_discount, price1 = 0, price2 = 0;
	char name[4][10] = { {"������"}, {"��������"}, {"�������"}, {"���"} };


	printf("������� ���������, �� ��������� ����� ������� 0\n");
	scanf_s("%d", &scode);
	do
	{

		for (j = 0; j < 4; j++)
		{
			if (scode == code[j])
			{
				printf("��� �����:%s\n", name[j]);
				lowerprice[j] = price[j] * (100 - discount[j]) / 100;
				printf("���� - %d, ������ - %d, ���� �� ������� - %d\n", price[j], discount[j], lowerprice[j]);
				kolvo[j]++;
				scanf_s("%d", &scode);
			}
			else if (scode == 0)
				break;

		}
	} while (scode != 0);

	for (j = 0; j < 4; j++)
	{
		lowerprice[j] = price[j] * (100 - discount[j]) / 100;
		price1 = price1 + price[j] * kolvo[j];
		price2 = price2 + lowerprice[j] * kolvo[j];
	}
	total_discount = price1 - price2;

	printf("���\n");
	for (j = 0; j < 4; j++)
	{
		if (kolvo[j] != 0)
			printf_s("%s: %d - %d, ���� �� ������� - %d\n", name[j], price[j], kolvo[j], lowerprice[j]);
	}
	printf("����� ��������� ��� ������:%d, ��������� ������:%d, �������� ���������:%d\n", price1, total_discount, price2);

	system("pause>nul");

}
	
