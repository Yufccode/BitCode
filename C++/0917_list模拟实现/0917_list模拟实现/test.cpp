#define _CRT_SECURE_NO_WARNINGS 1

//�ܽ᣺���������ص���� -- ���ã�����

#include"MyList.h"

#if 0
// �����ӡ����
template < class T>
void PrintList(const yufc::list<T>&l)
{
	auto it = l.cbegin();
	while (it != l.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
// ����List�Ĺ���
void TestList1()
{
	yufc::list<int> l1;
	yufc::list<int> l2(10, 5);
	PrintList(l2);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	yufc::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);
	yufc::list<int> l4(l3);
	PrintList(l4);
	l1 = l4;
	PrintList(l1);
	PrintListReverse(l1);
}
// PushBack()/PopBack()/PushFront()/PopFront()
void TestList2()
{
	// ����PushBack��PopBack
	yufc::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	PrintList(l);
	l.pop_back();
	l.pop_back();
	PrintList(l);
	l.pop_back();
	cout << l.size() << endl;
	// ����PushFront��PopFront
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	PrintList(l);
	l.pop_front();
	l.pop_front();
	PrintList(l);
	l.pop_front();
	cout << l.size() << endl;
}
void TestList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto pos = l.begin();
	l.insert(l.begin(), 0);
	PrintList(l);

	++pos;
	l.insert(pos, 2);
	PrintList(l);
	l.erase(l.begin());
	l.erase(pos);
	PrintList(l);
	// posָ��Ľڵ��Ѿ���ɾ����pos������ʧЧ
	cout << *pos << endl;
	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	cout << l.size() << endl;
}
#endif


#if 0
int main() {
	//yufc::test();
	//yufc::test2();
	//yufc::test3();
	//yufc::test4();
	yufc::test5();
	return 0;
}
#endif



//forward_iterator
//bidirectional_iterator
//random_access_iterator
//��ʵ������һ�ּ̳еĹ�ϵ
//˫��������ĵ�������������˫��

//Դ����ʵ������д�İ汾�����ӵö�
//�ܶ�汾����
//��������ȡ��ЩҲ�����˽�һ��
//��ȡ -- �������Ч��
//���������Ҫ���
//��ȡ�������ܸ��ӵ�һ��������������ȡ��������������
//���磺�����������������;�ֱ������������˫���������Ҫ����++�����
//��ȡ�������Ч��