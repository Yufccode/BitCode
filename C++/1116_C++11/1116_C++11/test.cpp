
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;
#elif
#endif


//���Ĭ�ϳ�Ա���� -- ��ǰ��6��1��
// 
//������8�� -- �ƶ�����/�ƶ���ֵ

//���������ʱ��������Ҫ�Լ�д�ƶ�������ƶ���ֵ
#if 0
int main()
{
	return 0;
}
#endif

/** �ƶ�������ƶ���ֵ��һЩע��ĵ� */
/*
* �������û���Լ�ʵ���ƶ����죬���ң�
* ����û��ʵ�������������������졢������ֵ�����е�����һ����
* ��ô���������Զ����ɡ�
* �Զ����ɵģ�
* ���������ͻ�ִ�����ֽڿ������Զ������ͣ�����Ҫ�������Ա
* �Ƿ�ʵ���ƶ����죬���ʵ���˾͵����ƶ����죬���û��ʵ�־�Ч�ÿ������졣
*/
/*
* ���û��ʵ���ƶ���ֵ������û���������������졢������ֵ�е�����һ��
* ��ô���������Զ�����һ��Ĭ���ƶ����졣
* Ĭ�����ɵ��ƶ����죬�����������ͳ�Ա���������Ա���ֽڿ���
* �Զ������ͻῴ�����Ա�Ƿ�ʵ�����ƶ���ֵ�����ʵ���˾͵��ã�
* ûʵ�־͵��ÿ������� 
*/

#if 0
struct Person
{
public:
	Person(Person&& p) = default;//ǿ������
	Person() = delete;//ǿ�Ʋ��������� -- �����ǲ�����Person������
};
int main()
{
	//Person p; -- err
	return 0;
}
#endif


//������ -- Ҫ����delete�ؼ��ִ���һ���� -- ֻ���ڶ�������
//1.���캯��˽�� -- �����ò���delete�ؼ���
#if 0
class HeapOnly
{
public:
	~HeapOnly() = delete;
	void destructor()
	{
		delete[] _str;
		//operator delete(this);
		//����������operator delete(ptr)
	}
private:
	char* _str;
};
int main()
{
	//HeapOnly hp1; err
	//static HeapOnly hp2; err
	HeapOnly* ptr = new HeapOnly;
	//�������ǿ��Թ����� -- ����������ô�����أ�
	//û�취������
	//delete ptr;//err
	//�����Լ�дһ�������������ˣ�
	ptr->destructor();
	operator delete(ptr);
	//freeҲ���ԣ�operator delete��free����
	// //Ϊ��ƥ��һ�����ǻ�����operator delete�õ�
	//free(ptr);
	return 0;
}
#endif



//�ɱ����ģ��
//Args... args����N��������(N>=0)
#if 0
void ShowList()
{
	cout << endl;//�������ɵݹ����ֹ����
}
template <class T, class ...Args>
void ShowList(const T& val, Args... args)
{
	//cout << sizeof...(args) << endl; //������������ĸ���
	//1.
	cout << val << " ";
	ShowList(args...);//������0��������ʱ�򣬾Ͳ��ʺϵ����Լ��ˣ�������������һ��0��������
	//��������ݹ鲻������ʱ���õ� -- �Ǳ���ʱ���õ�
}
int main()
{
	string str = "hello";
	/*ShowList();
	ShowList(1, 'A');
	ShowList(1, 'A', str);
	ShowList("aa");*/
	ShowList(1, 'A', str);
	return 0;
}
#endif


//���ֻ��һ��Args��
#if 0
template <class T>
void PrintArg(const T& x)
{
	cout << x << " ";
}
template <class ...Args>
void ShowList(Args... args)
{
	int a[] = { (PrintArg(args),0)... }; cout << endl;
	//�����б��ʼ��ȥ��
}
int main()
{
	ShowList('a', 1, 2.22);
	return 0;
}
#endif



