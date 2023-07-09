#pragma once

#include<string>
#include<iostream>


//����Ͳ���̫���ӵ���
//�Ѳ��ҺͲ������¾���

namespace Key{
	template<class K>
	struct BinarySearchTreeNode {
		BinarySearchTreeNode<K>* _left;
		BinarySearchTreeNode<K>* _right;
		K _key;
		BinarySearchTreeNode(const K& key)
			:_left(nullptr), _right(nullptr), _key(key) {}
	};

	template<class K> //һ��ϲ����key
	class BinarySearchTree {
		typedef BinarySearchTreeNode<K> Node;
	private:
		Node* _root = nullptr;
	public:
		~BinarySearchTree() {
			_destroy(_root);
		}
		BinarySearchTree() = default;//C++11 -- ǿ�Ʊ���������Ĭ�ϵĹ���
		BinarySearchTree(const BinarySearchTree<K>& t) {
			//ǰ������õ�
			_root = _copy(t._root);
		}
		BinarySearchTree<K>& operator=(BinarySearchTree<K>t) {
			swap(_root, t._root);
			return *this;
		}
	private:
		Node* _copy(Node* root) {
			if (root == nullptr) {
				return nullptr;
			}
			Node* copyRoot = new Node(root->_key);
			copyRoot->_left = _copy(root->_left);
			copyRoot->_right = _copy(root->_right);
			return copyRoot;
		}
		void _destroy(Node*& root) {
			//�����ÿ����������ÿ�������
			if (root == nullptr) {
				return;
			}
			_destroy(root->_left);
			_destroy(root->_right);
			delete root;
			root = nullptr;
		}
	public:
		bool insert(const K& key) {
			//���û�нڵ㣬ֱ��new
			if (_root == nullptr) {
				_root = new Node(key);
				return true;
			}
			//�Ҳ����λ��
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur) {
				if (cur->_key < key) {
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					//�������ǲ������ظ���ֵ��
					return false;//����ʧ��
				}
			}
			//Ϊ���ܲ��룬��ö���һ��parentͬʱ����
			cur = new Node(key);
			if (parent->_key < key) {
				parent->_right = cur;
			}
			else {
				parent->_left = cur;
			}
		}
		//����
		bool find(const K& key) {
			Node* cur = _root;
			while (cur) {
				if (cur->_key < key) {
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					cur = cur->_left;
				}
				else {
					return true;//����ʧ��
				}
			}
			return false;
		}
		//дһ������
		void inorder() {
			_inorder(_root);
			cout << endl;
		}
	private:
		void _inorder(Node* root) {
			if (root == nullptr)return;
			_inorder(root->_left);
			cout << root->_key << " ";
			_inorder(root->_right);
		}
	};
}

namespace key_value{
	template<class K,class V>
	struct BinarySearchTreeNode {
		BinarySearchTreeNode<K, V>* _left;
		BinarySearchTreeNode<K, V>* _right;
		K _key;
		V _value;
		BinarySearchTreeNode(const K& key, const V& value)
			:_left(nullptr), _right(nullptr), _key(key),_value(value) {}
	};

	template<class K, class V> //һ��ϲ����key
	class BinarySearchTree {
		typedef BinarySearchTreeNode<K, V> Node;
	private:
		Node* _root = nullptr;
	public:
		BinarySearchTree() = default;
		bool insert(const K& key, const V& value) {
			//���û�нڵ㣬ֱ��new
			if (_root == nullptr) {
				_root = new Node(key, value);
				return true;
			}
			//�Ҳ����λ��
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur) {
				if (cur->_key < key) {
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					//�������ǲ������ظ���ֵ��
					return false;//����ʧ��
				}
			}
			//Ϊ���ܲ��룬��ö���һ��parentͬʱ����
			cur = new Node(key, value);
			if (parent->_key < key) {
				parent->_right = cur;
			}
			else {
				parent->_left = cur;
			}
		}
		//����
		//kvģ�����ﷵ��Node*
		Node* find(const K& key) {
			Node* cur = _root;
			while (cur) {
				if (cur->_key < key) {
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					cur = cur->_left;
				}
				else {
					return cur;//���ؽڵ��ָ�뷽�������޸�
				}
			}
			return nullptr;
		}
		//дһ������
		void inorder() {
			_inorder(_root);
			cout << endl;
		}
	private:
		void _inorder(Node* root) {
			if (root == nullptr)return;
			_inorder(root->_left);
			cout << root->_key << " ";
			_inorder(root->_right);
		}
	};
	
	void testkv1() {
		//kvģ��ʹ�ó���1
		BinarySearchTree<string, string>dict;
		dict.insert("sort", "����");
		dict.insert("left", "���");
		dict.insert("right", "�ұ�");
		dict.insert("string", "�ַ���");
		dict.insert("insert", "����");
		string str;
		while (cin >> str) { //ctrl+Z+\n���Խ���   ctrl+Cֱ��ɱ�����̣�������ǰ��
			BinarySearchTreeNode<string, string>* ret = dict.find(str);
			if (ret) {
				cout << ":" << ret->_value << endl;
			}
			else {
				cout << "->�޴˵���" << endl;
			}
		}
	}
	void testkv2() {
		//����2
		//ͳ����ֵ���ֵĴ���
		string arr[] = { "ƻ��","�㽶" ,"��ݮ" ,"ƻ��" ,"ƻ��" };
		BinarySearchTree<string, int>map;
		for (auto& str : arr) {
			BinarySearchTreeNode<string, int>* ret = map.find(str);
			if (ret) {
				ret->_value++;
			}
			else {
				map.insert(str, 1);
			}
		}
	}
}