
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<map>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<memory>
using namespace std;
#elif
#endif

//����ָ��
//RAII��һ��˼�� -- ���ö����������������Ƴ�����Դ


#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	~SmartPtr() { delete _ptr; }
private:
	T* _ptr;
public:
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
};

//1.����RAII������Դ
//2.ӵ����ָ�����Ϊ����



struct A
{
public:
	int _a1 = 0;
	int _a2 = 0;
public:
	~A()
	{
		cout << "A::~A()" << endl;
	}
};



//auto_ptr -- C++98
int main()
{
	auto_ptr<A> ap1(new A);
	ap1->_a1++;


	return 0;
}
#endif

//1.����RAII������Դ
//2.ӵ����ָ�����Ϊ����
//3.��������

//list<int>lt;
//auto it = lt.begin();
//��ʱ����������ǳ����
//����Ҫָ��ͬһ��ռ�
//����Ϊʲô������ǳ����û���⣿��Ϊ��������������Դ���ͷţ�
//���Կ������ⲻ��ָ�������������
//�����������ǳ����
//��������Ҫ���ǳ�������ͷ����ε�����
struct A
{
public:
	int _a1 = 0;
	int _a2 = 0;
public:
	~A()
	{
		cout << "A::~A()" << endl;
	}
};
int main()
{
	//auto_ptr�Ĵ����� -- ��Դת��
	auto_ptr<A> ap1(new A);
	auto_ptr<A>ap2(ap1);
	//���ǵ��Կ��Է��� -- ����֮��-- ��Դֱ��ת��ap2�ˣ�ap1������
	//ap1->_a1++;//err
	//auto_ptr�����������������˳������� -- �ܶ๫˾��ȷҪ����ʹ����
	return 0;
}

//boost
//scoped_ptr
//shared_ptr
//weak_ptr

//C++11
//unique_ptr
//shared_ptr
//weak_ptr