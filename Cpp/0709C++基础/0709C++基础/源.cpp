#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

//using namespace std;

//һ����˵std��Ҫ��ȫչ��
//����
//1.��Ŀ�У�������Ҫ��using namespace std;
//2.�ճ���ϰ����using namespace std;
//3.��Ŀ�У�����ָ�������ռ����+չ�����õ�

#if 0
using std::cout;
using std::endl;
int main() {
	//�����֣�ָ��һ��vector������ĺ����Ͳ���ָ����
	std::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//������ЩҪ�ظ�д�����Ǿ�չ�����õ�
	cout << "hello world!" << endl;
	cout << "hello world!" << endl;
	cout << "hello world!" << endl;

	return 0;
}
#endif



//C++����������
using namespace std;
#if 0
int main() {
	int i;
	double d;
	cin >> i >> d;
	cout << i << " " << d << endl;
	cout << "hello world" << endl;
	char arr[] = "hello bit";
	cout << arr << endl;
	//C���ԵĶ������Լ����õ�
	//�����Ҫ��������ĸ�ʽ��ֻ���С�����λ������Щ
	//ֱ����printf�ͺ�
	return 0;
}
//��������Զ�ʶ������
#endif


#if 0
//ȱʡ����
void Func(int a = 0) {
	cout << a << endl;
}
int main() {
	Func(1);
	Func(2);
	Func();//����������ʱ��ȱʡ���������ã�������˲�����ȱʡ�����Ͳ�������
	return 0;
}


//ȫȱʡ�����Ͱ�ȱʡ����
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
void TestFunc2(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//ȱʡֻ�ܴ�������
//void F(int a = 10, int b, int c);//����
void F(int a, int b = 10, int c = 10);
//void F(int a = 10, int b, int c = 10);//����


int main() {
	TestFunc1();
	TestFunc1(1);
	TestFunc1(1, 2);//���Ĳ����Ǵ������Ҹ���
	TestFunc1(1, 2, 3);

	//TestFunc2();
	TestFunc2(1);
	TestFunc2(1, 2);//���Ĳ����Ǵ������Ҹ���
	TestFunc2(1, 2, 3);
	return 0;
}
#endif

#if 0
//��ô����
struct Stack {
	int* _a;
	int _top;
	int _capacity;
};
void StackInit(struct Stack* ps, int capacity = 4) {
	ps->_a = (int*)malloc(sizeof(int) * capacity);
	//...
	ps->_top = 0;
	ps->_capacity = capacity;
}
int main() {
	//���֪��һ�������100�����ݣ��Ϳ�����ʾ������100
	//������ǰ���ÿռ䣬�����������ݾͿ��Ա������ݣ��������д��۵�
	struct Stack st1;
	StackInit(&st1, 100);

	//�����֪���Ͳ���-ֱ��ȱʡ-��Ĭ�ϵ�4
	struct Stack st2;
	StackInit(&st2);

	return 0;
}

//ȱʡ���������������Ͷ���ͬʱ����
//һ���������������岻��
//һ���ǰ�������Ϊ׼��
#endif


//��������
//һ�������ж����˼
//C�����ǲ����������������ڵ�
//C++����
//1.ͬ������һ��Ҫ��ͬһ��������������
//2.��Щͬ���������β��б��������� �������� ˳�򣩱��벻ͬ
///������������ʵ�ֹ��������������Ͳ�ͬ�ĺ���
#if 0
int Add(int left, int right)
{
		return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.0, 20.0) << endl;
	cout << Add(10L, 20L) << endl;
	return 0;
}
#endif

//�������ض�C++�����ش�
#if 0
int main() {
	int a = 1;
	int b = 2;

	double c = 1.1;
	double d = 2.2;

	swap(a, b);
	swap(c, d);

	cout << a;//��ʵ�Զ�ʶ������-���Ǻ�������֧�ֵ�
	cout << c;
	return 0;
}
#endif
//ΪʲôC++֧�ֺ������أ�ΪʲôC��֧��
//C++��ε���C��
//�����⣺�������صĵײ�ԭ��


//����
//���Ǹ�����ȡ����
#if 0
int main() {
	int a = 0;
	int& b = a;//����������
	cout << &b << endl;//������ȡ��ַ
	cout << &a << endl;
	//���ֵ�ַ��һ����
	a++;
	cout << a << " " << b << endl;
	return 0;
}
#endif



//��������
//1.�����ڶ����ʱ��һ��Ҫ��ʼ��
//2.һ�����������ж������
//3.������ø���һ��ʵ�壬�Ͳ��ܸ�����һ��ʵ����
#if 0
int main() {
	//1.
	int a = 1;
	//int& b;  //err
	//2.
	int& b = a;
	int& c = a;
	int& d = c;
	cout << a << " " << b << " " << c << endl;
	++a;
	cout << a << " " << b << " " << c << endl;
	//3.
	//�����ָ���ǲ�һ���ģ�ָ�������ʱ�ı䣬һ���ָ����һ���ָ����
	int x = 10;
	b = x;//b��x�ı����أ�����x��ֵ��b�أ�---�����Ǹ�ֵ
	cout << a << " " << b << " " << c << endl;
	return 0;
}
#endif

//���õ�Ӧ�ó���
//1.������ -- ����Ͳ���
#if 0
void _swap(int& r1, int& r2) {
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}void _swap_ptr(int* r1, int* r2) {
	int tmp = *r1;
	*r1 = *r2;
	*r2 = tmp;
}

//vector
typedef struct SeqList {
	//...
}SL;
void SLPushBack(SL& s, int x)//����
{}
#endif

