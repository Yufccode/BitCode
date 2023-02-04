#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void _TestHeapSort() {
	//�����ӡ-�Ƚϼ򵥵�-ֱ�Ӵ�ӡ������-С��
	Heap hp;
	_HeapInit(&hp);
	vector<int>a = { 27,15,19,18,28,34,65,49,25,37 };
	//����
	for (int i = 0; i < a.size(); i++) {
		_HeapPush(&hp, a[i]);
	}
	
	while (!_HeapEmpty(&hp)) {
		cout << _HeapTop(&hp)<<" ";
		_HeapPop(&hp);
	}
	cout << endl;

	//���Ҫ�Ĵ�ѣ�ֻ��Ҫ��ģ����ϵ��������µ�������
	// 
	//���Ҫ�������ֵ������
}



void _heapSort1(int* a, int size) {
	Heap hp;
	_HeapInit(&hp);
	for (int i = 0; i < size; i++) {
		_HeapPush(&hp, a[i]);
	}
	int i = 0;
	while (!_HeapEmpty(&hp)) {
		a[i++] = _HeapTop(&hp);
		_HeapPop(&hp);
	}
}
//����һ����

#if 0
int main() {
#if 0
	Heap hp;
	_HeapInit(&hp);
	vector<int>a = { 27,15,19,18,28,34,65,49,25,37 };
	//����
	for (int i = 0; i < a.size(); i++) {
		_HeapPush(&hp, a[i]);
	}
	_HeapPrint(&hp);
	_HeapPush(&hp,10);
	_HeapPrint(&hp);
	
	_HeapPop(&hp);
	_HeapPrint(&hp);
	_HeapPop(&hp);
	_HeapPrint(&hp);
	_HeapPop(&hp);
	_HeapPrint(&hp);
#endif
	//_TestHeapSort();//�����ӡ
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	_heapSort1(arr, size);//������
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif

//����д�Ķ����������
//1.Ҫ��дһ����-̫�鷳��
//2.��O(n)�Ŀռ临�Ӷ�
//�����Ķ���������ô�鷳��������һ������


//topk����
//1.���� O(nlogn)
//2.��N������ѣ�top/pop k�� O(N+logN*k)
//�������N�ǳ��󣬱���N��100�ڣ�K�Ƚ�С��K��100�������⣿

//K������С��
//1.ǰk��������С��
//2.ʣ�µ�N-K�����κͶѶ����ݱȽϣ�����ȶѶ������ݴ󣬾��滻�Ѷ������ݽ���
//����֮�󣬶������K��������������ǰK��
//O(k+(n-k)logk))

#include<time.h>
void PrintTopK(int* a, int n, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ���
	int* kMinHeap = (int*)malloc(sizeof(sizeof(int) * k));
	assert(kMinHeap);
	for (int i = 0; i < k; i++) {
		kMinHeap[i] = a[i];
	}
	//����
	for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
		_AdjustDown(kMinHeap, k, i);
	}
	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
	for (int j = k; j < n; ++j) {
		if (a[j] > kMinHeap[0]) {
			kMinHeap[0] = a[j];
			//Ū����֮��Ҫ����Ū��
			_AdjustDown(kMinHeap, k, 0);
		}
	}
	for (int i = 0; i < k; ++i) {
		cout << kMinHeap[i] << " ";
	}
	cout << endl;
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		//���������С��1000000����
		a[i] = rand() % 1000000;
	}
	//���¿��԰�������Щ��ѡ����
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
int main() {
	TestTopk();
	return 0;
}