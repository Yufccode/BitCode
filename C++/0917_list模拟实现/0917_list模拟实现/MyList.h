#pragma once

#include<iostream>
#include<algorithm>
#include<cassert>
#include<list>
#include"reverse_iterator.h"

using namespace std;

namespace yufc {
	template<class T>
	struct list_node {
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& x = T()) //��ȱʡ
			:_data(x), _next(nullptr), _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list__iterator {
		typedef list_node<T>Node;
		//��׼��stl������Ҫ������͵�
		//����������漸���ò���find
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;

		Node* _node;
		__list__iterator(Node* node)//����
			:_node(node) {}
		//���Ŀ�����Ϊ
		bool operator!=(const __list__iterator& it)const {
			return _node != it._node;
		}
		//������Ƿ��� const T& ���ǾͲ��ܸ���
		//�Ե����������� -- ע�⣬Ҫ�������� -- �ɶ���д
		Ref operator*() { // ͬ�������ͻ�
			return _node->_data;
		}
		__list__iterator& operator++() {
			_node = _node->_next;
			return *this;
		}
		//��������
		bool operator==(const __list__iterator& it)const {
			return _node == it._node;
		}
		__list__iterator operator++(int) {
			__list__iterator tmp(*this);//�ȱ���һ��֮ǰ��ֵ
			_node = _node->_next;
			return tmp;//ֻ�ܴ�ֵ������ -- ��Ϊ����ʱ����
		}
		__list__iterator operator--(int) {
			__list__iterator tmp(*this);//�ȱ���һ��֮ǰ��ֵ
			_node = _node->_prev;
			return tmp;//ֻ�ܴ�ֵ������ -- ��Ϊ����ʱ����
		}
		__list__iterator& operator--() {
			_node = _node->_prev;
			return *this;
		}
		//stl���滹������һ�� -> �Ͼ�����������[ָ����Ϊ]��һ����������
		//ʲôʱ����� -> �أ� ���������ǽṹ��(���ʱ��)����Ҫ��
		//T* operator->() {
		Ptr operator->() { //���ͻ� -- �㴫ʲô���;͵���ʲô����
			//���ز��� -- ��Ϊ����ֵ��ͬ����������
			return &(operator*());
		}
	};


	template<class T>
	class list {
		typedef list_node<T>Node;
	public:
		typedef __list__iterator<T, T&, T*>iterator;
		typedef __list__iterator<T, const T&, const T*>const_iterator;
		typedef __reverse_iterator<iterator, T&, T*>reverse_iterator;
		typedef __reverse_iterator<const_iterator, const T&, const T*>const_reverse_iterator;


		iterator begin() {
			return iterator(_head->_next);//begin()���ڱ�λ����һ��λ��
		}
		iterator end() {
			return iterator(_head);//end()���ڱ�λ
		}
		reverse_iterator rbegin() {
			return reverse_iterator(end());//��Ϊǰ��������Ƶ��ǶԳƵģ���������������ҵķ�����ķ������ҵ���
		}
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		const_iterator begin() const {
			return const_iterator(_head->_next);//begin()���ڱ�λ����һ��λ��
		}
		const_iterator end() const {
			return const_iterator(_head);//end()���ڱ�λ
		}
		list() {
			empty_init();
		}
		~list() {
			//�������д������ -- ��ǳ���� -- �ͻ�϶��������
			//��clearһ�£��ٰ�ͷŪ��������
			this->clear();
			delete _head;
			_head = nullptr;
		}
		void empty_init() {
			//��������ʼ���ڱ�λͷ�ڵ�
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}//����д��֮�����ǵĹ���Ҳֱ�ӵ������empty_init()������
		//��������
		//����д�� -- ���ù��캯�� -- ������캯���Ǵ�һ������������ģ���һ��Ҫ��list�ĵ�������
		template<class InputIterator>
		list(InputIterator first, InputIterator last) { //����
			empty_init();//��������ʼ���ڱ�λͷ�ڵ�
			while (first != last) { //��Ȼ���ǲ���ֱ�Ӳ��� -- ͷ�ڵ�Ҫ��Ū�� -- ��Ȼֱ��pushֱ�ӱ�
				push_back(*first);
				++first;
			}
		}
		void swap(list<T>& x) {
			std::swap(_head, x._head);
		}
		list(const list<T>& lt) {
			//ֱ�Ӹ���list(InputIterator first, InputIterator last)���캯������
			//lt2(lt1)
			empty_init();//�Ȱ��Լ���ʼ��һ��
			list<T>tmp(lt.begin(), lt.end());//�������������lt2��Ҫ��
#if 0
			std::swap(_head, tmp._head);//ֱ�ӻ�ͷָ�������
#endif
			swap(tmp);
		}
		list<T>& operator=(list<T> lt) {
			//lt��һ�������ʱ���󣬻����� -- �������ͷ�
			swap(lt);
			return*this;
		}
		void clear() {
			//������ -- �ڱ�λ��Ҫ������
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
				//erase֮�� -- ��ʧЧ�� -- ���ǻ᷵����һ��λ�õĵ�����
				//����it = erase(it) ����д������
			}
		}
		void push_back(const T& x) {
#if 0
			Node* tail = _head->_prev;//β�ڵ�
			Node* newnode = new Node(x);
			//�򵥵����ӹ�ϵ
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
#endif
			//����insert
			insert(end(), x);
		}
		void push_front(const T& x) {
			insert(begin(), x);
		}
		iterator insert(iterator pos,const T&x){
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			//prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}
		void pop_back() {
			erase(--end());
		}
		void pop_front() {
			erase(begin());
		}
		iterator erase(iterator pos) {
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return iterator(next);//������һ��λ�õĵ�����
		}
	/// <summary>
	/// ������ -- �ص�֮�ص�
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// ������ô��++ȥ���õ�������
	/// C++���������� -- ��װ�����������/
	/// ���ȿ϶�Ҫ����*��Ҫ����++
	private:
		Node* _head;
	};


