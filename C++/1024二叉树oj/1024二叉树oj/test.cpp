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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//606. ���ݶ����������ַ���
//1.���Ҷ�Ϊ�� -- ʡ��
//2.��Ϊ�գ���Ϊ�� -- ʡ��
//tips:����Ҳ��� -- ��ʡ�� -- ��Ϊʡ���˾ͷֲ�����������Ļ����ҵ���
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr)return"";
        string str;
        str += to_string(root->val);

        //��߲�λŶ�Ǹ��������Ϊ���ұ߲�Ϊ�գ���߱���
        if (root->left || root->right) {
            str += '(';
            //�м�Ľ���������
            str += tree2str(root->left);
            str += ')';
        }

        //��Ϊ��һ��Ϊ�տ϶�Ҫʡ��
        if (root->right) {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }
        return str;
    }
};


//102. �������Ĳ������
//˼·����һ����һ��
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if (root == nullptr)return ret;
        queue<TreeNode*>q;
        size_t levelsize = 0;

        q.push(root);
        levelsize = 1;
        while (!q.empty()) {
            //����һ��һ���
            vector<int>path;
            for (size_t i = 0; i < levelsize; ++i) {
                TreeNode* front = q.front();
                q.pop();
                path.push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            ret.push_back(path);
            //��ǰ������ˣ���һ�㶼�������ˣ����е�size������һ������ݸ���
            levelsize = q.size();
        }
        return ret;
    }
};
/** ˫����Ҳ���Խ��������� -- һ��������TreeNode*,һ��������� */



//107. �������Ĳ������ II
//���˼·���������reverseһ��


//236. �������������������
//����1��
//��������ڵ�ֱ��ڵ�ǰ�ڵ�����ߣ���ǰ�ڵ�����������
//O(h*n)
class Solution {
private:
    bool find(TreeNode* sub, TreeNode* x) {
        if (sub == nullptr)return false;
        if (sub == x)return true;
        return find(sub->left, x) || find(sub->right, x);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //��������ڵ�һ�����ҵ���һ�����ҵ��� -- �����ҵ���
        //�����ҵ���� -- ֱ�ӽ����
        //�����ҵ��ұ� -- ֱ�ӽ��ұ�
        if (root == nullptr)return nullptr;
        if (root == p || root == q) {
            return root;
        }
        //�ߵ�����,pq����������
        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = find(root->left, p);
        pInRight = !pInLeft;
        qInLeft = find(root->left, q);
        qInRight = !qInLeft;
        if ((pInLeft && qInRight) || (qInLeft && pInRight))return root;
        else if (pInLeft && qInLeft) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (pInRight && qInRight) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            //������ĿҪ�󲻻��ߵ�����
            assert(false);
        }
    }
};

//�Ż���O(n)
//�ҵ��ڵ��·��
class Solution {
private:
    //������Һ���ǰд����ʵ������һ����
    //ֻ�������Ҷ���İ�·���Ž�path�������
    bool find_path(TreeNode* root, TreeNode* x, stack<TreeNode*>& path) {
        if (root == nullptr)return false;
        path.push(root);
        if (root == x)return true;
        if (find_path(root->left, x, path)) {
            return true;
        }
        if (find_path(root->right, x, path)) {
            return true;
        }
        path.pop();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //��һ��ջ��·��
        stack<TreeNode*>pPath, qPath;
        find_path(root, p, pPath);
        find_path(root, q, qPath);
        //���������ཻ
        while (pPath.size() != qPath.size()) {
            if (pPath.size() > qPath.size()) {
                pPath.pop();
            }
            else if (pPath.size() < qPath.size()) {
                qPath.pop();
            }
        }
        while (pPath.top() != qPath.top()) {
            pPath.pop();
            qPath.pop();
        }
        return pPath.top();
    }
};



//ţ�� JZ36 ������������˫������

/**
 * leftָ�������ǰһ��
 * rightָ������ĺ�һ��.
 */

/*
˼·һ
�� - �� - �� ����left
�� - �� - �� ����right
*/
class Solution {
private:
    void inorderconvert(TreeNode* cur, TreeNode*& prev) {//prevҪ������ -- ��ΪprevҪ��
        if (cur == nullptr)return;
        inorderconvert(cur->left, prev);
        cur->left = prev;
        if (prev)
            prev->right = cur;
        prev = cur;

        inorderconvert(cur->right, prev);
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        inorderconvert(pRootOfTree, prev);
        //�ҵ�ͷ������
        TreeNode* head = pRootOfTree;
        //���������Ҿ�����
        while (head && head->left) {
            head = head->left;
        }
        return head;
    }
};




////��ָ Offer 36. ������������˫������
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
//ע�������ѭ����
//���������һ��
//������һ��ͷβ����������
class Solution {
private:
    void inorder(Node* root, Node*& prev) {
        if (root == nullptr)return;
        inorder(root->left, prev);
        root->left = prev;
        if (prev)
            prev->right = root;
        prev = root;//�ݹ����
        inorder(root->right, prev);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)return nullptr;
        Node* prev = nullptr;
        inorder(root, prev);
        Node* head = root;
        while (head && head->left)head = head->left;
        Node* tail = root;
        while (tail && tail->right)tail = tail->right;
        //��ʱ�ҵ�head��tail��
        head->left = tail;
        tail->right = head;
        return head;
    }
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