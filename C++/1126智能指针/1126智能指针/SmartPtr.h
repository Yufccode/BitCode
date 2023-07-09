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
	//���ǻ����ṩһ��Ĭ�ϵ�ɾ��������Ȼɾɶ���ô�
	template<class T>
	struct DefaultDeleter
	{
		void operator()(T* ptr)
		{
			delete ptr;//Ĭ����delete
		}
	};

	template<class T, class D = DefaultDeleter<T>> //����һ������ɾ����
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
			D()(_ptr);//�ö���ɾ�����ͷ�
			//delete _ptr;
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

		int use_count()
		{
			return *_pCount;
		}
		T* get() const
		{
			return _ptr;
		}
	};
	//template<class T>
	//int shared_ptr<T>::_count = 0;

	//weak_ptr����һ�������͵�����ָ�룬�Ǹ����͵�
	//���ķ�����Ϊ�˽��shared_ptr��ѭ����������
	//STL��ʵ�ֱ�����������Ӻܶ࣬���������˺ܶ�����������
	//STL��weak_ptr��ʵ���������ü��������ڴ�����ڵ����⣬���忴�������
	//STL�е������������ü�����������Ҫ����һ��
	template<class T>
	class weak_ptr
	{
	protected:
		T* _ptr;
	public:
		weak_ptr()
			:_ptr(nullptr) {}
		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr) {}
		weak_ptr(const weak_ptr<T>& wp)
			:_ptr(wp._ptr) {}
		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
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
		//��������ʵ���ṩget���ṩԭ��ָ��
		T* get() const
		{
			return _ptr;
		}
	};
}

//��Ҫʵ�ֿ�������һ�ף����ø��Ӳ���
//��ʵshared_ptr���漰���̰߳�ȫ���⣬Ҫ������


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

#if 1
void test_shared_ptr()
{
	yufc::shared_ptr<A> sp1(new A);
	yufc::shared_ptr<A> sp2(sp1);
	yufc::shared_ptr<A> sp3(sp1);
	yufc::shared_ptr<int> sp4(new int(1));
	yufc::shared_ptr<A>sp5(new A);
}
#endif
/**
 * �ܷ��þ�̬������������
 * ���������� ��Բ�ͬ�ռ䣬����ϣ���ж�������������������ʹ���˾�̬����������
 * �������ͣ����пռ�ļ���������һ����.
 */


//weak_ptr
//ѭ������
#if 0
struct Node
{
	int _val;
	yufc::shared_ptr<Node> _next;
	yufc::shared_ptr<Node> _prev;
	~Node()
	{
		cout << "Node::~Node()" << endl;
	}
};
struct Node2
{
	int _val;
	yufc::weak_ptr<Node2> _next;
	yufc::weak_ptr<Node2> _prev;
	~Node2()
	{
		cout << "Node::~Node()" << endl;
	}
};
#endif
#if 0 //stl��weak_ptr����
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



//yufc��weak_ptr����
void test_weak_ptr2()
{
	cout << " ----- before use weak_ptr to construct the Node ----- " << endl;
	yufc::shared_ptr<Node>n1(new Node);
	yufc::shared_ptr<Node>n2(new Node);
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

	cout << endl << endl;

	//shared_ptr���޷������������
	//weak_ptr���ǳ��������ָ�룬û��RAII����֧��ֱ�ӹ�����Դ
	//weak_ptr����shared_ptr��С���� -- ר�Ű�æ����shared_ptr��ʣ������
	//weak_ptr��Ҫ��shared_ptr���� -- ����ѭ����������

	//�����ǰ�Node�����_prev��_next�ĳ�weak_ptr֮��_prev��_next���Ͳ����Ӽ���
	//����������Դ�ͷŹ������Է��ʺ��޸���Դ��������ѭ����������
	cout << " ----- after use weak_ptr to construct the Node ----- " << endl;
	yufc::shared_ptr<Node2>n11(new Node2);
	yufc::shared_ptr<Node2>n21(new Node2);
	cout << n11.use_count() << endl;
	cout << n21.use_count() << endl;
	n11->_next = n21;
	n21->_prev = n11;
	cout << n11.use_count() << endl;
	cout << n21.use_count() << endl;
}
#endif




