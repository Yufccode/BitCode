#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//KMP��ʵ����ǰ׺�������
//��Ϊstrstr�������� -- �˷ѵ�ʱ����ʵ�����ִ�����һ��һ�ε��ظ�
//��KMP���������ڣ���Ϊ���Ѿ��õ���ǰ׺
//�����ƶ��ַ���֮��ǰ��Ĳ��ñȽ���


//����ǰ׺��
void prefix_table(char pattern[], int prefix[], int n) {
	//��ʵ�Ƕ�̬�滮��˼��
	prefix[0] = 0;//��ʼ��
	int len = 0;
	int i = 1;//Ӧ���Ǵӵڶ�����ĸ��ʼ�Ƚ�
	while (i < n) {
		//������ֵ�i��λ�õ���ĸ���ڵ�lenλ�õ���ĸ
		//˵��ǰ׺[]����++
		//i���ڱ������±�
		//len�Ǵ�0��ʼ���ǰ׺��len�����
		if (pattern[i] == pattern[len]) {
			len++;//ǰ׺����++����Ϊƥ������
			prefix[i] = len;
			i++;
		}
		else {//�����
			//����Ҫб��ƥ�� -- ������
			if (len > 0)len = prefix[len - 1];
			else {
				prefix[i] = len;
				i++;//Ҫ�ǵõ���
			}
		}
	}
}
//дһ�����������prefixǰ׺�������һλ
void move_prefix_table(int prefix[], int n) {
	for (int i = n - 1; i > 0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}
void kmp_search(char text[], char pattern[]) {

}
int main() {
	char pattern[] = "ABABCABAA";
	int prefix[9];
	int n = 9;
	prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", prefix[i]);
	}
	return 0;
}