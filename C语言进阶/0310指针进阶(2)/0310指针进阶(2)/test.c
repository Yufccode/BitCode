#define _CRT_SECURE_NO_WARNINGS 1

//ָ�����2

#include<stdio.h>

int(*parr3[10])[5];
//parr3��һ�����飬������10��Ԫ�أ�ÿ��Ԫ�ص�������int(*)[5],��һЩ����ĵ�ַ

//һά���鴫��
#if 0
void test(int arr[10]) {};//ok,10û������
void test(int arr[]) {};//ok
void test(int* arr) {};
void test2(int* arr[20]) {};
void test2(int** arr) {};
int main() {
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test2(arr2);
	return 0;
}
#endif 



//��ά���鴫��
#if 0
void test(int* arr);//��ok
void test(int* arr[5]);//��ok
void test(int(*arr)[5]);//ok
void test(int** arr);//ok
int main() {
	int arr[3][5] = { 0 };
	test(arr);
	return 0;
}
#endif


#if 0
//����ָ��
int Add(int x, int y) {
	return x + y;
}
int main() {
	printf("%p\n", &Add);
	printf("%p\n", Add);
	//Add��&Add����ȫһ����
	//����������в��
	//Add��&Add����ȫһ����
	int(*pf)(int, int) = Add;
	//�����pf���Ǻ���ָ�����

	//����ָ���ʹ��
	int ret1 = (*pf)(2, 3);
	int ret2 = pf(2, 3);
	//���Ƿ���*�Ͳ���*������
	//*ֻ�ǰ������
	//���Ǽ���*��������⣬�������﷨
	//�������Ҫ��*����һ��Ҫ������
	printf("%d\n", ret2);
	return 0;
}
#endif

//������Ȥ�Ĵ���
#if 0
int main() {
	(*(void(*)())0)();
	//void(*)()��һ������ָ������
	//������ͷŵ�����������
	//���ͷŵ������������ǿ������ת��
	//(void(*)())0,��0����ǿ������ת����һ������ָ��
	//Ȼ���ٵ����������
	//����
	//1.��0ǿת��һ������ָ�룬���һλ��0��ַ����һ������������void���޲ε�һ������
	//2.����0��ַ�����������



	void(*signal(int, void(*)(int)))(int);
	//signal(int, void(*)(int))˵��
	//signal�Ǹ���������һ��������int���ڶ��������Ǻ���ָ������
	//Ȼ�����ȥ������ʣ��
	//void(*)(int)��Ҳ���Ǻ����ķ�������
	//���ϣ�
	//signal��һ����������һ��������int���ڶ��������Ǻ���ָ������
	//signal�ķ���ֵ��һ������ָ��
	//������仰��һ����������

	//���Ǵ�ʱ���֣��ڶ��������ͷ���ֵ������һ����
	typedef void(*pf_t)(int);//��void(*)(int)���������У�pf_t
	//����
	pf_t signal(int, pf_t);
}
#endif


#if 0
//����ָ������
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
#if 0
	//����ָ��
	int(*pf1)(int, int) = Add;
	int(*pf2)(int, int) = Sub;
	int(*pf3)(int, int) = Mul;
	int(*pf4)(int, int) = Div;
#endif
	//����ָ������
	int(*pf[4])(int, int) = { Add, Sub, Mul, Div };

	int i = 0;
	for (i = 0; i < 4; i++) {
		int ret = pf[i](8, 2);
		printf("%d\n", ret);
	}
	return 0;
}
#endif



//ʵ��һ��������
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
	printf("   9.exit  \n");
	printf("-----------\n");
}
int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		int ret = 0;
		switch (input) {
		case 1:
			printf("������������������");//�������������
			scanf("%d %d", &x, &y);
			ret = Add(x, y);
			printf("�����:%d\n", ret);
			break;
		case 2:
			printf("������������������");
			scanf("%d %d", &x, &y);
			ret = Sub(x, y);
			printf("�����:%d\n", ret);
			break;
		case 3:
			printf("������������������");
			scanf("%d %d", &x, &y);
			ret = Mul(x, y);
			printf("�����:%d\n", ret);
			break;
		case 4:
			printf("������������������");
			scanf("%d %d", &x, &y);
			ret = Div(x, y);
			printf("�����:%d\n", ret);
			break;
		case 0:
			printf("�˳�������\n");
			break;
		default:
			printf("err,������ѡ��");
			break;
		}
	} while (input);
	return 0;
}
#endif



//�Ľ�
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
	printf("   9.exit  \n");
	printf("-----------\n");
}
int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*pfArr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		if (input == 0) {
			printf("�˳�������\n");
		}
		else if (input >= 1 && input <= 4) {
			printf("������������������");//�������������
			scanf("%d %d", &x, &y);
			ret = pfArr[input](x, y);
			printf("���Ϊ��%d\n", ret);
		}
		else {
			printf("err\n");
		}
		
		
	} while (input);
	return 0;
}
//����ָ����ʵ�������������
//�������ָ���ʹ�ý�ת�Ʊ