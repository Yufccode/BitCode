#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>



#if 0
#include"add.h"
//����������
//��̬�����ú�ʹ��

//���뾲̬��
#pragma comment(lib,"add.lib")
//ע�⣬����Ҫ���ϲ���

int main() {
	int a = 10;
	int b = 20;
	int sum = Add(a, b);
	//������Ҫʹ�ñ��˵�Add
	//��̬�����ú�ʹ��
	printf("%d\n", sum);
	return 0;
}
//�������õ�add.h��add.lib�������ļ�֮��
//���뾲̬�⣬�Ϳ���ʹ����
//�������ǾͿ��Խ����ǵĴ���ܺõ����� ֻ��¶����������¶Դ����

#endif




//�����ݹ�
//�����������ı�̼��ɳ�Ϊ�ݹ�(recursion)
#if 0
int main() {
	printf("hehe\n");
	main();
	return 0;
}
//�����һ���ݹ飬���ǣ������һ������ݹ飬��ջ�����
//���ݹ�
#endif



#include<string.h>
//��д��������������ʱ���������ַ�������
int my_strlen(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + my_strlen(str + 1);
}
int main() {
	char* arr = "abcdefg";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}