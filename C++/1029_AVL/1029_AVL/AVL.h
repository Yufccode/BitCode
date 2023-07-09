#pragma once

#include<map>
#include<set>
#include<algorithm>
#include<assert.h>
#include<time.h>
using namespace std;


template<class K,class V>
struct AVLNode {
public:
	AVLNode<K, V>* _left;
	AVLNode<K, V>* _right;
	AVLNode<K, V>* _parent;
	pair<K, V>_kv;
	int _bf;  //balance factor
public:
	AVLNode(const pair<K, V>& kv)
		:_left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0) {}
};




//��θ���ƽ������
//�����ת
template<class K, class V>
struct AVL {
	typedef AVLNode<K, V>Node;
private:
	Node* _root = nullptr;
private:
	//����
	void rotate_left(Node* parent) {
		//��Ȼ���ǻ�Ҫע�⴦��parentָ��
		//parent��subR������Ϊ�� -- ������subRL����Ϊ��
		//1.parent����������
		//2.parent�������ĸ�
		//������һ��ƽ������
		//ֻ��subR��parent��ƽ�������ܵ���Ӱ��
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL) {
			subRL->_parent = parent;
		}
		Node* ppNode = parent->_parent;//��¼һ��ԭ��parent��parent
		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			//���ppNode==nullpt���ǲ�����������
			if (ppNode->_left == parent) {
				ppNode->_left = subR;
			}
			else {
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
		//����һ��ƽ������
		subR->_bf = parent->_bf = 0;//�����ͼ������
	}
	//�ҵ���
	void rotate_right(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR) {
			subLR->_parent = parent;
		}
		Node* ppNode = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (_root == parent) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent) {
				ppNode->_left = subL;
			}
			else {
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		//����ƽ������
		subL->_bf = parent->_bf = 0;
	}
	//����˫��
	void rotate_left_right(Node* parent) {
		//Ҫ�ڵ���֮ǰ��¼һ�£���Ϊ����֮��ƽ�����ӻ��
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;//��¼һ��subLR��ƽ������
		rotate_left(parent->_left);//������߽���һ������
		rotate_right(parent);//�ٶ��Լ�����һ������ת
		//����������������ƽ�����Ӹ����أ�

		subLR->_bf = 0;//һ��Ҫ��ͼ�����������subLR���ն���0
		if (bf == 1) {
			//���1
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1) {
			//���2
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0) {
			//���3
			parent->_bf = 0;
			subL->_bf = 0;
		}
		else assert(false);
	}
	//����˫��
	void rotate_right_left(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		rotate_right(parent->_right);
		rotate_left(parent);
		subRL->_bf = 0;
		if (bf == 1) {
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1) {
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0) {
			subR->_bf = 0;
			parent->_bf = 0;
		}
		else assert(false);
	}
public:
	//�����Ȳ�����pair����ʱ�����Ƿ�װmap��ʱ���ڸ�
	bool insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else return false;
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else  {
			parent->_left = cur;
		}
		cur->_parent = parent;
		//����ƽ��
		//�ȸ���ƽ������
		while (parent) {//ֻ�и�û�и���
			//�������Ҫ���µ���
			if (cur == parent->_right) {
				parent->_bf++;
			}
			else {
				parent->_bf--;
			}

			if (parent->_bf == 0) {
				//�߶Ȳ��� -- ֹͣ����
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				//��������
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				//˵��parent���ڵ������Ѿ���ƽ���� -- ��Ҫ��ת
				//����
				if (parent->_bf == 2 && cur->_bf == 1) {
					//ע������϶���bf==1����� -- ���ǵ���
					//parent->_bf==2˵��������
					rotate_left(parent);//��ת�Ͷ���6��ָ�� -- O(1)
				}
				else if (parent->_bf == -2 && cur->_bf == -1) {
					rotate_right(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) {
					//����˫��
					rotate_left_right(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) {
					//����˫��
					rotate_right_left(parent);
				}
				else assert(false);
				break;
			}
			else {
				assert(false);//�����ϲ����ߵ�����
			}
		}
		return true;
	}
public:
	void inorder() {
		_inorder(this->_root);
	}
	bool is_balance() {
		return _is_balance(this->_root);
	}
private:
	void _inorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		_inorder(root->_left);
		cout << (root->_kv).first << ":" << (root->_kv).second << endl;
		_inorder(root->_right);
	}
	int _height(Node* root) {
		if (root == nullptr)return 0;
		int leftHT = _height(root->_left);
		int rightHT = _height(root->_right);
		return max(leftHT, rightHT) + 1;
	}
	bool _is_balance(Node* root) {
		if (root == nullptr)return true;
		int leftHT = _height(root->_left);//�������߶�
		int rightHT = _height(root->_right);//�������߶�
		int diff = rightHT - leftHT;
		//��ƽ������Ҳ���һ��
		if (diff != root->_bf) {
			cout << root->_kv.first << "��ƽ�������쳣" << endl;
			return false;
		}
		return abs(diff) < 2
			&& _is_balance(root->_left)//�ж�һ���������Ƿ�ƽ��
			&& _is_balance(root->_right);//�ж�һ���������Ƿ�ƽ��
	}
};

void test1() {
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVL<int, int>t1;
	for (auto e : a) {
		t1.insert(make_pair(e, e));
	}
	t1.inorder();
	cout << "is_balance():" << t1.is_balance() << endl;
}
void test2(){
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVL<int, int>t1;
	for (auto e : a) {
		t1.insert(make_pair(e, e));
	}
	t1.inorder();
	cout << "is_balance():" << t1.is_balance() << endl;
}
void test3(){
	size_t N = 10000;
	srand(time(nullptr));
	AVL<int, int>t1;
	for (size_t i = 0; i < N; ++i) {
		int x = rand();
		t1.insert(make_pair(x, i));
	}
	cout << "is_balance():" << t1.is_balance() << endl;
}