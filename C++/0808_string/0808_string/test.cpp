#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//string -- ��̬������char�ַ�����

//string
//wstring
//u16string
//u32string

//��ʵ�������Ǳ��������
//���ĵı��볣����������ϵ�� gbk utf-8
int main() {
	char a1[] = "hello";
	char a2[] = "����";
	char a3[] = { -79,-56,-52,-40,0 };
	cout << a3 << endl;

	a3[3]++;
	cout << a3 << endl;

	a3[3]++;
	cout << a3 << endl;	

	a3[3]++;
	cout << a3 << endl;

	//��ʵ�ǰ�ͬ���ֱൽһ���

	//��ʲô�ô��أ�
	//����
	//��Ҫ�����Ϸ�����
	//��ô�� -- ����Ĵʿ�
	//����ڴʿ����� -- ���****
	//ͬ������ô�� -- ���ֱ���ͺܷ�����
	return 0;
}