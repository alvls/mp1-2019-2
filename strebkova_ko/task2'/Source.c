#include <stdio.h>
#include <locale.h>
#include <ctype.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int ndigit = 0, nword = 0, choice;
	char c, p = ' ';
	printf("������� �����:\n");
	do
	{
		c = getchar();
		switch (c)
		{
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			if ((p == ' ') || (p == '\t'))
				ndigit++;
			break;
		default:
			if (((p == ' ') || (p == '\t')) && ((isalpha(c)) || (c < (int)(NULL))))
				nword++;
			break;
		}
		p = c;
	} while (c != '\n');
	printf("���������� ����: %d\n", nword);
	printf("���������� �����: %d\n", ndigit);
	do
	{
		printf("������ ����� �����?\n");
		printf("1)��\n");
		printf("2)���\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			getchar();
			main();
		case 2:
			return 0;
		default:
			printf("������ ������\n");
		}
	} while ((choice != 1) || (choice != 2));
	system("pause");
}