#include <stdio.h>        
#include <locale.h>
#include <time.h>
#include <conio.h>
int main(void) {
	char *locale = setlocale(LC_ALL, "");
	int chislo[5], computer[5]; // chislo - ��� ������ ��������� ������� ������ ������������,computer - ������ �������� ������������� �����
	int b, k, p, ch, n, l = 0 , x = 1;// b - ���� , k - ������ ,ch - �������� ������������ ����� , l - ����, x - ���� 
	while (x == 1) {
		printf("����� n");
		scanf_s("%d", &n);
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			ch = rand() % 10;
			while (l == 0) {			// ���������� ��������� �����					
				for (int j = 0; j < n; j++) {
					while (computer[j] == ch) {
						ch = rand() % 10;
						j = 0;															
					}
					if (j == 3) {
						l = 1;
					}
				}
			}
			if (l == 1) {
				computer[i] = ch;
				ch = 0;
				//printf("%d", computer[i]);
				l = 0;
			}
		}
		  /*_______//________������!______________
			______(o)(o)___________________________
			______(�_�)____� ����� ������____________
			_______(_)____________����� ����_______
			_______(_)_______________________���_
			_________(_)_________(_)(_)_____________
			___________(_)____(_)(_)__(_)(_)__________
			_____________(_)(_)__________(_)(_)(_)(_)__
			______________________________________
			� ��� ����� ������, �������� ����� */
		k = 0;
		b = 0;
		p = 0;
		while (p == 0) {
			printf("������ �������\n");
			scanf_s("%d", &ch);
			b = 0;
			k = 0;
			for (int i = n - 1; i >= 0; i--) {		// �� ���, ��� ,������ ������� ����, �� ��� ���, �������� 
				chislo[i] = ch % 10;
				ch = ch / 10;
				//printf("i = %d chislo[i] = %d \n", i, chislo[i]);
				if (chislo[i] == computer[i]) {
					b++;
				}
				else {
					for (int j = 0; j < n; j++) {
						if ((chislo[i] == computer[j]) && (j != i)) {
							k++;
						}
					}
				}
			}
			if (b == n) {
				printf("�� ������\n");
				p = 1;
			}
			else {
				printf("��� ���-�� ����� %d � ����� %d\n", b, k);

			}
		}
		x = 0;
		printf("���� ������ ������� ��� ���, �� ����� 1");
		scanf_s("%d", &x);
	}
}