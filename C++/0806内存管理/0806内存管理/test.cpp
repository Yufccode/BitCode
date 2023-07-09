#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//C++ѧϰ������Ҫ�������������˸��������
//C
//ST st;
//...
//Creat ... Destroy
//
//C++
//stack<int>st;
//st.push()
//��ʵ����û�д���ַ��
//�еģ� thisָ����ǵ�ַ



/*
1. ջ�ֽж�ջ���Ǿ�̬�ֲ�����/��������/����ֵ�ȵȣ�ջ�����������ġ�
2. �ڴ�ӳ����Ǹ�Ч��I/Oӳ�䷽ʽ������װ��һ������Ķ�̬�ڴ�⡣�û���ʹ��ϵͳ�ӿڴ�������
���ڴ棬�����̼�ͨ�š���Linux�γ����ûѧ����飬����ֻ��Ҫ�˽�һ�£�
3. �����ڳ�������ʱ��̬�ڴ���䣬���ǿ����������ġ�
4. ���ݶ�--�洢ȫ�����ݺ;�̬���ݡ�
5. �����--��ִ�еĴ���/ֻ������
*/
#if 0
void Test() {
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	//����5��int������
	int* p3 = new int[5];//��5�� -- ����ʼ��
	//����һ��int���󣬳�ʼ��Ϊ5
	int* p4 = new int(5);
	
	//C++98��֧�ֳ�ʼ��new������
	//C++11֧��
	int* p5 = new int[5]{ 1,2,3 };

	free(p1);
	delete p2;
	delete[] p3;
	delete p4;
	delete[] p5;
	//malloc --  free
	//new -- delete 
	//Ҫ���Ӧ -- ��ʱ����������ʱ�򲻻�

	//����������� -- new/delete ��mallocû�б�������ֻ���÷�������
}
int main() {
	Test();
	return 0;
}
#endif

//����Զ������� -- ���кܴ������
#if 0
class A {
public:
	A(int a = 0) :_a(a) {
		cout << "������A�Ĺ��캯��" << " " << this << endl;
	}
	~A() {
		cout << "������A����������" << " " << this << endl;
	}
private:
	int _a;
};
int main() {
#if 0
	A* p1 = (A*)malloc(sizeof(A));
	//��Ҫ���

	//malloc()ֻ����ռ�
	free(p1);
	//ֻ�ͷſռ�


	A* p2 = new A;
	//1.������ϵĿռ�  2.������ù��캯����ע�⣺��Ĭ�Ϲ��죩
	delete p2;
	//1.������  2.�ͷ�

	//new delete ��Ϊ���Զ�������׼����

#endif
	//����Ƕ�������أ�
	A* p3 = new A[3];
	delete[] p3;
	//ÿ�����󶼻������ -- ÿ�����󶼻������
	//����˳��͹���˳�����෴��
	//�����������

	//Ĭ�Ϲ���������ǻ����ṩһ�£�����ȱʡ���������ױ಻�� -- �Ҳ���Ĭ�Ϲ���
	return 0;
}
#endif


//����һ�����Ե����� -- ���ռ�ʧ�ܵĴ���
#if 0
int main() {
	//ʧ�ܷ���NULL
	char* p1 = (char*)malloc(sizeof(char) * 1024u * 1024u * 1024u * 1024u);
	//cout << p1 << endl;//������ò�Ҫ��cout��cout��ʶ����ַ��� -- ���������printf
	printf("%p\n", p1);
	free(p1);


	//newʧ�����׳��쳣
	char* p2 = new char[1024u * 1024u * 1024u * 1024u * 1024u];
	printf("%p\n", p2);
	//���쳣������������Դ������ķ�ʽ��py���˽����
	return 0;
}
#endif




#if 0
//new��delete�������ǵ�����malloc��free
//ΪʲôҪ��װһ�㣿
//��ΪҪ�����쳣
//operator new������
//1.��װmalloc -- Ϊ��ȥ���쳣
#define free(p) _free_dbg(p, _NORMAL_BLOCK)
//free ��������һ���� -- ������Դ���뿴��ʱ���ܿ���


//opertor new����Ҳ�����Լ��õ� �÷���mallocһ��
int main() {
	char* p = (char*)operator new(sizeof(char) * 1024);
	//�÷���mallocһ����ʧ�ܵĻ����쳣
	return 0;
}
#endif
//ʵ��Ӧ�ò�Ҫȥ��
//ֱ����new��delete������


//opertor new/...�ǿ��Ա����ص�
//�����д���ǵ���Ĭ���Ǹ�
//����Ҳ����дһ���Լ�ר���� -- ���ͻ�ȥ���������Լ�д��


//����һ����ר����operator new
class ListNode {
public:
	int _val;
	ListNode* _next;
	static allocator<ListNode>_alloc;//��ҵĽڵ�Ūһ���ڴ�ؾ���
	//ע�� static ���õ��������������������涨�壡�����ˣ�

	ListNode(int val)
		:_val(val),
		_next(nullptr)
	{}
	//����
	void* operator new(size_t n) {
		//...����дһ���ڴ��
		//����Ҳ����ֱ�ӵ��ÿ������

		//allocator����� -- ��һ���ڴ��
		//C++����пռ�������
		void* obj = _alloc.allocate(n);
		//���ǿ���д�ɳ�Ա����
		return obj;
	}
	void operator delete(void* ptr) {
		_alloc.deallocate((ListNode*)ptr, 1);
	}
};	
allocator<ListNode>ListNode::_alloc;
int main() {
	//Ƶ������ListNode
	//��Ҫ���Ч�� -- ����ListNode��ʱ�򣬲�ȥmalloc���������Լ����Ƶ��ڴ��
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);

	delete node1;
	delete node2;
	delete node3;
	delete node4;

	return 0;
}

//�ڼ������������ -- Ƶ������һ���������Բ��óػ�������
//�������ڴ��

//�ܽ᣺
//new = operator new+���캯��
//Ĭ�������operator newʹ��ȫ�ֿ�����
//ÿ�������ȥʵ���Լ�ר��operator new ��new��������ʱ�򣬾Ͳ���ȥ��Ĭ�ϵģ���ʧȥ���Լ���



//��λnew �˽