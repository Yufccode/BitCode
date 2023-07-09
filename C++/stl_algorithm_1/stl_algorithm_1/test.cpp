
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include<algorithm>
#include<iostream>
using namespace std;
#include<vector>
#include<array>
#elif
#endif


//all_of
//any_of
//none_of
void test1() {
	//all_of �����������Ƿº��� -- ����ֵ�ǲ���ֵ
	//�жϵ�������������������Ƿ�ȫ�������������������ǵ����������ķº�����
	std::array<int, 8> foo = { 3,5,7,11,13,17,19,23 };
	if (std::all_of(foo.begin(), foo.end(), [](int i) {return i % 2; }))
		std::cout << "All the elements are odd numbers.\n";
	vector<int>foo2 = { 1,2,3,4,5,-1 };
	cout << all_of(foo2.begin(), foo2.end(), [](int i) {return i >= 0; }) << endl;//0
	cout << any_of(foo2.begin(), foo2.end(), [](int i) {return i < 0; }) << endl;//�����������Ƿ����С��0����
	cout << none_of(foo2.begin(), foo2.end(), [](int i) {return i > 100; }) << endl;//�����ǲ���û�д���100����
}

//for_each
void func(const int& a)
{
	cout << a << " ";
}
void func2(int& a)
{
	a *= 2;
}
void test2()
{
	//for_each
	//������fnӦ���ڷ�Χ[first��last]�е�ÿ��Ԫ�ء�
	vector<int>arr = { 1,2,3,4,5 };
	for_each(arr.begin(), arr.end(), func); cout << endl;
	for_each(arr.begin(), arr.end(), func2);
	for_each(arr.begin(), arr.end(), func); cout << endl;
}
void test3()
{
	//findϵ��
	vector<int>arr = { 1,2,3,4,5,1,2,3,9,5,6,7,8,10 };
	cout << *find(arr.begin(), arr.end(), 3) << endl;
	//find_if �ҵ���һ������������Ԫ�� -- ͬ��Ҳ�Ǵ��º���
	cout << *find_if(arr.begin(), arr.end(), [](int i) {return i == 10; }) << endl;//����������ӡҪע�⣬�������.end()
																				   //�����ûᱨ��
	cout << *find_if_not(arr.begin(), arr.end(), [](int i) {return i == 1; }) << endl;//���ص�һ�� �� ����1��Ԫ�صĵ�����
}
class mycomp
{
public:
	bool operator()(const int& i, const int& j)
	{
		return (i % j == 0);
	}
};
//find_end �� find_first_of �� adjacent_find
void test4()
{
#if 0
	vector<int> myvector{ 11, 22, 33, 100, 99, 101, 11, 22, 33 };
	int myarr[] = { 11, 22, 33 };
	vector<int>::iterator it = find_end(myvector.begin(), myvector.end(), myarr, myarr + 3);
	if (it != myvector.end())
	{
		cout << "Find��" << it - myvector.begin() << ",*it = " << *it << endl;
	}
	int myarr2[] = { 100, 99, 101 };
	it = find_end(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp());
	if (it != myvector.end())
	{
		cout << "Find��" << it - myvector.begin() << ",*it = " << *it;
	}
	cout << endl;


	//find_first_of
	//���ط�Χ[first1��last1������[first2��last2���е��κ�Ԫ��ƥ��ĵ�һ��Ԫ�صĵ�����������Ҳ���������Ԫ�أ�����������last1��
	vector<int>arr = { 100,2,3,4,5,6,7,8,9,102 };
	vector<int>foo = { 100,101,102,103 };
	if (find_first_of(arr.begin(), arr.end(), foo.begin(), foo.end()) != arr.end())
	{
		cout << *find_first_of(arr.begin(), arr.end(), foo.begin(), foo.end()) << endl;
	}
	else cout << "�Ҳ���" << endl;
#endif
	//adjacent_find
	/*
	�ڷ�Χ[first��last��������ƥ�����������Ԫ�صĵ�һ�γ��֣�
	����������Ԫ���еĵ�һ��Ԫ�ط��ص�������
	���û���ҵ�������Ԫ�ضԣ��򷵻�last��
	*/
	array<int, 11>arr = { 1,3,3,5,7,9,2,4,6,8,10 };
	auto it = adjacent_find(arr.begin(), arr.end());
	if (it == arr.end())cout << "�Ҳ���" << endl;
	else cout << *it << endl;
}

