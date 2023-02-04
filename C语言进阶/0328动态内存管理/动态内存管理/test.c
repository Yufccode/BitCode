#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

//�������ٿռ�

//stack-�ֲ�����
//heap-malloc-free-calloc-realloc
//static-ȫ�ֱ���


//�����ɶ������ṹʵ��


//Heap�ϵ��ڴ�
#if 0
int main() {
	int* ptr = (int*)malloc(10 * sizeof(int));//����д��0�Ǳ�׼Ϊ�����
	int* p = ptr;
	if (p == NULL) {
		perror("malloc");
	}
	for (int i = 0; i < 10; i++) {
		*p = i;
		p++;
		//*(p+i)=i;Ҳ�ǿ��Եģ���������д��p��λ��û�иı�
	}
	free(ptr);
	ptr = NULL;
	return 0;
}
#endif
//freeֻ���ͷ�heap�ϵĿռ�

#if 0
int main() {
	int* p = NULL;
	free(p);//ɶ��������
	return 0;
}
#endif


#if 0
int main() {
	int* ptr = (int*)malloc(40);
	if (ptr == NULL) { perror("malloc"); return 1; }
	free(ptr);
	//������ͷžͻ�����ڴ�й¶������
	return 0;
}
//����˵����������
#endif


#if 0
int main() {
	while (1) {
		malloc(10000);
	}
	return 0;
}
#endif


//calloc
//calloc����õ��ڴ��ǳ�ʼ���õģ���Ϊ0
#if 0
int main() {
	int* p = (int*)malloc(40);
	int* q = (int*)calloc(10, sizeof(int));//���Դ��ڴ棬ȫ����ʼ����0��
	//��Ȼ��������Ҳ��Ҫ�жϿ����Ƿ�ɹ���
	return 0;
}
#endif


//realloc
#if 0
int main() {
	int* p = (int*)malloc(10 * sizeof(int));//����д��0�Ǳ�׼Ϊ�����
	if (p == NULL) {
		perror("malloc");
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i;
	}
	//��ʱ�ռ䲻����
    //p = (int*)realloc(p, 20 * sizeof(int));
	//����д�з���
	//�������ʧ�ܣ��ͻ᷵�ؿ�ָ����
	//�������ǽ���һ����ʱָ��
	int* _ptr = (int*)realloc(p, 20 * sizeof(int));
	if (_ptr != NULL) {
		p = _ptr;
	}
	free(p);
	p = NULL;
	return 0;
}
#endif
//realloc�ķ���ֵ����
/*
* 1.�������Ŀռ��㹻��ֱ��׷�ӾͿ�����
* 2.����Ŀռ䲻������--������һ��ռ�--ͬʱ��ǰ�濽������--ͬʱ������ǰ�ǰ���free��
*/


#include<limits.h>
//��̬�ڴ泣����һЩ����
//1.�Կ�ָ��Ľ����ò���
#if 0
int main() {
	int* p = (int*)malloc(INT_MAX);
	//��������Ҫ�п�
	if (p == NULL) {
		exit(-1);
	}
	for (int i = 0; i < 5; i++) {
		*(p + i) = i;
	}
	return 0;
}
#endif
//2.�Զ��ϵĿռ�Խ�����
#if 0
int main() {
	int* arr = (int*)malloc(10 * sizeof(int));
	if (arr == NULL)exit(-1);
	for (int i = 0; i <= 10; i++) {//err
		*(arr + i) = i;
	}
	return 0;
}
#endif


//3.�ԷǶ��ϵĿռ����free����
#if 0
int main() {
	int a = 10;
	int* pa = &a;
	//...
	free(pa);///err
	return 0;
}
#endif


//4.�Զ��ϵĿռ䲻��ȫ�ͷţ�����ڴ�й¶
#if 0
int main() {
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)exit(-1);
	for (int i = 0; i < 10; i++) {
		*p = i;
		p++;
	}
	free(p);//ǰ��Ŀռ��Ѿ��Ҳ����ˣ�err
	return 0;
}
#endif
//һ��Ҫ��ס�ڴ����ʼλ�ã����ܶ�ʧ

//5.�Կ�һ��ռ����ͷ�
#if 0
int main() {
	int* p = malloc(1000);
	if (p == NULL)return 1;
	free(p);
	//...


	free(p);
	return 0;
}
#endif


//6.�����ͷ�
#if 0
void test() {
	int* p = malloc(100);
	//ʹ��
	//����������������ûfree
	//�����Ļ��ڴ��й¶��
	//��Ϊpֻ��һ���ֲ�����
}
int main() {
	test();
	return 0;
}
#endif


//#include<HBD.h>
#if 0
int main() {
	char str[] = "Happy Birthday To you!";
	char str1[] = "Happy everyday!";
	char str2[] = "Achieve your dream!";
	printf("%s\n%s\n%s\n", str, str1, str2);
	system("pause");
	return 0;
}
#endif

//������1
#if 0
void GetMemory(char* p) {
	p = (char*)malloc(100);
}
//��������ʱ�ģ����Խ����err
void Test(void) {
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}
int main() {
	Test();
	return 0;
}
#endif


#if 0
char* GetMemory(void) {
	char p[] = "hello world";
	return p;
}
void Test(void) {
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
int main() {
	Test();
	return 0;
}
#endif
//����ջ�Ͽռ�ĵ�ַ�ǲ��У���������ʱ����ͷ���

#if 0
#include<string.h>
void GetMemory(char** p, int num) {
	*p = (char*)malloc(num);
}
void Test(void) {
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
	free(str);
	str = NULL;
}
int main() {
	Test();
	return 0;
}
#endif



void Test(void) {
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	//Ұָ�������
	//����Ҫֵ���ÿ�
	//str=NULL;
	if (str != NULL) {
		strcpy(str, "world");//������ǷǷ��Ĳ�����
		printf(str);
	}
}
int main() {
	Test();
	return 0;
}