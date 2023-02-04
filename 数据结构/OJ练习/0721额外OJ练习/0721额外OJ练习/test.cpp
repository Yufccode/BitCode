#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//567. �ַ���������
#if 0
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //���s1��s2�����϶���������Ŀ����
        if (s1.size() > s2.size())return false;
        //����������ϣ����
        //���������ϣ����ȼ��ˣ�˵����������
        vector<int>hash1(26, 0);
        vector<int>hash2(26, 0);
        //���ǰѻ������ڿ�����s1.size()�Ĵ�С�����ˣ���Ϊ���һ����s1.size()��С��
        for (int i = 0; i < s1.size(); i++) {
            ++hash1[s1[i] - 'a'];
            ++hash2[s2[i] - 'a'];
        }
        if (hash2 == hash1)return true;//����֮ǰҲҪ�ж�һ�Σ�Ҫϸ�ĵ�
        //��ʼ����
        for (int i = s1.size(); i < s2.size(); i++) {
            ++hash2[s2[i] - 'a'];
            --hash2[s2[i - s1.size()] - 'a'];
            if (hash2 == hash1)return true;
        }
        return false;
    }
};
#endif




//36. ��Ч������
//�������
//ע��:hash.clear()��������
//     ����sizeҲ��Ϊ0��
//��Ҫһ��to_0������չ�ϣ�� -- ��������֪ʶ����������Ӧ�ò����������
#if 0
class Solution {
private:
    void to_0(vector<int>& hash) {
        for (int i = 0; i < 10; i++) {
            hash[i] = 0;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>hash(10, 0);
        //�����
        for (int i = 0; i < 9; i++) {
            //��i�е����ù�ϣ�洢
            to_0(hash);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    ++hash[board[i][j] - '0'];
                    if (hash[board[i][j] - '0'] > 1)return false;
                }
            }
        }
        to_0(hash);
        //�����
        for (int i = 0; i < 9; i++) {
            //��i�е����ù�ϣ�洢
            to_0(hash);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    ++hash[board[j][i] - '0'];
                    if (hash[board[j][i] - '0'] > 1)return false;
                }
            }
        }
        //���Ź���
        //��ȥȷ��һ���Ź���ķ�Χ
        to_0(hash);
        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j += 3) {
                //���Դ�ʱ�þŹ�������Ͻ�Ϊ(i,j)
                //���½�����Ϊ(i+2,j+2)
                //����������󼴿�
                to_0(hash);
                for (int x = i; x <= i + 2; x++) {
                    for (int y = j; y <= j + 2; y++) {
                        if (board[x][y] != '.') {
                            ++hash[board[x][y] - '0'];
                            if (hash[board[x][y] - '0'] > 1)return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
void copy(vector<vector<string>>board_org, vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = board_org[i][j][0];
        }
    }
}
int main() {
    Solution su;
    vector<vector<string>>board_org = { 
        {"8", "3", ".", ".", "7", ".", ".", ".", "."},
        {"6", ".", ".", "1", "9", "5", ".", ".", "."},
        {".", "9", "8", ".", ".", ".", ".", "6", "."},
        {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
        {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
        {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
        {".", "6", ".", ".", ".", ".", "2", "8", "."},
        {".", ".", ".", "4", "1", "9", ".", ".", "5"},
        {".", ".", ".", ".", "8", ".", ".", "7", "9"} };
    vector < vector<char>>board(9, vector<char>(9));
    copy(board_org, board);
    int ret = su.isValidSudoku(board);
    return 0;
}
#endif

#if 0
class Solution {
private:
    static bool cmp(const void* e1, const void* e2) {
        return *((char*)e1) > *((char*)e2);
    }
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end(), cmp);
        sort(t.begin(), t.end(), cmp);
        if (t == s) {
            return true;
        }
        return false;
    }
};
#endif


//1346. ������������������Ƿ����
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int _max = arr[arr.size() - 1];
        int _mid = _max / 2;
        int i;
        for (i = arr.size() - 1; i > 0; i--) {
            if (arr[i] > _mid && arr[i - 1] <= _mid)break;
        }
        //��ʱ��i����Ҫ��ʼ�������±�
        int index = arr.size() - 1;//�������ߵ�ָ��
        while (i >= 0 && index >= 0) {
            if (arr[i] * 2 == arr[index] && i != index)return true;
            else if (arr[i] * 2 > arr[index])i--;
            else if (arr[i] * 2 < arr[index])index--;
            else i--;
        }
        return false;
    }
};
int main() {
    vector<int>arr = { -2,0,10,-19,4,6,-8};
    Solution su;
    su.checkIfExist(arr);
    return 0;
}