
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


void print_vector(const vector<int>& v)
{
	for (const auto& e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}
template<class iterator_type>
void print_vector(iterator_type start, iterator_type end)
{
	while (start != end)
	{
		cout << *start++ << ' ';
	}
	cout << endl;
}
void test1()
{
#if 0
	//is_partitioned
	//Returns true if all the elements in the range [first,last) for which pred returns true precede those for which it returns false.
	//�ж��Ƿ�����true�Ķ���false��ǰ��
	vector<int>a = { 10,1,2,3,4,5,6,7,8,10 };
	cout << is_partitioned(a.begin(), a.end(), [](int i) {return i < 5; }) << endl;

	//partition
	//�������з�Χ[first��last���е�Ԫ�أ�ʹpred����true������Ԫ�ض����䷵��false������Ԫ��֮ǰ��
	//	���������ص�Ԫ��ָ��ڶ���ĵ�һ��Ԫ�ء�
	auto it = partition(a.begin(), a.end(), [](int i) {return i <= 5; });
	print_vector(a);
	print_vector(it, a.end());

	//stable_partition
	//��partitionһ�� -- ����������ȶ��� -- ����ԭ����˳��
	vector<int>a2 = { 10,1,2,3,4,5,6,7,8,10 };
	stable_partition(a2.begin(), a2.end(), [](int i) {return i <= 5; });
	print_vector(a2);

	//partition_copy
	//Copies the elements in the range [first,last) for which pred returns true into the range pointed by result_true, 
	//and those for which it does not into the range pointed by result_false.
	//��ʵ���ǰ�true�ĺ�false�ķֿ���
	vector<int>a = { 1,3,5,7,2,4,6,8,10,9 };
	vector<int>res1(10);
	vector<int>res2(10);
	partition_copy(a.begin(), a.end(), res1.begin(), res2.begin(), [](int i) {return i <= 5; });
	print_vector(res1); print_vector(res2);
#endif
	//partition_point
	//���ص�һ����Ϊtrue�ĵ�
	vector<int>a = { 1,2,3,4,5,6 };
	auto it = partition_point(a.begin(), a.end(), [](int i) {return i % 2 == 1; });//����ԭ����˳�򲻱�
	cout << *it << endl;
	print_vector(a);
}
int main()
{
	test1();
	return 0;
}