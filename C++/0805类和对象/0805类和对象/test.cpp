#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

//��ʼ���б�
//��ʼ���б���һ��ð�ſ�ʼ��������һ���Զ��ŷָ������ݳ�Ա�б�ÿ��"��Ա����"�����һ��������
//���еĳ�ʼֵ����ʽ
#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
#endif
//��Щ��Ա����ʹ�ó�ʼ���б��ʼ��
/*
���ó�Ա����
const��Ա����
�Զ������ͳ�Ա(����û��Ĭ�Ϲ��캯��) -- ��Ϊ��������ȥ���Զ������ͳ�Ա�Ĺ��캯��
			���û��Ĭ�Ϲ�����Ե� -- �ͻᱨ��
			������ʵ���캯����ʵ�����ʼ�����ѣ�������Date�ĳ�Ա���������Time��ʼ�� -- ����Ҫ��ʼ���б�
*/

//����ʹ�ó�ʼ���б��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б������Զ������ͳ�Ա������һ������ʹ
//�ó�ʼ���б��ʼ����

//������ôд�������ó�ʼ���б�� -- ���д�ˣ��͵���д�ģ����ûд�����ǵ��ñ�������
//ֻ�Ǳ������ĳ�ʼ���б�ֻ��ʼ���Զ������ͣ�����ʼ���������Ͷ���

//���ۣ��Զ������ͳ�Ա����ʹ�ó�ʼ���б��ʼ��

//��ʼ���б������Ϊ�ǳ�Ա��������ĵط�


#if false
class Time {
public:
	Time(int hour) {
		_hour = hour;
		cout << "������Time��Ĭ�Ϲ���" << endl;
	}
private:
	int _hour;
};
class Date
{
public:
	Date(int year,int hour) 
		:_t(hour) 
	{
		_year = year;
	}
private:
	int _year;
	Time _t;
};
int main() {
	Date d1(2022, 1);
	return 0;
}
#endif



//const�����ó�ʼ���б��ԭ��Ҳ�ܼ�
//const��Աֻ���ڶ����ʱ�򱻳�ʼ��
//const��Աֻ�ܳ�ʼ��һ��
//����ʼ���б�ĵط����Ƕ���ĵط�������ֻ���ڳ�ʼ���б��ʼ��

//����Ҳ��ͬһ�����ף�����Ҫ�ڶ����ʱ���ʼ��
#if false
class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};
class B
{
public:
	B(int a, int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	A _aobj; // û��Ĭ�Ϲ��캯��
	int& _ref; // ����
	const int _n; // const
};
#endif



//���ʱ�����ǾͿ��Խ���C++11�Ǹ�������ʲô��˼��
#if false
class Date {
public:
	Date(){}
	Date(int year) {
		_year = year;
	}
	void Print() {
		cout << _year << endl;
	}
private:
	//����
	int _year = 1; //��������Ҫ����� �������int _year��һ�����������Ƕ��壡
	//�������ڳ�ʼ���б��ϵģ�
	//�������= 0��ȱʡֵ����������ʵ�Ǹ���ʼ���б�ģ�
};
int main() {
	//Date d1(2002);
	Date d2;
	d2.Print();
	return 0;
}
#endif


//��������Ҳ�Ƽ�ʹ�ó�ʼ���б��ʼ������Ȼ���������ں������ڳ�ʼ��Ҳû��ʲô���Ե�����
//ͳһ�Ľ��飺��ʹ�ó�ʼ���б��ʹ�ã�����ûʲô����


//���ǲ���һ���Ӵ���
//��Щʱ��ʹ�ó�ʼ���б�ͻ�ܱ�Ť
//�����ʼ�������ʱ��
#if 0
class A {
public:
	//ָ������������
	//�����ó�ʼ���б����Ǻܱ�Ť���������ǻ�Ҫ��鿪�ռ��Ƿ�ɹ�
	//�������������д���������ڻ��һЩ
	A(int size)
		//:_a((int*)malloc(sizeof(int)* size)),
		//_size(size)   --    �ܱ�Ť
		:_size(size)
	{
		_a = (int*)malloc(sizeof(int) * size);
		//_size = size;//������������ĳ�ʼ��д����ʼ���б�����ͦ�õ�
		//���Ի���д
		if (_a == nullptr) {
			perror("malloc fail");
		}
		memset(_a, 0, sizeof(int) * size);
	}
private:
	int* _a;
	int _size;
};
int main() {
	A aa(10);
	return 0;
}
#endif


//�����������н����ʲô��
#if 0
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};
int main() {
	A aa(1);
	aa.Print();
	return 0;
}
#endif
//����϶��������ģ���Ϊ��_a2�ȳ�ʼ��
 
