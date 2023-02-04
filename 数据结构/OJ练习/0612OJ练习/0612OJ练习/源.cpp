#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//412. Fizz Buzz
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ret;
        for (int i = 1; i <= n; i++) {
            if ((i) % 3 == 0 && (i) % 5 == 0) {
                ret.push_back("FizzBuzz");
            }
            else if ((i) % 3 == 0) {
                ret.push_back("Fizz");
            }
            else if ((i) % 5 == 0) {
                ret.push_back("Buzz");
            }
            else {
                ret.push_back(to_string(i));
            }
        }
        return ret;
    }
};



//������ 08.07. ���ظ��ַ������������
class Solution {
private:
    vector<string>ret;
    string path;
    void dfs(string s, vector<bool>used) {
        if (path.size() == s.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (used[i] == true)continue;
            path += s[i];
            used[i] = true;
            dfs(s, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<string> permutation(string S) {
        vector<bool>used(S.size() + 1, false);
        dfs(S, used);
        return ret;
    }
};


//�ϲ�����
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //�ȴ���һ�������άvector
        vector<vector<int>> result;
        if (intervals.size() == 0) {//���û��Ԫ�ش�����
            return result;//ֱ�ӷ��ؿյļ���
        }

        //����
        sort(intervals.begin(), intervals.end(), cmp);
        //tips:����ʱ�Ĳ���Ҳ����ʳ��Lambda���ʽ

        //�Ȱѵ�һ���������
        result.push_back(intervals[0]);
        //��ʼ����,�ӵڶ���Ԫ��,���±�Ϊ1��λ�ÿ�ʼ����
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) {//���������󵽴��λ�ô���׼������Ԫ�ص�λ��ʱ���ϲ���
            //ע��!��>=����
                                                     //tips:Ԫ��ָ����һ������
                result.back()[1] = max(result.back()[1], intervals[i][1]);//����result����������󵽴��λ��
                                     ///����֮��������Ǹ�����Ϊ�ϲ���
            }
            else {
                result.push_back(intervals[i]);//���ܺϲ� ֱ�Ӳ����
            }
        }
        return result;
    }
};