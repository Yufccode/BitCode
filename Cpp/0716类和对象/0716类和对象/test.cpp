#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//C++���Ǵ��������ģ��ǻ�����������
//Java���Ǵ��������

//��
//C����-��ע���̵�ʵ�֣�������Щ�����ӿ�
#if 0
struct Stack {
	int* a;
	int top;
	int capacity;
};
void StackInit(struct Stack* ps);
void StackPush(struct Stack* ps, int x);
void StackPop(struct Stack* ps);
#endif
//C++ struct����C���﷨
//ͬʱ��struct�������� -- ��Ա����+��Ա����
#if 0
struct Stack {
	void Init() {
		//...
	}
	void Push(int x) {}
	void Pop() {}

	int* a;
	int top;
	int capacity;
};
int main() {
	struct Stack st1;
	Stack st2;
	//�����ֶ��嶼�ǿ��Ե�
	st1.Init();
	st1.Push(1);
	st1.Push(2);
	st1.Pop();
	return 0;
}
//C++�ж������ϲ����class
class ClassName {

};
#endif
//��ķ����޶���
//��װ
#if 0
class Stack {
public:
	void Init() {
		//...
	}
	void Push(int x) {}
	void Pop() {}
private:
	int* a;
	int top;
	int capacity;
};
int main() {
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	//st.a = nullptr;
	return 0;
}
#endif
//�����޶���ֻ�޶�������ķ��ʣ�������ķ��ʲ�����
//��ѧ�̳�֮ǰ��protected��private�ļ�ֵ��һ����


//������ֶ��巽ʽ
/*
* 1.�����Ͷ���ȫ���ŵ��൱�У���Ҫע�⣺��Ա������������ж��壬���������ܻὫ�䵱��������������
* 2.�����ŵ�.h����Ķ���ŵ�.cpp�ļ���
*/

//�����еĶ���
#include"f.h"
int main() {
	Queue q;
	q.Init();
	q.Push(1);
	q.Push(2);
	q.Pop();
	return 0;
}
//��Ķ��壺
//1.С���������Ϊ������ֱ���������涨�弴��
//2.����Ǵ����������Ͷ�����뼴��


//��������������ԣ���װ���̳С���̬
//��װ������ʵ��һ�ֹ���
//C -- û�취��װ - �淶ʹ�ú����������� - Ҳ����ֱ�ӷ������� - ���淶
//C++ -- ��װ - ����淶ʹ�ú����������� - ������ֱ�ӷ������� - �淶