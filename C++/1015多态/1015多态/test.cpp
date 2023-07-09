#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

#elif
#endif

//��̬
//��̬���������麯��


#if 0
class Person {
public:
	virtual void BuyTicket() { //ֻ�ó�Ա�������ܼ�virtual
		cout << "��Ʊ - ȫ��" << endl;
	}
};
class Student : public Person {
public:
	//�麯������д������ -- Ҫ����ͬ + �麯��
	//Ҫ�󣺺�������������ֵ��Ҫ��ͬ
	//��������д�Ž�����
	virtual void BuyTicket() { cout << "��Ʊ - ���" << endl; }
};
class Soldier : public Person {
public:
	virtual void BuyTicket() {
		cout << "��Ʊ - ������Ʊ" << endl;
	}
};

//��̬����������
//1.�麯������д
//2.����ָ���������ȥ�����麯��

void Func(Person& p) {
	p.BuyTicket();
	//���������ǰѧ��֪ʶ -- ����϶���ȥ����Person�ĺ���
	//�������ﹹ���˶�̬ -- ���ʱ��ͺ�p�����;�û�й�ϵ��
	//����ƻ���̬�������أ�
	//1.Peson& p --> Person p -- �����ɶ�̬
	//2.�����virtualȥ�� -- �����ɶ�̬
	//�����и����� -- C++�Ŀӣ��������virtualȥ����Ҳ�����Թ��ɶ�̬
	//��Ϊcpp����Ѹ���ĺ����̳�������д���ǽӿڼ̳У���дʵ�֣�������Ϊ����virtual -- �ӿڼ̳У����¿���
	//����1�������麯������virtual���ɹ�����д�����ɹ�����д��
	//����2����д��Э��
	//	����ֵ���Բ�ͬ��Ҫ������Ǹ��ӹ�ϵ��ָ���������
	//  ����������
}
int main() {
	Person ps;
	Student st;
	Soldier sd;
	Func(ps);
	Func(st);
	Func(sd);
	return 0;
}
#endif


//����2������Э��
#if 0
class A {};
class B : public A {};
class Person {
public:
	virtual A* BuyTicket() { //��Ȼ���ɸ��ӹ�ϵ��ָ��������ò�һ�����Լ��ģ��Ǳ��˵�Ҳ����
		cout << "��Ʊ - ȫ��" << endl;
		return nullptr;
	}
};
class Student : public Person {
public:
	virtual B* BuyTicket() { //����ķ���ֵ�ı���Ҫ������ĵͲ��У�һ���Ͳ���˵�ˣ�����ֵһ���Ͳ���Э���ˣ�����ԭʼ����д����
		//ֻ�����淵��A* ����B* ���ܷ�����
		cout << "��Ʊ - ���" << endl; 
		return nullptr;
	}
};
void Func(Person& p) {
	p.BuyTicket();
}
int main() {
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}
#endif



// ===================================== ������Ŀ ===================================== //

//��Ŀ��һ�³�����������ʲô
#if 0
class A{
public:
	virtual void func(int val = 1) {
		cout << "A->" << val << endl;
	}
	virtual void test() { func(); }
};
class B :public A {
public:
	void func(int val = 0) {
		cout << "B->" << val << endl;
	}
};
int main() {
	B* p = new B;
	p->test();
	return 0;
}
#endif
// �������Ժųơ�ɱ���⡱
//���ȵ���test() -- �϶���û�ж�̬�ģ��麯�����û��������д����������ͨ��������
//���ȵ���test() -- ��Ҫ��p��ָ�� -- ����ΪA* 
//�� this->func(); -- ���϶�̬������
//�����������׿���ĵط���
//1.B�����func����virtual���ɿ��Թ�����д�� -- ����B��func���麯��
//2.�麯����д�ǽӿڼ̳�
//  ��ͨ�����̳���ʵ�ּ̳�
//Ҳ����˵����B��func�ǰ�A������������������������ֻ��ʵ��
//����B�еĺ�����ʵ�õ���������� virtual void func(int val = 1) ������ void func(int val = 0)
// 
//					�ӿڼ̳У� +  ��дʵ�֣�
//���Դ�ӡ��val��1
//�ڹ�˾����ǧ��Ҫд�������Ĵ��룬д�����Ĵ�������Ҵ�


