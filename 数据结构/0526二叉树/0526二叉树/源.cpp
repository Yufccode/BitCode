#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cassert>
using namespace std;

typedef int BTDataType;
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

//������������
//�����������
//��0522������


//bfs�������
//��0522������
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
		std::cout << front->data << " ";
		q.pop();
		if (front->_left) {
			q.push(front->_left);
		}
		if (front->_right) {
			q.push(front->_right);
		}
	}
	std::cout << std::endl;
}



//�ж�һ�ö������ǲ�����ȫ������
//�����ò���������ѿ�Ҳ�뵽�������棬����պ��滹�зǿգ��Ͳ�����ȫ������
bool TreeComplete(BTNode* root) {
	queue<BTNode*>q;
	if (root) {
		//����ڵ㲻Ϊ��
		q.push(root);
	}
	while (!q.empty()) {
		//������в�Ϊ��
		BTNode* front = q.front();
		q.pop();
		if (front->_left == nullptr);
		if (front) {
			q.push(front->_left);
			q.push(front->_right);
		}
		else {
			//��ʱ��������-����
			break;
		}
	}
	//�������ȫ�ǿգ�������ȫ��������������зǿգ��Ͳ�����ȫ������
	while (!q.empty()) {
		BTNode* front = q.front();
		q.pop();
		if (front)return false;
	}
	return true;
}


int main() {
	BTNode* root;
	root = CreatBinaryTree();

	LevelOrder(root);
	printf("TreeComplete:%d\n", TreeComplete(root));
	return 0;
}