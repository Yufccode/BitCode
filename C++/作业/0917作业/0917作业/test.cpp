#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

//1.��������
int main()
{
	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);//�õ��������乹��
	vector<int>::iterator it = v.begin();
	//1 2 3 4 6 7 8 9 
	while (it != v.end())
	{
		if (*it != 0) {
			cout << *it;
		}
		else {
			v.erase(it);
		}
		it++;
	}
	return 0;
}
//��ʱ���һ���Ѿ�ʧЧ�ĵ������ڽ���++,�ᵼ�³������