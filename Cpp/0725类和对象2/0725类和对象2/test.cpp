#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cassert>
using namespace std;

//const��Ա
//��const���ε����Ա������֮Ϊconst��Ա������const�������Ա������ʵ�����θó�Ա����������this
//ָ�룬�����ڸó�Ա�����в��ܶ�����κγ�Ա�����޸ġ�
//һ��ʼd2�಻����ԭ����ʵ����Ȩ�޵ķŴ�
#if 0
class Date
{
public:
	Date() {}
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display()const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
};
void Test()
{
	Date d1;
	d1.Display();
	
	const Date d2;
	d2.Display();//����Ȩ�޵ķŴ�
}
int main() {
	Test();
	return 0;
}
#endif
//���øı��Լ��ĺ�����������const����
//��ס -- const���ε���thisָ�� ָ������� ��֤���������޸ĳ�Ա�ڲ��ı���
//���� -- const����ͷ�const���󶼿��Ե��������Ա����



//ȡ��ַ��constȡ��ַ����������
#if 0
class A {
public:
	A* operator&() { //һ����const һ��û�� �ǿ������ص� -- ��������ȥ����ƥ����Ǹ�
		return this;
	}
	const A* operator&()const {
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif
//������Щʱ����const��ûconst�����Ƕ�Ҫд��Ҫ�������ز���
//����ȡ��ַ�����أ���const��ûconst�ķ��صĶ����ǲ�һ����
//������Ĭ�ϳ�Ա���������ǲ�д���������Զ����ɣ��Զ����ɾ͹����ˣ�����һ�㲻��д
//���ⳡ���������ñ���ȡ��������͵ĵ�ַ -- �����Ǿ��Լ�д�����ؿ�ָ�����ɶ�ľ��У�������this����


//ϰ�⣺��1+2+3+.....n
#if 0
class Sum {
public:
	Sum() {
		sum += i;
		i++;
	}
};
static int i = 0;
static int sum = 0;
class Solution {
public:
	int Sum_Solution(const int n) {
		Sum a[n];//����n��Sum�Ĺ��캯��
		return sum;
	}
};
#endif