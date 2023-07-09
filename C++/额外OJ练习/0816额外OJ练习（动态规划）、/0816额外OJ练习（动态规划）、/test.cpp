#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//64. ��С·����
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //�ܹ���Ҫ�Ĳ���
        int row = grid.size();
        int col = grid[0].size();
        //����dp����
        vector<vector<int>>dp(row, vector<int>(col, 0));
        //��ʼ��dp����
        //ע�� -- ���ֳ�ʼ���϶��ǵ�һ�к͵�һ�ж�Ҫ��ʼ����
        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < col; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        //��̬�滮
        for (int i = 1; i < row; i++) {//ע�⣬�����Ǵ�1��ʼ��
            for (int j = 1; j < col; j++) {//����Ҳ�Ǵ�1��ʼ��
                dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
            }
        }
        return dp[row - 1][col - 1];
    }
};
int main() {
    vector<vector<int>>arr = { {} };
    Solution().minPathSum(arr);
    return 0;
}