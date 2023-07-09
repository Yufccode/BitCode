
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;

void print(const vector<int>& v)
{
	for (const auto& e : v)cout << e << " ";
	cout << endl;
}
void print(const set<int>& s)
{
	for (const auto& e : s)cout << e << " ";
	cout << endl;
}

//heapϵ��
void test1()
{
	vector<int>a = { 1,2,3,4,5 };
	make_heap(a.begin(), a.end());//�Ȱ����д���ɶ�
	cout << is_heap(a.begin(), a.end()) << endl;
	print(a);
	a.push_back(6);//��ʱ��a�Ѿ����Ƕ���
	print(a);
	push_heap(a.begin(), a.end());//�����д���ɶ�
	print(a);
	//������Ҫ��ȡ����Ԫ��
	pop_heap(a.begin(), a.end());//��ʱ�öѶ�Ԫ�غ����һ��Ԫ�ؽ����������ѧϰ�ѵ�ʱ����Ǹ�������һ����
	print(a);
	cout << "------------" << endl;
	vector<int>a2 = { 1,5,3,9,7 };
	make_heap(a2.begin(), a2.end());
	sort_heap(a2.begin(), a2.end());//ע�⣬�����������һ��Ҫ��һ����
	print(a2);
	cout << "sort_heap()֮�󣬻��Ƕ���" << is_heap(a2.begin(), a2.end()) << endl;
	//is_heap_until
	//Returns an iterator to the first element in the range [first,last) which is not in a valid position 
	//if the range is considered a heap (as if constructed with make_heap).
	//���ص�һ�������϶����ʵ�Ԫ�أ����ȫ�����ϣ����ز�����Чλ�õĵ�����������.end()��
}
//min/maxϵ��
void test2()
{
	//min,max
	//minmax���ص���һ��pair
	cout << min(2, 4) << endl;
	cout << min({ 2,1,4 }) << endl;
	cout << minmax({ 2,1,4 }).first << " " << minmax({ 2,1,4 }).second << endl;
	cout << "-------------------------" << endl;
	set<int>s = { 1,2,3,4,5,6,7,8,9,10,0,11,-1 };
	cout << *max_element(s.begin(), s.end()) << endl;
	set<int>s2 = { 1,1 };
	cout << *max_element(s2.begin(), s2.end()) << endl;
	//minmax_element���ص���һ��pair ����װ���ǵ�����
	cout << *(minmax_element(s.begin(), s.end()).first) << ' ' <<
		*(minmax_element(s.begin(), s.end()).second) << endl;
}
//others
void test3()
{
	//lexicographical_compare
	//�����Χ[first1��last1�����ֵ��ϱȷ�Χ[first2��last2��С���򷵻�true
	string a = "abcdefg";
	string b = "aa";
	vector<int>v1 = { 1, 2, 3 };
	vector<int>v2 = { 1, 1, 1 };
	cout << lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()) << endl;
	cout << lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl;

	//next_permutation
	//����Χ��first��last���е�Ԫ����������Ϊ��һ���ֵ�ʽ��������С�
	next_permutation(v1.begin(), v1.end());
	print(v1);
	//prev_permutation
	//����Χ��first��last���е�Ԫ����������Ϊ��ǰ���ֵ�˳������
	prev_permutation(v1.begin(), v1.end());
	print(v1);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
