#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//��̬˳���
typedef int SLDdataType;
typedef struct SeqList {
	SLDdataType* a;
	size_t size;//���ݸ���
	size_t capacity;//����
}SL;


void _SeqListInit(SL* ps);//��ʼ��
void _SeqListPrint(SL* ps);
void _SeqList_checkCapacity(SL* ps);
void _SeqListPushBack(SL* ps, SLDdataType x);//β��
void _SeqListPopBack(SL* ps);//βɾ
void _SeqListPushFront(SL* ps, SLDdataType x);//ͷ��
void _SeqListPopFront(SL* ps);//ͷɾ
void _SeqListDestroy(SL* ps);
void _SeqListInsert(SL* ps, int pos, SLDdataType x);
void _SeqListErase(SL* ps, int pos);
int _SeqListFind(SL* ps, SLDdataType x);
void _SeqListModify(SL* ps, int pos, SLDdataType x);