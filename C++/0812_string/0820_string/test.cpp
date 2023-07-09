#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//string



//string ��7�����캯��
//default (1)  string();
//copy(2) string(const string & str);
//substri ng(3) string(const string & str, size_t pos, size_t len = npos); -- ���ֿ�������
//                                npos������Ǿ��ǿ�������󣨹������������������Ҳ�ǿ�������󣨿���һ���֣�������Կ��ĵ� 
//npos��һ����̬��Ա������static const size_t npos=-1  ��Ϊ����size_t���͵ģ�������ʵ��һ���ܴ��ֵ


//from c - string(4) string(const char* s);
//from sequence(5) string(const char* s, size_t n);
//fill(6) string(size_t n, char c);
//range(7) template <class InputIterator> string(InputIterator first, InputIterator last);
void test_string1() {
	string s1;
	string s2("hello string");
	cout << s1 << " " << s2 << endl;

	string s3(s2);//�������� -- ��������� -- �Ժ�ģ��ʵ�ֵ�ʱ���ѧ -- ��Ȼ����Ҳ����д�Ⱥ�
	//ע�⣺ size����\0

	//substring��������
	string s4(s2, 6, 5);
	cout << s4 << endl;

	//from sequence(5)
	string s5("hello world", 5);
	cout << s5 << endl;

	// fill(6)
	string s6(10, 'x');
	cout << s6 << endl;

	//����дҲ���ԣ� -- ��ʽ����ת�� -- ��Ͷ����֪ʶ -- ����explicit�Ͳ�����
	string s = "hello world";
	cout << s << endl;
}

//��ֵ
/*string(1)
string& operator= (const string& str);
c - string(2)
string & operator= (const char* s);
character(3)
string& operator= (char c);*/
void test_string2() {
	string s1;
	string s2 = "hello world!";//����+��������+�Ż�=ֱ�ӹ���
	
	//�������־��Ǹ�ֵ��
	s1 = s2;
	s1 = "xxxx";
	s1 = 'y';
}

//[] size length
void test_string3() {
	string s("hello world");
	//ע�⣬����Щ��װ�õ��࣬�����ǲ��ܿ��ײ�ģ�����˵����ȥ���ײ��char*_str;

	//operator[]
	cout << s[1] << endl;
	s[1] = 'x';
	cout << s << endl;

	//size
	for (size_t i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	//const ���ص�[]
	const string s2("hello world");
	//s2[0] = " ";//err


	//length
	//��ʵҲ���Ա��� -- �Ƽ���size

	//[]�����Խ�� -- �ڲ�����

	//at�Ĺ��ܺ�[]��һ�µ�
	//��[]�������� -- atԽ��֮������쳣
}

//������
//������ָ��Ķ����Ķ���
//�п��ܾ���ָ��
//�п��ܲ���ָ��
//�÷���ָ��һ��
void test_string4() {
	string s("hello");
	string::iterator it = s.begin();
	//auto it=s.begin()����Ҳ��
	while (it != s.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;


	//abcdefg\0
	//^ s.begin()
	//        ^  s.end()
	//list/map/setֻ���õ���������

	//����������������ͨ�õķ��ʷ�ʽ

	//��Χfor
	//���е������������÷�Χfor
	//��Χfor -- �Զ����� ���Զ��жϽ���
	for (auto ch : s) {
		ch++;//�����ǸĲ��˵� -- Ҫ�����ý��ܲ��ܸ�
		cout << ch << " ";
	}
	cout << s << endl;
	//��Χfor�ĵײ��ǵ�����

	for (auto& ch : s) {//�������ܸ�
		ch++;
		cout << ch << " ";
	}
	cout << s << endl;

}

//rbegin(),rend() -- ���������
void test_string5() {
	string s("hello");
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend()) {
		cout << *rit << " ";
		rit++;//����Ҳ��++����Ϊ�Ƿ��������
	}
	cout << endl;
	//����const������ -- ֻ�ܶ�����д
}//��Χforֻ���������������ֻ���÷��������


void test_string6() {
	//
	string s("hello");
	s.push_back(' ');
	s.push_back('w');

	s.append("orld");
	cout << s << endl;

	//+=����
	//�����ַ������ַ���
	s += 'h';
	s += " hello";
	cout << s << endl;
}


void test_string7() {
	string s("hello world");
	string str = " hello linux";
	s.append(str.begin(), str.end());
	cout << s << endl;
	s.append(++str.begin(), --str.end());
	cout << s << endl;
}


//����string������
void test_string8() {
#if 0
	string s = "hello world";
	cout << s.capacity() << endl;
#endif
	//string�����ݻ���
	//˼·��������s����push_back()��������capacity����¼����
	vector<int>string_capacity;
	string test_capacity;
	string_capacity.push_back(test_capacity.capacity());
	//��¼
	for (int i = 0; i < 100; i++) {
		test_capacity.push_back('c');
		if (test_capacity.capacity() != string_capacity[string_capacity.size() - 1]) {
			string_capacity.push_back(test_capacity.capacity());
		}
	}
	//��ӡ
	vector<int>::iterator it = string_capacity.begin();
	cout << *it;
	it++;
	while (it != string_capacity.end()) {
		cout << "->" <<*it;
		it++;
	}
	cout << endl;
	//15->31->47->70->105
	//����Ҳ���Կ���linux��
	/*a.out  code  Desktop  Documents  Downloads  Linux  Music  Pictures  Public  Templates  test.cpp  Videos
	[yufc@localhost ~]$ ./a.out
	0->1->2->4->8->16->32->64->128  -- ���ݻ����ǲ�һ����
	*/
	//˵�� -- �õ�ʱ���������ײ�ʵ�� -- ��������Ҫ�� -- ��������
	//��ͬƽ̨��ͬ�������ײ���ܻ��в�ͬ�ĵط�


	//��������ñ�������������˼·���ռ� -- ���ǿ�����reserve
	string s2;
	s2.reserve(1000);//���ռ�
	cout << s2.capacity() << endl;
	s2.resize(1000,'a');//���ռ�+��ʼ������������Ĭ�Ϸ�\0)
}

int main() {
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	test_string8();
	return 0;
}