#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;


//stack_queue �򵥼򵥼򵥣�
//û�е����� -- Ҫ����stack_queue������

void test_stack() {
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}
void test_queue() {
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

int main() {
	//test_stack();
	test_queue();
	return 0;
}



//155. ��Сջ
//Ҫ��O(1)
class MinStack {
private:
    int _min;
    stack<int>st;//����ջ
    stack<int>minst;//��¼��С���ݵ�ջ
    //����д����ظ�������ô�죿
    //minst����������ͬ�������� -- ���Ǽ�һ��������������
    //minst���治�����֣���һ���ṹ�����
public:
    void push(int val) {
        st.push(val);
        if (minst.empty() || val <= minst.top()) { //����ջ���С�ڵ��ڣ�minstҲ����
            minst.push(val);
        }
    }
    void pop() {
        if (minst.top() == st.top()) {
            minst.pop();
        }
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return minst.top();
    }
};


//JZ31 ջ��ѹ�롢��������
//�ж�ջ����
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int i = 0;
        int j = 0;
        stack<int>st;
        while (j < popV.size()) {
            if (!st.empty() && st.top() == popV[j]) {
                st.pop();
                j++;
            }
            else {
                if (i < pushV.size()) {
                    st.push(pushV[i]);
                    i++;
                }
                else return false;
            }
        }
        return true;
    }
};


//150. �沨�����ʽ��ֵ
//��׺���ʽ
//1+2*3  --  ������������㲻�˵ģ���Ϊ��֪�����ȼ�
//��׺���ʽ
//1 2 3 * +  �����Ϳ�������

//��׺��ô�㣺���Ƚ����׺��ô�㣬Ȼ�����о���׺��ôת��׺��
//��������˳�򲻱�
//1.��������ջ
//2.��������ȡջ�������������������㣬��������ջ
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for (auto& str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                //ֱ�����ַ���operator==ȥ�жϣ�����'-'�͸�������
                long long right = st.top();
                st.pop();
                long long left = st.top();
                st.pop();
                switch (str[0]) {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
//��׺ת��׺��
//1.���������������
//2.����������
// a.ջΪ�գ����߱�ջ���Ĳ��������ȼ��ߣ���ջ
// b.��ջ���Ĳ��������ȼ��ͻ�����ȣ���ջ���������