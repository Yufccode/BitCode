#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

#elif
#endif


//�Ͻڿ����ݸ�ϰ
//��̬���� -- ����ʱ����
//����ʱ����ָ�����������ҵ����麯����ַ  






//������

//����������virtual
//�����ڼ̳�����������������麯��
#if 0
class Person {
public:
	virtual ~Person() {
		cout << "~Person()" << endl;
	}
};
class Student :public Person {
public:
	virtual ~Student() {
		cout << "~Student()" << endl;
	}
};
int main() {
	//����������д
	//�����������ᱻ�����destructor����������������鹹��������麯����д
#if 0
	Person p;
	Student s;//��ͨ����������ԭ���������û������ģ����������࣬�ٸ���
#endif

	Person* ptr1 = new Person;
	delete ptr1;

	Person* ptr2 = new Student;
	delete ptr2;
	/**
	 * �������ǻᷢ�֣��������virtual ���������Person������.
	 * ����ǲ��Ե� -- �Ҵ�������һ���������ȴ�����˸��������
	 * Ϊʲô����Ϊ���õ�ʱ�����������õ�
	 * ptr2->destructor()
	 * operator delete(ptr2) 
	 * �������virtual �����϶�̬���� -- ��ptr2����ȥ�������� -- ���Ե�����~Person()
	 * ����������call�Ĳ���~Person()��������call����~Student()
	 */
	//����ϣ��ָ��ָ���������ģ�ָ�����������ģ�������ȡ����ָ������
	return 0;
}
#endif



//C++11��final��override
#if 0
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-����" << endl; } //err�޷���дDrive
};
int main(){

	return 0;
}
#endif


//override: ����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
#if 0
class Car {
public:
	virtual void Drive() {}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-����" << endl; }
};
int main() {
	return 0;
}
#endif


/** ���ء���д�����صĶԱ� */
//���μ�


//������
//�������麯��������������ࣨ�ӿ��ࣩ
/*���麯���ĺ���д�� =0 �����������Ϊ���麯�����������麯��������������ࣨҲ�нӿ��ࣩ��������
����ʵ����������������̳к�Ҳ����ʵ����������ֻ����д���麯�������������ʵ����������
���麯���淶�������������д�����ⴿ�麯�������ֳ��˽ӿڼ̳С�*/
class Car
{
public:
	virtual void Drive() = 0; //����дʵ�֣�д��Ҳû��ȥ��
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-����" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-�ٿ�" << endl;
	}
};
void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}




//��̬��ԭ��
#if 0
class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
	virtual void func1() {
		cout << "func1()" << endl;
	}
}; 
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
	virtual void func2() {
		cout << "func2()" << endl;
	}; //vs���Ӵ��ں����,������濴����������� -- ��ʵ��Ҫ������
};

typedef void(*VFPTR)();//typedefһ���������
void print_vfttable(VFPTR* table, int n) {
	//���������Ǻ���ָ������
	//��vs���麯�������һ��Ԫ�غ�����һ����ָ�룬Linux�²�һ��
	//����Linux������ֻ��д����֪���м����麯����ѭ������
	//vs�����ǿ��Բ�д��
	//for (size_t i = 0; *(table + i) != nullptr; ++i) {
	for (size_t i = 0; i < n; ++i) {
		printf("vft[%d]:%p->", i, table[i]);//�������ǿ��԰ѵ�ַ����ӡ����
		table[i]();//�麯���ĵ�ַ��һ��() -- ���ú���
	}
}//д�����������֮�� -- �������һ�� -- ��εõ��麯����ĵ�ַ
//�麯�����ַ�ڶ����ַ��ͷ4��/8���ֽ���


