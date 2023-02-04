#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

#if 0

//��ָ Offer II 076. �����еĵ� k �������
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};



//503. ��һ������Ԫ�� II
class Solution {
private:
    int find_bigger(vector<int>nums, int startIndex) {
        int target = nums[startIndex];
        for (int i = startIndex + 1;; i++) {
            if (i == nums.size())i = 0;
            if (nums[i] > target)return nums[i];
            if (i == startIndex)break;
        }
        return -1;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ret;
        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(find_bigger(nums, i));
        }
        return ret;
    }
};

//�򺼸���������
class Solution {
private:
    int ret = 0;
    void dfs(vector<int>nums, int sum, int target) {
        if (sum == target) {
            ret++;
            return;
        }
        for (int i = 0; i < nums.size() && nums[i] + sum <= target; i++) {
            sum += nums[i];
            dfs(nums, sum, target);
            sum -= nums[i];
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());//�������ܹؼ�
        dfs(nums, 0, target);
        return ret;
    }
};




//80. ɾ�����������е��ظ��� II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)return nums.size();
        //�ź�����
        //[1,1,1,2,3,3,3,4,4,5,5,5,6,7,7,7];
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            while (fast < nums.size() && nums[fast] == nums[slow]) {
                fast++;
            }
            int stepback = 0;
            if (fast - slow > 2) {
                //ɾ����ɾ������--fast-slow-2��
                int sz = fast - slow - 2;
                auto it = nums.begin() + fast;
                nums.erase(it - sz, it);
                //
                stepback = sz;
            }
            fast -= stepback;
            slow = fast;
        }
        return nums.size();
    }
};
int main() {
    vector<int>nums = { 1,2,2,2};
    Solution su;
    int ret = su.removeDuplicates(nums);
    return 0;
}
#endif



//442. �������ظ�������
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ret;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};