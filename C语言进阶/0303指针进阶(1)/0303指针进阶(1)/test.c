#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//�ַ�ָ��
#if 0
int main() {
	char ch = 'w';
	char* pc = &ch;
	*pc = 'a';
	printf("%c\n", *pc);
	return 0;
}
#endif


#if 0
int main() {
	/*const char* p = "abcdefg";
	printf("%s\n", p);*/

	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* p = arr;

	const char* p1 = "abcdefg";
	const char* p2 = "abcdefg";

	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	if (p1 == p2)printf("p1==p2\n");//ֻ���ӡ���
	if (arr1 == arr2)printf("arr1==arr2\n");


	return 0;
}
#endif


//ָ������
#if 0
int main() {
	//���ָ�������
	//int* arr[10] = { NULL };
	//char* ch[5] = { NULL };

	int a = 10;
	int b = 20;
	int c = 30;

	int* arr[3] = { &a,&b,&c };
	for (int i = 0; i < 3; i++) {
		printf("%p ", *(arr + i));
		printf("\n");
		printf("%d ", **(arr + i));
	}
	return 0;
}
#endif


#if 0
int main() {
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 2,3,4,5,6 };
	int arr3[5] = { 3,4,5,6,7 };
	int* parr[3] = { arr1,arr2,arr3 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			//printf("%d ", parr[i][j]);
			printf("%d ", *(*(parr + i) + j));
		}
		printf("\n");
	}
	return 0;
}
#endif



//����ָ��
#if 0
int main() {
	int* p1[10];//�Ǹ�����
	int(*p2)[10];//�Ǹ�ָ��
	//
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//�ó�����ĵ�ַ
	int(*p)[10] = arr;
	printf("%p\n", arr);
	printf("%p\n", arr + 1);
	printf("%p\n", &arr);
	printf("%p\n", &arr + 1);
	printf("%p\n", p);
	printf("%p\n", p + 1);
	return 0;
}
#endif



#if 0
int main() {
	char* arr[5] = { NULL };
	char* (*p)[5] = &arr;
	return 0;
}
#endif


#if 0
void print1(int* arr, int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	print1(arr1, sz);


	return 0;
}
#endif




//һά����һ�㲻������ָ��
#if 0
void print1(int(*p)[10], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", (*p)[i]);
		//�˴���*p����������
		//������������ʵ�ܱ�Ť
		//��Զ��
	}
}
int main() {
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	print1(&arr1, sz);


	return 0;
}
#endif 



//����ָ���ڶ�ά�����е�����
void print2(int(*arr)[5], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ",arr[i][j]);
			//printf("%d ", i[arr][j]);
		}
		printf("\n");
	}
}
int main() {
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print2(arr, 3, 5);
	return 0;
}