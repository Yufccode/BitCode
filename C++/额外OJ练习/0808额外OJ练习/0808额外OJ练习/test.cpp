#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;


//60. ��������
//Ч�ʲ����� -- ��ʱ��
//�Ż���ͨ��
#if 0
class Solution {
private:
    int cnt = 0;
    vector<vector<int>>ret;
    vector<int>path;
    vector<int>ans;
    int _factorial(int x) {
        int ans = 1;
        for (int i = 1; i <= x; i++) {
            ans *= i;
        }
        return ans;
    }
    void dfs(vector<int>nums, vector<bool>used, int k) {
        //�����һЩ��֦ -- ��Ȼ������
        int rest_numNodes_cnt = _factorial(nums.size() - path.size() - 1);
        if (path.size() == nums.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true)continue;
            if (rest_numNodes_cnt < k && rest_numNodes_cnt>0) {
                k -= rest_numNodes_cnt;
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, k);
            //Ϊʲô���ﲻ�û�ԭ״̬��
            //used[i] = false;
            //path.pop_back();
        }
    }
    int My_to_int(vector<int>arr) {
        int ret = 0;
        for (int i = 0; i < arr.size(); i++) {
            ret += arr[i] * pow(10, arr.size() - i - 1);
        }
        return ret;
    }
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        vector<bool>used(n, false);
        dfs(nums, used, k);
        //����Ҫ��ret���±�Ϊk-1�ļ������ֺϲ���һ����
        int ans = My_to_int(ret[ret.size() - 1]);
        return to_string(ans);
    }
};
int main() {
    cout << Solution().getPermutation(9, 94626) << endl;
    //"348567921"
    return 0;
}
#endif
/*
�������� һ����Ҷ�ӽ�㴦�õ�������ÿһ����֧�����Ը����Ѿ�ѡ�������ĸ������������㻹δѡ�������ĸ�����Ȼ�����׳ˣ���֪����һ����֧�� Ҷ�ӽ�� �ĸ�����
��� kk ������һ����֧��Ҫ������Ҷ�ӽ������ֱ�����������֧����������С���֦����
��� kk С�ڵ�����һ����֧��Ҫ������Ҷ�ӽ��������˵�������ȫ����һ������һ����֧��Ҫ������Ҷ�ӽ�����Ҫ�ݹ���⡣
*/





//42. ����ˮ
//�㷨��ȷ�����ǳ�ʱ
//˼·��һ��һ����
class Solution {
private:
    int count_rain_v(vector<int>blocks) {
        //����blocks��ÿһ������
        //��˫ָ�����
        int slow = 0;
        int fast = 0;
        int sum_v = 0;
        while (fast < blocks.size()) {
            if (fast == slow && blocks[fast] == 0 && (fast == 0) || fast == blocks.size() - 1) {
                //�������������ָ��0�Ŀ���ͬʱǰ��
                fast++;
                slow++;
            }
            else if (fast == slow && blocks[fast] == 1) {
                fast++;
                slow++;
            }
            else if (fast == slow && blocks[fast] == 0 && blocks[fast - 1] == 1) {
                //fast�ߣ�slow����
                while (fast < blocks.size() && blocks[fast] == 0)fast++;
                if (fast == blocks.size()) {
                    //˵��fast�߳�ȥ�ˣ����ü�
                    return sum_v;
                }
                //��ʱ˵����fastû�г�ȥ�����Ի�����ˮ
                sum_v += fast - slow;
                slow = fast;
            }
            else {
                fast++;
                slow++;
            }
        }
        return sum_v;
    }
public:
    int trap(vector<int>& height) {
        //����ÿһ���ܽӵ���ˮ�����
        //�������߼���¥
        int max_height = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > max_height) {
                max_height = height[i];
            }
        }
        //�Ȱ�ÿһ�������Ū������
        vector<vector<int>>blocks;
        for (int i = 0; i < max_height; i++) {
            vector<int>path;
            for (int j = 0; j < height.size(); j++) {
                if (height[j] - i > 0) {
                    path.push_back(1);
                }
                else path.push_back(0);
            }
            blocks.push_back(path);
        }
        //[0,1,0,2,1,0,1,3,2,1,2,1]

        //[0,1,0,1,1,0,1,1,1,1,1,1]
        //[0,0,0,1,0,0,0,2,1,0,1,0]
        //[0,0,0,0,0,0,0,1,0,0,0,0]
        //����ÿһ���ܻ��۵���ˮ
        int ans_v = 0;//�������
        for (int i = 0; i < blocks.size(); i++) {
            //�����Ǳ���ÿһ��
            ans_v += count_rain_v(blocks[i]);
        }
        return ans_v;
    }
};
int main() {
    vector<int>height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    Solution().trap(height);
    return 0;
}