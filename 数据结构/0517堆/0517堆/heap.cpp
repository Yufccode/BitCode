#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void _HeapInit(Heap* php) {
	assert(php);
	php->a = nullptr;
	php->size = php->capacity = 0;
}
void _HeapDestroy(Heap* php) {
	assert(php);
	free(php->a);
	php->a = nullptr;
	php->size = php->capacity = 0;
}
//���ϵ����㷨
void _AdjustUp(HPDataType* a, int child) {
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
void _HeapPush(Heap* php, HPDataType x) {
	assert(php);
	//����
	if (php->size == php->capacity) {
		int _newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, _newCapacity * sizeof(HPDataType));
		if (tmp == nullptr) {
			perror("_HeapPush::realloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = _newCapacity;
	}
	php->a[php->size] = x;
	php->size++;
	//���ϵ����㷨
	_AdjustUp(php->a, php->size - 1);
}
//ɾ���Ѷ������ݣ���������ɾ������Ȼ��С��
//˼·�������һ��������--size
//��дһ�����µ����㷨

void _HeapPrint(Heap* php) {
	assert(php);
	for (int i = 0; i < php->size; i++) {
		cout<<php->a[i]<<" ";
	}
	cout << endl;
}
void _HeapPop(Heap* php) {
	//1.��ͷ��β����һ��
	//2.���µ���
	assert(php);
	assert(php->size > 0);
	swap(php->a[0], php->a[php->size - 1]);
	php->size--;
	//���µ����㷨
	_AdjustDown(php->a, php->size, 0);
}
HPDataType _HeapTop(Heap* php) {
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
bool _HeapEmpty(Heap* php) {
	assert(php);
	return php->size == 0;
}
int _HeapSize(Heap* php) {
	assert(php);
	return php->size;
}
//���µ����㷨
void _AdjustDown(HPDataType* a, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		//ѡ��С���Ǹ����ӽڵ�
		if (child + 1 < size && a[child + 1] < a[child]) {
			++child;
		}
		if (a[child] < a[parent]) {
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


