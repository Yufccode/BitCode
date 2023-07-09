#define _CRT_SECURE_NO_WARNINGS 1

#include"MyVector.h"
#include<iostream>
#include<vector>
using namespace std;

void PrintVector(yufc::vector<int>& v) {//��û��д���������ʱ������һ��Ҫ���õģ���Ȼǳ�������ͷ����λ������
	yufc::vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void PrintVector(const yufc::vector<int>& v) {
	yufc::vector<int>::const_iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void test_vector1() {
	yufc::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (int i = 0; i < v.size(); i++) {
		++v[i];
		cout << v[i] << " ";
	}
	cout << endl;
}
void test_vector2() {
	yufc::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	yufc::vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		(*it)--;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto& e : v) {
		e++;
		cout << e << " ";
	}
	cout << endl;

	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	PrintVector(v);
}
void test_vector3() {
	const yufc::vector<int>v;
#if 0 //�Ĳ��˵�
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
#endif
	PrintVector(v);
	//��Χfor��Ȼ��ɵ��ʽ���滻 -- ������Ҳ�ǻ����const��������
}
//������ʧЧ����
void test_vector4() {
	yufc::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.push_back(5); // ���Ƿ���  -- ԭ��4�����ݣ�insert֮��Ҫ���ݵ�ʱ�򣬾ͳ��������ˣ�
	//v.push_back(6);
	yufc::vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//
	auto p = find(v.begin(), v.end(), 3);
	if (p != v.end()) {
		v.insert(p, 30);

		//���ڲ��������������ʧЧ֮����ʵ���⻹��û�и��������
		//��Ϊ�ڲ���pos���²���Ӱ��p
		//����������ʹ�õ�ʱ��
		//��pλ�ò��������Ժ󣬲�Ҫ����p����Ϊp����ʧЧ��
		//��Ϊ����ʹ��STL��ʱ�򣬲��˽�ײ�����ݻ��ƣ������Ժ�����insert֮�󣬲�Ҫȥ����pλ�ã� -- ���ܻ�������

		//���ܷ��insert��һ�������ĳ�&���� -- ������Ҫ������ -- �ͿⱣ��һ�º�
		//��Ȼ���ǿ��ƽ�������� -- ���Ǹ��˿��ܻ������������� -- ���磬ͷ�壬�����봫v.begin();v.insert(v.begin(), 0);
		//�಻������Ϊ���Ͳ�ƥ��
#if 0
		cout << *p << endl;
		v.insert(p, 40);
#endif
	}
	PrintVector(v);
}
//erase��������ʧЧ��
//�������erase��ʧЧ�� -- ��֪��
//STL��û�й涨ʲô����
//��û��һ�ֿ��ܣ���size()<capacity()/2��ʱ����һ���ݣ����ݣ���ʱ�任�ռ䣩
//���������Ǹ�����ʣ����Ǹ�p�����ˣ�
void test_vector5() {
	yufc::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	auto p = find(v.begin(), v.end(), 3);
	if (p != v.end()) {
		v.erase(p);
	}
	PrintVector(v);
}
void test_vector6() {
	yufc::vector<int>v;
#if 0
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
#endif
	//���1��2
	//���Ƿ��ִ�ʱ�����5 -- ����������û�� -- ����
#if 1
	//���3
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
#endif
	//Ҫ��ɾ�����е�ż��
	auto it = v.begin();
	//���3��ʱ��it������end()��ֱ�Ӽ��������� -- ����
	//������������㷨�ǲ���ȷ�ģ�
	//��ʵ���ǿ�Դ������Է��� -- erase���з���ֵ�� -- �����һ�µ�����
	//STL�涨erase����ɾ��λ����һ��λ�õĵ�������
	//vs����������ǲ�ĺ��ϸ�� -- erase֮������ȥ���ʣ� -- ���ʾͱ���
	//Linux�¾Ͳ�ͬ
	while (it != v.end()) {
		if (*it % 2 == 0) {
			it = v.erase(it);//����Ҫ����һ��it����
		}
		else {
			++it;
		}
	}
	PrintVector(v);
}
//�ܽ�
//��ʵ������ʧЧ���������Լ���OJ��ʱ��Ҳ�����ģ��������ɾ��֮�󣬵�����ָ����������ָ��ĵط�
//��ʹ��vector�ĵ�������ʱ��Ҫ����ԣ�

void test_vector7() {
	//ϵͳĬ�ϵĿ���
	//1.�Զ������� -- ���������� -- Ĭ�����ɵ� -- ǳ����
	//2.�������� -- ֵ���� -- ǳ����
	yufc::vector<int>arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
	yufc::vector<int>arr2 = arr;
	//����ϵͳĬ�ϵĻ�����ǳ��������������϶�������� -- ����������
	//���������ǳ��������һ�ߵ�ֵ��һ��Ҳ�ᱻ�ı�
	arr2[0] = 100; //���߶��ᱻ�ı�� -- ����������Ҫ�����
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : arr2) {
		cout << i << " ";
	}
}
void test_vector8() {
	string s("hell");
	yufc::vector<int>vs(s.begin(), s.end());
	for (auto i : vs) {
		cout << i << " ";
	}
	cout << endl;
	//��ֵ
	yufc::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vs = v;//Ҫʵ��һ�����
	//��Ȼ�����f11 -- �������Ƚ�ȥ�����ģ���Ϊ����Ҫ����
	//���꿽���ͽ�ȥ��ֵ��
	for (auto i : vs) {
		cout << i << " ";
	}
}
//��ʵ��������Ҳ�й���
void test_type() {
	int i = 0;
	int j = int();
	int k = int(10);
}
void test_vector9() {
	//vector<int>v = { 1,2,3,4,5 };
	vector<int>v(10);
	yufc::vector<int>v(10, 1);//�����ͱ�����,�������������������int
	//������������ƥ�����⣬��ƥ�䵽����ȥ�ĵط�ȥ��
	//Ϊʲô -- ��Ϊ���������乹���Ǹ����������ʺ��������� -- ���Խ�������ȥ��
	//�����
	//1.���ε�ʱ��д(10u,1)��ʾ����Ǹ�usigned int����
	//2.��vector(size_t n,const T&val=T())�����size_t�ĳ�int��Ҳ���Խ�� -- ����stl�ٷ�������size_t
	//3.����һ�ݣ��ĳ�int��Ū�����ؾ��� -- stl_3.0�����������
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}
void test_vector10() {
	yufc::vector<int>v;
	v.resize(10, 1);
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	yufc::vector<int>v1;
	v1.reserve(10);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.resize(8, 8);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;

	v1.resize(20, 20);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;

	v1.resize(3);
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;
}


