#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cassert>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    //���������ǹ��캯�����໥����
    Node() {}
    Node(int _val) {
        val = _val;
        next = NULL;
    }
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

//��ָ Offer II 029. �����ѭ������
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        //�Ȱ��µĽڵ㴴����
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next = nullptr;
        newNode->val = insertVal;
        //����ڵ�Ϊ��
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            return newNode;
        }
        //���ֻ��һ���ڵ�
        if (head->next == head) {
            head->next = newNode;
            newNode->next = head;
            return head;
        }
        //��ֹһ���ڵ�
        //�Ȱ�������head�ҵ� -- ������һ��head��λ��
        Node* cur = head->next;
        Node* prev = head;
        //����Ҫ��realhead�ҳ�������Ȼ[3,3,3],0�����������
        int cnt = 0;//��¼�����Ƿ��ǵ�һȦ
        while (1) {
            if (cur->next->val >= cur->val && prev->val > cur->val)break;
            if (cur == head && cnt != 0)break;
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        cnt = 0;//��¼�����Ƿ��ǵ�һȦ
        Node* realHead = cur;
        while (1) {
            if (cur->val >= insertVal && prev->val <= insertVal)break;
            if (cur == realHead && cnt != 0)break;//��������һȦ��
            prev = cur;
            cur = cur->next;
            ++cnt;
        }
        //��ʱ�½ڵ�Ӧ�ò�����prev��cur֮��
        prev->next = newNode;
        newNode->next = cur;
        return head;
    }
};