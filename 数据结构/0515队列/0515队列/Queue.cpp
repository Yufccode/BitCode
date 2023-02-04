#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void _QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = nullptr;
}
void _QueueDestroy(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = nullptr;
}
void _QueuePush(Queue* pq, QDataType x) {
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == nullptr) {
		perror("_QueuePush::malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = nullptr;
	if (pq->tail == nullptr) {
		//����ǿն��е����
		pq->head = pq->tail = newnode;
	}
	else {
		//���зǿ�
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void _QueuePop(Queue* pq) {
	//ͷɾ-������һ�� free��ͷ���ܼ�
	//��ȻҪ�п�
	assert(pq);
	assert(!_QueueEmpty(pq));
	//���ֻ��һ���ڵ�Ҫ��������һ��
	if (pq->head->next == nullptr) {
		//���ֻ��һ���ڵ㣬ɾ��֮������ָ�붼Ҫ�ÿ�
		free(pq->head);
		pq->head = pq->tail = nullptr;
	}
	else {
		//��¼��ͷ
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDataType _QueueFront(Queue* pq) {
	//ȡ��ͷ����
	assert(pq);
	assert(!_QueueEmpty(pq));
	return pq->head->data;
}
QDataType _QueueBack(Queue* pq) {
	assert(pq);
	assert(!_QueueEmpty(pq));
	return pq->tail->data;
}
bool _QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == nullptr;
}
int _QueueSize(Queue* pq) {
	//��������Ч�ʣ������ڽṹ������Ūһ��size������O(1)

	//����
	//O(n)
	assert(pq);
	QNode* cur = pq->head;
	size_t cnt = 0;
	while (cur) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}