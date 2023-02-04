#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//��ͨ����ʽ������-��ɾ���û������
//����д洢����-������˳�������

//1.Ϊ�˺���ѧϰ�����Ӷ����������
//     ��������������AVL�����������B���ȣ�-���ٵ���������
//2.�ܶ�OJ��������ͨ��������

//��Ҫѧϰ���������ƽṹ


//����
//ǰ�к��� DFS
//������� BFS

//ǰ����� ��-������-������
//������� ������-��-������
//������� ������-������-��

typedef int BTDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType data;
}BTNode;

//���ִ�һ���������������ȱ����ɾ���
/*
*        1
*      2   4
*    3    5 6
*/
BTNode* BuyNode(BTDataType x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;
	node3->_right = node7;
	return node1;
}
/*
*        1
*      2   4
*    3    5 6
      7
*/


//ǰ�����
void PreOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//��������С
int TreeSize(BTNode* root);
int TreeSize_pro(BTNode* root);
//������Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root);
//���k��ڵ�ĸ���
int TreeKLevel(BTNode* root, int k);
//������������
int TreeDepth(BTNode* root);
//���Ҷ�������ֵΪx�Ľ��
BTNode* TreeFind(BTNode* root, BTDataType x);
//���ٶ�����
void TreeDestroy(BTNode* root);
//�������
void LevelOrder(BTNode* root);


int count = 0;//��������Сȫ�ֱ���
int main() {
	BTNode* root;
	root = CreatBinaryTree();

	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");

	count = 0;//ÿ�ε���֮ǰ��Ҫ��Ϊ0
	//printf("TreeSize:%d\n", TreeSize(root));

	printf("TreeSize:%d\n", TreeSize_pro(root));

	printf("TreeLeafSize:%d\n", TreeLeafSize(root));

	printf("TreeKLevel:%d\n", TreeKLevel(root, 1));
	printf("TreeKLevel:%d\n", TreeKLevel(root, 2));
	printf("TreeKLevel:%d\n", TreeKLevel(root, 3));

	printf("TreeFind:%d\n", TreeFind(root, 5)->data);

	printf("TreeDepth:%d\n", TreeDepth(root));

	LevelOrder(root);

	//���ٶ�����
	TreeDestroy(root);
	root = NULL;//��Ϊ������һ��ָ�룬�����ڽӿ������ÿ�û��
	return 0;
}
//�����㷨



//ǰ�����
void PreOrder(BTNode* root) {
	//1 2 3 # # # 4 5 # # 6 # #
	if (root == NULL) {
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->_left);
	PreOrder(root->_right);
}
//�������
void InOrder(BTNode* root) {
	//# 3 # 2 # 1 # 5 # 4 # 6 #
	if (root == NULL) {
		printf("# ");
		return;
	}
	InOrder(root->_left);
	printf("%d ", root->data);
	InOrder(root->_right);
}
//�������
void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("# ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%d ", root->data);
}


//��������С
//���������ȫ�ֱ�����ʵ����ȱ�ݵ�
//����ڲ���ϵͳ�����̵߳�ʱ��countҲ���������
#if 0
int TreeSize(BTNode* root) {
	//������˼·
	if (root == NULL)return;
	++count;
	TreeSize(root->_left);
	TreeSize(root->_right);
	return count;
}
#endif
int TreeSize_pro(BTNode* root) {
	//��֧��˼·
	return root == NULL ? 0 : 
		TreeSize_pro(root->_left) + TreeSize_pro(root->_right) + 1;
}


//������Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root) {
	if (root == NULL)return 0;
	if (root->_left == NULL && root->_right == NULL)return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}


//���k��ڵ�ĸ���
int TreeKLevel(BTNode* root, int k) {
	//�������ĵ�k-1��+������k-1��
	assert(k >= 1);
	if (root == NULL)return 0;
	if (k == 1)return 1;
	//˵��Ҫ��������
	return TreeKLevel(root->_left, k - 1) + TreeKLevel(root->_right, k - 1);
}

//������������
int fmax(int a, int b) {
	return a > b ? a : b;
}
int TreeDepth(BTNode* root) {
	if (root == NULL)return 0;
	//return fmax(TreeDepth(root->_left), TreeDepth(root->_right)) + 1;//--����Ҳ�ǶԵ�
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);
	return fmax(leftDepth, rightDepth) + 1;
}


//���Ҷ�������ֵΪx�Ľ��
//���Ҫ��ջ֡ͼ�������
BTNode* TreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)return NULL;
	if (root->data == x)return root;
	//�������Լ�д��
	//if(root->_left)	return TreeFind(root->_left, x);
	//if (root->_right)return TreeFind(root->_right, x);

	BTNode* ret1 = TreeFind(root->_left, x);
	if (ret1)return ret1;
	BTNode* ret2 = TreeFind(root->_right, x);
	if (ret2)return ret2;

	return NULL;
}


//ǰ�������ʺ�dfs��

//����������� dfs  �ݹ�
//����������� bfs  ���и������


//���ٶ�����
void TreeDestroy(BTNode* root) {
	if (root == NULL)return;
	TreeDestroy(root->_left);
	TreeDestroy(root->_right);
	free(root);
}


#include<queue>
#include<iostream>
void LevelOrder(BTNode* root) {
	//��������
	//˼·
	//��һ���ȥ��ÿ������д���һ�������
	std::queue<BTNode*>q;
	if (root) {
		//����ڵ㲻Ϊ��
		q.push(root);
	}
	while (!q.empty()) {
		//������в�Ϊ��
		BTNode* front = q.front();
		//�˴�������
		std::cout << front->data << " ";
		q.pop();
		//����һ�������
		if (front->_left) {
			q.push(front->_left);
		}
		if (front->_right) {
			q.push(front->_right);
		}
	}
	std::cout << std::endl;
}