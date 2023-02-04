#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//��ʼ��ͨѶ¼(��̬)
#if 0
void _initContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
#endif

//��̬�汾��ʼ��
void _initContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data =(PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("init::malloc");
		exit(-1);
	}
	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
}

//����ͨѶ¼
void _destroyContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

//����
void _checkCapacity(Contact* pc) {
	if (pc->sz == pc->capacity) {
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (tmp != NULL) {
			pc->data = tmp;
		}
		pc->capacity += 2;
		printf("contact is successfully enlarged!\n");
		printf("---------------------------------\n");
	}
}
//������ϵ��
void _addContact(Contact* pc) {
	assert(pc);
	//if (pc->sz == MAX) {
	//	printf("Contact is already full,err\n");
	//	exit(-1);
	//}
	
	//����Ҫ����
	_checkCapacity(pc);
	//¼����Ϣ
	printf("please input the name:");
	scanf("%s", pc->data[pc->sz].name);
	printf("please input the age:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("please input the sex:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("please input the tele_num:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("pleae input the address:");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("----------------------------\n");
	printf("successfully added!\n");
	printf("----------------------------\n");
	printf("\n");
	system("pause");
}

//��ӡͨѶ¼
void _printContact(const Contact* pc) {
	assert(pc);
	//��ӡ
	int i = 0;
	printf("\n");
	printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++) {
		printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, pc->data[i].age,
			pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
	printf("\n");
	system("pause");
}

//ͨ�����ֲ����˵���Ϣ
int _findByName(const Contact* pc, char* name) {
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

//ɾ��ָ����ϵ����Ϣ
void _delContact(Contact* pc) {
	assert(pc);
	if (pc->sz == 0) {
		printf("null Contact! err!\n");
		system("pause");
		return;
	}
	//ɾ��
	//1.�ҵ�
	char name[NAME_MAX] = { 0 };
	printf("please input the name��");
	scanf("%s", name);
	int pos = _findByName(pc, name);//�ҵ��ˣ������±ꣻ�Ҳ��������ظ�һ
	if (pos == -1) {
		printf("cannot find the PeoInfo,err!");
		system("pause");
		return;
	}
	//2.ɾ��
	//����Ҫ��΢�����������sz-1����ҪԽ����
	for (int j = pos; j < pc->sz - 1; j++) {
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;//�����Ҫ������
	printf("successfully deleted\n");
	system("pause");
}



//����һ���˵���Ϣ
void _searchContact(const Contact* pc) {
	char name[NAME_MAX] = { 0 };
	printf("please input the name:>");
	scanf("%s", name);
	int pos = _findByName(pc, name);
	if (pos == -1) {
		printf("cannot find the PeoInfo,err!");
		return;
	}
	printf("--------------------------------------------------\n");
	printf("the info is:\n");
	printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, pc->data[pos].age,
		pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
	printf("--------------------------------------------------\n");
	system("pause");
}


void _modifyContact(Contact* pc) {
	printf("whose Info do you want to modify:\n");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	int pos = _findByName(pc, name);
	if (pos == -1) {
		printf("cannot find the PeoInfo,err!\n");
		printf("--------------------------------------------------\n");
		system("pause");
		return;
	}
	//�޸�
	printf("--------------------------------------------------\n");
	printf("you are modifing %s's info\n", pc->data[pos].name);
	printf("please input the name:");
	scanf("%s", pc->data[pos].name);
	printf("please input the age:");
	scanf("%d", &(pc->data[pos].age));
	printf("please input the sex:");
	scanf("%s", pc->data[pos].sex);
	printf("please input the tele_num:");
	scanf("%s", pc->data[pos].tele);
	printf("pleae input the address:");
	scanf("%s", pc->data[pos].addr);
	printf("\n");
	printf("successfully modified!\n");
	printf("--------------------------------------------------\n");
	printf("\n");
	system("pause");
}


int cmp(const void* e1, const void* e2) {
	//���Ų�Ҫ������
	return (((PeoInfo*)e1)->age - ((PeoInfo*)e1)->age);
}
void _sortByAge(Contact* pc) {
	printf("sort by Age!\n");
	printf("--------------------------------------------------\n");
	qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp);
	_printContact(pc);
}
//�����������