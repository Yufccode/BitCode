#pragma once

#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

void PrintArray(int* a, int n);
// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
// ��������ݹ�ʵ��
void QuickSort(int* a, int n);
//�鲢����
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
//��¼���ŵݹ����(����)
extern int callCount;
//��������
void CountSort(int* a, int n);
//��������ľ�����
/*
* 1.����Ǹ��������ַ����Ͳ�������
* 2.������ݷ�Χ�ܴ󣬿ռ临�ӶȾͻ�ܸߡ���Բ��ʺ�
*/