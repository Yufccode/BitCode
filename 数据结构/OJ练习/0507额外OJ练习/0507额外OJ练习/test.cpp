#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>

using namespace std;

#if 1
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

//92. ��ת���� II
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            //ͷ��
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev = NULL;
        left--;//�ڶ���λ�ã���һ��������
        right--;
        while (left-- && start) {
            prev = start;
            start = start->next;
        }
        while (right-- && end) {
            end = end->next;
        }
        ListNode* cont = end->next;//��һ�����ӵ�cont��
        end->next = NULL;
        ListNode* newhead = reverseList(start);
        if (prev) {
            prev->next = newhead;
        }
        else {
            head = newhead;
        }
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = cont;
        return head;
    }
};












//82. ɾ�����������е��ظ�Ԫ�� II
//ϸ���ر�Ķ࣬����һ��һ����������
//�����һ���ڱ�λͷ�ڵ㣬��򵥺ܶ࣬�����ҵķ���û����
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)return head;
        while (head) {
            if (head->next == NULL)break;
            if (head->val != head->next->val)break;
            ListNode* realhead = head;
            while (realhead && realhead->next && realhead->val == realhead->next->val) {
                realhead = realhead->next;
            }
            if (realhead != head) {
                head = realhead->next;
            }
        }
        if (head == NULL)return NULL;
        ListNode* cur = head->next;
        ListNode* prev = head;
        ListNode* prevPrev = NULL;
        while (cur) {
            if (cur->val == prev->val) {
                while (cur && cur->val == prev->val) {
                    cur = cur->next;
                }
                if (cur) {
                    prevPrev->next = cur;
                    prev = cur;
                    cur = cur->next;
                }
                else {
                    prevPrev->next = NULL;
                }
            }
            else {
                prevPrev = prev;
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};


#endif





//796. ��ת�ַ���
bool rotateString(char* s, char* goal) {
    if (strlen(s) != strlen(goal))return false;//ע��������
    int len = strlen(s);
    char tmp[1000] = { 0 };
    strcpy(tmp, s);
    strncat(tmp, tmp, len);
    char* p = strstr(tmp, goal);
    if (p == NULL) {
        return false;
    }
    else return true;
}
int main() {
    char str1[] = "abcdef";
    char str2[] = "cdefab";
    bool ret = rotateString(str1, str2);
    return 0;
}




//1019. �����е���һ������ڵ�
//����Ǻ����Եı�����
class Solution {
private:
    int find_maxInList(ListNode* begin) {
        if (begin == NULL) {
            return INT_MIN;
        }
        int target = begin->val;
        ListNode* cur = begin->next;
        while (cur) {
            if (cur->val > target) {
                return cur->val;
            }
            cur = cur->next;
        }
        return INT_MIN;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ret;
        ListNode* cur = head;
        while (cur) {
            int num = find_maxInList(cur);
            if (num != INT_MIN) {
                ret.push_back(num);
            }
            else {
                ret.push_back(0);
            }
            cur = cur->next;
        }

        return ret;
    }
};