//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�



//explicit�ؼ���
#if false
class Date {
public:
	explicit Date(int year) :_year(year)
	{
		cout << "����Date�Ĺ��캯��" << endl;
	}
	Date(const Date& d) {
		cout << "�����˿�������" << endl;
	}
private:
	int _year;
};
int main() {
	//�����ַ�ʽ��ʵ�����ù��캯��
	Date d1(2022);//ֱ�ӵ��ù��캯��
	Date d2 = 2022;//����+��������+�Ż�->���ù��캯�� -- ���ﱾ������ʽ����ת��
	//�������explicit�ͻᱨ��
	//���ǹ����ǲ�һ����
	//��ʵ���ǿ����Լ�дһ���������죬�����ǲ���������˿�������
	//����д��֮���ֿ���������������ĵ��� -- �Ż���
	//�������ǿ��Լ���explicit�ؼ��֣���ֹ��ʽ���͵�ת��

	//�������()ǿת -- �Ͳ�����ʽ����ת�� ���Լ���Ĳ���
	return 0;
}
#endif

#if false
int main() {
	int i = 10;
	double d1 = (double)i;//��������ʽ������ת��
	double d2 = i;//����ͷ�������ʽ���͵�ת��
	//double& d3 = i;//err -- ��ʽ����ת���������ʱ��������ʱ�����߳��ԣ�d3��������i����������ʱ����
	const double& d4 = i;//�����Ϳ��Ա����
	i++;
	int& ii = i;//���û�в���ת����ii�ͻ���i�䣬��Ϊii��i������
	//����d4����i�����ã�d4����ʱ����������
	cout << d4 << endl;//����ǲ�����
	cout << ii << endl;
	cout << i << endl;
	return 0;
}
#endif

//��������
#if 0
class Date {
public:
	Date(int year) :_year(year)
	{
		cout << "����Date�Ĺ��캯��" << endl;
	}
	Date(const Date& d) {
		cout << "�����˿�������" << endl;
	}
	~Date() {
		cout << "������Date����������" << endl;
	}
private:
	int _year;
};
int main() {
	//Date d3(2022);
	Date(2022);//�������� -- ��������ֻ����һ��
	//����������������������ϻᱻ����
	return 0;
}
#endif


//����������һЩ�����������õ�
//����������OJ���ʱ��Ҫ����
#if false
class Solution {
public:
	void fun() {//���⺯��
		//...
	}
};
int main() {
	//������Ҫ�������۵�OJ
	//1.
	Solution su;
	su.fun();//����ȥ������
	//�������ǿ���˼��������ʵ����������Ŀ�ľ��������������û�б��Ŀ��
	//������ǿ�����������
	//2.
	Solution().fun();//����һ�и㶨 -- �ܼ��
	return 0;
}
#endif




//��̬��Ա
/*����Ϊstatic�����Ա��Ϊ��ľ�̬��Ա����static���εĳ�Ա��������֮Ϊ��̬��Ա��������static���ε�
��Ա��������֮Ϊ��̬��Ա��������̬�ĳ�Ա����һ��Ҫ��������г�ʼ��*/

