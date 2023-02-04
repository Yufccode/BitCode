#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


//������ⶼ���Լ�������ɵģ�



#if 1
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


//��ָ Offer II 078. �ϲ���������
class Solution {
private:
    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        struct ListNode* newhead = NULL;
        struct ListNode* tail = newhead;
        if (list1->val > list2->val) {
            tail = newhead = list2;
            list2 = list2->next;
        }
        else {
            tail = newhead = list1;
            list1 = list1->next;
        }
        struct ListNode* cur1 = list1;
        struct ListNode* cur2 = list2;
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                tail->next = cur1;
                cur1 = cur1->next;
                tail = tail->next;
            }
            else {
                tail->next = cur2;
                cur2 = cur2->next;
                tail = tail->next;
            }
        }
        if (cur2 == NULL) {
            tail->next = cur1;
        }
        else if (cur1 == NULL) {
            tail->next = cur2;
        }
        return newhead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = NULL;
        for (int i = 0; i < lists.size() - 1; i++) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }
};







//2095. ɾ��������м�ڵ�
//������ɵ��е���
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* slowPrev = head;
    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slowPrev = slow;
        slow = slow->next;
    }
    while (fast && fast->next && fast->next->next == NULL) {
        fast = fast->next;
        slowPrev = slow;
        slow = slow->next;
    }
    slowPrev->next = slow->next;
    free(slow);
    return head;
}

#endif

#include<Windows.h>
int main() {
    cout<<"��˭֪��lwq�������������ٽ�����"<<endl;
    Sleep(5000);
    cout << "��֪����\n" << endl;
    Sleep(5000);
    cout << "lwq����������Լ������ˣ�" << endl;

    return 0;
}





//1721. ���������еĽڵ�
struct ListNode* swapNodes(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* cur = head;
    struct ListNode* node1 = head;
    struct ListNode* node2 = head;
    int k_tmp = k - 1;//ע�����k
    while (k-- && cur) {
        cur = cur->next;
    }
    while (cur) {
        cur = cur->next;
        node1 = node1->next;
    }
    while (k_tmp-- && node2) {//node2����һ������������
        node2 = node2->next;
    }
    if (node1 && node2) {
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }
    return head;
}










//61. ��ת����
//ǰ��ƴ�ӣ���ͷ��һ��
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    if (k == 0) {
        return head;
    }
    struct ListNode* tail = head;
    int len = 0;
    while (tail && tail->next) {
        tail = tail->next;
        len++;
    }
    len++;
    if (len < k) {//�����ת�������ڳ��ȣ�ģһ��
        k %= len;
    }
    tail->next = head;
    struct ListNode* ahead_tail = tail->next;
    int times = len - k;
    while (times--) {
        ahead_tail = ahead_tail->next;
        tail = tail->next;
    }
    tail->next = NULL;
    return ahead_tail;
}



//1669. �ϲ���������
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode* cut1 = list1;
    struct ListNode* cut2 = list1;
    for (int i = 0; i < a - 1; i++) {
        cut1 = cut1->next;
    }
    for (int i = 0; i < b + 1; i++) {
        cut2 = cut2->next;
    }
    cut1->next = list2;
    struct ListNode* tail = list2;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = cut2;
    return list1;
}





//������ 02.05.�������
//�������long long ���������Ҫ��ѡ����
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    long long int ten = 1;
    long ret = 0;
    struct ListNode* cur = l1;
    while (cur) {
        ret += ((cur->val) * ten);
        cur = cur->next;
        if (cur) {
            ten *= 10;
        }
    }
    cur = l2;
    ten = 1;
    while (cur) {
        ret += ((cur->val) * ten);
        ten *= 10;
        cur = cur->next;
    }
    //ret;
    long cnt = 0;//λ��
    long ret_tmp = ret;
    while (ret_tmp) {
        ret_tmp /= 10;
        cnt++;
    }
    struct ListNode* tail = l1;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = l2;
    struct ListNode* newhead = l1;
    struct ListNode* cur1 = newhead;
    struct ListNode* prev = newhead;

    while (cnt--) {
        cur1->val = ret % 10;
        ret /= 10;
        prev = cur1;
        cur1 = cur1->next;
    }
    // if(prev->val==0){
    //     cur1->val=ret%10;
    //     prev=cur1;
    // }

    prev->next = NULL;
    return newhead;
}



//��������͹���
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        vector<int>ret(10000, 0);
        int i = 0;
        int sz = 0;
        while (cur1 && cur2) {
            ret[i] += (cur1->val + cur2->val);
            i++;
            cur1 = cur1->next;
            cur2 = cur2->next;
            sz++;
        }
        while (cur1) {
            ret[i] += (cur1->val);
            cur1 = cur1->next;
            i++;
            sz++;
        }
        while (cur2) {
            ret[i] += (cur2->val);
            cur2 = cur2->next;
            i++;
            sz++;
        }
        //����vector������
        for (int j = 0; j < ret.size(); j++) {
            if (j == sz - 1) {
                if (ret[j] >= 10) {
                    ret[j] -= 10;
                    ret[j + 1] = 1;
                    sz++;
                }
            }
            else {
                if (ret[j] >= 10) {
                    ret[j] -= 10;
                    (ret[j + 1])++;
                }
            }
        }
        //����������
        ListNode* tail = l1;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = l2;
        //��ֵ��ֵ��ȥ
        tail = l1;
        for (int j = 0; j < sz; j++) {
            tail->val = ret[j];
            if (j != sz - 1) {
                tail = tail->next;
            }
        }
        tail->next = NULL;
        return l1;
    }
};