#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Person
{
public:
	void PrintPersonInfo();
private:
	char _name[20];//���������壿
	//���ڱ����������Ͷ���ȡ�������Ƿ��п��ռ�
	char _gender[3];
	int _age;
};
//��������ĳ�Ա������ʵ��������

#if 0
int age;//�����Ƕ���
#endif
//��Ȼ�����age��������϶��ǻᷢ�����ӳ�ͻ�ģ���Ϊչ��������
//����
extern int age;//������ǰѶ����������� -- ���߱����������Ǹ�������������ȥ.cpp���涨�弴��
//���ǽ������ĵ�һ�ַ�ʽ����һ��staticҲ��
//�������Բ�ͬ
//�����static�Ļ���ֻ�е�ǰ�ļ��ɼ�����������ű�
//���������static�����ļ��ľ��ǲ�һ������
//�������Ҫ�ڱ���ļ���age����extern��������
