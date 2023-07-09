#pragma once

#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

template<class K, class V>
struct HashData
{
	pair<K, V>_kv;
	State _state = EMPTY;
};

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


#define THRESHOLD 0.7 //����������ֵ
//HashFunc���ó�Ĭ�ϵķº��� -- ����Կ���ֱ��ת����size_t�����ͣ�
template<class K, class V, class Hash = HashFunc<K>>
class HashTable
{
public:
	bool insert(const pair<K, V>& kv)
	{
		if (find(kv.first))return false;
		if (_table.size() == 0 || (double)_size / _table.size() >= THRESHOLD)
		{
			//����
			//˼·1���Լ���vector
#if 0
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			vector<HashData<K, V>>newTable;
			newTable.resize(newSize);
			//�ɱ������ӳ�䵽�±�
			for ()
			{

			}
			_table.swap(newTable);
#endif
			//˼·2������insert
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V, Hash>newHT;
			newHT._table.resize(newSize);
			for (auto& e : _table)
			{
				if (e._state == EXIST)
				{
					newHT.insert(e._kv);//ֱ�ӵ��Լ���insert
				}
			}
			_table.swap(newHT._table);
		}
#if false
		Hash hash;
		size_t hashi = hash(kv.first) % _table.size();
		//����̽��
		while (_table[hashi]._state == EXIST)
		{
			++hashi;
			hashi %= _table.size();
		}
		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_size;
#endif
		//����̽��
		Hash hash;
		size_t start = hash(kv.first) % _table.size();
		size_t i = 0;
		size_t hashi = start;
		while (_table[hashi]._state == EXIST)
		{
			++i;
			hashi = start + i * i;
			hashi %= _table.size();
		}
		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_size;

		return true;
	}
	bool erase(const K& key) 
	{
		HashData<K, V>* ret = find(key);
		if (ret) 
		{
			ret->_state = DELETE;
			--_size;
			return true;
		}
		else 
		{
			return false;
		}
	}
	HashData<K, V>* find(const K& key)
	{
		if (_table.size() == 0)return nullptr;
		Hash hash;
		size_t hashi = hash(key) % _table.size();
		size_t start = hashi;
		while (_table[hashi]._state != EMPTY) 
		{
			if (_table[hashi]._state != DELETE && _table[hashi]._kv.first == key)//�ҵ���
			{
				return &_table[hashi];
			}
			hashi++;
			hashi %= _table.size();
			if (hashi == start) 
			{
				break;
			}
		}
		return nullptr;//�Ҳ���
	}
	void print_for_test()
	{
		//Ϊ�˷������д�� -- ��ʵ��u_map�ײ㲻�������
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i]._state == EXIST) 
			{
				printf("[%d:%d]", i,_table[i]._kv.first);
			}
			else
			{
				printf("[%d:*]", i);
			}
		}
		cout << endl;
	}
private:
	vector<HashData<K, V>>_table;
	size_t _size = 0;
};


void test1() 
{
	int a[] = { 1,11,4,15,26,7,44,9 };
	HashTable<int, int>ht;
	for (auto e : a) {
		ht.insert(make_pair(e, e));
	}
	ht.erase(4);
	ht.print_for_test();
	cout << ht.find(44)->_kv.first << endl;
	cout << ht.find(4) << endl;
	//��������
	ht.insert(make_pair(-2, -2));
	ht.print_for_test();
	cout << ht.find(-2)->_kv.first << endl;
	//���ǲ��Է��� -- ����Ҳ���� -- ����Ϊʲô��
	//�����ʱ�� -- �������������޷�����

}

//������ȫ��deleteҲ��û�����


/// <summary>
/// ��������ǵ�key��������string��Щ�������͵�ʱ��
/// ������ôȥ������ϣ����
/// ��Ȼ������Ϳ϶��ǿɹ�ϣ����
/// ������ǻ���Ҫ��һ���º��� -- �����ǵĹ�ϣ����
/// </summary>

//��string���ͼ��Ϸº���֮�� -- ����ȥ -- ����ͨ��
//�������Ƿ��֣�u_map<>�ǲ��ô��º����� -- ��Ϊstring����һ���Ƚϳ���������
//�����������ǿ��Բ���ģ���ػ���
//�������ǵ�string�Ͳ��ô���
void test2() 
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
void test3()
{
	HashFunc<string>hash;
	//����������������������
	cout << hash("abcd") << endl;
	cout << hash("bcad") << endl;
	cout << endl;
	cout << hash("abcd") << endl;
	cout << hash("aadd") << endl;
	//���Ƿ����ֳ�ͻ��
	//�������ֱȽϸߵ��ַ�����ϣ�㷨 -- BKDR�㷨 -- ���ǲ���������ַ�����ϣ��
}

/** ����̽����ڵ����� */
//���ĳ��λ�ó�ͻ�ܶ������£��ᵼ�»���ռ�ã�����һ��Ƭ��ͻ
//Ч�ʽ���
//������룺
//1 11 21 31 2 3
//�������������̽��
//����̽�⣺�ڵ�ǰλ��+i����̽��
//����̽�⣺�ڵ�ǰλ��+i^2����̽��
//	�ڵ�ǰλ�ã���һ��+1���ڶ���+4��������+9... ��Զ��������ڷ�ɢ
//���Ƕ���̽��û�б����Ͻ������ -- ���ʻ���ռ�ñ��˵�λ��