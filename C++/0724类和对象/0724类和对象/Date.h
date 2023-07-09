#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



/// <summary>
/// һ���ൽ�׿������ض���������أ� -- ����Щ��������������������
/// </summary>
class Date
{
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
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
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
	
private:
	int _year;
	int _month;
	int _day;
};