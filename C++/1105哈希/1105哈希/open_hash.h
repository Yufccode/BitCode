#pragma once



#include<map>
#include<set>
#include<vector>
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



template<class K, class V>
struct HashNode
{
	pair<K, V>_kv;
	HashNode<K, V>* _next;
	HashNode<K, V>(const pair<K, V>& kv)
		:_kv(kv), _next(nullptr) {}
};
template<class K, class V, class Hash = HashFunc<K>>
struct HashTable
{
	typedef HashNode<K, V> Node;
private:
	vector<Node*>_tables;
	size_t _size = 0;//�洢����Ч���ݸ���
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
	bool insert(const pair<K, V>& kv)
	{
		//ȥ��
		if (find(kv.first))return false;
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
					size_t hashi = hash(cur->_kv.first) % newTables.size();
					cur->_next = newTables[hashi];
					newTables[hashi] = cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_tables.swap(newTables);//�µĺ;ɵĽ���һ��
		}

		Hash hash;
		size_t hashi = hash(kv.first) % _tables.size();
		//ͷ�壿β�壿
		Node* newnode = new Node(kv);
		newnode->_next = _tables[hashi];
		_tables[hashi] = newnode;
		this->_size++;
		return true;
	}
	Node* find(const K& key) 
	{
		//���ж�һ�±��ǲ��ǿյ�
		if (_tables.size() == 0)
		{
			return nullptr;
		}
		Hash hash;
		size_t hashi = hash(key) % _tables.size();
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (cur->_kv.first == key)return cur;
			cur = cur->_next;
		}
		return nullptr;
	}
	bool erase(const K& key)
	{
		if (_tables.size() == 0)
		{
			return false;
		}
		Hash hash;
		size_t hashi = hash(key) % _tables.size();
		Node* cur = _tables[hashi];
		Node* prev = nullptr;
		while (cur)
		{
			if (cur->_kv.first==key)
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

#include<iostream>
void test4()
{
	int a[] = { 1,11,4,15,26,7,44,99,55,78 };
	HashTable<int, int>ht;
	for (auto e : a) {
		ht.insert(make_pair(e, e));
	}
	ht.insert(make_pair(22, 22));
	cout << endl;
}
//��key��չһ��
void test5()
{
	string arr[] = { "ƻ��","ƻ��","�㽶","����","ƻ��","�㽶","����","ƻ��","����","�㽶","����","����" };
	//HashTable<string, int, HashFuncString>countHT;
	HashTable<string, int>countHT;
	for (auto& str : arr)
	{
		auto ptr = countHT.find(str);
		if (ptr)
		{
			ptr->_kv.second++;
		}
		else
		{
			countHT.insert(make_pair(str, 1));
		}
	}
	cout << endl;
}
/**
 * ������һ�����ۣ��ù�ϣ��Ĵ�СΪ���� -- ������һ���̶ȼ��ٳ�ͻ
 * ��������εõ���һ�����ʵ������أ�
 * stl_hashtable.h������ͨ�����ķ�ʽ��.
 */



void test6()
{
	int n = 100000;
	vector<int>v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; i++)
	{
		v.push_back(rand());
	}
	size_t begin1 = clock();
	HashTable<int, int>ht;
	for (auto e : v)
	{
		ht.insert(make_pair(e, e));
	}
	size_t end1 = clock();
	cout << "size():" << ht.size() << endl;
	cout << "table.size():" << ht.bucket_size() << endl;
	cout << "bucket_number():" << ht.bucket_num() << endl;
	cout << "avg_bucket_list_length: " << (double)ht.size() / ht.bucket_num() << endl;
	cout << "longest_bucket_length(): " << ht.longest_bucket_length() << endl;
	cout << endl;
}

//һ������£�findЧ�ʶ��Ǻܿ��
//�����ټ��� -- ���ǿ��ԹҺ����
//һ����˵�ҵ���������

//��ϣ���������Ҫ���� -- ���ݵ�ʱ�����¼���λ�ò��Ǻ�ʱ���
//���Թ�ϣ��Ĳ��벻ռ���Ƶ�


/**
 * �������ǻع�ͷ����
 * u_map����
 * bucket_count
 * max_bucket_count
 * bucket_size
 * load_factor��Щ�ӿ�
 * ���ǾͶ���������.
 */