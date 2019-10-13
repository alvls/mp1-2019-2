#include <stdio.h>
#include <math.h>
#include <string.h>

//�������� �� ��������������, ���������� �� ���� �� 1 �� 9, ���������.
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
//�������� ������� �� �������������� � ��������.
int is_word(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int get_entered(n) //������� �� �����, �� ����-����� - "0", ������� ����-����� - "-1", ������� �� n-������� ����� - "-2"
{
	int result = 0, k = n;
	char c[10];
	int l_lim = 0, r_lim = 0; //��������, � ������� ������ ��������� ��������� �����.
	gets(c);
	if (is_digit(c[0])) //�������� �� �����.
	{
		for (int i = 0; i < k; i++)
		{
			if (is_digit(c[i]))
			{
				result += (c[i] - '0') * pow(10, --n);
				l_lim += pow(10, n);
				r_lim += 9 * pow(10, n);
			}
			else
				return 0;
		}
		if (result >= l_lim && result <= r_lim)
			return result;
		else
			return -2;
	}
	else if (!(strcmp(c, "stop")))
	{
		return -1;
	}
	else
		return 0;
}

int main()
{
	int entered, n;
	scanf_s("%d", &n); getchar();
	entered = get_entered(n);
	if (entered == -1)
		printf("�� �������.\n");
	else if (entered == 0)
		printf("�������� ����.\n");
	else if (entered == -2)
		printf("�� %d-������� �����. ���������� ��� ���.\n");
	else
		printf("%d", entered);
	return 0;
}