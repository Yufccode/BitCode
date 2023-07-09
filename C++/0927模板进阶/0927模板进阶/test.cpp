#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

//ģ�����


#if 0
template<class T, size_t N>
class array {
private:
	T _a[N];
};
#if 0
template<class T,string s>
template<class T, double d>
class A {};
#endif
//һ����Щ������������ģ�������һ�������ͣ�char��Щ
int main() {
	array<int, 100>a1;
	array<double, 1000>a2;
	//������Ҫ��a1�����С��100
	//a2��1000
	//��ô�죿
	//������ģ����� -- ����
	//����֪����ģ������ͺ��������Ƿǳ���� -- ���Ը�ȱʡֵ
	return 0;
}
#endif

#include<array> //������ģ������ǳ�����
#if 0
//std::array
//�̶���С��˳������ -- ��̬����
//���Ǿ���Ŀ��Բ��ĵ� -- �ܼ�
//��׼���array����������?
int main() {
	array<int, 10>arr; //C++11ϣ������
	int arr2[10];  //C
	//�ĸ��ã�
	cout << sizeof(arr) << endl;
	cout << sizeof(arr2) << endl;
	//������û�г�ʼ��


	//�������������� -- Խ����
	//C�����Խ���ǲ����ģ�Խ��д�ż��
	//����Խ��д���Ҳ�Ǻ��о����Ե� -- Խ���ͼ�鲻����
	//���ǳ�����

	arr[10];//��������ô�����ᱻ�鵽�� ������Ӧ��assert��
	arr[10];
	arr2[15] = 1;

	//std::array��Խ������ϸ�
	return 0;
}
#endif


#if 0
//ģ����ػ� -- ģ�����⻯����
struct Date {
	Date(int year, int month, int day)
		:_year(year), _month(month), _day(day)
	{}
	bool operator>(const Date& d)const {
		if ((_year > d._year) || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day)) {
			return true;
		}
		else return false;
	}
	bool operator<(const Date& d)const {
		if ((_year < d._year) || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day)) {
			return true;
		}
		else return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
//����ģ�� -- ����ƥ��
template<class T>
bool Greater(T left, T right) {
	return left > right;
}
//�ػ� -- ���ĳЩ���ͽ������⻯����
//���ȣ�C++���ܱȽ����� ���� T == Date* ��������
//typeid������ -- ��ƽ̨���⣬��ʱ�����ͷ��ص���int���е�ʱ�򷵻ص���i
//��Ҫ�ػ��� -- ע��������﷨��������
template<>
bool Greater<Date*>(Date* left, Date* right) {
	return *left > *right;
}
//ע���﷨������
// // ============================================================
//����ģ������ػ� -- ��ģ��Ҳ����
namespace yufc {
	template<class T>
	struct less {
		bool operator()(const T& x1, const T& x2) const { 
			return x1 < x2;
		}
	};
	//�ػ�
	template<>
	struct less<Date*> {
		bool operator()(Date*& x1, Date*& x2) const {
			return *x1 < *x2;
		}
	};
}

int main() {
	cout << Greater(1, 2) << endl;//���ԱȽϣ������ȷ
	Date d1(2022, 7, 7);
	Date d2(2022, 7, 8);
	cout << Greater(d1, d2) << endl;//���ԱȽϣ������ȷ
	Date* p1 = &d1;
	Date* p2 = &d2;
	cout << Greater(p1, p2) << endl;//���ԱȽϣ��������

	yufc::less<Date>lessFunc1;
	cout << lessFunc1(d1, d2) << endl;
	yufc::less<Date*>lessFunc2; //����Ҳ������һ��������
	cout << lessFunc2(p1, p2) << endl;

	//�����������������
	priority_queue<Date, vector<Date>, less<Date>>dq1;
	priority_queue<Date*, vector<Date*>, less<Date*>>dq2;//���������ػ��ͻ������

	//��Ҫ�ػ���
	dq2.push(new Date(2022, 9, 27));
	dq2.push(new Date(2022, 9, 25));
	dq2.push(new Date(2022, 9, 28));

	return 0;
}
#endif


