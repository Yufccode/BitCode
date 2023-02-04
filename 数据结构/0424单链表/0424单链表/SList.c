#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//����ָ����Զ��ԣ�һ�����ܶ���
//һ��ָ����ȫ�ǿ���Ϊ�յ�
//���Ƕ���ָ��Ϊ��ֻ���Ǵ���

SListNode* _CreatListNode(SLTDataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void _SListPrint(SListNode* phead) {
	SListNode* cur = phead;
	while (cur) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void _SListPushBack(SListNode** pphead, SLTDataType x) {
	assert(pphead);
	SListNode* newNode = _CreatListNode(x);
	//����������
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		//��β
		SListNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void _SListPushFront(SListNode** pphead, SLTDataType x) {
	assert(pphead);
	SListNode* newNode = _CreatListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

void _SListPopBack(SListNode** pphead) {
	assert(pphead);
	assert(*pphead);//û�нڵ㲻��ɾ
	if ((*pphead)->next == NULL) {//ֻ��һ���ڵ�
		free(*pphead);
		*pphead = NULL;
	}
	else {//����ڵ�
		SListNode* tailPrev = NULL;//Ҫ����ǰһ���ڵ�
		SListNode* tail = *pphead;
		while (tail->next != NULL) {
			tailPrev = tail;
			tail = tail->next;
		}
		free(tail);
		tailPrev->next = NULL;
	}
}

void _SListPopFront(SListNode** pphead) {
	assert(pphead);
	assert(*pphead);
	//Ҫ�ȱ�����һ���ڵ㣬����free�˾��Ҳ�����
	SListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}


//���ҵĸ������þ����޸�
SListNode* _SListFind(SListNode* phead, SLTDataType x) {
	//���Ҳ���Ҫ����ָ��
	SListNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}



void _SListInsert(SListNode** pphead, SListNode* pos, SLTDataType x) {
	assert(pos);
	assert(pphead);
	//ͷ��
	if (pos == *pphead) {
		_SListPushFront(pphead, x);
	}
	else {
		SListNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		SListNode* newNode = _CreatListNode(x);
		prev->next = newNode;
		newNode->next = pos;
	}
}
void _SListErase(SListNode** pphead, SListNode* pos) {
	//ɾ��ĳ��λ�õ����ݻ���Ҫ֪��ǰһ���ڵ�
	assert(pphead);
	assert(pos);
	if (*pphead == pos) {
		_SListPopFront(pphead);
	}
	else {
		//�ҵ�ǰһ��
		SListNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}