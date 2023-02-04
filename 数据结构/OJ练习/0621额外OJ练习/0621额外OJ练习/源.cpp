#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

//404. ��Ҷ��֮��
#if 0
class Solution {
private:
    int ret = 0;
    void dfs(TreeNode* root) {
        if (root == nullptr)return;
        if (root->left && root->left->right == NULL && root->left->left == NULL) {
            ret += root->left->val;
            dfs(root->left);
        }
        else if (root->left) {
            dfs(root->left);
        }
        else if (root->left == nullptr) {
            dfs(root->left);
        }
        dfs(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return ret;
    }
};


//872. Ҷ�����Ƶ���
class Solution {
private:
    vector<int>nums1;
    vector<int>nums2;
    void dfs(TreeNode* root, vector<int>& ret) {
        if (root == nullptr)return;
        if (!root->left && !root->right) {
            ret.push_back(root->val);
        }
        dfs(root->left, ret);
        dfs(root->right, ret);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, nums1);
        dfs(root2, nums2);
        if (nums1.size() != nums2.size())return false;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] != nums2[i])return false;
        }
        return true;
    }
};


//671. �������еڶ�С�Ľڵ�
class Solution {
private:
    //�����õ���һ�����̵ķ���
    vector<int>nums;
    void dfs(TreeNode* root) {
        if (!root)return;
        nums.push_back(root->val);
        dfs(root->right);
        dfs(root->left);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[0])return nums[i];
        }
        return -1;
    }
};
#endif


//1022. �Ӹ���Ҷ�Ķ�������֮��
class Solution {
private:
    vector<int>ret;
    vector<int>path;
    void sigma(vector<int>path) {
        int path_sum = 0;
        int j = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            path_sum += pow(2, j) * path[i];
            j++;
        }
        ret.push_back(path_sum);
    }
    void dfs(TreeNode* root) {
        if (!root)return;
        //���������Ҷ�ӽڵ㣬����·���ϵ�ֵ
        if (!root->right && !root->left) {
            path.push_back(root->val);
            sigma(path);
            path.pop_back();
            return;
        }
        if (root->left) {
            path.push_back(root->val);
            dfs(root->left);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->val);
            dfs(root->right);
            path.pop_back();
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        int sum = 0;
        //ͳ��ret����ĺ�
        for (int i = 0; i < ret.size(); i++) {
            sum += ret[i];
        }
        return sum;
    }
};