// ===================================== ������Ŀ ===================================== //
// �������д�أ� A->1? or B->1?
#if 0
class A {
public:
	virtual void func(int val) {
		cout << "A->" << val << endl;
	}
	void test() { func(1); } //����Ӳ���virtualû��������Ϊ������û����дfunc
	//		this->func(1)  this��A* ���Դ�����̬
	//		��A��func����B��func -- ��this�������й�ϵ�� -- û�й�ϵ
	//		thisָ��˭�͵�˭��A*p = new B;  ָ�����B -- ���е���B��
};
class B :public A {
public:
	void func(int val) {
		cout << "B->" << val << endl;
	}
};
int main() {
	A* p = new B;
	p->test();
	return 0;
}
#endif


// ====================================== ��̬��ԭ�� ======================================
//sizeof�Ľ����ʲô
#if 0
class Base{
public:
	virtual void Func1() {
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
	//char _ch = 'A';//����������������Ի���
};
int main(){
	cout << sizeof(Base) << endl;
	//���￼�첻���ڴ���� -- ������Ƕ�̬
	Base b;
	//��̬������һ�����ָ�룡
	//�麯���������� -- ����������Ӽ���������������ô��
	return 0;
}
#endif

///�麯���������� -- ����������Ӽ���������������ô��
///virtual function table
#if 0
class Base {
public:
	virtual void Func1() {
		cout << "Func1()" << endl;
	}
	virtual void Func2() {
		cout << "Func1()" << endl;
	}
	virtual void Func3() {
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};
int main() {
	cout << sizeof(Base) << endl;
	//���￼�첻���ڴ���� -- ������Ƕ�̬
	Base b;
	return 0;
}
#endif


//��̬��ԭ��
class Person {
public:
	virtual void BuyTicket() { //ֻ�ó�Ա�������ܼ�virtual
		cout << "��Ʊ - ȫ��" << endl;
	}
	virtual void test() {} //�������麯�� -- ֻ��һ���������д
	int _a = 10;
};
class Student :public Person {
public:
	virtual void BuyTicket() {
		cout << "��Ʊ - ���" << endl;
	}
	int _b = 20;
};
void Func(Person& p) {
	//���ɶ�̬֮��
	//������ô֪��ȥ����һ����������
	//��������Ѿ��к���ָ���ˣ�

	//��ʹ��������Ƭ
	//���ǿ�����ֻ�и������
	//�����������������濴���ĸ��ಿ�����������ַ���Ѿ������ǹ��ˣ�����������Ƭ����̬һ���ܹ���������
	p.BuyTicket();
}
int main(){
	Person Mike;
	Func(Mike);
	Student Johnson;
	Func(Johnson);
	return 0;
}
//��̬��
//�麯���������
//����������û����� -- û�У�ֻ������ָ�룡
//���ı�����һ������ָ�������

//��ϵ��������ǿ��Է���
//Mike���������Johnson����������ȫһ���� -- �������ǵĵ�ַ���úܽ�
//���ǿ��Է��� BuyTicket()�ĵ�ַ�ǲ�ͬ��
//test()�ĵ�ַ����ͬ��
//Ϊʲô��
//��ΪBuyTicket()�������д
//�൱�ڰ�Mike����ָ��������һ��������Ȼ�����д�ĺ����ĺ���ָ�븲����ȥ

//����virtual��������ɶ�̬����Ȼ��������У������ڻ����������ֺ���ͨ����û�����𣬲���ȥ��������ҵ�ַ
//ֻ�д����˶�̬ -- �������е�ʱ��Ż�ȥ�ҵ�ַ


// ======================================== �ܽ� ======================================== //

//�ܽ᣺��̬�ı���ԭ�����϶�̬����������
//��ô����ʱ���ᵽָ������������ҵ����Ӧ���麯���ĵ�ַ�����е���

//��̬�ĵ��ã�<��������ʱ>ȥָ������������ҵ������ĵ�ַ�����е���
//��ͨ�����ĵ��ã�<��������ʱ>ȷ�������ĵ�ַ���ڷ��ű������ң�������ʱֱ�ӵ���