#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int r1(void)
{
	srand(time(NULL));
	int r = (rand() % 1000) + 1;
	int n = 0;
	int i = 0;
	printf("�������� �����\n");
	do 
	{
		i++;
		scanf("%d", &n);
		if (n > r)
			printf("���������� ����� ������\n");
		if (n < r)
			printf("���������� ����� ������\n");
	} while (n != r);
	printf("�� ������ ���������� ����� �� %d �������", i);
	return 0;
}
int r2(void)
{
	char c=0, o;
	int n1 = 1;
	int n2 = 1000;
	int n = 0;
	int i = 0;
	printf("���� �������\n");
	do
	{
		n = (n1 + n2) / 2;
		printf("%d\n", n);
		c = getchar();
		o = getchar();
		i++;
		if (c == '>')
		{
			n1 = n;
		}
		if (c == '<')
		{
			n2 = n;
		}
	} while (c != '=');
	printf("� ������ �� %d �������", i);
}


int main(void)
{
	setlocale(LC_ALL, "Rus");

	int r;

	int(*func[3])() = { exit, r1,r2 };
	do
	{
		printf("�������� �����\n1)�� ����������\n2)� ��������\n0)�����\n");
		scanf("%d", &r);
		func[r]();
	} while (2 * 2 == 4);
}