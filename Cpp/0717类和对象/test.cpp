#define _CRT_SECURE_NO_WARNINGS 1
#include"person.h"

//��Ͷ���
//������������Ҫ
//�������ںʹ洢λ���й�ϵ

//���ʵ����


// ������Ҫָ��PrintPersonInfo������Person�������
#if 0
int main() {
	cout << sizeof(Person) << endl;//û���ռ���ô���С��
	Person p1;//��ʱ�ſ��ռ� -- ��������ʵ����
	return 0;
}
#endif


//��Ĵ�С����
#if 0
class A {
public:
	void PrintA() {
		cout << _a << endl;
	}
	void func() {
		cout << "void A::func()" << endl;
	}
	char _a;
};
int main() {
#if 0
	cout << sizeof(A) << endl;
	A aa1;
	A aa2;
	//������_a�ǲ�һ����_a
	aa1._a = 1;
	aa2._a = 2;
	//���� -- ������������ͬһ��
	aa1.PrintA();
	aa2.PrintA();
#endif
	//��һ����Ŀ
	A* ptr = nullptr;
	ptr->func();
	//���������뱨���������У�
	//�������У���Ϊ��û�н����ã���Ա������û����������
	return 0;
}
#endif
//����洢��ʽ��ƶ���
//�ຯ�����ַ+���Ա����
//����洢��ʽ�������
//��Ա�����ŵ������棬��Ա�����ŵ�����������
//��������ʱ�͸��ݺ������������������ҵ������ĵ�ַ��call�����ĵ�ַ

//����ڴ�������ͽṹ��һ��
#if 0
class A2 {
public:
	void f2() {}
};
class A3{};
int main() {
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	return 0;
}
#endif
//Ϊʲô����0�أ�
//û�г�Ա����������󣬸�1byte��ռλ����ʶ������ڣ����洢ʵ������


