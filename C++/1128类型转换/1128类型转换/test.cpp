
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


//C++����ת���ֳ�����
//��ʽ����ת������ʽ����ת��
#if 0
void Test()
{
	int i = 1;
	//��ʽ����ת��
	double d = i;
	printf("%d, %.2f\n", i, d);
	int* p = &i;
	// ��ʾ��ǿ������ת��
	int address = (int)p;
	printf("%x, %d\n", p, address);
}
int main()
{
	Test();
	return 0;
}
#endif
//C����
//������������ͣ��������������
//�ڲ�������������ʱ��һ�ᷢ����ʽ����ת��
//������дC���Ե�ʱ������һ��Ҫע������



/*
	��׼C++Ϊ�˼�ǿ����ת���Ŀ����ԣ�����������������ǿ������ת����������
	static_cast��reinterpret_cast��const_cast��dynamic_cast
*/

//static_cast���ڷǶ�̬���͵�ת������̬ת��������������ʽִ�е��κ�����ת��������static_cast������
//����������������ص����ͽ���ת��
//�����������������
#if 0
int main()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;
	//���������������ת���˵�
	/*int* pa = nullptr;
	int aa = static_cast<int>(pa);*/
	return 0;
}
#endif

#include<vector>
//reinterpret_cast
//reinterpret_cast������ͨ��Ϊ��������λģʽ�ṩ�ϵͲ�ε����½��ͣ����ڽ�һ������ת��Ϊ��һ�ֲ�
//ͬ������
#if 0
typedef void (*FUNC)();
//typedef vector<int> FUNC;
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}
void Test()
{
	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
}
int main()
{
	Test();
	return 0;
}
#endif


//const_cast
//const_cast��õ���;����ɾ��������const���ԣ����㸳ֵ
#if 0
void Test()
{
	const int a = 2;
	int* p = const_cast<int*>(&a);
	//int* p = &a;//�಻��
	*p = 3;
	cout << a << endl;//2
	const int* pa = &a;
	cout << *pa << endl;//3 �����ֱ��ͨ���ڴ���ʵģ�������3
	cout << *p << endl;//3
	//C++��const���β��ǳ�����û�д浽��̬��ȥ�����ǳ����� -- ��ջ��
	
	//��ʵͨ���������ǿ��Է��� �� *p = 3;֮��&a��Ҳ����pָ��������Ѿ��ĳ�3��
	//��Ϊʲô��ӡ�Ļ���2��
	//������Ϊ���������Ż�
	//const���εı��� -- �ᱻ��������Ϊ�����ᱻ�޸ģ����Ա�������ŵ��Ĵ�����Щ�ط�
	//��Ϊÿ���ö�Ҫȥ�ڴ�ȡ̫�鷳��
	//�����ڴ��иĳ�3�ˣ��Ĵ�����֪��
	//��Щ������Ҳֱ�Ӳ���Ĵ���������VS��
	//���ǿ�vs����Ļ���֪����cout����call֮��push������push�Ĳ���a��2
	//����vs����һ������#define�����ĺ��滻�Ĳ��������Ժ��漴ʹ�ڴ��и��ˣ�Ҳû��
}
void Test2()
{
	//����һ�ַ�ʽ���Բ��ñ�����ȥ�Ż����const
	//�ؼ���volatile
	volatile const int a = 2;
	int* p = const_cast<int*>(&a);
	//��Ȼ�����ǻ���C������һ��Ҳ�ǿ��Եģ�ֱ��ǿת
	//int * p = (int*)(&a);
	*p = 3;
	cout << a << endl;//3
	cout << *p << endl;//3
	
	//��ȻC++���Ǽ���C�ģ�������
	//���ǲ�����ȥ�ã������ø��淶�ģ�
}
int main()
{
	//Test();
	Test2();
	return 0;
}
#endif

//static_cast(��ʽ����ת��)
//reinterpret_cast��const_cast(ǿת)


//dynamic_cast C++���ӵ�
/*
dynamic_cast���ڽ�һ����������ָ��/����ת��Ϊ��������ָ�������(��̬ת��)
����ת�ͣ��������ָ��/����->����ָ��/����(����Ҫת������ֵ���ݹ���) ����ת�ͣ��������ָ��/����-
>����ָ��/����(��dynamic_castת���ǰ�ȫ��)
ע�⣺ 1. dynamic_castֻ�����ں����麯������ 2. dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת
���������򷵻�0
*/

