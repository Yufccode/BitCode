#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"
//��������д��һ������
//��дinsert��erase

ListNode* _ListInit() {
	ListNode* phead = NULL;
	phead = _CreatListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}


ListNode* _CreatListNode(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		perror("_CreatListNode::malloc_fail");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}


void _ListPushBack(ListNode* phead, LTDataType x) {
	assert(phead);
	ListNode* newNode = _CreatListNode(x);
	ListNode* tail = phead->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}

void _ListPrint(ListNode* phead) {
	assert(phead);
	//���ܴ�ӡ��
	//ע��ѭ���Ľ���
	ListNode* cur = phead->next;
	while (cur != phead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void _ListPushFront(ListNode* phead, LTDataType x) {
	assert(phead);
	ListNode* newnode = _CreatListNode(x);
	ListNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
}

void _ListPopBack(ListNode* phead) {
	assert(phead);
	assert(!_ListEmpty(phead));//���
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;
	//����Ϊ�յ����Ҫ�ж�
}

void _ListPopFront(ListNode* phead) {
	assert(phead);
	assert(!_ListEmpty(phead));//���
	//ͬ�����ǳ��򵥣�phead-first-second ��first free���Ϳ�����
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}

bool _ListEmpty(ListNode* phead) {
	assert(phead);
	return phead->next == phead;
}

void _ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = _CreatListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}//ͷ��β����Ը��ã�pos��head����β�壬��head->next����ͷ��


void _ListErase(ListNode* pos) {
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}//ͷɾβɾ���Ը���


void _ListSize(ListNode* phead) {//��������һ��O(n)�Ľӿ�
	assert(phead);
	ListNode* cur = phead;
	int size = 0;
	while (cur != phead) {
		++size;
		cur = cur->next;//�򵥵ĵ�������
	}
	return size;
}
//��һ�ַ�������ͷ�ڵ��data�����
//���������Ǵ���ģ�
//��Ϊ���������Ĳ���int


void _ListDestroy(ListNode* phead) {
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead) {
		ListNode* next = cur->next;
		_ListErase(cur);
		cur = next;
	}
	free(phead);
}