
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<fstream>
using namespace std;

#if 0
int main()
{
	//cin��scanf
	//Ĭ�����ÿո�ֿ���
	int year = 0; int month = 0; int day = 0;
#if 0
	cin >> year >> month >> day;
	cout << year << " " << month << " " << day << endl;
	int ret = scanf("%d%d%d", &year, &month, &day);//��Ҫ�ӿո�
	cout << year << " " << month << " " << day << endl;
#endif

	//�������������զ�죿
	//20221128
	scanf("%4d%2d%2d", &year, &month, &day);
	cout << year << " " << month << " " << day << endl;

	string str;
	cin >> str;
	year = stoi(str.substr(0, 4));
	//...
	//����������
	return 0;
}
#endif

//oj��IO�͵�һЩ����������ô�죿
#if 0
int main()
{
	int year = 0; int month = 0; int day = 0;
	string str;
	while (cin >> str) //ctrl+Z+enter���ܽ��������ն˷���һ��������־
					   //ctrl+CҲ���ԣ�ctrl+C�൱��kill -9ֱ��ɱ��
	{
		year = stoi(str.substr(0, 4));
		month = stoi(str.substr(4, 2));
		day = stoi(str.substr(6, 2));
		cout << year << " " << month << " " << day << endl;
	}
	return 0;
}
#endif


//��ϰ -- ��ʽ����ת��
#if 0
class A
{
public:
	explicit A(int a)
		:_a(a) {}
	operator int()
	{
		return _a;
	}
protected:
	int _a;
};

int main()
{
	//��������ת�����Զ������ͣ�
	//A aa1 = 1;//������ʵ����ʽ����ת��������1����+�������� -- ���Լ�explicit���ܲ�����
			  //������ʵ�ϱ��������Ż���һ������
	A aa1(1);

	//�������Ҫ֧��һ���Զ�������ת������������
	//����һ��operator int -- ������֧����
	int i = aa1;
	return 0;
}
#endif

//������ʵ��
//�ղ�while(cin>>str)������ʵ��������һ��operator bool
//���Կ��Ա�ת����bool����


//C++���ļ���

struct ServerInfo
{
	char _address[20];
	int _port;
};

#if 0
int main()
{
	ifstream ifs("test.cpp");
	char ch = ifs.get();
	while (ifs)
	{
		cout << ch;
		ch = ifs.get();
	}
	//����Ҫ��ʽclose����Ϊ���Ƕ��󣬿����Զ���������
	return 0;
}
#endif


struct Date
{
	int year;
	int month;
	int day;
	friend istream& operator>>(istream& cin, Date& d)
	{
		cin >> d.year >> d.month >> d.day;
		return cin;
	}
	friend ostream& operator<<(ostream& cout, const Date& d)
	{
		cout << d.year << "��" << d.month << "��" << d.day << "��" << endl;
		return cout;
	}
};
int main()
{
	ifstream ifs("test.txt");
	int i;
	string s;
	double d;
	Date de;//�������C++�����ƣ��Զ�������Ҳ����
	ifs >> i >> s >> d >> de;
	cout << i << " " << s << " " << d << " " << de << endl;
	return 0;
}