//thisָ��
#if 0
class Date {
public:
	void Init(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;//�����ΪʲôҪ��_
	}
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main() {
	Date d1;
	d1.Init(2022, 7, 17);
	Date d2;
	d2.Init(2022, 7, 18);
	d1.Print();
	d2.Print();
	//�������ˣ�������ô���ִ�ӡ��ʱ����d1����d2��
	//��Ա�����ǹ��������
	//����һ������thisָ��
	return 0;
}
#endif
//�����淶
//1.���ʺ͵���֮������ĸ��д��� --�շ巨 GetYear
//2.����ȫ��Сд������֮����_�ָ�  get_year
// 
//���ã��շ巨
//1.�����������������е�������ĸ��д
//2.��������ĸСд�����浥������ĸ��д
//3.��Ա�����׵���ǰ���_

//��ʵ���治�������ģ���ʵInit()���ĸ�������Print()��һ��������thisָ��
//��Ȼ���Ǳ������Ĵ���ʽ�����ǲ����Լ�����Ū
//main()����Ҳ������صĴ���
#if 0
class Date {
public:
	//
	void Init(int year, int month, int day) {//
		cout << this << endl;
		this->_year = year;
		this->_month = month;
		this->_day = day;//�����ΪʲôҪ��_
	}
	void Print() {
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
/// <summary>
/// ��ʵ�����������������������ӵ� -- �����Լ�д��ʱ�����Լ����ϣ������������ﲻ�ܼ��ϣ��ڲ��ǿ����Լ��õģ�
/// //������������������Լ�ʹ�����this
/// </summary>
/// <returns></returns>
/// ʵ�κ��β��Ǹ�λ�ò�����ʾ���ݺͽ���thisָ��
/// ���ǿ����ڳ�Ա�������ڲ�ʹ��
int main() {
	Date d1;
	d1.Init(2022, 7, 17);
	Date d2;
	d2.Init(2022, 7, 18);
	d1.Print();
	d2.Print();
	return 0;
}
#endif



//thisָ���һЩ����
// 1.��������ܱ���ͨ����
// 2.����������������������
#if 0
class A {
public:
	void PrintA()
	{
		cout << _a << endl;
		//û����һ������ǿ���ͨ���ģ��������Ҫ��_a�Ͳ����ˣ���Ϊnullptr��ָ�벢û�и�_a���ռ�
		//_a����Ҫthisָ������õģ���Ϊthis�ǿգ��������б���
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main() {
	A* p = nullptr;
	p->PrintA();
	p->Show();
	return 0;
}
#endif
//thisָ���Ǵ����ĵģ�
//�� ջ ��̬�� ��������
//һ������ջ���� -- ��Ϊ����һ���β�
//����Ҳ��һ������Щ�ط�������Ż�������vs���� -- �ŵ��Ĵ�������
//Linux���԰ѻ����Գ�������




//��Ա����
//���6��Ĭ�ϳ�Ա����
//һ��������ʲô��û�У����Ϊ����
//��ʵ���������Զ�����6��Ĭ�ϳ�Ա����
/*
* 1.���캯������ʼ������
* 2.����������������
* 3.�������죺��ʹ��ͬ������ʼ����������
* 4.��ֵ���أ���һ������ֵ����һ������
* 5.6��ȡ��ַ���أ��˽�һ�£�����Ҫ��
*/


//���캯��
#if 0
class Date {
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//�������ʱ��������ǳ�ʼ����ô��
//����Init��ʼ�������ǿ��ܻ����� -- ���±������߳������ֵ
//�ܲ��ܱ�֤����һ������ʼ�� -- ���캯��
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d1.Display();

	Date d2;
	d2.SetDate(2018, 7, 1);
	d2.Display();
	return 0;
}
#endif
//���캯�����ԣ�
/*���캯�����������������ģ���������ʼ��������
1.��������������ͬ
2.�޷���ֵ
3.����ʵ����ʱ�����Զ����ö�Ӧ�Ĺ��캯��
4.���캯����������*/
#if 0
class Date {
public:
	// 1.�޲ι��캯��
	Date()
	{
		//...������Լ���д��������дҲ����
	}

	// 2.���ι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1; // �����޲ι��캯��
	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
	//���Ҳ�൱�ڴ���һ��Date���ͬʱ��Ҳ�Ѻ�������һ�£�����ע�⣬�޲ε�ʱ����()��������

	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
	Date d3();
}
int main() {
	TestDate();
	return 0;
}
#endif
//���캯����������ͨ�����Ķ���͵��ù���ȥ���
//Ҳ������ȫȱʡȥŪ


//ջ�Ĺ��캯��
#if 0
typedef int Datatype;
class Stack {
public:
	Stack(int capacity = 4) {
		_array = (Datatype*)malloc(sizeof(Datatype) * capacity);
		if (nullptr == _array) {
			perror("malloc");
			exit(-1);
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(Datatype data) {

	}
	void Pop() {

	}
private:
	Datatype* _array;
	int _size;
	int _capacity;
};
int main() {
	Stack st;
	st.Push(0);
	st.Push(1);
	return 0;
}
#endif


//���캯������
//5.�������û����ʽ���幹�캯������C++���������Զ�����һ���޲�
//  ���캯����һ���û���ʽ���壬�������������Զ�����

//�������ǵ��Է��֣�Ĭ�����ɵĹ��캯��ɶ��û��
// 
// 
// 
//C++���ͷ��ࣺ
//1.�������ͣ�int/doulbe/char/pointer��
//2.�Զ������ͣ�struct/class
// 
// 
// 
//Ĭ�����ɵĹ��캯��
//a.�������ͳ�Ա��������
//b.�Զ������ͳ�Ա��ȥ��������Ĭ�Ϲ��캯��
typedef int Datatype;
class Stack {
public:
	//Stack() {}
	Stack(int capacity = 4) {//���������д =4 ����MyQueue�͵���������ĺ����ˣ�������Ūһ������Stack
		_array = (Datatype*)malloc(sizeof(Datatype) * capacity);
		if (nullptr == _array) {
			perror("malloc");
			exit(-1);
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(Datatype data) {

	}
	void Pop() {

	}
private:
	Datatype* _array;
	int _size;
	int _capacity;
};
class MyQueue {
private:
	Stack _st1;
	Stack _st2;
};
int main() {
	MyQueue q;
	//���ǵ�MyQueue��Ȼû��д���캯����������ΪStack���Զ������ͣ����Ի��ǻᱻ��ʼ������Ϊ��ȥ����Stack�Ĺ��캯����
	//����ʵ��C++���ʱ���һ��ȱ�ݣ����Ĭ�Ϲ��캯������Ӧ�ð���������Ҳһ�����
	return 0;
}

//Ĭ�Ϲ��캯��
//1.���ǲ�д���������Զ������Ǹ�
//2.�����Լ�д�ģ�ȫȱʡ���캯��
//3.�����Լ�д�ģ��޲ι��캯��
//����������Ĭ�Ϲ���