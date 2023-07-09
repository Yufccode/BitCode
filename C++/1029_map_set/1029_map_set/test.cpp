#define _CRT_SECURE_NO_WARNINGS 1

#ifdef __cplusplus
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<numeric>
#include<queue>
#include<assert.h>
#include<map>
#include<set>
using namespace std;
#elif

#endif

void test1() {
	string arr[] = { "ƻ��","����","ƻ��","����" ,"ƻ��" ,
		"ƻ��" ,"����" ,"ƻ��" ,"�㽶" ,"ƻ��","�㽶" };
	//ͳ�ƴ���
	map<string, int>countMap;
	//����1
#if 0
	for (auto& str : arr) {
		map<string, int>::iterator it = countMap.find(str);
		if (it != countMap.end()) {
			it->second++;
		}
		else {
			countMap.insert(make_pair(str, 1));
		}
	}
	auto it = countMap.begin();
	while (it != countMap.end()) {
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
#endif
	//����2 -- ��[]
	for (auto& str : arr) {
		//[]���û���ҵ� -- ������һ���µ�key��������val��Ĭ�Ϲ��죬int����0
		countMap[str]++;
	}
	auto it = countMap.begin();
	while (it != countMap.end()) {
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
void test2() {
	map<string, string>dict;
	dict.insert(make_pair("sort", "����"));
	dict["insert"];
	dict["insert"] = "����";
	dict["left"] = "���";
	//1.map�������key������val�����ã����ҡ��޸�val��
	//2.mapû�����key�������һ��pair(key,V()); -- V()�������� -- ����default_constructor()
		//������+�޸�
}
void test3() {
	//multimap ��֧��[]
	multimap<string, string>mdict;
	//�����ĺ�multisetһ�� ���Ǽ���ʾһ�¾���
	//ֻ��key -- ������ô��������
	mdict.insert(make_pair("sort", "����"));
	mdict.insert(make_pair("left", "���"));
	mdict.insert(make_pair("left", "���"));
	mdict.insert(make_pair("left", "ʣ��"));
}
int main() {
	//test1();
	//test2();
	return 0;
}


//692. ǰK����Ƶ����
//1.�����ȼ�����
class Solution {
private:
	struct less {
		bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)const {
			if (kv1.second < kv2.second)return true;
			if (kv1.second == kv2.second && kv1.first > kv2.first)return true;
			return false;
		}
	};
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int>countMap;//��������ȶ��� -- ����ֱ�ӻ��ɹ�ϣ����
		for (auto& str : words) {
			countMap[str]++;
		}
		//topk
		typedef priority_queue<pair<string, int>, vector<pair<string, int>>, less> maxHeap;
		maxHeap mh(countMap.begin(), countMap.end());
		vector<string>v;
		while (k--) {
			pair<string, int>kv = mh.top();
			mh.pop();
			v.push_back(kv.first);
		}
		return v;
	}
};

//����2��ֱ����map������
class Solution {
	struct greater {
		bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)const {
			if (kv1.second > kv2.second)return true;
			//����������ȶ����� -- �Ͳ����������if��
			/*if (kv1.second == kv2.second && kv1.first < kv2.first) {
				return true;
			}*/
			return false;
		}
	};
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int>countMap;
		for (auto& str : words) {
			countMap[str]++;
		}
		//���ǿ��ǿ�����һ������
		//�����������һ����Ҫ�ȶ���
		//��Ϊ��map�����key�Ѿ��ǰ����ֵ��������ˣ���������Ҫ������val����
		//�������֮��ϣ�����Ǳ���ԭ�����ֵ���
		vector<pair<string, int>>sortV(countMap.begin(), countMap.end());

		//sort(sortV.begin(), sortV.end(), greater());//err ����Ǹ����ȶ�����
		//���ǿ�����һ���ȶ����� -- ����Ҳ���Ը�greater()�������� -- Ҳ����������ĿҪ��
		//���߲����ú����ȶ� -- ����ͨ������һ���Ƚ����� -- ����������ĿҪ��
		
		//sort(sortV.begin(), sortV.end(), greater());
		stable_sort(sortV.begin(), sortV.end(), greater());

		vector<string>v;
		for (int i = 0; i < k; ++i) {
			v.push_back(sortV[i].first);
		}
		return v;
	}
};


//������÷º��� -- ������ô��
//���ǿ�����map����
//���ǵߵ�һ�£����<int,string>����val����
//��������Ҫע�� -- map�ǻ�ȥ�صģ����ǵ�val���п������ظ��� -- ����ȥ��
//����ʹ��multimap
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int>countMap;
		for (auto& str : words) {
			countMap[str]++;
		}

		multimap<int, string, greater<int>>sortMap;//��Ϊ�����ǰ�val�ţ�val��int�����Էº��������Լ�д��
		//ע�⣺�����÷��������ȥ�� -- ��Ϊ�������ֵ����ַ���
		//���Ǽ�Ҫ�ֵ��������ģ���Ҫ���ִ����������ǽ��� -- ���Ը���int�ķº���
		for (auto& kv : countMap) {
			sortMap.insert({ kv.second,kv.first });//�ߵ�һ��
			//��Ϊmultimap�ظ�����Ĭ�����ұ߲壬����������ʵ�Դ���һ���ȶ�
		}
		//�����ź���
		vector<string>v;
		multimap<int, string, greater<int>>::iterator it = sortMap.begin();
		for (int i = 0; i < k; i++) {
			v.push_back(it->second);
			it++;
		}
		return v;
	}
};


//����map/set֮�⣬���ǻ�������<algorithm>�����unique����������ȥ��

//349. ��������Ľ���
/*
* �㷨����ǰ��������
* �ҽ�����
* 1.С��++
* 2.��ȵľ��ǽ�����ͬʱ++
* �Ҳ��
* 1.С�ľ��ǲ
* 2.��Ⱦ�ͬʱ++
*/
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int>s1(nums1.begin(), nums1.end());
		set<int>s2(nums2.begin(), nums2.end());
		auto it1 = s1.begin();
		auto it2 = s2.begin();
		vector<int>ret;
		while (it1 != s1.end() && it2 != s2.end()) {
			if (*it1 < *it2) {
				++it1;
			}
			else if (*it1 > *it2) {
				++it2;
			}
			else {
				ret.push_back(*it1);
				++it1;
				++it2;
			}
		}
		return ret;
	}
};