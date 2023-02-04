#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//1464. ��������Ԫ�ص����˻�
//��һ���Լ��ù�ϣ����
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int hash[1001] = { 0 };//��ʼ����ϣ����Ϊ0
        for (int i = 0; i < nums.size(); i++) {
            ++hash[nums[i]];
        }
        int i = 0;
        for (i = 1000; i >= 0; i--) {
            if (hash[i])break;
        }
        int j = 0;
        for (j = i - 1; j >= 0; j--) {
            if (hash[j + 1] > 1) {
                j = i;
                break;
            }
            if (hash[j])break;
        }
        return (i - 1) * (j - 1);
    }
};
#if 0
int main() {
    Solution su;
    vector<int>arr = { 3,4,5,2 };
    su.maxProduct(arr);
}
#endif


//2057. ֵ��ȵ���С����
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i % 10 == nums[i])return i;
        }
        return -1;
    }
};

//2154. ���ҵ���ֵ���� 2
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == original) {
                original *= 2;
            }
        }
        return original;
    }
};


//1207. ��һ�޶��ĳ��ִ���
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>hash(2001, 0);
        for (int i = 0; i < arr.size(); i++) {
            ++hash[arr[i] + 1000];
        }
        sort(hash.begin(), hash.end());
        for (int i = 0; i < hash.size() - 1; i++) {
            if (hash[i] == hash[i + 1] && hash[i] != 0)return false;//ע������Ҫ��0ȥ������Ϊarr[i]�����и���
        }
        return true;
    }
};

//905. ����ż��������
//˫ָ��
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            while (nums[slow] % 2 == 0) {
                slow++;
                if (slow >= nums.size())return nums;
            }
            while (nums[fast] % 2 == 1 || fast <= slow) {
                fast++;
                if (fast >= nums.size())return nums;
            }
            swap(nums[fast], nums[slow]);
            slow++;
            fast++;
        }
        return nums;
    }
};