//�����Ƿ��ܴ���һ��ֻ�������������ʹ�õ�ȫ�ֱ����� -- ��̬��Ա
#if 0
class A
{
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	//��̬��Ա���� -- û��thisָ��
	static int& GetCount() {//���������&Ҳ���ϣ�������Ϳ��Զ�_scount���в�����
		//û��thisָ�룬�����Ƿ��ʲ���_a��
		return _scount;
	}
private:
	//��̬��Ա���� ���������� �����������������������ڼ� ���ھ�̬��
	static int _scount;//���� -- ���Ƕ�֪����ֻ�������ǿ϶��ᱨ���

	int _a;
};
//��������Ҫ��취ȥ�������_scount
//����Ŀǰ��֪��
//1.��ʼ���б� -- ���� -- ��ʼ���б���������̬����
//2.ȱʡֵ -- ���� -- ȱʡֵ�������Ǹ���ʼ���б�ģ����ڳ�ʼ���б��в�ͨ�ˣ�ȱʡ�϶��в�ͨ��

//���� -- �����涨���ʼ��
int A::_scount = 0; //�����ʱ���ô�static

void TestA()
{
	A a1;
	A a2;
	A a3(a2);

#if 0
	cout << a1._scount << endl;//���羲̬��Ա�ǹ��еģ�����ȥ����һ��
	cout << a2._scount << endl;
	cout << A::_scount << endl;
	a1._scount++;
	cout << a1._scount << endl;
	cout << a2._scount << endl;
	cout << A::_scount << endl;
#endif//�����˽�еľͷ��ʲ����� -- ����һ���µĸ��� -- ��̬��Ա����
	cout << a1.GetCount() << endl;
	cout << a2.GetCount() << endl;
	cout << A::GetCount() << endl;
	a1.GetCount()++;//���������ִ��ֻ����Ϊ���Ƿ�����&����
	cout << a1.GetCount() << endl;
	cout << a2.GetCount() << endl;
	cout << A::GetCount() << endl;
}
int main() {
	TestA();
	return 0;
}

/*
1. ��̬��ԱΪ���������������������ĳ�������ʵ�� -- a1,a2,a3����һ��_scount
2. ��̬��Ա�������������ⶨ�壬����ʱ�����static�ؼ���
3. �ྲ̬��Ա����������::��̬��Ա���߶���.��̬��Ա������
4. ��̬��Ա����û�����ص�thisָ�룬���ܷ����κηǾ�̬��Ա
5. ��̬��Ա�������ͨ��Աһ����Ҳ��public��protected��private 3�ַ��ʼ���Ҳ���Ծ��з���ֵ
*/
#endif



