
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<functional>
using namespace std;
#elif
#endif

#if 0
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	auto f1 = [=]()
	{
		cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	};
	f1();

	//auto f2 = [=, a] ()  -- > err
	//{
	//	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	//};
	//f2();

	//��ϲ�׽
	auto f3 = [=, &a] ()
	{
		a++;
		cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	};
	f3();
	return 0;
}
#endif


// 1���������ڣ��洢����
// 2�������򣨱��������룬�õĵط��ܷ��ҵ���
// ��׽�б�ı��ʾ��Ǵ���
#if 0
static int f = 1;

int func()
{
	int a, b, c, d, e;
	a = b = c = d = e = 1;

	// ȫ����ֵ��׽
	auto f1 = [=](){
		cout << a << b << c << d << e << endl;
	};

	f1();

	// ��ϲ�׽
	auto f2 = [=, &a](){
		a++;
		cout << a << b << c << d << e << endl;
	};

	f2();
	static int x = 0;

	if (a)
	{
		auto f3 = [&, a](){
			//a++;
			b++;
			c++;
			d++;
			e++;
			f++;
			x++;
			cout << a << b << c << d << e << endl;
		};

		f3();
	}

	return 0;
}

int main()
{
	//auto f4 = [&, a](){
	//	//a++;
	//	b++;
	//	c++;
	//	d++;
	//	e++;
	//	f++;
	//	cout << a << b << c << d << e << endl;
	//};

	//f4();

	return 0;
}
#endif


//��׽�б�ĵײ㱾����һ���º���
#if 0
class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};


// ��ʵ���ʾ��ǻ���������һ����
// lambda_uuid
class lambda_xxxx
{

};

int main()
{
	// ��������
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);
	// �º���lambda_uuid
	// lambda -> lambda_uuid
	// ���õı�����operator()
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);
	auto r3 = [=](double monty, int year)->double{return monty*rate*year; };
	r3(10000, 2);
	return 0;
}
#endif



//��װ��
//ret = func(x);
#if 0
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;

	return f(x);
}

double f(double i)
{
	return i / 2;
}

struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

int main()
{
	// ����ָ��
	function<double(double)> f1 = f;
	cout << useF(f1, 11.11) << endl;

	// ��������
	function<double(double)> f2 = Functor();
	cout << useF(f2, 11.11) << endl;

	// lamber���ʽ����
	function<double(double)> f3 = [](double d)->double{ return d / 4; };
	cout << useF(f3, 11.11) << endl;

	return 0;
}
#endif

//150. �沨�����ʽ��ֵ
#if 0
#include<stack>
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<long long>st;
		map<string, function<long long(long long, long long)>>opFuncMap =
		{
			{"+",[](int a,int b) {return a + b; }},
			{"-",[](int a,int b) {return a - b; }},
			{"*",[](int a,int b) {return a * b; }},
			{"/",[](int a,int b) {return a / b; }}
		};
		for (auto& str : tokens)
		{
			if (opFuncMap.count(str))
			{
				//������
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(opFuncMap[str](left, right));
			}
			else
			{
				//������
				st.push(stoll(str));
			}
		}
		return st.top();
	}
};
#endif
//�����ð�װ�� -- ��ʽ��ס������
//function<����ֵ,(����)>



//��
int Div(int a, int b)
{
	return a / b;
}
int Plus(int a, int b)
{
	return a + b;
}
int Mul(int a, int b, int rate = 2)
{
	return a * b * rate;
}
class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};
int main()
{
#if 0
	//���Ҫ�ð�װ����ôд
	function<int(int, int)>funcPlus = Plus;
	function<int(Sub, int, int)>funcSub = &Sub::sub;//���Ƿ�������Ҫ��һ������Sub -- ��Ϊ����Ҫ���ö����
	//�����Ļ��ͻ��ú��鷳��
	//���ʱ�����Ҫ�õ�����
#endif
	
	int x = 10, y = 2;
	//����������˳�� -- ������ܼܺ���
	//_1,_2 ... �Ƕ�����placeholders�����ռ��У�����󶨺���������β�
	//_1�����һ���βΣ�_2����ڶ����β�
	//��������˳����ָ�����βε� -- ����ʱ���ʵ�β���
	auto bindFunc1 = bind(Div, placeholders::_1, placeholders::_2);
	auto bindFunc2 = bind(Div, placeholders::_2, placeholders::_1);
	cout << Div(x, y) << endl;//5
	cout << bindFunc1(x, y) << endl;//5
	cout << bindFunc2(x, y) << endl;//0

	//�����ļ�ֵ�� -- �󶨲��� -- ����������
	//�ѵ�һ���������� -- ��Ϊ��һ�������ǹ̶���
	function<int(int, int)>funcSub = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
	function<int(int, int)>funcPlus = Plus;
	function<int(int, int)>funcMul = bind(Mul, placeholders::_1, placeholders::_2, 2);//����2�����2��������������
																			//���2��Ҫ���� -- ȱʡֵ�ǲ������õ�
	map<string, function<int(int, int)>>opFuncMap =
	{
		{"+",Plus},
		{"-",bind(&Sub::sub,Sub(),placeholders::_1,placeholders::_2)}
	};
	cout << funcPlus(1, 2) << endl;
	cout << funcSub(1, 2) << endl;
	cout << opFuncMap["+"](1, 2) << endl;
	cout << opFuncMap["-"](1, 2) << endl;
	cout << funcMul(1, 2) << endl;
	//�����ļ�ֵ���ڿ��԰�ĳ������
	return 0;
}