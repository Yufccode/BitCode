#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

//557. ��ת�ַ����еĵ��� III
void reverseString(char* s, int sSize) {
    char* left = s;
    char* right = s + sSize - 1;
    char tmp = 0;
    tmp = *left;
    *left = *right;
    *right = '\0';
    if (sSize > 2) {
        reverseString(s + 1, sSize - 2);
    }
    *right = tmp;
}
char* reverseWords(char* s) {
    char* cur = s;
    char* fast = s;
    while (*cur) {
        while (*fast && *fast != ' ')fast++;
        reverseString(cur, fast - cur);
        cur = fast;
        if (*cur == ' ') {
            cur++;
            fast++;
        }
    }
    return s;
}

//1941. ����Ƿ������ַ����ִ�����ͬ
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        //��ϣ
        vector<int>hash(27, 0);
        for (int i = 0; i < s.size(); i++) {
            ++hash[s[i] - 'a'];
        }
        sort(hash.begin(), hash.end());
        for (int i = 0; i < hash.size() - 1; i++) {
            if (hash[i] == 0)continue;
            if (hash[i] != hash[i + 1] && hash[i + 1] != 0)return false;
        }
        return true;
    }
};


//��ָ Offer 05. �滻�ո�
class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ret += "%20";
            }
            else {
                ret += s[i];
            }
        }
        return ret;
    }
};

//2053. �����е� K ����һ�޶����ַ���
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>hash;
        for (int i = 0; i < arr.size(); i++) {
            ++hash[arr[i]];
        }
        int i = 0;
        for (i = 0; i < arr.size(); i++) {
            if (hash[arr[i]] == 1) {
                k--;
                if (k == 0) {
                    return arr[i];
                }
            }
        }
        if (k)return "";
        return nullptr;
    }
};


//��ָ Offer II 083. û���ظ�Ԫ�ؼ��ϵ�ȫ����
class Solution {
private:
    vector<int>path;
    vector<vector<int>>ret;
    void dfs(vector<int>nums, vector<bool>used) {
        if (path.size() == nums.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true)continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size() + 1, false);
        dfs(nums, used);
        return ret;
    }
};



//��ָ Offer 56 - II. ���������ֳ��ֵĴ��� II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n] ++;
        int ans;
        for (auto pr : mp) {
            if (pr.second == 1) {
                ans = pr.first;
                break;
            }
        }
        return ans;
    }
};