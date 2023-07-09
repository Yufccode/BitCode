
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif


#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<functional>
using namespace std;


//���һ��ֻ���ڶ����洴������

//����1��
#if 0
class HeapOnly
{
protected:
	//��������˽��
	~HeapOnly() {}
protected:
	int _a;
public:
	//��̬�Ǿ�̬��û��ϵ
	//����pҲ���� -- delete this����
	static void Delete(HeapOnly* p) 
	{
		cout << "HeapOnly::Delete()" << endl;
		delete p; 
	}
};
int main()
{
	//HeapOnly hp1;//ջ
	//static HeapOnly hp2;//��̬��
	HeapOnly* ptr = new HeapOnly;//��
	//delete ptr; //delete�ͷŲ��� -- �����Լ�дһ���ͷ�
	HeapOnly::Delete(ptr);
	return 0;
}
#endif



//����2��
#if 0
class HeapOnly2
{
protected:
	//���캯��˽�л�
	HeapOnly2()
		:_a(0) {}
protected:
	int _a;
public:
	static HeapOnly2* CreatObj()
	{
		return new HeapOnly2;
	}
	//��ֹ����
	HeapOnly2(const HeapOnly2& hp) = delete;
	HeapOnly2& operator=(const HeapOnly2& hp) = delete;
};
int main()
{
	//HeapOnly2 hp1;//ջ
	//static HeapOnly2 hp2;//��̬��
	//HeapOnly2* ptr = new HeapOnly2;//��
	//���캯����˽���� -- newҲnew������ -- �ṩһ�����еĴ�������Ľӿ�
	HeapOnly2* ptr = HeapOnly2::CreatObj();
	//bug:
	//HeapOnly2 copy(*ptr);//��������Ļ���ջ�ϣ�����Ҫ�ѿ����������
	return 0;
}
#endif



//���һ����ֻ����ջ�ϴ�������
//���캯��˽�У�Ȼ���Լ�����дһ��CreatObj()���ַ�ʽ�϶��ǿ��Ե�
//���ﲻ�ظ���
//��Ȼ��ͬ����Ҫע�⿽�����������
//���ǲ���ɾ���������죬��Ϊ���ǵ�CreatObj()ֻ�ܴ�ֵ���أ�������ˣ��ʹ���������
//���ǿ��Խ���operator new������staticȻ��copy��������ǽ������
//�����������������һ��Сȱ�ݵ�
#if 0
class StackOnly
{
protected:
public:
};
int main()
{
	StackOnly st1;
	static StackOnly st2;
	StackOnly* ptr = new StackOnly;
	return 0;
}
#endif


//���ܱ��̳е���
//C++98 -- ���ø��๹�캯��
//C++11 -- final�ؼ���


//���ֻ�ܴ���һ��������ࣨ����ģʽ��
//��������Ʒ���
//����ģʽ -- һ��ʼ(main())֮ǰ�ʹ�����������
#if 0
class MemoryPool //����Ҫ�����һ���ڴ�� -- Ҫ���ǵ����� ����Ȼֻ�����ֶ��ѣ����ǲ������ʵ���ڴ��
{
public:
	static MemoryPool* GetInstance()
	{
		return _pinst;
	}
	void* Alloc(size_t n)
	{
		void* ptr = nullptr;
		//...
		//����ɶ�������ǲ���
		return ptr;
	}
	void Dealloc(void* ptr)
	{
		//...
	}
protected:
	char* _ptr = nullptr;
protected:
	//���캯��˽��
	MemoryPool() {}
	//����д��������ֻд��һ�֣�д��ָ��Ҳ���ԣ���д��ָ��Ҳ����
	static MemoryPool* _pinst;//����
};
MemoryPool* MemoryPool::_pinst = new MemoryPool;


#define MemoryPoolObject MemoryPool::GetInstance()
int main()
{
	//һ�����������õģ�ֱ�ӵ�����
	void* ptr1 = MemoryPool::GetInstance()->Alloc(10);
	MemoryPool::GetInstance()->Dealloc(ptr1);
	//����ģʽһ�����ͨ����� MemoryPool::GetInstance() ȥ�ҵ�����Ѿ������õĶ���ȥ��������Ķ���
	void* ptr2 = MemoryPoolObject->Alloc(29);
	MemoryPoolObject->Dealloc(ptr2);
	return 0;
}
#endif

//����ģʽ
//�ŵ�:
//�򵥡�û���̰߳�ȫ����
//ȱ��:
//1.��һ���������ж���������������Ⱥ��ʼ��˳���Ҫ���ʱ�򣬶����޷�����
//2.���������ഴ���ö��ʱ�򣬳�ʼ��������ʱ�򣬻�Ӱ�����������ٶ�


//����ģʽ
//�����һ��ʹ�õ�ʱ���ٴ���
class MemoryPool //����Ҫ�����һ���ڴ�� -- Ҫ���ǵ����� ����Ȼֻ�����ֶ��ѣ����ǲ������ʵ���ڴ��
{
public:
	static MemoryPool* GetInstance()
	{
		//�������ָ����nullptr��ʱ��˵�������ǵ�һ��ʹ�������
		if (_pinst == nullptr)
		{
			//��һ�δ���
			cout << "��һ�δ�������" << endl;
			_pinst = new MemoryPool;
		}
		return _pinst;
	}
	void* Alloc(size_t n)
	{
		void* ptr = nullptr;
		//...
		//����ɶ�������ǲ���
		return ptr;
	}
	void Dealloc(void* ptr)
	{
		//...
	}
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (_pinst)delete _pinst;
		}
	};
protected:
	char* _ptr = nullptr;
protected:
	//���캯��˽��
	MemoryPool() {}
	//����д��������ֻд��һ�֣�д��ָ��Ҳ���ԣ���д��ָ��Ҳ����
	static MemoryPool* _pinst;//����
};
MemoryPool* MemoryPool::_pinst = nullptr;
//���ն���
//��main����֮��������������������ͻ��ͷŵ�������
static MemoryPool::CGarbo gc;
#define MemoryPoolObject MemoryPool::GetInstance()
int main()
{
	//һ�����������õģ�ֱ�ӵ�����
	cout << " -------- ��һ��ʹ�� -------- " << endl;
	void* ptr1 = MemoryPool::GetInstance()->Alloc(10);
	MemoryPool::GetInstance()->Dealloc(ptr1);
	//����ģʽһ�����ͨ����� MemoryPool::GetInstance() ȥ�ҵ�����Ѿ������õĶ���ȥ��������Ķ���
	cout << " -------- �ڶ���ʹ�� -------- " << endl;
	void* ptr2 = MemoryPoolObject->Alloc(29);
	MemoryPoolObject->Dealloc(ptr2);
	return 0;
}

//����ģʽ
//�ŵ㣺
//1.���Կ���˳��
//2.��Ӱ�������ٶ�
//ȱ�㣺
//1.��Ը���
//2.�̰߳�ȫ����Ҫ�����

//���������ͷ�����
//1.һ������£�����������Ҫ�ͷ� -- һ����˵�������������ڼ䶼������
//	���������ٽ�����������֮��Ҳ����Դ�ͷ�
//2.��Щ���ⳡ����Ҫ�ͷţ����絥����������ʱ����Ҫ����һЩ�־û����������ļ������ݿ�����ȥд��
//	��˼·������һ���ڲ�������������