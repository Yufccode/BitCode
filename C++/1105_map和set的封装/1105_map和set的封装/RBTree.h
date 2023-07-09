#pragma once
#include<map>
#include<iostream>
#include<assert.h>
using namespace std;
enum Colour {
	RED,BLACK
};

template<class T>
struct __Red_Black_TreeNode {
	__Red_Black_TreeNode<T>* _left;
	__Red_Black_TreeNode<T>* _right;
	__Red_Black_TreeNode<T>* _parent;
	//pair<K, V>_kv;
	T _data;
	Colour _col;
	__Red_Black_TreeNode(const T& data)
		:_left(nullptr), _right(nullptr), _parent(nullptr), _data(data) {}
};

//������
template<class T, class Ref, class Ptr>
struct __redblack_tree_iterator {
	typedef __Red_Black_TreeNode<T>Node;
	Node* _node;
	__redblack_tree_iterator(Node* node)
		:_node(node) {}
	Ref operator*() {
		return _node->_data;
	}
	Ptr operator->() {
		return &_node->_data;
	}
	bool operator!=(const __redblack_tree_iterator& s) const {
		return _node != s._node;
	}
	bool operator==(const __redblack_tree_iterator& s) const {
		return _node == s._node;
	}
	__redblack_tree_iterator& operator++() {
		//1.��������Ϊ�գ�++�������������������һ��
		//2.���������Ϊ�գ��Һ��Ӳ��Ǹ����ұߵ��Ǹ�����
			//�����ǰ�ڵ��Ǹ��׵��ң�˵�����׷��ʹ���
		if (_node->_right) {
			//1.
			Node* left = _node->_right;
			while (left->_left) {
				left = left->_left;
			}
			_node = left;
		}
		else {
			//2.
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent && cur == parent->_right) {
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	__redblack_tree_iterator& operator--() {
		//1.�����Ϊ�� -- ���������
		//2.�����Ϊ�� -- �ҵ����Ӳ��Ǹ��׵�����Ǹ�����
		if (_node->_left) {
			Node* right = _node->_left;
			while (right->_right) {
				right = right->_right;
			}
			_node = right;
		}
		else {
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent && cur == parent->_left) {
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}	
};


//������ģ�������һ���º���
template<class K,class T,class KeyOfT>
struct RBTree {
	typedef __Red_Black_TreeNode<T>Node;
private:
	Node* _root = nullptr;
public:
	typedef __redblack_tree_iterator<T, T&, T*> iterator;
	iterator begin() {
		//stlԴ�����������ڱ�λ�ģ���������û�� -- ����������һ������ڵ�
		Node* left = _root;
		while (left && left->_left) {
			left = left->_left;
		}
		return iterator(left);
	}
	iterator end() {
		return iterator(nullptr);//ֱ�Ӹ��վ�����
	}
private:
	//����
	void rotate_left(Node* parent) {
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
	}
public:
	//ǰ�����Ĺ��̺�������һ����
	pair<iterator, bool> insert(const T& data) {
		KeyOfT kot;
		if (_root == nullptr) {
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (kot(cur->_data) < kot(data)) {
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data)) {
				parent = cur;
				cur = cur->_left;
			}
			else return make_pair(iterator(cur), false);
		}
		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;//һ��ʼ�����ȱ��
		if (kot(parent->_data) < kot(data)) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED) {
			Node* grandparent = parent->_parent;
			assert(grandparent && grandparent->_col == BLACK);
			//�ؼ�������
			//�ж�һ������
			if (parent == grandparent->_left) {
				Node* uncle = grandparent -> _right;
				//���1����������
				if (uncle && uncle->_col == RED) {
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;
					//�������ϴ���
					cur = grandparent;
					parent = cur->_parent;
				}
				//���2+3
				//uncle������/������Ϊ��
				else {
					//���2
					//   g
					//  p  u
					// c
					//�ҵ���+��ɫ
					if (cur == parent->_left) {
						rotate_right(grandparent);
						parent->_col = BLACK;//���ױ��
						grandparent->_col = RED;//�游���
					}
					//���3
					//   g
					//  p  u
					//   c
					//����˫��+��ɫ
					else {
						rotate_left(parent);
						rotate_right(grandparent);
						//����ͼд������
						cur->_col = BLACK;
						grandparent->_col = RED;
					}
					break;
				}
			}
			else {
				Node* uncle = grandparent->_left;
				//���1����������
				if (uncle && uncle->_col == RED) {
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;
					//�������ϴ���
					cur = grandparent;
					parent = cur->_parent;
				}
				else {
					//���2
					//   g
					//  u  p
					//      c 
					//����+��ɫ
					if (cur == parent->_right) {
						rotate_left(grandparent);
						parent->_col = BLACK;//���ױ��
						grandparent->_col = RED;//�游���
					}
					//���3
					//   g
					//  u  p
					//    c
					//����˫��+��ɫ
					else {
						rotate_right(parent);
						rotate_left(grandparent);
						//����ͼд������
						cur->_col = BLACK;
						grandparent->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;//������۸��Ǻ��Ǻ� -- ������ɺ�
		//��������Ҫ���������Ľڵ� -- ���ǸղŲ�����̿��ܲ����ˣ�����ǰ����ñ���һ��
		return make_pair(iterator(newnode), true);
	}
};