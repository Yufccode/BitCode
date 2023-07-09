#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cassert>
using namespace std;

//ģ�� -- ���ͱ��
#if false
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
int main() {

	return 0;
}
#endif


//template<typename1,typename2,....> -- ģ�����
//template<typename T>//<>����Ҳ����дclass T -- Ŀǰ������û������ģ��Ժ��������
#if 0
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}
int main() {
	int a = 10, b = 20;
	double c = 10, d = 20;
	char e = 'a', f = 'b';
	//ע�⣬�����仰���õĲ���ͬһ������
	Swap(e, f);
	Swap(c, d);
	Swap(a, b);
	return 0;
}
#endif
//���仰����ͬһ��������
//��Ϊģ��� ���ݲ���ʵ���� -- �����ݳ�3����������


//ע�⣺ģ�岻����ʽ����ת����
//
#if 0
template<class T>
T Add(const T& left, const T& right) {
	return left + right;
}
int main() {
	//��ʽʵ����
	cout << Add(1, 2) << endl;
	//cout << Add(1.1, 2) << endl;//err -- ��������д����ģ�����Ҳ�ǿ��Ե�
	cout << Add((int)1.1, 2) << endl;//��ʽת���У������Ǿ���ʾת
	cout << Add(1.1, (double)2) << endl;

	//��ʽʵ����
	cout << endl << endl;
	cout << Add<int>(1.1, 2) << endl;
	cout << Add<double>(1.1, 2) << endl;
	return 0;
}
//��Щ�ط���һ��Ҫ��ʽʵ�����ģ�����
//��ʱ����û�а취����ʽ���ݵ�
#endif

//һ��int Add()��һ��ģ����ܷ�ͬʱ������
//ͬʱ���ڻ�ȥ������һ���أ�
//��ȥ�����ֳɵ� -- ���û�� -- ��ȥʵ����һ��
//������ȫ����������ȥд



//��ģ��
template<class T>
class Stack {
public:
	//����
	Stack(size_t capacity = 4)
		:_a(nullptr),
		_capacity(0),
		_top(0)
	{
		//Ĭ�ϸ���4
		if (capacity > 0) {
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}
	//����
	~Stack() {
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}
	void Push(const T& x) {
		if (_top == _capacity) {
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			//��C++�в����򲻵��Ѳ�Ҫȥ��malloc ��Ϊ������ȥ�����Զ������Ͷ���Ĺ��캯��
			//�����ᵼ���Զ�������û�б���ʼ��

			//�����C++�����ݷ�ʽ�����realloc�����鷳һ�㣬�������ǻ����Ƽ���new
			T* tmp = new T[newCapacity];
			if (_a) {
				memcpy(tmp, _a, sizeof(T) * _top);
				delete[] _a;
			}
			_a = tmp;
			_capacity = newCapacity;
		}
		//1.���¿ռ�
		//2.�Լ��ֶ�������ȥ
		//3.delete�ɿռ�
		_top++;
		_a[_top - 1] = x;
	}
	void Pop() {
		assert(_top > 0);
		--_top;
	}
	bool Empty() {
		return _top == 0;
	}
	const T& Top() {//������ô����ðɣ���Ϊ�����������ڣ���Ϊ�����ڶ���
		//��Ȼ�����ֱ�Ӵ����÷��� -- ����Ϳ����޸��ˣ�st1.Top()++
		//�������������·���
		//�Ӹ�const����
		assert(_top > 0);
		return _a[_top - 1];
	}
private:
	int* _a;
	int _top;
	int _capacity;
	//���ó�ʼ���б�Ҳ��������ȱʡ -- ������һ����
	//д������ȱʡ���ʾ��ǳ�ʼ���б�
	//int*_a=nullptr;
};
int main() {
	//�淶��Ӧ��Ҫȥtry catch ����ƽʱ��ϰ���Բ��õ�
	try
	{
		Stack<int>st1;
#if 0
		Stack<double>st2;

		//ֱ��Ҫ��100�����ݣ������ȱʡֵ���ô���
		Stack<int>st3(100);
#endif
		st1.Push(1);
		st1.Push(2);
		st1.Push(3);
		st1.Push(4);
		st1.Push(5);
		while (!st1.Empty()) {
			cout << st1.Top() << " ";
			st1.Pop();
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

//ģ�岻֧�ַ�����롣
//ģ�岻֧��������.h �������.cpp
//�����ͬһ���ļ��У��ǿ��������Ͷ�������
//ģ���ǿ���ȱʡ�ģ�����һ�㲻ʹ��
//��ϸ��������ģ������ٽ�

//template<typename TT = int>
//��������ҲҪ��<>
//Stack<>st1
//������������ȱʡ����