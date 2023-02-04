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


//445. ������� II
//���������ĸ��ӣ����˺ܶ�Σ�Ҫ���Ǻܶ�����
//����˼·��
//��������ȣ�Ȼ�����ÿһλ
//push��һ��vector����
//����vector���������
//���λ�����ȣ��Ž����������ٹ�
//�����Ϊ�������������Ȱ�������������һ����
//��һ��һ���Ž�ȥ
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>arr;
        int len1 = 0;
        int len2 = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        //�󳤶�
        while (cur1) {
            cur1 = cur1->next;
            len1++;
        }
        while (cur2) {
            cur2 = cur2->next;
            len2++;
        }
        //cur1��2���Լ�����
        cur1 = l1;
        cur2 = l2;
        //����ָ�룬�ȰѲ�����ӵ�push��ȥ����ָ�����
        if (len1 > len2) {
            int k = len1 - len2;
            while (k-- && cur1) {
                arr.push_back(cur1->val);
                cur1 = cur1->next;
            }
        }
        else {
            int k = len2 - len1;
            while (k-- && cur2) {
                arr.push_back(cur2->val);
                cur2 = cur2->next;
            }
        }
        //����ָ��ͬʱ��
        while (cur1 && cur2) {
            arr.push_back(cur1->val + cur2->val);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        //����arr����
        int i = 0;//��������
        for (int i = 1; i < arr.size(); i++) {
            int x = i;
            //ΪʲôҪ��while����Ϊ��������������λ
            //��һ��x�ã�����Ӱ�����������i
            while (x > 0 && arr[x] >= 10) {//������>0����>=0������--��ʱ�������Խ��
                arr[x] -= 10;
                arr[x - 1]++;
                x--;
            }
        }
        //�Ž�������
        //�Ȱ�����������������
        ListNode* tail = l1;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = l2;
        //�ٰ�tail�û�����������
        tail = l1;
        int j = 0;
        ListNode* prev = tail;
        while (tail && j < arr.size()) {
            if (tail == l1 && arr[0] >= 10) {//�����һ��λ�õ�vector���ڵ���10��˵��Ҫ���Ŷ�һ���ڵ�
                //����ֱ��һ����1����һ����arr[0]-10,��Ϊarr[0]��û�б�������
                tail->val -= 10;
                tail->val = 1;
                tail->next->val = arr[0] -= 10;
                prev = tail->next;
                tail = tail->next->next;
                j++;
                //j���ڿ�������
                //tial���ڿ�������
            }
            else {
                tail->val = arr[j];
                prev = tail;
                tail = tail->next;
                j++;
            }
        }
        //���Ҫ���ˣ����һ���ڵ�->next�ÿ�
        //������Ҫһ��prev����ҪҲ����
        //�������������һ��Ԫ�ص�ʱ������ָ��tail��Ҫ����
        //������ҪprevҲ����
        prev->next = NULL;
        return l1;
    }
};




//25. K ��һ�鷭ת����
//���ѵ��⣬�ύһ�ι�������������������������
//����һ���ڱ�λ��ͷ�ڵ㣡
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //����һ���ڱ���
        ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
        newhead->next = head;
        ListNode* tail = newhead;
        ListNode* cur = tail;
        while (cur) {
            for (int i = 0; i < k && cur; i++) {
                cur = cur->next;
            }
            if (cur == NULL)break;
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = NULL;
            ListNode* _new = reverseList(tail->next);
            tail->next = _new;
            //��β
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = cur;
            cur = tail;
        }
        return newhead->next;
    }
};


//������ 02.03. ɾ���м�ڵ�
class Solution {
public:
    void deleteNode(ListNode* node) {
        //���԰���һ����ֵ�������ٰ���һ��ɾ��������
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


//2. �������
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //��Ϊ���������õģ�������ʵ���ø�vector����Ҳ���ԣ�ֱ�ӼӾ����ˣ�������������Ҫ�����������򲻹���
        vector<int>arr;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 && cur2) {
            arr.push_back(cur1->val + cur2->val);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1) {
            arr.push_back(cur1->val);
            cur1 = cur1->next;
        }
        while (cur2) {
            arr.push_back(cur2->val);
            cur2 = cur2->next;
        }
        //����vector����ֵ
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] >= 10) {
                arr[i] -= 10;
                arr[i + 1]++;
            }
        }
        if (arr[arr.size() - 1] >= 10) {
            arr[arr.size() - 1] -= 10;
            arr.push_back(1);
        }
        //������������������
        cur1 = l1;
        while (cur1->next) {
            cur1 = cur1->next;
        }
        cur1->next = l2;
        cur1 = l1;
        //�Ž�ȥ
        int j = 0;
        ListNode* prev = l1;
        while (cur1 && j < arr.size()) {
            cur1->val = arr[j];
            j++;
            prev = cur1;
            cur1 = cur1->next;
        }
        prev->next = NULL;
        return l1;

    }
};


//328. ��ż����
//�Լ�д�ĳ�ʱ�ˣ�������O(n)�ģ���֪��Ϊʲô��ʱ��
//�Լ�д��
//��֪���𰸶Բ��ԣ�һֱ��ʾ��ʱ
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //����Ҫ���������ڵ����
        if (head == NULL || head->next == NULL)return head;
        ListNode* head2 = head->next;
        ListNode* tail = head2;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur && cur->next) {
            tail->next = cur;
            prev->next = cur->next;
            tail = tail->next;
            cur = cur->next->next;
        }
        tail->next = NULL;
        //�������ڵ��β
        ListNode* odd = head;
        while (odd->next) {
            odd = odd->next;
        }
        odd->next = head2;
        return head;
    }
};

//���
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};