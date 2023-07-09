#pragma once

#include<iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout << "A::~A()" << endl;
	}
	int _a = 0;
	int _b = 0;
};

namespace yufc
{
	template<class T>
	class auto_ptr
	{
	private:
		T* _ptr;
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr) {}
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}
		//ap1 = ap2;
		auto_ptr<T>& operator =(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					cout << "Delete:" << _ptr << endl;
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	};

	//unique_ptr
	template<class T>
	class unique_ptr
	{
	private:
		T* _ptr;
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr) {}
		//�¿���
		unique_ptr(unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	};

	//shared_ptr
	template<class T>
	class shared_ptr
	{
	protected:
		T* _ptr;
		//static int _count;
		int* _pCount;
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(new int(1)) {}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			(*_pCount)++;
		}
		void release()
		{
			cout << "Delete:" << _ptr << endl;
			delete _ptr;
			delete _pCount;
		}
		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (_ptr == sp._ptr)
			{
				return *this; 
			}
			if (--(*_pCount) == 0)
			{
				release();
			}

			//��������Դ��++����
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			(*_pCount)++;
			return *this;
		}
		~shared_ptr()
		{
			if (--(*_pCount) == 0)
			{
				release();
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	};
	//template<class T>
	//int shared_ptr<T>::_count = 0;
}

void test_auto_ptr()
{
	std::auto_ptr<A>ap1(new A);
	ap1->_a++;
	std::auto_ptr<A>ap2(ap1);
	//ap1->_a++;//err
	//����ֿ����������������
	//�ܶ๫˾��ȷ�涨����ʹ����
	std::auto_ptr<A>ap3(new A);
	//ע�� -- ���ﲻ�ǽ��� -- �ǰ�ap3����Դת�Ƹ�ap2��Ȼ���ap2���ͷŵ���ap3����
	ap2 = ap3;
	//ap3->_a++;
}

void test_unique_ptr()
{
	yufc::unique_ptr<A> up1(new A);
	//��׼������
	//std::unique_ptr<A> up2(up1);
	up1->_a++;
	yufc::unique_ptr<A> up2;
	//up2 = up1;//err
}

void test_shared_ptr()
{
	yufc::shared_ptr<A> sp1(new A);
	yufc::shared_ptr<A> sp2(sp1);
	yufc::shared_ptr<A> sp3(sp1);
	yufc::shared_ptr<int> sp4(new int(1));
	yufc::shared_ptr<A>sp5(new A);
}
/**
 * �ܷ��þ�̬������������
 * ���������� ��Բ�ͬ�ռ䣬����ϣ���ж�������������������ʹ���˾�̬����������
 * �������ͣ����пռ�ļ���������һ����.
 */


//weak_ptr
//ѭ������
struct Node
{
	int _val;
	shared_ptr<Node> _next;
	shared_ptr<Node> _prev;
	~Node()
	{
		cout << "Node::~Node()" << endl;
	}
};
struct Node2
{
	int _val;
	weak_ptr<Node2> _next;
	weak_ptr<Node2> _prev;
	~Node2()
	{
		cout << "Node::~Node()" << endl;
	}
};

void test_weak_ptr()
{
	cout << "before use weak_ptr to construct the Node" << endl;
	std::shared_ptr<Node>n1(new Node);
	std::shared_ptr<Node>n2(new Node);
	//tips:shared_ptr�Ĺ����Ǽ���explicit�� -- ��������ʽ����ת�������Բ�������д
	//std::shared_ptr<Node>n2 = new Node; //err

	//���ǿ�������� -- ��ʱ������ȷ�ͷ��� -- Ϊʲô��
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
	n1->_next = n2;
	n2->_prev = n1;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
	//�������ѭ�����õ�����

	//shared_ptr���޷������������
	//weak_ptr���ǳ��������ָ�룬û��RAII����֧��ֱ�ӹ�����Դ
	//weak_ptr����shared_ptr��С���� -- ר�Ű�æ����shared_ptr��ʣ������
	//weak_ptr��Ҫ��shared_ptr���� -- ����ѭ����������

	//�����ǰ�Node�����_prev��_next�ĳ�weak_ptr֮��_prev��_next���Ͳ����Ӽ���
	//����������Դ�ͷŹ������Է��ʺ��޸���Դ��������ѭ����������
	cout << "after use weak_ptr to construct the Node" << endl;
	std::shared_ptr<Node2>n11(new Node2);
	std::shared_ptr<Node2>n21(new Node2);
	cout << n11.use_count() << endl;
	cout << n21.use_count() << endl;
	n11->_next = n21;
	n21->_prev = n11;
	cout << n11.use_count() << endl;
	cout << n21.use_count() << endl;
}