//countϵ��
void test5()
{
	//count
	//���ط�Χ[first��last]�бȽϵ���val��Ԫ������
	vector<int>arr = { 1,2,3,4,5,6,7,8,9,10 };
	cout << count(arr.begin(), arr.end(), 10) << endl;
	//count_if ��һ���º��������Ϸº��������ļ�����++ ���Ҳ���������
	cout << count_if(arr.begin(), arr.end(), [](int i) {return i > 5; }) << endl;//ͳ�ƴ���5�ĸ���
}
bool newpredicate(int m, int n)
{
	return(m == n);
}
void test6()
{
	//mismatch
	/*
	�����������һ�Բ�ƥ���Ԫ�أ����������ص�һ��������Ԫ�أ�ÿ�������ж���һ����
	��������е�����Ԫ�ض���ƥ�䣬��ú�������pair(first1��first2)
	����ö��е�����Ԫ��ƥ�䣬��ú�������last1�;�����ͬλ�õ�Ԫ�ط��ص��ڶ��������е�last1��
	*/
	std::vector<int> newvector;
	for (int m = 1; m < 6; m++)
		newvector.push_back(m * 10);
	int newints[] = { 10,20,80,320,1024 };
	std::pair<std::vector<int>::iterator, int*> newpair;
	newpair = std::mismatch(newvector.begin(), newvector.end(), newints);
	std::cout << "Out of the given elements the first mismatching pair is:" << *newpair.first;
	std::cout << " and " << *newpair.second << "\n";
	++newpair.first; ++newpair.second;
	newpair = std::mismatch(newpair.first, newvector.end(), newpair.second, newpredicate);
	std::cout << "The next pair of mismatching elements are:" << *newpair.first;
	std::cout << " and " << *newpair.second << "\n";
}
#include<set>
void test7()
{
	//equal
	//����Χ[first1��last1���е�Ԫ�����first2��ʼ�ķ�Χ�е�Ԫ�ؽ��бȽϣ����������Χ�е�����Ԫ�ض�ƥ�䣬�򷵻�true��
	vector<int>arr1 = { 1,2,3,4,5,6 };
	vector<int>arr2 = { 1,2,2,4,5,6 };
	cout << equal(arr1.begin(), arr1.end(), arr2.begin() ) << endl;
	/*
	* STL �е� equal �������ڱȽ��������У�����������еĳ�����ͬ�����Ҷ�ӦԪ�ض���ȣ�equal() �㷨�᷵�� true��
	*/
	set<int>s1 = { 1,2,3,2,1 };
	set<int>s2 = { 2,1,2,3 };
	cout << (s1 == s2) << endl;
}
void test8()
{
	//is_permutation �ж�һ�������Ƿ�����һ�����е�����
	vector<int>a1 = { 1,2,3,4,5 };
	vector<int>a2 = { 5,4,3,1,2 };
	cout << is_permutation(a1.begin(), a1.end(), a2.begin(), a2.end()) << endl;
}
void test9()
{
#if 0
	//searchϵ��
	/* search
	�ڷ�Χ[first1��last1��������[first2��last2����������еĵ�һ�γ��֣��������һ��Ԫ�ط��ص����������û�г��֣��򷵻�last1��
	*/
	//��ʵ������������
	vector<int>a1 = { 1,2,3,4,5,6,7 };
	vector<int>a2 = { 2,3,4 };
	auto it = search(a1.begin(), a1.end(), a2.begin(), a2.end());
	if (it == a1.end())cout << "�Ҳ���" << endl;
	else cout << *it << endl;
#endif
	vector<int>a1 = { 1,2,2,2,3,4,5,6,7 };
	auto it = search_n(a1.begin(), a1.end(), 3, 2);//��a1��������������2������У����ص�һ��2��λ�ã����û�У�����a1.end()
	if (it == a1.end())cout << "�Ҳ���" << endl;
	else
	{
		cout << *it << endl;
		it++;
		cout << *it << endl;
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}