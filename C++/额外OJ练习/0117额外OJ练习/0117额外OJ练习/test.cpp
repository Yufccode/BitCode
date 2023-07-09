


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

//1026. �ڵ���������֮�������ֵ
//�ڱ��������У����ϸ������Ĳ�ֵ
//��ôЯ��
//Я����������ֵ�� ����Ǹ��� �� С���Ǹ����ּ��ɣ�
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return result;
    }

private:
    int result = 0;
    void dfs(TreeNode* node, int up, int low) {
        if (node == nullptr) {
            return;
        }
        result = max(max(abs(node->val - up), abs(node->val - low)), result);
        up = max(node->val, up);
        low = min(node->val, low);
        dfs(node->left, up, low);
        dfs(node->right, up, low);
    }
};





//2476. ��������������ڵ��ѯ
class Solution {
private:
    vector<int>arr;
    void dfs(TreeNode* root)
    {
        if (root == nullptr) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
    int get_index(int key)
    {
        //arr���������� -- ���Խ��ж��ֲ���
        auto it = lower_bound(arr.begin(), arr.end(), key);
        int idx = it - arr.begin();
        return idx;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ret;
        dfs(root);
        for (size_t i = 0; i < queries.size(); i++)
        {
            vector<int>tmp(2, 0);
            if (root == nullptr)
            {
                ret.push_back({ -1,-1 });
                continue;
            }
            int key = queries[i];
            int idx = get_index(key);
            if (idx == arr.size())
            {
                tmp[0] = arr[arr.size() - 1];
                tmp[1] = -1;
                ret.push_back(tmp);
                continue;
            }
            //������Ҫע��������
            else if (idx == 0)
            {
                if (arr[idx] == key)
                {
                    tmp[0] = key;
                    tmp[1] = key;
                }
                else
                {
                    tmp[0] = -1;
                    tmp[1] = arr[0];
                }
                ret.push_back(tmp);
                continue;
            }
            if (arr[idx] == key)
            {
                tmp[0] = key;
                tmp[1] = key;
            }
            else
            {
                tmp[0] = arr[idx - 1];
                tmp[1] = arr[idx];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};