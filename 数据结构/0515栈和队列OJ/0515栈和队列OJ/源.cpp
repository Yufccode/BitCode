#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

//����ʵ��ջ
class MyStack {
public:
    queue<int>que;
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) {
            que.push(que.front());
            que.pop();
        }
        int ret = que.front();
        que.pop();
        return ret;
    }

    int top() {
        return que.back();//ջͷ���Ƕ�β��
    }

    bool empty() {
        return que.empty();
    }
};





//ѭ������
//�����ʵ�ַ�ʽ
//head==NULL����Ҳ�ǿ�
//������һ��size��¼���ԣ���һ���ڵ㲻�洢����Ҳ���ѽ���������
//�����ݣ�tail=tail->next;
//�����ݣ�head=head->next;

//ʹ������ķ�ʽʵ��
//head tail���±�
//�����ݣ�tail++;
//�����ݣ�head++;
//�±곬����ķ�Χ��ʱ���ƻ�����ȡģ��һ�ַ�ʽ
//���tail+1==head������
//���ַ�ʽ�Ļ�ȡβ�Ƚϼ򵥣�����ע��߽�����
#if 1
typedef struct {
    int* a;//����
    int k;
    int head;
    int tail;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    //ע��tail���������head����ǰ���������
    int next = obj->tail + 1;
    if (next == obj->k + 1) {
        next = 0;
    }
    return next == obj->head;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->head == obj->tail;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));//�ȸ�һ���ڵ����
    obj->a = (int*)malloc(sizeof(int) * (k + 1));//�࿪һ���ռ�
    obj->head = obj->tail = 0;//����head tail���±�
    obj->k = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))return false;
    obj->a[obj->tail] = value;//��tail��λ�÷�val
    obj->tail++;
    //����Ҫ���Ʊ߽�
    if (obj->tail == obj->k + 1) {
        obj->tail = 0;//���±��ƻ���
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))return false;
    ++obj->head;
    if (obj->head == obj->k + 1) {
        obj->head = 0;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))return -1;
    return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))return -1;
    int prev = obj->tail - 1;
    if (obj->tail == 0) {
        prev = obj->k;
    }
    return obj->a[prev];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    //��free����
    //��freeѭ������
    free(obj->a);
    free(obj);
}
#endif

/*
* ����һѭ�����У����ͷָ��βfront����βָ��βrear��ѭ�����г���βN��ʵ�����洢N-1�����ݡ�
* �������Ч����Ϊ��
* (rear-front+N)%N
*/