//forwardList
#if 0
typedef struct SListNode {
	//...
}SLTNode;
void SListPushBack(SLTNode** pphead, int x) {}//ָ��汾
void SListPushBack(SLTNode*& pphead, int x) {}//���ð汾
#endif

//�ٸĽ�
#if 0
typedef struct SListNode {
	//...
}SLTNode,*PSLTNode;//������ʵ��ָ����ȥ�ˣ���ʵ����Ż���ʵ�ﲻ���Ż���Ч�������ӻ�������
void SListPushBack(PSLTNode& phead, int x) {//phead��ʵ����list�ı�����phead�ı���ʵlistҲ��ı�
	if (phead == NULL) {
		phead = (SLTNode*)malloc(sizeof(SLTNode));
		//...
	}
}
//��Щ����ҲҪ������
//�ղ��Ǹ�typedef���µ�*PSLTNode��ʵ����
typedef struct SListNode* PSLTNode;//��ʵ��һ������

int main() {
	int a = 0, b = 2;
	cout << a << " " << b << endl;
	_swap_ptr(&a, &b);
	cout << a << " " << b << endl;
	_swap(a, b);
	cout << a << " " << b << endl;
	//
	SL s;
	SLPushBack(s, 1);
	SLPushBack(s, 2);
	SLPushBack(s, 3);
	//
	SLTNode* list = NULL;
	SListPushBack(list, 1);
	SListPushBack(list, 2);
	SListPushBack(list, 3);

	return 0;
}
#endif


//����
//2.����󴫲Σ����Ч��
//��������Ϊ�������ǲ����ռ��
#if 0
#include <ctime>
struct A {
	int arr[10000];
};
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)//�����
		TestFunc1(a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
int main() {
	TestRefAndValue();
	return 0;
}
#endif 
//�����Ȳ�Ҫ���ĵײ�����ôʵ�ֵ�





//����
//3.����ֵ
#if 0
int Count1() {
	//int n = 0;
	static int n = 0;
	n++;
	//...
	return n;
}
//�����ô�ֵ���ص�ʱ��n��ʵ���Ƿ���ֵ����Ҫ����һ���µ�
//���Ի�ѹջ -- �ں�����ջ֡�����������н� -- С�Ļ��üĴ�������Ļ�����ǰ���ÿռ�
//Ϊʲô��ֵ����Ҫ��������
//��Ϊ����Count1��ջ֡��Ҫ���ٵ�
//��������n���ھ�̬��������ջ���棬����ϵͳ��Ҫ�����ã���Ϊ�Ǵ�ֵ����
//����ֻҪ�Ǵ�ֵ����
//��������һ�����ض��󿽱���Ϊ�������õķ���ֵ

//�����÷���
int& Count2() {
	int n = 1;
	//static int n = 0;
	n++;
	//...
	return n;
}
int main() {
	int& ret = Count2();
	//�������д��ret��ʵ����n����������֮��ret��ʵû��
	//����д��int ret= Count2(); �ǲ�һ����
	//
	printf("%d\n", ret);
// -- ��ʱret�Ľ����δ����ģ����ջ֡����ʱ��ϵͳ������ջ֡���ó����ֵ
//��ô����retӦ�������ֵ
//������Ҹպ���1
	printf("%d\n", ret);
	cout << ret << endl;//��ӡ�ڶ��ε�ʱ����ʵ�������ֵ�� -- ���ҵ�printf��cout�Ľ����һ��
	cout << ret << endl;
	//�������static��ʵ��Խ����
	//����Խ��!=����
	//Ϊʲô���ﲻ������ -- Դ��һ������

	//������ЩȫԽ����
	ret = 10;
	*(&ret + 1) = 20;
	*(&ret + 2) = 30;
	for (int i = 0; i < 100; i++) {//���������ٵ�ʱ����������ֲ��ˣ�ѭ����һ��������ͱ�����
		*(&ret + i) = i;
	}
	return 0;
}
#endif
//�ܽ᣺
/*
* ���˺������ã����ض���������� -- ��ôһ�����������÷��أ�һ��Ҫ�ô�ֵ����
* �����һ��static�Ϳ�������
*/

//���÷��صĳ���
#include<cassert>
typedef struct SeqList {
	int* a;
	int size;
	int capacity;
}SL;
void SLInit(SL& s, int capacity = 4) {
	s.a = (int*)malloc(sizeof(int) * capacity);
	assert(s.a);
	//...
	s.size = 0;
	s.capacity = capacity;
}
void SLPushBack(SL& s, int x) {
	if (s.size == s.capacity) {
		//...
	}
	s.a[s.size++] = x;
}
//������Ҫһ���޸�˳������ݵĽӿ�
void SLModify(SL& s, int pos, int x);//��ǰ�İ汾 -- ��ˬ
int& SLAt(SL& s, int pos) {
	assert(pos >= 0 && pos <= s.size);
	return s.a[pos];
}
int main() {
	SL sl;
	SLInit(sl);
	SLPushBack(sl, 1);
	SLPushBack(sl, 2);
	SLPushBack(sl, 3);
	for (int i = 0; i < sl.size; i++) {
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;
	//�޸�
	//��Ϊ����ֵ�����ã����Կ���ֱ�ӻ�ȡ˳��������ֵ
	SLAt(sl, 0)++;
	//�ٴ�ӡ
	for (int i = 0; i < sl.size; i++) {
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;
	//�ٸ�
	SLAt(sl, 0) = 10;
	//�ٴ�ӡ
	for (int i = 0; i < sl.size; i++) {
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;
	return 0;
}
//�������Ǹĵľͺ�ˬ
//���SLAt�ӿ���ʵ���������[]һ������д�ɸ�
//ֻҪ����return�Ķ����ڶ����棬����ֱ�������÷��ص���