#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//�⺯��
//www.cplusplus.com
//strcpy
//memset

#if 0
int main() {
	char arr[] = "hello bit";
	memset(arr, 'X', 5);//���ֽ�Ϊ��λ���õ�
	printf("%s\n", arr);
	return 0;
}
#endif


//��������
void swap(int x, int y);//err
void swap(int* x, int* y);//��ȷд��
//��ʽ������ʵ�ʲ���



//��ϰ��
//1.дһ�������ж���������ӡ100~200������
//2.�ж�����
//3.ʵ����������Ķ��ֲ���


//дһ��������ÿ����һ������������ͻὫnum��ֵ����1
#define TIMES 3//�������
void test(int*p) {
	*p += 1;
#if 0
	*p++;//err
	(*p)++;//��ȷ
#endif
}
int main() {
	int num = 0;
	for (int i = 0; i < TIMES; i++) {
		test(&num);
	}	
	printf("%d\n", num);
	return 0;
}