#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};
 
//203. �Ƴ�����Ԫ��
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = head;
    struct ListNode* cur = head;
    while (cur) {
        if (head->val == val) {
            head = head->next;
            cur = cur->next;
        }
        else if (cur->val == val) {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


//β�巨
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;
    struct ListNode* tail = newhead;
    if (head == NULL) {
        return head;
    }
    while (cur) {
        if (cur->val == val) {
            struct ListNode* del = cur;
            cur = cur->next;
            free(del);
        }
        else if (cur->val != val) {
            if (tail == NULL) {
                newhead = tail = cur;
            }
            else {
                tail->next = cur;
                tail = tail->next;
            }
            cur = cur->next;
        }
    }
    if (tail)
        tail->next = NULL;
    return newhead;
}

//���ڱ�λͷ�ڵ��β�巨
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* tail = NULL;
    struct ListNode* cur = head;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;

    while (cur) {
        if (cur->val == val) {
            struct ListNode* del = cur;
            cur = cur->next;
            free(del);
        }
        else {
            //β��
            //tail���ʱ�����п��ˣ�ֱ��β��
            tail->next = cur;
            tail = tail->next;
            cur = cur->next;
        }
    }
    tail->next = NULL;
    return head->next;
}



//206. ��ת����
//�Լ����ģ�ͷ�巨
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

//�����ͷ��
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while (cur) {
        struct ListNode* next = cur->next;
        //ͷ��
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}


//����ָ��
//�Լ�д�ģ�����ָ��
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



//ţ��  �����е�����k�����
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* ret = NULL;
    struct ListNode* cur = pListHead;
    //k--;
    while (cur && k--) {
        cur = cur->next;
    }
    if (k && cur == NULL) {//����ߵ����û�г�����˵�����ǵ�k��������ڵ�������
        return NULL;
    }
    ret = pListHead;
    while (cur) {
        cur = cur->next;
        ret = ret->next;
    }
    return ret;
}





//21. �ϲ�������������
//�Լ����� 
//�鲢����Ҳ����ͬ��˼��
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



// 83. ɾ�����������е��ظ�Ԫ��---�Լ�������Ŀ
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* prev = head;
    struct ListNode* cur = head->next;
    while (cur) {
        if (cur->val == prev->val) {
            prev->next = cur->next;
            cur = cur->next;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


//237. ɾ�������еĽڵ�---�Լ�������
void deleteNode(struct ListNode* node) {
    struct ListNode* cur = node;
    struct ListNode* prev = node;
    while (cur->next) {
        cur->val = cur->next->val;
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
}


//�Լ�������
//��ָ Offer 06. ��β��ͷ��ӡ����
void _reverseArray(int* arr, int size) {
    int* right = arr;
    int* left = arr + size - 1;
    while (right < left) {
        int tmp = *right;
        *right = *left;
        *left = tmp;
        left--;
        right++;
    }
}
int* reversePrint(struct ListNode* head, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 10000);
    int i = 0;//i����size
    while (head) {
        arr[i] = head->val;
        i++;
        head = head->next;
    }
    _reverseArray(arr, i);
    *returnSize = i;
    return arr;
}