int main() {
	//ͬһ�����͵Ķ�����һ�����
	Person p1;
	Person p2;
	//p1,p2�ǹ�������Ǹ��ø��ģ� -- �϶��ǹ��õ�

	//Person��Student�Ŀ϶�����ͬһ�� -- ���ݶ���һ��
	Student s1;
	Student s2;

	//�����û�������д����ͬһ������� -- ���Ƿ��ֲ��ǣ�
	//vs�� �����Ƿ������д���������������������ͬһ��

	//vs�ļ��������⣬�������麯�������濴����func(),�����ǿ���ͨ��ʲô�������أ�
	//1.�ڴ���Կ�
	//2.����дһ����������ӡ�麯����

	//���ַ��ʷ�ʽ��˽�е�Ҳ�ܷ��ʣ���Ϊ���Ѿ������������ķ��ʷ�ʽ��
	//����Ҫȡ�麯����ĵ�ַ
	//32λ������ȡͷ�ĸ��ֽ� -- ǿת��int -- �ٽ�����
#define __SIZEOF_POINTER__ 4
#if __SIZEOF_POINTER__ == 4
	print_vfttable((VFPTR*)*(int*)&s1, 3);
	cout << endl;
	print_vfttable((VFPTR*)*(int*)&p1, 2);
	//Ϊʲôǿת��int* ֮��Ҫ������ -- ��Ϊ���ǲ���Ҫ����ͷ���ĵ�ַ������Ҫ����ͷ����ַ����ָ�򡷵��ĸ��ֽڣ�
#elif __SIZEOF_POINTER__ == 8
	print_vfttable((VFPTR*)*(double*)&s1);
#endif
	//��ʵ���ֵ��ú�bug
	//��print_vfttable()����������ú�����������ĺ�����û�õ�this��Ҳû�õ������ָ�룬���Ѿ����ǳ���ĵ��÷�ʽ��
	void(*ptr)();
	return 0;
}
#endif


//��̳�
#if 0
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1 = 1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2 = 2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; } //func2()û����д
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	//cout << sizeof(d) << endl; //20
	/**
	 * Base1�Ĵ�С��8.
	 * Base2�Ĵ�СҲ��8
	 * �ٷŸ�d1 -- ��С��4
	 * ���������20
	 */
	/**
	 * ǰ���û���⣬d������������� -- �ֱ���Base1��Base2��
	 * �������ָ��ָ���������涼ֻ����������ָ�룬
	 * һ����fun1()��һ����func2()��.
	 * 
	 * ��d��func3()�����أ�
	 * �ŵ�Base1���棿Base2���棿���Ǳ�ĵط���
	 * ���Ǵ�ӡ��������
	 * \return 
	 */

	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	cout << endl;
	/** ����1 */
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));//�����ҵڶ������ĵ�ַ�ķ���Ҫע��
	/** ����2 -- ��Ƭ*/
	Base2* ptr2 = &d;//��Ƭ��ʱ����Զ�ƫ��
	PrintVTable(vTableb2);//�������ﴫptr2��vTableb2Ҳ����\

	//��ʱ�����������·��� -- ���Ƿ���d�̳���Base1��Base2��func1()�������д֮��
	//���������Base1��Base2��func1()�ĵ�ַȴ�ǲ�һ����
	//�������֣���ֻ��д����һ��func1()������ַ������������治ͬ -- Ϊʲô��

	//���漰��ָ��ƫ�Ƶ����� -- ��Ȼ������ַ��ͬ -- ��������ǵ��õ���ͬһ������ -- ���õ���func1()

	//�����Ƿ��϶�̬�� -- �����������
	Base1* ptr1 = &d;
	ptr1->func1();
	Base2* ptr2 = &d;
	ptr2->func1();
	//��vs������ -- ��ֻ���麯����ַ -- ���к����ĵ�ַ��ʵ����������pushջ֡�ĵ�ַ
	//���ǰ�����һ��
	//ͨ��������ǿ��Կ��� -- vs�µ��ú�����ʱ�򣬵��ú����ĵ�ַ��ʵ��һ��jmpָ��ĵ�ַ
	//jmp�������ĺ�����ַ֮�� -- �ſ�ʼpushջ֡
	//����vsΪʲô������� -- ��֪���� gcc����ʲô���ģ������о�һ��

	//��ptr2->func1()�е���jmp��ʱ��
	//������jmp��ȥ���Ǻ�����ַ��
	//����������һ������
	//ecx����һ��8               -----------------   ������ǹؼ������� --- Ϊʲô��8 ---���ǰ�ptr2Ū��ptr1�ϵ�λ����
	//ѧ�������������֪��ecx�����thisָ��
	return 0;
}
#endif




