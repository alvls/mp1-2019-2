#include <stdio.h>        
#include <locale.h>
#include <time.h>
#include <conio.h>
int main(void) {
	char *locale = setlocale(LC_ALL, "");
	int k = 0, ch, min = 1, max = 1000, p = 0, t, d = 0; // min - ������ �����, max - ������� �����
	char c = ' ', x;
	while (p == 0) {
		printf("���� ������ � ���� ����������� ��������, ����� ����� 1 � �������� ������ ����� 0 \n");
		scanf_s("%d", &t);
		if (t == 0) {
			ch = srand() % 500 + 500 ;
			printf("�� ���� �� ��� �����������, �� ������ : %d \n", ch);
			while (d != ch) {
				k++;
				printf("������))");
				scanf_s("%d", &d);
				if (d == ch) {
					printf("�� �� ����������!!! \n ��� ���� ���-�� ������� : %d \n", k);
				}
				else {
					if (d < ch) {
						printf("���, �������� ����� �������� \n");
					}
					else {
						printf("���, �������� ����� �������� \n");
					}
				}
			}
		}
		else {
			printf("�����, �����, � �������� \n ���  \n ");
			while (p != 2) {
				ch = (min + max) / 2;
				if (c != '\n') {
					k++;
					printf("%d  ��� ������ '>' ��� ������ '<' \n", ch);
				}
				c = getchar();
				if (c == '>') {
					max = ch;
				}
				if (c == '<') {
					min = ch;
				}
				if (c == '=') {
					printf("�������, �� � ������ \n ��� ��� ���-�� ������� : %d \n ", k);
				}
			}
		}
		p = 1;
		printf("����� ��� ��� ������� ����� 0 \n");
		scanf_s("%d", &p);
	}
}