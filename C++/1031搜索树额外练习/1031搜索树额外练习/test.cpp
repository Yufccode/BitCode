#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<numeric>
#include<queue>

using namespace std;
#elif
#endif

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//783. �����������ڵ���С����
//˼·���ҵ������������
#if 0
class Solution {
private:
    vector<int>arr;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        vector<int>difference;
        for (int i = 0; i < arr.size() - 1; i++) {
            difference.push_back(arr[i + 1] - arr[i]);
        }
        return *min_element(difference.begin(), difference.end());
    }
};
#endif


//538. �Ѷ���������ת��Ϊ�ۼ���
#if 0
class Solution {
private:
    vector<int>arr;
    vector<int>newVal;
    int j = 0;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
    void dfs_assignment(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs_assignment(root->left);
        root->val = newVal[j]; j++;
        dfs_assignment(root->right);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)return nullptr;
        dfs(root);
        int _sum = accumulate(arr.begin(), arr.end(), 0);
        for (int i = 0; i < arr.size(); i++) {
            newVal.push_back(_sum);
            _sum -= arr[i];
        }
        dfs_assignment(root);
        return root;
    }
};


bool insert(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return true;
    }
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while (cur) {
        if (val > cur->val) {
            prev = cur;
            cur = cur->right;
        }
        else if (val < cur->val) {
            prev = cur;
            cur = cur->left;
        }
        else return false;
    }
    cur = new TreeNode(val);
    if (prev->val > val) {
        prev->left = cur;
    }
    else {
        prev->right = cur;
    }
    return true;
}
int main() {
    TreeNode* root = nullptr;
    int arr[] = { 4,1,0,2,3,6,5,7,8 };
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        insert(root, arr[i]);
    }
    Solution().convertBST(root);
    return 0;
}
#endif


//653. ����֮�� IV - �������������
//˼·�����ֲ���
#if 0
class Solution {
private:
    vector<int>arr;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        //���ڿ�ʼ���ֲ���arr����
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum > k) {
                right--;
            }
            else if (sum < k) {
                left++;
            }
            else return true;
        }
        return false;
    }
};
#endif

//230. �����������е�KС��Ԫ��
class Solution {
private:
    vector<int>arr;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return arr[k];
    }
};


//1305. ���ö����������е�����Ԫ��
//����+�鲢
class Solution {
private:
    void dfs(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1;
        vector<int>nums2;
        dfs(root1, nums1);
        dfs(root2, nums2);
        vector<int>ret(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), ret.begin());
        return ret;
    }
};



//��ָ Offer II 044. ������ÿ������ֵ
class Solution {
private:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>node_q;
        if (root == nullptr)return{  };
        vector<vector<int>>ret;
        node_q.push(root);
        while (!node_q.empty()) {
            int curLevelSize = node_q.size();
            ret.push_back(vector<int>());//�ȼ���һ���յ�vector
            for (int i = 0; i < curLevelSize; i++) {
                TreeNode* node = node_q.front();
                node_q.pop();
                ret.back().push_back(node->val);
                if (node->left)node_q.push(node->left);
                if (node->right)node_q.push(node->right);
            }
        }
        return ret;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>>ret = levelOrder(root);
        vector<int>ans;
        for (int i = 0; i < ret.size(); i++) {
            ans.push_back(*max_element(ret[i].begin(), ret[i].end()));
        }
        return ans;
    }
};




//��ָ Offer 32 - III.���ϵ��´�ӡ������ III
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>node_q;
        if (root == nullptr)return{  };
        vector<vector<int>>ret;
        node_q.push(root);
        while (!node_q.empty()) {
            int curLevelSize = node_q.size();
            ret.push_back(vector<int>());//�ȼ���һ���յ�vector
            for (int i = 0; i < curLevelSize; i++) {
                TreeNode* node = node_q.front();
                node_q.pop();
                ret.back().push_back(node->val);
                if (node->left)node_q.push(node->left);
                if (node->right)node_q.push(node->right);
            }
        }
        //����һ��ret����
        for (int i = 1; i < ret.size(); i += 2) {
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};


//637. �������Ĳ�ƽ��ֵ
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>node_q;
        if (root == nullptr)return{  };
        vector<vector<int>>ret;
        node_q.push(root);
        while (!node_q.empty()) {
            int curLevelSize = node_q.size();
            ret.push_back(vector<int>());//�ȼ���һ���յ�vector
            for (int i = 0; i < curLevelSize; i++) {
                TreeNode* node = node_q.front();
                node_q.pop();
                ret.back().push_back(node->val);
                if (node->left)node_q.push(node->left);
                if (node->right)node_q.push(node->right);
            }
        }
        vector<double>ans;
        for (int i = 0; i < ret.size(); i++) {
            ans.push_back(accumulate(ret[i].begin(), ret[i].end(), 0) / ret[i].size());
        }
        return ans;
    }
};


//606. ���ݶ����������ַ���
class Solution {
private:
    string ret;
    void dfs(TreeNode* root) {
        if (root == nullptr)return;
        ret += root->val + '0';
        ret += '(';
        dfs(root->left);
        dfs(root->right);
        ret += ')';
    }
public:
    string tree2str(TreeNode* root) {
        dfs(root);
        //ɾ��û�õ�����
        int cur = 0;
        while (cur < ret.size() - 1) {
            if (ret[cur] == '(' && ret[cur + 1] == ')') {
                ret.erase(ret.begin() + cur);
            }
            else {
                cur++;
            }
        }
        return ret;
    }
};