#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//ѧУ��Ա����ϵͳ
//��ͬ���кܶ��ظ��Ķ���
//�ظ��Ķ���������ȡ�������ŵ�һ��������������ȥ
//�����������࣬���߻���
//���Ӧ�ģ�����/������
// -- ���ֵ�������ƶ����εĸ��ã�
#if 0
class Person {
public:
	void Print() {
		cout << "name " << _name << endl;
		cout << "age " << _age << endl;
	}
protected:
	string _name = "peter";
	int _age = 18;
	//....
};
class Student :public Person {
protected:
	int _stuid;
};
class Teacher :public Person {
protected:
	int _jobid;
};
int main() {
	Student s;
	s.Print();
	return 0;
}
#endif

//C++ �̳з�ʽ�ͷ����޶���
/*
* �̳з�ʽ
* 1.public�̳�
* 2.protected�̳�
* 3.private�̳�
*/
/*
* �����޶���
* 1.public����
* 2.protected����
* 3.private����
*/


//protected/private �����治�ܷ��ʣ���������Է���
//���ɼ�   ���� -- �������涼���ɼ�

//˽�г�Ա�����壺���뱻����̳еĳ�Ա��������Ƴ�˽��

//��ʵ��������һ�㶼��ʹ��public�̳У���������ʹ�ñ���/˽�м̳�
//����private��Ա�����ã�������û��ʲô�����ñ��̳еĳ�Ա
//��������Ҫ�����ิ�ã������ֲ��뱩¶ֱ�ӷ��ʵĳ�Ա����Ӧ�ö���ɱ���

//class Ĭ����˽�м̳�
//struct Ĭ���ǹ��м̳�
//ʹ�õ�ʱ�������ʾд����


//�̳��е�������
//�����к��������ܲ��ܶ���ͬ��������
//���� -- ��Ϊ����ͬһ����
//��ʱ��������������ͬ������
//�Ƿ�������� -- ���ʵ��������
#if 0
class Person {
protected:
	string _name = "С����";
	int _num = 111;
};
class Student :public Person {
public:
	void Print() {
		cout << "����:" << _name << endl;
		cout << "ѧ��:" << _num << endl;
		cout << "ѧ��:" << Person::_num << endl; //��Ȼ�ҿ���ָ������
	}
protected:
	int _num = 999;
};
int main() {
	Student d1;
	d1.Print();
	return 0;
}
#endif
/*
* ����͸�������ͬ����Ա�������Ա�����θ����ͬ����Ա��ֱ�ӷ��ʣ�
* ������������أ�Ҳ���ض���
*/
//���鲻Ҫ����������Ա


//���³�������func�Ĺ�ϵ��ʲô
//1.����fun���ɺ������أ� -- ���ԣ���������Ҫ����ͬһ������
//������func�������ع�ϵ -- ֻ��Ҫ��������ͬ�͹�������

class A {
public:
	void fun() {
		cout << "func()" << endl;
	}
};
class B :public A {
public:
	void fun(int i) {
		cout << "func(int i)->" << i << endl;
	}
};
int main() {
	B b;
	b.fun(10);
	//b.fun();//err -- �����ˣ�������
	b.A::fun();//ָ������
	return 0;
}
//����Ĳ��ǿ����������еģ����������ɵ