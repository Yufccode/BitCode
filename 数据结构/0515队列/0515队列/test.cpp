#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//���Enqueue
//����Dequeue

void _test() {
	Queue q;
	_QueueInit(&q);
	_QueuePush(&q, 1);
	_QueuePush(&q, 2);
	_QueuePush(&q, 3);
	_QueuePush(&q, 4);
	_QueuePush(&q, 5);

	while (!(_QueueEmpty(&q))) {
		printf("%d ", _QueueFront(&q));
		_QueuePop(&q);
	}
	printf("\n");
	//���к�ջ��һ����ֻҪ�������12345������ʲôʱ�������12345

	//1.�Ŷӣ����־��Թ�ƽ��
	//2.������ȱ���
}
int main() {
	_test();
	return 0;
}