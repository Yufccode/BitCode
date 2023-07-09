#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<numeric>
#include<queue>
#include<assert.h>
#include<map>
#include<set>

using namespace std;

#elif
#endif


//set
#if 0
void test1() {
	//set<int>s;
#if 0
#if 1
	int arr[] = { 1,2,1,6,3,8,5 };
	//���� + ȥ��
	set<int>s(arr, arr + sizeof(arr) / sizeof(int));
	set<int>::iterator it = s.begin();
	//����
	while (it != s.end()) {
		cout << *it << " ";
		it++;
		//*it = 3;//err ��֧�ָģ�key�ǲ��ܸĵ�
	}
	cout << endl;
	for (auto e : s) {
		cout << e << " ";
	}
	cout << endl;
#else
	int arr[] = { 1,2,1,6,3,8,5 };
	//���� + ȥ�� -- ����
	set<int, greater<int>>s(arr, arr + sizeof(arr) / sizeof(int));
	set<int>::iterator it = s.begin();
	//����
	while (it != s.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : s) {
		cout << e << " ";
	}
	cout << endl;
#endif
#endif
	int arr2[] = { 1,2,1,6,3,8,5 };
	//���� + ȥ��
	set<int>s2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	set<int>::iterator it = s2.begin();
	//����
	while (it != s2.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : s2) {
		cout << e << " ";
	}
	cout << endl;
	auto pos = s2.find(2);
	if (pos == s2.end())exit(-1);
	s2.erase(pos);
	for (auto e : s2) {
		cout << e << " ";
	}
}
void test2() {
	int arr[] = { 1,2,1,6,3,8,5 };
	set<int>s(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << s.count(2) << endl;//�ж��ڲ��ڿ���������
	cout << s.count(20) << endl;
	//count����ͨ��set���治��1����0 
	//count��ʵ��Ϊ��multiple_set��Ƶģ�����set��������������������ֵ����
}
void test3() {
	//lower_bound��upper_bound
	std::set<int> myset;
	std::set<int>::iterator itlow, itup;
	for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
	itlow = myset.lower_bound(30);				  //       ^
	//itlow = myset.lower_bound(35);                
	itup = myset.upper_bound(60);//70              //                   ^
	cout << "[" << *itlow << "," << *itup << "]" << endl;
	//�������ǿ��Եó� -- lower_bound���ص��Ǵ��ڵ���val��λ�õĵ�����
	//upper_boundҲ�ǷŻش���val��λ�õĵ�����
	
	//lower_bound�Ƿ��ش��ڵ��ڵ�
	//upper_bound���ص��Ǵ��ڵ�
	myset.erase(itlow, itup);                     // 10 20 70 80 90
	std::cout << "myset contains:";
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
void test4() {
	std::set<int> myset;
	for (int i = 1; i <= 5; i++) myset.insert(i * 10);   // myset: 10 20 30 40 50
	std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);
	ret = myset.equal_range(35);
	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}
int main() {
	//��Ҫ�������һ���� -- ���ۺܴ�
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
#endif


//multiset
//�÷���setû��ȥ��
#if 0
void print(multiset<int>& ms) {
	multiset<int>::iterator it = ms.begin();
	while (it != ms.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test1() {
	int arr[] = { 1,2,1,6,3,8,3,5,3 };
	//���� -- ����ȥ��
	multiset<int>s(arr, arr + sizeof(arr) / sizeof(arr[0]));
	print(s);
	cout << s.count(1) << endl;
	auto pos = s.find(3);//���ص�������ĵ�һ��3
	while (pos != s.end()) {
		cout << *pos << " ";
		++pos;
	}
	cout << endl;

	s.erase(3);//ɾ�����е�
	print(s);
}
int main(){
	test1();
	return 0;
}
#endif



//map
#if 0
void test1() {
	map<string, string>dict;
	//pair<string, string>kv1("sort", "����");
	//dict.insert(kv1);
	//����д̫������ -- ����ֱ������������
#if 0
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("test", "����"));
	dict.insert(pair<string, string>("string", "�ַ���"));
	dict.insert(pair<string, string>("string", "xxx"));//����϶��ǲ岻��ȥ��
	cout << endl;
#endif
	//��������дҲ�ܷ���
	//������make_pair -- ����һ������ģ��
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("test", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("string", "xxx"));

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end()) {
		//pair��û�������������
		cout << "key:" << it->first << "   val:" << it->second << endl;
		it++;
	}
	//����Ҳ����
	for (const auto& kv : dict) {
		//�ǵø�kv����& ��Ȼpair��Ҫ�������
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}
int main() {
	test1();
	return 0;
}
#endif