	void print_list(list<int>&lt) {
		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test() {
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		lt.push_front(0);
		lt.push_front(-1);

		list<int>::iterator it = lt.begin();
		while (it != lt.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : lt) {//��Ӧ�ģ���Ҳ������
			cout << e << " ";
		}
		cout << endl;
		lt.pop_back();
		lt.pop_back();
		for (auto e : lt) {//��Ӧ�ģ���Ҳ������
			cout << e << " ";
		}
		cout << endl;
		lt.pop_front();
		lt.pop_front();
		for (auto e : lt) {//��Ӧ�ģ���Ҳ������
			cout << e << " ";
		}
		cout << endl;

		//find
		//��3֮ǰ����һ��30
		auto pos = find(lt.begin(), lt.end(), 3);
		if (pos != lt.end()) {
			//pos��ʧЧ�𣿲���
			lt.insert(pos, 30);
			*pos *= 100; // ������ָ�����3
		}
		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
	}

	void func(const list<int>& lt) {
		//������ȥ����һ��
		//�϶����ܲ��˵� -- ��Ҫconst������
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end()) {
			//*it = 10;
			cout << *it << " ";
			++it;
		}
	}
	void test2() {
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		func(lt);
	}

	void test3() {
		//��ǳ��������
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		list<int>copy = lt;
		*lt.begin() = 10;
		print_list(lt);
		cout << endl;
		print_list(copy);
		//�����ǳ�����Ļ����������� -- ����list��ͷ��ָ��ͬһ���ڱ�λͷ�ڵ� -- ͬһ������
		lt.clear();
		cout << endl;
		print_list(lt);
		lt.push_back(1);
		print_list(lt);
	}
	void test4() {
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		list<int>copy;
		copy = lt;
		print_list(lt);
		print_list(copy);
		*lt.begin() = 10;
		print_list(lt);
		print_list(copy);
	}

	//�������������
	void test5() {
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		lt.push_back(7);
		lt.push_back(8);
		print_list(lt);
		//�������������
		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend()) {
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}
//����Ҫȥʵ�ַ��������
//��ͨ˼ά������һ����������� -- �޸�һ��
//����˼ά��
//1.list��������ʵ�֣���vector��Щ����ô���أ�
//	vectorҲ������listһ��Ūһ��struct ȥ����
//  ԭ��vector������ֱ��++�ǲ���operator�ģ���Ϊ���������Ϊ�Ϳ��Է��Ϲ淶
//	��������������Ҫʵ��һ��vector�ķ�������������ǾͿ���operatorһ��++ ʵ������--_ptr
//2.���ã� -- ��vector����ͷ�ļ