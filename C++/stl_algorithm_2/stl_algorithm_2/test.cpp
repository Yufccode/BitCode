
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include<algorithm>
#include<unordered_map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;

void print_vector(vector<int>& v)
{
	for (const auto& e : v)cout << e << " ";
	cout << endl;
}
//copyϵ�к�moveϵ��
void test1()
{
	//copy
	vector<int>a1 = { 1,2,3,4,5 };
	copy(a1.begin(), a1.end(), ostream_iterator<int>(cout, " "));//�������������
	cout << endl;
	copy_n(a1.begin(), 2, ostream_iterator<int>(cout, " "));//����ǰn�����������
	//copy_n(a1.begin(), 10, ostream_iterator<int>(cout, " "));//���˻ᱨ��
	cout << endl;
	copy_if(a1.begin(), a1.end(), ostream_iterator<int>(cout, " "), [](const int& a) {return a > 2; });//��������2�ĵ��������
	cout << endl;
	//copy_backward -- ���򿽱� -- ��Ҫ˫������� -- Ҫ�õ�ʱ��ȥ�� -- �����ò���
	//move �� move_backward ��copy�÷�Ӧ�������Ƶ�
	/*
	[first��last����Ԫ�ص�ֵ�����ݸ�resultָ���Ԫ�ء����ú�[first��last����Χ�е�Ԫ�ؽ�����δָ������Ч��״̬��
	*/
}

//swapϵ��
#include<array>
void test2()
{
	//swap
	//swap_ranges
	/*
	����Χ[first1��last1���е�ÿ��Ԫ�ص�ֵ�����first2��ʼ�ķ�Χ�е���ӦԪ�ص�ֵ������
	*/
	vector<int>a1 = { 1,2,3,4,5 };
	vector<int>a2 = { 5,4,3,2,1,1 };
	swap_ranges(a1.begin(), a1.end(), a2.begin());//�����ʱa2Ԫ�ر�a1�ٵ�ʱ��ᱨ��
	for (const auto& e : a1)cout << e << " ";
	cout << endl;
	for (const auto& e : a2)cout << e << " ";
	cout << endl;

	//iter_swap
	//����a��bָ���Ԫ�ء�
	array<int, 3>b1 = { 1,2,3 };
	array<int, 3>b2 = { 100,2,1 };
	auto it1 = b1.begin();
	auto it2 = b2.begin();
	iter_swap(it1, it2);
	for (const auto& e : b1)cout << e << " ";
	cout << endl;
	for (const auto& e : b2)cout << e << " ";
	cout << endl;
}
void test3()
{
	//tranform
	//������˳��Ӧ����һ��1����������2������Χ��Ԫ�أ���������洢�ڴӽ����ʼ�ķ�Χ�С�
	vector<int>a = { 1,2,3,4 };
	transform(a.begin(), a.end() - 1, ostream_iterator<int>(cout, " "), [](int& a) {a *= a; return a; });
}

//replaceϵ��
void test4()
{
	//replace
	//��new_value������Χ[first��last]����old_value��ȵ�����Ԫ�ء�
	vector<int>a = { 1,2,3,4 };
	replace(a.begin(), a.end(), 2, 3);//��2ȫ������3 -- �Ҳ����Ͳ��滻
	// 1 3 3 4
	print_vector(a);
	//replace_if ���������Ļ���
	replace_if(a.begin(), a.end(), [](int i) {return i == 3; }, 2);//�����е�3����2
	// 1 2 2 4
	print_vector(a);
	//replace_copy
	replace_copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "), 2, 3);//�����е�2����3��Ȼ���Ƶ��������
	cout << endl;
	//replace_copy_if ͬ��
}

//fill �� generate ϵ��
void test5()
{
	//fill
	//��val������Χ[first��last]�е�����Ԫ�ء�
	vector<int>arr(10);
	fill(arr.begin(), arr.end(), 5);
	print_vector(arr);
	//fill_n ָ��������
	vector<int>a2(10);
	fill_n(a2.begin(), 10, 1);//Խ��ᱨ��
	print_vector(a2);

	//generate
	//����������gen���ص�ֵ�������Χ[first��last���е�Ԫ�ء�
	vector<int>a3(10);
	generate(a3.begin(), a3.end(), []() { //��1~10��ֵ��a3
		static int i = 1;
	return i++;
		});
	//1 2 3 4 5 6 7 8 9 10
	print_vector(a3);
	//generate_n
	//����������gen���ص�ֵ�����firstָ������е�ǰn��Ԫ�ء�
	vector<int>a4(10);
	generate_n(a4.begin(), 5, []() {static int i = 1; return i++; }); //�ڶ�������Խ��ᱨ��
	//1 2 3 4 5 0 0 0 0 0
	print_vector(a4);
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