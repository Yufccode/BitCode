#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#elif
#endif


//��Ҫע����ǳ�Ա���������أ�ֻ��Ҫ��������ͬ�͹�������
//ע����ʵ���еļ̳���ϵ������ò�Ҫ����ͬ���ĳ�Ա
//�ع�
#if 0
class A {
public:
	void func() {
		cout << "func()" << endl;
	}
};
class B :public A {
public:
	void func(int i) {
		A::func();
		cout << "func(int i)->" << i << endl;
	}
};
void Test() {
	B b;
	b.func(10);
	b.A::func();
}

int main() {
	Test();
	return 0;
}
#endif


//��ֵ����ת��
#if 0
class Person {
protected:
	string _name;
	string _sex;
	int _age;
};
class Student :public Person {
public:
	int _No;
};
int main() {
	Student sobj;
	//1.���������Ը�ֵ���������/ָ��/����
	//������Ȼ�ǲ�ͬ���ͣ���������ʽ����ת�� -- ����������֧�� -- �﷨��Ȼ֧��
	//�и������˵�������и�
	//��Ϊ����������ĸ���
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj; //���Ϳ���ȷ�� -- ������ʽ����ת����������һ�����϶�����
	//					�������ʽ����ת�� -- �������ʱ���� -- ���г��� -- ���Կ϶����ò���

	//�������϶��ǲ��е� -- ����һ���ֶ���������Ķ�������û�У�ǿתҲ�ǲ���
	//����ָ������ÿ���ת -- ���������漰���ܸ��ӵ����� -- ���ﲻչ����
	return 0;
}
int main() {
	int i = 10;
	double d = 0;
	d = i;//��ʽ����ת��
	double& dd = i;//err
	const double& ddd = i;//ok
	return 0;
}
#endif



//�����6��Ĭ�ϳ�Ա������ô��
//������ĳ�Ա������ô����
#if 0
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};
//��������ô��ʼ����
class Student : public Person
{
public:
	Student() {}
	Student(const char* name, int num)
		: Person(name)//���ﲻ��д_name(name) ҪдPerson(name) -- ����Person
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s) //�������ʵ���Բ���д
		: Person(s) //ֱ�Ӵ�s -- �������Ƭ������
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)//������Լ����Լ���ֵ���Ͳ��ø���
		{
			Person::operator =(s);//ע����仰��
			//ΪʲôҪ��ʾдPerson:: -- ��Ϊͬ�������������أ���������������������operator=��ֻ��Person::��ʽ����
			_num = s._num;
		}
		return *this;
	}

	//����������ĺ������������������������أ���Ȼ��ͬ��
	//���ں����̬����Ҫ�������������ֻ�ͬ�⴦���destructor()
	//���һ��Ҫע�� -- ������أ�
	~Student()
	{
		//Person::~Person();//��Ȼ��ʽ������û�õģ���Ϊ�����Զ����ã���ʽдû������
		//ÿ�������������棬���Զ����ø��������������������ܱ�֤���������࣬����������
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};
void Test()
{
	//�������������ʲô����д
#if 0
	Student s;
#endif
	/*
	Person()
	~Person()
	*/
	//���������Ĭ�����ɵ�Ĭ�Ϲ��캯����
	///1.�Լ��ĳ�Ա������Ͷ���һ�� -- ���ò����� -- �Զ������͵��Զ������͵Ĺ���
	///2.���ڼ̳и����Ա��������ø���Ĺ��캯����ʼ��

	//�������죺
	//1.�Լ��ĳ�Ա������Ͷ���һ�����������ֵ�������Զ������͵��õ������Ŀ������죩
	//2.�̳и���ģ�������ø����

	//��ֵ
	//ͬ��

	//ȡ��ַ���� -- �ǲ��úϳɵģ�ȡ�Լ��ľ����ˣ�����ȡ�����
	//����һ�㲻�Լ�д

	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
}
int main() {
	Test();
	return 0;
}
#endif



//�̳�����Ԫ
//��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա
#if 0
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);//��Ԫ��ϵ�ǲ��ᱻ�̳���ȥ��
protected:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	//cout << s._stuNum << endl;//err
}
void main()
{
	Person p;
	Student s;
	Display(p, s);
}
#endif


/*
���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա���������������ٸ����࣬��ֻ��һ
��static��Աʵ��
*/
//������������ʵ���count����ͬһ��count
#if 0
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << "���� :" << Person::_count << endl;
	Person::_count++;
	cout << "���� :" << Student::_count << endl;
	//���ֶ���һ���ģ�count����ͬһ��
}
int main() {
	TestPerson();
	return 0;
}
#endif

