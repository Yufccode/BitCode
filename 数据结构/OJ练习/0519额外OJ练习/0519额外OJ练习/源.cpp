#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

//349. ��������Ľ���
//˫ָ��
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //�Ѿ���������
        int p1 = 0;
        int p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (p1 && nums1[p1] == nums1[p1 - 1]) {
                p1++;
                continue;
            }
            if (p2 && nums2[p2] == nums2[p2 - 1]) {
                p2++;
                continue;
            }
            if (nums1[p1] < nums2[p2]) {
                p1++;
            }
            else if (nums1[p1] > nums2[p2]) {
                p2++;
            }
            else if (nums1[p1] == nums2[p2]) {
                ret.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return ret;
    }
};



//350. ��������Ľ��� II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //�Ѿ���������
        int p1 = 0;
        int p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            //��Ҫ�����ȥ�ؾ�����
            // if (p1 && nums1[p1] == nums1[p1 - 1]) {
            //     p1++;
            //     continue;
            // }
            // if (p2 && nums2[p2] == nums2[p2 - 1]) {
            //     p2++;
            //     continue;
            // }
            if (nums1[p1] < nums2[p2]) {
                p1++;
            }
            else if (nums1[p1] > nums2[p2]) {
                p2++;
            }
            else if (nums1[p1] == nums2[p2]) {
                ret.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return ret;
    }
};


//1470. ������������
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ret;
        int i1 = 0;
        int i2 = n;
        while (i1 < (nums.size() / 2) && i2 < nums.size()) {
            ret.push_back(nums[i1]);
            ret.push_back(nums[i2]);
            i1++;
            i2++;
        }
        return ret;
    }
};



//2089. �ҳ�����������Ŀ���±�
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ret;
        sort(nums.begin(), nums.end());
        //
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};


//1295. ͳ��λ��Ϊż��������
class Solution {
private:
    bool is_Valid(int x) {
        int cnt = 0;
        while (x) {
            x /= 10;
            cnt++;
        }
        if (cnt % 2 == 0)return true;
        else return false;
    }
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (is_Valid(nums[i])) {
                cnt++;
            }
        }
        return cnt;
    }
};

//1512. �����Ե���Ŀ
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//LCP 01. ������
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int cnt = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == answer[i])cnt++;
        }
        return cnt;
    }
};

//2006. ��ľ���ֵΪ K ��������Ŀ
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k)cnt++;
            }
        }
        return cnt;
    }
};


//1431. ӵ������ǹ��ĺ���
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ret;
        int _max = 0;
        //�����
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > _max) {
                _max = candies[i];
            }
        }
        //
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= _max) {
                ret.push_back(true);
            }
            else {
                ret.push_back(false);
            }
        }
        return ret;
    }
};


//1773. ͳ��ƥ������������Ʒ����
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        int key = 0;
        if (ruleKey == "type")key = 0;
        else if (ruleKey == "color")key = 1;
        else if (ruleKey == "name")key = 2;
        for (int i = 0; i < items.size(); i++) {
            if (items[i][key] == ruleValue) {
                cnt++;
            }
        }
        return cnt;
    }
};

//LCP 06. ��Ӳ��
class Solution {
public:
    int minCount(vector<int>& coins) {
        int cnt = 0;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] % 2 == 1) {
                cnt += (coins[i] / 2 + 1);
            }
            else {
                cnt += (coins[i] / 2);
            }
        }
        return cnt;
    }
};