#include <stdio.h>
#include <locale.h>

int queen(int X1, int Y1, int X2, int Y2)
{

}

void main()
{
	setlocale(LC_ALL, "Rus");
	char K1[3];
	char K2[3];
	int piece;

	int c,d, m ,n, x1,x2,y1,y2;

	scanf("%s", &K1);
	scanf("%s", &K2);
	x1 = (int)K1[0] - 96;
	y1 = (int)K1[1] - 48;
	x2 = (int)K2[0] - 96;
	y2 = (int)K2[1] - 48;

	printf("�������� ������:");
	printf("1. �����");
	printf("2. �����");
	printf("3. ������");
	printf("4. ����");
	printf("5. ����");
	scanf("%i", &piece);


}