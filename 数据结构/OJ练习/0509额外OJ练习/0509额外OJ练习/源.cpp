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



//������ 02.01. �Ƴ��ظ��ڵ�
class Solution {
private:
    bool is_count(vector<int>arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return true;
            }
        }
        return false;
    }
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        vector<int>arr;
        ListNode* cur = head;
        ListNode* prev = head;
        while (cur) {
            if (is_count(arr, cur->val)) {
                //ɾ��cur��λ��
                prev->next = cur->next;
                cur = cur->next;
            }
            else {
                arr.push_back(cur->val);
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};




//35. ��������λ��
//���ֲ���
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};



//136. ֻ����һ�ε�����
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret ^= nums[i];
        }
        return ret;
    }
};




//217. �����ظ�Ԫ��
class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1])return true;
        }
        return false;
    }
};