#define _CRT_SECURE_NO_WARNINGS 1

//ָ���������������

#include<stdio.h>
#include<string.h>

//һά����
#if 0
int main() {
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a + 0));//4
	printf("%d\n", sizeof(*a));//4
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4
	printf("%d\n", sizeof(*&a));//16
	printf("%d\n", sizeof(&a + 1));//4
	printf("%d\n", sizeof(&a[0]));//4
	printf("%d\n", sizeof(&a[0] + 1));//4
	return 0;
}
#endif
//�ַ�����
#if 0
int main() {
	char arr[] = { 'a','b','c','d','e','f' };
#if 0
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr + 0));//4
	printf("%d\n", sizeof(*arr));//1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr+1));//4
	printf("%d\n", sizeof(&arr[0] + 1));//4
#endif
	printf("%d\n", strlen(arr));//���ֵ
	printf("%d\n", strlen(arr + 0));//���ֵ
	//printf("%d\n", strlen(*arr));//err
	//printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//���ֵ
	printf("%d\n", strlen(&arr + 1));//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ
	return 0;
}
#endif


//�ַ���
#if 0
int main() {
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7
	printf("%d\n", sizeof(arr + 0));//4
	printf("%d\n", sizeof(*arr));//1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr + 1));//4
	printf("%d\n", sizeof(&arr[0] + 1));//4

	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	//printf("%d\n", strlen(*arr));//err
	//printf("%d\n", strlen(arr[1]));//err
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//5
	return 0;
}
#endif


//�����ַ���
#if 0
int main() {
	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4
	printf("%d\n", sizeof(p + 1));//4
	printf("%d\n", sizeof(*p));//1
	printf("%d\n", sizeof(p[0]));//1
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4
	printf("%d\n", sizeof(&p[0] + 1));//4

	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	//printf("%d\n", strlen(*p));//err
	//printf("%d\n", strlen(p[0]));//err
	printf("%d\n", strlen(&p));//���ֵ-����һ��ʼд���ˣ�д��3
	printf("%d\n", strlen(&p + 1));//���ֵ-����һ��ʼд���ˣ�д����5
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}
#endif


//��ά����
#if 0
int main() {
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(*(a + 1)));//16-��д��4-�����൱�ڵڶ��е�������
	printf("%d\n", sizeof(&a[0] + 1));//4-��д��16
	printf("%d\n", sizeof(*(&a[0] + 1)));//16-��д��4
	printf("%d\n", sizeof(*a));//16-��д��4-a�൱��&��һ�У�����*a�൱�ڵ�һ�е�������
	printf("%d\n", sizeof(a[3]));//16
	return 0;
}
#endif

//����
#if 0
int main() {
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	                    //2      //5
	return 0;
}
#endif

//����
#if 0
struct Test {
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;//����ṹ���С��20���ֽ�
int main() {
	p = (struct Test*)0x1000000;
	printf("%p\n", p + 0x1);
	                    //0x10000014
	printf("%p\n", (unsigned long)p + 0x1);
	                    //0x10000001
	//                  ����+1����+1����������ָ��
	printf("%p\n", (unsigned int*)p + 0x1);
	                    //0x10000004
	return 0;
}
#endif

#if 0
int main() {
	int a[4] = { 1,2,3,4 };
	//01 00 00 00 02 00 00 00 ....
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%#x %#x", ptr1[-1], *ptr2);
	                   //4      //020000000
	return 0;
}
#endif

#if 0
int main() {
	int a[3][2] = { (0,1),(2,3),(4,5) };
	int* p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}
#endif


int main() {
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	//��������-4
	//10000000000000000000000000000100~-4��ԭ��
	//11111111111111111111111111111011
	//11111111111111111111111111111100~-4���ڴ��е���ʽ
	//���ԣ���������ַ
	//1111 1111 1111 1111 1111 1111 1111 1100
	//f    f    f    f    f    f    f    c
	return 0;
}