//��ʱ����Ҫ�ǵ�
//������ת���У������ǲ��淶��ת�����ǹ淶��ת�����������ʱ�����ģ����г��ԣ�
//��ϰ
#if 0
int main()
{
	int i = 10;
	double d = 2.0;
	double d = i;//����ת�����ǻ������ʱ���� i->tmp->d
	//����
	//double& d = i;//err 
	//double& d = static_cast<double>(i);//err 
	//������Ϊd��������i��������Ϊ��仰����d����i����d������ʱ��������ʱ�������г���
	const double& d = i;
	return 0;
}
#endif

//ע�⣬�̳����������ת������������ת��
//��Ϊ�����������ʱ����
#if 0
class A
{
protected:
	int _a = 0;
public:
	virtual void f()
	{
		cout << "A::f()" << endl;
	}
};
class B :public A
{
protected:
	int _b = 1;
public:
	void f()
	{
		cout << "B::f()" << endl;
	}
};
#if 0
int main()
{
	A aa;
	B bb;
	A aa1 = bb;//û�з�������ת��,�������Ƭ
	//���
	A& ra1 = bb;//�����������ʱ�����������Ǳ಻����
	//�����������
	//������ǰѼ̳й�ϵȥ�����ͱ಻����

	//���ԣ��̳����������ת������������ת��
	return 0;
}
#endif
#if 0
int main()
{
	//1.�������������ζ�����ת�����
	A aa;
	//B bb = (B)aa;//err
	//B bb = dynamic_cast<B>(aa);//err
	//������ζ�ת����

	//2.ָ���أ������أ� -- ����
	return 0;
}
#endif
void fun(A* pa)
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
/*
ע�� ǿ������ת���رջ���������������ͼ�飬ÿ��ʹ��ǿ������ת��ǰ������ԱӦ����ϸ�����Ƿ���
������ͬ�ķ����ﵽͬһĿ�ģ������ǿ������ת�����ɣ���Ӧ����ǿ��ת��ֵ���������Լ��ٷ�������
�Ļ��ᡣǿ�ҽ��飺����ʹ��ǿ������ת��
*/
int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}
#endif


//������������һ����������һ����������
class A1
{
public:
	virtual void f() {}
public:
	int _a1 = 0;
};
class A2
{
public:
	virtual void f() {}
public:
	int _a2 = 0;
};
class B :public A1, public A2
{
public:
	int _b = 0;
public:
	virtual void f() {}
};
int main()
{
	B bb;
	A1* ptr1 = &bb;
	A2* ptr2 = &bb;
	//��������ָ��϶��ǲ�һ����
	cout << "&bb  " << &bb << endl << "ptr1 " << ptr1 << endl << "ptr2 " << ptr2 << endl;
	//B������A1��Ҳ��A2��A1�ĵ�ַ��B��ַһ����A2��ƫ��

	//���ڸ���ת���࣬���ֱ�Ӱ����Ϸ�ʽ��ǿת
	B* pb1 = (B*)ptr1;
	B* pb2 = (B*)ptr2;
	cout << endl << pb1 << endl << pb2 << endl;//���Ƿ���������һ����

	B* pb3 = dynamic_cast<B*>(ptr1);
	B* pb4 = dynamic_cast<B*>(ptr2);
	cout << endl << pb3 << endl << pb4 << endl;//���Ƿ���������һ����

	//����ֱ����Ϊ�����ֱ��ǿת����������ǰ�pb1ƫ�ƻ�ȥ����ʵ�ǻ�ģ�

	//���Ҫ˵���𣬿������ڣ���������麯����dynamic_cast���ò�����
	return 0;
}


//C++Ҫע�����������
//RAII
//RTTI -- ����ʱ����ʶ��
//	typeid/dynamic_cast/decltype
//typeid ��ȡ���������ַ���
//dynamic_cast����� ���׵�ָ��ָ������󣬻����������
//decltype �Ƶ�һ���������ͣ���������������һ������