//��̬��β
//���μ̳�
#if 0
class A{
public:
	int _a;
public:
	virtual void fun1() {
		cout << "A::func1()" << endl;
	}
};
//class B : public A {
class B :virtual public A {
public:
	int _b;
	virtual void fun1() {
		cout << "B::func1()" << endl;
	}
};
//class C : public A {
class C: virtual public A{
public:
	int _c;
	virtual void fun1() {
		cout << "C::func1()" << endl;
	}
};
class D :public B, public C {
public:
	int _d;
	virtual void fun1() {
		cout << "D::func1()" << endl;
	}
};
//���Ǹ�A����һ���麯��func1()
//B,C�����һ����д
//���Ƿ��ֱ���ᱨ��
//	error C2250: ��D��:��void A::fun1(void)���Ĳ���ȷ�̳�
//Ϊʲô��
//��ʵ���������D�ϣ���D���ε���û����
//���������̳� -- D��Ӧ�û����������
//��������������̳��� -- D��ֻ��һ��A�����
//�����﷨Ҫ�� -- D������д
int main() {
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}
#endif

/** ======================================= �ص� ======================================= */
//Ҫ������Щ
/**
 * �﷨��
 * 1.��д�ĸ��������
 * 2.��̬�ĸ������
 * 
 * ԭ��
 * 1.�����ʲô��
 * 2.��̬��ԭ����ʲô��
 * 3.��ͨ���ã�����ʱ����Ͷ�̥���ã�����ʱ�����������ʲô.
 */





/** ================================== ѡ���� ================================== */
//��������
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A
{
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A
{
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class D :public B, public C
{
public:
	D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
//A�Ĺ���᲻���ظ����ã�
//������˳������ǳ�ʼ���б��˳�� -- ����˳����ABCD
int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}


/** ============================================== �ʴ��� ============================================== */
//1.���������ɲ��������麯����
	//inlineֻ��һ�������͵Ĺؼ��� -- �����ϲ��� -- ��Ϊ��������û�е�ַ���麯����Ҫ��ַ�ŵ����
	//inlineֻ���Ὠ�� -- ���Ա����ǿ���ͨ���� -- ʵ������û������ -- ��̬�����У�inlineʧЧ
//2.static�����������麯����
	//�����ԣ�static����û��thisָ�� -- ����A::Func()����ȥ����
	//���麯����Ϊ��ʵ�ֶ�̬ -- ����̬��Ա�������ڱ���ʱ�����
//3.���캯���������麯����
	//�����ԣ�
	//�����ʲôʱ���ʼ���ģ� -- �ڳ�ʼ���б�׶γ�ʼ����
//4.���������������麯����
	//���ԣ���������������������
//5.��������͸�ֵ�������麯����
	//�������첻���ԣ� -- ��������Ҳ�ǹ���
	//��ֵ���ԣ��﷨�Ͽ��ԡ���ֵ��ɶ�̬��û�����壬���˿�����ɸ��ำֵ������ -- ��������û����
//6.�麯���컹����ͨ������
	//�����̬���� -- ��ͨ�죬����һ����
//7.����ַ���ĸ���
	//���ǿ��Կ�����ַ����Щ���͵ı������ý� -- �Ϳ��ж���
	//����׶����� -- ���ڴ���Σ���������
//���� -- У��ǰ -- ��Щ��Ҫ��ϰ��