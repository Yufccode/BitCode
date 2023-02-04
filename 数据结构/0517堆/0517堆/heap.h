#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef int HPDataType;
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}Heap;

//��ӡ��
void _HeapPrint(Heap* php);
//��ʼ����
void _HeapInit(Heap* php);
//���ٶ�
void _HeapDestroy(Heap* php);
//����һ��Ԫ
void _HeapPush(Heap* php, HPDataType x);
//ɾ��һ��Ԫ��
void _HeapPop(Heap* php);
//ȡ�Ѷ�Ԫ��
HPDataType _HeapTop(Heap* php);
//���п�
bool _HeapEmpty(Heap* php);
//�Ѵ�С
int _HeapSize(Heap* php);
//���ϵ����㷨
void _AdjustUp(HPDataType* a, int child);
//���µ����㷨
void _AdjustDown(HPDataType* a, int size, int parent);