#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;


//4. Ѱ�����������������λ��
class Solution {
private:
    //��дһ���ϲ���������Ľӿ�
    void mergeArrays(vector<int>& ret, vector<int>nums1, vector<int>nums2) {
        int ptr1 = 0;
        int ptr2 = 0;
        //�鲢
        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ret.push_back(nums1[ptr1]);
                ptr1++;
            }
            else if (nums1[ptr1] >= nums2[ptr2]) {
                ret.push_back(nums2[ptr2]);
                ptr2++;
            }
        }
        //����鲢���µ�Ԫ��
        while (ptr1 < nums1.size()) {
            ret.push_back(nums1[ptr1]);
            ptr1++;
        }
        while (ptr2 < nums2.size()) {
            ret.push_back(nums2[ptr2]);
            ptr2++;
        }
    }
    bool is_odd(int x) {
        return x % 2 == 1 ? true : false;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;//�������
        mergeArrays(ret, nums1, nums2);
        return is_odd(ret.size()) ? ret[ret.size() / 2] : ((ret[ret.size() / 2 - 1] + ret[ret.size() / 2]) / 2.0);
    }
};





//239. �����������ֵ
//���Թ��ö�ȥŪ��ûŪ����
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    }
};


//������ 17.19. ��ʧ����������
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ret;
        int cmp = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != cmp) {
                ret.push_back(cmp);
                cmp++;
                i--;
            }
            else {
                cmp++;
            }
            if (ret.size() == 2)break;
        }
        if (ret.size() == 1) {
            ret.push_back(cmp);
        }
        else if (ret.size() == 0) {
            ret.push_back(cmp);
            ret.push_back(cmp + 1);
        }
        return ret;
    }
};