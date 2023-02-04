#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//923. ����֮�͵Ķ��ֿ���
//��û��
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        //�ȸ���������
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            //ö���˵�һ�����ˣ���������˫ָ��
            int left = i + 1;
            int right = arr.size() - 1;
            while (left < right) {
                int sum = arr[left] + arr[right] + arr[i];
                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else if (sum == target) {
                    //������Ҫ�ú������మ����һ��
                    int cnt_left = 1;
                    int cnt_right = 1;
                    while (left < right && arr[left] == arr[left + 1]) {
                        left++;
                        cnt_left++;
                    }
                    while (left < right && arr[right] == arr[right - 1]) {
                        right--;
                        cnt_right++;
                    }
                    right--;
                    left++;
                    cnt += cnt_right * cnt_left;
                }
            }
        }
        return cnt;
    }
};
int main() {
    Solution su;
    int target = 8;
    vector<int>arr = { 1,1,2,2,3,3,4,4,5,5 };
    su.threeSumMulti(arr, target);
    return 0;
}