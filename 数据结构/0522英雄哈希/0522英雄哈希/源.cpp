#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//1748. ΨһԪ�صĺ�
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int hash[101] = { 0 };
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ++hash[nums[i]];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] == 1) {
                sum += nums[i];
            }
        }
        return sum;
    }
};


//2206. �����黮�ֳ��������
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int hash[501] = { 0 };//����ǵ�Ҫ��ʼ��
        for (int i = 0; i < nums.size(); i++) {
            ++hash[nums[i]];
        }
        for (int i = 0; i < nums.size(); i++) {
            //�ж�����������д��hash[i]&1
            if (hash[nums[i]] % 2 == 1)return false;
        }
        return true;
    }
};



//1832. �жϾ����Ƿ�Ϊȫ��ĸ��
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int hash[256] = { 0 };//ֱ�ӿ�ֻ����ĸ��һ��Ҳ���ԣ�����ֱ�ӿ�256��
                          //��ĸ�ķ�Χ�϶���256֮��
        for (int i = 0; i < sentence.size(); i++) {
            ++hash[sentence[i]];
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (hash[i] == 0)return false;
        }
        return true;
    }
};

//1512. �����Ե���Ŀ
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hash[101] = { 0 };
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            //�������˼�ǣ����hash[nums[j]]��λ����0��Ҳ����û�г��ֹ����Ͳ��ü�
            ans += hash[nums[j]];
            ++hash[nums[j]];
        }
        return ans;
    }
};


//2006. ��ľ���ֵΪ K ��������Ŀ
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int hash[101] = { 0 };
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] + k;
            if (x >= 1 && x <= 100) {
                ans += hash[x];
            }
            x = nums[i] - k;
            if (x >= 1 && x <= 100) {
                ans += hash[x];
            }
            ++hash[nums[i]];
        }
        return ans;
    }
};



//930. ����ͬ�Ķ�Ԫ������
//ǰ׺��+���+��ϣ����
//��ϣ��ʵ�����ÿռ仯ʱ��
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int hash[60010] = { 0 };
        int ans = 0;
        //����ǰ׺��
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
            //ǰ׺������������������ԭ�ص���������������nums[i]����ǰ������Ԫ�صĺ�
        }
        hash[goal] = 1;//��goal���뵽��ϣ����ȥ
        for (int i = 0; i < nums.size(); i++) {
            ans += hash[nums[i]];
            ++hash[nums[i] + goal];
        }
        return ans;
    }
};


//560. ��Ϊ K ��������
//��һ�����һ�����һ�������������һ�ⲻ����0��1
//���ֱ��������ģ���ϣ�Ͼͻᵼ�������±�Խ��
//unordered_map���԰���������ɴ�������ӳ��
class Solution {
private:
    unordered_map<int, int>hash;
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        //�����ĺ���һ��һ����
        //��ʵǰ��Ĺ�ϣ�����������
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        hash.clear();
        hash[k] = 1;
        for (int i = 0; i < nums.size(); i++) {//���Ҫ��ͷ������ϣ����0��ʼ
            ans += hash[nums[i]];
            ++hash[nums[i] + k];
        }
        return ans;
    }
};


//454. ������� II
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>hash;
        hash.clear();
        int ret = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                ++hash[-(nums1[i] + nums2[j])];
            }
        }
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                ret += hash[(nums3[i] + nums4[j])];
            }
        }
        return ret;
    }
};