//���̳У�һ������ֻ��һ��ֱ�Ӹ���ʱ������̳й�ϵΪ���̳�
//Ҳ����һ����

//��̳У�һ������������������ֱ�Ӹ���ʱ������̳й�ϵΪ��̳�
//class Assistant :public student, public:teacher;


//����������Ŀ��
//1.��ζ���һ�����ܱ��̳е��ࣿ
//C++98������
//	a.���๹�캯��˽�� -- �����ǲ��ɼ�
//  b.�������ʵ�������޷����ù��캯��
//C++11������
//�����Ĺؼ���final
#if 0
class A final {
private:
	A() {}
protected:
	//���캯��˽�л�
	int _a;
};

//class B :public A {
//
//};

int main() {
	//B bb;//err
	return 0;
}

#endif


//��Ŀ2
//A.p1==p2==p3   B.p1<p2<p3   C.p1==p3!=p2  D.p1!=p2!=p3
#if 0
class Base1 {
public:
	int _b1;
};
class Base2 {
public:
	int _b2;
};
class Derive :public Base1, public Base2 {
public:
	int _d;
};
int main() {
	//�������һ����Ƭ -- ��ֵ����ת��
	//ע�⣬�ȼ̳е���ǰ��
	//��������ṹ��
	/*
		Base1       p1,p3ָ������
		Base2		p2ָ������
		int _d
	*/
	//����ѡC
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	//p1==p3
	//��p2����p1��
	//p2��
	//ջ�ǵ��ŷŵ�
	//ע�⣺����ʹ�С��û��ϵ����С�˷�������һ������������ֽڣ�������Ԫ��֮��ĵ�ַ��ϵ
	return 0;
}
#endif


//���μ̳У�
//���μ̳��Ƕ�̳е�һ���������
//							   class Person
// class Student:public Person				class Teacher:public: Person
//				  class Assistant:public:Student,public Teacher
/*
���μ̳е����⣺������Ķ����Աģ�͹��죬���Կ������μ̳�����������Ͷ����Ե����⡣��Assistant
�Ķ�����Person��Ա�������ݡ�
*/
#if 0
class Person
{
public:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void Test()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;

	//a._name = "peter";//err ���������� -- ����ȷ
	 
	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}
#endif
//��Ȼ�ܽ�������ԣ�������������û�н��


//��̳п��Խ�������ԺͶ����Ե�Ϊ��
//							   class Person
// �������������   virtual                    virtual
// class Student:public Person				class Teacher:public: Person
//				  class Assistant:public:Student,public Teacher
#if 0
class Person
{
public:
	string _name; // ����
};
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void Test()
{
	//��̳н���˶����Ժ���������
	Assistant a;
	a._name = "peter";//�������ᱨ���� -- ������a._name��ֻ��һ����
}
#endif
//��ʵ��һ����ٶ������μ̳�
//����˵�涨��Ҫ�������μ̳�
//������Щ�ط������õ���
//C++��IO��������ʵ����������μ̳�
//�����Ҫ�õ���̳�

//��ô��̳�����ν�������ԺͶ����Եģ�
//���Ӵ����Ѿ�����ʵ�ˣ�ʧ����
//�������ڴ洰������
#if 0
class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	//���ǿ���ͨ���ڴ濴��
	//���a���Ȳ���ŵ�B���棬Ҳ����ŵ�C���棬����ŵ�һ��������λ��
	//��B,C�������ȥ�ҵ�a������
	//ͨ���ڴ洰�ڿ��Կ�������ʵ�����һ��ƫ����
	//��ͻᵼ��һ������
	//��Ϊa��B,C�����Ƿ���һ���
	//��������и���Ƭ��ô��
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	B bb;
	cout << sizeof(B) << endl;//12 -- �����˸�������ָ�� -- �е���deque�ĵ���������˼��
	//B������û��_a?
	//�϶��У���Ȼ����̳� -- ��������϶���_a
	//����㲻����Ҫ�ٿ����������Ƶ

	return 0;
}
#endif

//�����Ǽ̳�
//���ֽ���� -- ѧУ�Ѿ��ù��ܶ����
class C {
	//...
};
class D {
protected:
	C _c;
};
//����������
//�ʺ��ü̳о��ü̳У��ʺ�����Ͼ������
//�ȿ���ʹ����Ϻͼ̳е������ -- ����ʹ����� 

//�̳еĸ���ͨ������Ϊ -- ���临��
//��ϵĸ���ͨ������Ϊ -- ���临��