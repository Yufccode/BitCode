#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<string.h>

//��������

//�ṹ�����һ��Ԫ��������δ֪��С�����飬��ͽ�����������
//������������������
#if 0
struct S {
	int num;
	double d;
	int arr[];//���������Ա
};
//���������һ���ܵù����������Ӧ�ÿ��ԣ�����֮��һ���϶����Ե�
struct S2 {
	int num;
	double d;
	int arr[0];//Ҳ�����������Ա
};
struct S3 {
	int num;
	int arr[0];//Ҳ�����������Ա
};
int main() {
	printf("%d\n", sizeof(struct S3));//4
	return 0;
}
#endif
//����������ص�
/*
* 1.�ṹ�е����������Աǰ���������һ��������Ա
* 2.sizeof()���ص����ֽṹ��С����������������ڴ�
* 3.�������������Ա�Ľṹ��malloc���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ��Ĵ�С������Ӧ���������Ԥ�ڴ�С
*/



#if 0
struct S3 {
	int num;
	int arr[0];//Ҳ�����������Ա
};
int main() {
	struct S3* ps = (struct S3*)malloc(sizeof(struct S3) + 40);
	//��þ����ж�һ�¿����Ƿ�ɹ�
	//����10�����Σ���д40
	ps->num = 100;
	for (int i = 0; i < 10; i++) {
		ps->arr[i] = i;
	}
	//��ӡ
	for (int i = 0; i < 10; i++) {
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	//����
	struct S3* ptr = (struct S3*)realloc(ps, sizeof(struct S3) + 80);
	if (ptr == NULL) {
		perror("realloc");
		exit(-1);
	}
	ps = ptr;
	for (int i = 0; i < 20; i++) {
		ps->arr[i] = i;
	}
	for (int i = 0; i < 20; i++) {
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	//�ͷ�
	free(ps);
	ps = NULL;
	return 0;
}
#endif


struct S4 {
	int num;
	int* arr;
};
int main() {
	struct S4* ps = (struct S4*)malloc(sizeof(struct S4));
	if (ps == NULL) {
		perror("malloc struct");
		exit(1);
	}
	ps->arr = (int*)malloc(40);
	if (ps->arr == NULL) {
		perror("malloc array");
		free(ps);
		ps = NULL;
		exit(1);
	}
	//�ͷ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
//�о������ʽ��������������û������
//����������ǣ�����������num��arr�ǿ���һ��ģ��������
//������ָ��ʵ�ֵķ�ʽ��num��arr��һ������һ���
//�����������ַ�ʽ�Ŀ���ʵ����ͬ��Ч��

//����

//�������������
/*
* 1.�����ڴ���ͷ�
* 2.�����ڷ����ٶ�-�����ڼ����ڴ���Ƭ
*/