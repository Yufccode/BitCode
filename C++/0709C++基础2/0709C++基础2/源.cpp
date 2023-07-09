#define _CRT_SECURE_NO_WARNINGS 1
//0709_bit_Cpp_introduction2

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//�������� -- �����޸ķ��صĶ���

//��ֵ���غʹ����÷��ص����ܶԱ�
#if 0
#include <ctime>
struct A { int a[10000]; };
A a;
// ֵ����
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2() { return a; }
void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main() {
	TestReturnByRefOrValue();
	return 0;
}
#endif


//const����
#if 0
int main() {
	int a = 10;
	int& b = a;//������Ȩ��ƽ��
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	const int c = 20;
	//int& d = c;//err
	//d������c�ı��� -- ��Ϊc���ܸ�
	//��һ�������Ȩ�޵ķŴ��ǲ������
	cout << typeid(c).name() << endl;
	//C++���Դ�ӡ��������

	int e = 30;
	const int& f = e;//Ȩ�޵���С

	//��ʽ���͵�ת��
	int ii = 1;
	double dd = ii;// -- ��ʵ���ǻῪһ����ʱ����
	//double& rdd = ii;//�����
	const double& rdd = ii;//��ȷ��
	//����ת���м�������ʱ����
	//�������ʱ�������г���
	//���Բ���const��ʱ����ʵ��ʱ������Ŀ�������Ȩ�޷Ŵ�
	//����const��ʵֻ��Ȩ��ƽ��

	//constҲ�����������ı���
	const int& x = 10;//
	//���������Ժ��������þ;�����const -- ��Ȼ���ܻ������ܶ�����
	return 0;
}
//ǿת����ı�ԭ����������
#endif



#if 0
void func1(int n)
{}
void func2(int& n)
{}
int main() {
	int a = 10;
	const int b = 20;
	func1(a);
	func1(b);
	func1(30);
	//ע�⣺Ȩ�޷Ŵ�ֻ������ã���Ϊ���ñ�����ͬһ��ռ�
	//�������ﴫ���ǿ�����������Ȩ�޵�����

	func2(a);
	//func2(b);
	//func2(30);//err
	//��func2()��Ӹ�const�����������ܴ���ȥ��
	return 0;
}
#endif
/* �ܽ᣺const���к�ǿ�Ľ��ն�
* ���ʹ�����ô��Σ�������������ı�n����ô������const���ô���
*/



//���ú�ָ��
#if 0
int main()
{
	int a = 10;
	int& ra = a;

	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl;
	return 0;
}
//ָ���ǿ�󣬸�Σ�գ���Σ��
//Ӧ����Ծ���һЩ������ȫ������


//���﷨�Ƕȣ�����û�п��ռ䣬ָ�뿪��4����8
//���Ǵ򿪻�࣬���Է��֣����ַ�ʽ�Ļ�������һ����
//�������õĵײ����ָ��
int main() {
	//
	int a = 10;
	int& ra = a;
	ra = 20;
	//
	int* pa = &a;
	*pa = 20;

	return 0;
}
#endif
//�൱��������ָ��ķ�װ
//�����õ�ʱ�򣬾������þ��ǻ������� -- ��ȥ��ȡ�ò�����õ�


//C++Ϊʲô֧�ֺ�������
//Linux 7_19_cpp����ʾ
//��װg++ָ��
//yum install gcc-c++ libstdc++-devel

//Ԥ����+����+���+����
//Ԥ����ͷ�ļ�չ�������滻���������룬ȥ��ע��
//���ɣ�func.i test.i

//���룺�﷨��飬���ɻ�����
//���ɣ�func.s test.s

//��ࣺ�ѻ�����ת�������ƻ�����
//���ɣ�func.o test.o -- ����func���л�����

//����
//a.out(linux)  
//xxx.exe(windows)

//���ӵ�ʱ����ô�������Ķ���
//call func (?)�����ǵ�ַ
//��ַ�����ң��ڶ�������
//�������ӽ׶���
//��ô��
//һ��ʼ�����ɷ��ű�
//
//����ͳ��ڷ��ű���
//�޷����庯��
//��Ϊ��������ͬ�����ɵķ��Ž�һ��

//��ôg++�����ʱ�����ɷ��ű��ʱ�򣬻���һ�����������ι���
//readelf test.o -s
//readelf func.o -s ���Կ����ű�
//���ű������func����������
//_Z4funcid
//_Z4funcii
// 4���������ĳ��ȣ�id����������͵�����ĸ��iiͬ��
//�����Ͳ����ͻ��

//�ܽ᣺Ϊʲôcpp֧�ֺ������� -- ���������ι��� -- ������ͬ�����γ������־Ͳ�ͬ��


//C++��ô����C
//C++����    C++��
//C����      C��
//�����������أ�
//���Ե� -- ������Ҫ��һЩ����
//C++��������ʶC�Ĺ���
//C����������ʶC�Ĺ���
// 

