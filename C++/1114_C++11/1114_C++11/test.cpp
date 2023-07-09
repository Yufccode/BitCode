#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<functional>
#include<iostream>
#include<assert.h>
using namespace std;
#elif
#endif

//��ֵ����

//ʲô����ֵ��
#if 0
int main()
{
	int a = 10;
	const int b = 20;
	int* p = &a;
	//��ֵ���ص��ǣ�����ȡ��ַ
	//��ֵ����ȡ��ַ
	double x = 1.1;
	double y = 2.2;
	//���¼������ǳ�������ֵ
	10;
	x + y;
	fmin(x, y);
	//��ֵ���ص㣺����ȥ��ַ
	//����ֵȡ����
	int&& rr1 = 10;
	double&& rr2 = x + y;
	double&& rr3 = fmin(x, y);
	return 0;
}
#endif



//�����ֵ(T x) -- ��ʲô������ -- ����
//����Ϊ�˼��ٿ��� -- ϲ�������� -- (T& x)
//����������� -- ���Ǿ�ֻ�ܴ���ֵ�� -- ���Խ�����(const T& x)
//��ʱx���ܽ�����ֵҲ�ܽ�����ֵ
#if 0
template<class T>
void func(T& x)
{}
int main()
{
	//��ֵ�����ܲ��ܸ���ֵȡ������
	double x = 1.1;
	double y = 2.2;
	//double& ret = x + y;//err
	const double& ret = x + y; //�Ӹ�const������
	//��ֵ�����ܲ��ܸ���ֵȡ������
	int num = 20;
	//int&& rr = num;	//err
	int&& rr5 = move(num);
	//����ֱ�����ã����ǿ�������move֮�����ֵ
	return 0;
}
#endif

/** һ����������� */
/*
* ��ֵ�ǲ���ȡ��ַ��
* ���Ǹ���ֵȡ�����󣬻ᵼ����ֵ���洢���ض���λ�ã��ҿ���ȡ��ַ
*/
#if 0
int main()
{
	double x = 1.1;
	double y = 2.2;
	int&& rr1 = 10;
	double&& rr2 = x + y;
	rr1 = 10;
	rr2 = 5.5;
	//�е�ַ��
	printf("%p\n", &rr1);
	printf("%p\n", &rr2);
	return 0;
}
#endif

//��ֵ���õ�Ӧ��
//���� -- �����Ǹ���ģ�
/** ���õļ�ֵ -- ���ٿ���*/

//��ֵ���ã�
//1.������ -- a.���ٿ��������Ч��  b.������Ͳ���
//2.������ֵ -- a.���ٿ��������Ч��  b.���÷��أ������޸ķ��ض��󣬱���operator[]
//����ֵ����������ֵ��ʱ�� -- ��ʵֻ�����70%������
//����	to_string() -- ��ֵ����
//��Ϊ to_string(){}�����string�Ǿֲ�����
//���Ǵ�ֵ���أ�Ҫ���ܶ࿽��
//���緵��һ��vector<vector<int>>
//��ô�죿
//ȫ�֣� -- ȫ���ڶ��߳��»������
//���һ��Ҫ�Ż� -- �ŵ������ϣ��������Ͳ��� -- ���⣺������д�����ϰ��

//��ֵ���õ�һ����Ҫ���� -- ���ǽ�����淵��ʱ����������
#if 1
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ��������(���)" << endl;

			//string tmp(s._str);
			//swap(s);

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			//��ʱ���Ƿ���s��һ����ֵ -- һ������ֵ -- ���ǻ��б�Ҫ���������
			//�Ѿ�û�б�Ҫ�� -- ����ֱ��swap -- ����һ����Դת�ƾ���
			cout << "string(string&& s) -- ��Դת��" << endl;
			swap(s);
		}
		// ������ֵ
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ������ֵ(���)" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}
		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string s) -- �ƶ���ֵ(��Դ�ƶ�)" << endl;
			swap(s);

			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

bit::string to_string(int value)
{
	bool flag = true;
	if (value < 0)
	{
		flag = false;
		value = 0 - value;
	}

	bit::string str;
	while (value > 0)
	{
		int x = value % 10;
		value /= 10;

		str += ('0' + x);
	}

	if (flag == false)
	{
		str += '-';
	}

	std::reverse(str.begin(), str.end());
	return str;
}
#endif

// ����������ƶ�����
#if 0
int main()
{
	bit::string ret = to_string(-3456);

	bit::string s1("1111111");
	bit::string s2(s1);

	return 0;
}
#endif
//�������죺
//string to_string(char*str){return ans}
//string ret = to_string("1234");
//ԭ��ans��һ��ռ�
//ret��һ��ռ�
//û���Ż����Ŀ������죺
	//ans ��������ʱ�ռ� tmp��tmp������ret���ͷ�tmp��ans
//�Ż���Ŀ�������
	//ans ������ret�ϣ��ͷ�ans
//�ƶ�����
//ret��ָ�벻ָ��ԭ���Ŀռ��� -- ֱ��ָ��ans��ȥ
//ans��ָ������
//��ʱ�ƶ�����û�з�������

//��ֵ���õļ�ֵ -- �������ƶ�������ƶ���ֵ�ϣ�

#if 0
int main()
{
	string s1("hello world");
	string s2(s1);//��������
	string s3 = s1 + s2; //�ƶ�����
	return 0;
}
#endif

//stl�������еĲ���ӿ� -- ����������ֵ�汾
//push_back()��Щ�ӿ����涼��
#if 0
int main()
{
	vector<bit::string>v;
	return 0;
}
#endif
//����emplace_back()��Щ�ӿ�



//����ת��
void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

//�������ã�t����������ֵ��Ҳ��������ֵ
template<typename T>
void PerfectForward(T&& t)
{
	//Fun(t);
	//����ת��
	Fun(std::forward<T>(t));
}
int main()
{
	PerfectForward(10); //��ֵ
	int a = 20;
	PerfectForward(a);//��ֵ
	PerfectForward(std::move(a));//��ֵ
	const int b = 8;
	PerfectForward(b);//const ��ֵ
	PerfectForward(std::move(b));//const ��ֵ
	return 0;
	/*
	��ֵ����
	��ֵ����
	��ֵ����
	const ��ֵ����
	const ��ֵ����
	*/
	///������ǲ�������ת�������Ƿ���tͨͨ�������ֵ
	///���ʹ������ת�� -- t�����ԾͿ��Ա�����
	//��ʱ
	//��ֵ����
	//��ֵ����
	//��ֵ����
	//const ��ֵ����
	//const ��ֵ����
}

//����ת�� -- ʲôʱ������
//����stl
//void func(T&& x)
/// ��ΪҪʹ��ģ�� -- ��ʱ�����������ת�� 
/// x�ᱻ�����۵� -- ȫ�������ֵ�� 
/// �����ֵ -- �ÿ����Ŀ�����
/// ��������ת��һ�£�����ԭ������������ -- ���ÿ����ı𿽱��ˣ�
/// �������Ҫ�Ĵ����ʱ�� -- ÿһ�㶼Ҫ����ת��
/// ��Ȼ��һ��ת�� -- ����ȥûת -- ����������
/// ���Կ���list.h����θĵ