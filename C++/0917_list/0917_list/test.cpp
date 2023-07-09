#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<time.h>
using namespace std;
//list -- ˫��ѭ������
//��֧��operator[]
//��΢��һ���ĵ�������������

//ʹ��
void test_list1() {
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2); 
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	//������
	list<int>::iterator it = lt.begin();
	while (it != lt.end()) { //�������ɶ�Ҳ��д -- �ܼ�
		//�����������Щ -- ����һ����
		//front(),back()ȡͷ��β������
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : lt) {
		cout << e << " ";
	}
}
void test_list2() {
	//insert��erase
	//ͬ�� -- �����õ�����
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	//��3��ǰ�����һ��30
	auto pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end()) {
		lt.insert(pos, 30);
	}//�ϲ����� -- �ܼ�
	//�������ˣ�
	//pos�Ƿ��ʧЧ -- �����
	//����Ľṹ������ˣ�������˳��洢������
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
	//ɾ������
	auto pos1 = find(lt.begin(), lt.end(),30);
	if (pos1 != lt.end()) {
		lt.erase(pos1);//pos�᲻��ʧЧ -- ��ʧЧ������һ�¾�֪����
					   //�ܼ� -- �ڵ㶼��delete���ˣ������Ұָ������
	}
	for (auto e : lt) {
		cout << e << " ";
	}
}
void test_list3() {
	//��Щ����Ҫ�õ�ʱ��ȥ���ĵ�������
	//splice ת��
	//remove 
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(2);
	lt.push_back(5);
	lt.remove(2);//ɾȫ���� -- ���ĵ������ˣ���һ��Ҫ��
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
	//remove_if ��������ɾ
}
void test4() {
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(2);
	lt.push_back(5);
	//unique
	//unique ȥ�� -- ���������ȥ
	//һ��Ҳ�����������������ȥ����ʵ���۲�С
	// 
	//�Ժ���������setȥ��
	lt.sort();
	lt.unique();
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;

	
	//sort
	//Ϊʲô<algorithm>�Ѿ���һ��sort�ˣ����ﻹҪһ��sort��
	//<algorithm>��sortҪ������ռ�����Ҫ������
	//���ŵ�ʵ����Ҫ�����䣬��Ҫ����ȡ��
	// 
	//list::sort()ʹ�õĹ鲢������ʽ�ṹ�鲢�ռ���O(1)��
	lt.push_front(10);
	lt.sort();
	for (auto e : lt) {
		cout << e << " ";
	}
	//merge -- �鲢
	//��Щ���õķǳ���
}
//������n(�ܴ�)��������Ҫ������һ�ֺã�
//1.vector+algorithm::sort
//2.list+list::sort
//д����������һ��,��release��
//vector��
//������������Ҫ���ʵ�ʱ��vector����������Ե����ƾ������ֳ�����
void TestOP() {
	srand(time(0));
	const int N = 10000000;
	vector<int>v;
	v.reserve(N);
	list<int>lt1;
	list<int>lt2;
	for (int i = 0; i < N; i++) {
		auto e = rand();
		v.push_back(e);
		//lt1.push_back(e);
		lt2.push_back(e);
	}
	//������vector��������֮���ٿ�������
	int begin1 = clock();
	//for (auto e : lt1) {
	//	v.push_back(e);
	//}
	sort(v.begin(), v.end());
	//size_t i = 0;
	//for (auto& e : lt1) {
	//	e = v[i++];
	//}
	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	cout << "vectorSort" << " " << end1 - begin1 << endl;
	cout << "listSort" << " " << end2 - begin2 << endl;
}
int main() {
	//test_list1();
	//test_list2();
	//test_list3();
	//test4();
	TestOP();
	return 0;
}