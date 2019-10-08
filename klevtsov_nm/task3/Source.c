#include <stdio.h>
#include <time.h>
#include <locale.h>

void bulls_and_cows(int guessed, int n)
{
	int alleged;

	do
	{
		printf("������� %d-������� ����� � ���������������� �������: ", n);
		scanf_s("%d", &alleged);
		
		//��������� n-�� ����� ����������� � n-�� ������ �������������.
	} while (guessed != alleged);

	printf("�� �������!");
}

//Create number with length.
void length_2(int n)
{
	int guessed;
	do { guessed = rand() % 90 + 10; } while (!(guessed / 10 != guessed % 10));
	bulls_and_cows(guessed, n);
}

void length_3(int n)
{
	int guessed;
	do { guessed = rand() % 900 + 100; } while (!(guessed / 100 != guessed % 10 != (guessed / 10) % 10));
	bulls_and_cows(guessed, n);
}

void length_4(int n)
{
	int guessed;
	do { guessed = rand() % 9000 + 1000; } while (!(guessed / 1000 != guessed % 10 != (guessed / 10) % 10 != (guessed / 100) % 10));
	bulls_and_cows(guessed, n);
}

void length_5(int n)
{
	int guessed;
	do { guessed = rand() % 90000 + 10000; } while (!(guessed / 10000 != guessed % 10 != (guessed / 10) % 10 != (guessed / 100) % 10 != (guessed / 1000) % 10));
	bulls_and_cows(guessed, n);
}

void set_length_for_BaC()
{
	int n;
	printf("�������� ����� ������������� �����(�� 2 �� 5).\n 0)�����.\n");
	scanf_s("%d", &n);

	switch (n)
	{
	case 0:
		exit();
		break;
	case 2:
		length_2(n);
		break;
	case 3:
		length_3(n);
		break;
	case 4:
		length_3(n);
		break;
	case 5:
		length_3(n);
		break;
	default:
		printf("������������ ������.\n");
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int variable;
	
	set_length_for_BaC();

	printf("����������� �����?\n");
	printf("1)��.\n");
	printf("2)���.\n");
	scanf_s("%d", &variable);
	if (variable == 1)
		set_length_for_BaC();
	return 0;
}