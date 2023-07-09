
#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#elif
#endif

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;


void print(const vector<int>& v)
{
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


//accumulate
/*
* template <class InputIterator, class T, class BinaryOperation>
   T accumulate (InputIterator first, InputIterator last, T init,
                 BinaryOperation binary_op);
	//���Դ�һ����Ԫ��������
*/
void test1()
{
	//���ش�[first��last����init��Χ������ֵ���ۻ����
	vector<int>a = { 1,2,3,4,5 };
	cout << accumulate(a.begin(), a.end(), 1, multiplies<int>()) << endl;
}
//adjacent_difference
void test2()
{
	//����������ĵ�Ҳ������ -- ����������ӡ�Ľ����ϸ��һ�¾��ܶ���
	//�������������в���
	//adjacent_differenceĬ��������������Ԫ�صĲ�
	//����Ҳ���Դ���Ԫ�ķº���
	vector<int> data{ 2,3,1,5,2,8,4,2 };
	cout << "ԭʼ����:" << endl;;
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	cout << "�����" << endl;;
	adjacent_difference(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "���" << endl;;
	adjacent_difference(data.begin(), data.end(), ostream_iterator<int>(cout, " "), plus<int>());//�ӷ�
	cout << endl;
	cout << "���" << endl;;
	adjacent_difference(data.begin(), data.end(), ostream_iterator<int>(cout, " "), multiplies<int>());//�˷�
}
//inner_product ���ڻ�
void test3()
{
	/*
	* ���ؽ�init���first1��first2��ʼ��������Χ��Ԫ����ɵĶԵ��ڻ���ӵĽ����
	*/
	vector<int>a = { 1,2,3,4 };
	vector<int>b = { 2,2,2,2 };
	//vector<int>b = { 2,2,2,2,2 };//���Ա�Ĺ�
	//vector<int>b = { 2 };//err
	cout << inner_product(a.begin(), a.end(), b.begin(), 0) << endl;
}
//partial_sum
void test4()
{
	/*
	* ��result��ʼ��Ϊ��Χ�ڵ�ÿ��Ԫ�ط��䷶Χ����ӦԪ�صĲ��ֺ�[first��last]
	*/
	//����һ��Ӧ�þ�����ǰ׺��
	//partial_sum �������� a,b,c,d �������� a,a+b,a+b+c,a+b+c+d
	vector<int>a = { 1,2,3,4,5 };
	partial_sum(a.begin(), a.end(), ostream_iterator<int>(cout, " ")); cout << endl;
}
//iota
void test5()
{
	/*
	* ��Χ��first��last���е�ÿ��Ԫ�ط���val������ֵ��������д��ÿ��Ԫ�غ���++val����һ��
	*/
	vector<int>a(10);
	print(a);
	iota(a.begin(), a.end(), -5);
	print(a);
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