#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
//�����Ķ�����O(nlogn)
//���ϵ����㷨
void _AdjustUp(int* a, int child) {
	int parent = (child - 1) / 2;
	//���ѭ����������ֹ����Ҫע��
	while (child > 0) {
		if (a[child] < a[parent]) {
			swap(a[child], a[parent]);
			//�Ѹ��׵��±������
			child = parent;
			parent = (child - 1) / 2;
		}
		//��ʱֱ��break
		else {
			break;
		}
	}
}
void _AdjustDown(int* a, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		//ѡ��С���Ǹ����ӽڵ�
		if (child + 1 < size && a[child + 1] > a[child]) {
			++child;
		}
		if (a[child] > a[parent]) {
			//���µ���
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			//�������
			break;
		}
}
}
void _heapSort1(int* a, int n) {
	//����-��ʽ1
#if 0
	for (int i = 1; i < n; i++) {
		//�ӵڶ���λ�ÿ�ʼ���ϵ���
		_AdjustUp(a, i);
	}
#endif
	//����-��ʽ2
	//�ӵ�����һ����Ҷ�ӽڵ㿪ʼ���µ���-��������
	//���µ�����ǰ�᣺�������������Ǵ�/С��
	//�������µ���û������
	//�������ǽ��ѵ�ʱ��Ҫ��������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {//n-1�����һ��Ҷ�ӣ�n-1-1/2���ǵ�һ����Ҷ�ӽڵ�
		_AdjustDown(a, n, i);
	}
	//�������-��ʽ1�ĸ��Ӷ���O(NlogN)����Ϊ����Ǹ߶ȴ�
	//��ʽ2�ĸ��Ӷ���O(n)--��ʽ2����

	//����--�����
	//�����С��-ѡ����С��������Ҫ���½��ѣ�ÿ�ν�����O(n)
	//�����O(n^2)
	//�Ǹ�ð��һ����������ô�鷳
	//�����
	//���µ���O(logN)
	int end = n - 1;
	while (end > 0) {
		swap(a[0], a[end]);
		_AdjustDown(a, end, 0);
		--end;
	}
}
int main() {
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	_heapSort1(arr, size);//������
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}