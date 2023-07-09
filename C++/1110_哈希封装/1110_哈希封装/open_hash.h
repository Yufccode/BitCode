#pragma once

//tips:  deepcopy hasn't realize

#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


//��ɢ��
//������
//��ϣͰ

template<class K>
struct HashFunc
{
	//Ŀ�ľ��ǰ�һ����������ת����һ���޷�������
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
//�ػ�
template<>
struct HashFunc<string>
{
	//BKDR�㷨
	size_t operator()(const string& key)
	{
		size_t val = 0;
		for (auto ch : key)
		{
			val *= 131;
			val += ch;
		}
		return val;
	}
};



template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;
	HashNode(const T& data)
		:_data(data), _next(nullptr) {}
};
//ǰ������һ�¹�ϣ��
template<class K, class T, class Hash, class KeyOfT>
struct HashTable;
template<class K, class T, class Hash, class KeyOfT>
struct __hash_iterator
{
	typedef HashNode<T>Node;
	typedef HashTable<K, T, Hash, KeyOfT> HT;
	typedef __hash_iterator<K, T, Hash, KeyOfT>self;
	Node* _node;
	HT* _pht; //��Ϊ����Ҫ��HashTable����ָ�룬����ǰ��Ҫǰ������һ��

	__hash_iterator(Node* node, HT* pht)
		:_node(node), _pht(pht) {}
	T& operator*()
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &_node->_data;
	}
	self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//����һ��Ͱ
			//����Ҫ�ҵ��Լ����ĸ�Ͱ�� 
			//��һ�µ�ǰ�Ĺ�ϣֵ������
			Hash hash;
			KeyOfT kot;
			size_t i = hash(kot(_node->_data)) % _pht->_tables.size();//�����Ƿ��ʲ���_tables�ģ�Ҫ����һ����Ԫ
			++i;//����һ��Ͱ��ʼ��
			for (; i < _pht->_tables.size(); i++)
			{
				if (_pht->_tables[i])//�����ǰͰ��Ϊ��
				{
				_node = _pht->_tables[i];
				break;
				}
			}
			//����ҵ����û���ҵ���Ϊ�յ�Ͱ -- Ҳ����һ��ʼ�±�Ϊi��Ͱ�Ѿ������һ��Ͱ��
			if (i == _pht->_tables.size())
			{
				_node = nullptr;
			}
		}
		return*this;
	}
	bool operator!=(const self& s)const
	{
		return _node != s._node;
	}
	bool operator==(const self& s)const
	{
		return _node == s._node;
	}
};
/// <summary>
/// ����Դ�����ǿ��Է��֣���ǰ���Ƕ��ǻḴ�ô���� ����Ref Ptr��������
/// �����ڹ�ϣ������Ƿֿ�ʵ�ֵģ���϶�����ԭ���

template<class K, class T, class Hash, class KeyOfT>
struct HashTable
{
private:
	typedef HashNode<T> Node;
private:
	vector<Node*>_tables;
	size_t _size = 0;//�洢����Ч���ݸ���
public:
	friend struct __hash_iterator<K, T, Hash, KeyOfT>;//��__hash_iterator���Է���_tables
	typedef __hash_iterator<K, T, Hash, KeyOfT> iterator;//������
	iterator begin()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			if (_tables[i])
			{
				return iterator(_tables[i], this);//�ڶ���������this��Ҫ���ǹ�ϣ���ָ�룬����this����
			}
		}
		//���һ��Ͱ��û��
		return end();
	}
	iterator end()
	{
		return iterator(nullptr, this);
	}
public:
	HashTable() = default;
	~HashTable()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			Node* cur = this->_tables[i];
			while (cur)
			{
				Node* next = cur->_next;
				free(cur);
				cur = next;
			}
			_tables[i] = nullptr;
		}
	}
private:
	inline size_t __stl_next_prime(size_t n)
	{
		static const size_t __stl_num_primes = 28;
		static const size_t __stl_prime_list[__stl_num_primes] =
		{
			53, 97, 193, 389, 769,
			1543, 3079, 6151, 12289, 24593,
			49157, 98317, 196613, 393241, 786433,
			1572869, 3145739, 6291469, 12582917, 25165843,
			50331653, 100663319, 201326611, 402653189, 805306457,
			1610612741, 3221225473, 4294967291
		};

		for (size_t i = 0; i < __stl_num_primes; ++i)
		{
			if (__stl_prime_list[i] > n)
			{
				return __stl_prime_list[i];
			}
		}

		return -1;
	}
public:
	pair<iterator, bool> insert(const T& data)
	{
		KeyOfT kot;
		//ȥ��
		iterator ret = find(kot(data));
		if (ret != end())//�Ѿ������ֵ��
		{
			return make_pair(ret, false);//����ʧ��
		}
		//����
		//�������ӵ�1������
		if (_size==_tables.size())
		{
			//ͬ�������⣺Ū����vector�û��Ǹ���insert�ã�
			//���ﴴ��vector����
			//��Ϊ�ڵ����ǿ���ֱ��������
			//size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			vector<Node*>newTables;
			//newTables.resize(newSize, nullptr);
			newTables.resize(__stl_next_prime(_tables.size()), nullptr);
			//�ɱ��еĽڵ��ƶ�ӳ�䵽�±�
			Hash hash;
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;//��Ϊcur��� -- ������ǰ������һ��
					size_t hashi = hash(kot(cur->_data)) % newTables.size();
					cur->_next = newTables[hashi];
					newTables[hashi] = cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_tables.swap(newTables);//�µĺ;ɵĽ���һ��
		}

		Hash hash;
		size_t hashi = hash(kot(data)) % _tables.size();
		//ͷ�壿β�壿
		Node* newnode = new Node(data);
		newnode->_next = _tables[hashi];
		_tables[hashi] = newnode;
		this->_size++;
		return make_pair(iterator(newnode, this), true);//�����½ڵ�ĵ�������true
	}
	iterator find(const K& key) 
	{
		//���ж�һ�±��ǲ��ǿյ�
		if (_tables.size() == 0)
		{
			return end();//��Ϊ�� -- ���ؿ�
		}
		Hash hash;
		KeyOfT kot;
		size_t hashi = hash(key) % _tables.size();
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (kot(cur->_data) == key)return iterator(cur, this);
			cur = cur->_next;
		}
		return end();
	}
	bool erase(const K& key)
	{
		if (_tables.size() == 0)
		{
			return false;
		}
		Hash hash;
		KeyOfT kot;
		size_t hashi = hash(key) % _tables.size();
		Node* cur = _tables[hashi];
		Node* prev = nullptr;
		while (cur)
		{
			if (kot(cur->_data)==key)
			{
				if (prev == nullptr)
				{
					//˵��ɾ����ͷ
					_tables[hashi] = cur->_next;
					delete(cur);
					--this->_size;
					return true;
				}
				else
				{
					prev->_next = cur->_next;
					delete cur;
					--this->_size;
					return true;
				}
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}
	size_t size()
	{
		return this->_size;
	}
	size_t bucket_size()
	{
		return _tables.size();
	}
	size_t bucket_num()
	{
		size_t ret = 0;
		for (size_t i = 0; i < _tables.size(); i++)
		{
			if (_tables[i])
			{
				++ret;
			}
		}
		return ret;
	}
	size_t longest_bucket_length()
	{
		size_t max_len = 0;
		for (size_t i = 0; i < _tables.size(); i++)
		{
			size_t len = 0;
			Node* cur = _tables[i];
			while (cur)
			{
				++len;
				cur = cur->_next;
			}
			max_len = max(max_len, len);
		}
		return max_len;
	}
};