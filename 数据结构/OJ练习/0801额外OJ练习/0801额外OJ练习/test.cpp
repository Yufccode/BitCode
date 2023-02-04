#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std; 

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//143. ��������
class Solution {
private:
    struct ListNode* reverseList(struct ListNode* head) {
        //����ָ��
        //����ָ������
        if (head == NULL)return NULL;
        struct ListNode* prev = NULL;
        struct ListNode* cur = head;
        struct ListNode* next = head->next;
        while (next) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur->next;
        }
        cur->next = prev;
        return cur;
    }
public:
    void reorderList(ListNode* head) {
        //1.�ҵ�������м�ڵ�
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        //prev
        //�����ҶϿ�
        ListNode* head2 = prev->next;
        prev->next = nullptr;
        //��ת�ұߵ�����
        head2 = reverseList(head2);
        //��ʼ��������
        ListNode* cur1 = head;
        ListNode* cur2 = head2;
        //Ūһ���µ�ͷ
        ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
        newhead->next = nullptr;
        ListNode* tail = newhead;
        while (cur1 && cur2) {//��Ϊcur1�϶��Ƚϳ�
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;

            tail->next = cur2;
            tail = tail->next;
            cur2 = cur2->next;
        }
        //tail->next=cur1;
        head = newhead->next;
    }
};