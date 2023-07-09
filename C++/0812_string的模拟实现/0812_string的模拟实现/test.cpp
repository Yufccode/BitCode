#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"MyString.h"
using namespace std;
//using namespace MyString;
void test1() {
	try {
		MyString::string s1 = "hello";
		cout << s1.c_str() << endl;
		for (int i = 0; i < s1.size(); i++) {
			cout << s1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < s1.size(); i++) {
			s1[i]++;
		}
		for (int i = 0; i < s1.size(); i++) {
			cout << s1[i] << " ";
		}
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

void test2() {
	try {
		MyString::string s1 = "hello";

		MyString::string::iterator it = s1.begin();
		while (it != s1.end()) {
			cout << *it << " ";
			(*it) = 'a';//��д
			it++;
		}
		cout << endl;

		//��ΧforҲ֧�� -- �������Զ���ɵ�����
		for (auto ch : s1) {
			cout << ch << " ";
		}
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}
void test3() {
	try
	{
		MyString::string s1("hello world");
		MyString::string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

#if 0
		bit::string s3 = "hello Linux";
		s1 = s3;//���������Ҫ�Լ�ʵ�ֵ�
		//���������ڴ��й¶��
		//����Ĭ�ϵĻ��s1�ĵ�ַȥָ��s3��s1ԭ��ָ��Ŀռ�й¶�� -- ����Ҫʵ��һ�������ֵ
#endif
		MyString::string s4="1111111111111112";
		s1 = s4;
		cout << s1.c_str() << endl;
		cout << s4.c_str() << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
void test4() {
	try
	{
		MyString::string s1("hello");
		cout << s1.c_str() << endl;
		s1.push_back('h');
		cout << s1.c_str() << endl;
		s1 += 'n';
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
		s1 += 'n';
		s1 += 'n';
		s1 += 'n';
		s1 += 'n';
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
void test5() {
	try
	{
		MyString::string s1("hello ");
		s1.append("world");
		cout << s1.c_str() << endl;
		s1 += ' ';
		s1 += "hello";
		s1.push_back(' ');
		s1 += "SQL";
		cout << s1.c_str() << endl;

		s1.insert(6, '#');
		cout << s1.c_str() << endl;

		s1.insert(0, '#');
		cout << s1.c_str() << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
void test6() {
	try
	{
		MyString::string s1("hello !");
		s1.insert(5, " Linux");
		cout << s1.c_str() << endl;
		s1.insert(0, "Linux ");
		cout << s1.c_str() << endl;
		s1.erase(0, 6);
		cout << s1.c_str() << endl;
		s1.erase(12, 1);
		cout << s1.c_str() << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
void test7() {
	MyString::string s1("hello!");
	cout << s1 << endl;
}
void test8() {
	MyString::string s1("hello");
	cin >> s1;
	cout << s1;
}
void test9() {
	MyString::string s1("hello");
	cout << s1.find("ll") << endl;
	cout << s1.substr(s1.find("ll"), strlen("ll"));
}
void test10() {
	std::string s1;
	s1.resize(20);//�������� -- Ĭ��'\0'

	std::string s2("hello");
	s2.resize(20, 'x');//�Ѿ��еĲ��䣬�����ȫ����ʼ����'x'

	s2.resize(10);//����10��

	MyString::string s11;
	s1.resize(20);//�������� -- Ĭ��'\0'

	MyString::string s22("hello");
	s22.resize(20, 'x');//�Ѿ��еĲ��䣬�����ȫ����ʼ����'x'

	s22.resize(10);//����10��
}
void test11() {
	//vs�µ�string����һЩ��һ���Ķ���
	string s1("1111111111");
	string s2("11111111111111111111111111111111111111111");
	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
	//������һ���� -- ����28��Ϊʲô����12�أ�������Ա
}
int main() {
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test11();
	return 0;
}