#pragma once


template<class K> 
struct BinarySearchTreeNode {
	BinarySearchTreeNode<K>* _left;
	BinarySearchTreeNode<K>* _right;
	K _key;
	BinarySearchTreeNode(const K& key)
		:_left(nullptr), _right(nullptr), _key(key) {}
};

template<class K> //һ��ϲ����key
class BinarySearchTree{
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
	//�ݹ����
	bool insertR(const K& key) {
		return _insertR(_root, key);
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
	//�ݹ����
	bool findR(const K& key) {
		return _findR(_root, key);
	}
	//ɾ��
		//ɾ������û�нڵ� -- ֱ���ÿ�
		//ɾ������ֻ��һ������ -- �й�
		//ɾ���������������� -- �滻��ɾ�� -- ��һ��ֵȥ�滻Ҫɾ����
		//��˭ȥ�滻�� -- �����������ڵ��������������С�ڵ�

		/**
		 * �滻�ڵ㸳ֵ��ɾ���ڵ��ɾ���滻�ڵ�
		 * �滻�ڵ�Ҫôû�к��ӣ�Ҫôֻ��һ�����ӣ�����ֱ��ɾ��.
		 */
	bool erase(const K& key) {
		//�Ȳ���
		Node* parent = nullptr;
		Node* cur = _root;
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
				//�ҵ��� -- ��ʼɾ��
				//Ҫɾ�����Ƕ�Ϊ1�Ľڵ�
				//��Ȼ����һ��������� -- ���Ҫɾ�����Ǹ� -- ��ô��
				if (cur->_left == nullptr) {
					//���ж����ĸ���������߻������ұ�
					if (cur == this->_root) {
						//�����������
						_root = cur->_right;
					}
					else { // ɾ�����Ǹ�
						if (cur == parent->_left) {
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
					}
					delete cur;//ɾ������ڵ�
					cur = nullptr;
				}
				else if (cur->_right == nullptr) {
					//���ж����ĸ���������߻������ұ�
					if (cur == _root) {
						_root = cur->_left;
					}
					else {
						if (cur == parent->_left) {
							parent->_left = cur->_left;
						}
						else {
							parent->_right = cur->_left;
						}
					}
					delete cur;//ɾ������ڵ�
					cur = nullptr;
				}
				//Ҫɾ�����Ƕ�Ϊ2�Ľڵ�
				else {
					//�滻��ɾ��
					//�ҵ���������С�ڵ�����滻
					Node* rightMin = cur->_right;
					Node* minParent = cur;//���ﲻ�ܸ��� -- ���Ҫɾ����_root�ͳ������ˣ�ѭ������ȥ
					while (rightMin->_left) {
						minParent = rightMin;
						rightMin = rightMin->_left;//�ҵ�����ߵ�
					}
					swap(cur->_key, rightMin->_key);
					//���ھ��Ƕ�Ϊ1/0�������
					
					//minParent->_left = min->_right;
					// //���ﲻ��ֱ����parent����ȥָ��min����
					//��һɾ�����Ǹ��ڵ� -- �Ͳ���parent����ȥָ�ˣ�����parent����ȥָmin����
					//������������ʵʵ�ж�һ��
					if (minParent->_left == rightMin) {
						minParent->_left = rightMin->_right;
					}
					else {
						minParent->_right = rightMin->_right;
					}
					delete rightMin;
					rightMin = nullptr;
				}
				return true;
			}
		}
		return false;
	}
	//�ݹ�ɾ��
	bool eraseR(const K& key) {
		return _eraseR(this->_root, key);
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
	//�ݹ����
	bool _findR(Node* root, const K& key) {
		//O(h) h�����ĸ߶�
		if (root == nullptr)return false;
		if (root->_key < key) {
			return _findR(root->_right, key);
		}
		else if (root->_key > key) {
			return _findR(root->_left, key);
		}
		else {
			return true;
		}
	}
	//�ݹ����
	bool _insertR(Node*& root, const K& key) {
		//��֮һ�� -- ����������� -- ����ֱ�Ӽ��˾�ֱ������������
		if (root == nullptr) {
			//���Բ���
			root = new Node(key);
			return true;
		}
		if (root -> _key < key) {
			return _insertR(root->_right, key);
		}
		else if (root -> _key > key) {
			return _insertR(root->_left, key);
		}
		else return false;
	}
	//�ݹ�ɾ��
	bool _eraseR(Node*& root, const K& key) {
		if (root == nullptr) {
			return false;
		}
		if (root->_key < key) {
			return _eraseR(root->_right, key);
		}
		else if (root->_key > key) {
			return _eraseR(root->_left, key);
		}
		else {
			Node* del = root;
			if (root->_left == nullptr) {
				root = root->_right;
			}
			else if (root->_right == nullptr) {
				//���ڵ�root����һ��root->right�ı��� -- ֱ�ӻ�������
				root = root->_left;
			}
			else {
				//Ҫɾ���Ľڵ��Ϊ2
				//���ʱ��Ͳ��ܽ�������ķ�ʽ��
				Node* min = root->_right;
				while (min->_left) {
					min = min->_left;
				}
				swap(root->_key, min->_key);
				//return eraseR(key); -- err ������ɾ������ -- ��Ϊ����֮�����Ľṹ�Ѿ���������
				return _eraseR(root->_right, key);//�����Ҵ�root->right��ʼ�����Ϳ�
			}
			delete del;
			return true;
		}
	}
};
/**
 * ��ɾ���ʱ�临�Ӷ���O(h)
 * ��������O(n)
 * �����ǵ�֧��ʱ�����������˻�������
 * �Ľ��ķ�����ƽ���� -- AVL/�����.
 */


/** keyģ�ͣ��жϹؼ����ڲ��� */
/** key/valueģ�ͣ�ͨ��keyȥ��value */


void Test1(){
	BinarySearchTree<int>t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a) {
		//������ʵ������+ȥ��
		t.insert(e);
	}
	t.inorder();

	t.erase(3);
	t.inorder();
	t.erase(8);
	t.inorder();
}

void Test2() {
	BinarySearchTree<int>t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a) {
		//������ʵ������+ȥ��
		t.insertR(e);
	}
	t.inorder();

	cout << "��ʼɾ��" << endl;
	for (auto e : a) {
		//������ʵ������+ȥ��
		t.eraseR(e);
		t.inorder();
	}
}

//��������
void Test3() {
	BinarySearchTree<int>t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a) {
		//������ʵ������+ȥ��
		t.insertR(e);
	}
	//t.inorder();

	BinarySearchTree<int>copy = t;
	copy.inorder();
	t.inorder();

	BinarySearchTree<int>t1;
	t1 = t;
	t1.insert(100);
	t1.inorder();
}