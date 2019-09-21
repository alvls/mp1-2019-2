#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

//�������� ����� �������� � �����.
int difWord, difNum;

//�������, ����������� ������ ������� �� ������ �� ������ ������.
int king(char word1, char word2, int num1, int num2)
{
	if ((difWord == 1) && (difNum == 1))
		return 1;
	else
		return 0;
}

int queen(char word1, char word2, int num1, int num2)
{
	if ((word1 == word2) || (num1 == num2) || (difWord == difNum))
		return 1;
	else
		return 0;
}

int rook(char word1, char word2, int num1, int num2)
{
	if ((word1 == word2) || (num1 == num2))
		return 1;
	else
		return 0;
}

int phant(char word1, char word2, int num1, int num2)
{
	if (difWord == difNum)
		return 1;
	else
		return 0;
}	

int horse(char word1, char word2, int num1, int num2)
{
	if (((difWord == 1) && (difNum == 2)) || ((difWord == 2) && (difNum == 1)))
		return 1;
	else
		return 0;
}

//������ �� ����� ������ ����� ��������� ������� �� ������ ������.
void kingOut()
{
	printf("� ��� ������ ����� ������� ������.\n");
}

void queenOut()
{
	printf("� ��� ������ ����� ������� �����.\n");
}

void rookOut()
{
	printf("� ��� ������ ����� ������� �����.\n");
}

void phantOut()
{
	printf("� ��� ������ ����� ������� ����.\n");
}

void horseOut()
{
	printf("� ��� ������ ����� ������� ����.\n");
}

void main()
{
	setlocale(LC_ALL, "Rus");

	char K1[3], K2[3];
	char word1, word2;
	int num1, num2;
	int variable;

	//���� ������.
	do
	{
		printf("������� ������ 1 (����� �� A �� H, ����� �� 1 �� 8): ");
		scanf("%s", &K1);
		printf("������� ������ 2 (...): ");
		scanf("%s", &K2);
		word1 = K1[0];
		word2 = K2[0];
		num1 = (int)K1[1]-48;
		num2 = (int)K2[1]-48;
		if ((word1, word2 < 'A') && (word1, word2 > 'H') && (num1, num2 < 1) && (num1, num2 > 8))
		{
			printf("������������ ������.\n");
		}
	} while ((word1, word2 < 'A') && (word1, word2 > 'H') && (num1, num2 < 1) && (num1, num2 > 8));

	difWord = fabs((int)(word1)- (int)word2);
	difNum = fabs(num1 - num2);

	//����� ������, ��� ������� �� ����� ��������, ������� �� ��� �� �������, � ���� �� �������, �� ����� ������ �����, ������� ����� ������� �� ��� ������.
	printf("�������� ������:\n");
	printf("1)������.\n");
	printf("2)�����.\n");
	printf("3)�����.\n");
	printf("4)����.\n");
	printf("5)����.\n");
	scanf_s("%d", &variable);
	switch (variable)
	{
	case 1:
		if (king(word1, word2, num1, num2))
		{
			printf("������ ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
		}
		else
		{
			printf("������ �� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
			if (queen(word1, word2, num1, num2))
				queenOut();
			if (rook(word1, word2, num1, num2))
				rookOut();
			if (phant(word1, word2, num1, num2))
				phantOut();
			if (horse(word1, word2, num1, num2))
				horseOut();
		}
		break;
	case 2:
		if (queen(word1, word2, num1, num2))
		{
			printf("����� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
		}
		else
		{
			printf("����� �� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
			if (king(word1, word2, num1, num2))
				kingOut();
			if (rook(word1, word2, num1, num2))
				rookOut();
			if (phant(word1, word2, num1, num2))
				phantOut();
			if (horse(word1, word2, num1, num2))
				horseOut();
		}
		break;
	case 3:
		if (rook(word1, word2, num1, num2))
		{
			printf("����� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
		}
		else
		{
			printf("����� �� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
			if (king(word1, word2, num1, num2))
				kingOut();
			if (queen(word1, word2, num1, num2))
				queenOut();
			if (phant(word1, word2, num1, num2))
				phantOut();
			if (horse(word1, word2, num1, num2))
				horseOut();
		}
		break;
	case 4:
		if (phant(word1, word2, num1, num2))
		{
			printf("���� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
		}
		else
		{
			printf("���� �� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
			if (king(word1, word2, num1, num2))
				kingOut();
			if (queen(word1, word2, num1, num2))
				queenOut();
			if (rook(word1, word2, num1, num2))
				rookOut();
			if (horse(word1, word2, num1, num2))
				horseOut();
		}
		break;
	case 5:
		if (horse(word1, word2, num1, num2))
		{
			printf("���� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
		}
		else
		{
			printf("���� �� ����� �� ���� ��� ������� �� ������ %c%d � ������ %c%d.\n", word1, num1, word2, num2);
			if (king(word1, word2, num1, num2))
				kingOut();
			if (queen(word1, word2, num1, num2))
				queenOut();
			if (rook(word1, word2, num1, num2))
				rookOut();
			if (phant(word1, word2, num1, num2))
				phantOut();
		}
		break;
	default:
		printf("�� ���������� �������� ��������.\n");
		break;
	}

	printf("������ ��� ������ ����� � ������?\n");
	printf("1)��.\n");
	printf("2)���.\n");
	scanf_s("%d", &variable);
	if (variable == 1)
	{
		main();
	}
}