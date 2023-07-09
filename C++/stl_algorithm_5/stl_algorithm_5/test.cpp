
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif


#include<algorithm>
#include<vector>
#include<array>
#include<iostream>
using namespace std;


//sortϵ��
void print_vector(const vector<int>& v)
{
	for (const auto& e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}
template<class iterator>
void print_vector(iterator begin, iterator end)
{
	while (begin != end)
	{
		cout << *begin++ << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int>a = { 1,3,2,7,9,5,4,6,8,10 };
	sort(a.begin(), a.end());
	print_vector(a);

	//stable_sort �ȶ�������
	vector<int>a2 = { 1,3,5,7,9,2,4,6,8,10 };
	stable_sort(a2.begin(), a2.end());
	print_vector(a2);

	//partial_sort
	//�������з�Χ[��һ�������һ�����е�Ԫ�أ�ʹ�м�֮ǰ��Ԫ����������Χ����С��Ԫ�أ�
	//�����������򣬶������Ԫ��û���κ��ض���˳��
	//��ֻ����ǰ�벿��
	vector<int>a3 = { 1,3,5,7,9,2,4,6,8,10 };
	partial_sort(a3.begin(), a3.begin() + 5, a3.end());
	print_vector(a3);

	//partial_sort_copy
	//��[first��last����Χ�ڵ���СԪ�ظ��Ƶ�[result_first��result_last����
	//�Ը��Ƶ�Ԫ�ؽ������򡣸��Ƶ�Ԫ��������result_firs��result_last֮��ľ�����ͬ�����������[first��last���е�Ԫ����������
	//û�㶮�Ǹ�ɶ��
	/*vector<int>a4 = { 1,3,5,7,9,2,4,6,8,10 };
	vector<int>res(10);
	partial_sort(a4.begin(), a4.end(), res.begin());
	print_vector(a4);*/ //err
}
//sortϵ��
void test2()
{
	//is_sorted �ж��Ƿ�������
	vector<int>a = { 1,2,3,4,5 };
	cout << is_sorted(a.begin(), a.end()) << endl;
	//is_sorted_until ���ط�Χ[first��last���в���ѭ����ĵ�һ��Ԫ�صĵ�����
	vector<int>a1 = { 1,2,3,4,5,2,3,1,3,4 };
	auto it = is_sorted_until(a1.begin(), a1.end());
	print_vector(it, a1.end());

	//nth_element
	//�������з�Χ[first��last]�е�Ԫ�أ���ʹ��n��λ�õ�Ԫ��������������λ�ڸ�λ�õ�Ԫ�� -- ��û�㶮
	vector<int>a2 = { 1,8,7,6,5,4,3,9 };
	nth_element(a2.begin(), a2.begin() + 4, a2.end());
	print_vector(a2);
}

//���ֲ���ϵ��
//Ҫ�ڷ���/���������ϲ���
void test3()
{
	//lower_bound
	//����һ�����������õ�����ָ��Χ[first��last���еĵ�һ��Ԫ�أ���Ԫ�صıȽ�ֵ��С��val

	//upper_bound
	//����һ�����������õ�����ָ��Χ[first��last���бȽ�ֵ����val�ĵ�һ��Ԫ��

	//equal_range
	//�����ӷ�Χ�ı߽磬���ӷ�Χ������Χ��first��last��ֵ����val������Ԫ��
	vector<int>a = { 1,2,3,4,4,4,4,5,6,7,8,9 };//��Ҫ����������
	pair<vector<int>::iterator, vector<int>::iterator>p = equal_range(a.begin(), a.end(), 4);
	print_vector(p.first, p.second);

	//binary_search ���ֲ���
	//�ҵ��� -- ����true�����򷵻�false
	cout << binary_search(a.begin(), a.end(), 4) << endl;
}

//mergeϵ��
//����Ҫ����
void test4()
{
	//merge
	//������Χ[first1��last1����[first2��last2���е�Ԫ����ϳ�һ���µķ�Χ����result��ʼ������Ԫ�ض�������
	vector<int>a1 = { 1,3,5,7,9 };
	vector<int>a2 = { 0,2,4,6,8 };
	merge(a1.begin(), a1.end(), a2.begin(), a2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//inplace_merge
	//�ϲ���������������Χ��[��һ���м䣩��[�м䣬��󣩣������������ϵ�����Χ[��һ�����
	vector<int>a = { 1,3,5,7,9,2,4,6,8,10 };
	inplace_merge(a.begin(), a.begin() + 5, a.end());
	print_vector(a);

	//includes
	//�������Χ[first1��last1����������Χ[ffirst2��last2���е�����Ԫ�أ��򷵻�true
	//��Ҫ����������Ҫ����
	vector<int>a3 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>a4 = { 1,2,6,8 };
	cout << includes(a3.begin(), a3.end(), a4.begin(), a4.end()) << endl;

	//set_union  ����
	//Constructs a sorted range beginning in the location 
	//pointed by result with the set union of the two sorted ranges [first1,last1) and [first2,last2).
	print_vector(a1); print_vector(a2);
	a2.push_back(9);
	set_union(a1.begin(), a1.end(), a2.begin(), a2.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	//set_intersection ����
	set_intersection(a1.begin(), a1.end(), a2.begin(), a2.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	//set_difference -- � ����1�е�����2��û�е�Ԫ�� �����߲��
	set_difference(a1.begin(), a1.end(), a2.begin(), a2.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	//set_symmetric_difference -- ˫�߲ -- Ҳ���ǣ������� - ������
	set_symmetric_difference(a1.begin(), a1.end(), a2.begin(), a2.end(), ostream_iterator<int>(cout, " ")); cout << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
