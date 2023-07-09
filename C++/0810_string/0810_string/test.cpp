#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<cassert>
using namespace std;

//insert
void test_string1() {
	string str("wo lai le");
	//ÿ���ո��λ�ò���һ��%
	//������insert������Ч�ʵͣ���������
	//��Ҫ�õĲ���һ���ĵ�����
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			str.insert(i, "%20");//��������ѭ���ģ���Ϊi��������ˣ���һֱ������
			i += 3;
		}
	}
	cout << str << endl;

	//�ո�ĳ�%20
	//�ѿո�erase��
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			str.erase(i, 1);
		}
	}
	cout << str << endl;


	//Ҳ������.replace() -- �滻
	//�����ʱ��ֱ�Ӳ��ĵ�������
}

//c_str ����C
void test_string2() {
	string filename("hello world");
	//��Cȥ���ļ�

	FILE* pf = fopen(filename.c_str(), "r");
	assert(pf);

	//�����ߵ����岻��һ����
	cout << filename << endl;
	cout << filename.c_str() << endl;
}

void test_string3() {
	string filename("hello world");
	cout << filename << endl;
	cout << filename.c_str() << endl;

	filename += '\0';
	filename += "Hello Linux";
	cout << filename << endl;//string������sizeΪ׼
	cout << filename.c_str() << endl;//��\0Ϊ׼
}

//findϵ��
void test_string4() {
#if 0
	string filename("test.cpp");
	//�Һ�׺
	size_t pos = filename.find('.');
	if (pos != string::npos) {//npos�Ǿ�̬�� -- ����string::npos����ȡ
		string suff = filename.substr(pos,filename.size() - pos);
		//�ڶ���������дҲ�У������ҵ����� -- ������npos
		cout << suff << endl;
	}
#endif
	//��ʱ��������
	//��Linux�¾����������ļ���
	//test.bak.cpp.txt
	//����Ҫȡ��ĺ�׺��ô�죿����Ȼ��׺��Linux�²��Ǿ����ļ����͵Ķ�����
	//rfind
	string filename("test.cpp.bak.txt");
	//�Һ�׺
	size_t pos = filename.rfind('.');//��β��ʼ�ң�������
	if (pos != string::npos) {//npos�Ǿ�̬�� -- ����string::npos����ȡ
		string suff = filename.substr(pos, filename.size() - pos);
		//�ڶ���������дҲ�У������ҵ����� -- ������npos
		cout << suff << endl;
	}
}

//find�������÷�
void Deal(string url) {
	size_t pos1 = url.find("://");
	if (pos1 == string::npos) {
		cout << "�Ƿ�url" << endl;
		exit(-1);
	}
	//ȡЭ��
	string protocol = url.substr(0, pos1);
	cout << protocol << endl;
	//ȡ����
	size_t pos2 = url.find("/", pos1 + 3);//��pos1+3��λ�ÿ�ʼ��
	if (pos2 == string::npos) {
		cout << "�Ƿ�url" << endl;
		exit(-1);
	}
	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
	cout << domain << endl;
	//ȡ����
	string uri = url.substr(pos2 + 1);
	cout << uri << endl;
}
void test_string5() {
	string url1 = "https://cplusplus.com/string/string";
	string url2 = "https://leetcode.cn/problemset/all/";
	//������ַ��������
	//1.Э��
	//2.����
	//3.���ද������
	//������Ҫ�и��������
	Deal(url1);
}

void test_string6() {
	//����ת�ַ���
	int ival = 10;
	double dval = 10.11;
	string istr = to_string(ival);
	string dstr = to_string(dval);
	cout << istr << endl;
	cout << dstr << endl;
	//�ַ���ת����
	istr = "9999";
	dstr = "9999.99";
	ival = stoi(istr);
	dval = stod(dstr);
	cout << ival << " " << dval << endl;
	//�����Ĳ��ĵ����� -- ���ü�ס
}
int main() {
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	test_string6();
	return 0;
}