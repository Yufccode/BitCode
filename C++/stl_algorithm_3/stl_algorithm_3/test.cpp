
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<array>
#include<random>
using namespace std;

void print_vector(const vector<int>& a)
{
	for (const auto& e : a)cout << e << " ";
	cout << endl;
}
template<class iterator>
void print_vector(iterator begin, iterator last)
{
	auto it = begin;
	while (it != last)
	{
		cout << *it << " "; it++;
	}
	cout << endl;
}

//removeϵ��
void test1()
{
	//remove
	vector<int>a = { 1,2,3,4,5,2,2,3,3,4 };
	//1 2 4 5 2 2 4 3 3 4
	auto last = remove(a.begin(), a.end(), 3);//ע�⣬������ͨ������������ɾ����
	print_vector(a);
	print_vector(a.begin(), last);//������ӡ���ǶԵ�
	//remove_if ��ǰ��ͬ������ -- ��һ���º���

	//remove_copy 
	//����Χ[first��last]�е�Ԫ�ظ��Ƶ���result��ʼ�ķ�Χ�����Ƚϵ���val��Ԫ�س��⡣
	//����ֵ��һ��ָ���Ʒ�Χĩβ�ĵ�������������[first��last���е�����Ԫ�أ����Ƚϵ���val��Ԫ�س��⡣
	//remove_copy_if
	vector<int>a2 = { 1,2,3,4,5,2,2,3,3,4 };
	remove_copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "), 3); cout << endl;//ɾ��3�������д�ӡ����
	remove_copy_if(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "), [](int i) {return i == 3; });//ɾ��3�������д�ӡ����
	cout << endl;//ע�⣬remove_copy��remove_copy_ifԭ�����ǲ����
}
//uniqueϵ��
void test2()
{
#if 0
	//uniqueϵ��
	//unique
	//�ӷ�Χ[first��last���е�ÿ��������ЧԪ������ɾ������һ��Ԫ�����������Ԫ�ء�//Ҫ�����Ĳ���ȥ�� -- ���Խ�����һ����
	vector<int>a = { 1,2,3,4,5,2,2,3,3,4 };
	sort(a.begin(), a.end());
	print_vector(a);
	auto it = unique(a.begin(), a.end());
	print_vector(a.begin(), it);//����������ӡ -- ���Ǹ���ɾ�� -- ����������һ�������� -- Ӧ���õ���������
#endif
	//unique_copy
	vector<int>a2 = { 1,2,3,4,5,2,2,3,3,4 };
	sort(a2.begin(), a2.end());
	unique_copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "), [](int a, int b) {return a == b; });//ȥ�غ��ӡ
}
//reverseϵ��
void test3()
{
	//reverse
	vector<int>a = { 1,2,3,4,5 };
	std::reverse(a.begin(), a.end());
	print_vector(a);
	//reverse_copy
	std::reverse_copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
}
//rotate
void test4()
{
#if 0
	//rotate
	vector<int>a = { 1,2,3,4,5 };
	rotate(a.begin(), a.begin() + 2, a.end());
	print_vector(a);
#endif
	//rotate_copy
	vector<int>a1 = { 1,2,3,4,5 };
	rotate_copy(a1.begin(), a1.begin() + 2, a1.end(), ostream_iterator<int>(cout, " "));
}
//shuffleϵ��
void test5()
{
#if 0
	//random_shuffle
	//����������з�Χ��first��last���е�Ԫ�ء�
	vector<int>a = { 1,2,3,4,5 };
	srand(time(nullptr));
	random_shuffle(a.begin(), a.end());//ÿ�����еĴ��ҷ�ʽ��һ���� -- ���Լ�һ��srand()�ȽϺ���
	print_vector(a);
#endif
	//shuffle
	//ʹ��g��Ϊ���������������������������з�Χ��first��last���е�Ԫ�ء�
	std::array<int, 5> foo = { 1,2,3,4,5 };
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));
	std::cout << "shuffled elements:";
	for (int& x : foo) std::cout << ' ' << x;
	std::cout << '\n';
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}