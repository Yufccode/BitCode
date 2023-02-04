#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

//������ 17.10. ��ҪԪ��
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>hash;
        for (int i = 0; i < nums.size(); i++) {
            ++hash[nums[i]];
            if (hash[nums[i]] > nums.size() / 2) {
                return nums[i];
            }
        }
        return -1;
    }
};



//��ָ Offer 38. �ַ���������
class Solution {
private:
    void my_sort(string& s) {
        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = 0; j < s.size() - 1 - i; j++) {
                if (s[j] > s[j + 1]) {
                    swap(s[j], s[j + 1]);
                }
            }
        }
    }
    vector<string>ret;
    string path;
    void dfs(string s, vector<bool>used) {
        if (path.size() == s.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i && s[i] == s[i - 1] && used[i - 1] == false)continue;
            if (used[i] == true)continue;
            path.push_back(s[i]);
            used[i] = true;
            dfs(s, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<string> permutation(string s) {
        my_sort(s);
        vector<bool>used(s.size() + 1, false);
        dfs(s, used);
        return ret;
    }
};


//��ָ Offer 50. ��һ��ֻ����һ�ε��ַ�
class Solution {
public:
    char firstUniqChar(string s) {
        int hash[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            ++hash[s[i] - 'a'];
        }
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a'] == 1)return s[i];
        }
        return ' ';
    }
};


//��ָ Offer 53 - I. �����������в������� I
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == target)break;
        }
        //���û���������
        if (i == nums.size())return 0;
        int start = i;
        int fast = i;
        while (fast < nums.size() && nums[fast] == nums[start]) {
            fast++;
        }
        return fast - start;
    }
};


//��ָ Offer 53 - II. 0��n-1��ȱʧ������
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() + 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n - 1;
    }
};