#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<list>

using namespace std;

#elif
#endif

//�б��ʼ��
#if 0
int main()
{
	// �������ͱ���
	int x1 = { 10 };
	int x2{ 10 };
	int x3 = 1 + 2;
	int x4 = { 1 + 2 };
	int x5{ 1 + 2 };
	// ����
	int arr1[5]{ 1,2,3,4,5 };
	int arr2[]{ 1,2,3,4,5 };
	// ��̬���飬��C++98�в�֧��
	int* arr3 = new int[5]{ 1,2,3,4,5 };
	// ��׼����
	vector<int> v{ 1,2,3,4,5 };
	map<int, int> m{ {1,1}, {2,2,},{3,3},{4,4} };
	return 0;
}
#endif

#if 0
class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};
int main()
{
	Point p{ 1, 2 };
	return 0;
}
#endif

//��������ñȽ϶�
#if 0
int main()
{
	vector<int>arr = { 1,2,3,4 };
	vector<int>arr2{ 1,2,3,4 };
	list<int>arr3{ 1,2,3,4 };
	//{}��������� -- ����
	//��C++11������һ�����ͣ�����
	auto x = { 1,2,3,4 };
	cout << typeid(x).name() << endl;
	//class std::initializer_list<int>
	initializer_list<int>array1 = { 1,2,3 };
	for (auto& e : array1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

//�Լ�д��vector֧��{}��
//��Ҫ����{}�Ĺ��캯��


#if 0
class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};
int main()
{
	//���ڿ�������֧����
	vector<Point>parr = { {1,2},{2,3} };
	map<string, string>m = { {"A","a"},{"B","b" } };
	m = { {"C","c"},{"D","d" } };//�����Ǹ�ֵ
	return 0;
}
#endif



//auto
#if 0
#include<string.h>
int main()
{
	auto funciton = strcpy;
	cout << typeid(funciton).name() << endl;
	return 0;
}
#endif


//decltype
#if 0
int main()
{
	//���������Ƶ�����
	//typeid�õ�������ֻ�����͵��ַ����������������ȥ�������ʲô��
	int x = 10;
	decltype(x) y = 20;
	cout << typeid(y).name() << endl;

	//��auto�������ǲ�һ����
	decltype(x) y1 = 20.22;
	auto y2 = 20.22;
	cout << y1 << " " << y2 << endl;
	return 0;
}
#endif



//������
#include<array>
#include<forward_list>
int main()
{
	//array �� forward_list 
	//���ܶ����²� -- �ܼ���
	//array -- ϣ�����a[]
	//arrayԽ�����ϸ�
	array<int, 10>arr;
	
	//forward_list
	forward_list<int>a = { 1,2,3,4 };
	forward_list<int>::iterator it = a.begin();
	while (it != a.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//��list���ǲ�һ��ָ���λ�ã�����forward_list�Ĺ��ܻ���ȫ
	return 0;
}