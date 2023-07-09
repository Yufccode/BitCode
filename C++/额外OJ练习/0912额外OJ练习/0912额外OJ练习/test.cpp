#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<Windows.h>
#include<assert.h>
using namespace std;

//��ָ Offer II 034. ���������Ƿ�����
class Solution {
private:
    unordered_map<char, int>hash;
    int my_strcmp(const string& s1, const string& s2) {
        //˫ָ��
        int cur1 = 0;
        int cur2 = 0;
        while (cur1 < s1.size() && cur2 < s2.size()) {
            if (hash[s1[cur1]] == hash[s2[cur2]]) {
                cur1++;
                cur2++;
            }
            else if (hash[s1[cur1]] < hash[s2[cur2]]) {
                return -1;
            }
            else {
                return 1;
            }
        }
        if (cur1 != s1.size())return 1;//˵��s1�ϳ�
        else if (cur2 != s2.size())return 0;
        return 0;
    }
    void init_hash(string order) {
        for (int i = 0; i < order.size(); i++) {
            hash[order[i]] = i;//������ϣӳ��
        }
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        init_hash(order);//��ʼ����ϣ��
        for (int i = 0; i < words.size() - 1; i++) {
            if (my_strcmp(words[i], words[i + 1]) > 0)return false;
        }
        return true;
    }
};