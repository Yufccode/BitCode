#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>

//BC28 ��Сдת��
//��ʽ
//���룺
//A
//B...
//���
//a
//b...
int main() {
	int ch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch >= 'A' && ch <= 'Z') {
			ch += 32;
		}
		printf("%c\n", ch);
		getchar();//ȥ������ʱ��\n���漰���������ĸ���
	}
	return 0;
}