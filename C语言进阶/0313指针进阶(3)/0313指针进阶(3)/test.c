#define _CRT_SECURE_NO_WARNINGS 1

//����ָ�븴ϰ

#include<stdio.h>
#include<stdlib.h>
//����ָ������ �� ָ����ָ�������ָ��
#if 0
int main() {
	int(*pfarr[4])(int, int);
	int(*(*p3)[4])(int, int) = &pfarr;
	return 0;
}
#endif


//Ӧ��

#if 0
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
int main() {
	//����ָ������
	int (*pfArr[4])(int, int) = { Add,Sub,Mul,Div };
	int(*(*p3)[4])(int, int) = &pfArr;
	int i = 0;
	for (i = 0; i < 4; i++) {
		int ret = (*p3)[i](3, 4);
		printf("%d\n", ret);
	}
	return 0;
}
#endif


//�ص�����
//ͨ��һ������ָ����õĺ�����
//�����Ѻ�����ָ��(��ַ)��Ϊ�������ݸ���һ�������������ָ��
//��������������ָ��ĺ���ʱ�����ǻص�����

//����1
#if 0
int test() {
	printf("hehe\n");
}
void print_Hehe(void (*p)()) {
	if (1)
		p();
}
int main() {
	//test();
	print_Hehe(test);//��ӵ���test()
	return 0;
}
#endif
 

//����2
//���ûص���������������
#if 0
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
void menu() {
	printf("-----------\n");
	printf("   1.Add   \n");
	printf("   2.Sub   \n");
	printf("   3.Mul   \n");
	printf("   4.Div   \n");
	printf("   0.exit  \n");
	printf("-----------\n");
}
void calc(int(*pf)(int, int)) {
	int x = 0;
	int y = 0;
	printf("������������������");
	scanf("%d %d", &x, &y);
	int ret = pf(x, y);
	printf("ret=%d\n", ret);
}
int main() {
	int input = 0;
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		int ret = 0;
		switch (input) {
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("�˳�������\n");
			exit(-1);
			break;
		default:
			printf("err,������ѡ��");
			break;
		}
	} while (input);
	return 0;
}
#endif



//qsort��һ���⺯��
//�ǻ��ڿ�������ʵ�ֵ������㷨
//1.��������
#if 1
int cmp_int(const void* e1, const void* e2) {
	return +(* (int*)e1 - *(int*)e2);
}
void _OutputArr(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}
int main() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	_OutputArr(arr, sz);
	return 0;
}
#endif
//�ȽϺ���Ҫ��qsort������ʹ�����ڣ��Զ���һ���ȽϺ���


//2.����ṹ��
#include<string.h>
#if 0
struct Stu {
	char name[20];
	int age;
	double score;
};
int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2) {
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
int main() {
	struct Stu arr[3] = { {"zhangsan",20,55.5},
		{"lisi",30,88},{"wangwu",10,90.0} };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
	qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);

	//����Ͳ���ӡ�ˣ����ǿ��Ե��Կ�������Ľ�� 
	return 0;
}
#endif









//qsort������ģ��ʵ��
//ע�⣺qsort���������ߣ��ǲ���֪��ʹ���߽���Ҫ��ʲô���͵����ݵ�
void swap(char* bulf1, char* bulf2, int width) {
	//��Ϊ���ǲ�֪��Ҫ��������
	//һ�ν���һ���ֽ�
	int i = 0;
	for (i = 0; i < width; i++) {
		char tmp = *bulf1;
		*bulf1 = *bulf2;
		*bulf2 = tmp;
		bulf1++;
		bulf2++;
	}
}
void my_qsort_ByBubble(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2)) {
	intptr_t i = 0;
	intptr_t j = 0;
	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < num - 1 - i; j++) {
			//����
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//����
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);//�������ǲ�֪������Ҫ���������ֽ�
				                                                             //���Դ�width
			}
		}
	}
}
//��������
#if 0
int cmp_int(const void* e1, const void* e2) {
	return +(*(int*)e1 - *(int*)e2);
}
void _OutputArr(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}
int main() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort_ByBubble(arr, sz, sizeof(arr[0]), cmp_int);
	_OutputArr(arr, sz);
	return 0;
}
#endif


