#include <stdio.h>
#include <math.h>
#include <clocale>


void main()
{
	setlocale(LC_ALL, "Russian");
	double x1, y1, a, x2, y2, b, l, k, q;
	printf("������� a, (x1,y1) � b, (x2,y2)");
	scanf_s("%lf %lf %lf %lf %lf %lf", &a, &x1, &y1, &b, &x2, &y2);
	l = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (b>a)  
	{
		k = b;
		b = a;
		a = k;
	}
	if (l > (a + b))
		printf("1) ���������� �� ������������");
	else if (l == a + b)
			printf("2) ���������� ������������� �� ������� �������");
		 else if (l < a + b)
				  if (l > a - b)
					  printf("3) ���������� ������������");
					  if ((l == a - b) && (l != 0))
						  printf("4) ���������� ������������� �������");
						  else if (l < a - b)
						           printf("5) ���� ���������� ������ ������");
						           else if ((l = 0) && (a - b == 0))
						                    printf("6) ���������� �����");
scanf_s("%lf", &q);
}