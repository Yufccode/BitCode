#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

/// ��������غ���
///�κ�һ���ֻ࣬��Ҫдһ��>��==���ɣ�����ȫ�����ü��ɣ�
bool Date::operator==(const Date& x2) {
	return this->_year == x2._year
		&& this->_month == x2._month
		&& this->_day == x2._day;
}
bool Date::operator!=(const Date& d) {
	return !(*this == d);//���þ���
}
bool Date::operator<(const Date& d) {
	return !(*this >= d);//С�ھ��Ǵ��ڵ��ڵķ�
}
bool Date::operator>(const Date& d) {
	if (_year > d._year)return true;
	else if (_year == d._year && _month > d._month)return true;
	else if (_year == d._year && _month == d._month && _day > d._day)return true;
	else return false;
}
bool Date::operator<=(const Date& d) {
	return !(*this > d);
}
bool Date::operator>=(const Date& d) {
	return (*this == d) || (*this > d);
}
Date& Date::operator+=(int day) {
	//���ж�day�����Ļ��Ǹ���
	if (day < 0) {
		return *this -= -day;
	}

	//�߼�����ֱ�Ӽ���˵���������ж����ڵĺϷ��� -- ��Ȼ�����ǻ���Ҫ֪��ÿ���¶����죬�ǲ������� 
	//��Ȼ��Щ����easy
	_day += day;
	//�ж��Ƿ�Ϸ�����Ȼ������дһ��is_Valid()ȥ�ж�
	while (_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13) {
			_month = 1;
			_year++;
		}
	}
	/// ���ڵ������ǣ�_year��Щ�������Ǹ���˭�ģ���this�ģ��������Ƿ���*this
	return *this;
	///�ܲ������÷��أ� -- ���˺�����*this�����𣬻��ڣ����Է�������
}
Date Date::operator+(int day) {
	//�Լ��ǲ��ı�ģ� -- ����һ���ֲ����󼴿�
	Date ret(*this);
	//Date ret=*this �����ǿ������죬���Ǹ�ֵ����Ϊret��û����ʼ�������ret=*this������Ǹ�ֵ
	ret += day;
	return ret;
	///�������������ret�����ˣ����Բ������÷���
}
Date& Date::operator++() {
	///ǰ��
	*this += 1;
	return *this;//������������ -- ���÷���
}
Date& Date::operator++(int) {
	///����
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date Date::operator-(int day) {
	Date ret = *this;//��������
	ret -= day;
	return ret;
}
Date& Date::operator-=(int day) {
	if (day < 0) {
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0) {
		--_month;
		if (_month == 0) {
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date& Date::operator--() {//ǰ��
	*this -= 1;
	return *this;
}
Date& Date::operator--(int) {//����
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
int Date::operator-(const Date& d) {
	///�������
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d) {
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max) {
		++min;
		++n;
	}
	return n * flag;
}
//������������Ҫ��
#if 0
void Date::operator<<(ostream& out) {
	out << _year << "/" << _month << "/" << _day << endl;
}
#endif