//����ɾ����
struct Node
{
	int _val;
	std::shared_ptr<Node> _next;
	std::shared_ptr<Node> _prev;
	~Node()
	{
		cout << "Node::~Node()" << endl;
	}
};
void test5()
{
	std::shared_ptr<Node> n1(new Node[5]); //���ﱨ����Ϊdelete[]û��ƥ����
	std::shared_ptr<Node> n2(new Node);
	//����ʵ��new�ĵײ�ʵ�����й�ϵ��
	//new[]����deleteû��[] -- �᲻�ᱨ��Ϊʲô�ᱨ����ʵ���ƽ̨�й�ϵ
	//new Node[5] �����漰��Node�Ĺ��������
	//��ʱ new Node[5]   -->  5��malloc��5�ι��캯��
	//�����delete --> 1����������+free
	//delete[] --> 5����������+free
	//��ʱ����������������ǵ���������ûд -- ������Ϊ���Node����Ҫ���� -- ֱ��free����
	//�������Ż� -- ����������������д  -- ��ʱ����������������

	//����Node��С��12������new Node[5]
	//��VS�£���ʵ���Ĳ���60�ֽڣ�����64�ֽ� -- 4���ֽڷ���ͷ�������������
	//��Ϊdelete[]��ʵ�涨�������� -- ����new Node[]��ʱ���͵͵��¼
	//���Ե���delete[] ��֪������Ҫ���ö��ٴ�������
	//����new []��������ָ����ʵ����ʵmalloc�����ĵ�ַ���ƫ����4���ֽ�
	//delete[]��ʱ����ʵָ��ͻ���ǰƫ���ĸ��ֽڣ����ҵ�����
	//����delete[] ��ʵ��free((char*)ptr - 4)���λ�õ�ָ��
	//���ֱ��delete ����5��Nodeֻ����һ�������ͷ�ϵ�4���ֽ�û�˹���

	//��������delete��ʱ��Ҫƥ��

	//�������������ָ���ʱ��ĳ�����ǳ�����
	std::shared_ptr<Node> n3(new Node[6]); 
	std::shared_ptr<int> n4((int*)malloc(sizeof(int) * 12));
	//����������Ҫ����ɾ����
	//һ���Ǵ�һ���º�������������
}
template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		cout << "delete[] " << ptr << endl;
		delete[] ptr;
	}
};
template<class T>
struct Free
{
	void operator()(T* ptr)
	{
		cout << "free() " << ptr << endl;
		free(ptr);
	}
};
void test6()
{
	//����Ҫ������ĵ� -- shared_ptr�Ķ���ɾ�������ڹ��캯�����洫��
	//unique_ptr�ĵ�ַɾ����������ģ��������洫��
	std::shared_ptr<Node> n1(new Node[5], DeleteArray<Node>());
	std::shared_ptr<int> n4((int*)malloc(sizeof(int) * 12), Free<int>());
	//�����Ͳ����������
	std::shared_ptr<Node> n3(new Node[5], [](Node* ptr) {delete[] ptr; });//��������������Ҳ�Ǻܺ��õ�
	std::shared_ptr<int> n2((int*)malloc(sizeof(int) * 12), [](int* ptr) {free(ptr); });
	//��������ô��
	std::shared_ptr<FILE> n5(fopen("test.txt", "w"), [](FILE* ptr) {fclose(ptr); });


	//unique_ptr���������������ˣ���ΪҪ��ģ��������洫����
	std::unique_ptr<Node, DeleteArray<Node>>up(new Node[5]);
}
void test7()
{
	//���������Լ������shared_ptr��ɾ����
	yufc::shared_ptr<Node, DeleteArray<Node>>up(new Node[5]);
}



//�������Ҫ�������һ�������Դӹ��캯����������Ŀǰʵ�ֵļܹ�����������
//��ΪSTL����ļ�������ʵ�Ƿ�װ����һ�����
//���Ǵ�����ɾ������ʱ����ʵ�����´���һ��
//�����������Ҫͨ�����캯���������ɾ������ֻ���ڹ��캯���������ˣ������ò��ˡ�
//��������дһ����ģ��������洫��

//����ɾ�����ڿ�ʼ�������
//����ƽʱʹ�û��ǵ��õ���