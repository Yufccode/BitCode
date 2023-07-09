#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//
#if 0
class A
{
public:
    A(int a)
        :_a1(a)
        , _a2(_a1)
    {}
    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }
private:
    int _a2;
    int _a1;
};
int main()
{
    A aa(1);
    aa.Print();
}
#endif


//541. ��ת�ַ��� II
class Solution {
private:
    string myReverseStr(string& s, int start, int end) {
        int left = start;
        int right = end - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
public:
    string reverseStr(string s, int k) {
        if (s.size() == 0)return s;
        int fast = 0;//��ָ��
        int slow = 0;//��ָ��

        while (fast < s.size()) {
            int i = 0;
            for (i = 0; i < 2 * k && fast < s.size(); i++) {
                fast++;
            }
            //��һ�����
            if (fast == s.size() && i < k) {
                s = myReverseStr(s, slow, fast);
            }
            //�ڶ������
            else if (fast == s.size() && i >= k) {
                s = myReverseStr(s, slow, slow + k);
            }
            //û����
            else {
                s = myReverseStr(s, slow, slow + k);
                slow = fast;
            }
        }
        return s;
    }
};