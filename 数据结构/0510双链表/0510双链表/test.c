#define _CRT_SECURE_NO_WARNINGS 1

//����Ϊ�յ�ʱ����Ҫ��һ���ڵ��

//��ͷѭ��˫������ĶԱ�
//˳�����vector��
//�ŵ㣺֧���±�������ʡ�CPU���ٻ��������ʸߣ����ټ��ص�ʱ����Ժܺõ�����-��Ϊ�����ַ֮��û�й�ϵ�����Ի����϶����в���
//ȱ�㣺ͷ�������м�Ĳ���ɾ��Ч�ʵ͡����ݣ���һ���̶����ܵ�����-Ϊʲô-realloc��ʱ��
//���λ�ù����ã����λ�ò�����Ҫ���¿ռ䣬Ҫ�������ݣ������Ч���Ƿǳ����Ѻõģ��ǳ��ǳ���ʱ�䣡��
//�����ܴ��ڿռ��˷�
//

//��ͷ˫��ѭ������list��
//�ŵ㣺������λ�ò���ɾ��O(1),���������ͷ�
//ȱ�㣺��֧���±��������

#include"List.h"
void Test1() {
	ListNode* plist = _ListInit();
	_ListPushBack(plist, 1);
	_ListPushBack(plist, 2);
	_ListPushBack(plist, 3);
	_ListPushBack(plist, 4);
	_ListPushBack(plist, 5);
	_ListPrint(plist);

	_ListPushFront(plist, 0);
	_ListPushFront(plist, -1);
	_ListPrint(plist);

	_ListPopBack(plist);
	_ListPopBack(plist);
	_ListPopBack(plist);
	_ListPrint(plist);

	_ListPopFront(plist);
	_ListPopFront(plist);
	_ListPrint(plist);

}
int main() {
	Test1();
	return 0;
}