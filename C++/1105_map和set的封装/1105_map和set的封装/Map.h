#pragma once

#include"RBTree.h"

namespace yufc {
	template<class K, class V>
	class map {
		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
	//������
		//ȡģ���ģ������� -- ����Ҫtypename -- ���߱�����������
		typedef typename RBTree <K, pair<K, V>, MapKeyOfT>::iterator iterator;
		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
	public:
		//operator[] -- ֻ��map����
		V& operator[](const K& key) {
			//����� -- ����ɹ�
			//���û�� -- ����ʧ��
			pair<iterator, bool>ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
	public:
		pair<iterator, bool> insert(const pair<K, V>& kv) {
			return _t.insert(kv);
		}
	private:
		RBTree <K, pair<K, V>, MapKeyOfT>_t;
	};



	void test_map() {
		map<int, int>m;
		m.insert(make_pair(1, 2));
		m.insert(make_pair(5, 2));
		m.insert(make_pair(2, 2));
		m.insert(make_pair(2, 2));
		m.insert(make_pair(3, 2));
		m.insert(make_pair(4, 2));
		m.insert(make_pair(6, 2));

		cout << "����++" << endl;
		map<int, int>::iterator it = m.begin();
		while (it != m.end()) {
			cout << it->first << endl;
			++it;
		}
		cout << "����--" << endl;
		//--it;
		//while (it != m.begin()) {
		//	cout << it->first << endl;
		//	--it;
		//}
		cout << endl;
	}
	void test_map2() {
		string arr[] = { "ƻ��","�㽶","ƻ��","ƻ��","����","�㽶","ƻ��","ƻ��" };
		map<string, int>hash;
		for (auto& str : arr) {
			hash[str]++;
		}
		//map<string, int>::iterator it = hash.begin();
		//while (it != hash.end()) {
		//	cout << it->first << ":" << it->second << endl;
		//	++it;
		//}
		//��Χfor
		for (auto& e : hash) {
			cout << e.first << ":" << e.second << endl;
		}
	}
}