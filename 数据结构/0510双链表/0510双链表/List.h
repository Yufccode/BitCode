#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;

//void _ListInit(ListNode** pphead);
ListNode* _ListInit();
void _ListPrint(ListNode* phead);
ListNode* _CreatListNode(LTDataType x);
void _ListPushBack(ListNode* phead, LTDataType x);
void _ListPushFront(ListNode* phead, LTDataType x);
void _ListPopBack(ListNode* phead);
void _ListPopFront(ListNode* phead);
bool _ListEmpty(ListNode* phead);
void _ListInsert(ListNode* pos, LTDataType x);//��pos֮ǰɾ��
void _ListErase(ListNode* pos);//ɾ��posλ�ýڵ�
void _ListSize(ListNode* phead);
void _ListDestroy(ListNode* phead);