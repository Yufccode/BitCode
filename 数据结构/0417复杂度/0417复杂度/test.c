#define _CRT_SECURE_NO_WARNINGS 1


//���ݽṹ���ף�C����ʵ��--20�ڿ�

//C++��50�ڿ�
//C++�﷨
//�߽����ݽṹ
//STL

//��Σ������3�·�


//���ݽṹ�����ݿ������
/*
* ���ݽṹ--���ڴ��д洢��������
* ���ݿ�--�ٴ����д洢��������
*/


//ʱ�临�Ӷ�
//һ���㷨���е�ʱ���Ӳ�������й�ϵ������ͬ��һ���㷨��û�а취���׼ȷʱ���


//�����һ��Func1��++count����ܹ�ִ���˶��ٴ�
#if 0
void Func1(int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			++count;
		}
	}
	for (int k = 0; k < 2 * n; ++k) {
		++count;
	}
	int M = 10;
	while (M--) {
		++count;
	}
}
#endif

//F(N)=n^2+2*n+10
//����ʽ������㷨����׼ȷ����
//��O�Ľ�����ʾ
/*
* 1.�ó���1ȡ��ʱ���е����мӷ�����
* 2.���޸ĺ�����д��������У�ֻ������߽���
* 3.�������������ϵ����Ϊ1����ȥ���������
* //�õ��Ľ�����Ǵ�O��
*/



//����ʱ�临�Ӷ�
#if 0
void Func2(int n) {
	int count = 0;
	for (int k = 0; k < 2 * n; k++) {
		++count;
	}
	int M = 10;
	while (M--) {
		++count;
	}
}
#endif
//O(N)



//
#if 0
void func3(int n, int m) {
	int count = 0;
	for (int k = 0; k < m; k++) {
		count++;
	}
	for (int k = 0; k < n; k++) {
		count++;
	}
}
//O(M+N)


//
void func4(int n) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		count++;
	}
}
//O(1)


//
const char* strchr(const char* str, int character);
//O(n)
//ʱ�临�Ӷ�һ����������



//ʱ�临�ӶȲ�Ҫ��ѭ��
//һ��Ҫ���㷨˼��
//
void _bubble_sort(int* arr, int sz);
//O(n^2)
//F(n)=n+n-1+n-2+......+2+1


//���ֲ���
int _BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	// [begin, end]��begin��end������ұ����䣬�����=��
	while (begin <= end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}
#endif
//���O(1)
//�--�Ҳ��������һ���ҵ���
//�����۰������x��
//2^x=n
//n=log(2)n


//��Ϊ�ı���д��������д����ʱ�临�Ӷ��У�log(2)N��������
//����ֱ�Ӽ�д��logN
//��Щ�鼮�򲩿͵ȵȻ��д��lgN����ʵ�ǲ�̫�Եģ���ôҪ֪����д����log(2)N

//O(n)��O(logN)
//��ʵ�ǲ�ͬ������㷨
//��ʵ���ַ���һ����ţ�Ƶ��㷨



//����
//������ 17.04. ��ʧ������
//˼·2
int missingNumber(int* nums, int numsSize) {
	int x = 0;
	for (int i = 0; i < numsSize; i++) {
		x ^= nums[i];
	}
	for (int j = 0; j < numsSize + 1; j++) {
		x ^= j;
	}
	return x;
}
//˼·1����ϣ˼�룩����һ��ӳ��
//mallocһ��n+1������
//������Щ���֣�������Ƕ��٣���д����Ӧλ��

//˼·2�����

//˼·3������+���ֲ���

//˼·4����ʽ����--������������