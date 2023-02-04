#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};




//24. �������������еĽڵ�
class Solution {
private:
    struct ListNode* reverseList(struct ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        struct ListNode* cur = head;
        struct ListNode* next = head->next;
        struct ListNode* ahead = NULL;
        while (cur) {
            cur->next = ahead;
            ahead = cur;
            if (next) {
                cur = next;
                next = cur->next;
            }
            else {
                break;
            }
        }
        return ahead;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λͷ�ڵ�
        newhead->next = head;
        ListNode* prevPrev = newhead;
        ListNode* cur = newhead;
        ListNode* prev = newhead;
        cur = cur->next;

        while (cur && cur->next) {
            //����һ����
            cur = cur->next;
            prev = cur;
            if (cur) {
                cur = cur->next;
            }
            prev->next = NULL;
            prevPrev->next = reverseList(prevPrev->next);
            while (prevPrev->next) {
                prevPrev = prevPrev->next;
            }
            prevPrev->next = cur;
        }
        return newhead->next;
    }
};
