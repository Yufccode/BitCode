#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

//ţ��CM11 ����ָ�
class Solution {
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* greaterhead, * greatertail, * lesshead, * lesstail;
		//���ڱ�λ��ø�һ��
		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
		greatertail->next = NULL;
		lesstail->next = NULL;

		ListNode* cur = pHead;
		while (cur) {
			if (cur->val < x) {
				lesstail->next = cur;
				lesstail = lesstail->next;
			}
			else {
				greatertail->next = cur;
				greatertail = greatertail->next;
			}

			cur = cur->next;
		}
		lesstail->next = greaterhead->next;
		ListNode* head = lesshead->next;
		return head;
	}
};




//������ 02.04. �ָ�����
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)return NULL;
        //�ڱ�λͷ�ڵ�
        ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
        newhead->next = head;
        //�ڱ�λ2������β��
        ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
        ListNode* tail = head2;
        ListNode* cur = newhead;
        ListNode* prev = newhead;
        cur = cur->next;//��ʱ��curָ����������head
        while (cur) {
            if (cur->val >= x) {
                tail->next = cur;
                prev->next = cur->next;
                tail = tail->next;
                cur = cur->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        tail->next = NULL;
        prev->next = head2->next;
        return newhead->next;
    }
};





//141. ��������
//�ж��л�
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)return true;
        }
        return false;
    }
};
//fast��slowֻ�����ٶ����1��ʱ����ܱ�֤�����