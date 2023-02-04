#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
using namespace std;

//��ָ Offer 35. ��������ĸ���
class Node {
public:
    int val;
    Node* next;
    Node* random;//��һ�����ָ���
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //1.�ѿ����ڵ�ŵ�����
        Node* cur = head;
        while (cur) {
            Node* copy = (Node*)malloc(sizeof(Node));
            copy->val = cur->val;
            copy->next = cur->next;
            cur->next = copy;

            cur = cur->next->next;//����
        }
        //2.��������
        cur = head;
        while (cur) {
            Node* copy = cur->next;
            //������ϵ
            if (cur->random == NULL) {
                copy->random = NULL;
            }
            else {
                copy->random = cur->random->next;
            }
            cur = copy->next;
        }
        //3.�Ͽ�����
        //��������β��ķ�ʽ���������ַ�ʽҲ���Ե�
        cur = head;
        Node* copyhead = NULL;
        Node* copytail = NULL;
        while (cur) {
            Node* copy = cur->next;
            Node* next = copy->next;

            if (copytail == NULL) {
                copyhead = copytail = copy;
            }
            else {
                copytail->next = copy;
                copytail = copytail->next;
            }
            cur->next = next;
            cur = next;
        }
        return copyhead;
    }
};



//����������-�����-�ŵ�-���ҿ죡
#include<map>
#include<set>
//��ϣ��-���ҿ�
#include<unordered_map>
#include<unordered_set>
//˳���
#include<vector>
//�ַ���-Ҳ��˳���
#include<string>
//������
#include<forward_list>
//˫����
#include<list>
int main() {
    forward_list<int>list2;
    list2.push_front(1);
    list2.push_front(2);
    list2.push_front(3);
    list2.push_front(4);

    return 0;
}