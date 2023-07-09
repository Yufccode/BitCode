#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//41. ȱʧ�ĵ�һ������
class Solution {
private:
    int find_one(vector<int>nums) {
        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)break;
        }
        return i;
    }
    void removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //����һ��ɾ�������ظ���Ĵ���
        removeDuplicates(nums);
        //�ȿ��������������ֵ��ʲô�����С�ڵ���0��ֱ�ӷ���1����
        if (nums[nums.size() - 1] <= 0)return 1;
        if (nums[0] > 1)return 1;
        int index = find_one(nums);
        int cmp = 1;
        while (index < nums.size()) {
            if (nums[index] == cmp) {
                cmp++;
                index++;
            }
            else {
                return cmp;
            }
        }
        return cmp;
    }
};