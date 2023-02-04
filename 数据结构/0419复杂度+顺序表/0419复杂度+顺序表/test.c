#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//���㸴�Ӷ�
#if 0
long long Fac(size_t N) {
	if (0 == N)
		return 1;
	return Fac(N - 1) * N;
}
//O(N)


//���㸴�Ӷ�
long long fib(size_t N) {
	if (N < 3)
		return 1;
	return fib(N - 1) + fib(N - 2);
}
#endif
//�õȱ����й�ʽ
//2^0+2^1+2^2+.....2^(n-1)-1
//����������2^n����

//˵��쳲������ݹ��㷨--��ʵ����û��ʵ����ֵ��ֻ�����ۼ�ֵ��


//��ѭ��֮��--O(n)�Ϳ�����


//���ǽ׳��Ǹ�
//д10000��ʱ��Ҳ����
//��Ϊջ�����

//�ռ临�Ӷ�
void bubble_sort(int arr, int n);
//O(1)
//û�ж���ռ�ÿռ�


#include<stdlib.h>
//fibǰn��
#if 0
long long* fib(size_t n) {
	if (n == 0) {
		return NULL;
	}
	long long* _fibArray = (long long*)malloc((n + 1) * sizeof(long long));
	_fibArray[0] = 0;
	_fibArray[1] = 1;
	for (int i = 2; i <= n; i++) {
		_fibArray[i] = _fibArray[i - 1] + _fibArray[i - 2];
	}
	return _fibArray;
}
//O(n)
#endif

#if 0
long long fac(size_t n) {
	if (n == 0)
		return 1;
	return fac(n - 1) * n;
}
#endif
//�ռ临�Ӷȣ�O(n)
//������㷨�Ŀռ临�Ӷȶ���O(1)��O(n)


//
#if 0
long long fib(size_t n) {
	if (n < 3)
		return 1;
	return fib(n - 1) + fib(n - 2);
}
#endif

//ʱ�����ۼƵģ��ռ��ǲ��ۼƵ�
//�ռ临�Ӷȣ�O(n)


//�ռ�����ظ����õ�ʵ��
#if 0
void f1() {
	int a = 10;
	printf("%p\n", &a);
}
void f2() {
	int a = 10;
	printf("%p\n", &a);
}
int main() {
	f1();
	f2();
	return 0;
}
#endif
//���ֽ����һ����