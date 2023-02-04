#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//��������
void _insertsort(int* arr, int sz) {
	//[0,end]�Ѿ������ˣ����ڽ�end+1��λ����ǰ����
	for (int i = 0; i < sz - 1; i++) {//ע�������sz��-1��
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0) {
			if (tmp < arr[end]) {
				arr[end + 1] = arr[end];
				end--;
			}
			else break;
		}
		arr[end+1] = tmp;
	}
}
//ϣ������
void _shellsort(int* arr, int sz) {
	for (int gap = sz; gap >= 1; gap /= 2) {
		for (int i = 0; i < sz - gap; i++) {
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0) {
				if (tmp < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else break;
			}
			arr[end + gap] = tmp;
		}
	}
}
//������
void adjustDown(int* arr, int sz, int parent) {
	int son = parent * 2 + 1;
	while (son<sz) {
		if (son + 1 < sz && arr[son] < arr[son + 1]) {
			son++;
		}
		else if (arr[son] > arr[parent]) {
			swap(arr[son], arr[parent]);
			//���������±궼Ҫ����
			parent = son;
			son = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void _heapsort(int* arr, int sz) {
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--) {
		adjustDown(arr, sz, i);
	}
	int end = sz - 1;
	while (end > 0) {
		swap(arr[end], arr[0]);
		adjustDown(arr, end, 0);//���������������ˣ����һ����ȥ�����Բ���sz��end
		--end;
	}
}
#include<climits>
void select_sort(int* arr, int sz) {
	int begin = 0;
	int end = sz - 1;
	while (begin < end) {
		int max = INT_MIN;
		int min = INT_MAX;
		int imax = 0;
		int imin = 0;
		for (int i = begin; i <= end; i++) {
			if (arr[i] < min) {
				imin = i;
				min = arr[i];
			}
			if (arr[i] > max) {
				imax = i;
				max = arr[i];
			}
		}
		swap(arr[begin], arr[imin]);
		//���Իᷢ����������ģ����begin��maxi�ص��˵Ļ�
		//��һ���������ᵼ��maxi�����ֱ����ߣ���������
		//����
		if (begin == imax)imax = imin;
		swap(arr[end], arr[imax]);
		begin++;
		end--;
	}
}
void _qs(int* arr, int begin, int end) {
	//�ݹ�һ��Ҫ����ֹ����
	if (begin >= end) {
		return;
	}
	int left = begin;
	int right = end;
	int ikey = left;
	while (left < right) {
		//���key���ұ�����
		while (left < right && arr[right] >= arr[ikey])right--;
		while (left < right && arr[left] <= arr[ikey])left++;
		swap(arr[right], arr[left]);
	}
	swap(arr[ikey], arr[left]);
	ikey = left;
	_qs(arr, begin, ikey - 1);
	_qs(arr, ikey + 1, end);
}
void quick_sort(int* arr, int sz) {
	int begin = 0;
	int end = sz - 1;
	_qs(arr, begin, end);
}
int main() {
	int arr[] = { 2,3,1,4,5,2,6,8,9,10 };
	select_sort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}