//C++����C�Ŀ�
//���������Cд��һ����̬��(.lib)��������Ҫ��C++������������(��̬�������Stack.c�����һЩ��������)
//�������ò��˵ģ���ΪC���ɵ�.lib�ļ��ķ��Ź����C++��ͬ
//����extern "C" ����
extern "C" {
#include"Stack.h"
}
//�����extern "C"��������ʵ���Ǹ���C++�������������������ʵ�֣�ʹ��Cʵ�ֵ�
//������C�Ĺ���ȥ���Ӳ�������


//C����C++��
//����������һ��
//�����治һ���ĵ��ǣ����C���򲻱��ˣ���ΪC��������ʶC++
//����ֻ�ܸĿ�
//��.h�ļ�����������ӿ�����Ū��extern "C"���ѽӿڶ�������
//����������ʵ��������⣬��Ϊ.h����.c�ļ�����չ��������.c�ļ����治֧��extern "C"��ΪC++��֧����������
//��������ҪŪһ��C++��ʶ�� -- �����ɷ��ű��ʱ��Cpp����������extern "C"������C�Ĺ�������.lib�ļ�
//����Ҫ��.c���治չ������Ϊ.c������extern "C"
#ifdef __cplusplus
extern "C"
{
#endif
	//...�ӿ�����
	//...
#ifdef __cplusplus
}
#endif
//����Ū�Ļ���cpp������extern "C"��c�����û����


//��������
/*
* ��inline���εĺ���������������������ʱC++��������������������ĵط�
* չ����û�к���ѹջ�Ŀ������������������������е�Ч��
*/
//1.��С�ĺ���
//2.Ƶ���ĵ��ã���10��Σ�
//���������źͿ��ŵ�swap����

//C: �꺯��
//C++: inline

//ADD�ĺ꺯��
#if 0
#define ADD(X,Y)((X)+(Y))
int main() {
	int a = 10+1;
	int b = 15;
	int ret = ADD(a, b);
	cout << ret << endl;
	return 0;
}
#endif

#if 0
inline int Add(int a, int b) {
	return a + b;
}
int main() {
	int a = 10;
	int b = 20;
	cout << Add(a, b) << endl;
	return 0;
}
#endif
//inline ��������������£��ڵ��õĵط�չ��
//C++�л������ٽ���ʹ�ú�
//��effective C++����һ�����������const enum inlineȥ�����

//����inline
/*
* 1.inline��һ���Կռ任ʱ���������ʡȥ���ú����Ŀ�����
*   ���Ե�����ܳ�������ѭ��/�ݹ�ĺ������ʺ�ʹ����Ϊ��������
* 2.inline���ڱ���������ֻ��һ�����顣���������Զ��Ż�
*   �������Ϊinline�ĺ��������еݹ飬�����Ƚϳ��ȵȣ��������Ż�ʱ����Ե�����
* 3.inline�����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ��Ҳ��� -- ������ֱ�Ӳ��ŵ����ű�����
*/


//auto �Զ��Ƶ�����
#if 0
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();

	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
	return 0;
}
#endif

#if 0
int main() {
	int a[] = { 1,2,3,4,5,6 };
	//����Ҫ����a�������
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	//����
	//��Χfor
	//�Զ�ȡa�����ݸ�ֵ��e
	//�Զ��������Զ��жϽ���
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#include<map>
#if 0
int main() {
	std::map<std::string, std::string>dict;
	std::map<std::string, std::string>::iterator it = dict.begin();
	auto it = dict.begin();//�������п�����auto�Ż����������
	//���ͱȽϳ���ʱ�򣬿�����auto����
	return 0;
}
#endif


//auto��ָ����ʹ��
#if 0
int main() {

	int x = 10;
	auto a = &x;//int*
	auto* b = &x;//ǿ��һ��Ҫ��ָ��
	auto& c = x;//ǿ��c��һ������
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;

	*b = 30;
	c = 40;
	return 0;

}
#endif

//�����پ�һ���ղ���������ӣ�����ͨ����Χfor���޸������ֵ��ô��
#if 0
void print_arr(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
#if 0
	for (auto e : arr) {
		e--;
	}
#endif
	for (auto& e : arr) {
		e--;
	}
	//�����϶���û��Ч����,��Ϊe��arr[]��һ�������������Ҹĳ����þͲ�ͬ�ˣ����þͲ��ǿ�����
	print_arr(arr,sizeof(arr)/sizeof(int));
	return 0;
}
#endif

//auto������Ϊ�����Ĳ���
//auto����������������s



//NULL������
void f(int) {
	cout << "f(int)" << endl;
}
void f(int*) {
	cout << "f(int*)" << endl;
}
int main() {
	int* p = NULL;
	f(0);
	f(NULL);//���Ƿ���NULL��ʵȥ���õ�һ���ˣ���Ϊ��cpp��NULL�������0��
	f(p);
	return 0;
}
//nullptr��C++�Ŀӣ����ǲ�C���ԵĿӣ��Ժ���nullptr����