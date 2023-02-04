#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>

using namespace std;


//20. ��Ч������
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {//ϸ��
            return false;
        }
        stack<char>st;
        int i = 0;
        while (i <= s.size() - 1) {//ϸ��
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                ++i;
            }
            else {
                if (st.empty()) {//ϸ��
                    return false;
                }
                if ((st.top() == '{' && s[i] == '}')
                    || (st.top() == '(' && s[i] == ')')
                    || (st.top() == '[' && s[i] == ']')) {
                    ++i;
                    if (!st.empty()) {//ϸ��
                        st.pop();
                    }
                    else return false;
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();//ϸ��
    }
};

int main() {
    int i = 0;
    string s = "abc";
    
    return 0;
}