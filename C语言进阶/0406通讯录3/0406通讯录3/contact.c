#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"


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



//��ʼ��ͨѶ¼(��̬)
#if 0
void _initContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
#endif

//��̬�汾��ʼ��
#if 0
void _initContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("init::malloc");
		exit(-1);
	}
	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
}
#endif
//����ͨѶ¼
void _loadContact(Contact* pc) {
	//���ļ�
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL) {
		perror("_loadContact::fopen");
		return;
	}
	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf)) {
		//�Ž�ȥ
		_checkCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


//������ļ��İ汾
void _initContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("init::malloc");
		exit(-1);
	}
	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
	//�����ļ���Ϣ��ͨѶ¼
	_loadContact(pc);
}

//����ͨѶ¼
void _destroyContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
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


//����ͨѶ¼
void _saveContact(const Contact* pc) {
	FILE* pf = fopen("contact.dat", "wb");//�Զ����Ƶ���ʽд��ȥ
	if (pf == NULL) {
		perror("_saveContact::fopen");
		return;
	}
	//д�ļ�
	for (int i = 0; i < pc->sz; i++) {//һ��һ��д��ȥ
		fwrite(pc->data+i,sizeof(PeoInfo),1,pf);
	}
	printf("sucessfully saved!\n");
	printf("--------------------------------------------------\n");
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}