//��̬��ʹ�ó���
//Ӧ��1��
//��1+....+n
#if 0
class Sum {
public:
	Sum() {
		_sum += _i;
		++_i;
	}
	static int GetSum() {
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};
int Sum::_sum = 0;
int Sum::_i = 1;
class Solution {
public:
	int Sum_Solution(int n) {
		Sum a[n];
		return Sum::GetSum();
	}
};
//����������ǵı�׼�淨
//����ײ�ľ���˼·���Ƿ�װ
#endif


//Ӧ��2��
//���һ��ֻ����ջ�϶������
#if 0
class StackOnly {
public:
	static StackOnly CreateObj() {
		StackOnly so;//�������ջ�ϵ�
		return so;
	}
private:
	StackOnly(int x = 0, int y = 0)
		:_x(x),
		_y(0)
	{}
private:
	int _x = 0;
	int _y = 0;
};
int main() {
#if 0
	StackOnly so1;//ջ
	static StackOnly so2;//��̬��
#endif
	//�����ʱ��������ǰѹ��캯�����óɹ��е�
	//�����Ʋ��������ﴴ���ˣ���Ϊ�Ķ����Ե����������
	//��������ֱ�Ӱѹ��캯�����ó�˽�е�
	// -- ���ó�˽��֮���Ķ��������ˣ����ʱ���������������ṩһ����������
	//�����������Ա�������棬��ջ�ϴ�����Ȼ�󷵻� -- ���������ֻ�ܵõ�������ջ�ϴ����Ǹ���
	
	//���ھͳ��������м��������е��������ˣ����������CreateObj()��Ҫ�������󣬵��Ƕ��󴴽���ҪCreateObj
	//���Ը������������static
	StackOnly so3 = StackOnly::CreateObj(); //���������ˣ�
	return 0;
}


//��������
//1.��̬��Ա�������Ե��÷Ǿ�̬��Ա������ -- ���ܣ���Ϊû��this
//2.�Ǿ�̬��Ա�������Ե�����ľ�̬��Ա������ -- ����

#endif



//��Ԫ
//1.��Ԫ����
//2.��Ԫ��
//��Ԫ�ṩ��һ��ͻ�Ʒ�װ�ķ�ʽ����ʱ�ṩ�˱�����������Ԫ��������϶ȣ��ƻ��˷�װ��������Ԫ���˶��á�

/*
��Ԫ��������ֱ�ӷ������˽�г�Ա�����Ƕ��������ⲿ����ͨ�������������κ��࣬����Ҫ������ڲ���
��������ʱ��Ҫ��friend�ؼ��֡�
��Ԫ����������const����
��Ԫ�����������ඨ����κεط�����������������޶�������
һ�����������Ƕ�������Ԫ����
��Ԫ�����ĵ�������ͨ�����ĵ��ú�ԭ����ͬ
*/

/*
1.��Ԫ������г�Ա��������������һ�������Ԫ�����������Է�����һ�����еķǹ��г�Ա��
2.��Ԫ��ϵ�ǵ���ģ������н����ԡ�
��������Time���Date�࣬��Time��������Date��Ϊ����Ԫ�࣬��ô������Date����ֱ�ӷ���Time
���˽�г�Ա������������Time���з���Date����˽�еĳ�Ա�������С�
��Ԫ��ϵ���ܴ���
3.���B��A����Ԫ��C��B����Ԫ������˵��CʱA����Ԫ��
*/


//�ڲ���
#if 0
class A {
private:
	int h;
public:
	//B������A���� -- ֻ������Щ����
	//1.��A���������ƣ��ܷ����޶���������
	//2.B������A����Ԫ
	class B {
	public:
		void foo(const A& a) {
			cout << a.h << endl;//���Է���A��˽��
		}
	private:
		int _b;
	};
};
int main() {
	cout << sizeof(A) << endl;//4
	A a;
	A::B b;
	return 0;
}
#endif
/*
1. �ڲ�����Զ������ⲿ���public��protected��private���ǿ��Եġ�
2. ע���ڲ������ֱ�ӷ����ⲿ���е�static��ö�ٳ�Ա������Ҫ�ⲿ��Ķ���/������
3. sizeof(�ⲿ��)=�ⲿ�࣬���ڲ���û���κι�ϵ
*/


//���ڱ�������һЩ�Ż�
class A {
public:
	A() {
		cout << "������A�Ĺ��캯��" << endl;
	}
	A(int x) {
		cout << "������A�Ĺ��캯��" << endl;
	}
	A(const A& a) {
		cout << "������A�Ŀ������캯��" << endl;
	}
	//~A() {
	//	cout << "������A����������" << endl;
	//}
};
void f2(const A& a) {

}
A f3() {
	A a;
	return a;//��Ȼ������ֻ�ܴ�ֵ����
}
int main() {
	A a1;
	cout << endl;
	f2(A());//����Ŀ�������ͻᱻ�Ż���
	//���ۣ�
	//����һ�����ʽ�����У���������һ�㶼���Ż� -- һ���϶�Ϊһ

	cout << endl;     
	A a = 1;//ͬ�� �������챻�Ż���

	cout << endl;
	f3();

	cout << endl;
	A a2 = f3();//��������1�ι���2�ο�������
	//������һ�ο������챻�Ż��ˣ�
	return 0;
}