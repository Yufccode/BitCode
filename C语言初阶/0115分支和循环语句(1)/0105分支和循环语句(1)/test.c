#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���1-100�������
#if 0
int ifOdd(int x) {
	return x % 2 == 1 ? 1 : 0;
}
int main() {
	int input = 0;
	printf("������n:");
	scanf("%d", &input);
	for (int i = 1; i <= input; i++) {
		if (ifOdd(i)) {
			printf("%d ", i);
		}
	}
}
//switch���
//case����ֻ�ܸ� ���ͳ������ʽ
#endif

//ѭ��
//continue:��������ѭ��

#if 0
//����������
int main() {
	int ch = 0;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
//����getchar()��ʱ�򣬰�ctrl Z���Դ���getchar()��-1����ֵ����ѭ����ֹ
//����scanf()��ʱ������ctrl Z��һ����ͣ�����������vs��һ��bug��vs��Ҫ��������ctrl Z����


//����
int main() {
	char password[20] = { 0 };
	printf("����������:");
	scanf("%s", password);

	printf("��ȷ������(Y/N):");
	int ch = getchar();
	if ('Y' == ch)
		printf("ȷ�ϳɹ�\n");
	else
		printf("ȷ��ʧ��\n");
	return 0;
}
//err
//��������ǲ���ʵ����Ҫ�Ĺ��ܵģ�����������У�getchar��ȡ���ǻ����������\n ������һ����ȷ��ʧ�ܵ�

//��΢�޸�һ��
int main() {
	char password[20] = { 0 };
	printf("����������:");
	scanf("%s", password);

	getchar();//����\n

	printf("��ȷ������(Y/N):");
	int ch = getchar();
	if ('Y' == ch)
		printf("ȷ�ϳɹ�\n");
	else
		printf("ȷ��ʧ��\n");
	return 0;
}
#endif
//err
//���������� 123456 abcdef\nҲ�ᵯ����printf("��ȷ������(Y/N):");�ģ�
//��ΪgetcharҲ��ֱ���ú���Ķ�����ֱ�Ӹ�ch����������Ҫ�ٸģ���getchar����һ����������
#if 0
int main() {
	char password[20] = { 0 };
	printf("����������:");
	scanf("%s", password);

	//����
	int tmp = 0;
	while ((tmp = getchar()) != '\n') {
		;//������\n֮ǰ�ģ�����\n�Ķ��ᱻ�������
	}

	printf("��ȷ������(Y/N):");
	int ch = getchar();
	if ('Y' == ch)
		printf("ȷ�ϳɹ�\n");
	else
		printf("ȷ��ʧ��\n");
	return 0;
}
#endif


#if 0
//����
int main() {
	int ch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch < '0' || ch>'9')
			continue;
		putchar(ch);
	}
	return 0;
}
//���ã���ȡ�ַ�������ֻ��ӡ�����ַ�
#endif


//forѭ��
#if 0
int main() {
	int i = 0;
	for (i = 1; i <= 10; i++) {
		printf("%d ", i);
	}
	return 0;
}
#endif

//�����ӡ����hehe?
#if 0
int main() {
	int i = 0;
	int j = 0;
	for (; i < 10; i++) {
		for (; j < 10; j++) {
			printf("hehe\n");
		}
	}
	return 0;
}
//����ֻ���ӡ10�����ܶ��˻�����Ϊ��100��
//��Ϊ�ڶ��ν�jѭ����ʱ��j���ᱻ��ʼ��Ϊ0������10�������ڲ�ѭ������һֱ������ȥ��
#endif


#if 1
//����ѭ����������
//���Ƿǳ��ټ�
int main() {
	int x = 0;
	int y = 0;
	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++) {
		printf("hehe\n");
	}
	return 0;
}
#endif