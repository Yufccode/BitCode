#pragma once
#include<stdio.h>
#include<memory.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define NAME_MAX 20 //һ����ϵ�����ֵ����ռ�
#define SEX_MAX 5   //�Ա�
#define TELE_MAX 12  //�绰
#define ADDR_MAX 30  //��ַ  
#define DEFAULT_SZ 3 //Ĭ�ϳ�ʼ������С-��������Ҫ���������
//һ���˵���Ϣ
typedef struct PeoInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//��̬�汾
#if 0
typedef struct Contact {
	PeoInfo data[MAX];//���Դ��1000���˵���Ϣ
	int sz;//��¼ͨѶ¼���Ѿ��������Ϣ����
}Contact;
#endif

typedef struct Contact {
	PeoInfo* data;//���Դ��
	int sz;
	int capacity;//��¼�������
}Contact;



//ʵ�ֵĽṹ����
//�ô���Ŀɶ���������
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};


void _initContact(Contact* pc);
void _addContact(Contact* pc);
void _printContact(const Contact* pc);
void _delContact(Contact* pc);
void _searchContact(const Contact* pc);
void _modifyContact(Contact* pc);
void _sortByAge(Contact* pc);
void _destroyContact(Contact* pc);
void _saveContact(const Contact* pc);