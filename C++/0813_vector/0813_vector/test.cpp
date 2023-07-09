#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>
using namespace std;

//��������ռ����Լ�д�ĺϲ�
namespace std {
	//��ӡ˳���
	void PrintVector(vector<int>v) {
		for (size_t i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	//����
	void test_vector1() {
		vector<int> v1;//����
		vector<int> v2(10, 1);//��10��1����
		vector<int> v3(v1);//��������
	}
	//
	void test_vector2() {
		vector<int> v1;//����
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//�±�+[]
		for (int i = 0; i < v1.size(); i++) {
			v1[i]++;
		}
		for (size_t i = 0; i < v1.size(); i++) {
			cout << v1[i] << " ";
		}
		cout << endl;
		//������
		vector<int>::iterator it = v1.begin();
		while (it != v1.end()) {
			(*it)--;//�����޸�
			cout << *it << " ";
			++it;
		}
		cout << endl;
		//const������ -- ֻ����д
		//�����������һ����

		//��Χfor
		for (auto e : v1) {
			cout << e << " ";
		}
		cout << endl;
	}
	//���ݻ������ǿ����Լ�д��������vs��g++������
	void test_vector3() {
		vector<int> v1;//����
		v1.reserve(100);
		cout << v1.capacity() << endl;
	}
	//vector������û��ʵ��find�ģ������string��ͬ��string���������ַ������ִ�
	//vector/list��Щȥ�����ݣ������ڵ�������������ȥ�ҵ�
	//#include<algorithm> -- ����������find���� -- ���������������
	//insert
	void test_vector4() {
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//����Ҫ��3ǰ�����һ��30
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);//����3
		//find����Ҳ��������ص��Ǹ����������λ�ã�����ҿ��� -- ��������Ҳ��������ص���v1.end()
		//���ص���һ������������
		if (pos != v1.end()) {
			//��鷵��ֵ
			v1.insert(pos, 30);
		}
		for (size_t i = 0; i < v1.size(); i++) {
			cout << v1[i] << " ";
		}
		cout << endl;
	}
	//erase -- ɾ��ĳ��λ��/ɾ��ĳ������������
	void test_vector5() {
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//����Ҫɾ��3
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end()) {
			//��鷵��ֵ
			v1.erase(pos);
		}
		PrintVector(v1);


		//ɾ��һ������
		v1.erase(v1.begin(), v1.end() - 2);
		PrintVector(v1);
	}
	void test_vector6() {
		//����
		vector<int>v = { 4,5,1,2,7,8,10,2,3 };
		//sort -- ����
		//���������������
		sort(v.begin(), v.end());
		PrintVector(v);
		//���� -- �º������ȵ�stack��queue��ȥ��
		less<int>ls;// ����
		greater<int> gt;// ����
		//sort(v.begin(), v.end(), ls);
		sort(v.begin(), v.end(), greater<int>());//����дҲ���� -- ��������
		PrintVector(v);

		vector<string>strV;
		strV.push_back("1234");
		strV.push_back("2345");
		//Ϊʲô����Ҫ������
		//��Ϊvector��������string����
		//����������ã���Ҫ���ÿ�������ģ��������
		for (const auto& str : strV) {
			cout << str << endl;
		}
	}
}
int main() {
	//std::test_vector1();
	//std::test_vector2();
	//std::test_vector3();
	//std::test_vector4();
	//std::test_vector5();
	std::test_vector6();
	return 0;
}