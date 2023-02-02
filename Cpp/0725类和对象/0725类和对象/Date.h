#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cassert>
using namespace std;



/// <summary>
/// һ���ൽ�׿������ض���������أ� -- ����Щ��������������������
/// </summary>
class Date
{
	//��Ԫ���� -- ��������ڲ�����ʹ��Date�������˽�б�����Ա
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in,Date& d);
public:
	//�ж�����
	bool IsLeapYear(int year) {
		//����д��
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))return true;
		return false;
	}
	//���ÿ���µ�����
	int GetMonthDay(int year, int month) {
		static int days[] = { NULL, 31,28,31,30,31,30,31,31,30,31,30,31 };
		//���дһ��static�ɣ���Ϊ���days[]���ܻᱻƵ���ĵ��ã�����Ҫÿ�ζ���һ��days[]��������һ���ظ��þ���
		if (month == 2 && IsLeapYear(year))return 29;
		return days[month];
	}
	bool is_DateValid() {
		if (_year >= 1 && _month > 0 && _month < 13 && _day>0 && _day <= GetMonthDay(_year, _month))return true;
		return false;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		assert(is_DateValid());
	}
#if 0
	Date(const Date& d)///��ʵ�ǲ���Ҫ�Լ�д��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "�����˿�������" << endl;
	}
#endif
	/// Ϊ�˺��淽�㿴��� -- дһ��Print()
	void Print() {
		cout << "����Ϊ:" << this->_year << "/" << this->_month << "/" << this->_day << endl;
	}
	/// ��������غ���
	bool operator==(const Date& x2);
	bool operator!=(const Date& x2);
	bool operator<(const Date& x2);
	bool operator>(const Date& x2);
	bool operator<=(const Date& x2);
	bool operator>=(const Date& x2);
	//��ֵ������Ҫ�Լ�д��
	//Date& operator=(const Date& d);
	//���ڼ�����
	Date& operator+=(int day);
	Date operator+(int day);
	//++ ���ٵ����� -- ����ǰ�úͺ���
	//ֱ�Ӱ��������أ��޷�����
	//���⴦��ʹ���������֣�����++��������һ������int������ǰ�ù��ɺ������ؽ�������
	Date& operator++();///ǰ��
	Date& operator++(int);///����

	Date operator-(int day);
	Date& operator-=(int day);
	Date& operator--();
	Date& operator--(int);

	///����Ҫһ�����ڼ�����
	int operator-(const Date& d);

	//��������
#if 0
	void operator<<(ostream& out);
#endif
private:
	int _year;
	int _month;
	int _day;
};
//IO����
#if 0
ostream& operator<<(ostream& out, const Date& d);
#endif
//��Ϊ���������Ƶ���ĵ��ã�����Ū�������ȽϺ�
//ͬʱ�������������������룬����ֱ��ȫ��д��.h����ȽϺ�
inline ostream& operator<<(ostream& out, const Date& d) {
	out << d._year << "/" << d._month << "/" << d._day << endl;
	//���Ƿų����� -- ���ʲ���˽�е�
	//1.дGetMonth()�Ⱥ���
	//2.Ū�ɹ���
	//3.��Ԫ����������������������˽�����ԣ�
	return out;
	//����ֵ����Ҫ���ϣ�����Ͳ�����������ͬһ�е�<<��
}
//˳�������ȡҲд��
inline istream& operator>>(istream& in,Date& d) {//���ܼ�const����Ȼ�Ĳ�����
	in >> d._year >> d._month >> d._day;
	assert(d.is_DateValid());
	return in;
}
//�������Ҫ�����ڣ���������ܼ��Ĺ��ܣ�Ҳ����ʵ�֣�
//�ȸ���һ����׼��Ȼ���������ڼ����ڵĹ���֮�󣬼�һ�£��������˼������ڼ���

/*
ע�⣺
1.����ͨ���������������������µĲ�����������operator@
2.���ز�����������һ�������ͻ���ö�����͵Ĳ�����
3.�����������͵Ĳ��������京�岻�ܸı䣬���磺���õ�����+���� �ܸı��京��
4.��Ϊ���Ա�����غ���ʱ�����βο������Ȳ�������Ŀ��1��Ա�����ģ�thisָ���ԭ��
5.��������һ��Ĭ�ϵ��β�this���޶�Ϊ��һ���β�
.* ��:: ��sizeof ��?: ��. ע������5��������������ء���������ڱ���ѡ�����г��֡� 
*/