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


//66. ��һ
//˼·�������ҵ���һ����Ϊ9�����֣�����++��Ȼ������ȫ����Ϊ0
//���ȫ��9���ͷ���һ���µ����飬��С��digits��1��Ȼ���һ������Ϊ1������ȫΪ0
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        // digits �����е�Ԫ�ؾ�Ϊ 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};



//283. �ƶ���
//˫ָ���㷨
//�����ע������ѭ������
//����Խ�����
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prev = 0;
        int cur = 0;
        while (cur < nums.size() - 1) {
            while (nums[prev] == 0 && nums[cur] == 0 && cur < nums.size() - 1) {
                cur++;
            }
            //��ʱcurָ������ֲ�Ϊ0�ˣ�������������
            if (nums[prev] == 0 && nums[cur] != 0 && cur > prev) {
                swap(nums[prev], nums[cur]);
            }
            while (nums[prev] != 0) {
                if (cur == prev) {
                    cur++;
                }
                prev++;
                if (prev == nums.size() - 1)break;
            }
            if (prev == (nums.size() - 1) || cur < prev)
                break;
        }
    }
};





//191. λ1�ĸ���
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1 == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};




//2235. ���������
class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};



//1480. һά����Ķ�̬��
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int>ret;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ret.push_back(sum);
        }
        return ret;
    }
};


//1929. ���鴮��
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ret;
        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(nums[i]);
        }
        return ret;
    }
};

//1920. �������й�������
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ret;
        for (int i = 0; i < nums.size(); i++) {
            ret.push_back(nums[nums[i]]);
        }
        return ret;
    }
};


//1672. ��пͻ����ʲ�����
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        int sum = 0;
        for (int i = 0; i < accounts.size(); i++) {
            sum = 0;
            for (int j = 0; j < accounts[0].size(); j++) {
                sum += accounts[i][j];
            }
            if (sum > max)max = sum;
        }
        return max;
    }
};



//1720. �������������
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ret;
        ret.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            ret.push_back(ret[i] ^ encoded[i]);
        }
        return ret;
    }
};



//2011. ִ�в�����ı���ֵ
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "X++") {
                x++;
            }
            else if (operations[i] == "++X") {
                ++x;
            }
            else if (operations[i] == "X--") {
                x--;
            }
            else if (operations[i] == "--X") {
                --x;
            }
        }
        return x;
    }
};
