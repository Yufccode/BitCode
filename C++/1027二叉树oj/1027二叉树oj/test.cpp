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
#include<assert.h>

using namespace std;

#elif
#endif

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

//105. ��ǰ��������������й��������
//��˼·��ǰ�򴴽���������ָ���������
class Solution {
private:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend) {
        if (inbegin > inend)return nullptr;
        //[inbegin,inend]��������������� -- ���·ָ�Ҫ��
        //prei��������preorder -- ��ΪpreorderҪ��˳����� -- ����������
        TreeNode* root = new TreeNode(preorder[prei]);
        ++prei;
        //�ָ�����
        int ini = 0;
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), root->val);//�������������val
        ini = it - inorder.begin();//����ǿ϶����ҵ���
        //[inbegin,ini-1] ini [ini,inend]
        //���ڵݹ鴴����������������������
        root->left = _buildTree(preorder, inorder, prei, inbegin, ini - 1);
        root->right = _buildTree(preorder, inorder, prei, ini + 1, inend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};



//106. �����������������й��������
//����һ����һ���� -- ����������
class Solution {
private:
    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder, int& prei, int inbegin, int inend) {
        if (inbegin > inend)return nullptr;
        //[inbegin,inend]��������������� -- ���·ָ�Ҫ��
        //prei��������preorder -- ��ΪpreorderҪ��˳����� -- ����������
        TreeNode* root = new TreeNode(postorder[prei]);
        --prei;
        //�ָ�����
        int ini = 0;
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), root->val);//�������������val
        ini = it - inorder.begin();//����ǿ϶����ҵ���
        //[inbegin,ini-1] ini [ini,inend]
        //���ڵݹ鴴����������������������
        root->right = _buildTree(postorder, inorder, prei, ini + 1, inend);
        root->left = _buildTree(postorder, inorder, prei, inbegin, ini - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return _buildTree(postorder, inorder, i, 0, inorder.size() - 1);
    }
};


//144. ��������ǰ�����
/*
1.��·�ڵ�
2.��·�ڵ�������
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* cur = root;
        vector<int>v;
        while (cur || !st.empty()) {
            //��ʼ����һ����
            //1.�ȷ�����·�ڵ�
            while (cur) {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //2.��·�Ľڵ��������
            TreeNode* top = st.top();
            st.pop();

            cur = top->right;//���������������
            //����ľ�����һ��
        }
        return v;
    }
};


//94. ���������������
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>v;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            //1.��·�ڵ���ջ -- ����push��v����
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            //2.����·�ڵ��ջ�г���ʱ�򣬱�ʾ�������Ѿ����ʹ��� -- Ӧ�÷��ʸ�������
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            cur = top->right;//������ -- ����������
            //��ʵ��ǰ�������������Ƿ��ʵ�ʱ���������
            //һ���������ȥ��ʱ��ͽ�v��һ���ǳ��� -- pop��ʱ��Ž�v
        }
        return v;
    }
};

//145. �������ĺ������
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>v;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur || !st.empty()) {
            //1.��·�ڵ���ջ -- ����push��v����
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();//�����ҵ�����ڵ��ʱ���ܲ���ֱ��pop��
            //��һ����
            //��Ϊ�ߵ�����ֻ��˵�� -- top������Ѿ����ʹ���
            //�����ұ��Ƿ���� -- ���ǲ������
            //�ܷ�pop���ܷ���ʵ�ǰ�ڵ�ȡ�����ұ��Ƿ�Ϊ��

            //�����ǰ�ڵ��Ҳ�Ϊ�յ�����£�
            //1.������û�з��� -- ��ʱҪȥ�����ҽڵ�
            //2.�������Ѿ����ʹ��� -- ���ʸ�����ǰ���ڵ�
            //���ַ���
            //a.������ -- ������һ�η��ʵĽڵ��ǲ���ջǰ���ĸ��ڵ�
            //b.��һ�η��ʵ�ǰ�ڵ�֮�� -- �ں���Ÿ�nullptr

            if (top->right == nullptr || top->right == prev) {
                //�ұ�Ϊ�� -- ����ֱ�ӷ���
                //����ǵڶ����� -- Ҳ���Խ���
                v.push_back(top->val);
                prev = top;
                st.pop();
            }
            else {
                cur = top->right;
            }
            //st.pop();
            //v.push_back(top->val);

            //cur = top->right;//������ -- ����������
            //��ʵ��ǰ�������������Ƿ��ʵ�ʱ���������
            //һ���������ȥ��ʱ��ͽ�v��һ���ǳ��� -- pop��ʱ��Ž�v
        }
        return v;
    }
};