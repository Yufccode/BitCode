#define _CRT_SECURE_NO_WARNINGS 1



#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

#if 0
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
 
//965. ��ֵ������
//������Լ�д��
class Solution {
private:
    bool ret = true;
    void dfs(TreeNode* root, int x) {
        if (root == NULL)return;
        if (root->val != x)ret = false;
        if (ret == false)return;
        dfs(root->left, x);
        dfs(root->right, x);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        dfs(root, root->val);
        return ret;
    }
};


//����-��������ֵ��dfs
class Solution {
private:
    bool flag = true;
    void PreOrderCompare(TreeNode* root, int val) {
        if (root == NULL || flag == false)return;
        if (root->val != val)flag = false;
        PreOrderCompare(root->left, val);
        PreOrderCompare(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)return true;
        PreOrderCompare(root, root->val);
        return flag;
    }
};


//���ַ���Ҫѧ�ᣡ
//������ֵ��
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)return true;
        if (root->left && root->left->val != root->val) return false;
        if (root->right && root->right->val != root->val)return false;
        //�ߵ���һ����˵��������������һ���ģ�����������
        //�����������µݹ飡
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
    //��һ��չ��ͼ��һ�����һ��
    //�ݹ鲻�Ƿ��ص����棡�Ƿ��ص���һ�㣡
};



//100. ��ͬ����
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //�������Ҫ������ֵ��һ��Ҫץ����ȣ�������ץ���
        if (p == NULL && q == NULL)return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))return false;
        if (p->val != q->val)return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};




//101. �Գƶ�����
//������Լ�д��
class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //�������Ҫ������ֵ��һ��Ҫץ����ȣ�������ץ���
        if (p == NULL && q == NULL)return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))return false;
        if (p->val != q->val)return false;
        //������΢��һ�£�һ��������ܣ�һ�����ұ���
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)return true;
        if (root->left == NULL && root->right == NULL)return true;
        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))return false;
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        return isSameTree(p, q);
    }
};


//����д��
class Solution {
public:
    bool compare(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)return true;
        if ((!root1 && root2) || (!root2 && root1))return false;
        if (root1->val != root2->val)return false;
        return compare(root1->left, root2->right) && compare(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)return true;
        //���ǿգ��Ƚ���������������
        return compare(root->left, root->right);
    }
};



//572. ��һ����������
class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //�������Ҫ������ֵ��һ��Ҫץ����ȣ�������ץ���
        if (p == NULL && q == NULL)return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))return false;
        if (p->val != q->val)return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
#if 0
        if (root == NULL && subRoot == NULL)return true;
        if ((root == NULL && subRoot != NULL) || (root != NULL && subRoot == NULL))return false;//����϶�û��
#endif
        if (root == NULL)return false;//����Ҳ�ǿ��Ե�
        //�ҵ��˾ͷ���true
        if (isSameTree(root, subRoot))return true;
        //�Ҳ�������������
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

#endif

//ţ��KY11 �������ı��� ���Ӽ��μ�
//����������֮�����������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef char BTDataType;
typedef struct BinaryTreeNode {
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
    BTDataType data;
}BTNode;

BTNode* BuyNode(BTDataType x) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);
    node->data = x;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}
//�������ǰ�򹹽��������Ĺ���
BTNode* CreatTree(char* str, int* pi) {//ͬ���������ַ
    if (str[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    //
    BTNode* root = BuyNode(str[(*pi)++]);
    root->_left = CreatTree(str, pi);
    root->_right = CreatTree(str, pi);
    return root;
}
void InOrder(BTNode* root) {
    if (root == NULL)return;
    InOrder(root->_left);
    printf("%c ", root->data);
    InOrder(root->_right);
}
int main() {
    char str[100] = { 0 };
    scanf("%s", str);
    int i = 0;
    BTNode* root = CreatTree(str, &i);
    InOrder(root);
    return 0;
}