//ģ�������ȱʡ����������
#if 0
template<class T1,class T2>
class Data {
public:
	Data() { cout << "Data<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//ȫ�ػ�
template<>
class Data<int, char> {//ȫ�ػ�
public:
	Data() { cout << "Data<int,char>" << endl; }
private:
	int _d1;
	char _d2;
};
//ƫ�ػ�
//�κ����ģ�������һ����������������Ƶ��ػ��汾
template<class T1>
class Data<T1, int> {
public:
	Data() { cout << "Data<T1, int>" << endl; }
};
//����ģ��������У�����Ҳ��ƫ�ػ�
template<class T1,class T2>
class Data<T1*, T2*> { //ֻҪ��ָ�� -- �������ƫ�ػ�
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};
//ģ����������� -- �ͻ�ƥ����
template<class T1, class T2>
class Data<T1&, T2&> { //ֻҪ��ָ�� -- �������ƫ�ػ�
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};
int main() {
	Data<int, int>d1;
	Data<int, char>d2;
	Data<int*, int*>d3;
	Data<double*, void*>d33;
	Data<int*, double>d4;

	Data<int&, int&>d5;
	Data<int&, char&>d6;

	return 0;
}
#endif
//��ʵ����ģ����ػ�����һ������ƥ������� -- ����ƥ��ģ�������ƥ��Ľ���һ�µ�Ҳ�У�ʵ�ڲ��Ծͱ���
//�������˼��


//ģ��ķ������
//ģ���ǲ�֧�ַ�������
//����1����Ϊ�������֮�󣬱������ܶ�ط��㲻�������������������ͻ��Ǳ���

//����
template<class T>
void PrintContainer(const list<T>& lt) {
	typename list<T>::const_iterator it = lt.begin();
	//��ʱ�������Ǹ㲻���const_iterator���������ͻ��Ǳ����� -- ����һ��typenameǰ׺����
	while (it != lt.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main() {
	list<int>lt = { 1,2,3,4 };
	PrintContainer(lt);
	return 0;
}

//����2���ص� -- һЩ�ӿڻ�������Ӵ���
//�������Ƿ��������Ͷ��� -- ����push_back()��Щ�ͻᱨ���Ӵ���
//�����Ӵ��� -- �ҵ������� -- �Ҳ�������
//���ú�����ʱ����ʵ���� callһ����ַ
//������Ϊpush_back()û��ʵ�֣�����û�б�ʵ����
//���캯����size()��operator[]��Щ������Ҫ������ -- ����Ҫ
//��Ϊ������vector.h���ж��� -- ����vector<int>ʵ������ʱ�� -- �����Ѿ�ʵ������
//����size()��vector(),operator[]��Щ�����ڱ���׶��Ѿ�ȷ����ַ��
//push_back(),insert()����vector.h��ֻ��������û�ж���
//��ô��ַ��ֻ�������ӽ׶�ȥ�� -- ����˵���Ҳ�����
//������������ģ���ʱ���ǲ���ȥ�ܵ� -- T����֪�� -- ��֪������ôȷ��heap���濪���ٿռ䣿

//��ô�����
//1.ģ�������Ͷ��岻Ҫ�ֿ��ŵ�.h��.cpp��
//2.��ʾʵ���� -- д���� -- �൱��û��ģ����


//ģ����ȱ��
/*
* �ŵ㣺
* 1.ģ�帴���˴��룬��ʡ��Դ������ĵ���������C++��STL��˶�����
* 2.��ǿ�˴��������ԣ��ظ��Ĺ������������� -- ����ǽ�����
* ȱ�㣺
* 1.ģ���ǻᵼ�´����������⣬Ҳ�ᵼ�±���ʱ��䳤
* 2.����ģ��������ʱ��������Ϣ�ǳ����ң����׶�λ����
*/