//emplace
#if 0
int main()
{
	vector<int>v;
	//�����ֲ���û������
	v.emplace_back(1);
	v.push_back(2);

	vector<pair<string, int>>v2;
	v2.push_back({ "sort",1 });//����+��������/����+�ƶ�����
	v2.emplace_back("sort", 1);//����
	v2.emplace(v2.begin(), "my", 2);
	for (auto& e : v2)
	{
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}
#endif



#if 0
class Date
{
protected:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{
		cout << "Date::Date()" << endl;
	}
	Date(const Date& d)
		:_year(d._year), _month(d._month), _day(d._day) 
	{
		cout << "Date::Date(const Date&)" << endl;
	}
	Date& operator=(const Date& d)
	{
		cout << "Date& Date::operator=(const Date& d)" << endl;
	}
};
int main()
{
	//��֤���ֶ�vectorû�����𣬶�list�����������
	//����������emplace���ÿ������� �� ����vectorΪʲôû����֤����Ҫȥ��Դ��
	//��ûɶ��Ҫȥ��
	cout << "----------------- vector -----------------" << endl;
	vector<Date>v3;
	v3.push_back(Date(2022, 11, 16));
	cout << "---------------" << endl;
	v3.emplace_back(2022, 11, 16);
	cout << "----------------- list -----------------" << endl;
	list<Date>l;
	l.push_back(Date(2022, 11, 16));
	cout << "---------------" << endl;
	l.emplace_back(2022, 11, 16);
	return 0;
}
#endif



//����ʹ�õĶ���/����
//1.����ָ��
//2.�º��� -- ��������() -- Ҳ�к�������
//3.lambda

#if 0
struct Goods
{
	string _name;
	double _price;
	int _evaluate;
	//...
	Goods(const char* str, double price, int evaluate)
		:_name(str), _price(price), _evaluate(evaluate) {}
};
#endif
//����������_name,_price,_evaluate��Щ�����������
//����Ҫ�ṩ�����º���

//lambda��д��ʽ��
//[capture - list](parameters)mutable->return-type{ statement };
#if 0
int main()
{
#if 0
	//���������
	auto add1 = [](int a, int b)->int {return a + b; };
	cout << typeid(add1).name() << endl;
	cout << add1(1, 2) << endl;

	//ʡ�Է���ֵ
	auto add2 = [](int a, int b) {return a + b; };
	cout << add2(1, 2) << endl;

	//����
	int x = 0; int y = 1;
	auto swap1 = [](int& a, int& b) {int tmp = a; a = b; b = tmp; };
	swap1(x, y);
	cout << x << " " << y << endl;
	//
	auto swap2 = [](int& a, int& b)
	{
		int tmp = a; a = b; b = tmp;
	};

	//Ҫ�󲻴���������x,y
	int x = 0; int y = 1;
	auto swap3 = [x, y]()mutable// ��׽�б�
	{
		int tmp = x; x = y; y = tmp;
	};
	swap3();
	//Ĭ�ϲ�׽�����ı��������޸� -- ���Լ�һ��mutable
	cout << x << " " << y << endl;
	//���ָĲ��� -- ���ֲ�׽ֻ�ǿ�����׽
#endif
	int x = 0; int y = 1;
	auto swap4 = [&x, &y]()
	{
		int tmp = x; x = y; y = tmp;
	};
	swap4();
	cout << x << " " << y << endl;
	return 0;
}
#endif


struct Goods
{
	string _name;
	double _price;
	int _evaluate;
	//...
	Goods(const char* str, double price, int evaluate)
		:_name(str), _price(price), _evaluate(evaluate) {}
};
ostream& operator<<(ostream& out, const Goods& g)
{
	cout << g._name << " " << g._price << " " << g._evaluate << endl;
	return out;
}
int main()
{
	vector<Goods> v = { {"ƻ��",2.1,5},{"�㽶",3,4},{"����",2.2,3},{"����",1.5,4} };
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
		{
			return g1._name < g2._name;
		});
	for (auto e : v)
	{
		cout << e << endl;
	}
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
		{
			return g1._evaluate < g2._evaluate;
		});
	for (auto e : v)
	{
		cout << e << endl;
	}
	return 0;
}