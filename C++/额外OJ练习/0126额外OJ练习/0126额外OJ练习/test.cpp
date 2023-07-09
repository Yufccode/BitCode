

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;


//218. ��������� ����
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //���ҵ���Զ��λ��������
        priority_queue<int>pq_max;
        for (size_t i = 0; i < buildings.size(); i++)
        {
            pq_max.push(max(buildings[i][0], buildings[i][1]));
        }
        int pq_size = pq_max.top();
        //pq_size���ǽ�������Զ�ĵط�
        //ÿһ�������깹��һ�����ȶ��У�ÿһ�������궼ά��
        vector<priority_queue<int>>arr(pq_size + 2, priority_queue<int>());
        //�����+2��ϸ�� -- �Ǵӵ��Եĳ����� -- ��Ȼ���һ���ؼ��㴦������
        for (size_t i = 0; i < buildings.size(); i++)
        {
            int height = buildings[i][2];
            int left = buildings[i][0];
            int right = buildings[i][1];
            for (size_t j = left; j <= right; j++)
            {
                arr[j].push(height);
            }
        }
        //��ʱ�Ѿ��ҵ��������
        vector<int>h;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i].size() == 0)
            {
                h.push_back(0); continue;
            }
            h.push_back(arr[i].top());
        }
        //��ʱarr��ľ��������
        vector<vector<int>>ret;
        for (size_t i = 0; i < h.size(); i++)
        {
            if(i == 0)
            {
                if (h[i] != 0)
                {
                    ret.push_back({ 0,h[i] });
                }
                continue;
            }
            if (h[i] > h[i - 1])
            {
                ret.push_back({ (int)i,h[i] });
            }
            else if (h[i] < h[i - 1])
            {
                ret.push_back({ (int)(i - 1),h[i] });
            }
            else
            {
                continue;
            }
        }
        return ret;
    }
};
int main()
{
    vector<vector<int>>b = { {2, 9, 10},{3, 7, 15},{5, 12, 12},{15, 20, 10},{19, 24, 8} };
    Solution().getSkyline(b);
    return 0;
}