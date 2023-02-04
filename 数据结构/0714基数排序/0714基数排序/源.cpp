#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//��������
/*
* ����˼�룺
* 1.�ַ�����
* 2.��������
*/
//����һ����ؼ�������
//����λ�����˷ַ�����
#define K 3 //���3λ��
#define RADIX 10 //ʮ������
#include<queue>

//�������
queue<int>Q[RADIX];//����Ƕ�������--��������Ҫ�����Ƚ��ȳ� -- ����ʹ�ö���
//�ҵ�key
int GetKey(int value, int k) {
	//value:278
	//k:0
	//�����һ�ηַ�������8����
	//���ԾͰ�8��ȡ�����Ϳ�
	int key = 0;
	while (k >= 0) {
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;//����һ������ʱ25256 ���ڰ��ո�λ��6���֣�key�ͷ��ص�ʱ6
}
//�ַ�����
void distribute(int* arr, int left, int right,int k) {
	//k�����ǵڼ��ηַ�
	for (int i = left; i < right; i++) {//ע������������ҿ���������<
		//����key�ַ���key��ô�ң���k����
		int key = GetKey(arr[i], k);
		Q[key].push(arr[i]);//��arr[i]push���±�Ϊ8�Ķ�������
	}
}
void collect(int* arr) {
	//����Ҫ���ֵڼ��Σ�ֻ��Ҫ�����ݻ��յ��������漴��
	//Ҫ������еĶ��У���Ϊ���ǲ�֪����һЩ������������һЩû��
	int k = 0;
	//arr��0��ʼ�����ռ�
	for (int i = 0; i < RADIX; i++) {
		while (!Q[i].empty()) {
			//˵�������������������
			//����������ʵ���ǰ��������ηŵ���������ȥ
			arr[k++] = Q[i].front();
			Q[i].pop();
		}
	}
}
void _radixSort(int* arr, int left, int right) {
	for (int i = 0; i < K; ++i) {//���ѭ������
		//�м�λ��ѭ������
		//�ַ�����
		distribute(arr, left, right, i);//i���������ڲ�����ʱ��һλ��
		//��������
		collect(arr);
	}
}
void radixSort(int* arr, int sz) {
	int left = 0;
	int right = sz;
	//[right,left)
	_radixSort(arr, left, right);
}
int main() {
	int arr[] = { 278,109,63,930,589,184,505,269,8,83 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	//
	radixSort(arr, sz);
	//
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}