//vector��ĿǰΪֹ�������һ���ӻ�û�н��
//�������Լ���vector����һ���������
class Solution {
public:
	yufc::vector<yufc::vector<int>> generate(int numRows) {
		yufc::vector<yufc::vector<int>> ret(numRows);
		for (int i = 0; i < numRows; ++i) {
			ret[i].resize(i + 1);
			ret[i][0] = ret[i][i] = 1;
			for (int j = 1; j < i; ++j) {
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}
		return ret;
	}
};
void test_vector11() {
	Solution().generate(10);
	//���� -- �ں���������ʱ�������
	//�޸�һ�� -- �Ѻ����ĳ�void���ͣ���return -- û����
	//Ϊʲô��
	//������������ -- ��ͨ��vector���û���� -- ��������������
	//������ǳ���������������
	// //            //�������ǵ�vector������� -- ����������Զ�������û�������������������������
	//���ǿ�����ʱ������Ŀռ����������������Ķ���������ָ����ǰ�ĵط�
	//��ͳд������Ϊmemcpy���µ� -- ���ǽ�memcpy�ĳ�һ��һ����ֵ�����ˣ������Ļ��Զ�������Ҳ�����������������Լ���deepcopy����
	//�ִ�д������Ϊ��ΪҪ����push_back()����push_back()�������reserve(),��reserve()�����memcpy������
}
int main() {
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	//test_vector7();
	//test_vector8();
	//test_type();
	//test_vector9();
	//test_vector10();
	test_vector11();
	return 0;
}


//����һ��Ҫ����һ���㣺
//STLֻ��һ���淶
//����淶��ôȥʵ�֣���û�й涨�ģ�
//VS-PJ��   g++ SGI��