#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>


//ͬһ�������ڲ�ͬ�������µõ��Ĵ𰸲�ͬ��˵������һ���������

//32λ�����ַ�ռ�
//CPU-32λ��ַ-��ַ�ߴ���->�ڴ�
//64λ�����ַ�ռ�
//CPU-64λ��ַ-�����ߴ���->�ڴ�


//����ָ��
#if 0
int main() {
	int a = 10;
	int* pa = &a;
	printf("%p\n", pa);
	return 0;
}
#endif


//ָ���ָ������
//Ϊʲô��Ҫָ������



#if 0
int main() {
	int a = 0x11223344;
	//int* pa = &a;
	//*pa = 0;
	char* pa2 = &a;
	*pa2 = 0;
	return 0;
}
#endif
//ͨ�����ڴ����ǿ��Է���
//ָ�����;��������õ�ʱ��ķ���Ȩ��





//ָ�����;���ָ��+1���������ֽ�
#if 0
int main() {
	int a = 10;
	int* p1 = &a;
	char* p2 = &a;
	printf("%p\n", p1);
	printf("%p\n", p2);
	printf("%p\n", p1 + 1);
	printf("%p\n", p2 + 1);
	return 0;
}
#endif




//Ұָ��
#if 0
int* test() {
	int a = 10;
	printf("%d\n", a);
	return &a;
}
int main() {
	int* p = test();
	*p = 100;
	printf("%d\n", *p);
	return 0;
}
#endif
//err
//a���ڴ��ڳ�test()��ʱ���Ѿ��ͷ�
//p���Ǹ�Ұָ��
//pָ��ĵط��Ѿ�û�в���Ȩ����

//�ǵó�ʼ����
//���ÿվ��ÿգ�
//��ֹԽ�磡
//ʹ��ָ��ǰ���ָ�����Ч�ԣ�
//���ⷵ�ؾֲ������ĵ�ַ��



//ָ�������
//ָ��-ָ��ľ���ֵ��ָ���ָ��֮���Ԫ�ظ���
///ǰ�᣺����ָ�����ָ��ͬһ��ռ�


//my_strlen()�ĵ����ַ�����ָ��-ָ��
#if 0
int my_strlen(char* str) {
	char* cur = str;
	while (*cur)
		cur++;
	return cur - str;
}
int main() {
	char arr[] = "abcdef";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
	return 0;
}
#endif

//����������Ԫ�ص�ַ
//��������������
//sizeof(������)����������ʾ��������
//&����������ʾȥ����������ĵ�ַ
#if 0
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	int* p2 = &arr;//������p2������int*����,+1ֻ������4���ֽڣ�ֻ������һ��
	int ret = *(&arr + 1);
	printf("%p\n", p + 1);
	printf("%p\n",p2 + 1);
	printf("%p\n", &arr + 1);
	printf("%d\n", ret);
	return 0;
}
//�����ַ+1������������
#endif


#if 0
//����ָ��
int main() {
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;
	printf("%p\n", pa);
	printf("%p\n", ppa);
	return 0;
}
#endif



int main() {
	int data1[] = { 1,2,3,4,5 };
	int data2[] = { 2,3,4,5,6 };
	int data3[] = { 3,4,5,6,7 };

	int* arr[3] = { data1,data2,data3 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
	return 0;
}