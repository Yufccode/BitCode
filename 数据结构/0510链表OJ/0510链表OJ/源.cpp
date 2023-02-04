#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};



//OJ142 ���뻷��
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				//����
				ListNode* meet = slow;

				//����Ǵ���ѧ��ʽ�Ƶ�������
				while (meet != head) {
					//һ����head��ʼ��
					//һ����meet��ʼ��
					meet = meet->next;
					head = head->next;
				}
				return meet;
			}
		}
		return NULL;
	}
};


//�Ͽ�ת�����ཻ��������Ҳ�ǿ��Ե�
class Solution {
private:
    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
        if (headA == NULL) {
            return headB;
        }
        if (headB == NULL) {
            return headA;
        }
        struct ListNode* cur1 = headA;
        struct ListNode* cur2 = headB;
        struct ListNode* curA = headA;
        struct ListNode* curB = headB;
        int la = 0;
        int lb = 0;
        while (cur1) {
            la++;
            cur1 = cur1->next;
        }
        while (cur2) {
            lb++;
            cur2 = cur2->next;
        }
        if (lb > la) {
            for (int i = 0; i < lb - la; i++) {
                curB = curB->next;
            }
        }
        else {
            for (int i = 0; i < la - lb; i++) {
                curA = curA->next;
            }
        }
        //���������ǲ��еģ���Ϊ���������Ȳ�һ��һ�������Կ����Ȱ�La��Lb��������ó������߲�ֵ
        while (curA) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                fast = fast->next;
                slow->next = NULL;
                return getIntersectionNode(fast, head);
            }
        }
        return NULL;
    }
};